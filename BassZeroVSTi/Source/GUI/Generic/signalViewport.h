/*
  ==============================================================================

    signalViewport.h
    Created: 28 Oct 2019 5:09:09am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class signalViewport    : public Component
{
public:
    signalViewport()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }

    ~signalViewport()
    {
    }

    void paint (Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

        g.setColour (Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        g.setColour (Colours::white);
        g.setFont (14.0f);
        g.drawText ("signalViewport", getLocalBounds(),
                    Justification::centred, true);   // draw some placeholder text
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (signalViewport)
};