/*
  ==============================================================================

    dataBindingCollection.h
    Created: 24 Oct 2019 11:48:40am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//#include "../Source/Data/Binding/dataBindingEntry.h"
#include "../Source/GUI/Components/imbSynthParameterEditor.h"
//#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
//#include "../Source/Data/Structures/imbEnumerationList.h"
#include "../Source/Utility/imbSynthTools.h"
#include "dataBindingEntry.h"

class dataBindingCollection {
 

 
    public:

		std::multimap<std::string, dataBindingEntry> items;

		void removeBindigsFor(std::string parameterIDPath);

		std::vector<dataBindingEntry> getBindingsFor(std::string parameterIDPath);

		void Add(dataBindingEntry binding);
	
		dataBindingCollection();




    
};

void dataBindingCollection::detachAll()
{
}

void dataBindingCollection::attachControl(Slider * _slider)
{
}

void dataBindingCollection::attachControl(ComboBox * _comboBox)
{
}

void dataBindingCollection::attachControl(ToggleButton * _button)
{
}

void dataBindingCollection::attachControl(TextEditor * _textEditor)
{
}
