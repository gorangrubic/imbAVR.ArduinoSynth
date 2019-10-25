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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TabWaveforms.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabWaveforms::TabWaveforms (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    WFA.reset (new OSCEditor (synthState, "WFA"));
    addAndMakeVisible (WFA.get());
    WFA->setBounds (16, 48, 96, 120);

    WFB.reset (new OSCEditor (synthState, "WFB"));
    addAndMakeVisible (WFB.get());
    WFB->setBounds (426, 48, 100, 112);

    PERKA.reset (new OSCEditor (synthState, "PERKA"));
    addAndMakeVisible (PERKA.get());
    PERKA->setBounds (16, 212, 96, 112);

    label_WFA.reset (new Label ("Title",
                                TRANS("WF A")));
    addAndMakeVisible (label_WFA.get());
    label_WFA->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_WFA->setJustificationType (Justification::centredLeft);
    label_WFA->setEditable (false, false, false);
    label_WFA->setColour (Label::backgroundColourId, Colour (0xffed6216));
    label_WFA->setColour (TextEditor::textColourId, Colours::black);
    label_WFA->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Label_WFB.reset (new Label ("Title",
                                TRANS("WF B")));
    addAndMakeVisible (Label_WFB.get());
    Label_WFB->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    Label_WFB->setJustificationType (Justification::centredLeft);
    Label_WFB->setEditable (false, false, false);
    Label_WFB->setColour (Label::backgroundColourId, Colour (0xffed6216));
    Label_WFB->setColour (TextEditor::textColourId, Colours::black);
    Label_WFB->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_perkA.reset (new Label ("label_perkA",
                                  TRANS("PERK A")));
    addAndMakeVisible (label_perkA.get());
    label_perkA->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_perkA->setJustificationType (Justification::centredLeft);
    label_perkA->setEditable (false, false, false);
    label_perkA->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label_perkA->setColour (TextEditor::textColourId, Colours::black);
    label_perkA->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2.reset (new Label ("new label",
                             TRANS("PWM\n")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colour (0xff181f22));
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFA_PWM.reset (new SourceMixerComponent (synthState, "WFA_PWM"));
    addAndMakeVisible (WFA_PWM.get());
    Title3.reset (new Label ("new label",
                             TRANS("Shaper")));
    addAndMakeVisible (Title3.get());
    Title3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title3->setJustificationType (Justification::centred);
    Title3->setEditable (false, false, false);
    Title3->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title3->setColour (Label::textColourId, Colour (0xff181f22));
    Title3->setColour (TextEditor::textColourId, Colours::black);
    Title3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFA_Shaper.reset (new SourceMixerComponent (synthState, "WFA_Shaper"));
    addAndMakeVisible (WFA_Shaper.get());
    Title4.reset (new Label ("new label",
                             TRANS("PWM\n")));
    addAndMakeVisible (Title4.get());
    Title4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title4->setJustificationType (Justification::centred);
    Title4->setEditable (false, false, false);
    Title4->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title4->setColour (Label::textColourId, Colour (0xff181f22));
    Title4->setColour (TextEditor::textColourId, Colours::black);
    Title4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKA_PWM.reset (new SourceMixerComponent (synthState, "PERKA_PWM"));
    addAndMakeVisible (PERKA_PWM.get());
    Title5.reset (new Label ("new label",
                             TRANS("HP FREQ")));
    addAndMakeVisible (Title5.get());
    Title5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title5->setJustificationType (Justification::centred);
    Title5->setEditable (false, false, false);
    Title5->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title5->setColour (Label::textColourId, Colour (0xff181f22));
    Title5->setColour (TextEditor::textColourId, Colours::black);
    Title5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKA_HPFREQ.reset (new SourceMixerComponent (synthState, "PERKA_HPFREQ"));
    addAndMakeVisible (PERKA_HPFREQ.get());
    Title6.reset (new Label ("new label",
                             TRANS("AMP")));
    addAndMakeVisible (Title6.get());
    Title6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title6->setJustificationType (Justification::centred);
    Title6->setEditable (false, false, false);
    Title6->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title6->setColour (Label::textColourId, Colour (0xff181f22));
    Title6->setColour (TextEditor::textColourId, Colours::black);
    Title6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKA_AMP.reset (new SourceMixerComponent (synthState, "PERKA_AMP"));
    addAndMakeVisible (PERKA_AMP.get());
    PERKB.reset (new OSCEditor (synthState, "PERKB"));
    addAndMakeVisible (PERKB.get());
    PERKB->setBounds (426, 211, 96, 112);

    label_perkB2.reset (new Label ("label_perkB",
                                   TRANS("PERK B")));
    addAndMakeVisible (label_perkB2.get());
    label_perkB2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_perkB2->setJustificationType (Justification::centredLeft);
    label_perkB2->setEditable (false, false, false);
    label_perkB2->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label_perkB2->setColour (TextEditor::textColourId, Colours::black);
    label_perkB2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title7.reset (new Label ("new label",
                             TRANS("PWM\n")));
    addAndMakeVisible (Title7.get());
    Title7->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title7->setJustificationType (Justification::centred);
    Title7->setEditable (false, false, false);
    Title7->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title7->setColour (Label::textColourId, Colour (0xff181f22));
    Title7->setColour (TextEditor::textColourId, Colours::black);
    Title7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKB_PWM.reset (new SourceMixerComponent (synthState, "PERKB_PWM"));
    addAndMakeVisible (PERKB_PWM.get());
    Title8.reset (new Label ("new label",
                             TRANS("HP FREQ")));
    addAndMakeVisible (Title8.get());
    Title8->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title8->setJustificationType (Justification::centred);
    Title8->setEditable (false, false, false);
    Title8->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title8->setColour (Label::textColourId, Colour (0xff181f22));
    Title8->setColour (TextEditor::textColourId, Colours::black);
    Title8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKB_HPFREQ.reset (new SourceMixerComponent (synthState, "PERKB_HPFREQ"));
    addAndMakeVisible (PERKB_HPFREQ.get());
    Title9.reset (new Label ("new label",
                             TRANS("AMP")));
    addAndMakeVisible (Title9.get());
    Title9->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title9->setJustificationType (Justification::centred);
    Title9->setEditable (false, false, false);
    Title9->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title9->setColour (Label::textColourId, Colour (0xff181f22));
    Title9->setColour (TextEditor::textColourId, Colours::black);
    Title9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PERKB_AMP.reset (new SourceMixerComponent (synthState, "PERKB_AMP"));
    addAndMakeVisible (PERKB_AMP.get());
    Title10.reset (new Label ("new label",
                              TRANS("PWM\n")));
    addAndMakeVisible (Title10.get());
    Title10->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title10->setJustificationType (Justification::centred);
    Title10->setEditable (false, false, false);
    Title10->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title10->setColour (Label::textColourId, Colour (0xff181f22));
    Title10->setColour (TextEditor::textColourId, Colours::black);
    Title10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFB_PWM.reset (new SourceMixerComponent (synthState, "WFB_PWM"));
    addAndMakeVisible (WFB_PWM.get());
    Title11.reset (new Label ("new label",
                              TRANS("Shaper")));
    addAndMakeVisible (Title11.get());
    Title11->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title11->setJustificationType (Justification::centred);
    Title11->setEditable (false, false, false);
    Title11->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title11->setColour (Label::textColourId, Colour (0xff181f22));
    Title11->setColour (TextEditor::textColourId, Colours::black);
    Title11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFB_Shaper.reset (new SourceMixerComponent (synthState, "WFB_Shaper"));
    addAndMakeVisible (WFB_Shaper.get());
    Title12.reset (new Label ("new label",
                              TRANS("AMP")));
    addAndMakeVisible (Title12.get());
    Title12->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title12->setJustificationType (Justification::centred);
    Title12->setEditable (false, false, false);
    Title12->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title12->setColour (Label::textColourId, Colour (0xff181f22));
    Title12->setColour (TextEditor::textColourId, Colours::black);
    Title12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFA_Shaper2.reset (new SourceMixerComponent (synthState, "WFA_Shaper"));
    addAndMakeVisible (WFA_Shaper2.get());
    Title13.reset (new Label ("new label",
                              TRANS("AMP")));
    addAndMakeVisible (Title13.get());
    Title13->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title13->setJustificationType (Justification::centred);
    Title13->setEditable (false, false, false);
    Title13->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title13->setColour (Label::textColourId, Colour (0xff181f22));
    Title13->setColour (TextEditor::textColourId, Colours::black);
    Title13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WFA_Shaper3.reset (new SourceMixerComponent (synthState, "WFA_Shaper"));
    addAndMakeVisible (WFA_Shaper3.get());
    cachedImage_background1_jpg_1 = ImageCache::getFromMemory (background1_jpg, background1_jpgSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 360);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabWaveforms::~TabWaveforms()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    WFA = nullptr;
    WFB = nullptr;
    PERKA = nullptr;
    label_WFA = nullptr;
    Label_WFB = nullptr;
    label_perkA = nullptr;
    Title2 = nullptr;
    WFA_PWM = nullptr;
    Title3 = nullptr;
    WFA_Shaper = nullptr;
    Title4 = nullptr;
    PERKA_PWM = nullptr;
    Title5 = nullptr;
    PERKA_HPFREQ = nullptr;
    Title6 = nullptr;
    PERKA_AMP = nullptr;
    PERKB = nullptr;
    label_perkB2 = nullptr;
    Title7 = nullptr;
    PERKB_PWM = nullptr;
    Title8 = nullptr;
    PERKB_HPFREQ = nullptr;
    Title9 = nullptr;
    PERKB_AMP = nullptr;
    Title10 = nullptr;
    WFB_PWM = nullptr;
    Title11 = nullptr;
    WFB_Shaper = nullptr;
    Title12 = nullptr;
    WFA_Shaper2 = nullptr;
    Title13 = nullptr;
    WFA_Shaper3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabWaveforms::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 0, y = -66, width = 840, height = 490;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage_background1_jpg_1,
                     x, y, width, height,
                     0, 0, cachedImage_background1_jpg_1.getWidth(), cachedImage_background1_jpg_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabWaveforms::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label_WFA->setBounds (16 + 0, 20, 98, 24);
    Label_WFB->setBounds (426 + 0, 20, 96, 24);
    label_perkA->setBounds (16 + 0, 212 + -28, 98, 24);
    Title2->setBounds (16 + 96, 48, 100, 16);
    WFA_PWM->setBounds (getWidth() - 725, 66, 96, 96);
    Title3->setBounds (16 + 96 - -100, 48, 100, 16);
    WFA_Shaper->setBounds (getWidth() - 626, 66, 96, 96);
    Title4->setBounds (getWidth() - 728, 212, 100, 16);
    PERKA_PWM->setBounds (getWidth() - 725, 230, 96, 96);
    Title5->setBounds (16 + 96 - -100, 212, 100, 16);
    PERKA_HPFREQ->setBounds (getWidth() - 626, 230, 96, 96);
    Title6->setBounds (16 + 96 - -198, 212, 100, 16);
    PERKA_AMP->setBounds (getWidth() - 527, 230, 96, 96);
    label_perkB2->setBounds (16 + 410, 212 + -29, 98, 24);
    Title7->setBounds (16 + 96 - -410, 211, 100, 16);
    PERKB_PWM->setBounds ((16 + 0) + 98 - -413, 229, 96, 96);
    Title8->setBounds (16 + 96 - -510, 211, 100, 16);
    PERKB_HPFREQ->setBounds (getWidth() - 216, 229, 96, 96);
    Title9->setBounds (16 + 96 - -608, 211, 100, 16);
    PERKB_AMP->setBounds (getWidth() - 117, 229, 96, 96);
    Title10->setBounds (16 + 96 - -410, 48, 100, 16);
    WFB_PWM->setBounds (getWidth() - 315, 66, 96, 96);
    Title11->setBounds (16 + 96 - -510, 48, 100, 16);
    WFB_Shaper->setBounds (getWidth() - 216, 66, 96, 96);
    Title12->setBounds (16 + 96 - -204, 48, 100, 16);
    WFA_Shaper2->setBounds (getWidth() - 522, 66, 96, 96);
    Title13->setBounds (16 + 96 - -613, 47, 100, 16);
    WFA_Shaper3->setBounds (getWidth() - 113, 65, 96, 96);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabWaveforms" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="360">
  <BACKGROUND backgroundColour="323e44">
    <IMAGE pos="0 -66 840 490" resource="background1_jpg" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <JUCERCOMP name="WFA" id="7f2b83568bc74387" memberName="WFA" virtualName=""
             explicitFocusOrder="0" pos="16 48 96 120" sourceFile="../Components/OSCEditor.cpp"
             constructorParams="synthState, &quot;WFA&quot;"/>
  <JUCERCOMP name="WFB" id="3980a735eeaa4277" memberName="WFB" virtualName=""
             explicitFocusOrder="0" pos="426 48 100 112" sourceFile="../Components/OSCEditor.cpp"
             constructorParams="synthState, &quot;WFB&quot;"/>
  <JUCERCOMP name="PERKA" id="b67e636837fe23b5" memberName="PERKA" virtualName=""
             explicitFocusOrder="0" pos="16 212 96 112" sourceFile="../Components/OSCEditor.cpp"
             constructorParams="synthState, &quot;PERKA&quot;"/>
  <LABEL name="Title" id="1298f19adf91ae02" memberName="label_WFA" virtualName=""
         explicitFocusOrder="0" pos="0 20 98 24" posRelativeX="7f2b83568bc74387"
         bkgCol="ffed6216" edTextCol="ff000000" edBkgCol="0" labelText="WF A"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="Title" id="20ddfe5157a31e7e" memberName="Label_WFB" virtualName=""
         explicitFocusOrder="0" pos="0 20 96 24" posRelativeX="3980a735eeaa4277"
         bkgCol="ffed6216" edTextCol="ff000000" edBkgCol="0" labelText="WF B"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="label_perkA" id="577d7910af9dfd2b" memberName="label_perkA"
         virtualName="" explicitFocusOrder="0" pos="0 -28 98 24" posRelativeX="b67e636837fe23b5"
         posRelativeY="b67e636837fe23b5" bkgCol="ff397daa" edTextCol="ff000000"
         edBkgCol="0" labelText="PERK A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="new label" id="4bbeb0561535668a" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="0R 48 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="PWM&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFA_PWM" id="6dc4e4d5157c3da" memberName="WFA_PWM" virtualName=""
             explicitFocusOrder="0" pos="725R 66 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFA_PWM&quot;"/>
  <LABEL name="new label" id="20cb7c605be9b700" memberName="Title3" virtualName=""
         explicitFocusOrder="0" pos="-100R 48 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="Shaper" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFA_Shaper" id="38ab92d5c01dd24b" memberName="WFA_Shaper"
             virtualName="" explicitFocusOrder="0" pos="626R 66 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFA_Shaper&quot;"/>
  <LABEL name="new label" id="5a32b5c2f6d25c05" memberName="Title4" virtualName=""
         explicitFocusOrder="0" pos="728R 212 100 16" bkgCol="fff0f8ff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="PWM&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <JUCERCOMP name="PERKA_PWM" id="2f54030abd37d923" memberName="PERKA_PWM"
             virtualName="" explicitFocusOrder="0" pos="725R 230 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;PERKA_PWM&quot;"/>
  <LABEL name="new label" id="ad3a513f7073d4af" memberName="Title5" virtualName=""
         explicitFocusOrder="0" pos="-100R 212 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="HP FREQ" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="PERKA_HPFREQ" id="8cf17791916897fc" memberName="PERKA_HPFREQ"
             virtualName="" explicitFocusOrder="0" pos="626R 230 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;PERKA_HPFREQ&quot;"/>
  <LABEL name="new label" id="8092e87417e52596" memberName="Title6" virtualName=""
         explicitFocusOrder="0" pos="-198R 212 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="AMP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="PERKA_AMP" id="587db963e5f465ac" memberName="PERKA_AMP"
             virtualName="" explicitFocusOrder="0" pos="527R 230 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;PERKA_AMP&quot;"/>
  <JUCERCOMP name="PERKB" id="805277eefae212c4" memberName="PERKB" virtualName=""
             explicitFocusOrder="0" pos="426 211 96 112" sourceFile="../Components/OSCEditor.cpp"
             constructorParams="synthState, &quot;PERKB&quot;"/>
  <LABEL name="label_perkB" id="4d53d1b1bc98d3eb" memberName="label_perkB2"
         virtualName="" explicitFocusOrder="0" pos="410 -29 98 24" posRelativeX="b67e636837fe23b5"
         posRelativeY="b67e636837fe23b5" bkgCol="ff397daa" edTextCol="ff000000"
         edBkgCol="0" labelText="PERK B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="new label" id="ff0a15d235c6c65c" memberName="Title7" virtualName=""
         explicitFocusOrder="0" pos="-410R 211 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="PWM&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="PERKB_PWM" id="e85773c0439b0a4b" memberName="PERKB_PWM"
             virtualName="" explicitFocusOrder="0" pos="-413R 229 96 96" posRelativeX="1298f19adf91ae02"
             sourceFile="../Components/SourceMixerComponent.cpp" constructorParams="synthState, &quot;PERKB_PWM&quot;"/>
  <LABEL name="new label" id="2159a76c8cc4ee0a" memberName="Title8" virtualName=""
         explicitFocusOrder="0" pos="-510R 211 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="HP FREQ" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="PERKB_HPFREQ" id="87c1ff4f7bc34756" memberName="PERKB_HPFREQ"
             virtualName="" explicitFocusOrder="0" pos="216R 229 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;PERKB_HPFREQ&quot;"/>
  <LABEL name="new label" id="8981983e4b695732" memberName="Title9" virtualName=""
         explicitFocusOrder="0" pos="-608R 211 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="AMP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="PERKB_AMP" id="c528b4bf745f7e4e" memberName="PERKB_AMP"
             virtualName="" explicitFocusOrder="0" pos="117R 229 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;PERKB_AMP&quot;"/>
  <LABEL name="new label" id="6dbdc7b932a19d96" memberName="Title10" virtualName=""
         explicitFocusOrder="0" pos="-410R 48 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="PWM&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFB_PWM" id="8ba061d401a098c" memberName="WFB_PWM" virtualName=""
             explicitFocusOrder="0" pos="315R 66 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFB_PWM&quot;"/>
  <LABEL name="new label" id="79e14f7e55cdf688" memberName="Title11" virtualName=""
         explicitFocusOrder="0" pos="-510R 48 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="Shaper" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFB_Shaper" id="98f2b70d9c7fc60f" memberName="WFB_Shaper"
             virtualName="" explicitFocusOrder="0" pos="216R 66 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFB_Shaper&quot;"/>
  <LABEL name="new label" id="9e594b82a3588497" memberName="Title12" virtualName=""
         explicitFocusOrder="0" pos="-204R 48 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="AMP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFA_Shaper" id="2e243343b9ba97cc" memberName="WFA_Shaper2"
             virtualName="" explicitFocusOrder="0" pos="522R 66 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFA_Shaper&quot;"/>
  <LABEL name="new label" id="24df3b379b707fe9" memberName="Title13" virtualName=""
         explicitFocusOrder="0" pos="-613R 47 100 16" posRelativeX="7f2b83568bc74387"
         bkgCol="fff0f8ff" textCol="ff181f22" edTextCol="ff000000" edBkgCol="0"
         labelText="AMP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="WFA_Shaper" id="9f610db72eb81132" memberName="WFA_Shaper3"
             virtualName="" explicitFocusOrder="0" pos="113R 65 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;WFA_Shaper&quot;"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: background1_jpg, 51706, "../../../Resources/GUI/Background1.jpg"
static const unsigned char resource_TabWaveforms_background1_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,100,0,100,0,0,255,236,0,17,68,117,99,107,121,0,1,0,4,0,0,0,96,0,0,255,238,0,38,65,100,
111,98,101,0,100,192,0,0,0,1,3,0,21,4,3,6,10,13,0,0,22,176,0,0,23,123,0,0,89,7,0,0,201,248,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,2,1,2,2,2,2,2,2,2,2,3,3,3,3,
3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,3,2,2,3,4,3,3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,255,194,0,17,8,1,234,3,72,3,1,17,0,2,
17,1,3,17,1,255,196,0,175,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,2,3,4,9,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,5,16,0,2,2,1,5,1,1,1,1,1,0,0,0,0,0,0,0,1,16,17,32,48,64,80,2,18,49,96,33,65,192,17,0,1,2,
5,5,1,1,1,0,0,0,0,0,0,0,0,97,48,17,32,64,80,96,33,0,16,112,128,65,49,177,209,18,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,19,0,2,2,2,2,1,3,1,9,1,1,0,3,1,1,0,1,17,33,49,0,65,16,81,97,113,129,161,145,32,48,64,
96,240,177,193,209,225,80,241,112,128,144,160,192,255,218,0,12,3,1,0,2,17,3,17,0,0,1,249,177,211,227,160,66,4,32,66,4,32,66,4,32,66,4,32,39,164,244,30,137,174,247,59,133,83,9,198,222,103,51,40,24,48,17,
198,176,0,66,104,0,142,199,164,244,203,218,206,242,233,119,73,17,17,147,18,112,179,206,190,84,242,24,16,33,2,16,33,2,16,33,2,16,33,2,16,33,2,16,16,18,1,32,18,1,32,18,1,32,18,1,32,19,161,232,61,39,117,
218,116,136,201,202,223,50,121,12,129,26,32,3,6,4,128,208,153,33,59,30,147,210,189,83,188,186,93,86,136,136,78,49,134,124,246,249,147,202,121,192,72,4,128,72,4,128,72,4,128,72,4,128,72,4,128,64,64,132,
8,64,132,8,64,132,8,64,132,8,72,238,122,15,68,187,174,201,17,131,148,190,91,60,167,48,16,19,68,64,100,141,1,162,50,6,142,231,115,212,189,14,210,105,116,186,164,64,201,202,78,86,121,229,242,217,229,50,
4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,38,142,231,164,232,189,85,77,24,50,114,147,141,115,56,25,0,33,33,16,52,100,209,147,70,0,72,244,29,207,66,236,236,154,141,46,193,
117,89,9,56,217,201,124,201,229,56,1,8,16,129,8,16,129,8,16,129,8,16,129,8,16,128,128,144,9,0,144,9,0,144,9,0,144,9,17,216,236,117,59,69,117,179,9,71,59,48,115,49,25,174,64,2,70,136,200,128,16,145,163,
0,34,119,58,157,205,203,210,182,41,214,5,208,25,78,22,242,79,41,229,50,64,36,2,64,36,2,64,36,2,64,36,2,64,36,2,2,4,32,66,4,32,66,4,32,66,4,32,66,116,59,29,141,155,140,214,78,70,76,25,3,36,100,136,209,
144,32,33,2,17,19,32,66,117,54,118,52,108,234,186,58,166,163,70,76,215,9,124,246,121,142,0,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,34,119,58,29,0,14,38,14,96,68,68,108,
200,153,2,16,33,2,18,52,6,72,64,209,161,52,117,59,29,87,208,41,184,197,114,94,41,230,60,198,4,8,64,132,8,64,132,8,64,132,8,64,132,8,64,64,72,4,128,72,4,128,72,4,128,72,4,76,137,212,234,104,142,71,35,32,
36,2,104,4,200,9,0,144,9,0,154,0,32,18,1,34,59,30,163,178,247,52,128,47,40,243,89,230,56,128,144,9,0,144,9,0,144,9,0,144,9,0,144,8,8,16,129,8,16,129,8,16,129,8,16,145,160,50,104,238,104,10,57,86,64,201,
8,137,24,33,2,16,33,2,16,52,38,8,64,132,8,72,236,123,14,211,93,110,82,57,181,197,159,49,230,50,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,36,104,140,17,212,235,16,152,160,192,1,
8,0,16,129,8,16,129,8,26,19,4,32,66,2,64,108,245,158,153,123,86,146,50,188,227,205,103,152,226,4,32,66,4,32,66,4,32,66,4,32,66,4,32,32,36,2,64,36,2,64,36,2,64,36,2,104,140,144,157,141,192,102,178,96,136,
136,200,9,0,144,9,0,144,8,137,146,1,32,54,64,4,122,15,97,217,174,140,196,115,107,139,62,99,202,4,2,64,36,2,64,36,2,64,36,2,64,36,2,2,4,32,66,4,32,66,4,32,66,4,32,38,128,200,157,4,209,200,8,8,209,144,16,
33,2,16,33,2,16,19,70,8,64,132,141,17,130,61,7,164,244,203,210,196,140,175,40,243,89,192,243,144,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,26,19,36,38,204,0,8,9,179,0,
32,66,4,32,66,4,32,71,67,153,8,16,128,155,48,7,83,214,119,151,189,41,17,197,174,108,249,79,57,129,2,16,33,2,16,33,2,16,33,2,16,33,1,1,32,18,1,32,18,1,32,18,1,34,34,35,102,76,155,2,1,1,16,2,1,32,19,66,
116,2,57,129,145,33,32,1,32,18,34,35,161,220,245,155,107,162,105,50,101,174,44,241,60,167,32,18,1,32,18,1,32,18,1,32,18,1,32,16,16,33,2,16,33,2,16,33,2,18,54,100,201,8,144,17,179,38,140,154,2,3,36,32,
66,116,58,29,68,209,144,57,25,56,145,208,201,129,2,16,33,2,52,122,78,199,121,117,110,145,50,184,147,141,156,79,40,1,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,9,161,19,152,8,136,0,
154,32,34,32,50,66,2,116,59,29,78,166,229,141,24,51,103,51,137,200,232,71,35,152,16,129,8,17,163,169,216,236,110,52,186,180,50,83,62,106,226,112,2,16,33,2,16,33,2,16,33,2,16,33,1,1,32,18,1,32,18,1,32,
18,35,161,179,38,76,1,161,50,70,128,209,144,35,70,72,128,77,29,142,199,115,164,215,75,54,128,152,92,25,48,8,28,206,7,51,38,72,128,72,14,135,83,70,206,134,205,202,219,153,49,103,156,243,152,32,18,1,32,
18,1,32,18,1,32,18,1,1,2,16,33,2,16,33,2,16,35,161,208,212,39,42,230,4,104,140,26,52,96,4,13,17,146,16,58,29,206,231,101,236,116,147,107,160,32,76,5,6,23,6,14,41,131,6,0,14,64,32,104,209,27,59,157,205,
75,171,113,51,198,184,30,112,16,33,2,16,33,2,16,33,2,16,33,2,16,33,2,16,33,2,16,33,3,71,67,99,9,138,230,96,141,17,129,52,100,72,136,140,144,145,208,236,122,14,211,93,238,122,198,154,221,68,70,96,36,201,
148,205,114,92,153,57,166,14,103,35,136,1,8,17,220,245,29,151,74,70,46,120,30,99,144,129,8,16,129,8,16,129,8,16,129,8,8,9,0,144,9,0,144,9,0,137,208,209,184,4,229,92,200,72,200,145,160,34,32,2,3,66,117,
61,39,162,94,246,118,151,165,186,16,34,32,0,140,36,97,49,89,94,103,36,243,156,78,2,64,36,116,61,71,170,93,91,163,156,156,108,243,158,115,2,64,36,2,64,36,2,64,36,2,64,32,32,66,4,32,66,4,32,66,6,141,16,
157,76,129,204,201,162,48,71,64,34,50,34,96,132,141,26,61,7,165,125,7,120,218,245,172,154,2,34,32,24,197,16,38,19,157,113,94,9,228,56,1,8,17,212,246,30,137,123,88,2,242,56,39,148,226,4,32,66,4,32,66,4,
32,66,4,32,66,4,32,66,4,32,66,4,36,70,204,154,35,96,70,8,76,1,163,70,72,200,155,48,2,36,7,115,212,122,87,178,119,151,118,232,201,160,33,50,104,201,163,34,115,140,39,59,60,178,249,108,243,9,204,128,143,
73,235,61,43,209,55,24,172,47,158,60,214,121,142,100,32,66,4,32,66,4,32,66,4,32,32,36,2,64,36,2,64,36,32,36,32,32,117,1,50,96,8,208,9,129,18,19,32,104,209,131,71,168,244,175,164,235,39,102,181,72,9,0,
128,153,52,4,98,57,51,202,223,42,113,56,152,56,137,163,212,123,87,178,118,150,19,146,113,183,206,158,67,206,64,36,2,64,36,2,64,36,2,64,32,32,66,4,32,66,4,32,38,206,98,108,200,8,9,178,50,70,8,209,163,153,
161,33,50,4,66,38,78,167,172,238,190,148,235,47,91,99,64,66,100,208,9,147,64,6,100,226,156,109,243,167,3,202,96,143,65,237,59,175,166,69,173,214,34,78,22,112,95,50,121,14,66,4,32,66,4,32,66,4,32,66,4,
32,66,4,32,66,4,32,108,140,9,162,48,116,48,6,132,128,201,26,34,18,32,16,2,52,6,77,30,131,210,119,95,74,110,94,182,164,68,38,77,25,18,34,3,156,156,147,141,190,52,241,137,216,245,30,133,239,38,218,235,64,
152,142,105,194,188,233,228,60,192,4,32,66,4,32,66,4,32,66,2,2,64,36,2,64,36,6,132,0,141,17,145,32,1,32,18,35,100,38,64,13,9,130,17,50,70,143,73,234,59,47,162,77,181,210,145,2,16,16,33,2,50,98,78,54,112,
94,8,157,87,178,117,142,141,116,168,64,12,73,201,60,246,249,83,202,112,18,1,32,18,1,32,18,1,32,16,16,33,2,16,33,2,17,16,50,38,136,193,176,50,32,66,4,38,142,132,114,50,36,104,140,145,160,50,38,207,65,235,
59,47,121,58,53,186,72,136,64,136,136,136,201,137,57,166,6,181,27,93,174,169,16,34,50,115,147,141,158,101,242,39,152,193,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,26,18,3,34,104,140,26,19,36,4,32,66,
104,232,71,35,38,132,132,201,147,100,100,128,234,122,143,66,247,59,73,182,186,86,128,132,8,136,132,8,12,198,81,21,107,96,66,4,32,115,142,108,249,237,242,167,148,243,144,129,8,16,129,8,16,129,8,8,9,0,144,
9,0,144,154,3,36,70,136,201,27,50,100,72,4,128,217,208,142,64,104,128,141,25,3,68,96,72,232,122,143,68,189,235,188,155,107,116,136,8,17,17,16,128,129,17,17,8,8,17,65,92,228,227,103,157,124,73,230,50,2,
64,36,2,64,36,2,64,32,32,66,4,32,66,2,108,8,200,9,162,48,34,38,64,132,8,68,232,38,0,209,147,36,34,0,104,12,144,157,15,81,232,94,231,105,58,53,210,131,70,68,136,136,76,154,50,36,68,68,6,140,137,17,24,142,
108,249,173,243,167,136,224,32,66,4,32,66,4,32,66,4,32,66,4,32,66,6,205,9,200,128,142,134,76,137,160,19,4,32,66,71,67,160,16,156,142,98,104,13,25,35,70,0,64,234,122,143,68,189,236,239,26,107,173,6,140,
154,2,19,38,140,154,50,104,8,76,154,50,104,201,160,34,56,201,202,207,42,249,83,198,64,66,4,32,66,4,32,66,2,2,64,36,2,64,104,78,167,48,48,34,70,140,1,163,70,64,128,72,4,234,110,52,53,152,231,92,132,141,
24,52,38,77,25,50,36,116,61,71,165,123,39,162,93,47,90,201,160,18,1,1,50,104,4,128,76,154,50,104,4,128,193,198,103,133,190,68,242,156,4,128,72,4,128,72,4,128,64,64,132,8,64,132,142,164,7,33,1,54,100,200,
137,26,48,2,4,32,108,244,69,80,156,78,66,104,200,16,155,32,50,100,132,234,122,79,82,246,78,242,238,222,134,77,1,9,147,64,38,77,1,9,147,64,38,77,1,9,131,18,121,172,224,190,36,243,153,33,2,16,33,2,16,33,
2,16,33,2,16,33,52,108,209,196,200,128,154,35,2,70,136,140,144,16,129,163,185,163,64,100,226,108,201,128,35,66,104,201,25,50,32,118,61,71,169,123,73,232,93,91,162,34,33,50,104,200,145,17,16,26,50,36,68,
68,114,147,154,121,87,203,103,144,230,66,4,32,66,4,32,66,2,2,64,36,2,68,108,232,96,201,144,17,18,50,6,132,4,140,9,0,137,212,232,108,76,129,152,205,113,50,108,136,13,25,52,100,200,145,216,245,158,165,237,
39,117,221,176,129,16,128,129,17,17,8,8,17,8,17,147,140,156,107,200,158,51,137,0,144,9,0,144,9,0,128,129,8,16,129,26,54,104,201,204,4,4,208,25,18,52,2,70,64,132,8,232,118,54,104,76,153,57,156,4,72,140,
26,52,4,6,72,79,65,235,61,75,222,58,46,234,33,2,16,34,34,34,33,2,16,33,0,57,201,231,179,204,190,68,242,128,129,8,16,129,8,16,129,8,16,129,8,17,163,98,100,192,8,26,16,50,36,104,0,209,24,33,2,52,118,58,
29,13,129,131,145,192,132,12,128,154,34,32,50,34,122,143,106,247,78,242,244,181,34,34,16,34,34,34,33,2,16,33,2,57,201,197,60,214,249,19,200,96,64,132,8,64,132,8,64,64,72,4,128,72,78,132,115,2,1,17,0,1,
52,0,34,0,2,64,117,59,27,58,137,131,7,16,35,153,129,52,6,140,144,129,145,58,158,179,216,189,228,234,215,74,8,132,4,8,136,136,64,64,136,64,132,229,24,103,203,111,145,60,135,48,18,1,32,18,1,32,16,16,33,
2,16,35,102,140,17,146,16,52,32,100,72,208,25,35,66,100,128,132,142,231,83,169,26,48,96,193,131,129,162,3,70,68,200,136,25,19,214,122,151,214,157,165,233,106,68,6,140,154,2,34,32,52,100,72,136,136,8,225,
39,10,242,167,140,224,32,66,4,32,66,4,32,66,4,32,66,4,116,50,104,192,16,129,163,70,76,136,26,52,115,33,19,70,0,132,13,158,131,103,81,134,176,96,226,114,52,96,128,4,140,137,179,0,117,61,167,169,125,81,
210,221,9,147,70,77,25,52,4,38,77,25,52,100,208,16,153,52,96,196,158,106,243,167,132,243,136,16,129,8,16,129,8,8,9,0,144,9,9,163,38,68,128,77,1,0,9,179,32,64,104,141,24,32,17,58,29,205,157,68,163,157,
115,48,115,50,115,1,52,100,136,141,152,19,212,123,151,209,39,117,233,104,32,32,32,36,2,2,100,208,9,0,129,28,100,229,103,141,124,137,230,1,32,18,1,32,18,1,1,2,16,33,2,58,25,2,2,18,52,38,0,64,209,163,153,
8,26,35,70,8,8,217,208,236,116,58,148,21,204,228,100,243,1,162,35,71,50,17,32,59,158,195,216,118,151,173,186,50,104,4,201,160,33,50,104,4,201,160,33,50,104,201,206,79,61,158,115,194,121,200,8,64,132,8,
64,132,8,64,132,8,64,141,9,129,2,18,52,70,8,64,217,24,33,2,54,2,6,72,77,157,78,198,142,132,96,228,115,56,17,163,34,70,64,72,72,209,238,61,107,232,142,182,232,128,209,145,34,34,19,38,140,137,17,17,0,156,
36,229,94,68,241,158,97,2,16,33,2,16,33,1,1,32,18,1,33,32,1,32,52,36,100,128,77,17,146,1,32,52,36,0,2,116,58,157,77,137,28,142,103,18,50,104,8,0,4,72,79,97,236,95,76,157,90,221,66,2,4,66,4,32,32,68,32,
66,115,49,39,158,188,169,227,56,0,144,9,0,144,9,0,128,129,8,16,129,8,16,129,8,137,24,33,3,66,96,132,8,64,77,16,0,17,216,232,117,54,7,51,153,192,8,136,208,25,16,35,96,122,143,106,250,100,234,189,109,136,
64,136,136,136,132,8,136,136,136,201,198,103,207,111,149,60,103,17,2,16,33,2,16,33,2,16,33,2,16,33,2,16,33,17,35,4,32,104,76,128,129,8,16,136,144,1,29,142,166,200,201,147,145,200,128,141,153,1,2,52,39,
160,246,203,232,179,180,189,45,209,8,16,129,8,16,129,8,17,16,24,147,138,121,151,203,103,144,230,32,66,4,32,66,4,32,32,36,2,64,36,2,64,36,6,200,0,128,77,17,146,1,32,18,1,17,33,48,108,236,104,209,144,8,
231,92,136,68,201,0,144,29,79,65,234,94,231,105,54,186,93,84,104,8,136,136,64,64,136,64,140,156,164,229,103,153,124,137,229,0,18,1,32,18,1,32,16,16,33,2,16,33,2,16,35,66,64,100,132,13,9,144,16,33,2,16,
35,68,70,132,235,13,68,80,28,235,38,13,1,146,16,33,52,122,79,73,217,174,140,244,141,44,108,202,232,213,66,36,6,140,137,17,17,147,156,153,79,45,188,19,200,112,1,2,16,33,2,16,33,2,16,33,2,16,33,2,16,35,
66,70,64,132,13,26,48,2,4,32,66,4,32,104,142,162,106,49,65,163,2,115,19,36,4,32,66,39,115,210,117,93,75,210,192,217,38,161,54,168,154,5,213,6,140,154,50,80,38,1,56,91,202,60,150,121,206,68,32,66,4,32,
66,4,32,32,36,2,64,36,2,64,36,38,136,230,36,2,104,8,0,72,4,128,68,13,153,52,100,217,1,144,16,34,32,18,1,32,52,122,13,29,77,1,160,52,43,208,78,134,145,141,130,236,201,163,36,129,146,174,75,131,204,156,
15,49,16,9,0,144,9,0,144,8,8,16,129,8,16,129,8,17,208,0,0,132,13,26,48,2,4,36,34,68,38,77,24,34,52,64,0,66,4,32,66,4,36,117,58,129,146,48,32,116,52,118,54,109,122,69,90,3,70,77,24,34,140,5,114,78,71,152,
192,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,9,162,50,64,66,6,132,8,136,141,25,18,34,32,2,2,17,18,50,2,4,32,66,4,34,104,76,153,32,33,1,54,116,58,27,52,70,204,154,3,38,72,140,145,192,228,64,66,4,32,
66,4,32,66,2,2,64,36,2,64,36,2,104,136,12,137,0,136,145,17,9,147,70,8,136,68,200,9,0,154,34,0,34,1,32,18,35,96,100,136,4,128,72,4,77,9,163,6,200,76,0,9,160,50,100,4,128,72,4,128,72,4,128,64,64,132,8,64,
132,8,64,208,145,129,2,16,52,38,64,64,141,9,146,2,17,32,2,16,19,68,68,6,68,8,64,209,163,32,64,70,128,64,8,64,132,8,64,141,9,146,2,52,100,132,8,64,132,8,64,132,8,64,132,8,64,132,8,64,132,4,209,24,16,33,
3,66,6,68,8,77,0,1,9,26,3,36,32,70,204,137,16,144,16,145,25,2,17,54,32,100,12,144,129,8,16,129,9,26,3,36,32,66,4,32,66,4,32,66,4,32,32,36,2,64,36,2,64,36,66,0,36,2,34,0,2,64,116,3,2,64,38,204,144,0,145,
162,35,2,32,36,2,0,34,116,54,49,25,174,103,49,32,18,1,32,52,68,2,64,64,36,2,64,36,2,64,36,2,64,32,32,66,4,32,66,4,32,66,4,32,66,6,132,140,8,16,136,153,2,16,52,116,48,100,128,78,134,204,145,200,136,8,64,
141,145,216,208,144,1,231,2,54,70,76,136,17,178,54,100,0,76,128,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,8,16,129,163,64,100,128,132,217,17,204,132,14,198,141,28,192,201,179,172,21,163,
37,24,168,193,8,27,19,100,116,34,3,153,200,14,160,104,230,100,12,155,19,102,77,28,136,12,144,129,8,16,129,8,16,129,8,16,128,128,144,9,0,144,9,0,144,9,0,144,9,163,66,96,201,17,163,71,67,0,96,14,166,205,
198,107,81,145,42,13,25,52,100,209,152,72,13,86,77,9,178,54,71,32,48,104,201,163,35,1,154,76,26,50,104,230,6,64,72,4,128,72,4,128,72,4,128,72,4,4,8,64,132,8,64,132,8,64,132,8,64,209,179,70,64,201,177,
54,48,152,172,154,24,208,86,140,154,2,19,38,140,154,50,104,8,76,154,19,102,77,144,17,147,38,77,25,52,1,26,50,102,178,39,50,48,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,66,4,32,104,72,64,
208,154,3,113,17,16,129,163,52,145,17,16,26,50,36,81,21,64,104,13,8,17,1,147,70,68,138,0,160,193,28,200,128,132,8,64,132,8,64,132,8,64,132,8,64,136,136,136,136,136,136,136,136,136,136,136,136,136,216,
8,27,35,102,68,136,128,232,6,204,68,4,52,26,50,104,196,104,10,183,1,163,21,184,205,36,2,6,163,6,204,137,154,201,28,141,24,2,34,34,34,34,34,34,34,34,34,34,34,34,34,63,255,218,0,8,1,1,0,1,5,2,222,47,224,
144,177,248,89,232,179,209,103,173,84,46,212,33,56,188,220,49,161,141,115,200,88,92,246,116,122,61,22,122,44,189,5,138,19,132,197,163,67,59,46,121,11,11,150,49,173,74,205,9,136,79,66,161,195,31,54,161,
77,197,141,195,135,179,66,237,9,150,92,94,76,103,110,109,10,22,12,177,189,186,98,101,137,150,89,98,120,56,99,31,52,161,97,101,140,178,246,246,34,197,216,177,50,203,193,199,100,53,205,168,184,245,30,139,
202,246,182,122,23,99,208,187,69,224,225,143,157,177,151,192,166,39,9,224,198,53,207,212,87,0,132,197,139,86,49,243,87,195,33,23,147,67,231,110,47,122,177,76,89,49,161,243,74,111,131,71,92,92,49,174,114,
248,68,196,44,63,198,49,143,153,91,10,40,72,162,138,216,161,125,20,184,99,252,74,80,145,69,30,74,40,125,101,45,101,11,22,135,200,214,217,66,83,81,69,20,52,121,150,180,209,98,115,101,203,67,227,214,75,
100,166,162,162,138,40,242,81,228,104,242,81,90,9,202,101,151,139,31,27,88,86,205,66,138,138,138,138,40,162,162,138,60,148,121,40,163,206,118,122,16,156,208,198,191,12,133,133,69,99,81,81,81,69,31,10,
208,76,88,80,198,184,196,124,201,107,168,71,88,90,53,21,21,20,80,255,0,133,15,248,53,159,81,98,212,62,47,228,92,94,209,66,213,172,104,99,67,205,29,98,176,236,135,199,92,189,159,81,49,57,189,103,12,104,
166,86,61,126,33,96,227,176,248,229,164,244,20,161,71,93,139,142,200,168,115,254,164,117,193,195,25,219,141,172,89,254,99,90,104,235,9,235,184,106,26,30,9,29,81,81,82,212,49,161,174,50,247,22,39,23,163,
121,56,104,99,67,40,72,74,138,17,88,184,99,225,22,206,165,233,38,34,196,39,176,99,67,71,131,200,145,66,43,54,49,163,183,225,19,16,152,139,143,186,181,20,81,228,168,173,22,134,52,63,194,38,38,38,34,238,
62,235,214,171,26,24,215,40,179,121,60,19,17,112,191,187,199,12,104,124,13,109,152,138,213,76,76,69,139,120,225,141,15,129,123,53,139,213,76,177,50,196,247,142,24,214,249,31,236,61,154,213,88,166,38,38,
88,180,86,205,140,103,109,242,135,179,71,249,47,65,21,151,86,38,45,227,134,134,53,191,189,170,133,53,162,242,234,196,196,196,88,183,76,103,97,241,11,7,154,194,182,41,137,150,45,211,134,118,67,222,45,186,
62,139,97,88,38,33,56,189,211,24,214,241,110,22,110,62,106,33,49,9,197,222,229,140,99,221,161,237,214,84,63,233,85,15,69,202,58,177,23,187,103,97,242,138,22,21,15,89,9,136,91,134,161,140,237,202,172,42,
30,186,98,58,194,220,49,157,190,61,218,30,197,104,172,30,15,87,172,44,22,201,97,216,99,229,214,14,30,21,164,142,176,183,14,59,124,124,125,230,156,92,92,56,115,122,93,78,162,133,133,232,222,141,195,25,
219,129,91,107,132,240,122,203,234,16,183,44,236,62,97,56,188,30,178,16,163,238,221,157,142,220,202,121,86,170,16,162,235,108,216,198,199,204,172,28,181,166,133,244,88,222,197,203,31,51,90,53,164,161,
66,155,139,143,233,122,127,48,108,236,62,114,203,44,178,245,81,98,44,178,203,61,22,89,120,92,92,89,101,197,205,140,108,124,186,194,246,104,178,207,66,236,122,44,76,177,50,203,44,89,217,101,142,44,237,
202,86,233,77,150,122,61,22,122,19,44,76,184,178,226,203,44,178,230,225,143,241,246,61,4,203,19,61,30,139,61,150,122,61,30,143,71,162,203,44,124,43,229,172,178,207,69,158,139,44,178,203,44,245,249,90,
253,69,69,126,150,133,63,7,248,250,209,173,26,138,209,172,234,43,157,120,168,169,162,133,133,21,20,84,214,141,69,96,214,149,242,11,53,146,193,226,176,120,169,80,191,14,240,174,1,254,38,226,243,189,27,
209,184,178,226,203,155,202,230,249,135,178,122,75,52,56,122,47,127,255,218,0,8,1,2,0,1,5,2,255,0,165,187,255,218,0,8,1,3,0,1,5,2,255,0,165,187,255,218,0,8,1,2,2,6,63,2,75,119,255,218,0,8,1,3,2,6,63,2,
75,119,255,218,0,8,1,1,1,6,63,2,171,183,72,196,144,68,34,44,76,108,35,18,153,249,30,54,22,104,236,195,68,212,118,233,243,89,184,148,17,141,133,108,73,9,177,198,89,71,54,56,69,215,19,194,184,203,139,139,
20,204,240,192,68,77,139,60,72,99,97,24,146,22,120,191,135,72,26,244,199,56,183,148,1,176,68,73,101,127,221,99,226,98,48,152,160,9,177,36,17,8,132,71,20,230,232,123,105,151,110,165,55,136,132,66,34,182,
54,18,89,248,136,140,38,58,194,244,23,81,235,141,54,215,64,233,168,151,254,68,35,245,147,22,176,146,29,20,126,89,206,176,134,120,240,34,17,8,132,69,136,54,202,34,49,182,81,17,141,179,209,159,118,247,94,
235,221,123,7,181,95,255,218,0,8,1,1,3,1,63,33,198,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,
0,121,2,215,243,155,178,24,7,147,223,135,128,235,18,172,110,28,93,239,9,193,108,36,33,197,228,176,166,122,252,248,121,44,56,216,90,181,231,12,12,185,198,82,213,173,62,94,153,87,239,143,8,198,82,213,173,
62,9,222,27,193,107,206,19,156,211,128,249,54,214,158,14,152,49,147,26,191,124,172,188,100,70,175,223,19,194,248,194,60,158,252,62,8,198,49,174,177,92,50,150,173,105,242,202,90,181,167,203,41,106,214,
159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,5,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,
171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,
181,133,56,173,59,92,4,230,182,173,96,184,173,59,193,121,4,235,229,96,3,1,214,4,15,141,228,140,53,231,172,49,141,221,109,94,78,85,167,120,64,222,43,241,242,176,140,175,155,224,3,38,98,190,112,159,56,193,
186,97,171,88,80,106,165,59,224,39,53,181,107,10,113,90,118,184,71,63,24,217,138,249,88,70,4,230,182,173,99,70,43,78,240,222,44,128,107,229,96,94,218,239,52,226,127,230,48,76,87,206,53,129,27,167,171,
195,6,43,205,229,229,25,175,156,32,23,132,235,8,71,202,188,153,138,249,89,179,8,119,66,213,225,178,171,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,
173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,
192,78,107,106,214,20,226,180,237,112,19,154,218,181,194,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,
202,41,234,158,159,3,128,68,235,249,193,128,172,91,81,79,206,74,48,158,178,76,235,225,225,117,147,156,92,129,24,184,69,61,83,211,231,201,175,135,134,48,78,17,181,31,15,150,79,84,244,249,147,58,248,124,
134,39,85,225,225,191,92,211,148,122,119,231,27,143,3,51,174,241,170,192,93,227,83,175,135,131,9,89,70,162,159,156,241,131,132,19,233,240,240,86,6,241,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,
61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,
90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,193,156,233,101,125,222,122,96,172,106,102,94,216,198,121,100,9,198,62,243,199,44,124,251,228,43,8,198,82,213,173,62,89,75,86,
180,240,97,203,11,203,247,202,174,25,167,106,215,3,206,19,23,255,0,188,178,150,173,105,224,36,97,97,41,218,181,128,231,110,86,240,53,227,235,4,61,254,113,245,195,52,237,237,193,156,175,190,3,188,12,101,
45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,10,113,90,118,184,
9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,
156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,176,102,151,114,173,101,189,247,107,6,190,113,33,214,251,195,102,75,88,240,25,13,203,227,8,79,195,188,253,30,81,119,42,214,59,180,225,218,
195,129,67,173,247,134,202,114,248,194,48,39,53,181,107,59,85,167,120,51,171,242,173,103,119,123,181,135,1,16,223,156,38,74,107,94,152,240,88,109,111,9,190,181,222,12,234,239,86,176,220,53,167,107,128,
156,214,213,172,115,13,127,28,19,9,127,76,79,233,223,6,141,220,171,88,45,252,218,207,15,140,4,63,117,120,76,153,46,5,134,229,137,42,181,223,1,219,242,173,96,73,191,123,88,51,129,57,173,171,88,83,138,211,
181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,
92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,194,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,
158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,204,170,138,126,114,57,233,148,241,222,159,12,119,158,81,78,245,135,136,138,200,97,106,199,13,31,93,97,46,184,70,213,175,22,8,195,95,206,
176,21,194,41,234,158,159,40,167,170,122,124,162,158,169,233,224,195,56,138,122,167,167,204,218,135,122,120,50,88,203,249,211,196,94,79,32,201,96,192,119,167,237,132,198,8,192,143,123,196,189,241,149,
144,53,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,
173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,224,63,175,28,1,38,28,127,56,59,97,46,176,193,56,
109,105,225,42,78,28,53,56,235,88,248,102,153,93,99,226,137,199,94,113,44,39,25,73,199,90,229,148,181,107,79,150,82,213,173,62,89,75,86,180,248,17,135,173,55,225,242,202,90,181,167,195,56,12,67,139,247,
228,2,48,12,117,231,59,48,23,56,34,159,183,156,30,120,145,26,254,112,94,17,130,76,107,225,224,46,25,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,
148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,224,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,
167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,142,171,93,174,5,135,91,86,176,22,98,133,62,176,21,128,179,53,226,
214,16,149,95,43,24,78,72,205,111,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,2,195,173,171,200,4,223,135,120,183,140,127,126,152,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,
181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,2,195,167,56,81,49,79,119,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,214,2,70,48,135,95,56,17,233,
175,76,29,252,96,35,40,248,249,88,75,172,171,173,171,193,4,197,105,245,128,177,133,235,229,97,178,171,79,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,
90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,
167,107,128,156,214,213,174,17,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,27,194,8,157,119,167,192,43,3,33,235,69,111,
26,197,134,168,245,225,231,110,9,39,170,124,163,106,41,249,202,197,188,45,81,233,249,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,224,21,136,144,245,94,252,162,158,169,233,242,138,122,
167,167,202,41,234,158,159,19,200,168,245,225,240,111,17,1,234,159,156,188,49,132,7,170,200,70,6,34,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,
167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,
242,202,90,181,167,194,88,201,11,86,188,242,16,89,88,245,193,51,141,103,190,218,211,195,139,39,178,188,172,188,168,213,173,60,79,30,51,78,45,121,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,
45,90,211,224,78,52,20,171,247,229,148,181,107,79,150,82,213,173,62,89,75,86,180,248,37,135,231,202,211,192,216,49,176,165,95,190,86,25,195,27,43,199,113,154,215,90,124,178,150,173,105,242,202,90,181,
167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,240,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,
133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,89,224,87,
202,202,205,205,57,88,83,138,211,181,131,1,68,117,242,178,13,103,76,135,250,172,32,200,21,243,158,112,34,102,182,175,10,6,43,78,242,241,163,53,242,176,217,85,175,78,2,115,91,86,176,167,21,167,107,128,
156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,179,113,90,118,178,240,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,16,
221,109,94,20,12,86,157,231,156,9,205,109,90,200,113,79,221,103,254,216,177,126,123,192,93,87,202,202,156,8,153,173,171,194,133,86,157,225,14,113,55,95,43,4,207,198,91,2,115,91,86,176,167,21,167,107,128,
156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,
9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,174,17,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,
213,61,62,67,51,175,135,135,137,189,83,215,6,177,67,249,243,146,244,199,214,74,122,248,124,94,72,157,124,60,60,34,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,
240,47,11,19,175,135,202,41,234,158,159,40,167,170,122,124,9,194,196,168,248,124,140,53,29,249,188,45,96,192,200,122,175,15,12,96,156,135,161,250,60,93,241,141,168,239,207,40,167,170,122,124,162,158,169,
233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,
90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,184,79,219,4,225,198,82,213,173,60,121,172,106,101,58,229,148,181,107,79,144,98,252,242,202,90,181,167,203,41,106,214,159,
44,165,171,90,124,178,150,173,105,242,202,90,181,167,200,49,126,220,178,150,173,105,242,202,90,181,167,200,49,127,251,201,169,195,172,253,127,124,39,251,227,143,29,121,193,56,99,25,219,111,33,88,24,219,
67,172,5,195,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,5,56,173,59,92,4,230,182,173,
97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,122,
53,252,112,19,154,218,181,133,56,173,59,88,51,171,242,173,97,223,174,237,112,155,167,43,172,54,83,90,203,193,97,214,253,48,142,171,78,241,98,144,235,197,172,10,87,123,181,135,2,115,91,86,176,167,21,167,
107,128,156,214,213,172,41,197,105,218,224,92,181,181,107,36,211,78,31,89,227,241,129,135,91,239,12,204,150,184,216,54,190,87,190,16,140,86,157,240,19,154,218,181,144,226,156,59,88,124,100,48,235,125,
225,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,106,111,250,100,74,173,119,133,223,182,58,125,234,214,119,119,14,215,8,135,78,123,
203,20,250,96,97,18,27,237,233,134,202,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,
43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,112,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,
138,122,167,167,202,41,234,158,159,40,167,170,122,124,163,106,29,242,138,122,167,167,131,12,226,55,170,122,124,163,104,203,219,129,231,8,138,255,0,220,30,112,248,196,85,110,252,242,138,122,167,167,202,
54,163,189,103,102,46,176,170,182,189,242,121,250,198,61,163,43,195,143,60,34,96,123,226,92,17,61,119,231,8,60,34,158,169,233,242,138,122,167,167,202,41,234,158,159,33,218,41,175,24,14,26,188,215,243,
231,11,188,244,192,214,30,9,106,222,220,8,88,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,
167,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,205,107,175,56,50,83,134,174,45,121,197,195,41,106,214,158,92,96,140,39,90,181,167,
194,120,244,225,215,158,100,70,190,30,25,193,24,78,181,240,249,101,45,90,211,228,15,183,195,196,224,98,49,48,181,214,158,12,115,154,78,58,243,157,214,16,56,227,211,227,27,144,56,137,8,87,195,197,220,97,
108,100,214,173,121,229,148,181,107,79,150,82,213,173,62,65,53,174,188,241,24,32,141,117,167,141,224,43,24,198,190,30,81,98,120,76,39,229,121,196,78,11,201,173,90,215,44,165,171,90,124,178,150,173,105,
242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,5,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,
214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,131,1,150,107,229,97,82,158,47,252,200,123,95,198,27,42,180,250,225,28,214,213,225,68,
197,105,222,28,9,205,109,90,198,53,90,118,177,111,1,17,250,57,0,197,121,199,129,57,173,171,89,117,94,111,14,4,230,182,173,97,78,43,78,215,1,57,173,171,88,46,43,229,96,193,0,244,218,188,64,213,121,181,
128,119,129,136,117,227,172,67,250,239,138,31,171,194,167,199,202,194,213,145,61,54,175,8,19,13,105,222,32,188,66,124,124,172,4,172,56,87,191,107,194,141,87,241,198,230,183,222,20,226,180,237,112,19,154,
218,181,133,56,173,59,92,80,253,253,48,17,237,242,177,245,136,51,80,214,41,49,79,120,49,102,107,229,97,35,22,240,175,215,88,0,18,171,229,112,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,
107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,
118,184,9,205,109,90,225,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,67,79,161,249,193,214,44,246,240,244,240,224,226,41,234,158,159,21,132,18,44,171,
128,30,123,27,94,31,40,167,170,122,124,86,22,154,138,126,121,69,61,83,211,228,2,159,70,75,4,96,34,30,168,122,224,136,225,61,120,240,248,39,145,13,21,85,188,150,67,28,135,170,247,194,22,28,159,3,105,233,
225,223,14,88,74,138,126,125,241,79,140,142,50,116,42,183,132,46,17,79,84,244,248,120,200,155,20,214,248,128,24,68,207,161,249,205,24,156,231,177,180,244,248,75,8,3,149,94,248,120,69,61,83,211,229,20,
245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,
107,79,128,48,18,2,213,224,14,113,235,61,205,181,167,135,8,88,202,90,181,167,197,227,32,116,254,120,5,102,172,219,90,124,44,184,149,107,206,17,130,112,180,181,126,252,178,150,173,105,240,35,1,113,234,
247,200,100,176,18,35,86,188,224,15,43,27,178,155,94,115,198,66,178,72,90,181,231,18,214,39,146,2,108,90,243,192,140,62,190,215,156,88,87,19,11,87,239,132,70,23,194,225,42,214,22,156,49,140,165,171,90,
124,178,150,173,105,242,100,181,107,206,79,30,177,121,61,173,60,110,48,237,140,99,87,227,21,195,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,
178,150,173,105,242,202,90,181,167,193,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,
138,211,181,192,78,107,106,214,53,84,247,121,33,128,183,143,149,144,107,253,199,172,67,12,181,95,56,70,35,14,182,173,97,64,197,105,222,94,110,105,202,200,126,52,239,30,176,1,31,163,141,152,175,149,149,
129,19,53,181,120,80,61,31,190,88,120,19,154,218,181,133,56,173,59,92,35,156,39,170,249,79,41,132,211,173,171,200,6,42,83,188,151,211,4,39,76,122,226,4,254,171,30,176,1,141,152,175,149,149,130,76,215,
139,194,129,138,243,120,134,113,35,227,229,97,9,207,24,159,218,196,9,138,249,88,86,177,13,211,213,224,52,86,157,225,105,201,38,183,218,193,56,246,244,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,
156,86,157,174,6,138,215,202,196,39,244,115,198,33,191,247,13,158,181,233,155,134,38,122,124,224,128,98,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,
211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,215,8,167,170,122,124,162,158,169,233,242,138,
122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,240,50,100,43,225,227,225,166,162,159,156,148,112,137,244,175,124,172,19,146,39,95,15,149,13,71,126,112,30,248,211,53,240,248,24,88,157,
124,62,81,79,84,244,240,97,24,247,170,240,240,21,88,111,4,78,176,86,53,138,26,142,252,231,142,3,51,175,135,134,48,78,22,39,95,15,134,163,42,215,191,156,71,8,196,72,241,240,240,142,190,153,44,2,36,8,248,
121,179,35,24,141,233,167,231,148,83,213,61,62,92,78,190,30,6,240,96,131,94,254,114,112,140,68,216,143,140,68,224,57,196,125,169,235,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,
83,213,61,62,81,79,84,244,249,69,61,83,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,153,75,86,180,249,6,47,255,0,112,224,199,174,222,217,24,60,227,44,24,124,
96,49,243,239,203,41,51,42,215,30,184,73,173,117,200,49,127,251,135,134,82,213,173,60,21,131,206,50,33,251,121,194,126,188,17,39,183,128,224,192,73,56,117,174,4,222,19,24,60,225,241,128,198,31,28,51,78,
222,220,122,225,171,246,211,197,222,6,17,30,255,0,56,42,179,230,205,26,126,87,38,82,213,173,62,127,115,1,96,96,116,202,117,172,88,158,87,248,243,132,119,128,177,149,237,248,229,148,181,107,79,150,82,213,
173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,248,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,
107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,176,100,57,167,42,214,4,202,173,59,88,124,100,110,183,222,122,53,252,97,172,176,109,109,97,34,126,29,224,243,145,31,42,214,21,175,
155,88,112,39,53,181,107,10,113,90,118,176,86,11,13,203,227,19,84,225,218,224,92,214,213,172,220,87,155,88,124,100,67,247,239,10,113,90,118,184,70,29,109,97,82,171,93,240,82,46,229,90,195,146,157,238,
240,30,176,132,58,223,120,228,201,127,24,15,211,5,134,255,0,166,21,42,181,222,15,57,215,174,173,103,119,123,181,135,198,5,14,183,222,27,41,255,0,78,5,134,214,240,169,85,174,240,121,194,162,253,173,98,
187,184,118,176,49,13,251,171,198,18,154,215,166,20,197,33,180,254,49,117,90,239,128,156,214,213,172,1,194,180,237,100,145,128,35,173,247,138,74,114,142,0,144,218,254,51,110,181,222,46,253,176,42,239,
86,176,46,253,237,96,102,230,183,222,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,
133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,92,34,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,240,48,211,215,124,129,21,239,135,6,53,168,119,192,
201,94,62,48,21,146,201,211,107,144,13,168,119,174,89,60,17,134,112,8,175,124,51,194,41,234,158,158,12,17,132,111,84,245,193,60,40,253,44,7,128,59,86,188,7,4,97,17,130,48,206,1,24,103,132,109,67,190,4,
97,172,17,128,241,69,127,238,51,8,194,218,135,122,224,96,253,114,111,93,233,224,15,58,113,34,176,96,126,188,99,90,41,222,40,196,175,32,241,223,156,33,96,225,19,89,51,28,34,158,169,233,242,138,122,167,
167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,107,36,5,175,
231,129,121,38,53,240,243,92,81,56,181,231,144,117,175,135,134,112,70,18,107,93,114,14,181,107,206,45,231,238,114,68,107,225,225,156,172,100,195,139,90,224,141,227,41,106,214,159,50,150,175,195,224,21,
128,142,227,227,140,23,130,41,251,121,193,128,184,222,72,141,127,56,103,4,97,102,53,240,248,89,68,253,188,226,92,6,35,95,15,12,224,140,99,85,240,248,100,229,62,87,156,84,228,204,96,58,62,94,30,54,7,24,
17,141,124,100,56,2,130,126,222,113,44,51,25,34,13,124,96,60,33,70,9,33,107,225,224,107,14,50,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,
41,106,214,159,5,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,35,159,140,163,21,242,176,156,9,205,109,
90,205,197,105,245,149,150,89,175,149,133,56,173,59,88,183,145,31,61,172,41,197,105,218,224,92,181,181,107,13,195,90,118,184,9,205,109,90,194,156,86,157,174,1,17,250,57,104,175,149,132,5,129,3,53,181,
120,65,197,105,223,22,102,190,112,145,63,163,135,2,115,91,86,179,101,87,202,203,205,205,120,235,10,113,90,118,177,24,76,131,175,156,3,253,103,108,1,253,78,81,241,242,177,184,193,6,107,197,225,70,171,205,
229,101,153,175,156,36,98,222,2,50,140,87,206,94,4,46,188,94,20,76,87,155,202,194,25,122,223,107,18,85,124,230,220,1,237,111,8,3,21,230,214,0,214,12,25,173,171,197,53,79,120,10,48,49,241,242,178,3,197,
188,4,101,24,175,156,51,25,87,94,47,4,26,173,60,5,142,47,95,43,0,74,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,
224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,184,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,70,245,79,79,18,198,240,133,58,239,148,72,122,167,231,
60,112,42,161,167,167,139,132,83,213,61,62,81,79,84,244,249,155,211,189,98,207,24,136,4,234,159,156,190,17,79,84,244,240,28,91,205,81,233,233,242,136,15,84,252,225,158,17,79,84,244,241,56,91,200,26,61,
120,120,91,192,216,24,157,87,190,60,86,34,67,213,123,227,88,183,158,199,175,15,18,198,241,16,30,171,223,47,43,17,33,234,189,241,172,59,97,244,218,240,240,239,146,198,19,170,168,121,44,1,99,16,245,79,206,
84,98,222,123,30,188,60,75,27,196,64,122,175,124,51,134,61,240,132,53,20,252,228,35,140,54,182,188,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,
148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,228,85,195,107,79,30,177,44,39,90,235,207,45,5,42,253,243,207,1,211,242,180,241,188,56,202,90,181,167,203,41,106,214,159,44,165,171,90,120,
241,44,100,133,42,253,240,199,26,218,181,167,137,227,207,125,181,167,151,192,36,137,69,229,112,202,90,181,167,194,99,9,79,111,195,198,225,41,192,133,171,247,193,24,14,26,10,85,251,226,120,243,223,109,
105,227,120,150,50,99,87,239,149,151,141,5,171,247,196,241,172,94,118,214,158,120,89,12,184,149,107,206,37,137,227,65,106,215,156,79,30,123,237,173,60,111,18,198,194,149,126,249,88,67,200,5,166,253,241,
147,131,145,89,182,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,130,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,
197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,205,197,105,222,61,96,1,140,108,197,124,174,2,115,91,86,178,28,83,135,107,47,42,13,120,181,133,56,173,59,92,0,35,12,213,124,174,2,115,91,86,
176,167,21,167,107,128,156,214,213,172,41,197,105,218,225,35,229,99,117,95,56,99,46,233,134,175,33,197,105,229,227,70,107,229,98,56,249,235,30,0,35,12,152,249,235,128,137,154,218,188,77,83,135,124,4,230,
182,173,97,78,43,78,214,105,195,0,143,227,3,152,175,149,128,169,194,22,175,23,141,120,121,188,19,141,25,175,149,132,9,199,172,0,70,54,98,190,86,86,9,51,94,47,10,6,43,205,229,227,70,107,229,98,24,245,128,
8,198,204,87,202,202,193,38,107,197,225,131,21,230,242,241,163,53,242,176,129,56,245,128,8,198,204,87,202,202,193,38,107,197,228,36,87,155,88,67,156,129,241,130,159,140,235,132,0,124,111,181,133,56,173,
59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,92,34,158,169,233,242,
138,122,167,167,202,41,234,158,159,40,167,170,122,124,250,60,63,60,162,158,169,233,243,34,117,240,243,92,77,235,191,56,223,8,167,170,122,124,162,158,169,233,242,138,122,167,167,131,172,21,146,103,95,15,
1,96,60,128,122,248,120,184,242,162,159,156,111,132,76,251,61,60,172,19,132,111,95,207,51,122,239,206,105,56,140,50,103,95,15,2,97,57,201,18,43,225,224,156,106,49,67,81,223,156,111,128,204,235,225,225,
140,19,146,39,95,207,13,98,134,163,191,56,245,196,153,215,243,134,48,78,22,39,95,15,134,163,20,53,29,249,198,248,147,233,240,240,198,9,192,35,81,241,132,49,198,54,188,63,57,62,17,79,84,244,249,69,61,83,
211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,224,86,2,105,195,172,166,60,101,45,90,211,228,18,175,15,12,165,171,
90,121,172,19,120,126,58,243,203,41,106,214,159,44,165,171,90,120,50,87,154,184,235,0,120,66,201,87,15,231,32,99,137,173,117,167,139,4,222,19,23,130,114,176,24,191,253,195,195,41,106,214,159,26,142,3,
2,227,29,131,12,23,141,86,10,198,105,195,174,4,222,19,23,130,112,198,3,24,99,134,105,195,174,4,222,19,24,39,12,96,49,120,98,184,102,156,58,224,77,225,49,130,112,229,139,243,192,140,109,140,171,136,222,
50,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,193,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,
181,133,56,173,59,92,88,58,223,166,108,159,244,227,97,190,222,152,142,43,207,92,4,230,182,173,100,56,169,78,214,31,24,22,235,125,225,78,43,78,215,2,195,125,176,169,85,174,240,121,205,205,109,117,133,56,
173,59,92,4,230,182,173,97,78,43,78,215,1,48,233,207,166,68,170,211,190,29,93,234,214,119,119,14,214,28,136,116,231,188,41,197,105,218,193,130,196,150,240,169,85,174,248,136,191,42,214,119,119,187,88,
124,98,67,173,247,134,202,107,92,4,230,182,173,102,226,181,222,119,100,129,211,213,172,232,119,187,88,58,97,136,253,157,99,147,47,233,192,176,218,222,21,42,181,222,15,57,213,249,86,179,191,93,218,195,
227,18,31,191,120,108,166,181,192,176,223,244,194,165,86,187,193,231,58,245,213,172,238,238,29,172,62,48,40,117,190,240,217,79,250,112,44,54,183,133,74,173,119,131,206,117,235,171,89,221,248,118,176,226,
27,173,247,131,37,53,129,129,33,185,124,96,137,85,174,248,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,
90,194,156,86,157,174,2,115,91,86,184,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,241,101,49,27,70,94,220,145,79,84,244,249,2,48,240,138,122,167,167,130,176,69,225,5,87,40,167,170,122,
124,162,158,169,233,241,108,254,75,223,7,156,62,48,8,172,23,92,35,104,203,219,138,201,189,119,231,139,192,241,133,171,132,109,67,190,102,245,223,156,208,120,14,30,191,156,5,224,56,29,171,94,184,17,120,
68,86,12,62,48,8,195,194,54,173,237,192,139,194,35,7,156,62,48,8,195,53,194,54,173,237,192,139,194,35,7,156,56,4,86,3,145,135,9,104,203,219,6,51,179,8,55,167,122,124,162,158,169,233,242,138,122,167,167,
202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,224,197,148,78,45,121,207,60,50,150,173,105,240,47,11,49,175,135,154,225,148,
181,107,79,7,1,136,215,195,195,60,50,150,173,105,242,202,90,181,167,192,198,17,171,241,134,112,59,194,235,95,15,53,132,158,10,191,111,56,70,240,227,41,106,214,159,2,50,125,191,156,99,1,206,56,78,58,243,
139,134,82,213,173,62,52,28,45,56,248,226,44,16,78,45,121,228,24,141,124,60,51,130,50,76,107,249,225,60,112,156,117,231,22,248,12,70,190,30,25,193,24,89,141,124,62,19,156,112,156,117,231,18,158,36,122,
124,60,51,130,48,179,26,248,121,227,8,120,81,113,107,206,2,158,0,68,105,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,5,56,173,59,92,4,230,182,173,
97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,3,33,215,202,194,68,252,97,27,198,61,182,173,97,78,43,78,215,1,57,173,171,89,184,173,59,89,89,228,215,202,194,156,86,
157,174,45,53,148,98,190,86,92,96,66,233,234,241,11,85,230,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,67,138,249,88,79,2,6,107,106,242,13,84,167,121,80,114,71,199,202,194,67,63,205,226,222,
71,235,172,55,21,174,2,30,27,87,133,19,21,167,121,89,4,205,124,225,34,126,49,111,1,17,250,56,71,85,242,184,9,205,109,90,205,197,107,188,215,142,51,95,56,7,250,239,59,96,34,47,202,188,139,21,243,151,129,
11,167,171,194,137,138,243,121,88,153,154,249,88,72,197,188,4,98,70,43,229,101,224,131,53,226,240,201,138,243,121,88,153,154,249,88,72,197,188,4,70,36,98,190,86,94,4,12,215,139,194,141,83,221,229,98,102,
107,229,98,3,132,98,111,223,16,200,175,149,147,172,220,214,251,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,
156,86,157,174,2,115,91,86,184,69,61,83,211,229,20,245,79,79,148,83,213,61,62,64,38,117,79,206,67,19,194,124,27,94,30,30,17,79,84,244,248,24,137,15,84,252,225,235,132,83,213,61,60,24,222,16,68,235,191,
57,121,88,182,138,167,202,41,234,158,159,48,157,87,191,8,98,38,101,87,190,86,39,158,198,211,211,194,48,224,5,66,41,249,203,202,195,79,85,239,197,231,177,181,225,226,222,55,132,147,213,63,60,249,213,63,
60,38,243,192,109,120,120,59,193,167,120,136,157,87,190,94,86,38,30,171,223,26,196,243,216,218,240,241,111,27,196,68,234,189,242,242,177,19,58,175,124,107,22,243,216,218,122,120,150,55,137,7,170,247,203,
202,196,72,122,167,231,26,194,28,225,237,30,158,158,6,242,81,132,0,157,119,231,15,8,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,173,105,242,202,90,
181,167,203,41,106,214,159,32,144,22,186,243,128,231,26,207,115,109,105,242,202,90,181,167,192,15,25,1,106,215,156,61,240,202,90,181,167,131,18,194,92,106,215,156,5,101,225,174,151,239,203,41,106,214,
159,32,154,113,107,206,67,4,227,81,166,215,156,79,15,91,194,33,51,111,195,195,49,128,176,50,58,117,231,22,47,30,156,117,206,183,109,105,227,214,37,140,144,181,107,206,17,195,41,106,214,158,91,23,133,228,
219,240,241,145,130,48,16,45,127,57,89,120,200,141,95,190,39,141,103,185,239,195,199,172,75,25,49,171,247,202,203,198,68,106,253,241,60,122,207,115,223,135,141,226,88,216,90,191,124,172,188,100,5,171,
94,113,60,122,194,33,51,109,105,240,5,147,137,86,176,17,225,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,130,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,
214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,176,12,37,117,243,137,173,254,216,240,39,53,181,107,10,113,90,118,184,9,205,109,90,202,170,112,239,47,54,1,175,149,133,56,173,59,92,11,14,156,
250,101,152,175,149,132,96,78,107,106,214,52,213,105,222,94,67,14,190,86,20,226,180,237,112,19,154,218,181,133,56,173,59,92,27,51,94,48,161,85,167,120,38,113,128,186,249,88,64,159,209,195,136,255,0,126,
240,26,43,231,58,50,13,215,139,200,85,105,223,27,14,182,173,98,26,173,99,214,0,35,244,112,217,85,252,112,17,51,91,87,128,28,86,157,240,44,58,218,188,33,231,195,188,211,139,31,163,129,170,190,86,8,145,
129,27,167,171,194,129,138,243,121,121,70,107,231,8,24,245,128,12,108,197,124,172,172,8,153,175,23,134,12,87,155,203,198,140,215,202,194,6,61,96,3,44,197,124,229,96,68,205,120,188,40,85,121,188,188,163,
53,243,132,12,38,86,16,54,252,247,147,49,95,43,1,78,90,107,106,240,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,
167,21,167,107,128,156,214,213,174,17,79,84,244,249,69,61,83,211,229,20,245,79,79,153,1,235,225,224,194,112,143,17,223,158,81,79,84,244,248,24,88,157,124,60,58,225,20,245,79,79,153,33,235,249,230,83,215,
195,224,226,41,234,158,159,40,167,170,122,120,10,195,121,35,208,253,31,7,172,80,212,119,231,47,15,179,36,216,143,135,145,145,151,136,137,213,63,60,53,138,26,142,252,231,140,35,17,79,84,244,241,224,156,
35,122,248,124,2,178,160,234,159,156,119,9,15,31,25,231,4,225,98,117,240,248,107,20,53,29,249,207,28,6,103,95,15,12,96,156,44,78,190,31,13,70,40,106,59,243,141,199,18,103,95,15,12,96,156,44,78,190,31,
13,102,197,225,249,195,214,13,224,146,30,190,31,36,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,145,75,15,142,30,181,107,
150,82,213,173,62,58,88,12,95,254,225,225,148,181,107,79,129,231,13,47,117,231,150,125,186,214,122,113,227,79,219,150,82,213,173,62,1,194,98,255,0,247,31,88,43,1,132,225,214,176,226,239,25,47,127,24,158,
35,128,69,158,253,240,193,140,140,101,38,85,174,7,156,63,22,180,248,120,12,95,254,225,224,219,25,86,176,240,187,199,30,249,229,135,198,3,31,171,195,227,134,105,219,219,129,55,132,198,15,56,124,96,49,135,
199,12,211,183,183,3,206,19,31,171,193,231,14,3,23,135,199,4,148,157,189,184,74,243,201,231,223,60,184,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,224,167,21,167,
107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,172,244,196,135,91,239,44,83,90,224,39,53,181,107,10,113,90,118,184,9,205,109,90,206,238,225,218,
195,227,33,135,91,239,10,113,90,118,184,9,205,109,90,194,181,90,239,61,112,39,53,181,107,10,113,90,118,184,32,230,182,176,217,77,107,141,203,95,43,10,113,90,118,184,9,205,109,90,205,197,124,172,7,253,
196,135,91,87,142,74,114,140,24,44,55,219,211,4,74,246,239,23,249,132,85,220,171,89,19,235,14,214,90,50,28,214,251,195,101,86,189,56,9,205,109,90,200,149,236,239,128,156,214,213,172,41,197,105,218,224,
45,214,213,225,76,170,215,166,11,194,145,46,216,8,215,183,120,125,227,171,185,86,179,191,93,218,195,227,18,31,191,120,108,166,181,192,176,223,244,194,165,86,187,193,231,58,245,213,172,238,239,118,176,
248,192,161,214,251,195,101,63,233,192,176,218,222,21,42,181,222,15,57,215,174,173,103,119,225,218,195,227,18,31,191,120,108,166,181,134,179,97,191,233,137,42,181,221,231,150,123,239,86,176,217,85,230,
248,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,225,20,245,79,79,148,83,213,61,62,81,79,84,244,249,
20,245,222,25,225,20,245,79,79,148,83,213,61,62,12,224,17,94,248,111,132,83,213,61,62,6,26,254,117,202,41,234,158,159,0,226,54,161,223,40,167,170,122,124,135,122,239,79,4,225,96,118,161,222,3,130,48,63,
247,79,18,203,97,16,215,120,120,100,212,119,139,4,97,17,94,252,205,235,189,60,188,53,147,122,239,206,28,112,21,250,187,225,120,4,97,158,17,181,14,248,17,132,70,8,195,56,4,97,158,17,181,14,248,17,132,70,
8,195,56,43,12,240,65,77,67,190,6,48,37,235,155,112,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,243,36,
45,127,57,67,134,82,213,173,62,89,75,86,180,248,17,146,99,95,15,150,82,213,173,62,53,146,2,215,199,44,165,171,90,124,130,75,87,239,139,124,74,90,235,79,150,82,213,173,60,70,94,8,167,229,121,193,193,233,
199,195,201,12,49,142,66,212,250,60,93,226,202,39,29,121,197,190,36,70,190,30,27,225,148,181,107,79,132,231,15,90,181,231,45,133,172,50,33,199,195,193,57,8,201,49,175,231,132,242,137,251,121,197,190,36,
70,191,156,51,130,48,179,26,248,124,44,162,126,222,113,46,36,122,124,60,51,130,48,179,26,248,124,39,134,9,195,175,56,70,30,48,11,95,15,36,61,248,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,
86,180,249,101,45,90,211,224,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,172,7,33,205,111,181,133,56,173,59,92,4,230,182,173,97,78,
43,78,215,8,230,182,176,162,98,158,239,43,55,53,190,240,167,21,167,107,128,156,214,213,172,242,43,229,101,224,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,3,221,124,229,24,175,149,
151,137,39,91,87,133,56,173,59,92,4,230,182,173,96,15,109,119,131,188,4,124,172,244,175,156,188,129,117,226,241,77,83,135,120,96,98,4,248,241,120,72,254,177,111,1,17,250,57,70,43,229,101,226,68,58,241,
120,83,138,211,181,192,78,107,106,214,49,61,105,222,44,56,58,241,145,49,94,109,97,56,200,221,69,94,89,138,243,121,89,102,107,231,9,24,183,128,140,163,21,242,178,240,65,154,241,120,81,170,243,121,89,102,
107,231,9,24,183,128,140,163,21,243,151,129,3,53,226,240,163,85,230,242,178,204,215,206,18,48,143,239,9,30,125,178,36,170,159,92,39,24,129,58,122,188,41,197,105,218,224,39,53,181,107,10,113,90,118,184,
9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,132,83,213,61,62,81,79,84,244,249,69,61,83,211,229,111,84,252,242,138,122,167,167,202,
41,234,158,158,9,202,196,72,233,252,242,138,122,167,167,192,235,17,1,234,159,158,81,79,84,244,249,69,61,83,211,225,226,65,234,159,156,188,172,69,52,85,61,115,224,61,61,60,29,224,106,193,79,85,239,134,
112,192,192,36,61,53,239,143,137,78,85,61,62,30,34,7,79,231,9,124,34,158,169,233,243,166,143,79,79,43,13,172,18,39,84,252,222,75,4,98,33,210,189,241,172,79,61,143,94,30,45,227,120,136,15,85,239,151,149,
136,144,245,94,248,214,45,231,177,235,195,196,177,188,68,7,170,247,203,202,196,72,122,167,231,26,196,240,157,163,107,195,195,19,239,132,227,24,7,170,126,112,159,8,167,170,122,124,162,158,169,233,242,138,
122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,149,151,132,144,58,95,191,44,165,171,90,124,
14,241,146,22,173,121,229,148,181,107,79,150,82,213,173,62,89,73,199,90,202,203,198,130,149,126,248,184,103,217,181,167,141,140,17,56,216,90,191,124,172,51,132,161,101,126,248,91,14,77,107,175,60,182,
20,171,94,112,240,202,90,181,167,200,233,249,90,121,113,130,150,17,49,174,188,228,48,78,4,45,95,190,39,56,214,123,237,173,60,122,196,177,176,165,95,190,86,94,52,20,171,247,196,241,231,190,218,211,198,
241,44,108,41,87,239,149,151,140,136,213,251,226,120,74,194,210,123,107,79,52,100,49,209,42,215,158,108,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,20,226,180,
237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,76,214,213,225,64,197,105,222,
28,9,205,109,90,194,156,86,157,174,2,115,91,86,179,192,175,149,149,144,230,156,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,99,77,86,157,229,
227,70,107,229,97,1,158,1,16,233,234,214,2,234,190,86,86,2,9,154,114,175,8,56,244,59,203,195,23,95,43,0,89,253,44,56,19,154,218,181,144,226,190,86,86,110,105,202,194,156,86,157,174,2,115,91,86,176,167,
21,167,107,129,12,126,163,9,194,191,135,130,6,24,38,105,234,214,48,42,180,240,77,224,40,248,254,49,140,233,129,70,54,98,190,86,86,9,51,94,47,12,24,175,55,151,141,25,175,149,132,9,199,172,0,70,54,98,190,
86,86,4,76,215,139,195,21,79,119,151,141,25,175,227,16,159,26,194,127,172,43,219,248,195,109,87,202,200,179,141,153,167,238,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,
90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,174,17,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,3,106,59,214,24,193,56,70,
245,240,249,69,61,83,211,224,86,6,103,95,15,148,83,213,61,62,81,79,84,244,249,69,61,83,211,230,111,85,225,228,111,26,140,165,120,126,112,98,67,3,51,175,135,134,48,78,22,61,63,156,215,174,53,25,74,138,
126,115,124,74,122,239,79,148,83,213,61,62,81,79,84,244,240,165,96,199,33,168,248,120,10,194,120,215,165,123,224,35,134,171,223,206,116,207,76,4,167,95,15,33,128,131,133,137,215,195,225,168,197,13,71,
126,113,190,36,250,124,60,49,130,112,237,175,231,47,9,214,26,107,195,243,154,56,49,30,62,31,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,173,105,
242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,189,215,156,19,134,49,154,113,107,79,150,82,213,173,62,6,19,23,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,
202,90,181,167,192,120,205,56,117,172,214,3,222,24,111,211,207,2,155,192,194,253,176,166,241,227,52,202,117,145,143,25,75,86,180,249,101,45,90,211,229,148,181,107,79,6,23,120,33,126,112,158,67,4,111,35,
71,6,26,156,58,224,30,242,151,243,188,5,225,56,12,94,48,199,143,90,116,241,248,192,216,73,96,35,132,249,193,11,62,152,78,56,194,116,225,214,184,48,225,235,93,114,202,90,181,167,203,41,106,214,159,44,165,
171,90,124,178,150,173,105,242,202,90,181,167,193,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,
171,88,83,138,211,181,131,58,187,213,172,238,238,29,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,137,84,227,188,30,114,28,212,53,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,
86,176,167,21,167,107,129,115,91,86,177,73,85,167,107,22,36,63,117,120,108,167,211,211,129,97,181,191,76,54,85,174,240,31,241,231,87,114,173,102,202,126,246,177,224,61,211,149,120,108,166,181,143,2,115,
91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,135,78,114,37,86,157,225,119,237,150,30,179,178,205,238,225,218,195,128,67,173,247,132,25,77,56,197,192,
176,201,237,233,132,101,86,157,252,103,110,105,119,42,214,11,93,238,215,2,16,235,106,240,153,43,193,233,143,1,144,218,222,18,37,86,187,192,123,120,72,134,239,221,98,79,172,62,176,244,248,192,16,253,251,
194,146,154,215,166,19,244,195,32,223,244,194,18,189,187,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,
181,107,10,113,90,118,184,9,205,109,90,225,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,146,34,188,96,243,135,17,79,84,244,249,69,61,83,211,224,97,5,87,40,167,170,122,124,
162,154,42,158,158,44,93,229,43,195,193,24,124,96,17,134,107,143,58,126,220,216,107,107,223,6,25,196,109,69,63,60,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,120,50,8,225,172,
5,97,12,173,120,126,112,227,211,143,106,222,216,156,46,191,75,59,115,192,224,37,87,245,146,172,3,140,220,167,114,179,215,243,129,47,247,195,13,252,222,14,216,122,224,37,87,245,132,147,88,152,73,180,101,
237,133,133,136,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,
90,181,167,204,136,215,195,195,57,227,25,75,86,180,249,101,45,90,211,224,86,6,35,95,15,44,226,201,167,31,15,35,22,56,78,58,243,139,124,72,141,124,60,51,130,50,76,107,225,227,92,50,150,173,105,242,205,
56,181,172,188,17,146,99,95,15,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,22,241,234,241,132,107,225,225,62,25,75,86,180,249,101,45,90,211,225,225,68,56,248,201,226,113,136,90,
248,120,49,57,202,39,29,121,200,207,8,65,175,231,11,86,4,194,70,53,240,248,146,57,84,226,215,156,44,37,227,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,
171,90,124,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,158,69,124,172,188,8,25,
173,171,196,113,90,124,4,230,182,173,97,78,43,78,215,1,57,173,171,89,217,21,242,178,240,32,102,182,173,97,68,197,105,222,60,130,102,190,113,141,86,177,111,1,31,249,121,178,190,109,99,193,229,173,174,176,
167,21,167,107,1,196,204,215,202,195,101,86,159,92,4,230,182,173,97,78,43,78,215,2,195,173,174,176,205,87,155,202,203,51,95,43,10,101,124,240,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,
215,1,57,173,171,88,83,138,211,181,128,96,33,140,128,124,124,227,192,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,5,248,218,235,15,74,215,166,12,204,
205,124,172,240,246,206,248,40,253,251,197,101,87,202,246,194,245,129,12,181,226,240,153,166,180,237,96,60,153,150,190,113,52,214,187,199,188,96,223,191,166,20,226,180,237,112,19,154,218,181,133,56,173,
59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,112,138,122,167,167,202,41,234,158,159,40,167,170,
122,124,162,158,169,233,242,138,122,167,167,199,140,68,7,170,126,114,248,69,61,83,211,229,20,245,79,79,129,214,34,3,213,63,56,120,69,61,83,211,228,53,69,53,225,226,223,8,167,170,122,124,162,158,169,233,
227,194,55,136,167,170,122,124,162,158,169,233,240,10,196,197,149,99,196,243,219,107,195,197,194,41,234,158,159,40,167,170,122,124,44,246,54,158,158,87,8,167,170,122,124,178,122,167,194,196,109,69,63,
60,162,158,169,233,242,138,122,167,167,202,41,234,158,159,34,37,69,63,57,120,66,196,83,213,61,62,101,53,20,252,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,
167,202,41,234,158,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,66,213,175,57,92,50,150,173,105,242,202,90,181,167,192,239,25,33,106,215,156,33,112,
202,90,181,167,203,52,225,191,15,30,176,140,101,45,90,211,229,148,181,107,79,135,172,46,156,90,211,229,148,181,107,79,150,64,90,181,231,135,143,201,182,180,241,188,75,27,141,95,190,16,176,7,149,26,187,
222,44,107,30,153,87,239,204,214,173,107,23,190,75,40,38,85,175,57,44,107,11,167,13,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,60,5,101,225,117,171,92,178,150,173,105,242,
202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,5,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,
20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,13,167,91,87,133,56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,89,178,5,124,172,172,187,167,42,214,20,226,180,
237,112,19,154,218,181,133,56,173,59,92,0,35,218,178,234,188,223,1,57,173,171,88,83,138,211,181,192,176,235,106,241,15,235,188,122,205,205,120,235,10,113,90,118,184,9,205,109,90,194,156,86,157,172,25,
70,90,254,48,142,171,92,11,154,218,181,132,218,107,78,214,60,97,217,120,188,97,217,121,188,120,15,117,181,107,13,149,90,119,192,78,107,106,214,32,76,86,187,89,12,0,124,29,12,40,85,121,188,64,222,90,107,
231,0,51,215,241,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,56,173,59,92,4,230,182,173,97,78,43,78,215,0,119,91,200,38,43,231,8,192,156,214,213,172,99,84,247,120,123,192,156,214,213,172,
41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,
156,86,157,174,2,115,91,86,184,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,248,214,6,103,95,15,15,8,167,170,122,124,162,
158,169,233,224,235,137,181,29,233,242,138,122,167,167,196,214,85,207,175,156,156,35,17,79,84,244,248,24,136,149,31,15,0,194,50,175,84,252,226,197,136,167,170,122,124,162,158,169,233,242,215,172,3,89,
15,24,38,84,124,60,93,98,120,88,157,127,56,107,13,145,136,218,138,122,120,47,61,24,137,146,35,8,225,20,245,79,79,150,79,85,129,152,196,196,111,95,24,112,97,17,227,225,242,138,122,167,167,202,41,234,158,
159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,202,41,234,158,159,40,167,170,122,124,178,150,173,105,242,202,90,181,167,203,41,106,214,159,44,165,171,90,124,178,150,173,105,242,202,90,181,
167,203,41,106,214,159,44,165,171,90,124,12,45,124,172,30,112,227,41,106,214,159,51,90,235,79,22,39,148,94,252,178,150,173,105,240,25,52,204,171,88,112,187,194,34,226,253,240,99,195,41,238,253,240,248,
225,154,237,237,137,146,194,35,127,238,14,216,112,4,39,182,188,226,235,6,124,59,86,177,12,12,229,12,19,135,53,243,135,198,28,163,76,202,181,159,70,1,222,26,191,108,93,240,105,79,107,79,8,192,60,100,211,
50,173,112,60,225,49,243,239,155,56,113,146,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,248,41,197,105,218,224,39,53,181,107,10,
113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,21,167,107,128,156,214,213,172,41,197,105,218,224,39,53,181,107,10,113,90,118,184,9,205,109,90,194,156,86,157,174,2,115,91,86,176,167,
21,167,107,128,156,214,213,172,141,86,187,207,60,34,175,202,181,157,221,238,214,44,220,214,251,205,148,214,187,88,6,2,33,181,191,76,59,77,107,188,245,194,43,167,171,88,173,123,59,88,176,68,58,223,120,
164,167,211,211,129,98,75,120,146,171,93,224,243,145,30,178,173,103,119,123,181,135,198,36,58,223,120,108,166,181,192,176,220,190,49,37,86,187,193,231,58,125,202,181,145,62,187,181,135,198,36,58,218,188,
54,83,151,199,1,34,73,207,166,21,42,181,222,7,126,217,213,249,86,178,39,225,218,195,227,16,142,156,247,134,202,107,92,11,13,203,227,10,149,90,239,7,156,235,214,85,172,66,83,189,218,194,14,176,121,107,
106,240,217,78,95,28,11,18,91,194,165,86,187,199,145,15,189,90,195,180,215,155,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,133,
56,173,59,92,4,230,182,173,97,78,43,78,215,1,57,173,171,88,83,138,211,181,192,78,107,106,214,20,226,180,237,112,19,154,218,181,194,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,
202,41,234,158,159,40,167,170,122,124,162,158,169,233,242,138,122,167,167,192,205,120,239,79,6,3,172,2,48,206,12,5,106,29,240,35,8,98,177,44,51,128,21,94,250,197,194,54,161,223,2,48,215,243,172,17,134,
112,8,254,112,206,60,70,212,59,224,70,17,21,239,130,48,206,1,21,239,134,120,2,26,135,124,8,205,84,119,128,172,39,88,4,127,56,103,132,109,67,190,4,97,17,94,248,35,14,1,31,206,28,120,141,168,119,132,142,
13,120,239,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,148,83,213,61,62,81,79,84,244,249,69,61,83,211,229,20,245,79,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,
107,79,150,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,135,24,34,28,124,60,244,192,72,194,204,56,254,112,16,46,50,231,40,156,117,231,4,78,38,53,184,254,112,144,112,16,49,184,113,241,
194,202,39,29,121,196,184,12,70,190,30,25,193,25,38,53,240,248,79,40,156,117,231,60,241,34,53,252,225,156,17,133,152,215,195,225,111,40,153,244,243,146,39,128,72,149,240,240,144,114,24,72,192,175,135,
143,19,202,39,29,121,197,190,36,70,190,30,25,202,188,45,2,190,49,247,135,29,39,22,188,229,99,198,82,213,173,62,89,75,86,180,249,101,45,90,211,229,148,181,107,79,150,82,213,173,62,89,75,86,180,249,101,
45,90,211,229,148,181,107,79,150,82,213,173,63,198,14,2,176,224,253,44,223,3,13,96,195,130,176,222,125,115,126,252,15,127,108,53,129,239,192,43,7,131,123,207,174,11,222,26,192,247,195,239,148,195,198,
253,248,24,107,144,87,45,251,240,48,214,13,222,28,21,150,252,127,255,218,0,8,1,2,3,1,63,33,255,0,253,45,223,255,218,0,8,1,3,3,1,63,33,255,0,140,255,0,249,36,127,201,63,144,7,11,23,230,167,248,229,246,
198,31,204,79,255,0,181,3,15,35,255,0,148,198,31,204,131,255,0,164,171,149,249,153,253,135,202,197,249,169,254,108,124,47,190,31,146,199,224,95,222,143,201,135,255,0,148,207,255,0,173,199,255,0,192,243,
255,0,209,241,248,193,249,164,126,106,63,147,71,227,15,228,227,249,167,95,138,31,252,112,63,52,140,63,252,168,177,98,252,214,249,95,154,159,43,22,44,88,184,143,255,0,137,191,255,218,0,12,3,1,0,2,17,3,
17,0,0,16,203,101,178,217,108,182,91,45,150,203,97,16,180,56,37,139,44,150,217,100,132,117,41,0,146,123,6,203,101,178,217,108,182,91,45,150,203,101,178,203,37,146,201,100,178,89,44,150,75,36,9,150,233,
82,192,4,150,75,109,146,144,148,164,146,5,192,27,37,146,201,100,178,89,44,150,75,37,146,203,45,150,203,101,178,217,108,182,91,37,18,168,74,230,217,100,146,219,101,146,218,66,31,66,65,5,193,45,150,203,
101,178,217,108,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,162,0,3,122,25,45,150,219,44,178,217,104,37,190,52,36,148,5,178,217,108,182,91,45,150,203,101,178,217,101,146,201,100,178,89,44,
150,75,37,128,92,11,138,75,36,150,75,37,182,203,100,130,172,138,229,26,17,146,201,100,178,89,44,150,75,37,146,201,101,150,203,101,178,217,108,182,91,45,182,24,49,20,3,37,150,73,45,150,203,37,182,16,2,
13,213,54,34,203,101,178,217,108,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,211,108,164,217,108,182,75,101,178,217,36,182,89,40,4,162,101,108,89,108,182,91,45,150,203,101,178,217,108,
178,201,100,178,89,44,150,75,37,146,219,13,162,89,45,150,203,37,146,201,109,146,89,44,150,2,205,163,147,100,178,89,44,150,75,37,146,201,100,178,203,101,178,217,108,182,91,45,146,75,96,38,75,108,178,91,
45,150,203,101,182,217,108,182,74,13,242,20,37,178,217,108,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,73,109,150,209,101,178,203,101,178,217,108,178,219,45,150,75,32,134,81,225,182,91,
45,150,203,101,178,217,108,182,89,100,178,89,44,150,75,37,146,201,108,176,203,45,182,219,37,146,201,100,178,89,44,150,89,44,8,91,3,18,89,44,150,75,37,146,201,100,178,89,101,178,217,108,182,91,45,150,203,
45,182,217,100,150,219,45,150,203,101,178,219,108,182,73,109,128,125,42,148,217,108,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,217,109,150,73,101,150,73,101,178,217,108,182,91,45,150,
203,36,178,72,164,64,27,45,150,203,101,178,217,108,182,91,44,178,89,44,150,75,37,146,203,36,178,219,101,182,91,37,146,219,104,166,217,108,150,75,36,146,88,136,156,170,108,150,75,37,146,201,100,178,89,
44,178,217,108,182,91,45,150,201,37,178,219,37,150,73,109,150,217,68,178,144,100,150,91,45,150,218,109,45,30,12,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,217,109,182,73,37,178,217,45,
178,203,5,119,250,136,36,27,101,178,217,4,187,18,37,54,203,101,178,217,108,182,91,45,150,89,44,150,75,37,146,201,109,182,219,108,182,73,37,146,201,77,80,48,202,37,178,100,146,201,100,38,85,196,6,75,37,
146,201,100,178,89,44,150,89,108,182,91,45,150,203,100,178,73,36,178,75,45,182,203,105,44,194,208,249,48,136,36,11,101,178,128,14,26,155,45,150,203,101,178,217,108,182,91,45,150,203,101,178,217,100,166,
211,36,182,217,108,182,217,37,6,167,73,6,76,51,8,170,68,182,91,69,2,170,101,178,217,108,182,91,45,150,203,44,150,75,37,146,201,101,144,217,108,178,203,44,182,201,108,162,228,1,36,144,12,195,160,152,50,
89,33,144,14,77,146,201,100,178,89,44,150,75,44,182,91,45,150,203,101,178,216,13,178,219,101,146,219,101,178,16,5,32,146,73,48,206,219,6,217,109,35,186,81,54,203,101,178,217,108,182,91,45,150,203,101,
178,217,109,146,73,109,146,73,100,178,201,108,182,208,90,192,144,9,4,16,32,112,75,45,161,163,129,134,217,108,182,91,45,150,203,101,150,75,37,146,201,100,182,219,45,150,91,37,182,219,100,178,203,65,42,
16,0,32,146,0,152,186,44,180,146,52,237,25,100,178,89,44,150,75,37,150,91,45,150,203,101,178,201,45,146,91,45,146,217,37,146,217,41,45,98,0,4,0,64,3,114,137,180,176,225,133,56,101,178,217,108,182,91,45,
150,203,101,178,217,108,178,91,101,178,217,37,182,203,36,182,75,108,133,183,201,36,18,73,36,29,209,20,51,233,34,80,196,182,91,45,150,203,101,178,203,37,146,201,100,182,89,100,146,203,109,146,73,109,146,
89,101,150,6,124,32,146,9,32,146,115,9,7,168,36,141,153,50,89,44,150,75,37,146,203,45,150,203,101,182,201,101,150,91,45,150,217,37,178,203,37,182,91,88,212,18,0,36,2,65,223,45,40,0,144,2,2,217,108,182,
91,45,150,203,101,178,217,108,182,201,44,178,201,101,178,217,36,182,73,37,146,75,4,7,208,64,4,128,8,34,237,65,0,16,5,197,27,45,150,203,101,178,217,101,146,201,100,178,217,100,182,73,45,146,201,108,150,
219,108,178,203,37,38,143,73,0,146,73,0,146,73,36,2,77,25,19,44,150,75,37,146,201,101,150,203,101,178,203,108,178,203,45,150,203,100,182,91,101,182,217,109,148,18,124,36,146,73,4,146,73,36,146,73,34,96,
12,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,217,108,178,146,5,178,203,37,178,210,43,244,130,0,36,16,72,4,130,9,0,14,129,150,203,101,178,217,108,178,201,100,178,89,109,150,75,37,182,
217,100,182,219,5,150,217,37,178,201,109,46,210,64,0,130,72,0,18,73,0,2,122,38,75,37,146,201,100,178,203,101,178,217,109,150,89,45,150,201,101,178,217,36,34,201,36,146,75,100,0,56,9,0,144,1,32,18,0,36,
0,7,64,219,45,150,203,101,178,217,108,182,91,44,182,203,108,178,219,36,182,91,0,180,217,100,146,203,44,180,135,177,36,144,73,36,146,73,36,146,72,251,139,101,178,217,108,182,89,100,178,89,37,150,203,36,
146,219,108,178,89,33,50,193,37,182,89,101,178,80,94,196,18,64,36,146,73,4,146,9,38,2,37,146,201,100,178,89,101,178,217,108,146,219,45,182,203,44,150,217,109,166,203,105,178,75,36,150,219,75,22,128,8,
0,144,9,0,16,0,32,246,101,150,203,101,178,217,108,182,91,45,182,201,101,150,89,100,178,91,45,180,73,44,22,75,101,146,203,45,133,112,9,0,18,1,32,2,0,4,29,144,178,217,108,182,91,44,178,89,44,150,89,37,150,
89,109,178,75,44,150,195,37,144,137,109,178,75,108,160,31,9,32,18,73,36,130,73,4,131,25,162,201,100,178,89,44,178,217,108,182,75,109,150,217,100,182,219,108,182,90,37,178,80,101,182,217,37,182,16,185,
36,146,9,36,146,73,36,146,77,32,203,101,178,217,108,182,91,45,150,203,45,178,217,44,182,91,108,182,203,104,178,139,69,150,75,109,150,194,132,0,130,9,0,144,65,0,146,0,65,89,108,182,91,45,150,89,44,150,
73,109,146,203,100,178,201,45,178,203,36,2,19,37,34,217,44,150,89,8,216,16,65,0,2,9,32,0,65,25,3,100,178,89,44,150,89,108,182,91,44,150,201,37,178,201,108,178,201,45,148,200,32,144,217,44,182,203,41,111,
18,0,32,0,64,4,128,8,7,39,37,178,217,108,182,91,45,150,203,108,178,217,37,182,89,45,150,203,101,178,65,96,54,9,109,182,201,101,4,194,73,36,146,65,36,146,73,32,226,140,182,91,45,150,203,44,150,75,36,146,
201,109,146,89,36,150,75,100,146,203,13,146,65,44,146,75,45,144,47,73,4,146,9,32,146,65,36,144,24,178,89,44,150,75,44,182,91,45,150,203,100,146,217,109,182,91,45,178,91,109,22,218,101,150,75,45,182,1,
241,0,18,1,32,2,64,36,0,144,50,217,108,182,91,45,150,203,101,178,217,108,178,91,45,178,203,101,182,75,101,128,203,5,150,219,101,178,81,16,0,2,0,4,0,64,4,145,191,22,91,45,150,203,101,150,75,37,146,201,
100,182,201,44,150,203,37,146,201,108,178,155,96,150,73,101,146,218,8,218,0,73,36,144,9,32,144,66,6,89,44,150,75,37,150,91,45,150,203,101,178,75,108,178,203,45,150,203,101,182,218,0,182,219,45,150,201,
74,43,1,236,36,146,73,36,128,55,68,89,108,182,91,45,150,203,101,178,217,108,182,201,109,150,73,101,178,217,108,178,216,105,6,91,101,178,217,41,134,48,30,208,111,72,32,139,247,16,219,45,150,203,101,178,
203,37,146,201,100,178,89,44,150,75,37,146,201,108,178,219,100,150,219,37,146,201,101,54,145,26,1,23,220,32,95,178,12,137,44,150,75,37,146,203,45,150,203,101,178,217,44,182,89,37,150,219,44,146,203,37,
150,219,45,150,203,101,144,16,9,130,6,51,36,130,151,228,9,108,182,91,45,150,203,101,178,217,108,182,89,101,150,203,44,150,203,109,146,89,45,182,89,101,178,217,108,150,89,45,150,211,72,161,108,9,34,19,
45,150,203,101,178,217,101,146,201,100,178,89,37,182,75,45,178,73,101,182,75,108,150,217,108,146,201,100,178,89,44,150,75,109,34,194,0,166,139,44,150,75,37,146,201,101,150,203,101,178,217,109,150,91,44,
182,203,108,146,217,108,182,91,100,182,203,101,146,73,109,178,91,45,150,203,100,178,219,108,182,91,45,150,203,101,178,217,108,182,91,44,178,203,101,150,89,109,146,91,36,182,203,101,150,203,100,146,219,
108,146,75,101,178,217,108,178,91,45,150,203,101,178,217,108,178,201,100,178,89,44,146,75,37,150,89,100,178,89,44,150,75,36,178,217,109,178,89,101,54,27,37,146,201,101,178,201,44,150,75,37,146,201,100,
178,203,101,178,217,108,182,91,45,150,217,101,178,91,108,182,203,45,180,139,101,178,217,96,22,131,108,146,203,100,150,73,44,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,178,203,44,182,75,45,
150,208,37,146,128,32,178,218,73,146,88,108,32,9,108,150,73,45,150,203,101,178,217,108,182,89,100,178,89,44,150,75,37,146,203,45,178,203,44,182,65,68,148,219,109,54,74,76,182,203,104,36,155,5,182,219,
108,150,75,37,146,201,100,178,89,101,178,217,108,182,91,45,150,203,44,178,201,5,134,75,101,146,75,44,178,73,101,150,217,36,178,201,100,182,91,108,182,91,45,150,203,101,178,217,108,182,91,45,150,203,101,
178,217,100,178,201,97,178,91,36,36,0,64,36,9,73,182,203,100,180,208,45,18,219,45,150,203,101,178,217,108,182,91,45,182,219,109,182,219,109,182,219,109,178,217,45,150,75,73,2,219,69,148,219,68,172,203,
45,130,216,224,182,203,109,182,219,109,182,219,109,182,219,109,191,255,218,0,8,1,1,3,1,63,16,205,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,
77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,48,177,128,228,153,96,56,209,172,98,39,81,233,172,34,193,53,13,222,240,213,0,48,126,22,176,132,
65,22,71,243,252,102,194,174,200,5,94,56,185,7,96,203,216,119,131,8,163,170,63,24,57,24,3,67,6,185,77,3,40,20,189,48,138,18,73,232,58,31,57,74,205,90,127,85,134,40,26,108,30,132,214,19,128,179,177,63,
190,18,100,63,44,216,199,35,16,37,154,32,170,158,12,194,67,16,123,195,13,37,102,192,202,195,66,107,190,65,38,145,7,1,19,88,198,18,39,111,18,24,121,176,50,176,208,154,239,1,32,177,149,224,170,112,3,18,
93,26,32,154,175,124,128,68,207,90,194,3,178,72,190,240,136,15,80,22,236,176,132,232,106,241,44,54,4,131,214,35,50,29,131,136,42,207,25,7,71,188,238,97,98,51,37,208,56,130,172,216,95,128,58,196,9,147,
179,183,132,74,2,88,61,9,172,99,9,25,4,186,35,0,196,116,209,235,38,76,59,32,97,213,127,56,204,108,241,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,
3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,226,68,164,104,178,26,223,16,37,33,69,146,
158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,
178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,240,64,128,146,38,132,14,26,218,
192,169,62,130,227,88,134,13,48,74,163,40,127,24,89,97,162,73,4,144,214,170,43,14,204,27,77,123,96,128,220,132,44,143,124,32,65,112,153,76,162,176,213,139,235,69,198,17,43,161,29,128,125,112,6,210,196,
200,33,170,241,146,132,230,129,75,0,1,130,92,53,70,155,198,228,32,146,139,4,213,70,61,33,211,95,238,54,9,96,3,36,90,218,112,241,76,9,73,61,30,245,128,1,128,141,56,57,12,53,1,15,37,239,172,112,29,202,17,
6,171,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,146,96,146,82,156,167,132,8,24,57,78,205,13,98,15,140,129,41,10,44,148,247,128,8,94,70,136,56,107,120,17,4,221,9,172,11,1,96,209,217,41,239,
172,38,36,54,37,137,128,246,140,39,212,159,94,114,80,73,33,16,201,73,27,184,120,13,6,12,72,118,14,43,32,117,245,32,225,148,73,65,130,16,221,225,3,77,201,67,71,182,0,1,159,233,44,4,0,49,139,84,15,79,10,
35,69,162,109,106,163,9,48,180,254,48,130,69,166,27,160,205,197,98,24,1,12,72,118,246,67,239,0,1,1,235,130,49,54,4,208,244,240,64,3,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,
66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,
72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,
74,66,139,37,61,241,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,
243,160,50,160,208,211,239,6,48,18,71,143,29,224,64,0,201,52,83,202,250,96,132,224,148,48,136,5,32,187,12,96,32,36,149,5,109,125,224,2,99,178,252,253,48,0,48,68,3,53,251,97,32,36,12,147,71,178,255,0,140,
84,195,94,14,90,83,224,208,24,64,97,138,106,29,223,107,88,72,0,108,126,220,104,12,168,52,52,251,224,21,35,3,33,6,104,20,123,47,181,148,17,233,224,230,195,58,240,48,226,4,197,53,228,92,235,45,65,161,167,
222,34,74,222,17,12,4,64,120,0,73,2,133,52,104,119,222,16,138,224,132,128,202,72,208,211,239,2,0,153,131,39,246,194,131,40,96,118,67,24,69,0,26,32,98,215,222,17,1,72,245,188,0,152,177,189,140,48,48,36,
74,65,14,254,171,88,96,36,139,68,119,151,128,29,122,97,32,64,65,148,200,242,39,128,8,112,73,179,147,192,94,28,153,25,216,74,152,131,190,240,146,89,24,126,229,96,67,32,0,67,34,59,192,132,144,80,160,84,
172,39,181,151,198,224,249,140,35,37,223,182,104,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,
239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,
134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,128,44,108,78,36,66,198,10,220,225,146,33,146,11,131,41,213,122,99,32,145,234,34,35,20,134,224,63,
63,92,10,123,4,237,95,85,133,21,83,210,198,48,72,88,243,133,112,32,192,166,81,53,88,89,236,160,29,12,59,54,168,22,142,50,150,72,101,25,90,87,166,1,39,234,34,10,200,24,172,216,25,88,104,77,119,206,192,
202,195,66,107,188,103,1,225,16,144,68,182,47,3,104,149,32,113,167,237,133,146,165,157,172,0,46,223,206,69,53,146,50,175,219,8,11,160,38,53,132,73,84,177,231,8,21,147,4,6,86,149,233,146,91,176,162,163,
141,129,149,134,132,215,121,72,112,100,14,251,59,62,248,171,149,146,50,167,244,192,173,87,211,233,132,36,2,242,7,120,193,24,0,90,5,74,85,158,96,136,232,141,225,82,26,77,131,188,49,66,74,145,12,173,26,
244,194,133,20,117,17,128,5,219,249,197,9,172,76,202,191,108,32,16,117,252,60,100,127,181,227,130,0,148,25,50,157,53,233,142,19,104,79,79,253,200,88,8,203,139,205,129,149,134,132,215,124,236,12,172,52,
38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,
101,97,161,53,223,18,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,
146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,
214,240,25,3,0,55,129,3,210,221,226,58,105,151,129,13,97,104,216,52,245,120,77,36,132,86,211,123,194,184,210,101,177,229,67,199,90,75,217,101,166,3,73,203,79,120,226,18,153,152,69,197,111,32,101,212,31,
225,128,108,64,35,123,165,132,9,68,103,194,53,188,52,88,117,43,59,137,8,168,110,247,139,223,137,220,182,161,226,36,81,200,18,144,162,201,79,120,64,100,211,61,128,226,183,131,50,39,79,198,20,218,12,122,
132,172,9,164,25,125,3,88,104,193,32,237,96,69,8,196,83,91,79,120,35,4,100,161,51,234,80,241,252,1,210,254,240,132,132,16,130,211,211,222,4,148,6,69,141,3,134,183,134,204,146,78,158,20,218,8,254,161,60,
0,11,96,250,132,53,190,32,74,66,139,37,61,228,9,165,40,27,150,212,60,9,18,71,254,98,218,0,33,168,246,56,120,78,209,41,154,160,226,183,233,133,114,73,58,108,172,86,16,38,206,197,131,104,74,113,3,208,240,
155,183,153,97,150,16,250,149,205,239,0,88,3,37,59,94,219,194,99,73,109,165,94,153,233,32,158,211,185,140,138,105,25,170,24,173,225,4,153,108,130,159,120,34,145,1,248,2,159,140,8,8,129,37,67,192,214,32,
163,215,175,140,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,
129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,
247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,198,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,
52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,200,12,44,196,65,2,201,211,88,116,48,88,247,7,12,145,101,37,28,113,32,67,40,121,46,171,27,244,16,251,88,21,64,172,58,214,
22,166,68,192,142,223,85,131,86,193,26,135,142,11,81,226,22,20,71,68,166,41,221,247,128,8,131,101,38,64,121,90,68,117,175,174,2,145,0,144,194,215,120,98,97,225,196,224,33,126,239,95,92,138,106,32,87,107,
213,98,6,73,99,67,191,166,1,38,68,83,136,192,37,128,36,53,11,39,117,89,34,39,215,9,38,243,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,134,39,202,202,0,146,47,198,104,12,168,52,52,
251,228,0,1,200,144,61,137,247,137,19,244,217,250,98,72,36,161,228,198,92,68,134,128,76,14,245,148,32,77,61,253,112,130,1,229,254,142,16,60,166,137,34,9,33,223,166,72,192,138,110,206,13,122,88,38,71,215,
0,130,131,83,34,214,167,26,85,61,111,0,147,34,41,249,194,147,64,145,0,144,196,223,166,22,23,22,25,82,68,125,6,18,98,76,130,84,52,239,211,15,26,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,
79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,192,202,195,66,107,190,118,6,
86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,188,33,67,172,26,8,159,
67,162,22,0,82,66,192,101,26,124,96,0,80,35,173,225,24,133,211,140,33,65,29,137,74,87,120,211,26,208,53,142,5,108,70,1,130,198,46,70,73,86,18,55,140,138,39,24,26,67,145,77,38,187,192,67,120,75,44,231,
97,39,51,162,174,240,17,2,107,107,81,128,93,188,216,36,228,101,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,4,199,121,160,246,193,214,17,144,37,224,102,132,253,121,216,
25,88,104,77,119,192,81,29,224,233,24,193,149,163,67,9,16,4,31,129,128,16,96,219,16,43,0,8,50,216,148,81,62,154,193,36,72,140,36,21,160,96,214,54,74,110,68,81,87,120,68,22,131,211,211,9,4,33,36,136,24,
90,72,151,45,50,130,94,32,132,162,222,128,193,0,65,245,240,191,204,96,36,204,148,203,81,227,11,98,23,142,54,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,
96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,137,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,
107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,
64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,203,11,72,201,89,13,69,112,96,17,164,40,178,83,218,192,17,203,15,97,47,77,224,0,2,86,
193,153,120,0,23,144,4,163,52,167,143,3,6,40,27,52,53,21,136,37,178,86,64,148,132,21,146,156,53,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,66,6,144,162,14,83,222,84,65,152,
40,226,161,172,103,217,181,243,147,6,211,16,76,52,167,15,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,
240,128,141,4,19,78,83,222,58,154,146,41,13,86,240,192,0,216,175,32,228,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,
148,135,219,39,210,24,2,70,142,112,161,0,148,161,190,149,227,12,180,237,159,151,215,9,32,73,32,144,213,173,222,240,23,16,203,148,232,209,88,3,35,111,128,49,2,5,230,27,67,243,132,1,212,158,198,166,177,
68,99,173,191,166,8,4,195,134,148,22,159,120,0,1,164,104,114,134,184,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,
248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,
148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,198,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,
12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,128,51,79,127,76,208,55,222,134,4,129,146,129,161,167,223,31,57,224,132,132,58,161,6,159,121,160,184,216,235,11,73,
41,233,86,57,104,1,44,164,148,240,152,40,102,200,214,25,133,61,157,15,108,2,18,90,130,154,105,247,204,18,74,130,160,211,239,1,23,5,251,24,198,54,70,210,172,41,0,3,100,128,141,62,249,208,25,80,104,105,
247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,132,39,103,88,96,164,58,21,5,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,192,72,44,97,25,
146,142,144,194,144,48,48,235,216,120,192,182,205,175,56,22,135,187,214,8,169,46,201,27,95,120,80,170,193,89,159,65,145,137,2,100,138,38,239,188,27,61,140,97,1,125,235,161,154,3,42,13,13,62,249,208,25,
80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,
206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,128,175,120,
125,102,193,63,73,25,5,36,1,178,32,171,147,9,137,212,227,217,222,66,208,122,26,25,160,201,31,56,138,76,182,189,197,135,40,4,75,7,193,30,152,64,77,248,61,97,36,11,3,193,195,170,239,206,119,176,96,247,136,
78,135,139,56,202,145,37,145,180,38,187,205,135,125,104,97,33,27,27,200,36,149,133,65,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,240,18,4,148,63,115,
143,52,157,3,136,42,254,121,216,25,88,104,77,119,206,192,202,195,66,107,190,17,50,6,108,12,172,52,38,187,225,191,213,225,2,12,137,187,197,89,16,8,61,244,71,166,8,18,14,154,63,230,60,208,118,14,32,171,
249,206,246,12,30,240,47,170,93,225,145,145,57,0,225,165,93,249,203,70,252,126,186,193,132,153,255,0,48,144,19,50,114,52,38,185,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,
50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,196,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,
190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,
61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,227,4,150,41,41,217,161,172,32,3,30,227,188,130,4,8,69,13,109,61,228,137,72,209,100,53,188,83,118,43,211,219,
6,227,38,65,41,35,74,123,196,98,88,130,74,38,192,213,69,97,66,201,180,255,0,204,1,4,180,8,105,57,121,140,33,133,147,34,14,26,222,24,133,239,206,42,154,144,137,13,222,58,155,146,137,13,86,0,1,159,97,214,
0,0,2,88,53,217,55,132,9,26,70,73,202,26,218,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,
72,148,141,22,67,91,226,4,164,40,178,83,222,48,8,180,141,22,67,91,192,0,51,236,58,200,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,128,32,14,164,34,48,221,239,
12,169,185,41,163,85,188,33,143,217,241,144,37,33,69,146,158,240,201,41,147,86,109,109,97,16,14,65,3,2,205,0,65,66,32,209,189,172,17,16,192,9,33,246,69,70,16,32,255,0,208,113,84,212,132,72,110,241,195,
55,37,17,6,171,120,32,97,180,186,21,128,4,0,37,131,84,111,59,194,16,209,36,145,176,53,81,144,32,68,134,61,114,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,
164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,
141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,223,26,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,
84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,0,169,24,0,96,80,166,139,89,60,16,3,16,207,1,2,131,42,12,147,79,188,32,68,162,247,252,97,
34,32,86,158,163,8,6,2,154,129,209,223,120,72,145,42,77,108,47,231,8,105,84,112,188,6,105,163,67,79,188,100,81,35,3,33,36,250,206,16,4,5,138,104,162,52,243,77,146,137,60,104,12,168,52,52,251,231,64,101,
65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,40,247,253,176,0,128,177,77,20,70,159,58,3,42,13,13,62,249,208,25,80,104,105,247,128,145,89,176,206,188,12,0,36,165,
50,10,35,92,156,204,146,137,80,219,188,41,68,145,130,123,133,252,98,138,130,163,212,100,208,20,50,69,172,190,153,176,70,188,28,216,123,64,107,0,131,0,204,26,41,100,240,137,27,19,103,4,130,64,81,71,163,
155,20,148,34,14,251,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,
167,223,58,3,42,13,13,62,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,
43,13,9,174,249,7,112,0,88,104,102,43,54,25,34,188,96,35,243,155,3,43,13,9,174,240,144,72,216,107,163,128,152,91,218,147,133,38,37,164,83,17,245,88,75,227,96,101,97,161,53,223,0,145,35,211,9,18,73,146,
14,1,74,189,48,241,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,33,82,68,18,203,67,170,244,231,96,101,97,161,53,223,59,3,43,13,
9,174,248,4,138,56,66,172,153,36,50,180,175,76,54,85,62,34,25,68,100,83,73,226,46,147,75,75,4,32,234,131,188,112,128,144,68,16,208,209,84,214,88,76,164,188,101,4,65,55,231,24,140,168,112,234,189,49,203,
161,19,180,112,36,52,216,190,207,190,20,152,238,26,29,127,152,244,5,227,199,27,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,
134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,248,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,
72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,32,
51,178,83,185,109,67,194,17,254,123,200,18,144,162,201,79,121,34,82,52,89,13,111,9,17,133,54,131,30,161,43,0,22,13,2,93,138,107,137,128,104,40,125,147,222,71,101,50,181,229,67,194,12,146,26,112,134,0,
176,28,48,185,105,224,193,44,100,96,163,138,222,2,49,94,176,240,34,37,136,112,50,74,243,146,72,153,67,192,214,242,240,252,245,144,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,
164,104,178,26,223,0,8,108,15,80,148,247,128,9,18,17,1,148,63,56,204,33,129,251,179,96,144,137,163,155,222,8,108,38,68,181,229,70,17,78,226,224,133,128,194,32,100,50,35,208,166,60,148,142,132,112,214,
248,129,41,10,44,148,247,158,87,128,178,26,222,51,179,218,255,0,49,48,204,68,22,211,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,
107,120,207,103,32,74,66,139,37,61,228,137,72,209,100,53,188,62,232,126,208,112,192,217,3,86,135,78,30,61,132,38,122,106,183,147,38,125,177,24,50,71,245,9,239,2,105,6,248,7,141,41,184,107,4,36,64,143,
146,55,188,16,118,67,43,79,196,96,147,213,248,91,193,146,92,16,190,201,198,8,0,105,26,44,134,182,184,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,
10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,
37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,198,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,
251,231,64,101,65,161,167,223,58,3,42,13,13,62,240,2,107,1,11,165,241,133,101,211,8,67,181,244,231,64,101,65,161,167,222,121,238,143,120,12,20,145,121,4,12,168,52,52,251,192,204,13,224,33,116,190,50,46,
162,209,149,175,85,132,133,216,49,27,192,32,186,80,241,132,46,201,128,10,43,107,244,198,4,236,82,123,201,17,176,116,107,8,4,178,96,80,168,52,234,185,208,25,80,104,105,247,200,32,66,146,129,146,105,211,
195,80,34,114,224,3,33,214,178,72,144,22,40,217,58,172,38,80,31,189,253,48,2,165,221,22,20,245,16,133,19,106,118,178,30,193,142,223,211,10,24,161,64,216,4,228,128,77,64,167,105,250,97,40,16,176,50,98,
240,136,136,101,2,182,199,152,12,83,29,241,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,228,97,18,4,81,145,254,86,1,3,122,141,235,88,192,52,2,61,14,22,92,2,67,0,33,91,94,36,168,
146,145,239,9,37,53,116,107,2,66,10,105,168,119,233,88,36,130,69,36,224,60,97,116,175,198,177,98,237,5,25,90,245,88,1,16,100,26,243,135,41,8,102,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,
208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,
129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,105,35,39,34,160,154,239,16,4,96,236,122,227,250,154,172,34,17,165,97,240,174,240,144,147,191,142,54,6,86,26,
19,93,224,96,157,191,0,44,208,99,126,14,18,64,153,216,104,77,119,130,8,61,28,36,68,138,211,220,96,136,34,176,185,240,174,240,161,32,5,180,40,97,32,132,36,145,3,1,3,18,197,166,81,19,89,160,78,252,12,208,
99,126,14,24,128,198,77,50,212,124,236,12,172,52,38,187,226,224,96,144,73,155,1,158,135,148,73,178,116,61,113,68,124,207,120,12,0,74,23,34,9,19,245,192,0,42,32,6,6,22,8,64,105,153,56,143,144,115,62,21,
222,18,5,189,74,72,250,96,130,164,154,250,97,21,51,54,129,129,73,229,100,229,177,128,128,200,23,125,44,2,28,68,185,52,5,132,0,64,194,14,48,104,208,194,64,76,202,194,160,171,190,118,6,86,26,19,93,243,176,
50,176,208,154,239,144,132,140,217,98,160,154,167,132,65,4,251,129,162,176,9,2,201,175,24,21,137,98,228,122,26,239,21,0,62,103,89,84,149,47,193,194,18,24,23,36,181,40,102,194,10,198,18,34,69,121,222,58,
98,6,211,225,93,225,9,168,51,29,17,252,96,2,17,39,247,194,129,201,149,134,73,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,
129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,18,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,
247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,241,1,103,88,16,48,48,16,54,77,239,172,
38,160,202,98,86,170,30,19,108,219,127,187,12,0,177,16,210,125,174,24,192,0,13,35,67,148,53,193,0,77,200,240,30,158,9,83,82,91,70,171,121,4,13,135,61,131,144,37,33,69,146,158,242,249,33,63,0,212,60,103,
217,181,243,132,150,105,134,0,163,155,140,36,135,37,138,217,61,173,225,35,103,219,89,2,82,20,89,41,239,8,16,117,37,20,131,138,198,8,29,63,119,144,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,
146,158,240,3,22,114,64,105,26,202,193,4,33,181,61,1,235,131,82,114,9,232,247,222,56,102,4,148,125,133,111,4,2,135,87,47,0,67,6,12,4,150,101,97,1,32,64,4,161,0,166,170,49,173,139,105,123,224,41,0,200,
97,128,18,57,241,128,33,0,151,32,48,8,55,140,27,15,252,1,235,56,4,72,92,134,72,110,247,134,74,146,88,4,53,67,42,130,94,47,227,8,34,88,112,208,0,154,124,96,197,5,50,129,18,180,212,86,28,146,72,69,181,144,
52,38,66,67,105,198,24,136,10,146,157,244,106,49,19,64,156,9,37,33,5,7,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,240,32,100,76,4,178,222,119,128,18,65,37,200,12,65,161,173,224,
112,137,254,195,2,41,185,98,18,183,120,201,202,146,217,56,143,223,4,0,4,163,162,36,23,128,1,22,12,26,179,74,120,1,41,166,80,54,181,81,132,223,169,175,156,2,32,22,65,34,5,246,184,172,149,4,218,116,109,
173,224,130,98,76,159,215,174,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,
145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,
200,107,124,64,148,133,22,74,123,227,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,146,8,66,0,209,5,29,225,34,
218,22,54,51,189,24,65,86,25,13,147,68,242,39,132,3,178,28,97,3,64,177,121,160,50,160,208,211,239,0,100,12,234,101,206,64,73,40,84,59,190,248,145,51,140,167,5,139,216,120,96,153,125,154,227,64,101,65,
161,167,223,0,160,216,61,104,224,16,58,100,18,54,190,249,208,25,80,104,105,247,193,54,7,72,190,142,20,66,18,192,202,135,211,193,142,131,111,101,96,192,25,4,184,241,128,74,67,177,68,59,172,11,44,11,241,
129,167,103,223,4,91,39,41,236,79,24,72,32,153,98,103,52,1,234,104,1,132,166,143,35,13,175,8,196,64,19,127,222,26,236,25,129,253,97,138,144,232,67,69,29,152,192,192,143,117,120,82,91,78,106,178,54,68,
52,60,201,226,97,115,24,67,0,107,98,134,17,88,203,178,64,182,14,137,0,155,31,214,16,129,144,103,244,240,145,32,181,13,33,216,135,227,24,70,254,8,227,64,101,65,161,167,223,0,210,163,79,198,1,32,74,89,128,
65,167,88,76,197,14,242,32,211,130,44,96,0,166,72,133,27,39,222,0,0,78,160,248,17,128,172,70,61,177,148,224,208,246,30,20,242,68,143,56,50,0,39,111,71,219,10,84,153,202,141,174,158,88,161,198,128,202,
131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,192,202,195,66,107,190,
118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,12,147,147,49,38,80,56,96,42,167,138,53,158,186,198,6,12,192,187,196,82,131,99,220,
88,109,32,137,134,240,100,72,216,144,119,221,102,192,202,195,66,107,188,5,23,157,204,44,50,2,77,144,28,4,85,196,136,111,8,48,8,216,61,13,119,128,50,176,168,110,176,48,146,75,52,65,53,222,34,94,240,18,
104,52,174,103,8,1,204,208,56,130,174,118,6,86,26,19,93,224,12,129,130,25,124,169,24,81,12,67,3,14,52,174,240,245,144,73,19,245,196,153,132,20,123,96,128,228,212,209,5,88,128,37,179,73,66,192,106,153,
27,119,128,129,16,108,35,201,98,123,3,77,214,44,136,192,144,81,99,219,18,146,102,205,16,77,24,194,187,30,255,0,67,22,114,0,160,14,240,216,154,133,66,141,119,133,195,32,143,67,67,223,17,0,50,33,209,249,
194,36,209,216,135,146,172,47,9,19,191,76,148,71,184,52,189,176,153,166,46,0,196,19,66,48,12,87,243,237,129,153,9,19,250,99,0,83,39,32,200,2,147,84,112,98,207,208,104,96,178,54,55,222,108,12,172,52,38,
187,231,96,101,97,161,53,223,35,9,146,93,24,164,10,171,40,36,157,24,85,128,129,131,48,27,188,4,147,3,179,192,214,116,17,239,172,80,33,161,32,236,98,5,204,193,7,34,147,88,41,138,63,28,108,12,172,52,38,
187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,72,148,141,22,67,91,226,4,164,
40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,
22,67,91,226,4,164,40,178,83,222,33,25,22,32,144,211,91,192,0,39,200,220,78,4,0,178,100,53,70,148,240,131,25,38,83,211,219,25,209,180,254,51,181,128,8,36,139,66,77,198,24,48,105,18,29,128,59,94,48,2,71,
190,1,77,152,245,9,79,120,101,77,201,77,26,173,224,0,25,254,146,192,128,6,130,134,156,167,188,68,96,57,26,33,166,183,140,251,52,254,48,18,205,48,200,52,115,113,132,8,24,57,78,205,13,97,0,24,254,219,195,
10,106,66,104,221,239,8,137,19,36,9,16,213,111,19,10,245,224,12,129,41,10,44,148,247,146,37,35,69,144,214,248,9,25,2,26,77,110,252,96,9,50,2,88,118,244,48,147,11,235,71,4,114,169,4,10,128,163,123,88,9,
115,114,132,134,171,120,33,9,150,131,219,12,16,181,196,160,209,79,30,166,65,37,18,103,232,241,140,232,218,127,24,1,13,166,25,6,83,155,194,4,12,24,167,102,138,194,0,49,253,183,132,5,53,33,141,30,248,225,
25,146,130,67,89,101,190,160,100,32,89,96,74,128,105,79,28,129,76,162,109,106,161,225,110,91,83,244,197,16,193,1,200,129,43,119,21,132,208,5,52,200,4,219,81,130,6,30,160,185,199,66,148,6,32,155,247,235,
6,69,36,201,74,3,138,192,139,7,224,104,120,192,1,67,49,14,205,60,116,88,130,73,34,155,85,71,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,222,0,38,103,87,227,
4,2,101,165,41,14,158,56,163,68,148,244,213,96,36,104,218,127,24,30,36,129,12,131,77,220,96,176,6,28,177,178,208,214,4,2,10,213,137,194,42,2,164,52,152,110,247,133,83,12,125,66,26,223,124,64,148,133,22,
74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,
18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,227,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,
105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,129,5,176,235,24,144,92,169,6,134,158,2,32,18,137,41,192,192,77,2,151,212,96,114,20,169,232,239,188,37,224,54,105,133,132,
0,24,64,138,56,129,36,20,40,81,80,119,218,192,216,244,82,205,134,117,224,97,0,64,92,166,138,89,62,123,137,40,159,43,239,24,84,132,214,240,128,3,16,69,28,12,144,138,148,209,107,39,222,18,232,33,208,193,
4,23,51,88,0,64,92,145,32,162,52,249,208,25,80,104,105,247,150,90,55,237,128,70,0,89,176,10,144,5,74,201,250,99,160,237,173,24,196,25,146,32,116,55,132,64,0,51,181,14,215,174,8,44,81,54,255,0,243,1,148,
84,73,146,1,25,220,73,68,249,95,120,9,37,170,89,27,194,0,12,32,64,40,172,0,48,40,83,69,173,121,176,70,188,28,216,103,94,6,0,16,22,41,162,150,188,0,16,202,36,217,194,68,149,217,214,16,50,0,105,65,242,186,
120,194,152,35,118,9,88,48,26,68,72,56,28,16,196,169,6,134,159,120,49,69,162,84,70,25,9,13,107,173,224,214,28,162,81,236,193,16,210,72,147,134,64,244,96,111,79,10,10,25,32,43,100,251,231,64,101,65,161,
167,223,34,37,5,138,37,104,239,188,17,0,131,36,92,31,56,224,173,10,39,79,19,33,53,19,8,239,188,148,17,27,40,135,131,0,144,18,194,225,36,211,69,141,167,222,32,137,254,248,153,33,33,133,215,254,225,16,104,
202,131,36,239,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,192,202,195,66,107,
190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,229,216,50,176,244,53,222,22,76,222,2,69,97,10,178,100,144,202,210,189,50,5,10,181,212,229,2,245,238,112,
37,201,177,63,67,245,88,200,68,41,244,194,36,170,38,144,156,84,9,77,167,13,38,189,48,25,36,223,165,100,8,216,182,183,132,40,202,36,144,101,104,215,166,27,62,188,5,142,194,70,85,245,88,64,93,1,49,172,4,
146,138,47,193,88,80,145,147,13,13,38,187,224,18,43,8,85,147,36,134,86,149,233,128,1,143,252,227,96,101,97,161,53,222,35,122,183,177,24,68,149,68,210,19,128,36,32,1,114,141,26,167,133,145,165,120,196,
37,102,255,0,94,48,200,68,153,25,78,171,181,135,16,41,79,128,113,82,186,247,194,37,44,154,212,254,152,64,93,1,49,172,34,74,150,60,225,2,50,152,32,50,157,86,72,157,130,79,89,2,54,46,133,225,10,50,153,36,
50,157,86,17,5,81,53,107,0,11,176,102,119,145,77,98,102,85,251,97,1,116,167,211,1,36,170,38,136,19,130,96,8,6,229,42,86,6,39,113,163,161,136,49,5,104,88,194,69,193,34,67,129,74,244,194,17,20,78,171,35,
34,10,89,150,115,176,111,78,74,127,76,48,48,61,177,18,85,20,84,38,179,96,101,97,161,53,223,34,80,50,139,38,72,6,154,244,194,83,166,71,88,48,43,201,123,55,136,19,38,145,67,95,85,134,52,2,242,32,227,20,
197,216,64,224,23,12,128,11,148,10,53,233,133,44,88,83,243,133,40,219,5,6,240,25,34,36,14,201,85,53,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,
236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,248,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,
145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,130,140,130,14,158,14,215,128,178,83,222,108,150,162,200,107,120,206,207,107,252,193,1,41,
8,249,77,239,10,103,100,167,114,218,134,178,12,52,189,8,172,33,49,36,118,1,225,195,194,144,48,25,116,218,43,120,206,207,79,253,194,25,129,76,64,44,149,128,4,161,1,149,244,13,101,161,212,175,243,32,74,
66,139,37,61,228,137,72,209,100,53,188,254,71,139,209,141,92,180,225,225,177,13,37,22,67,91,225,18,82,20,89,41,239,0,153,96,4,174,193,138,218,198,118,123,95,230,0,66,68,8,42,161,187,222,72,148,141,22,
67,91,227,101,152,236,79,206,119,18,51,242,138,222,122,222,12,50,0,61,70,111,2,40,9,46,141,60,41,69,154,13,127,153,180,72,69,65,205,239,59,3,148,236,190,214,0,35,176,158,150,47,100,13,92,188,198,119,18,
51,242,138,222,51,179,80,255,0,220,41,179,72,254,161,96,77,32,203,232,30,51,179,82,191,204,238,36,35,229,55,188,94,200,83,185,120,140,133,164,189,150,122,202,33,105,233,198,119,18,51,242,138,222,51,179,
211,255,0,112,8,182,193,249,146,176,131,10,55,192,53,134,36,166,212,173,253,48,197,36,197,80,221,239,2,140,156,202,207,178,30,107,87,198,0,48,74,100,92,188,198,11,18,204,76,213,12,86,248,129,41,10,44,
148,247,131,52,144,154,44,134,183,134,33,40,77,8,248,198,153,161,17,242,155,222,0,99,153,43,35,202,135,128,5,3,83,214,27,69,33,171,30,225,130,32,1,145,154,131,138,222,19,112,45,72,209,250,224,219,4,0,
254,169,60,25,40,17,149,228,67,91,194,150,3,98,215,90,192,0,9,200,65,65,202,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,
64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,
22,74,123,227,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,241,102,104,111,79,0,152,137,101,8,105,223,167,0,56,24,64,228,128,5,20,135,119,
233,128,203,2,6,253,48,209,194,137,170,132,59,94,171,43,34,89,170,125,28,38,64,9,100,212,13,223,107,3,2,8,38,170,112,137,133,41,251,97,0,204,164,42,29,223,167,37,9,136,128,41,107,94,171,9,11,183,243,198,
128,162,80,42,26,119,233,150,3,13,47,57,64,18,69,248,194,7,36,0,40,164,59,191,76,2,76,8,167,19,135,52,6,84,26,26,125,225,35,219,4,96,18,100,69,56,140,50,10,101,69,147,79,188,5,23,144,128,215,164,97,0,
18,8,0,162,85,174,234,177,197,138,239,76,96,144,148,181,215,140,13,162,73,8,6,215,211,2,145,144,90,243,128,73,145,20,226,48,133,128,36,18,129,80,238,253,50,192,97,165,231,40,2,72,191,24,64,196,16,1,68,
168,119,126,152,4,152,17,78,39,1,11,165,241,138,186,168,67,181,244,194,66,237,252,224,18,100,69,56,140,2,88,2,67,77,67,78,234,179,65,130,107,206,81,8,144,231,172,112,196,130,41,168,218,234,178,105,2,160,
250,224,214,130,143,76,32,23,76,33,45,175,85,130,7,151,30,185,112,143,221,103,18,68,201,64,208,211,239,24,3,26,128,50,46,107,253,194,4,146,1,166,65,77,59,244,195,147,2,20,154,120,32,5,0,164,65,233,128,
1,106,160,83,191,219,9,74,38,131,147,128,138,11,232,112,133,209,36,64,8,196,29,227,69,193,43,30,80,14,223,140,8,152,0,36,18,160,155,186,172,52,8,167,198,128,202,131,67,79,190,116,6,84,26,26,125,243,160,
50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,
239,157,129,149,134,132,215,124,68,4,146,49,144,68,146,148,9,65,19,92,81,239,251,97,32,66,80,180,203,34,107,24,96,108,5,241,199,97,43,74,130,174,240,130,47,215,131,128,196,177,105,154,19,89,160,118,201,
214,104,62,190,12,97,66,70,76,52,52,154,239,147,128,88,202,194,180,174,240,16,44,148,181,168,192,2,237,145,24,8,24,151,45,50,148,121,160,118,201,214,8,144,125,71,156,217,3,35,25,85,119,128,128,17,40,139,
194,22,21,174,204,102,192,202,195,66,107,188,16,65,232,225,32,132,37,252,97,67,34,101,6,82,141,122,112,230,9,0,18,22,67,44,107,4,145,41,12,49,55,232,236,161,142,144,155,46,84,19,93,227,130,202,217,142,
150,4,36,200,71,166,2,6,51,45,50,133,30,104,29,178,117,154,15,108,29,97,1,9,66,211,45,70,176,16,2,36,2,4,225,34,88,75,79,113,157,130,110,103,69,93,224,34,4,214,214,163,9,4,33,47,227,8,12,75,22,153,74,
53,154,7,108,157,102,131,219,7,88,1,68,80,180,203,34,107,188,40,14,136,21,222,29,128,65,167,188,184,50,157,167,69,93,140,57,13,4,149,168,194,37,0,72,125,28,69,132,52,25,232,127,77,228,32,82,103,227,5,
2,36,150,58,193,0,9,147,76,177,166,176,0,0,108,104,254,248,8,150,20,171,220,101,128,137,114,58,42,239,1,16,38,182,181,24,129,179,248,243,136,46,102,90,102,84,214,80,18,71,209,100,226,55,32,248,255,0,48,
200,9,66,74,101,187,44,8,4,144,85,231,5,19,16,76,30,243,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,
134,132,215,124,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,
22,67,91,226,4,147,15,100,229,63,24,64,33,98,229,58,52,53,128,33,13,228,9,72,81,100,167,188,64,144,105,26,31,169,109,96,32,17,254,219,196,0,192,41,164,192,101,60,145,41,26,44,134,183,128,144,14,235,211,
9,50,69,166,32,54,74,112,242,68,164,104,178,26,223,4,0,48,48,245,9,79,120,64,150,193,245,8,107,124,64,148,133,22,74,123,201,18,145,162,200,107,120,44,47,95,164,225,37,154,97,128,40,230,227,2,17,105,148,
79,100,86,16,64,90,111,165,56,170,110,67,36,55,120,65,77,73,240,30,214,240,20,94,0,4,88,56,105,48,114,158,2,81,166,80,34,142,42,48,8,149,127,25,2,82,20,89,41,239,2,4,105,144,29,26,26,194,81,9,243,161,
136,0,15,32,224,229,41,239,36,74,70,139,33,173,229,83,3,6,64,153,134,180,114,189,177,210,137,0,27,38,172,84,86,17,116,109,172,60,1,37,18,24,20,15,204,96,144,134,132,167,70,97,173,224,17,75,222,133,226,
10,110,67,41,13,222,50,102,164,162,144,213,96,32,17,254,219,192,0,11,8,181,96,244,240,2,83,76,160,68,167,21,140,232,219,95,56,65,13,166,24,2,83,155,194,1,11,25,167,64,246,176,148,66,124,232,99,162,110,
67,58,55,120,5,77,73,71,71,182,2,1,31,237,188,8,9,134,16,76,210,67,196,153,36,80,34,154,168,194,18,118,181,222,18,0,130,34,16,9,78,83,138,194,18,210,43,67,69,120,194,32,25,244,48,48,41,75,144,201,13,222,
2,10,153,145,9,35,85,188,0,176,159,209,156,16,9,114,13,38,109,60,153,29,148,196,167,21,140,232,219,95,56,65,13,166,24,2,83,155,194,1,11,25,167,64,246,177,69,47,190,150,0,8,78,65,157,2,239,12,153,169,38,
6,189,183,128,9,143,216,130,112,96,38,24,53,102,155,199,100,1,148,196,167,21,28,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,
18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,227,64,101,65,
161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,96,129,149,6,134,159,120,10,77,145,172,208,55,222,134,20,2,18,202,5,52,211,239,128,81,7,12,84,135,68,141,175,188,37,6,233,
2,58,174,24,51,50,16,209,79,10,237,248,92,104,12,168,52,52,251,231,64,101,65,161,167,223,32,0,10,104,129,13,105,213,96,32,91,157,199,120,220,6,183,161,133,90,76,201,34,14,251,194,64,29,41,227,64,101,65,
161,167,222,35,211,24,217,27,74,176,178,208,58,32,180,240,130,10,56,14,187,131,130,42,75,178,70,215,222,108,2,187,227,64,101,65,161,167,222,69,5,170,199,38,64,252,97,72,5,146,82,232,240,128,161,100,105,
95,140,16,128,27,236,235,90,192,4,76,152,129,2,216,0,80,130,36,231,83,47,172,48,82,29,10,141,179,65,215,91,24,198,200,218,85,140,167,3,146,246,30,108,5,173,43,205,3,125,232,96,130,146,236,84,109,158,48,
6,207,121,212,203,195,5,33,208,168,219,52,23,224,142,176,164,164,59,10,176,10,96,200,177,106,167,222,73,41,178,12,18,240,212,4,159,17,241,128,88,146,204,91,178,204,96,8,13,25,217,31,76,162,104,237,78,
5,64,64,153,4,65,223,120,16,181,246,55,140,108,141,165,88,202,112,57,47,97,230,192,90,210,188,208,55,222,134,8,41,46,197,70,216,55,12,119,129,91,18,7,163,147,168,57,4,42,12,135,131,34,13,81,236,97,9,36,
195,154,163,132,4,176,9,10,48,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,59,3,43,13,9,174,249,
216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,242,229,25,16,198,139,89,42,35,32,248,205,131,93,236,97,72,145,147,145,80,77,119,192,146,7,156,121,164,232,28,65,87,243,132,48,221,48,
7,87,193,16,145,52,99,4,53,233,154,4,19,190,176,17,89,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,192,240,32,159,140,216,53,222,198,18,110,23,7,16,85,223,156,4,138,41,187,137,
224,18,16,150,148,98,200,154,202,9,246,3,67,33,4,50,23,190,34,147,45,131,234,44,36,40,72,247,196,128,82,193,193,53,89,245,131,135,197,56,205,129,149,134,132,215,124,30,64,250,156,16,6,168,3,241,87,122,
202,2,12,131,58,202,2,251,7,99,251,195,162,72,104,50,160,171,188,43,15,126,198,3,193,107,179,141,52,157,3,141,43,249,205,135,125,104,100,32,134,66,247,196,82,101,177,238,44,208,32,157,245,155,3,242,15,
88,140,200,118,14,32,171,62,176,115,189,1,3,188,121,164,186,7,26,86,108,47,192,29,102,131,36,111,188,46,19,14,209,245,214,16,79,100,135,107,18,65,130,36,131,130,61,198,98,160,171,1,212,65,130,224,224,
25,150,134,134,52,211,52,104,130,172,216,119,214,134,66,8,100,47,124,69,38,91,30,226,205,2,9,223,89,176,63,32,245,143,52,25,131,141,61,30,16,3,176,96,247,148,76,1,94,189,227,73,37,136,224,81,170,197,25,
190,134,134,40,16,164,108,97,12,144,196,218,19,94,156,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,241,34,82,52,
89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,120,83,74,70,136,56,107,120,19,220,
159,190,0,198,129,13,90,221,198,16,32,96,197,62,200,173,225,178,169,228,9,72,81,100,167,188,40,69,144,168,178,26,222,0,1,159,97,214,48,65,149,122,8,202,123,201,18,145,162,200,107,120,44,47,79,172,96,5,
152,0,134,173,110,226,176,193,20,40,73,15,179,199,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,1,33,105,232,105,249,241,128,34,214,68,154,123,111,188,4,36,
116,151,111,24,66,192,80,72,57,79,120,100,67,51,67,78,26,222,0,1,159,97,214,0,0,2,88,53,217,55,146,36,137,36,20,122,10,192,101,13,211,192,11,48,1,13,90,221,197,98,25,72,18,160,203,67,91,192,81,254,49,
84,212,132,72,110,240,0,144,238,71,64,10,173,174,32,74,66,139,37,61,228,137,72,209,100,53,188,60,21,152,127,173,227,192,148,195,36,25,27,184,120,35,7,6,74,100,51,69,96,193,61,8,236,63,223,14,9,33,13,131,
7,62,235,8,17,45,34,130,32,246,194,2,205,245,214,0,0,2,88,53,217,55,132,20,104,146,157,173,86,51,236,211,248,192,11,48,1,13,90,221,225,2,6,12,83,179,67,88,64,6,61,199,120,130,154,144,194,67,119,132,84,
220,148,52,123,96,2,71,117,224,96,0,6,44,26,163,74,120,72,73,13,18,83,77,106,162,177,159,102,159,198,0,89,160,67,86,183,120,64,129,132,147,236,138,194,4,134,175,200,196,20,212,134,18,27,188,67,77,201,
65,33,170,192,0,51,236,58,192,0,0,75,6,187,38,240,130,141,18,83,181,170,198,125,154,127,24,1,102,0,33,171,91,188,32,64,193,138,118,104,107,8,18,26,191,35,8,10,106,67,26,61,240,65,22,204,161,236,43,0,13,
70,23,88,0,0,131,32,213,128,244,240,162,141,18,75,38,6,170,48,8,37,36,148,240,105,185,8,43,52,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,
69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,198,128,202,131,67,79,190,
116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,2,139,24,8,134,201,210,86,215,222,22,192,37,130,193,32,90,194,0,12,65,2,14,104,12,168,52,52,251,224,88,245,24,64,16,22,41,162,136,
211,197,34,100,144,223,183,9,32,100,160,84,26,125,224,34,0,214,214,227,8,0,21,8,102,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,11,216,91,250,96,0,36,65,0,163,128,1,129,82,154,
45,101,151,4,3,30,59,196,170,137,186,194,72,54,41,168,89,98,110,73,179,134,207,90,244,192,8,18,74,130,130,59,239,1,16,6,182,183,24,64,1,136,34,142,0,74,32,232,44,141,60,4,151,240,115,97,157,120,24,112,
16,22,41,162,182,92,164,129,146,129,80,105,247,134,36,80,126,99,44,15,99,222,5,11,112,9,0,181,150,1,8,220,17,223,251,150,82,117,209,140,4,0,86,82,10,35,79,16,25,146,68,225,34,33,90,122,206,226,74,39,202,
251,192,68,1,173,173,198,16,0,97,2,4,28,65,132,10,104,181,175,54,14,209,26,205,134,117,224,97,0,65,50,154,40,89,96,0,134,81,36,97,34,32,86,158,163,59,137,40,159,43,239,1,18,201,75,91,140,32,0,196,16,32,
224,0,97,18,154,40,217,102,193,26,240,115,97,237,1,172,0,32,44,83,69,44,158,0,8,102,73,18,112,145,16,173,61,103,113,37,19,229,125,224,34,0,214,214,227,8,0,48,129,2,14,4,50,10,20,209,107,39,155,4,107,193,
205,135,180,6,176,11,18,146,26,37,174,251,88,22,16,201,131,128,67,3,85,188,121,185,58,74,218,251,222,1,129,244,43,199,26,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,
125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,192,4,243,127,190,8,38,186,80,52,254,152,1,5,110,52,176,145,
179,155,3,43,13,9,174,249,33,24,134,211,135,85,233,132,67,2,148,142,159,27,3,43,13,9,174,241,4,244,111,173,225,18,69,22,187,195,40,6,100,228,84,19,93,174,118,6,86,26,19,93,243,176,50,176,208,154,239,17,
207,95,180,225,152,20,54,187,201,139,0,44,52,58,170,201,76,181,76,100,36,83,116,48,34,18,36,201,196,21,122,99,244,19,62,15,13,38,100,228,104,77,119,128,0,46,251,235,8,146,40,181,222,16,35,0,11,78,29,85,
86,88,231,248,194,209,121,158,240,133,89,50,72,101,105,94,152,0,24,227,96,101,97,161,53,223,5,37,140,94,164,224,192,105,2,3,40,154,174,214,88,184,16,113,40,141,216,239,253,195,2,70,90,112,210,250,227,
148,151,99,175,174,33,2,17,98,124,159,124,238,174,145,78,159,211,8,11,165,241,132,73,20,90,239,8,17,128,5,167,14,171,54,25,34,188,101,4,67,111,206,16,163,41,146,67,41,213,97,18,64,197,168,140,0,46,223,
206,119,87,72,167,79,233,132,5,210,235,88,68,145,69,174,240,129,65,32,54,3,135,85,233,150,19,41,47,25,65,16,77,249,194,20,98,27,78,29,86,17,36,81,107,172,0,46,223,206,119,87,72,167,79,233,132,5,210,248,
194,36,138,45,119,132,8,202,96,128,202,117,89,97,50,146,241,144,68,65,62,47,25,180,102,14,29,85,86,64,197,27,17,24,53,219,179,217,203,182,0,208,233,255,0,24,41,136,215,133,128,65,60,216,25,88,104,77,119,
206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,226,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,
69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,0,12,201,2,137,202,83,222,16,193,16,146,29,250,148,60,133,164,189,150,20,187,194,23,47,48,242,163,72,173,165,13,67,226,
4,164,40,178,83,222,14,212,168,120,26,222,51,179,218,255,0,50,1,47,15,213,123,201,18,145,162,200,107,124,47,100,16,180,244,227,59,137,25,249,69,111,1,176,213,15,253,192,0,0,242,20,57,74,121,34,82,52,89,
13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,141,134,40,39,41,79,107,52,180,181,122,43,120,200,54,209,79,253,194,155,65,31,212,39,129,52,131,124,3,88,36,176,27,82,191,204,91,72,139,245,94,242,68,
164,104,178,26,222,8,76,255,0,224,207,88,68,45,61,56,206,226,70,126,81,91,198,65,219,29,227,34,70,12,124,130,192,154,65,151,208,53,140,236,246,191,204,236,36,34,182,155,222,8,139,41,149,175,42,31,16,37,
33,69,146,158,240,166,148,140,148,28,53,188,157,19,233,147,131,13,24,25,33,100,167,188,19,44,140,135,98,26,194,48,199,202,127,198,242,193,166,40,103,100,247,132,6,226,80,55,234,80,242,8,97,37,236,179,
214,81,11,79,78,51,184,145,159,148,86,241,157,158,159,251,133,54,131,31,32,176,38,141,50,250,7,140,236,212,175,243,59,4,196,86,211,123,200,236,166,86,188,168,200,90,75,217,98,246,64,213,203,204,103,113,
35,63,40,173,227,59,53,15,253,194,155,52,143,234,22,4,210,13,240,15,25,217,169,95,230,119,18,17,242,155,222,47,100,41,220,188,70,66,210,94,203,61,101,16,180,244,227,59,137,25,249,69,111,25,217,168,127,
238,20,217,164,127,80,176,38,144,103,212,33,229,225,189,167,130,0,210,162,131,155,222,121,10,64,118,3,134,161,224,147,133,240,176,108,172,37,95,213,15,24,38,145,146,131,138,223,16,37,33,69,146,158,242,
68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,
223,16,37,33,69,146,158,248,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,1,26,24,146,173,122,107,34,234,45,25,90,245,88,65,157,138,141,241,160,50,160,208,
211,239,128,201,139,194,6,69,52,74,135,119,233,128,75,34,148,158,215,26,3,42,13,13,62,240,131,3,230,59,192,36,194,41,245,132,51,16,211,80,238,253,48,130,47,141,1,149,6,134,159,124,232,12,168,52,52,251,
226,32,77,16,64,61,98,37,128,36,88,138,218,253,49,129,59,20,158,242,68,108,29,26,194,7,100,209,42,29,223,166,20,137,8,191,82,51,125,122,235,34,234,13,25,95,213,97,33,122,208,239,0,50,35,81,137,32,100,
160,84,26,125,224,36,86,18,81,92,248,194,160,73,38,65,40,167,105,227,140,52,152,72,228,1,210,130,14,176,172,137,84,18,29,175,167,41,32,100,160,84,26,125,226,75,45,44,43,0,22,67,145,214,16,10,25,34,84,
109,116,214,28,152,165,127,173,96,208,52,4,17,209,24,35,99,172,10,27,253,176,144,187,127,56,4,152,69,62,176,133,152,134,154,135,119,144,96,193,62,111,36,70,193,181,172,32,100,83,32,148,83,187,192,36,177,
73,56,156,4,46,151,198,69,53,13,25,95,237,132,133,216,49,27,192,36,233,67,198,16,178,41,128,10,41,221,227,2,118,41,61,228,136,216,58,53,132,12,138,104,149,14,239,211,0,147,8,167,222,2,23,75,227,34,154,
134,140,175,246,194,66,237,252,224,18,97,20,250,194,22,69,48,1,69,59,188,129,59,20,158,242,72,9,35,205,97,3,48,0,166,161,221,225,160,120,38,39,17,104,2,43,162,49,115,49,100,101,177,234,176,4,183,126,248,
64,74,33,170,135,131,52,52,64,246,39,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,129,149,134,132,215,124,236,12,172,52,38,
187,231,96,101,97,161,53,223,59,3,43,13,9,174,241,0,0,193,235,24,200,173,105,161,157,132,173,136,42,239,17,5,188,146,5,135,198,192,202,195,66,107,190,40,247,253,176,128,132,169,105,150,163,88,192,32,96,
128,151,27,3,43,13,9,174,242,207,66,253,240,144,66,8,147,67,8,4,137,98,211,61,21,154,4,239,192,194,17,89,176,50,176,208,154,239,157,129,149,134,132,215,124,20,17,103,88,96,36,100,66,2,100,147,205,2,118,
244,48,0,73,50,196,194,172,18,8,74,151,103,162,187,243,145,3,4,126,248,113,16,2,50,140,97,36,100,220,138,210,187,194,4,90,180,224,24,195,9,3,189,102,192,202,195,66,107,188,184,24,1,156,30,244,70,50,64,
18,165,166,81,68,240,8,0,74,35,89,64,71,214,194,206,226,78,103,194,187,194,87,30,131,92,108,12,172,52,38,187,225,33,155,96,225,130,68,45,50,198,154,254,112,32,0,72,11,8,75,30,207,97,102,213,36,98,180,
174,241,129,103,93,117,132,130,16,68,154,24,64,36,75,22,153,232,172,208,39,126,6,104,49,191,7,9,2,24,150,153,70,143,1,0,0,80,32,86,18,34,69,105,238,51,184,147,153,240,174,240,16,44,150,214,158,18,8,66,
73,16,48,128,196,177,105,148,163,89,160,78,252,12,208,99,126,14,16,16,148,45,50,212,172,4,0,138,4,9,24,72,136,86,158,243,184,147,153,240,174,240,17,2,173,173,97,32,132,17,38,134,4,34,75,22,153,74,53,154,
2,59,122,25,160,198,252,28,32,33,129,105,158,138,192,147,33,21,135,99,241,178,177,132,26,87,244,85,222,28,152,68,176,53,24,22,164,151,227,46,199,184,61,13,118,185,216,25,88,104,77,119,206,192,202,195,
66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,
40,178,83,222,72,148,141,22,67,91,193,97,211,193,28,192,72,105,48,23,188,4,128,96,2,80,218,213,70,16,3,177,53,243,140,77,177,30,161,41,195,201,18,145,162,200,107,124,64,148,133,22,74,123,196,9,6,145,162,
200,107,120,8,4,127,182,241,2,67,38,26,76,210,158,72,148,141,22,67,91,224,128,0,204,67,73,167,231,198,16,8,88,177,77,35,67,88,75,38,247,210,199,68,220,25,72,110,254,49,130,117,37,20,102,218,241,196,9,
72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,96,114,153,77,89,13,111,16,0,78,142,163,21,77,200,100,134,239,60,181,44,72,56,172,4,7,250,2,14,17,1,144,225,129,102,148,240,0,6,0,37,0,166,
154,195,54,1,182,191,220,37,145,100,48,213,237,189,224,128,65,164,100,154,112,214,248,112,73,136,106,6,239,120,37,77,73,109,26,173,224,32,17,254,219,192,140,168,210,96,12,167,188,4,128,96,2,80,218,213,
70,51,236,218,249,194,75,52,195,0,81,205,198,12,18,88,177,77,89,13,113,2,82,20,89,41,239,10,105,72,201,65,195,91,197,0,69,17,71,4,39,50,13,104,229,63,24,33,32,18,0,48,58,106,161,172,34,116,109,175,56,
113,109,135,129,180,252,96,0,75,12,128,116,15,107,9,0,135,185,235,25,19,112,103,70,239,227,0,169,169,40,232,246,192,64,35,253,183,128,0,88,48,106,205,41,224,4,128,192,4,160,109,106,163,25,209,182,190,
112,130,27,76,48,4,167,55,132,8,88,177,78,141,21,132,128,67,250,75,16,83,114,25,72,110,241,13,53,37,20,134,171,1,0,143,246,222,0,1,96,193,171,52,222,0,74,105,148,13,173,84,99,58,54,215,206,16,89,162,67,
86,183,120,64,133,139,20,232,208,214,18,1,15,233,44,0,166,228,51,163,223,25,51,82,71,70,171,1,0,143,177,239,0,0,176,96,213,154,83,195,53,48,37,2,3,94,209,135,147,176,90,240,79,140,97,18,76,64,74,6,110,
43,0,76,25,128,213,145,80,235,5,59,110,41,28,9,37,33,5,7,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,
33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,141,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,33,10,20,52,21,6,158,20,129,208,65,108,102,194,81,58,235,13,
224,18,47,34,125,172,4,109,247,174,52,6,84,26,26,125,240,72,179,214,85,72,116,72,131,188,36,26,225,29,46,52,6,84,26,26,125,229,130,243,251,102,129,190,244,48,32,83,37,2,144,53,214,125,32,95,174,117,50,
231,9,37,100,162,67,77,62,249,208,25,80,104,105,247,200,144,137,38,88,168,22,78,158,2,145,9,63,92,37,34,72,108,120,197,98,14,133,65,71,125,228,192,131,29,34,198,27,140,27,17,88,88,152,52,61,135,139,70,
211,4,118,8,194,101,142,176,6,20,232,42,15,211,62,144,51,169,151,56,4,130,153,33,81,7,124,1,103,62,152,202,112,88,189,135,140,44,204,154,188,208,55,222,134,1,9,45,68,65,167,200,4,0,166,84,21,6,177,64,
91,3,91,25,97,163,9,74,88,116,12,22,175,34,121,20,204,143,22,48,70,21,177,160,49,24,146,236,84,65,222,125,32,103,83,46,113,162,144,232,84,65,222,104,47,193,29,102,194,81,58,235,25,78,11,23,176,241,133,
153,147,87,154,6,251,208,196,98,75,177,81,7,121,212,64,25,245,131,136,196,135,66,162,14,243,65,215,91,24,198,200,193,170,198,83,131,67,216,121,176,22,70,187,205,3,125,232,96,51,41,46,197,70,215,222,117,
16,179,235,7,40,164,58,36,20,119,89,160,191,4,117,139,52,24,53,88,234,131,49,26,41,247,135,29,140,146,59,89,17,7,182,250,172,58,1,46,138,64,181,214,88,250,241,160,50,160,208,211,239,157,1,149,6,134,159,
124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,40,22,46,80,129,53,222,32,219,208,235,13,70,86,222,22,88,128,
218,240,53,132,178,248,216,25,88,104,77,119,196,135,172,186,146,232,209,5,88,12,2,222,186,23,198,192,202,195,66,107,188,176,94,127,108,216,53,222,198,20,3,20,54,21,4,215,124,14,230,22,17,18,18,232,28,
4,77,115,176,50,176,208,154,239,148,38,13,97,72,45,83,194,1,18,14,143,120,108,28,10,67,179,128,213,201,136,209,163,89,176,239,173,12,240,48,128,93,225,75,32,133,248,90,194,32,64,34,119,210,198,161,201,
223,153,194,8,9,152,37,160,162,106,176,152,54,199,89,220,194,194,74,69,44,49,78,154,239,138,145,129,148,36,6,199,184,177,141,17,166,235,54,3,86,250,203,169,14,205,16,85,128,1,135,124,108,12,172,52,38,
187,194,0,25,56,192,23,65,191,124,50,20,34,63,113,97,250,31,159,174,2,70,131,157,140,152,200,2,200,112,81,53,252,231,140,131,163,222,119,48,177,25,146,232,28,65,86,108,47,192,29,102,130,26,219,188,69,
40,28,31,184,177,141,17,166,235,54,13,119,177,136,204,135,96,226,10,179,184,151,157,204,1,136,204,151,64,226,10,179,97,223,90,24,192,193,154,110,241,20,160,112,126,226,205,0,39,183,89,176,107,189,140,
105,164,59,7,16,85,157,196,188,243,128,52,59,203,41,46,141,1,21,86,108,47,192,29,97,70,65,194,110,240,141,0,90,167,107,188,55,0,35,223,193,199,137,29,79,157,97,22,50,14,73,138,37,117,92,230,192,202,195,
66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,226,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,
68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,222,0,134,101,224,8,6,46,26,160,240,240,92,200,130,40,147,61,43,9,72,245,15,227,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,
37,61,227,4,75,19,36,72,106,183,128,0,103,250,75,10,12,38,9,73,26,83,201,18,145,162,200,107,124,45,136,32,156,166,240,144,64,193,202,118,109,172,16,12,119,144,37,33,69,146,158,241,10,66,230,136,105,173,
224,0,25,254,146,194,0,13,32,215,100,167,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,16,67,169,4,139,17,187,241,132,66,93,201,68,65,237,188,140,20,159,217,96,33,153,52,74,72,
210,158,18,81,166,81,38,142,42,48,137,141,130,158,16,1,32,160,68,52,115,113,129,44,131,18,26,131,222,48,48,157,237,224,237,169,144,144,221,252,98,17,14,228,208,131,219,107,128,0,147,33,69,146,156,60,47,
50,44,88,153,90,168,198,125,154,127,24,9,102,152,100,26,57,184,194,12,96,68,160,108,182,214,240,16,3,16,70,140,188,48,166,164,38,141,222,240,2,155,19,68,28,53,194,88,144,162,14,83,222,26,72,16,101,136,
32,112,212,60,35,114,27,79,12,11,18,17,12,131,79,120,172,17,166,12,72,118,111,24,158,100,118,222,50,38,160,198,141,223,198,17,83,114,80,209,237,128,0,103,250,75,1,0,12,98,213,3,211,194,9,33,144,73,68,
218,213,70,51,163,105,252,96,4,54,152,100,25,78,111,8,16,48,98,157,154,43,8,0,199,246,222,16,83,82,24,209,239,136,105,185,40,36,53,88,0,6,127,164,176,0,3,22,13,81,165,60,32,148,211,40,147,41,197,99,58,
54,159,198,2,65,45,2,25,22,183,113,132,130,6,19,78,193,237,97,0,24,254,219,194,10,106,67,26,61,241,211,55,37,13,26,172,1,25,159,26,24,8,0,99,22,168,30,158,16,73,12,130,74,38,214,170,48,141,216,167,235,
144,168,5,16,209,233,195,196,32,96,197,52,222,75,120,38,11,31,179,255,0,113,75,50,16,137,2,101,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,
100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,241,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,229,0,0,
188,50,13,14,240,192,12,134,231,87,133,4,143,167,140,32,12,18,20,80,166,13,62,215,58,3,42,13,13,62,248,16,67,51,56,0,64,92,166,138,89,60,161,89,54,120,208,25,80,104,105,247,130,195,167,56,64,1,132,8,163,
133,132,40,64,104,175,119,124,176,64,50,68,162,150,79,0,4,50,137,54,112,17,32,102,128,202,131,67,79,190,116,6,84,26,26,125,225,9,140,0,178,55,3,172,6,80,11,147,69,45,120,164,74,38,222,18,5,43,179,172,
238,36,162,124,175,188,32,154,250,168,107,6,25,8,134,0,2,72,133,52,123,47,211,1,72,19,5,244,99,198,73,126,144,194,10,2,74,192,86,201,224,0,134,81,38,206,18,34,5,105,234,51,184,146,137,242,190,240,18,75,
84,178,55,128,70,18,205,1,149,6,134,159,121,10,8,239,162,51,97,157,120,24,112,16,22,41,163,67,79,130,19,5,102,132,200,20,148,29,247,135,64,227,103,100,97,0,24,130,38,35,219,25,132,18,5,2,139,27,191,227,
26,0,46,143,71,54,25,215,129,128,4,5,202,104,165,150,0,8,101,18,108,225,34,32,86,158,163,59,137,40,159,43,239,1,36,181,75,35,120,64,1,132,8,5,21,128,6,5,10,104,181,175,54,8,215,131,155,12,235,192,192,
2,2,197,52,82,215,128,2,25,68,155,56,72,146,187,58,206,226,74,39,202,251,192,68,10,182,183,132,0,24,64,138,56,16,192,169,77,22,178,121,176,33,165,163,155,12,235,192,192,2,9,20,209,236,188,0,16,202,36,
217,194,68,64,173,61,70,64,24,157,49,181,247,134,73,36,65,13,149,130,0,130,4,53,236,112,137,12,211,82,232,251,193,64,17,14,61,120,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,
160,50,160,208,211,239,157,1,149,6,134,159,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,51,113,77,144,202,117,251,97,16,85,19,72,70,0,0,236,38,79,123,198,82,50,176,166,151,213,
115,176,50,176,208,154,239,131,3,97,30,175,120,66,172,153,36,50,180,175,76,137,67,233,215,27,3,43,13,9,174,248,34,74,162,105,9,195,55,20,236,141,43,211,144,32,153,147,145,146,77,119,132,144,101,9,192,
17,128,5,219,249,194,74,32,77,201,153,83,245,92,236,12,172,52,38,187,225,41,65,54,187,27,194,132,50,108,134,86,149,233,128,193,240,146,32,172,66,27,6,123,120,66,70,87,200,248,63,166,32,69,9,244,250,98,
117,209,136,188,27,68,34,129,200,213,85,97,33,46,197,69,60,34,48,81,36,189,252,101,88,27,7,26,53,233,142,65,68,232,70,64,77,21,61,225,238,74,49,77,47,219,6,17,37,82,199,156,50,2,101,141,134,132,215,124,
54,175,247,194,21,100,201,33,149,165,122,96,0,99,255,0,56,142,80,6,70,70,48,73,82,248,194,146,7,176,83,88,12,10,37,6,90,102,26,244,195,36,157,180,14,178,4,108,91,91,194,20,101,18,73,14,52,175,76,34,10,
162,105,8,192,2,237,252,228,83,88,153,149,126,216,64,93,1,49,172,34,74,150,60,225,2,50,152,32,50,157,86,72,157,130,79,89,2,54,46,133,225,10,50,153,36,50,157,86,17,5,81,53,107,0,11,176,102,119,145,77,98,
102,85,251,97,1,116,167,211,8,146,168,154,66,112,129,25,64,130,3,141,43,211,36,78,193,39,172,96,136,179,226,240,133,24,134,211,135,85,132,65,84,77,33,24,0,93,191,156,184,173,76,248,126,216,1,29,65,63,
76,144,138,125,28,97,22,12,0,48,101,123,61,49,136,54,35,251,227,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,241,34,82,52,89,13,111,136,18,
144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,14,164,208,107,252,206,194,66,43,105,189,225,9,45,38,86,71,149,15,136,18,
144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,120,19,72,55,192,53,140,236,246,191,204,236,41,31,41,189,228,137,72,209,100,53,190,32,74,66,139,37,61,229,210,145,158,154,173,224,220,154,41,
189,100,9,72,81,100,167,188,145,41,26,44,134,183,192,1,57,138,26,114,158,242,123,41,149,175,42,30,66,241,240,176,0,137,40,105,89,167,13,100,137,72,209,100,53,190,32,74,66,139,37,61,227,0,139,72,166,172,
134,183,133,112,218,16,117,163,24,96,73,164,42,131,148,247,137,187,148,173,19,181,24,75,211,125,44,94,200,33,126,135,24,67,58,102,105,166,43,120,26,219,216,255,0,184,39,224,47,98,87,156,76,128,166,167,
192,240,21,147,107,252,192,80,89,8,142,128,205,239,12,25,18,40,83,150,214,248,129,41,10,44,148,247,132,144,145,2,124,71,21,188,68,182,218,97,189,100,9,72,81,100,167,188,145,41,26,44,134,183,140,148,155,
218,218,193,36,26,67,222,77,239,54,9,25,39,40,107,13,120,110,112,111,176,33,104,116,227,24,50,68,153,249,69,111,12,97,154,65,253,119,128,25,157,30,160,138,192,154,52,203,232,30,51,179,82,191,204,236,19,
17,91,77,239,39,178,153,90,242,163,33,105,47,101,139,217,3,87,47,49,157,196,140,252,162,183,140,236,212,63,247,10,108,210,63,168,88,19,72,50,250,7,140,236,212,175,243,59,137,8,249,77,239,23,178,20,238,
94,35,33,105,47,101,158,178,136,90,122,113,157,196,140,252,162,183,140,236,212,63,247,10,108,210,63,168,88,19,72,51,234,16,241,157,158,211,254,51,176,76,69,109,55,188,158,202,101,107,202,140,86,165,30,
153,29,176,2,175,208,227,59,15,47,177,91,192,33,201,202,126,158,113,119,11,253,66,123,196,177,34,161,7,181,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,
32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,241,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,228,77,70,68,20,41,
221,250,96,18,96,69,56,156,37,251,0,51,64,101,65,161,167,223,58,3,42,13,13,62,240,88,245,25,64,18,69,248,194,7,36,0,40,164,59,191,76,145,126,181,198,128,202,131,67,79,190,1,22,68,29,250,224,18,232,144,
212,32,83,191,78,116,6,84,26,26,125,240,136,53,251,99,174,170,16,237,122,172,36,46,221,14,240,130,44,102,128,202,131,67,79,190,76,4,8,100,16,208,211,244,194,214,191,156,8,10,135,236,107,1,28,128,36,10,
239,234,176,41,18,220,15,58,88,4,153,17,78,35,12,152,4,130,80,72,90,253,48,216,97,175,124,23,9,178,124,97,0,145,32,64,149,14,239,181,134,9,143,115,217,225,178,166,161,13,53,235,148,108,120,2,94,1,38,68,
83,136,194,23,4,65,40,36,59,191,78,82,68,201,64,208,211,239,11,144,26,156,0,88,65,26,196,144,50,80,42,13,62,240,54,250,127,230,17,0,19,245,108,99,150,0,144,208,42,19,183,166,69,131,180,71,145,148,0,73,
12,31,24,64,228,16,26,37,67,187,244,192,36,192,138,113,56,8,93,47,140,117,213,66,29,175,166,18,23,111,231,0,147,34,41,196,97,11,0,72,37,2,161,221,250,101,128,195,75,206,80,4,145,126,48,129,136,32,2,137,
80,238,253,48,9,48,34,156,78,2,23,75,227,21,117,80,135,107,233,132,133,219,249,192,36,200,138,113,24,66,224,18,26,5,67,187,244,203,1,134,151,156,208,36,139,241,128,67,16,64,105,168,105,221,86,1,38,4,83,
137,192,66,233,124,97,68,234,161,13,181,244,194,10,238,176,73,50,33,9,234,112,196,128,18,9,6,161,162,111,211,35,40,117,236,8,195,103,212,230,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,
211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,200,64,12,11,76,163,217,99,130,136,143,247,141,129,149,134,132,215,124,236,12,172,
52,38,187,192,9,40,102,131,219,7,88,72,16,148,45,50,200,154,231,96,101,97,161,53,223,12,16,2,73,11,211,3,4,75,150,129,40,82,107,157,129,149,134,132,215,124,128,210,102,129,149,5,88,8,22,74,90,212,97,32,
132,36,154,24,64,200,100,208,154,19,93,243,176,50,176,208,154,239,54,33,96,115,141,31,80,176,214,19,70,50,138,187,205,73,213,129,146,10,216,253,60,36,4,147,105,148,163,71,36,1,42,79,65,100,0,24,152,232,
177,144,2,85,147,44,137,224,9,162,215,120,90,69,107,59,9,57,157,21,119,128,129,100,165,173,70,18,8,66,73,16,48,16,49,46,90,101,40,242,205,255,0,231,27,3,43,13,9,174,240,20,94,18,36,174,142,227,198,17,
72,75,27,10,8,171,188,34,31,91,239,2,66,73,56,32,17,76,20,9,64,134,189,48,160,4,162,137,195,145,122,142,186,194,64,134,37,166,81,163,192,64,8,194,249,194,68,72,173,61,198,118,9,185,157,21,119,128,129,
100,165,173,70,18,8,66,73,16,48,16,49,153,105,148,40,243,64,237,147,172,208,123,96,235,8,8,74,22,153,106,53,128,128,17,32,16,39,9,18,194,90,123,140,236,19,115,58,42,239,1,16,38,182,181,24,72,33,9,127,
24,16,137,44,90,101,40,214,104,29,178,117,154,15,108,29,97,1,9,66,211,45,70,176,16,2,48,190,112,145,18,43,79,113,155,165,147,58,42,239,12,11,41,34,80,214,0,176,36,144,191,156,34,72,150,36,166,81,19,194,
4,3,183,242,56,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,
226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,193,6,206,18,67,41,0,138,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,130,0,47,32,
9,26,114,158,241,212,212,145,72,106,183,128,128,71,251,111,2,73,72,65,65,202,123,201,18,145,162,200,107,124,64,148,133,22,74,123,196,1,44,114,83,72,208,214,18,136,79,157,12,129,41,10,44,148,247,146,37,
35,69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,24,32,49,96,210,135,135,136,16,177,114,159,100,53,132,128,67,250,75,16,164,46,40,134,211,222,72,148,141,22,67,91,226,4,164,40,178,83,222,
4,74,36,49,144,128,123,81,128,78,141,181,214,240,226,196,216,64,148,230,227,2,4,150,145,1,208,56,107,9,68,39,206,134,14,219,153,58,55,123,235,1,179,82,100,97,166,188,97,4,24,34,71,151,132,9,44,56,125,
14,83,192,73,1,160,74,27,90,168,198,125,155,95,56,73,102,152,96,10,57,184,194,1,11,23,41,209,161,172,36,2,31,210,88,146,18,14,16,114,158,242,68,164,104,178,26,223,16,37,33,69,146,158,240,0,128,115,52,
65,195,91,194,101,157,146,214,0,72,98,1,131,77,111,20,229,139,199,96,177,91,140,168,154,246,194,8,229,137,19,160,93,237,100,53,230,64,232,52,214,2,1,31,237,188,0,0,176,139,86,15,79,1,36,6,129,40,27,90,
168,198,116,109,175,156,32,134,211,12,1,41,205,226,4,44,92,167,70,134,176,144,8,127,73,98,10,110,67,41,13,222,50,102,164,162,144,213,96,32,17,254,219,192,0,11,8,181,96,244,240,2,83,76,160,68,167,21,140,
232,219,95,56,65,13,166,24,2,83,155,194,1,11,25,167,64,246,176,144,8,127,73,96,5,55,33,157,30,248,201,6,84,148,66,154,173,224,40,140,121,209,192,0,11,8,181,96,244,240,18,64,104,18,129,181,170,140,51,7,
204,30,22,102,4,128,118,1,205,195,88,0,130,51,0,232,40,86,240,0,159,208,19,254,101,148,184,50,144,108,223,140,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,
145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,190,52,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,
124,178,129,149,5,65,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,128,132,84,183,157,76,190,176,192,8,18,64,42,10,52,251,231,64,101,65,161,167,223,4,194,92,179,165,130,42,75,178,70,215,223,58,3,
42,13,13,62,249,208,25,80,104,105,247,192,32,22,143,198,2,130,73,150,72,218,251,206,162,22,16,1,25,116,69,231,153,52,25,116,251,228,136,24,26,16,44,65,167,128,66,3,34,82,207,0,118,244,48,8,132,201,138,
136,59,195,84,34,178,48,50,207,241,128,106,68,2,160,163,79,9,8,83,223,99,219,9,114,115,222,27,40,105,247,149,35,30,69,188,16,2,76,128,74,128,141,62,242,2,215,26,3,42,13,13,62,249,4,144,128,232,208,211,
196,76,17,51,233,145,131,125,244,240,8,82,78,73,16,219,188,58,232,29,142,240,149,25,152,56,0,33,14,133,70,196,102,130,252,17,214,108,37,61,42,198,83,129,201,123,15,24,89,155,74,243,64,223,122,24,32,164,
187,21,27,103,81,11,58,153,125,97,130,144,232,84,109,154,14,186,216,198,54,70,210,172,101,56,28,151,176,243,96,45,105,94,104,27,239,67,4,20,151,98,163,108,234,33,103,156,131,177,222,24,41,14,137,6,203,
172,208,95,130,58,205,132,167,165,88,105,128,37,84,105,224,236,102,72,119,24,178,110,11,208,192,41,73,118,72,135,125,206,0,16,97,39,231,244,248,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,
26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,224,128,
54,10,121,244,129,146,17,114,129,199,179,190,118,6,86,26,19,93,240,8,37,236,120,121,117,33,217,162,10,176,193,35,207,27,3,43,13,9,174,249,216,25,88,104,77,119,206,196,197,200,202,154,239,1,18,27,76,108,
103,210,6,60,210,116,14,32,171,249,201,135,78,86,176,132,86,0,0,25,75,7,161,174,243,196,19,126,60,228,168,207,98,36,96,57,164,56,32,226,10,179,235,7,35,116,1,67,186,194,72,105,64,202,209,174,242,209,131,
208,165,128,138,82,35,193,198,146,50,114,42,9,174,249,5,36,28,19,68,21,96,0,80,126,252,108,12,172,52,38,187,228,142,196,209,143,67,88,13,66,79,194,156,158,18,134,250,120,48,57,14,9,104,96,190,184,122,
180,64,246,35,8,76,192,61,23,56,73,36,153,64,227,70,179,99,116,149,102,131,36,111,188,69,38,91,30,226,201,81,25,7,198,108,26,239,99,26,104,59,7,26,87,243,157,236,24,61,231,210,6,52,210,116,14,52,175,231,
54,29,245,161,144,130,25,11,223,17,73,150,199,184,179,64,130,119,214,108,15,200,61,99,205,6,96,227,79,71,157,236,24,61,231,210,6,35,50,93,3,136,42,205,133,248,3,172,76,131,36,64,61,224,88,35,96,250,139,
29,8,37,135,210,156,220,13,9,125,97,132,137,7,102,143,101,60,129,40,193,209,190,248,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,
124,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,
226,4,164,40,178,83,222,72,148,141,22,67,91,225,84,212,132,72,110,241,212,220,148,72,106,176,152,7,183,26,0,100,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,4,18,89,50,67,76,208,214,
16,1,143,113,222,6,2,204,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,16,164,46,104,134,154,222,0,1,159,97,
214,0,0,2,88,53,217,55,132,33,162,74,118,181,81,133,18,146,45,49,189,86,0,162,48,51,216,155,138,192,69,132,147,76,5,6,176,27,138,216,193,231,42,9,163,119,130,18,153,20,209,229,111,0,18,59,175,3,16,132,
136,16,74,163,74,120,64,13,50,154,125,42,26,194,103,200,135,218,200,18,144,162,201,79,120,136,229,34,154,240,53,188,32,72,106,252,140,8,129,104,40,105,202,123,201,18,145,162,200,107,124,64,148,133,22,
74,123,201,18,145,162,200,107,124,50,22,4,52,65,50,155,135,128,32,96,196,130,83,242,100,98,33,107,185,192,2,202,4,132,98,180,252,97,36,204,153,61,192,121,88,66,91,87,166,38,4,146,225,164,195,74,120,74,
73,69,18,81,36,53,170,138,197,218,90,107,0,75,24,4,52,67,91,188,32,64,194,73,246,69,97,2,67,87,228,98,10,106,67,9,13,222,33,166,228,160,144,213,96,0,25,246,29,96,0,0,37,131,93,147,120,65,70,137,41,218,
213,99,62,205,63,140,0,179,0,16,213,173,222,16,32,96,197,59,52,53,132,9,13,95,145,132,20,212,134,52,123,226,25,155,146,26,53,88,0,6,125,135,88,130,12,96,74,76,52,222,48,33,200,177,77,106,162,176,178,60,
161,248,197,16,75,66,25,6,123,94,4,164,4,74,125,158,60,97,4,33,65,91,103,8,4,180,77,43,37,61,172,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,
134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,190,52,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,
52,52,251,231,64,101,65,161,167,223,37,54,73,64,201,52,251,205,130,53,224,230,195,218,3,88,96,32,102,154,41,101,206,128,202,131,67,79,190,44,52,65,40,251,96,1,129,66,154,45,100,240,217,245,60,104,12,168,
52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,8,16,25,73,26,26,245,192,75,200,217,56,72,136,86,158,177,164,201,211,234,190,243,64,125,206,235,0,0,136,32,55,235,136,48,40,83,69,172,158,108,17,
162,53,155,12,233,104,98,12,9,20,209,66,203,10,145,68,135,239,132,152,43,204,216,195,33,98,212,193,181,247,128,52,63,165,132,0,24,130,4,28,36,224,50,72,13,13,62,249,208,25,80,104,105,247,206,128,202,131,
67,79,188,50,104,95,247,136,17,17,16,125,158,19,66,144,148,88,131,79,52,32,215,130,50,209,144,210,235,28,24,185,176,40,37,62,240,128,9,108,222,56,36,2,8,211,130,48,11,49,13,45,65,223,120,24,183,161,139,
140,96,9,34,3,140,0,193,186,104,181,147,194,18,1,74,66,142,72,146,9,104,13,124,224,1,1,98,154,41,100,240,0,67,50,72,147,132,136,133,105,235,59,137,40,159,43,239,1,16,6,182,183,24,64,1,132,8,16,112,33,
144,80,166,139,89,60,216,35,94,14,108,61,160,53,142,8,36,72,162,160,240,149,157,225,195,3,3,123,24,59,9,162,149,181,247,132,38,80,109,116,7,243,132,0,98,8,26,195,32,145,100,209,98,148,253,48,241,160,50,
160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,
157,129,149,134,132,215,124,128,24,101,32,197,104,213,53,150,19,41,47,25,65,16,77,249,194,64,197,43,52,38,169,174,118,6,86,26,19,93,241,50,141,90,236,225,2,48,0,180,225,213,85,97,46,79,27,3,43,13,9,174,
249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,240,26,87,154,56,55,215,200,202,158,65,106,9,143,31,76,61,72,88,161,139,64,81,176,209,165,85,96,118,200,98,162,178,17,8,219,139,248,
194,164,153,12,146,197,58,175,76,1,71,146,91,247,196,72,11,18,78,243,222,156,138,116,253,86,20,19,29,118,48,145,130,115,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,151,244,15,209,28,
49,76,212,168,148,112,128,0,36,10,6,81,38,43,181,150,12,175,140,36,132,89,114,35,14,84,146,109,22,157,107,198,22,36,11,77,95,174,5,38,223,161,127,92,8,154,235,39,78,60,98,173,71,149,142,34,99,64,139,250,
97,68,4,0,45,8,105,94,152,114,100,130,146,113,137,68,2,9,189,188,57,71,77,166,64,105,87,166,18,32,197,164,16,120,33,64,191,6,115,186,110,145,58,127,76,34,180,95,24,66,68,69,174,240,100,5,6,211,41,213,
99,2,84,84,86,28,36,132,244,131,194,65,129,178,197,3,77,97,196,2,134,199,147,132,52,185,236,147,239,138,23,171,22,134,190,171,8,34,76,117,227,8,162,98,253,86,28,137,153,57,16,26,77,15,28,236,12,172,52,
38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,
173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,241,2,82,20,89,41,239,36,74,70,139,33,173,229,229,248,235,10,109,4,127,80,158,4,210,13,240,143,136,18,144,162,201,
79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,73,36,159,209,91,198,118,122,127,238,30,212,168,121,19,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,
148,141,22,67,91,225,18,82,20,89,41,239,11,72,12,125,66,26,222,20,40,51,218,21,128,210,38,4,80,115,123,197,236,134,87,47,17,144,188,124,44,52,203,200,133,159,7,15,1,176,177,154,22,138,222,75,45,224,83,
35,4,249,4,240,148,194,50,161,100,63,56,72,151,94,145,131,4,33,40,100,131,155,222,16,146,12,80,218,112,214,240,145,138,29,12,129,41,10,44,148,247,146,37,35,69,144,214,248,129,41,10,44,148,247,146,37,35,
69,144,214,248,129,41,10,44,148,247,146,37,35,69,144,214,248,221,96,130,107,195,222,61,137,19,212,53,91,195,130,136,249,23,128,24,93,24,135,153,96,6,140,26,17,224,107,16,98,246,191,195,140,178,194,42,
14,108,222,76,50,164,101,63,17,131,218,205,170,133,157,180,225,229,128,200,212,129,199,171,8,236,212,57,88,5,177,68,145,246,167,129,105,6,77,232,60,50,139,83,31,214,109,146,18,8,57,188,12,153,12,150,219,
88,170,194,94,105,96,228,202,32,11,79,204,101,224,202,250,56,161,121,44,153,71,232,227,69,2,52,132,146,176,49,29,165,4,244,172,158,71,202,28,176,20,195,132,85,205,239,6,25,7,44,111,232,222,12,141,126,
197,130,147,32,106,253,14,30,5,114,36,201,65,197,111,9,38,201,126,114,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,
4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,223,26,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,
160,50,160,208,211,239,146,76,18,96,10,41,218,126,152,192,157,138,79,121,58,211,126,28,102,128,202,131,67,79,190,116,6,84,26,26,125,241,18,205,83,232,225,12,196,52,212,59,191,76,44,25,190,52,6,84,26,26,
125,242,196,72,160,208,211,239,25,61,107,207,211,61,129,220,97,70,4,67,160,167,107,170,203,1,134,151,156,145,27,7,70,176,129,145,77,18,161,221,250,96,18,97,20,251,192,66,233,124,97,5,32,53,52,101,107,
213,97,36,222,2,139,194,10,68,172,80,45,126,153,6,12,19,230,240,24,41,34,241,1,138,84,21,6,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,155,122,37,
178,240,203,2,18,244,201,56,5,18,154,128,110,240,12,9,147,61,188,122,44,95,143,166,4,118,0,18,73,16,107,213,99,140,8,94,67,192,128,96,88,49,3,68,181,174,154,192,173,251,27,62,131,10,11,38,42,72,140,176,
137,12,0,85,174,234,176,62,4,212,218,140,154,144,143,63,222,12,228,128,105,200,107,244,194,230,4,138,113,63,56,131,105,70,193,26,206,173,46,197,170,235,8,173,157,13,177,166,69,47,102,28,186,32,192,6,130,
216,146,118,52,123,249,199,33,34,61,2,201,86,1,162,75,36,110,251,195,142,137,20,167,235,144,95,172,178,49,66,20,45,25,95,213,96,75,36,199,238,79,166,16,25,242,164,95,249,154,3,42,13,13,62,249,208,25,80,
104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,
192,202,195,66,107,190,4,159,98,134,2,6,37,139,76,162,38,179,64,157,248,24,88,13,219,122,172,216,25,88,104,77,119,206,192,202,195,66,107,190,44,22,73,40,123,97,0,145,44,90,103,162,176,138,8,63,198,116,
37,126,199,17,4,41,180,73,100,77,96,27,65,219,56,72,178,32,107,89,220,73,204,248,87,120,8,22,173,173,60,36,16,132,146,32,96,32,98,88,180,202,34,107,52,9,223,129,154,12,111,193,194,66,132,169,105,154,21,
119,132,128,8,5,78,18,228,230,192,202,195,66,107,190,64,2,20,172,50,73,172,106,0,187,61,102,131,27,240,112,144,33,42,90,101,168,240,130,47,141,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,
161,53,223,59,3,43,13,9,174,240,16,69,95,35,34,17,51,65,224,9,182,105,147,162,177,36,247,170,198,105,198,108,12,172,52,38,187,231,96,101,97,161,53,223,0,132,60,12,197,54,153,149,53,88,1,0,51,113,132,131,
29,244,245,144,130,80,146,153,106,52,48,32,0,72,4,95,232,140,241,60,118,99,18,196,156,202,130,167,120,28,9,45,173,124,225,2,16,68,154,253,3,128,133,150,105,148,40,211,196,145,2,109,232,97,24,24,216,46,
15,206,5,66,84,180,207,69,59,192,160,3,4,122,97,2,69,106,83,11,198,18,44,41,90,84,21,119,132,19,175,31,173,99,25,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,
53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,196,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,228,137,72,209,100,
53,190,32,74,66,139,37,61,228,137,72,209,100,53,190,32,74,66,139,37,61,224,0,18,201,144,26,178,26,194,64,33,253,37,138,166,228,50,67,119,132,69,57,158,196,246,183,196,9,72,81,100,167,188,145,41,26,44,
134,183,196,9,72,81,100,167,188,8,22,38,64,105,26,26,194,64,33,238,122,197,64,203,16,201,228,191,140,112,200,73,100,134,171,0,0,137,173,137,7,34,18,33,128,42,72,57,194,243,41,25,9,90,172,4,97,219,94,248,
65,13,162,67,74,57,78,48,144,36,128,202,133,144,252,225,35,4,254,216,65,141,129,217,41,79,121,34,82,52,89,13,111,17,116,112,0,11,7,13,89,165,60,0,0,210,52,57,67,92,64,148,133,22,74,123,201,18,145,162,
200,107,124,16,4,105,10,28,165,60,67,51,2,74,132,61,176,16,8,255,0,109,224,0,5,131,6,147,52,167,131,112,0,37,11,45,86,16,69,228,9,72,81,100,167,188,145,41,26,44,134,183,196,9,72,81,100,167,188,145,41,
26,44,134,183,196,9,72,81,100,167,188,145,41,26,44,134,183,132,51,175,59,194,24,209,33,171,91,184,194,10,33,146,36,6,160,226,176,145,240,58,200,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,
201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,130,0,27,144,161,202,83,135,140,37,138,19,36,229,15,206,28,0,9,175,89,197,1,34,24,2,147,52,216,194,44,201,51,36,211,138,24,239,
179,107,244,48,46,68,72,130,65,187,140,1,35,23,41,209,161,203,2,9,39,227,11,178,144,202,4,122,211,195,5,129,141,30,6,176,4,25,192,139,3,6,155,7,43,206,32,157,131,36,83,88,72,246,45,163,88,76,18,68,136,
88,217,56,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,
52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,136,18,144,162,201,79,124,104,12,168,52,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,
1,97,6,167,172,170,146,236,145,7,121,212,64,28,104,12,168,52,52,251,231,64,101,65,161,167,223,4,193,13,239,161,89,85,37,217,34,14,240,153,99,141,1,149,6,134,159,124,161,152,72,43,67,79,188,97,102,100,
213,225,146,72,205,1,149,6,134,159,124,232,12,168,52,52,251,192,32,34,12,117,132,63,37,208,205,1,149,6,134,159,124,232,12,168,52,52,251,225,143,7,9,64,1,50,80,211,188,0,2,51,209,10,179,97,40,157,117,133,
144,201,145,98,246,31,120,99,108,250,113,160,50,160,208,211,239,157,1,149,6,134,159,124,3,55,24,202,112,105,123,15,32,160,178,60,70,18,77,230,128,202,131,67,79,190,65,33,51,160,167,107,215,8,69,18,125,
134,177,211,223,89,4,146,160,168,52,251,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,203,4,142,104,136,52,251,206,162,22,123,12,208,25,80,104,105,247,200,32,194,45,65,80,105,247,
206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,
66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,128,72,44,101,212,135,102,136,42,194,16,169,113,198,192,202,195,66,107,190,118,6,86,26,19,93,240,8,16,214,187,23,151,82,29,154,32,171,32,45,241,
176,50,176,208,154,239,144,128,193,65,158,134,187,198,52,70,155,172,66,35,54,6,86,26,19,93,243,176,50,176,208,154,239,0,4,128,113,129,131,52,221,226,4,140,108,52,38,171,157,129,149,134,132,215,124,168,
114,78,13,16,85,132,27,80,103,211,1,139,159,223,3,4,129,177,224,107,1,65,34,119,155,6,187,216,198,25,16,37,131,136,44,0,57,58,188,4,164,12,37,25,147,40,25,65,85,98,25,48,244,21,102,130,26,219,188,36,182,
16,113,163,93,242,24,33,50,176,201,38,187,200,74,233,212,224,219,0,64,3,253,197,116,116,104,130,172,34,13,151,161,21,132,160,67,35,111,10,76,236,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,
190,118,6,86,26,19,93,243,176,50,176,208,154,239,61,70,121,192,26,29,226,4,204,145,161,164,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,
66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,137,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,
201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,120,9,5,140,66,144,56,162,27,79,121,34,82,52,89,13,111,136,18,144,162,201,79,121,
34,82,52,89,13,111,136,18,144,162,201,79,120,17,97,50,67,76,208,214,16,140,71,141,28,96,129,100,0,27,23,121,34,82,52,89,13,111,136,18,144,162,201,79,121,34,82,52,89,13,111,135,8,181,34,210,182,158,18,
12,134,12,84,32,225,174,32,74,66,139,37,61,228,137,72,209,100,53,190,18,196,133,16,114,158,240,148,146,26,36,177,211,85,140,100,173,63,140,64,4,228,28,28,165,61,228,137,72,209,100,53,190,32,74,66,139,
37,61,228,137,72,209,100,53,188,0,64,38,116,60,1,148,0,40,146,132,134,148,226,176,44,151,145,66,154,126,56,68,148,133,22,74,123,201,0,164,52,89,13,111,2,72,8,251,165,128,128,146,134,18,27,189,225,1,36,
165,4,134,171,120,134,72,126,235,36,0,140,133,22,74,120,150,36,104,131,134,183,196,9,72,81,100,167,188,4,67,72,201,89,13,96,83,2,122,214,20,18,80,105,107,119,128,114,179,37,4,134,0,24,9,246,88,80,67,19,
68,164,129,202,120,206,28,137,4,223,74,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,224,68,130,193,196,19,78,83,196,
96,2,0,148,236,30,212,96,0,98,50,4,164,40,178,83,222,33,206,68,18,26,175,25,32,11,112,178,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,
148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,40,178,83,222,72,148,141,22,67,91,226,4,164,
40,178,83,223,26,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,
0,38,163,36,31,140,0,48,40,83,71,178,251,193,66,33,193,253,248,208,25,80,104,105,247,206,128,202,131,67,79,188,38,180,249,239,8,0,49,4,81,194,8,77,37,3,67,79,190,116,6,84,26,26,125,240,194,30,61,163,58,
200,212,99,107,239,8,34,138,35,177,254,225,7,167,121,160,50,160,208,211,239,128,103,198,240,8,28,72,161,5,45,245,194,144,200,12,236,225,129,33,122,27,53,132,224,4,180,128,232,211,239,25,175,157,83,194,
67,52,6,84,26,26,125,243,160,50,160,208,211,239,144,97,3,36,192,36,52,211,166,176,228,130,82,218,179,128,65,160,157,96,16,104,74,5,30,203,239,9,4,65,74,232,28,7,34,140,165,161,245,192,2,3,52,200,40,89,
96,2,4,162,78,253,176,200,208,126,235,1,130,20,168,52,52,233,224,48,24,73,48,132,87,239,188,3,56,133,48,33,167,120,137,21,198,128,202,131,67,79,190,65,154,8,105,40,105,167,222,51,69,221,52,48,128,58,35,
97,12,120,129,34,83,73,132,167,128,0,97,116,176,102,68,121,239,12,0,128,92,166,141,14,253,48,164,20,155,62,56,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,
239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,64,101,65,161,167,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,
134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,6,224,215,88,80,2,83,128,195,170,201,61,134,136,172,4,126,115,96,101,97,161,53,223,45,36,100,229,161,62,158,72,46,135,237,188,12,0,147,221,
4,86,48,34,37,48,1,148,233,253,57,216,25,88,104,77,119,192,16,41,186,123,120,2,61,130,27,87,213,96,17,70,164,120,250,99,147,2,33,208,71,14,195,100,25,0,209,170,120,82,222,181,35,32,66,73,110,35,24,43,
37,145,7,26,87,166,17,5,81,50,21,96,1,118,247,222,18,7,39,161,218,191,108,40,232,95,166,6,34,24,210,134,176,224,195,16,193,1,198,149,140,37,164,43,24,64,146,115,11,14,93,15,32,104,215,107,9,130,136,171,
32,1,4,224,21,48,118,112,2,4,214,33,77,95,182,32,64,1,117,173,224,149,26,242,167,13,0,148,11,1,195,170,167,128,72,182,72,210,172,96,66,130,91,25,38,230,201,7,14,171,181,143,35,163,244,198,23,239,48,247,
129,29,193,28,169,253,48,8,20,0,117,99,120,194,1,19,186,0,28,18,20,18,96,134,41,215,237,147,36,130,58,194,4,131,37,213,156,0,150,16,14,207,3,93,172,65,65,158,247,251,100,49,14,200,254,240,32,114,75,43,
215,237,132,4,168,10,90,250,97,18,85,19,72,78,16,35,40,16,1,149,163,94,152,37,154,175,19,144,145,102,252,129,155,2,137,100,56,105,87,167,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,
190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,124,236,12,172,52,38,187,226,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,
104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,242,68,164,104,178,26,223,16,
37,33,69,146,158,242,68,164,104,178,26,223,16,37,33,69,146,158,240,192,202,70,126,81,91,205,164,205,63,24,34,124,131,177,186,243,136,18,20,101,244,79,206,18,5,9,244,192,146,82,16,80,114,158,240,128,81,
38,50,236,134,183,136,147,47,233,56,45,138,24,92,180,227,4,81,33,152,237,21,188,1,148,37,233,191,231,39,96,74,28,60,201,225,18,100,0,18,130,164,134,183,132,154,179,226,114,81,228,16,47,85,239,16,18,193,
149,134,241,15,33,120,248,89,235,8,133,167,167,25,216,72,207,202,43,120,19,9,211,31,222,16,204,10,72,69,146,176,38,144,101,244,13,99,59,53,43,252,206,194,66,43,105,189,228,236,164,202,215,149,15,33,120,
248,88,189,24,213,203,78,30,118,18,51,242,138,222,51,179,211,255,0,112,128,208,82,81,228,79,0,100,5,50,65,224,120,19,9,82,135,245,157,132,133,91,77,239,23,187,19,185,120,135,128,58,17,240,176,34,65,80,
215,131,135,157,196,140,252,162,183,146,55,125,176,166,6,12,124,170,194,10,45,50,75,74,154,198,118,123,95,230,0,18,46,40,164,153,189,228,246,83,43,94,84,60,133,227,225,98,244,99,87,45,56,121,220,72,207,
202,43,120,206,207,79,253,194,155,52,148,121,19,199,24,1,151,208,60,122,199,181,130,2,73,7,137,187,222,47,118,39,114,218,135,144,188,124,44,245,132,66,211,211,140,238,36,103,229,21,188,102,165,168,39,
248,195,41,18,56,121,19,194,13,146,21,228,67,92,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,
22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,201,18,145,162,200,107,124,64,148,133,22,74,123,
227,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,226,18,106,158,
7,161,36,80,72,35,186,172,140,24,117,55,145,236,67,120,64,196,16,1,32,149,14,239,211,0,147,2,41,196,224,49,208,29,235,2,184,154,70,29,175,166,4,124,142,187,241,128,210,34,156,70,76,177,4,160,84,59,188,
6,71,205,96,176,65,145,233,0,224,204,192,2,138,90,238,178,101,128,252,235,1,11,165,30,152,171,170,132,59,94,171,9,11,183,243,128,73,145,20,226,48,9,96,9,13,66,201,221,86,104,48,77,121,202,0,148,223,140,
32,114,8,13,20,135,119,233,128,73,129,20,226,112,65,52,6,157,99,174,170,16,237,122,172,36,46,223,206,1,38,68,83,136,194,23,4,65,40,36,59,191,76,176,24,105,121,202,0,146,47,198,16,57,32,1,69,33,221,250,
96,18,96,69,56,156,4,46,151,198,22,18,80,5,10,118,189,86,18,23,111,231,0,147,34,41,196,97,39,113,100,2,129,187,170,192,192,130,9,170,156,36,116,110,112,129,200,32,52,82,29,223,166,4,136,16,145,52,240,
16,174,7,198,183,142,186,168,67,181,234,176,144,187,127,56,4,153,17,78,35,8,92,17,4,160,144,238,253,50,192,97,165,231,36,128,146,30,16,57,4,0,84,33,221,250,100,139,21,78,3,56,64,205,32,7,167,174,42,234,
161,14,215,170,192,132,150,244,44,227,46,66,30,198,115,114,37,148,10,35,78,154,231,64,101,65,161,167,223,58,3,42,13,13,62,249,208,25,80,104,105,247,206,128,202,131,67,79,190,116,6,84,26,26,125,243,160,
50,160,208,211,239,157,1,149,6,134,159,124,232,12,168,52,52,251,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,
157,129,149,134,132,215,124,236,12,172,52,38,187,225,32,188,120,194,32,204,101,160,73,4,77,97,46,10,118,117,144,4,250,24,70,48,130,133,38,137,40,209,224,132,132,55,222,16,88,40,215,156,236,36,230,116,
85,222,49,178,82,192,214,18,4,12,154,24,18,140,133,160,96,81,172,128,4,25,187,3,233,144,132,173,180,86,20,164,5,162,72,35,79,1,0,34,68,12,36,73,34,180,247,25,216,73,204,168,42,239,1,16,38,182,181,24,72,
33,9,127,24,64,98,88,180,202,34,107,52,14,217,235,52,24,216,235,9,2,18,165,166,90,141,96,32,4,97,124,225,34,36,86,158,227,59,9,57,149,5,93,224,4,22,91,107,88,72,33,9,36,64,192,64,196,185,105,148,40,243,
64,157,158,179,65,141,142,176,128,132,161,105,150,68,214,2,0,68,162,48,145,41,90,123,140,109,3,114,58,42,239,1,48,36,70,252,125,48,184,64,2,79,154,194,3,22,22,129,130,39,144,129,219,39,88,2,7,212,116,
112,22,137,104,146,212,121,84,74,90,209,194,68,72,173,61,198,118,18,115,58,42,239,1,2,201,75,90,140,36,16,132,146,32,96,32,98,92,180,202,81,230,129,234,122,24,8,137,1,177,231,8,12,40,92,146,198,154,202,
73,46,206,19,44,77,92,56,195,96,13,9,42,9,174,240,72,27,194,71,250,205,129,149,134,132,215,124,236,12,172,52,38,187,231,96,101,97,161,53,223,59,3,43,13,9,174,249,216,25,88,104,77,119,206,192,202,195,66,
107,190,118,6,86,26,19,93,243,176,50,176,208,154,239,157,129,149,134,132,215,127,140,169,245,247,205,61,242,175,127,223,47,237,252,231,186,176,41,235,187,190,47,237,252,229,222,223,190,84,254,142,84,126,
142,85,239,251,229,23,90,188,26,244,250,103,234,247,195,95,213,229,176,187,209,251,229,79,159,190,105,234,202,189,95,190,95,209,130,135,236,172,63,56,172,53,252,235,62,46,93,232,253,242,167,207,223,42,
60,253,242,155,221,221,229,253,184,253,94,252,95,219,249,203,189,191,124,161,253,28,211,223,42,247,253,242,222,216,40,123,86,126,175,126,47,237,252,229,222,223,190,126,133,86,84,126,142,127,37,94,122,
212,46,248,54,125,79,239,248,223,255,218,0,8,1,2,3,1,63,16,252,101,156,63,105,114,177,98,231,127,125,121,35,238,78,15,200,35,28,240,121,3,237,44,88,191,1,121,95,114,48,224,255,0,189,103,236,172,92,235,
240,183,202,199,246,247,154,224,255,0,221,24,107,151,143,31,2,120,223,225,43,47,148,49,112,254,200,224,127,220,56,62,218,252,77,225,230,49,98,251,3,15,7,254,224,225,98,197,139,236,47,195,172,158,87,216,
95,144,119,246,111,23,227,87,218,95,100,255,0,220,28,223,252,59,252,134,112,28,53,143,254,33,251,103,254,225,200,224,127,195,28,14,79,35,243,14,240,253,161,135,243,17,251,39,243,73,224,97,252,152,248,
127,131,24,127,40,223,217,89,56,255,0,0,62,224,126,73,28,63,178,241,243,57,63,120,126,224,71,228,139,63,97,114,242,57,120,241,228,31,188,88,254,216,195,249,24,97,174,73,203,197,139,22,78,60,99,35,153,
226,14,78,79,220,174,72,251,53,255,0,56,230,248,31,132,28,235,238,87,15,236,191,192,15,249,235,145,248,125,102,254,237,112,248,92,62,7,219,53,246,135,253,5,139,240,163,141,102,254,249,113,124,12,223,219,
56,127,37,152,228,140,31,127,57,99,238,119,135,135,143,31,228,154,226,191,0,35,138,226,190,229,112,15,3,55,249,28,207,224,71,216,21,246,15,23,246,43,47,242,61,97,252,24,60,94,15,178,103,237,87,228,129,
201,252,11,127,105,253,179,131,145,249,32,199,224,94,49,140,99,251,170,252,153,95,129,95,122,63,53,2,255,0,52,239,129,131,254,171,199,143,31,223,223,38,63,24,115,95,245,206,44,89,95,243,199,3,7,253,67,
201,193,248,11,226,255,0,24,115,92,111,254,161,193,205,126,6,248,53,248,179,131,139,31,245,14,15,176,134,86,15,190,174,1,194,48,126,42,184,31,246,199,223,214,30,43,241,71,53,255,0,88,253,163,31,131,31,
138,28,107,254,168,251,85,143,239,143,53,248,161,135,129,255,0,80,253,178,48,126,0,254,48,127,214,174,73,56,249,223,223,159,197,156,214,15,250,199,7,7,9,193,201,140,5,253,232,224,254,44,102,255,0,235,
30,78,1,131,145,247,199,53,131,241,7,53,255,0,102,185,88,31,35,239,78,31,197,235,141,255,0,222,223,223,107,141,254,40,127,223,223,224,14,15,196,140,31,246,79,217,223,224,53,131,240,227,141,127,219,223,
216,56,62,244,102,248,88,255,0,11,103,254,251,198,49,140,147,130,254,244,97,226,240,142,39,31,224,94,1,192,205,255,0,219,88,177,112,190,251,127,97,241,25,24,134,44,156,156,127,116,248,31,148,77,242,134,
46,23,217,140,88,177,113,57,60,79,11,22,87,35,55,249,62,114,114,120,88,184,158,35,23,15,236,62,95,15,31,11,15,229,149,195,251,11,149,136,100,100,114,241,126,92,67,23,218,67,132,56,67,255,0,164,175,39,
129,249,93,227,251,199,139,147,56,63,40,60,127,102,241,97,25,56,241,253,167,143,23,220,188,120,255,0,37,28,79,22,35,147,147,139,237,44,92,78,73,196,113,125,202,197,136,98,197,149,143,31,228,3,132,172,
120,249,39,243,25,15,8,197,133,156,71,17,124,179,143,30,60,103,25,199,143,25,199,143,39,25,201,199,143,24,251,182,56,120,241,240,191,35,30,117,131,15,35,237,125,56,25,188,24,47,131,246,143,216,222,31,
248,127,255,218,0,8,1,3,3,1,63,16,252,117,112,62,192,24,192,198,198,127,2,11,194,22,3,247,36,101,28,63,144,70,26,229,240,6,18,255,0,10,11,24,66,192,126,228,224,145,249,8,107,236,0,240,215,225,193,120,
66,199,143,237,156,23,249,12,60,8,100,12,37,254,32,28,64,226,88,241,227,251,86,63,32,2,185,39,241,128,72,199,132,3,141,146,49,227,252,140,63,248,12,240,64,225,4,125,128,103,13,126,100,5,225,31,96,22,48,
223,230,64,112,142,65,195,95,153,111,8,95,96,223,230,128,176,143,205,3,131,249,144,86,27,228,191,51,4,114,47,243,40,224,142,5,240,127,50,3,194,25,3,131,95,147,0,124,16,196,56,35,248,64,113,143,201,192,
62,14,25,225,156,108,96,226,7,27,27,17,252,11,192,120,35,242,80,172,39,133,139,22,44,88,177,156,103,132,28,95,129,24,103,242,80,172,55,131,237,44,88,177,98,199,194,15,4,126,252,67,195,31,146,41,134,240,
125,218,197,139,25,224,152,194,23,223,19,252,144,50,216,62,248,140,88,214,65,251,177,88,79,0,225,15,242,69,142,7,223,145,130,14,31,185,23,132,240,184,7,8,252,142,14,6,15,192,17,128,225,31,112,32,101,224,
24,177,112,11,24,66,252,142,11,25,88,15,224,8,192,112,133,246,128,194,94,1,246,14,86,25,31,145,193,88,100,96,140,5,253,249,226,199,217,1,225,56,7,218,35,1,194,39,242,56,43,8,120,63,0,70,81,195,56,142,
35,137,99,56,7,219,60,88,252,144,14,17,128,227,251,242,49,28,103,25,197,128,125,201,24,10,56,71,228,128,112,140,7,240,43,23,222,17,130,70,31,201,0,225,24,255,0,26,70,86,26,252,146,14,16,176,31,198,156,
24,111,242,72,56,66,192,127,24,114,142,7,228,160,112,133,128,254,48,224,145,249,44,23,132,44,7,241,100,96,51,132,126,75,18,50,142,15,197,28,49,134,71,228,203,24,63,22,70,10,252,152,10,195,128,254,40,224,
191,201,161,148,112,126,36,240,107,242,105,145,128,254,40,224,145,249,56,96,224,63,137,60,13,254,76,17,135,7,226,78,91,13,254,77,18,48,102,191,16,112,94,91,242,109,176,222,15,196,28,23,150,252,158,31,
136,56,47,13,254,78,188,15,196,30,6,255,0,39,10,224,126,28,224,175,202,3,120,63,16,96,126,81,1,199,248,82,112,97,252,158,12,229,225,11,30,60,120,255,0,2,78,19,130,7,229,16,86,65,196,224,216,142,35,143,
30,60,121,31,114,198,60,120,6,19,249,81,156,103,25,198,198,49,3,132,178,70,60,120,241,227,56,241,227,199,143,36,224,24,74,252,182,9,28,24,56,135,218,2,28,24,198,48,159,204,44,227,56,207,255,0,193,175,
255,217,0,0};

const char* TabWaveforms::background1_jpg = (const char*) resource_TabWaveforms_background1_jpg;
const int TabWaveforms::background1_jpgSize = 51706;

// JUCER_RESOURCE: basszero_vstiwaveform_png2, 11962, "../../../Resources/GUI/basszero_vsti-waveform.png"
static const unsigned char resource_TabWaveforms_basszero_vstiwaveform_png2[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,193,0,0,0,193,8,6,0,0,0,118,66,212,156,0,0,32,0,73,68,65,84,120,94,
237,93,9,124,84,213,213,63,239,205,36,33,9,171,236,106,1,1,193,13,9,90,133,160,66,104,75,107,181,10,84,9,72,21,89,212,90,81,17,1,81,9,48,152,168,168,88,192,245,115,131,72,85,32,184,64,109,173,150,170,
129,170,4,173,18,196,165,46,104,64,171,200,34,9,66,182,153,121,247,251,223,55,243,38,111,38,147,204,219,102,146,121,243,222,79,156,36,115,215,115,207,255,157,115,238,61,231,92,129,156,199,161,64,138,83,
64,72,241,249,59,211,119,40,64,14,8,28,38,72,121,10,56,32,72,121,22,112,8,224,128,192,225,129,148,167,128,3,130,148,103,1,135,0,14,8,28,30,72,121,10,56,32,72,121,22,112,8,224,128,192,225,129,148,167,128,
3,130,148,103,1,135,0,14,8,28,30,72,121,10,24,6,193,89,183,151,228,136,34,141,20,72,232,104,53,21,25,177,74,73,162,205,239,221,149,95,110,117,219,78,123,177,41,80,87,87,55,86,146,164,153,140,177,28,65,
176,126,125,99,143,64,127,9,140,181,18,99,45,23,69,113,69,70,70,198,6,61,45,232,6,65,142,231,165,142,153,190,250,85,36,8,99,245,116,100,168,44,99,27,106,220,233,83,203,61,227,42,13,213,119,42,233,166,
64,117,117,245,75,96,166,248,175,173,238,145,105,175,0,64,108,200,202,202,26,167,181,134,110,16,228,46,40,225,40,27,163,181,3,211,229,48,161,173,69,19,52,79,200,108,127,195,60,107,250,144,87,28,41,8,52,
150,65,202,225,51,47,216,102,37,99,84,46,64,74,225,115,67,109,90,250,70,187,129,179,178,170,170,40,35,61,125,126,249,206,143,216,186,151,254,42,108,223,177,147,126,58,114,196,44,73,19,86,127,196,57,185,
52,253,242,203,88,255,190,39,8,62,159,239,193,118,237,218,221,168,165,115,93,32,224,42,144,219,69,219,181,52,108,101,25,159,159,134,196,91,53,146,153,223,239,90,4,130,76,209,58,118,70,84,76,46,255,226,
50,207,101,21,90,235,180,214,114,53,53,53,125,48,182,175,143,30,173,102,151,76,158,46,36,19,243,171,105,218,174,109,91,122,97,245,83,44,59,59,75,200,204,204,212,196,223,154,10,41,157,228,46,88,127,19,
17,91,150,248,133,20,102,109,45,28,191,60,94,253,14,43,88,231,129,10,176,200,104,251,18,163,155,182,21,229,175,48,90,191,53,212,11,218,1,47,253,99,211,235,84,180,52,110,164,78,200,84,239,94,52,159,70,
12,31,70,113,1,129,89,102,49,74,1,232,120,139,203,138,38,120,140,214,111,170,30,183,111,218,248,189,203,244,188,253,155,106,139,75,133,90,87,218,172,100,85,145,32,9,56,125,23,173,124,102,13,61,245,151,
231,172,38,117,66,219,155,126,197,36,154,118,249,101,14,8,180,80,125,216,130,146,82,0,96,100,100,217,30,29,178,104,196,201,199,209,137,61,59,210,137,61,58,210,0,124,126,254,125,37,125,177,23,255,240,185,
229,211,255,209,222,170,234,70,93,192,86,40,45,43,202,31,165,165,239,214,86,198,1,129,198,21,177,147,36,192,92,138,161,2,93,25,57,245,105,121,167,208,85,191,56,53,38,69,158,124,227,99,90,89,250,73,227,
114,140,86,108,45,202,135,218,152,92,143,3,2,141,235,101,23,16,228,22,172,27,139,45,222,151,212,211,238,223,163,3,21,140,59,91,126,235,107,125,184,116,40,122,233,93,250,114,111,85,120,21,198,198,97,71,
75,215,94,181,214,62,227,85,206,1,129,70,202,218,7,4,37,21,136,169,235,173,76,59,59,35,141,94,156,125,33,181,107,147,166,145,18,13,197,190,175,60,74,147,31,222,68,71,235,188,161,63,226,176,175,162,172,
112,194,9,186,27,107,193,10,14,8,52,18,223,14,32,128,29,48,5,118,192,42,245,148,151,92,54,92,182,1,140,62,220,70,184,117,205,59,97,213,97,40,79,45,43,204,47,54,218,166,85,245,184,212,195,129,99,105,44,
131,221,1,129,70,138,27,5,193,212,17,3,105,98,110,127,185,151,181,91,191,164,85,91,62,211,216,99,160,152,149,187,67,145,198,240,121,39,29,75,247,76,58,71,215,120,162,21,158,247,220,219,244,239,255,126,
167,254,106,227,214,194,252,22,63,121,13,206,119,48,99,194,242,90,183,123,69,83,96,112,64,160,145,5,140,130,96,233,164,92,58,163,79,23,185,151,15,42,14,208,156,231,182,106,236,209,58,16,4,15,195,238,132,
20,152,164,116,142,183,53,45,189,252,92,58,103,64,79,93,227,137,86,152,219,7,83,30,221,20,246,85,141,43,173,83,172,55,176,233,142,99,52,16,1,122,156,118,71,7,131,25,16,172,88,82,68,189,142,63,14,231,11,
203,232,253,242,15,229,17,157,153,115,58,21,204,153,69,221,186,6,214,93,121,254,179,125,7,189,130,179,136,217,215,95,75,217,89,89,161,191,31,173,174,166,207,191,220,69,67,78,31,212,104,70,47,191,250,79,
90,178,236,65,205,164,106,117,91,164,67,122,119,161,91,47,202,161,52,183,40,79,194,235,147,104,201,203,229,180,125,247,1,205,147,178,66,18,228,22,132,219,1,74,231,61,58,102,209,139,55,95,168,121,44,205,
21,28,190,112,125,216,215,96,184,81,101,69,227,75,45,105,220,96,35,33,16,112,196,55,28,141,54,2,67,188,64,192,153,251,242,107,102,132,141,254,55,191,28,37,131,224,211,207,190,160,153,183,22,52,154,217,
85,147,255,64,249,227,46,166,146,151,254,74,79,174,126,86,247,204,91,29,8,20,85,104,231,55,63,202,147,25,244,179,99,116,171,68,18,147,86,136,130,24,182,155,163,135,50,56,209,205,17,5,90,142,125,124,249,
129,63,16,84,172,134,159,31,154,154,71,103,156,208,85,79,147,81,203,94,183,178,148,202,43,246,55,124,215,10,118,137,20,16,40,243,229,64,80,185,9,132,192,176,117,222,249,124,91,215,208,97,89,115,146,192,
1,1,168,202,85,33,133,241,57,119,112,219,128,3,66,143,74,4,73,176,25,123,250,141,14,181,180,114,45,103,128,0,227,195,37,142,255,16,124,148,223,181,158,13,196,234,111,249,43,229,84,82,246,133,12,48,85,
55,177,170,197,245,123,69,0,168,199,36,3,34,2,12,35,79,62,182,252,230,223,158,158,183,254,249,231,117,159,24,235,81,135,184,106,179,253,195,143,26,169,67,92,77,82,164,130,173,36,129,162,10,241,85,230,
42,16,127,184,106,164,252,174,85,37,66,108,193,70,65,36,237,27,248,145,108,197,232,120,48,101,191,112,141,0,160,8,240,2,205,252,109,14,77,200,61,209,52,51,38,21,8,130,18,145,79,26,160,168,202,59,185,103,
249,205,23,12,30,105,53,8,82,94,18,204,185,96,48,93,144,211,43,42,115,189,82,190,135,150,190,178,67,19,227,153,181,9,212,222,175,33,181,64,197,4,197,127,26,173,235,144,172,169,65,39,133,58,20,193,252,
128,0,118,141,210,151,59,234,144,38,86,36,210,187,59,180,242,234,60,58,238,152,236,48,27,64,177,17,254,247,227,81,154,246,68,169,166,158,205,130,128,119,210,148,159,80,78,159,174,244,200,180,60,77,227,
136,85,168,53,27,198,56,192,131,212,11,168,130,252,205,175,48,191,178,123,101,214,48,254,249,144,193,33,242,120,189,94,122,125,243,91,116,198,224,65,141,118,135,190,222,189,135,254,178,238,249,212,48,
140,71,159,118,60,205,252,205,32,249,36,85,189,27,164,168,72,252,148,118,197,107,59,105,211,71,223,198,226,45,75,206,9,184,199,104,186,175,254,86,81,16,230,9,208,131,24,231,7,124,62,50,125,20,13,9,110,
223,198,28,72,51,5,146,97,139,52,26,243,43,83,50,3,2,51,116,139,71,221,86,183,59,100,197,36,173,144,4,202,56,34,37,194,8,28,150,45,177,249,97,25,192,14,67,44,160,246,56,135,101,141,57,82,87,80,141,94,
117,200,10,0,4,196,183,117,241,4,142,219,68,244,85,113,36,129,70,110,181,3,8,248,84,35,15,206,218,194,113,238,5,28,152,25,117,160,187,242,145,77,116,164,182,193,129,14,111,222,221,112,167,238,163,145,
172,173,162,152,3,2,141,203,96,31,16,52,118,165,230,193,51,243,199,157,165,107,151,136,219,1,183,174,121,155,246,86,70,4,216,180,130,67,50,141,75,26,42,230,128,64,35,197,236,2,130,160,52,88,142,205,146,
153,145,83,159,62,234,84,154,62,234,148,152,20,113,130,106,98,146,168,197,10,56,134,177,14,210,55,25,94,9,127,162,145,60,188,18,210,161,191,42,188,242,75,30,94,137,127,155,121,120,101,228,219,63,208,111,
171,240,28,213,65,2,71,18,128,2,186,12,99,187,101,155,144,3,237,125,245,203,163,133,89,106,97,164,240,189,119,246,52,118,95,110,106,105,175,81,45,227,142,86,198,81,135,52,82,206,174,121,135,204,170,121,
18,209,29,219,10,243,13,167,108,209,72,254,184,22,139,119,202,149,225,217,149,52,174,195,65,234,159,81,67,109,93,18,149,87,103,211,51,63,118,167,29,181,109,45,159,87,92,83,174,200,186,116,162,51,208,37,
72,197,144,227,13,124,34,207,63,212,40,248,190,169,85,194,214,237,46,148,239,135,221,160,245,216,13,202,183,124,53,19,216,160,146,124,235,200,209,163,236,210,201,87,89,154,124,139,3,96,113,207,61,81,103,
51,231,219,190,150,2,129,39,223,122,126,245,147,172,109,118,118,124,146,111,241,89,200,185,72,253,222,98,252,152,136,84,140,27,17,152,50,37,145,42,70,48,23,209,88,232,137,72,195,8,167,61,28,52,193,249,
174,131,124,218,42,240,52,140,84,137,191,111,64,142,161,13,174,122,41,51,93,244,127,141,191,103,48,18,135,149,21,94,186,45,129,124,107,121,87,138,74,180,253,195,157,178,47,63,247,246,180,34,19,221,210,
99,119,209,224,172,163,13,254,235,202,200,65,216,29,144,8,115,190,235,103,201,92,120,194,173,169,200,55,52,160,95,95,126,182,180,2,249,72,53,101,253,208,101,19,168,71,26,80,141,132,60,198,36,227,222,157,
77,76,93,16,196,74,159,159,149,198,59,245,162,21,148,31,186,160,100,49,194,133,22,162,173,237,8,167,60,195,138,54,91,178,13,36,228,221,0,233,102,233,11,174,122,70,48,167,65,164,63,55,64,32,100,182,167,
204,165,59,45,157,50,0,176,17,0,208,28,218,106,24,4,150,142,58,137,27,203,157,85,146,73,217,180,27,210,160,43,147,132,203,203,238,28,175,63,20,170,149,205,63,104,31,220,20,76,205,222,161,169,225,21,35,
86,60,7,145,131,57,189,59,55,59,131,230,65,208,14,32,248,200,52,5,48,214,170,96,106,246,229,113,79,205,110,122,180,54,108,160,193,21,131,125,87,229,18,78,248,196,147,95,111,195,105,134,166,36,107,1,34,
50,118,8,148,163,37,132,244,192,212,174,165,60,40,74,222,77,11,70,244,113,7,70,238,213,202,3,166,186,172,218,159,215,146,244,114,36,129,69,212,199,134,193,7,104,106,8,150,121,65,89,225,248,34,139,154,
109,117,205,68,238,164,105,73,38,112,96,122,231,177,2,115,69,13,143,21,37,105,84,167,226,3,165,45,57,81,7,4,22,81,127,216,130,231,135,10,36,149,225,69,87,237,117,249,122,191,239,153,164,61,147,128,69,
99,136,103,51,234,183,191,186,31,216,65,154,120,136,3,129,36,241,38,152,1,8,147,13,72,0,23,99,158,150,6,0,159,139,166,9,196,147,184,118,106,27,106,209,139,32,40,46,20,97,43,183,22,78,152,110,151,185,133,
189,253,121,44,6,103,156,32,231,104,5,129,66,139,131,211,186,201,10,81,231,149,251,90,13,239,181,154,129,216,129,97,206,92,84,210,43,205,207,190,4,139,184,137,164,83,203,138,38,126,154,204,243,138,124,
251,71,9,208,39,7,4,201,188,194,113,26,59,222,154,75,97,4,206,198,235,110,51,210,48,182,168,193,103,116,138,129,179,160,122,156,128,11,129,125,246,136,183,127,200,93,196,128,203,184,35,9,140,174,74,18,
213,59,231,150,141,237,164,244,90,108,153,10,157,240,230,28,131,251,10,254,154,68,195,15,13,85,222,241,98,228,81,18,23,7,54,117,2,113,202,161,20,54,6,128,238,128,32,25,185,193,192,152,145,4,119,6,64,240,
16,24,231,203,50,215,39,3,201,227,129,123,81,242,61,65,7,67,46,13,102,65,186,181,231,121,154,130,27,155,178,81,96,68,218,217,10,4,135,166,116,205,193,202,142,36,49,78,247,220,74,172,18,39,177,155,59,21,
239,79,190,187,140,61,30,113,152,255,148,207,96,112,245,183,195,125,102,67,23,172,93,44,48,97,161,146,184,44,148,208,43,85,37,193,161,41,29,59,250,197,244,85,220,183,38,17,239,54,238,167,227,146,234,167,
118,42,174,76,170,187,140,135,45,92,255,91,129,177,87,160,59,28,18,235,219,244,126,251,222,49,63,37,130,94,86,247,17,184,183,218,187,7,90,80,59,201,47,220,46,184,164,9,80,137,148,252,42,186,227,39,108,
33,9,14,76,237,6,223,146,132,56,207,133,214,147,3,161,203,202,125,9,187,203,216,42,70,106,8,218,97,203,177,101,58,203,170,118,19,217,206,176,5,235,30,6,211,95,7,48,111,193,237,59,114,42,76,110,47,64,23,
194,21,151,108,185,222,11,21,147,30,4,178,10,36,10,9,191,199,152,19,94,148,216,144,100,83,141,134,21,172,61,25,35,255,24,82,83,194,65,218,192,119,138,38,238,74,36,3,155,237,139,143,95,32,81,246,110,99,
36,13,82,111,249,114,9,145,86,239,237,163,215,201,49,233,65,112,112,90,23,24,73,98,11,220,99,204,151,65,154,213,121,229,129,164,187,96,23,111,210,71,241,38,189,22,19,208,173,58,152,101,98,179,245,97,224,
111,134,1,60,2,146,248,33,108,247,222,96,182,61,94,223,6,32,232,230,193,60,90,42,130,106,49,78,25,121,255,73,245,4,226,19,234,119,3,8,237,5,137,141,124,231,206,9,91,146,97,2,195,10,74,46,134,218,187,145,
219,52,184,238,169,175,85,49,29,14,8,204,173,126,82,130,32,160,67,175,191,5,27,138,247,224,141,250,9,222,168,177,239,135,53,71,39,211,181,243,60,111,186,107,253,251,63,229,187,91,56,24,155,137,75,8,31,
48,221,104,176,1,7,4,230,40,153,180,32,224,76,85,231,219,255,37,63,120,146,152,48,109,91,209,248,85,230,72,17,223,218,67,11,214,207,22,5,182,52,30,231,28,14,8,204,173,93,210,130,128,79,123,104,65,201,
165,184,45,103,61,44,204,253,116,148,122,111,93,150,95,99,142,28,241,169,125,166,231,185,46,233,62,247,87,124,75,20,135,99,163,177,251,243,47,43,123,114,64,96,142,154,73,13,2,89,45,42,88,183,21,7,78,195,
160,103,23,98,187,145,135,100,182,186,7,113,17,143,97,80,215,0,0,175,0,0,214,92,230,166,154,165,3,2,115,75,158,244,32,8,165,172,97,84,87,47,185,78,120,255,174,75,190,55,71,18,107,107,39,98,75,55,101,65,
208,166,96,19,137,61,7,144,244,253,231,84,91,52,218,232,202,37,61,8,248,196,145,12,120,53,84,141,43,96,112,62,3,131,243,10,163,196,136,71,61,101,75,148,31,130,197,235,112,47,37,65,224,58,251,247,148,62,
161,144,132,54,109,137,213,30,161,250,117,11,200,255,238,139,70,214,208,22,32,56,243,246,23,122,42,105,90,124,126,26,162,247,176,201,8,225,180,212,25,86,176,254,247,130,192,94,224,91,162,85,110,161,23,
226,164,143,104,169,167,183,76,74,130,32,253,15,247,144,123,248,68,89,10,112,105,224,123,103,45,213,63,59,79,47,237,120,121,91,128,64,54,146,131,105,90,160,119,151,65,239,206,53,66,12,43,235,200,187,87,
254,253,252,52,187,23,28,69,175,131,251,247,163,86,182,175,110,43,37,65,192,85,33,161,211,177,228,123,227,73,114,255,226,42,98,135,190,51,166,18,49,246,52,78,47,191,142,215,226,196,106,23,1,225,240,104,
181,38,32,92,157,166,5,94,166,227,183,21,229,63,31,171,255,120,126,15,131,125,30,12,246,37,242,57,134,235,147,65,241,116,253,78,57,16,40,170,144,194,248,10,32,140,168,68,102,239,50,182,128,137,44,149,
68,195,230,175,187,82,16,133,98,126,161,71,134,187,107,255,82,207,40,159,5,99,212,221,4,223,18,77,243,187,113,162,77,89,126,18,70,188,91,56,254,223,186,27,209,81,33,229,64,160,168,66,138,10,20,249,187,
14,218,241,20,126,92,18,84,232,170,99,65,97,128,47,47,120,145,184,165,32,144,141,228,96,154,22,76,110,46,12,209,165,22,12,87,119,19,185,11,214,61,133,8,153,105,80,131,254,10,53,200,210,204,115,209,6,147,
82,32,16,7,12,167,244,201,127,38,177,83,207,70,180,144,14,125,79,245,171,111,38,233,243,119,244,44,154,229,76,168,165,115,44,154,7,229,184,191,148,229,253,55,164,105,97,135,107,93,233,189,173,242,207,
209,50,47,94,230,236,5,107,7,139,76,132,87,48,67,214,75,169,223,123,119,94,246,141,214,186,70,203,165,20,8,210,126,119,51,165,141,254,19,73,251,43,194,108,0,121,187,180,107,31,242,110,122,148,188,127,
251,179,30,90,90,206,132,90,58,143,39,8,120,255,112,84,123,1,142,106,191,199,150,233,35,216,50,157,161,101,76,86,149,65,92,64,25,212,160,161,0,193,82,72,162,185,86,181,219,92,59,41,5,130,140,27,159,37,
215,192,115,27,237,6,41,42,145,255,179,183,168,238,129,63,232,161,187,45,65,160,164,105,129,151,41,188,42,18,23,115,0,23,111,100,205,18,214,113,55,142,42,55,245,141,215,150,104,228,2,167,20,8,244,112,
183,198,178,182,4,65,64,26,132,210,180,252,3,94,166,23,104,164,135,225,98,167,120,74,210,59,248,233,11,52,128,45,81,118,13,182,105,159,48,220,152,206,138,14,8,116,18,44,162,184,109,65,160,78,211,146,136,
152,3,184,118,23,192,181,187,176,37,92,187,29,16,56,32,104,146,2,170,52,45,113,141,57,56,203,83,210,195,229,167,93,137,218,18,117,212,33,115,76,31,89,219,182,146,64,158,168,42,77,11,49,225,218,173,69,
227,185,55,167,229,15,182,68,159,198,150,232,100,108,137,190,136,45,209,75,44,239,32,70,131,142,36,48,71,113,123,131,128,219,6,161,52,45,241,137,57,224,91,162,46,18,203,97,7,120,19,181,37,234,72,2,115,
76,159,90,146,32,56,91,37,77,11,24,245,30,24,172,183,90,73,194,134,45,81,90,130,68,186,183,89,217,182,214,182,108,32,9,82,47,219,68,188,207,9,34,153,71,73,115,130,115,3,201,235,18,250,191,191,56,63,250,
181,143,90,185,46,88,14,167,211,147,240,227,179,45,29,217,150,244,32,72,197,188,67,137,6,1,231,89,37,77,11,244,246,117,208,219,39,234,228,247,70,197,229,45,81,31,85,32,142,161,103,75,199,56,39,61,8,56,
117,91,36,3,29,163,141,93,86,237,75,72,218,199,40,58,172,7,127,139,139,219,68,83,204,173,78,211,98,197,213,176,161,75,54,24,149,227,190,229,33,102,65,101,166,190,45,64,32,231,34,21,210,139,19,149,138,
17,111,195,141,46,86,63,165,37,114,145,98,174,125,24,185,239,102,162,56,145,73,210,6,23,249,102,97,28,21,102,152,64,107,93,37,77,11,202,155,186,26,150,111,137,186,3,82,32,131,36,26,186,245,206,252,119,
181,142,33,30,229,108,1,2,133,48,1,213,136,229,33,35,157,229,247,24,7,250,144,42,69,73,40,109,169,212,139,7,166,117,157,2,183,130,240,212,40,140,85,226,214,197,89,93,86,238,47,142,7,131,168,219,84,167,
105,33,137,77,218,122,231,132,53,70,250,132,49,252,44,206,4,38,233,85,173,14,77,237,50,18,170,83,78,28,178,142,115,201,202,31,229,211,200,180,26,215,225,89,204,5,86,222,105,213,129,205,122,27,116,174,
107,138,66,49,46,1,36,49,61,24,192,163,92,211,194,11,202,23,206,253,228,98,222,211,19,33,17,66,105,90,200,216,213,176,185,243,75,206,38,145,182,193,24,174,243,185,169,207,123,158,252,189,177,24,68,126,
185,9,252,122,86,0,32,25,31,198,202,69,70,200,98,174,61,165,191,3,2,213,66,7,152,63,141,235,255,191,3,195,119,9,94,81,167,42,17,200,204,15,32,236,131,58,248,156,40,121,87,196,27,12,74,154,22,236,22,205,
135,151,233,93,122,248,18,65,253,219,229,187,134,137,21,161,238,130,88,117,213,27,31,174,159,157,66,105,3,207,33,33,171,201,187,188,99,53,151,240,239,235,183,191,66,254,111,62,145,251,213,147,192,217,
1,1,8,198,237,28,48,63,18,13,11,83,154,93,57,229,158,162,176,66,172,24,96,224,182,66,92,238,79,80,210,180,232,189,26,54,119,193,250,201,0,241,211,144,2,223,35,217,87,63,45,201,190,14,78,237,10,208,8,57,
109,175,95,69,233,67,226,238,199,23,23,144,212,189,189,150,142,174,156,201,223,95,21,157,87,237,59,65,75,39,41,15,130,160,248,127,19,139,175,178,109,130,119,177,52,98,250,160,36,8,222,221,21,34,48,8,46,
50,54,78,143,8,214,178,56,74,25,85,154,150,39,241,70,191,58,86,221,176,24,102,137,38,111,187,51,255,47,177,234,28,154,210,37,79,18,197,55,185,4,232,224,121,51,86,241,86,253,125,149,103,148,44,17,180,94,
19,155,210,32,144,141,95,70,203,194,1,128,245,85,51,191,252,51,255,27,215,132,130,63,132,126,86,107,74,241,51,154,149,52,45,232,54,93,203,213,176,8,212,41,194,80,231,99,204,154,183,68,149,180,251,153,
23,207,161,204,49,9,137,175,137,27,144,170,215,20,80,237,191,158,112,64,16,139,194,209,37,0,248,60,179,29,101,93,86,68,172,190,134,170,159,9,247,90,224,223,101,94,50,159,132,244,76,226,132,102,53,17,55,
48,97,247,8,70,217,168,120,72,132,80,154,150,24,247,132,157,53,127,205,207,220,162,43,112,202,172,99,75,84,57,20,180,3,8,106,54,222,71,53,127,93,234,128,160,57,16,200,54,128,144,246,117,164,4,72,203,57,
159,218,78,127,32,100,12,74,7,246,144,239,155,143,200,191,231,99,18,187,252,12,134,226,112,124,246,146,155,102,213,85,116,228,169,27,201,91,254,106,120,87,178,106,84,143,91,117,172,181,17,212,42,14,188,
76,47,130,151,233,223,162,205,17,167,205,107,176,181,59,81,111,134,59,7,4,177,94,155,54,251,30,6,96,49,0,112,165,122,90,217,211,86,80,198,57,250,61,20,106,55,61,70,213,107,35,114,235,34,51,70,231,85,251,
155,55,178,13,208,84,73,211,210,84,202,116,37,112,159,111,137,234,205,117,234,128,192,192,130,36,107,149,240,51,128,192,44,184,4,104,119,3,220,236,13,62,63,61,120,101,35,137,32,74,245,39,196,99,251,84,
73,211,194,152,112,99,89,209,248,7,213,67,86,190,195,213,186,119,108,43,204,215,117,163,144,3,2,131,139,159,140,213,34,165,0,215,243,59,222,251,190,169,253,112,174,26,85,222,114,102,184,141,192,216,10,
72,3,126,17,182,165,79,195,219,62,252,106,216,161,243,75,174,16,69,90,13,69,237,59,58,34,244,215,178,37,170,30,152,3,2,75,151,169,117,55,134,197,174,192,8,123,43,163,52,170,6,69,206,50,180,63,173,124,
161,99,159,90,47,197,176,101,186,30,59,86,151,162,222,62,232,254,200,82,33,72,80,129,218,225,111,153,48,237,175,220,90,56,30,96,208,247,56,32,208,71,175,164,45,29,205,21,188,211,131,159,155,146,2,33,158,
135,52,56,116,195,128,48,218,232,57,181,212,67,212,97,158,53,125,4,191,43,148,151,181,225,134,121,38,225,230,249,11,225,41,26,97,173,55,223,58,223,42,6,136,230,97,3,248,36,177,231,137,148,121,193,141,
176,143,38,232,25,82,171,42,235,236,14,53,179,28,202,129,144,82,68,236,124,188,172,10,89,245,112,149,72,58,248,109,168,57,36,241,197,118,169,53,73,124,35,199,200,3,243,253,162,80,33,214,74,95,9,233,200,
34,199,189,68,241,224,88,163,134,249,233,231,219,238,206,15,248,15,196,120,154,114,141,79,27,242,91,106,119,125,113,147,181,223,47,255,144,174,153,57,155,78,59,249,36,90,113,79,17,117,236,208,129,30,120,
236,73,122,250,185,117,116,229,164,9,116,227,31,175,162,218,218,90,42,188,111,25,189,250,175,55,228,118,122,116,239,70,15,221,119,55,157,208,187,23,41,245,23,222,50,155,198,92,120,62,125,189,123,15,93,
63,247,54,186,227,246,121,116,102,206,233,205,214,141,53,39,7,4,205,80,72,21,32,35,151,50,107,16,71,118,213,96,32,51,240,164,236,99,244,0,49,255,26,252,230,119,11,130,159,9,34,254,121,253,18,62,211,235,
5,249,147,9,245,242,39,255,151,41,226,83,172,241,75,71,68,191,95,112,249,143,17,211,252,228,250,193,143,180,189,181,77,77,75,237,37,138,46,247,227,109,126,189,214,123,135,195,36,35,63,20,84,30,249,80,
144,168,195,162,215,201,213,235,180,168,93,43,76,172,48,118,167,142,29,104,230,188,2,250,232,211,255,134,64,192,65,241,195,190,253,180,96,238,44,106,211,166,141,204,248,11,239,186,71,6,194,143,135,42,
101,16,41,245,121,39,106,16,52,87,151,131,168,185,199,1,129,14,16,88,125,48,164,16,63,214,155,202,138,239,185,47,209,174,180,227,217,77,221,110,205,118,51,31,123,98,175,231,224,79,98,54,187,177,251,109,
93,143,243,254,224,125,236,135,194,111,96,47,248,209,151,31,128,68,194,105,242,135,126,103,248,29,127,135,220,232,129,173,226,190,97,39,228,124,112,193,19,243,172,137,119,80,155,209,127,108,18,4,15,252,
223,19,116,252,113,199,210,217,103,12,161,211,79,59,133,150,61,242,24,181,107,219,150,186,119,235,74,23,157,255,235,48,166,230,141,40,146,129,127,127,206,208,179,101,16,240,135,75,14,117,249,99,58,117,
108,182,46,151,50,14,8,12,114,81,226,36,1,231,35,196,132,225,62,5,124,236,99,2,115,97,200,46,48,163,11,186,183,11,204,216,240,187,64,248,153,225,111,248,100,2,202,4,127,151,255,46,255,158,213,212,116,
103,119,157,77,159,165,159,64,227,127,122,149,174,60,252,55,250,206,221,141,174,233,190,144,122,123,191,163,135,247,233,112,56,141,244,145,10,254,222,220,75,130,191,213,57,8,70,158,147,75,187,42,118,203,
106,17,151,2,109,179,179,41,59,59,75,102,234,69,119,221,75,139,111,191,69,86,127,148,135,191,225,249,195,65,192,165,194,229,249,151,210,210,7,31,161,57,55,92,71,207,148,60,47,171,67,28,4,205,213,117,64,
96,16,0,188,90,99,155,224,103,176,9,254,99,162,197,240,170,137,178,9,216,20,106,115,126,207,149,151,29,118,183,93,9,165,235,192,45,7,31,62,227,87,245,255,173,191,180,219,221,243,171,92,237,110,104,35,
213,190,246,210,183,115,102,136,76,114,213,167,51,23,255,20,88,26,254,73,46,31,99,0,22,254,49,183,11,26,216,153,146,224,90,33,191,249,249,195,213,32,213,207,237,231,190,72,238,147,206,105,86,18,220,120,
237,213,180,226,209,199,229,50,151,92,252,59,218,253,109,192,38,210,34,9,20,213,232,229,87,255,41,219,18,252,121,124,197,253,50,8,212,170,17,255,187,90,138,56,32,48,193,178,118,217,29,10,228,18,101,216,
29,18,142,229,129,243,238,250,244,231,253,25,117,119,113,123,128,147,71,146,164,220,109,119,78,44,139,69,170,128,11,121,122,57,202,5,182,140,85,18,129,111,26,116,240,188,209,228,206,153,34,9,22,223,54,
151,22,221,125,31,29,248,241,71,89,215,231,12,205,31,206,168,177,108,2,5,4,188,60,103,250,189,63,236,147,65,192,13,99,199,38,136,181,122,38,190,79,216,57,1,209,110,184,242,246,49,49,212,38,171,226,100,
152,251,105,44,198,63,57,254,24,191,15,194,207,31,202,124,76,52,27,73,125,53,231,188,231,47,6,24,13,203,131,23,145,200,125,186,7,228,82,54,156,8,155,50,138,121,25,5,4,124,103,104,245,218,245,244,254,246,
29,242,46,17,255,89,1,1,255,84,118,140,248,207,145,187,67,10,8,184,186,180,241,239,175,210,29,247,222,31,2,65,115,117,99,209,212,49,140,99,80,168,241,137,113,123,89,37,50,19,65,21,56,49,254,57,78,140,
15,55,244,30,167,19,99,238,86,157,230,242,127,201,109,5,117,38,10,68,160,61,14,70,190,26,32,40,6,8,166,198,98,148,200,239,101,123,137,177,69,220,141,58,217,93,169,29,16,196,88,253,168,190,67,49,246,196,
99,49,84,98,125,135,2,185,68,241,202,127,30,135,98,227,149,177,169,239,30,51,114,53,172,115,98,28,107,149,109,246,189,149,94,164,81,183,69,227,228,69,26,10,181,68,46,209,104,217,233,16,76,51,31,182,109,
145,145,171,97,29,16,216,140,201,99,77,167,145,65,24,172,192,79,73,219,194,165,90,81,141,120,60,129,255,155,143,17,83,128,120,130,206,60,158,32,55,60,158,0,177,172,222,237,255,136,236,110,55,60,72,115,
172,142,39,224,157,132,130,238,155,200,83,170,54,152,225,101,122,9,188,76,53,223,154,238,128,32,22,215,216,240,251,192,78,17,149,66,181,8,75,167,32,100,182,15,70,150,85,71,137,44,107,143,200,178,219,17,
89,150,21,140,44,83,217,0,50,141,88,149,40,81,94,60,34,203,134,205,47,153,32,136,180,22,111,249,31,14,187,133,254,77,93,175,164,202,57,170,235,106,88,7,4,54,100,114,45,83,10,36,216,162,229,145,64,8,63,
65,13,207,59,20,182,167,30,214,9,171,98,130,52,165,203,83,7,55,104,233,91,111,25,184,71,124,131,177,30,15,160,77,199,37,123,43,155,171,31,138,43,96,194,156,109,69,227,239,215,210,151,3,2,45,84,178,105,
153,232,18,161,193,47,51,16,101,175,60,77,100,155,192,118,40,60,70,199,198,67,2,4,212,160,245,139,4,129,97,247,70,91,224,188,145,171,97,29,16,216,148,193,181,78,43,24,115,188,60,50,228,178,81,253,104,
121,135,96,4,139,204,123,83,60,108,0,222,191,209,92,162,136,53,94,7,55,141,124,173,87,195,58,217,38,180,114,139,205,203,201,219,167,66,26,143,6,187,28,128,232,220,200,177,44,144,119,5,255,103,251,145,
170,229,57,48,255,242,120,132,80,170,201,28,10,156,215,153,166,93,239,213,176,13,121,135,78,149,79,138,147,249,169,242,252,66,222,208,112,242,14,153,88,197,176,179,132,136,188,67,0,192,17,151,228,29,20,
111,230,231,195,55,146,75,52,2,64,247,64,26,220,2,232,106,186,26,246,224,180,174,112,161,16,6,219,34,3,157,142,19,123,195,201,183,100,93,154,104,100,28,178,22,7,214,145,103,25,70,142,157,120,233,217,177,
48,18,53,43,53,118,127,192,80,55,37,34,43,181,12,130,96,46,81,35,129,243,188,190,222,171,97,195,115,145,158,74,105,112,158,51,115,146,30,139,198,86,127,95,255,1,207,69,250,177,220,172,158,168,62,221,32,
144,239,39,16,211,87,161,98,66,46,205,0,211,109,112,73,245,200,50,108,109,30,31,45,11,192,37,130,79,112,47,17,5,113,2,99,18,238,73,240,113,221,191,66,75,93,179,101,112,203,228,52,188,149,159,226,185,68,
113,227,124,31,108,137,214,27,105,19,234,212,181,144,6,143,130,142,159,148,185,62,25,132,91,50,129,169,166,159,224,70,65,49,151,8,70,250,107,249,58,108,7,182,169,113,159,69,28,179,82,183,200,77,53,0,66,
151,149,251,198,181,4,129,91,226,186,38,28,122,181,197,245,74,95,193,252,232,106,230,110,2,153,94,170,171,97,161,217,93,135,235,159,30,213,66,199,128,141,64,72,207,110,249,253,19,74,42,24,238,0,104,225,
195,239,179,160,114,35,225,172,186,36,129,115,103,217,62,143,133,171,214,100,83,120,123,43,186,252,54,56,195,13,51,219,231,208,133,37,163,145,30,242,159,48,244,15,137,245,109,122,191,125,239,152,136,252,
145,102,123,208,94,63,233,111,170,81,182,209,180,79,217,202,146,210,172,206,43,15,224,96,43,177,79,162,37,1,207,37,138,104,151,93,240,8,69,128,177,148,243,110,225,196,29,86,204,24,126,69,255,128,95,209,
249,18,163,251,182,21,229,223,98,69,155,70,218,176,1,8,224,110,27,184,196,174,37,30,219,95,230,205,137,10,102,221,8,102,189,24,238,17,171,112,143,49,236,2,107,158,225,5,107,251,193,245,250,51,171,175,
134,213,59,58,7,4,122,41,22,94,222,246,32,56,123,193,250,243,16,104,188,133,7,209,123,93,190,222,239,123,38,29,48,71,178,240,218,202,213,176,145,110,216,86,246,17,171,45,7,4,177,40,212,252,247,246,6,65,
192,128,221,9,35,237,20,164,104,153,87,86,56,254,94,115,228,106,92,219,234,171,97,141,140,207,1,129,17,170,53,212,177,53,8,224,244,198,227,131,121,130,221,61,25,174,174,253,74,61,163,124,230,200,21,189,
182,85,87,195,26,29,155,3,2,163,148,11,212,179,45,8,248,27,58,211,87,143,45,81,161,147,36,8,99,183,221,49,126,163,57,82,53,93,59,236,106,88,131,121,75,205,140,205,1,129,25,234,217,24,4,72,169,248,16,0,
48,3,91,152,91,182,22,77,24,105,142,76,177,107,195,54,200,199,1,26,114,156,24,187,26,54,118,15,77,151,72,57,16,180,41,216,68,98,207,240,36,181,156,60,190,119,214,82,253,179,243,244,210,210,150,146,96,
88,193,218,147,5,18,119,114,98,48,146,6,149,21,77,252,84,47,97,140,148,111,136,82,19,60,136,64,179,248,224,202,1,65,136,2,28,4,66,167,99,169,126,221,2,242,191,27,136,244,139,246,55,141,139,104,75,16,64,
10,108,134,20,24,161,53,127,168,70,90,197,44,166,196,43,27,185,213,38,102,227,205,20,72,73,73,16,9,130,140,27,159,37,87,191,179,201,187,233,81,242,254,77,115,122,28,91,218,4,67,23,174,31,131,171,95,55,
240,147,220,26,119,122,223,114,207,184,184,220,133,220,20,79,42,201,124,33,131,86,35,90,45,236,250,42,51,140,222,92,221,148,7,129,56,96,56,165,79,254,179,124,67,164,90,58,104,34,56,130,87,240,198,12,229,
228,215,84,199,130,66,56,180,202,195,233,109,30,154,178,84,18,201,6,170,127,255,46,180,203,19,117,222,128,36,90,15,89,48,92,93,77,40,87,195,242,180,238,70,210,180,232,234,44,88,56,37,65,96,149,77,0,102,
220,172,206,146,102,100,1,76,214,177,20,4,208,201,231,97,62,75,180,122,119,154,28,123,147,213,149,59,143,141,164,105,49,50,166,148,4,65,84,117,104,224,185,228,255,236,45,170,123,224,15,218,233,24,144,
4,21,218,43,88,91,18,23,110,148,26,241,80,140,54,10,117,162,44,228,76,31,241,110,225,248,127,91,59,90,237,173,169,175,134,197,53,55,151,110,187,99,194,11,218,107,235,47,233,128,0,52,75,251,221,205,148,
54,250,79,228,223,245,174,62,16,88,172,142,232,95,62,235,106,64,10,172,132,20,224,169,18,55,66,13,74,72,92,70,115,163,199,1,218,85,8,26,125,2,70,178,174,52,45,70,40,226,128,0,84,147,13,99,72,2,3,219,164,
150,170,35,70,22,111,145,97,255,0,0,14,117,73,68,65,84,208,138,58,103,47,88,59,216,69,98,57,212,15,175,159,73,253,222,187,243,178,111,172,104,215,108,27,48,146,63,230,46,27,48,146,231,194,72,94,106,182,
189,166,234,167,36,8,162,217,4,186,85,161,0,69,109,1,2,48,91,25,152,109,40,188,57,239,45,43,156,160,251,176,36,94,204,57,124,254,186,17,184,7,115,51,198,117,184,214,149,222,59,94,59,85,41,7,2,139,23,44,
233,65,160,202,14,183,159,142,82,111,189,119,13,91,76,207,70,205,33,166,249,101,236,20,253,14,17,104,143,34,2,237,186,120,244,231,128,192,28,85,147,26,4,114,158,80,31,85,128,201,122,242,139,53,144,25,
110,149,57,114,88,95,91,137,57,224,45,11,36,13,124,167,104,34,223,194,181,244,113,64,96,142,156,73,13,130,161,11,74,22,35,123,198,66,173,89,228,204,145,202,120,109,24,237,15,192,104,191,1,227,252,39,82,
191,255,198,120,75,209,107,58,32,48,71,209,164,5,129,209,44,114,230,200,101,172,182,58,230,0,64,248,173,222,139,193,99,245,234,128,32,22,133,154,255,62,105,65,160,164,68,132,123,196,26,120,137,78,50,71,
134,248,215,134,241,126,51,140,247,251,113,144,247,37,210,180,12,140,149,166,69,207,136,28,16,232,161,86,227,178,73,9,2,179,89,228,204,145,204,88,109,117,204,129,68,194,140,109,133,227,31,49,214,82,227,
90,54,0,65,23,228,233,20,151,89,69,16,125,237,180,76,182,9,125,99,108,92,90,201,34,135,111,22,225,96,236,14,179,237,37,170,126,238,194,146,113,80,135,94,180,58,77,75,210,131,32,21,243,14,153,97,58,213,
73,172,169,44,114,102,198,96,166,174,18,115,128,3,180,165,56,64,155,107,166,45,165,110,210,131,128,79,164,69,50,208,49,218,216,101,213,190,22,119,47,208,195,4,234,44,114,76,162,137,101,119,230,7,110,171,
78,162,39,214,29,105,70,166,98,11,16,200,185,72,133,244,98,228,198,25,99,132,8,122,235,224,224,6,57,64,235,145,91,50,241,185,72,245,142,85,93,30,111,209,165,216,106,156,13,227,210,146,44,114,102,198,98,
166,46,114,162,202,183,101,98,29,94,196,1,218,37,74,91,48,158,249,45,63,99,245,250,62,217,2,4,10,17,2,170,17,203,139,67,174,202,96,23,60,183,164,0,207,77,237,137,85,205,44,182,149,117,249,161,19,12,74,
132,73,10,110,73,144,134,88,149,69,206,202,49,106,109,75,29,115,192,239,77,134,141,144,73,130,132,132,204,66,31,0,124,51,210,68,130,7,180,63,182,2,129,246,105,167,94,73,149,251,193,83,120,123,94,149,236,
20,128,84,243,224,8,121,17,12,229,35,144,110,109,149,249,56,32,72,246,149,141,211,248,193,48,191,2,163,108,2,195,252,84,239,246,245,181,58,139,92,156,134,221,100,179,252,240,44,195,231,125,64,20,232,10,
94,136,223,89,194,83,2,96,142,252,222,30,71,18,36,122,65,90,125,127,170,52,232,241,118,73,78,4,45,184,4,0,179,207,68,95,29,67,0,224,121,204,193,253,192,128,3,130,68,44,66,178,245,49,180,160,100,38,222,
152,203,249,73,107,27,87,215,147,227,149,69,46,17,116,129,225,91,10,62,151,115,32,201,47,127,254,246,15,187,201,51,48,10,24,198,186,210,251,59,54,65,34,86,175,133,250,8,100,145,243,238,1,159,180,35,38,
92,180,181,104,252,223,90,104,40,150,116,27,156,15,183,5,184,36,8,168,65,184,173,48,18,8,14,8,44,33,183,61,26,65,192,250,35,80,17,254,4,94,217,132,29,147,95,219,99,86,242,29,202,121,208,254,139,193,253,
189,1,4,25,10,92,21,82,30,7,4,118,89,105,147,243,224,89,228,176,85,204,195,19,165,120,249,225,155,28,162,169,234,209,164,130,2,4,61,32,144,175,128,18,132,55,185,65,33,50,41,175,211,170,3,155,77,13,204,
162,202,186,244,57,139,250,180,93,51,13,89,228,216,3,8,153,148,213,7,59,62,152,231,88,40,68,252,160,180,131,30,73,16,188,44,157,51,63,238,64,107,120,16,103,93,234,98,222,113,45,125,16,234,128,192,36,183,
170,29,205,170,220,66,47,220,50,121,196,100,147,173,186,186,44,21,252,222,98,12,82,246,24,96,76,24,133,92,166,165,205,13,250,224,212,174,80,167,132,64,134,187,192,30,43,15,93,11,252,143,177,21,157,87,
237,231,23,168,183,216,99,24,4,220,175,68,20,105,36,12,37,121,251,204,202,7,170,103,165,36,209,230,247,238,202,199,229,210,173,247,81,103,145,179,218,229,184,165,103,93,83,83,51,18,202,127,14,222,214,
81,215,247,217,183,63,63,105,245,91,95,140,189,126,244,160,181,23,157,209,171,162,185,241,214,204,29,116,19,171,62,220,145,155,20,13,134,181,108,94,16,117,232,182,55,235,174,247,254,207,236,124,49,214,
74,140,181,60,51,51,83,183,138,165,27,4,193,92,250,171,128,236,248,59,180,33,79,39,114,116,78,141,87,230,131,104,132,151,13,65,65,26,131,55,92,14,118,67,250,112,247,128,192,27,140,202,177,108,149,130,
192,202,125,126,225,105,14,208,220,130,245,183,161,204,93,45,157,69,206,44,3,169,235,215,215,215,231,248,124,190,85,28,0,177,218,253,169,214,75,71,235,188,212,163,67,86,179,69,171,103,244,110,252,61,151,
8,65,195,34,235,225,221,177,186,210,252,61,7,130,219,237,158,154,158,158,174,249,5,170,27,4,200,152,176,1,35,74,136,243,92,128,249,216,6,68,99,197,253,14,99,238,16,134,206,22,133,152,62,6,217,241,86,219,
35,48,161,59,207,227,217,210,89,228,52,115,72,140,130,28,0,126,191,127,59,47,246,197,174,175,104,251,135,59,233,200,209,106,211,205,95,244,193,18,202,174,171,196,123,164,177,36,56,148,221,131,94,59,221,
26,109,232,188,220,161,116,98,191,190,242,120,93,46,215,16,173,64,208,5,130,80,58,111,211,100,209,215,64,60,147,197,202,115,18,9,146,141,95,92,173,255,193,149,168,85,130,219,159,83,230,185,172,66,127,
237,214,85,163,186,186,122,59,151,0,183,221,113,23,109,121,123,171,101,131,155,219,109,15,253,186,125,32,225,118,0,8,242,15,178,36,120,177,178,51,61,122,224,56,203,250,186,224,215,191,162,249,179,229,
189,137,10,168,70,39,104,105,88,23,8,114,23,172,7,100,89,11,68,150,9,179,182,22,142,183,252,14,227,128,234,195,94,2,161,140,217,53,88,72,6,10,226,63,232,163,194,184,88,6,162,150,5,105,169,50,176,1,242,
208,247,155,92,2,76,185,206,218,13,174,108,209,71,247,31,183,139,250,101,212,133,77,111,71,117,54,45,218,219,155,142,74,110,75,167,93,252,200,10,89,34,0,4,154,248,91,83,33,101,132,65,95,146,132,223,99,
12,61,111,49,238,244,245,88,73,169,32,0,222,140,214,230,57,3,122,80,191,110,237,41,167,119,23,234,215,189,189,92,100,215,15,135,169,124,247,1,218,181,239,48,189,253,249,222,168,67,209,178,83,98,229,28,
172,108,171,182,182,246,38,208,121,217,202,103,214,208,83,127,121,206,202,166,67,109,13,110,115,4,64,168,161,182,46,137,56,0,118,212,134,28,82,45,237,111,230,181,87,81,254,184,49,14,8,154,163,106,80,173,
227,0,8,147,0,156,225,111,185,48,135,78,236,17,218,6,143,218,204,23,123,171,232,222,191,151,203,192,136,120,42,153,203,63,36,25,85,35,72,2,254,146,89,20,79,16,88,202,233,205,52,54,253,138,73,52,237,242,
203,28,16,52,71,112,164,64,41,135,1,60,88,93,102,242,185,3,104,202,136,129,186,214,169,120,203,103,180,250,173,207,195,235,96,23,9,185,122,134,232,106,168,21,20,118,64,160,113,17,236,160,14,5,195,2,195,
82,32,26,1,128,66,178,135,55,125,76,47,188,247,85,24,5,97,42,76,133,255,80,177,70,178,182,138,98,14,8,52,46,131,29,64,128,168,47,158,15,52,180,113,205,85,160,39,166,203,30,195,134,159,171,159,218,28,166,
26,97,7,164,2,238,19,154,118,38,12,119,106,113,69,7,4,26,9,154,236,32,136,102,12,63,54,109,68,76,27,32,22,121,184,141,240,199,149,91,194,138,197,115,91,55,214,120,212,223,15,243,172,233,163,197,70,113,
64,160,145,170,122,65,48,21,58,246,196,220,254,148,230,66,42,90,213,179,255,112,13,45,121,185,156,182,99,183,69,203,99,197,238,144,156,99,211,231,229,7,125,161,215,254,208,254,221,104,201,132,161,90,134,
16,179,204,130,231,223,11,223,53,98,180,2,182,129,53,167,64,49,123,111,186,0,36,223,114,38,176,49,196,196,169,205,109,225,58,32,208,72,100,163,32,216,249,205,143,52,231,185,192,225,139,2,12,245,223,98,
117,111,22,4,65,0,108,193,217,204,32,117,95,29,179,50,232,233,107,71,81,187,54,105,177,134,16,243,251,72,35,217,72,252,109,204,78,12,20,8,139,16,99,84,138,83,13,108,55,55,118,120,115,64,160,145,184,86,
128,96,244,105,199,211,204,223,12,162,125,144,6,211,158,192,154,104,120,204,130,128,191,13,121,132,84,48,38,36,216,99,224,8,255,146,179,250,210,140,209,167,106,24,69,243,69,202,119,31,164,155,159,125,
167,161,80,43,217,37,82,131,64,25,28,220,118,74,201,237,159,170,86,147,244,130,224,214,89,55,208,69,231,135,199,14,29,173,174,166,251,31,10,248,194,205,190,254,90,122,99,203,91,180,100,217,131,244,155,
95,142,146,127,207,206,10,248,24,41,229,94,123,253,77,90,177,164,136,78,30,120,162,92,143,255,206,219,61,31,229,95,223,252,22,157,49,120,16,117,235,218,37,140,240,251,246,31,160,162,165,203,232,253,242,
15,155,92,144,86,181,69,26,237,173,63,231,130,193,116,65,78,47,250,160,226,64,72,58,196,226,64,128,224,21,156,234,241,251,126,13,61,88,244,129,130,40,164,169,124,182,100,143,94,238,191,213,189,67,38,173,
153,241,43,67,237,170,43,113,103,178,49,127,126,53,4,176,64,56,162,128,211,104,86,199,111,141,135,59,66,29,230,129,79,194,167,80,135,239,106,5,252,14,85,165,78,96,98,224,83,226,191,139,117,200,231,84,
39,226,103,9,63,187,240,233,23,165,58,151,11,215,30,251,164,186,52,183,191,206,91,151,81,119,36,195,87,167,197,109,59,4,2,57,44,44,112,54,170,4,196,96,136,197,228,242,47,230,96,48,2,2,206,172,207,148,
188,64,79,174,126,150,206,204,57,157,10,230,204,162,61,223,254,143,94,217,244,122,8,4,219,63,252,72,254,249,211,207,190,160,153,183,22,200,253,63,243,248,195,50,32,56,51,79,158,152,31,21,4,74,187,74,121,
254,121,249,53,51,52,173,83,171,4,129,121,155,128,74,177,112,121,154,40,208,76,33,181,3,151,250,231,55,110,191,200,108,211,20,14,2,211,205,233,108,128,213,114,96,5,0,6,208,17,0,6,240,49,0,15,32,60,17,
18,175,189,2,250,96,198,148,16,16,2,29,177,229,207,205,24,93,215,163,67,230,60,173,135,101,202,27,91,97,86,229,109,207,153,93,13,130,158,221,187,135,49,121,228,196,154,146,4,182,3,129,90,255,87,212,33,
78,140,21,175,237,164,77,31,125,27,115,193,37,137,45,149,68,87,113,204,130,77,20,112,17,207,152,70,103,169,191,86,152,226,244,94,157,105,249,229,195,141,54,29,170,23,174,14,241,156,60,210,215,60,13,35,
174,102,202,16,36,41,3,151,226,101,192,235,52,3,223,180,1,115,102,32,18,51,3,140,155,1,223,37,252,157,50,248,223,32,25,50,240,182,198,223,240,59,126,70,125,124,82,6,220,181,81,47,240,51,47,143,50,109,
32,202,248,247,217,177,6,30,244,218,15,73,62,165,188,90,42,242,191,181,205,112,87,61,126,213,200,14,175,188,188,81,147,219,68,52,117,232,235,221,123,228,183,181,2,8,174,14,113,16,244,58,254,56,249,173,
223,165,115,231,144,90,228,245,122,101,41,50,232,148,147,233,231,67,194,206,45,73,249,142,75,24,219,72,130,72,35,120,229,213,121,212,173,125,166,102,16,152,182,9,84,142,127,193,184,166,80,242,144,235,
126,117,42,93,122,118,192,253,214,204,211,146,134,241,153,158,151,179,50,107,15,103,212,181,73,203,72,243,186,50,124,105,222,12,151,95,204,240,75,98,134,40,74,143,227,5,48,36,160,158,241,151,62,255,84,
185,52,227,238,98,56,1,122,160,18,158,100,84,18,116,233,124,140,108,31,252,103,251,14,89,229,137,4,129,90,231,231,52,86,75,17,14,130,104,54,65,74,72,2,30,140,161,117,155,212,44,8,56,225,229,84,130,36,
220,134,183,108,186,172,0,128,25,122,117,110,43,239,14,89,241,180,214,45,210,48,155,0,147,15,121,76,6,153,95,57,217,54,107,19,112,181,102,240,105,167,200,111,247,111,254,247,93,76,155,224,248,99,123,134,
36,65,74,128,32,210,38,168,174,243,105,150,2,1,134,181,198,139,148,31,150,225,45,40,123,142,42,204,96,251,195,50,85,18,45,153,150,72,157,8,255,111,79,228,54,169,89,16,40,111,255,163,8,194,121,237,141,
55,233,247,23,93,216,228,238,16,31,135,34,53,108,111,19,88,241,134,181,18,4,188,173,72,183,137,254,221,59,208,227,211,71,152,26,106,164,219,4,56,109,55,14,202,250,152,106,212,162,202,138,36,104,138,249,
149,110,244,130,192,162,225,197,165,153,86,181,59,100,213,12,173,146,4,178,90,20,200,171,159,50,14,116,178,26,232,150,138,99,185,78,56,32,208,200,173,122,15,203,52,54,27,179,152,149,32,8,0,161,177,43,
245,149,231,13,164,43,207,27,16,115,44,234,2,209,61,72,217,14,56,207,25,10,213,212,213,185,197,133,29,16,104,36,168,109,64,0,167,50,242,185,202,213,73,164,56,9,184,106,52,247,194,193,49,29,234,184,195,
220,125,127,223,65,95,254,80,21,70,57,24,219,85,56,137,77,202,120,99,7,4,41,6,2,89,26,4,226,139,163,134,87,158,203,195,43,1,136,156,222,157,169,47,194,44,249,243,21,194,42,249,89,192,46,48,254,91,77,132,
87,182,22,207,81,141,203,25,86,204,1,129,70,170,217,69,18,40,211,149,119,139,136,109,136,148,8,26,201,17,42,38,75,0,18,198,38,121,160,189,7,19,114,194,43,99,45,190,221,178,77,240,249,242,120,99,151,139,
21,71,134,91,198,162,133,242,61,220,47,118,144,75,26,27,203,240,212,218,94,75,149,115,36,129,70,202,219,49,239,80,72,42,240,93,35,70,60,31,127,148,116,105,81,8,20,113,216,164,145,132,173,182,88,34,178,
77,36,106,242,113,205,54,193,39,145,240,12,116,68,27,245,94,19,106,134,216,193,100,92,83,224,74,128,29,30,214,81,145,16,242,27,159,132,74,0,165,220,39,81,113,107,207,147,170,151,6,74,222,161,207,145,119,
104,170,197,121,135,244,142,197,108,249,85,200,59,52,32,94,121,135,248,224,34,179,18,155,29,112,140,250,27,107,92,105,83,18,153,139,52,206,243,105,213,205,35,3,29,118,204,132,193,86,103,160,75,228,164,
85,25,232,118,35,249,86,31,45,125,235,74,190,165,110,48,160,26,9,121,140,73,198,178,183,53,51,58,65,16,43,125,126,86,106,183,183,173,150,5,105,201,50,234,92,164,92,34,108,223,193,115,145,30,109,201,33,
233,234,251,188,225,195,100,9,192,159,184,229,34,213,53,34,167,112,82,82,32,8,4,30,139,173,205,54,106,125,179,220,13,0,140,213,154,140,151,15,223,176,36,104,125,115,119,70,228,80,192,24,5,28,16,24,163,
155,83,203,70,20,112,64,96,163,197,116,166,98,140,2,14,8,140,209,205,169,101,35,10,56,32,176,209,98,58,83,49,70,1,7,4,198,232,230,212,178,17,5,28,16,216,104,49,157,169,24,163,128,3,2,99,116,115,106,217,
136,2,14,8,108,180,152,206,84,140,81,192,1,129,49,186,57,181,108,68,129,255,7,201,151,30,87,6,58,125,0,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TabWaveforms::basszero_vstiwaveform_png2 = (const char*) resource_TabWaveforms_basszero_vstiwaveform_png2;
const int TabWaveforms::basszero_vstiwaveform_png2Size = 11962;


//[EndFile] You can add extra defines here...
//[/EndFile]

