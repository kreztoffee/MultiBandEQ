#include "PluginProcessor.h"
#include "PluginEditor.h"

MultiBandEqAudioProcessorEditor::MultiBandEqAudioProcessorEditor (MultiBandEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (700, 300);
}

MultiBandEqAudioProcessorEditor::~MultiBandEqAudioProcessorEditor()
{
}

//==============================================================================
void MultiBandEqAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MultiBandEqAudioProcessorEditor::resized()
{
}
