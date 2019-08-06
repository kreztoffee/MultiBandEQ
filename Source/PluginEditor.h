#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class MultiBandEqAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MultiBandEqAudioProcessorEditor (MultiBandEqAudioProcessor&);
    ~MultiBandEqAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    MultiBandEqAudioProcessor& processor;

	std::vector<std::unique_ptr<Slider>> m_eqLeftBandSliders;
	std::vector<std::unique_ptr<Slider>> m_eqRightBandSliders;
	std::vector<std::unique_ptr<Label>> m_eqBandLabels;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiBandEqAudioProcessorEditor)
};
