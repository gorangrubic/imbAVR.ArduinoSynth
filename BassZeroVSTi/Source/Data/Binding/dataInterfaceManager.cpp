/*
  ==============================================================================

    dataInterfaceManager.cpp
    Created: 24 Oct 2019 4:05:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataInterfaceManager.h"

#include "../Source/Data/Model/dataObject.h"

void dataInterfaceManager::Register(dataObject _model)
{
	dataModels.Add(&_model);
}

dataContextMenu dataInterfaceManager::showContextMenu(std::string pathID)
{
	dataContextMenu output;
	
	return output;
}

void dataInterfaceManager::setGuiFocus(std::string pathID)
{
	dataElementBase _focused = GetDataElement<dataElementBase>(pathID);
}

void dataInterfaceManager::setFloatValueChange(float newValue, std::string pathID)
{
}

void dataInterfaceManager::setStringValueChange(std::string newValue, std::string pathID)
{
}

void dataInterfaceManager::updateState(SynthApplicationEnvironment & environment, std::string parameterIDPath)
{
}

void dataInterfaceManager::updateGUI(SynthApplicationEnvironment & environment, std::string parameterIDPath)
{
}

void dataInterfaceManager::updateGUIView(ViewSettings & viewSettings, std::string parameterIDPath)
{
}

void dataInterfaceManager::detachAll()
{
}

void dataInterfaceManager::attachAutomatically(dataElementBase * element, Component * component)
{
}

void dataInterfaceManager::attachAsParent(dataElementBase * element, Component * component)
{
	dataBindingEntry entry = attachControlBase(element, component);
	
	entry.attachControlAsParent(component);
	
}

dataBindingEntry dataInterfaceManager::attachControlBase(dataElementBase * element, Component * _component)
{
	dataBindingEntry entry = dataBindingEntry(element->parameterIDPath);
	entry.onGUIFocus = setGuiFocus;
	entry.onShowContextMenu = showContextMenu(std::string pathID);
	bindings.Add(entry);
	return entry;
}

void dataInterfaceManager::attachControl(dataElementBase * element, Slider * _slider)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, ComboBox * _comboBox)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, ToggleButton * _button)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, TextEditor * _textEditor)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, Label * _textLabel)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, imbSynthParameterEditor * _editor)
{
}

void dataInterfaceManager::attachControl(dataElementBase * element, imbSynthGUIComponent * _editor)
{
}
