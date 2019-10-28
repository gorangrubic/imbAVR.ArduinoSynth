/*
  ==============================================================================

    imbSynthPresetLibrary.h
    Created: 27 Oct 2019 7:06:56am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Source/Application/GeneralDefinitions.h"

class imbSynthPresetLibrary :public imbValueSetFile
{
public:


	dataStringProperty libraryName = dataStringProperty("libraryName", "Custom library", "Name", "");
	dataStringProperty libraryDescription = dataStringProperty("libraryDescription", "Custom library", "Name", "");
	dataStringProperty libraryUrl = dataStringProperty("libraryUrl", "Custom library", "Name", "");

	

	std::string libraryDirectoryPath;

	File libraryDir;

	//std::vector<imbSynthPresetDefinition> presets;


	imbSynthPresetLibrary(std::string _name)
		:imbValueSetFile(FILENAME_LIBRARY, _name, FILEEXTENSION_LIBRARY, "Library") {
		elementClassRole = "imbSynthPresetLibrary";

		Add(&libraryName);
		Add(&libraryDescription);
		Add(&libraryUrl);

	}


};
