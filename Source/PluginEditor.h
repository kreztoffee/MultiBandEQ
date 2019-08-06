/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MultiBandEqAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MultiBandEqAudioProcessorEditor (MultiBandEqAudioProcessor&);
    ~MultiBandEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultiBandEqAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiBandEqAudioProcessorEditor)
};
