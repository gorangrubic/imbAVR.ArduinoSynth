/*
  ==============================================================================

    CommandInvokePoint.h
    Created: 28 Oct 2019 12:46:26am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../Source/Data/Header.h"
#include "../../Data/Model/dataObject.cpp"

class CommandInvokePoint:public dataObject {
 
    
    
    
    public:

		//KeyPress key;
		
		dataElementBase* parent;

		dataElementBase* source;

		//dataEnumProperty presetType = dataEnumProperty("presetType", 0, "Type", "", "presetNamePrefix", "");


		dataEnumProperty Key = dataEnumProperty("Key", 0, "Key", "", "keyPressCodes","", parameterClass::configuration);
		dataEnumProperty keyModify = dataEnumProperty("keyModify", 0, "Modify", "", "keyPressModifiers", "", parameterClass::configuration);
		dataStringProperty keyLetter = dataStringProperty("keyLetter", "", "Letter", "", "keyPressModifiers","", parameterClass::configuration);


		std::function<bool(dataElementBase*, std::string idPath, int ID)> onInvoked = nullptr;
    
		//std::function<bool(dataElementBase*, std::string idPath, int ID)> onInvoked = nullptr;

    int ID;

	bool isTicked = false;

	//CommandInvokePoint() {}

	CommandInvokePoint(dataElementBase * target, std::function<bool(dataElementBase*, std::string idPath, int ID)> _onInvoked = nullptr, int keyCode = 0,
		ModifierKeys modifiers = 0,
		juce_wchar textCharacter = 0)
		:dataObject(target->parameterIDPath, target->parameterLabel, target->parameterHelp, target->parameterUnit, target->parameterHelpUrl, parameterClass::configuration){
		
		onInvoked = _onInvoked;
		
		//IntProperty(target->parameterIDPath, 0, target->parameterLabel, target->parameterHelp, target->parameterUnit, target->parameterHelpUrl) {
		source = target;
		entryColorHex = target->entryColorHex;

		Add(&Key);
		Add(&keyModify);
		Add(&keyLetter);

		Key.Set(keyCode);
		keyModify.Set(modifiers.getRawFlags());
		keyLetter.Set(String(textCharacter).toStdString());

		elementClassRole = "CommandInvokePoint";
	};

	CommandInvokePoint(std::string _id, std::string _label, std::function<bool(dataElementBase*, std::string idPath, int ID)> _onInvoked = nullptr, std::string _description = "", int keyCode = 0,
		ModifierKeys modifiers = 0,
		juce_wchar textCharacter = 0)
		:dataObject(_id, _label, _description, "", "", parameterClass::configuration) {
			

				onInvoked = _onInvoked;

				Add(&Key);
				Add(&keyModify);
				Add(&keyLetter);

				Key.Set(keyCode);
				keyModify.Set(modifiers.getRawFlags());
				keyLetter.Set(String(textCharacter).toStdString());

				elementClassRole = "CommandInvokePoint";
			};
	
    
};