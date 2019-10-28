/*
  ==============================================================================

    CommandModel.h
    Created: 28 Oct 2019 12:45:32am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Header.h"
#include "CommandInvokePoint.h"


class CommandModel :  public dataObject {
    
public:

	//dataObject * parent = nullptr;

	//dataObject * currentBlock = nullptr;

	CommandModel * parent = nullptr;

	CommandModel * currentBlock = nullptr;

	int invokePointCount = 1;

	void _getAllCommands(Array<CommandID>& commands) {

		for each (auto var in children)
		{
			if (var->elementClassRole == "CommandInvokePoint") {

				CommandInvokePoint * cip = static_cast<CommandInvokePoint *>(var.get());
				commands.add(cip->ID);
			}
			if (var->elementClassRole == "CommandModel") {

				CommandModel * cm = static_cast<CommandModel *>(var.get());
				cm->_getAllCommands(commands);
				
			}
		}
	};

	void _deploy(imbDictionary<int, dataElementBase*> &_idIndex) {

		for each (auto var in children)
		{
			if (var->elementClassRole == "CommandInvokePoint") {

				CommandInvokePoint * cip = static_cast<CommandInvokePoint *>(var.get());
				_idIndex.Set(cip->ID, cip);
				
			}
			if (var->elementClassRole == "CommandModel") {

				CommandModel * cm = static_cast<CommandModel *>(var.get());
				cm->_deploy(_idIndex);

			}
		}
	}


	CommandInvokePoint Add(dataElementBase * target, std::function<bool(dataElementBase*, std::string idPath, int ID)> _onInvoked = nullptr, int keyCode = 0,
		ModifierKeys modifiers = 0,
		juce_wchar textCharacter = 0) {
		CommandInvokePoint output = CommandInvokePoint(target, _onInvoked, keyCode, modifiers, textCharacter);
		
		if (currentBlock != nullptr) {
			output.parent = currentBlock;

			currentBlock->add(&output);
			
		}
		else {
			output.parent = this;
			add(&output);
			//Add(&output, true);
			//currentBlock = &block;
			//currentBlock = &block;
		}

		output.ID = invokePointCount;
		invokePointCount++;

		layout.Add(&output);

		return output;
	};

	CommandInvokePoint Add(std::string _id, std::string _label, std::function<bool(dataElementBase*, std::string idPath, int ID)> _onInvoked = nullptr, std::string _description = "", int keyCode = 0,
		ModifierKeys modifiers = 0,
		juce_wchar textCharacter = 0){
		//CommandInvokePoint output = CommandInvokePoint(target, _onInvoked, keyCode, modifiers, textCharacter);
		CommandInvokePoint output = CommandInvokePoint(_id, _label, _onInvoked, _description, keyCode, modifiers, textCharacter);
		if (currentBlock != nullptr) {
			output.parent = currentBlock;

			currentBlock->add(&output);

		}
		else {
			output.parent = this;
			add(&output);
		}
		output.ID = invokePointCount;
		invokePointCount++;

		layout.Add(&output);

		return output;
	};

	//void Add(CommandModel *_child) {
	//	_child->parent = this;
	//	//	Add(static_cast<dataObject*>(_child), true); 
	//	add(_child);

	//	layout.currentBlock->add(_child,nullptr);
	//};

	//void Add(CommandInvokePoint *_child, bool _addToLayout=true) {
	//	//_child->parent = this;
	////	Add(static_cast<dataObject*>(_child), true); 
	//		currentBlock->Add(_child,true); 
	//		
	//		//layout.currentBlock->add(_child);
	//};

	//dataObject * OpenBlock(std::string _label = "", std::string _description = "", std::string _hexColor = "") {

	CommandModel * OpenBlock(std::string _label = "", std::string _description = "", std::string _hexColor = "") {

		layout.OpenBlock(_label, _description, _hexColor);

		CommandModel block = CommandModel(_label = "", _description = "", _hexColor = "");
		block.entryColorHex = _hexColor;
		block.invokePointCount = currentBlock->invokePointCount * 100;

		if (currentBlock != nullptr) {
			currentBlock->add(&block);
			block.parent = currentBlock;
		}
		else {
			block.parent = this;
		}

		currentBlock = &block;

		return &block;
	}

	void CloseBlock() {

		if (currentBlock->parent != nullptr) {
			currentBlock = currentBlock->parent; //static_cast<dataLayoutBlock*>(currentBlock->parent);
		}
		else {
			currentBlock = nullptr;
		}

		layout.CloseBlock();
	}

	CommandModel(std::string _label = "", std::string _description = "", std::string _hexColor = "") :dataObject(_label, _label, _description, "", "", parameterClass::unspecified) {

		elementClassRole = "CommandModel";
	};

	
};