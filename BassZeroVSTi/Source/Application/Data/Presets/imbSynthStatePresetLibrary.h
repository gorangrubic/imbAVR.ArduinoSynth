#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Source/Application/GeneralDefinitions.h"

#include "imbSynthPresetGroup.h"


class imbSynthStatePresetLibrary:public imbValueSetFile
{
public:


	dataStringProperty libraryName = dataStringProperty("libraryName", "Custom library", "Name", "");
	dataStringProperty libraryDescription = dataStringProperty("libraryDescription", "Custom library", "Name", "");
	dataStringProperty libraryUrl = dataStringProperty("libraryUrl", "Custom library", "Name", "");

	std::string libraryDirectoryPath;
	//SharedPointerVector<imbSynthPresetGroup> Groups;
	//std::vector<imbSynthPresetGroup*> Groups;

	imbSynthStatePresetLibrary(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
		:imbValueSetFile("UserLibrary", _name, FILEEXTENSION_LIBRARY,"Library") {
		Add(&libraryName, true);
		Add(&libraryDescription, true);
		Add(&libraryUrl, true);

	}

	
};

