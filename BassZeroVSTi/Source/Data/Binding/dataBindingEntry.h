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

//#include "../Source/Application/Settings/ViewSettings.h"

#include "../Source/Application/SynthApplicationEnvironment.h"
#include "dataContextMenu.h"

//#include "../Source/GUI/Components/imbSynthGUIComponent.h"


class dataBindingEntry:public MouseListener {


protected: 

	void attachControlBase(Component * _component);



public:

	void mouseDown(const MouseEvent& event) override;
	void mouseEnter(const MouseEvent& event) override;

	std::function<void(std::string idPath)> onGUIFocus = nullptr;
	std::function<bool(float newValue, std::string idPath)> onFloatValueChange = nullptr;
	std::function<bool(std::string newValue, std::string idPath)> onStringValueChange = nullptr;

	std::function<dataContextMenu(std::string idPath)> onShowContextMenu = nullptr;

	std::string parameterIDPath;

	guiAttachedComponentType componentType = guiAttachedComponentType::unassigned;

	std::shared_ptr<Slider> pSlider;
	std::shared_ptr<ComboBox> pComboBox;
	std::shared_ptr<ToggleButton> pToggleButton;
	std::shared_ptr<TextEditor> pTextEditor;
	std::shared_ptr<Label> pLabel;
	std::shared_ptr<imbSynthParameterEditor> pParameterEditor;
	//std::shared_ptr<imbSynthGUIComponent> pImbComponent;
	std::shared_ptr<Component> pComponent;

	juce::Rectangle<int> getBounds();
	
	void attachControlAsParent(Component * _component);
	void attachControl(Slider* _slider);
	void attachControl(ComboBox* _comboBox);
	void attachControl(ToggleButton* _button);
	void attachControl(TextEditor* _textEditor);
	void attachControl(Label* _textLabel);
	void attachControl(imbSynthParameterEditor* _editor);


	void updateGUI(SynthApplicationEnvironment & environment);
	void updateGUIView(ViewSettings & viewSettings);

	
	

	dataBindingEntry(std::string _parameterIDPath)
	{
		parameterIDPath = _parameterIDPath;
	}

};