#include "PluginProcessor.h"
#include "PluginEditor.h"

MultiBandEqAudioProcessor::MultiBandEqAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	for (int i = 0; i < 30; ++i)
	{
		AudioParameterFloat* leftBandGain = nullptr;
		AudioParameterFloat* rightBandGain = nullptr;

		addParameter(leftBandGain = new AudioParameterFloat("eqLeftBandGain" + String(i),
					 "Left Band " + String(i) + " Gain" + String(i),
					 -1.0f,
					 1.0f,
					 0.0f));

		m_eqLeftBandGains.push_back(leftBandGain);

		addParameter(rightBandGain = new AudioParameterFloat("eqRightBandGain" + String(i),
					 "Right Band " + String(i) + " Gain" + String(i),
					 -1.0f,
					 1.0f,
					 0.0f));

		m_eqRightBandGains.push_back(rightBandGain);
	}
}

MultiBandEqAudioProcessor::~MultiBandEqAudioProcessor()
{
}

const String MultiBandEqAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MultiBandEqAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MultiBandEqAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MultiBandEqAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MultiBandEqAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MultiBandEqAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MultiBandEqAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MultiBandEqAudioProcessor::setCurrentProgram (int index)
{
}

const String MultiBandEqAudioProcessor::getProgramName (int index)
{
    return {};
}

void MultiBandEqAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void MultiBandEqAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void MultiBandEqAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MultiBandEqAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    return true;
}
#endif

void MultiBandEqAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

bool MultiBandEqAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* MultiBandEqAudioProcessor::createEditor()
{
    return new MultiBandEqAudioProcessorEditor (*this);
}

void MultiBandEqAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	MemoryOutputStream mem(destData, true);

	for (int i = 0; i < 30; ++i)
	{
		mem.writeFloat(*m_eqLeftBandGains[i]);
		mem.writeFloat(*m_eqRightBandGains[i]);
	}
}

void MultiBandEqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	MemoryInputStream mem(data, static_cast<size_t> (sizeInBytes), false);
	
	for (int i = 0; i < 30; ++i)
	{
		*m_eqLeftBandGains[i] = mem.readFloat();
		*m_eqRightBandGains[i] = mem.readFloat();
	}
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MultiBandEqAudioProcessor();
}
