/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/imbSynthStateData.h"
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabInOut  : public Component,
                          public imbSynthGUIComponent,
                          public Button::Listener,
                          public ComboBox::Listener,
                          public Slider::Listener
{
public:
    //==============================================================================
    MainViewTabInOut (imbSynthStateData * synthState, String nameSufix);
    ~MainViewTabInOut();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* basszero_background_jpg;
    static const int basszero_background_jpgSize;
    static const char* background2_jpg;
    static const int background2_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label6;
    std::unique_ptr<ToggleButton> EnableDirectMIDIInputs;
    std::unique_ptr<ComboBox> Device;
    std::unique_ptr<ToggleButton> Enable;
    std::unique_ptr<ToggleButton> ForwardInputsToOutputs;
    std::unique_ptr<ToggleButton> ForwardVSTHostToOutputs;
    std::unique_ptr<TextButton> Send5;
    std::unique_ptr<ComboBox> SerialPortSelection;
    std::unique_ptr<ToggleButton> UseSerialLink;
    std::unique_ptr<Slider> ccMessagesCycle;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<ComboBox> SerialPortBaudrate;
    std::unique_ptr<ComboBox> MIDIInput1;
    std::unique_ptr<Label> label4;
    std::unique_ptr<ComboBox> MIDIInput2;
    std::unique_ptr<ComboBox> MIDIInput3;
    std::unique_ptr<ComboBox> MIDIOutput1;
    std::unique_ptr<Label> label5;
    std::unique_ptr<ComboBox> MIDIOutput2;
    std::unique_ptr<ComboBox> MIDIOutput3;
    std::unique_ptr<Label> label7;
    Image cachedImage_background2_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabInOut)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

