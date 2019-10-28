/*
  ==============================================================================

    dataLayoutBlockComponent.h
    Created: 27 Oct 2019 5:14:45pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
//==============================================================================
#include "../../../JuceLibraryCode/JuceHeader.h"
struct dataLayoutBlockComponent : public juce::Component
{
    dataLayoutBlockComponent (juce::Colour col, FlexItem& item)
        : flexItem (item), colour (col)
    {
        int x = 70;
        int y = 3;

        setupTextEditor (flexOrderEditor, { x, y, 20, 18 }, "0", [this] { flexItem.order = (int) flexOrderEditor.getText().getFloatValue(); });
        addLabel ("order", flexOrderEditor);
        y += 20;

        setupTextEditor (flexGrowEditor, { x, y, 20, 18 }, "0", [this] { flexItem.flexGrow = flexGrowEditor.getText().getFloatValue(); });
        addLabel ("flex-grow", flexGrowEditor);
        y += 20;

        setupTextEditor (flexShrinkEditor, { x, y, 20, 18 }, "1", [this] { flexItem.flexShrink = flexShrinkEditor.getText().getFloatValue(); });
        addLabel ("flex-shrink", flexShrinkEditor);
        y += 20;

        setupTextEditor (flexBasisEditor, { x, y, 33, 18 }, "100", [this] { flexItem.flexBasis = flexBasisEditor.getText().getFloatValue(); });
        addLabel ("flex-basis", flexBasisEditor);
        y += 20;

        alignSelfCombo.addItem ("auto",       1);
        alignSelfCombo.addItem ("flex-start", 2);
        alignSelfCombo.addItem ("flex-end",   3);
        alignSelfCombo.addItem ("center",     4);
        alignSelfCombo.addItem ("stretch",    5);

        alignSelfCombo.setBounds (x, y, 90, 18);
        alignSelfCombo.onChange = [this] { updateAssignSelf(); };
        alignSelfCombo.setSelectedId (5);
        alignSelfCombo.setColour (ComboBox::outlineColourId, Colours::transparentBlack);
        addAndMakeVisible (alignSelfCombo);
        addLabel ("align-self", alignSelfCombo);
    }

    void setupTextEditor (TextEditor& te, Rectangle<int> b, StringRef initialText, std::function<void()> updateFn)
    {
        te.setBounds (b);
        te.setText (initialText);

        te.onTextChange = [this, updateFn]
        {
            updateFn();
            refreshLayout();
        };

        addAndMakeVisible (te);
    }

    void addLabel (const String& name, Component& target)
    {
        auto label = new Label (name, name);
        label->attachToComponent (&target, true);
        labels.add (label);
        addAndMakeVisible (label);
    }

    void updateAssignSelf()
    {
        switch (alignSelfCombo.getSelectedId())
        {
            case 1:  flexItem.alignSelf = FlexItem::AlignSelf::autoAlign; break;
            case 2:  flexItem.alignSelf = FlexItem::AlignSelf::flexStart; break;
            case 3:  flexItem.alignSelf = FlexItem::AlignSelf::flexEnd;   break;
            case 4:  flexItem.alignSelf = FlexItem::AlignSelf::center;    break;
            case 5:  flexItem.alignSelf = FlexItem::AlignSelf::stretch;   break;
        }

        refreshLayout();
    }

    void refreshLayout()
    {
        if (auto parent = getParentComponent())
            parent->resized();
    }

    void paint (Graphics& g) override
    {
        auto r = getLocalBounds();

        g.setColour (colour);
        g.fillRect (r);

        g.setColour (Colours::black);
        g.drawFittedText ("w: " + String (r.getWidth()) + newLine + "h: " + String (r.getHeight()),
                          r.reduced (4), Justification::bottomRight, 2);
    }

    void lookAndFeelChanged() override
    {
        flexOrderEditor .applyFontToAllText (flexOrderEditor .getFont());
        flexGrowEditor  .applyFontToAllText (flexGrowEditor  .getFont());
        flexShrinkEditor.applyFontToAllText (flexShrinkEditor.getFont());
        flexBasisEditor .applyFontToAllText (flexBasisEditor .getFont());
    }

    FlexItem& flexItem;

    TextEditor flexOrderEditor, flexGrowEditor, flexShrinkEditor, flexBasisEditor;
    ComboBox alignSelfCombo;

    juce::Colour colour;
    OwnedArray<Label> labels;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DemoFlexPanel)

};
