/*
  ==============================================================================

    CommandModelComplete.h
    Created: 28 Oct 2019 2:19:56am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Header.h"
#include "../Source/Data/Structures/dataElementIndexMap.h"
#include "CommandInvokePoint.h"
#include "CommandModel.h"

class CommandModelComplete :
	public CommandModel,
	public ApplicationCommandTarget {

public:
	CommandModelComplete(std::string _label = "", std::string _description = "", std::string _hexColor = "") :CommandModel(_label, _description, _hexColor) {

	}

	CommandModelComplete()
	{
		Array<Colour> coloursToUse{ Colours::darkblue, Colours::darkgrey, Colours::red,
									 Colours::green, Colours::blue, Colours::hotpink };
		//colours.addArray(coloursToUse);

		//addAndMakeVisible(button);
	}

	
	imbDictionary<int, dataElementBase*> idIndex;

	//void deploy() {

	//	_deploy(idIndex);

	//};

	//==============================================================================
	/** No other command targets in this simple example so just return nullptr. */
	ApplicationCommandTarget* getNextCommandTarget() override { return nullptr; }

	void getAllCommands(Array<CommandID>& commands) override
	{
		_deploy(idIndex);
		_getAllCommands(commands);

	}

	void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override
	{
		auto element = idIndex.Get((int)commandID, false);
		if (element != nullptr) {

			if (element->elementClassRole == "CommandInvokePoint") {

				CommandInvokePoint * cip = static_cast<CommandInvokePoint *>(element);
				cip->parent->parameterIDPath;

				result.setInfo(cip->parameterID, cip->parameterHelp, cip->parent->parameterIDPath, 0);
				if (cip->Key.Get() > 0) {
					result.addDefaultKeypress(cip->Key.Get(), cip->keyModify.Get());
					result.setTicked(cip->isTicked);
				}

			}
		}
		
	}

	bool perform(const InvocationInfo& info) override
	{
		auto element = idIndex.Get((int)info.commandID, false);
		if (element != nullptr) {

			if (element->elementClassRole == "CommandInvokePoint") {
				CommandInvokePoint * cip = static_cast<CommandInvokePoint *>(element);
				if (cip->onInvoked != nullptr) {
					cip->onInvoked(cip->source, cip->parameterIDPath, cip->ID);
				}
				
			}
		}
		else {
			return false;
		}

		return true;
	}

private:

};
