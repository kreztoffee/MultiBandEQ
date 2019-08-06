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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiBandEqAudioProcessorEditor)
};
