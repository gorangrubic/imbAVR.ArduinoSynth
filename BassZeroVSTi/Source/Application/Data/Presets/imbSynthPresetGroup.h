/*
  ==============================================================================

    imbSynthPresetGroup.h
    Created: 27 Oct 2019 4:06:04am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Source/Application/GeneralDefinitions.h"

class imbSynthPresetGroup :public imbValueSetFile
{
public:

	dataStringProperty groupName = dataStringProperty("groupName", "Custom group", "Name", "");
	dataStringProperty groupDescription = dataStringProperty("groupDescription", "Custom group", "Name", "");
	
	File p_dir; // = p_var.getParentDirectory();
	std::string p_dir_path; // = p_dir.getFullPathName().toStdString();

	imbSynthPresetGroup(std::string _name="", std::string _description="")
		:imbValueSetFile("_group", _name, FILEEXTENSION_GROUP, "Library") {

		elementClassRole = "imbSynthPresetGroup";

		groupName.SetStrValue(_name);
		groupDescription.SetStrValue(_description);

		

		Add(&groupName);
		Add(&groupDescription);
	}

	
private:

};

