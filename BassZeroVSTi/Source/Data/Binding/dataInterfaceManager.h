/*
  ==============================================================================

    dataInterfaceManager.h
    Created: 24 Oct 2019 4:05:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Binding/dataBindingCollection.h"
#include "../Source/GUI/Components/imbSynthParameterEditor.h"
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
//#include "../Source/Data/Structures/imbEnumerationList.h"
#include "../Source/Utility/imbSynthTools.h"
#include "dataContextMenu.h"

#include "../Source/Data/Model/dataObject.h"

#include "../Source/Data/Structures/imbValueSet.h"
#include "dataBindingEntry.h";



/* manages current focus (selection) in data tree; copy/clipboard data, etc */
class dataInterfaceManager {

    public:

		imbValueSet clipboard;
		dataBindingCollection bindings;

		dataObject model;
	
		std::unique_ptr<CommandBufferDisplayModel> bufferDisplayModel;

		//std::shared_ptr<ControlStateDisplay> controlStateDisplay{ nullptr };

		std::unique_ptr<ControlStateDisplayModel> controlDisplayModel;


		//std::shared_ptr<SynthStateDisplay> synthStateDisplay{ nullptr };
		std::unique_ptr<SynthStateDisplayModel> stateDisplayModel;


		dataContextMenu showContextMenu(std::string pathID);
		void setGuiFocus(std::string pathID);
		void setFloatValueChange(float newValue, std::string pathID);
		void setStringValueChange(std::string newValue, std::string pathID);

	/* Calls updateState to all elements selected with parameterIDPath */
		void updateState(SynthApplicationEnvironment & environment, std::string parameterIDPath = "");
	
		void updateGUI(SynthApplicationEnvironment & environment, std::string parameterIDPath = "");
		void updateGUIView(ViewSettings & viewSettings, std::string parameterIDPath = "");

		void detachAll();

		void attachAutomatically(dataElementBase * element, Component * component);
	
		void attachAsParent(dataElementBase * element, Component * component);
		dataBindingEntry attachControlBase(dataElementBase * element, Component * _component);
	
		void attachControl(dataElementBase * element, Slider* _slider);
		void attachControl(dataElementBase * element, ComboBox* _comboBox);
		void attachControl(dataElementBase * element, ToggleButton* _button);
		void attachControl(dataElementBase * element, TextEditor* _textEditor);
		void attachControl(dataElementBase * element, Label* _textLabel);
		void attachControl(dataElementBase * element, imbSynthParameterEditor* _editor);
		void attachControl(dataElementBase * element, imbSynthGUIComponent* _editor);
	
		std::string inFocusParameterID{ "" };
	
		//void SetParameterInFocus(std::string parameterIDPath);
	
		
};