/*
  ==============================================================================

    dataBindingEntry.h
    Created: 24 Oct 2019 11:48:49am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/GUI/Components/imbSynthParameterEditor.h"
#include "../Source/GUI/Components/imbSynthGUIComponent.h"

class dataBindingEntry:public MouseListener {


protected: 

	void attachControlBase(Component * _component);



public:

	void mouseDown(const MouseEvent& event) override;
	void mouseEnter(const MouseEvent& event) override;

	std::function<void(std::string idPath)> onGUIFocus = nullptr;
	std::function<void(float newValue)> onFloatValueChange = nullptr;
	std::function<void(std::string newValue)> onStringValueChange = nullptr;

	std::function<PopupMenu(std::string idPath)> onShowContextMenu = nullptr;

	std::string parameterIDPath;

	guiAttachedComponentType componentType = guiAttachedComponentType::unassigned;

	std::shared_ptr<Slider> pSlider;
	std::shared_ptr<ComboBox> pComboBox;
	std::shared_ptr<ToggleButton> pToggleButton;
	std::shared_ptr<TextEditor> pTextEditor;
	std::shared_ptr<Label> pLabel;
	std::shared_ptr<imbSynthParameterEditor> pParameterEditor;
	std::shared_ptr<imbSynthGUIComponent> pImbComponent;
	std::shared_ptr<Component> pComponent;

	juce::Rectangle<int> getBounds();

	void attachControl(Slider* _slider);
	void attachControl(ComboBox* _comboBox);
	void attachControl(ToggleButton* _button);
	void attachControl(TextEditor* _textEditor);
	void attachControl(Label* _textLabel);
	void attachControl(imbSynthParameterEditor* _editor);


};