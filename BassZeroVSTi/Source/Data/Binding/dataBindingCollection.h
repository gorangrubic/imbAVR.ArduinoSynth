/*
  ==============================================================================

    dataBindingCollection.h
    Created: 24 Oct 2019 11:48:40am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Binding/dataBindingEntry.h"
#include "../Source/GUI/Components/imbSynthParameterEditor.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/imbEnumerationList.h"
#include "../Source/Utility/imbSynthTools.h"

#include <vector>
class dataBindingCollection {
 

 
    public:
    
		std::vector<dataBindingEntry> entries;

		void detachAll();

		void attachControl(Slider* _slider);
		void attachControl(ComboBox* _comboBox);
		void attachControl(ToggleButton* _button);
		void attachControl(TextEditor* _textEditor);
		void attachControl(Label* _textLabel);
		void attachControl(imbSynthParameterEditor* _editor);
		void attachControl(imbSynthGUIComponent* _editor);

    
};