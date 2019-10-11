/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "BassZeroVstiAudioProcessor.h"
#include "BassZeroVstiAudioProcessorEditor.h"
#include "BassZeroInterface.h"

#define WIDTH 840
#define HEIGHT 500

//==============================================================================
BassZeroVstiAudioProcessorEditor::BassZeroVstiAudioProcessorEditor (BassZeroVstiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), bassZeroGUI(&p.bassZeroState)
{
	
	
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (WIDTH, HEIGHT);

	addAndMakeVisible(bassZeroGUI);
	bassZeroGUI.setTopLeftPosition(0, 0);
	bassZeroGUI.setSize(WIDTH, HEIGHT);
	
	//addChildComponent(bassZeroGUI);
}

BassZeroVstiAudioProcessorEditor::~BassZeroVstiAudioProcessorEditor()
{
}

//==============================================================================
void BassZeroVstiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
   // g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void BassZeroVstiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
