#include "PluginProcessor.h"
#include "PluginEditor.h"

MultiBandEqAudioProcessorEditor::MultiBandEqAudioProcessorEditor (MultiBandEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	for (int i = 0; i < 30; ++i)
	{
		std::unique_ptr<Slider> eqLeftBandSlider = std::make_unique<Slider>();
		eqLeftBandSlider->setSliderStyle(Slider::LinearVertical);
		addAndMakeVisible(*eqLeftBandSlider);
		m_eqLeftBandSliders.push_back(std::move(eqLeftBandSlider));

		std::unique_ptr<Slider> eqRightBandSlider = std::make_unique<Slider>();
		eqRightBandSlider->setSliderStyle(Slider::LinearVertical);
		addAndMakeVisible(*eqRightBandSlider);
		m_eqRightBandSliders.push_back(std::move(eqRightBandSlider));

		std::unique_ptr<Label> eqBandLabel = std::make_unique<Label>();
		eqBandLabel->setText(String(i), dontSendNotification);
		eqBandLabel->setFont(Font(8));
		addAndMakeVisible(*eqBandLabel);
		m_eqBandLabels.push_back(std::move(eqBandLabel));
	}

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
	float sep = (getWidth() - 30) / 30.0f;

	for (int i = 0; i < 30; ++i)
	{
		m_eqLeftBandSliders[i]->setBounds(30 + (i * sep), 10, 20, 130);
		m_eqRightBandSliders[i]->setBounds(30 + (i * sep), 140, 20, 130);
		//m_eqBandLabels[i]->setBounds(30 + (i * sep), 215, 20, 20);
	}
}
