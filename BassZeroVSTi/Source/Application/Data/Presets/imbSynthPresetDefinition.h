#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Application/GeneralDefinitions.h"
#include "../Source/Data/Model/dataObject.h"
#include "imbSynthLibraryContributor.h"

class imbSynthPresetDefinition :public imbValueSetFile
{
	
public:

	

	dataIntProperty	permanentID = dataIntProperty("permanentID", 0, "Permanent ID", "Permanent program ID for this preset. If 0, the ID is temporarly assigned with library load", "", "", 0, 255);
	//dataIntProperty	assignedID = dataIntProperty("assignedID", 0, "Assigned ID", "Currently assigned program ID", "", "", 0, 255,parameterClass::configuration, dataElementFeatures::_features::isTemporary);

	dataObject content = dataObject("content", "Content", "Parameters&values stored in this preset");

	dataEnumProperty presetType = dataEnumProperty("presetType", 0, "Type", "", "presetNamePrefix", "");

	dataStringProperty presetName = dataStringProperty("presetName", "New preset", "Name", "");
	dataStringProperty presetNote = dataStringProperty("presetNote", "", "Note", "");

	dataStringProperty presetChecksum = dataStringProperty("presetChecksum", "", "Checksum", "");


	dataEnumProperty author = dataEnumProperty("author", 0, "Author", "", "authorIDS");

	std::string presetFilename = "";
	int assignedID = 0;

	


	imbSynthPresetDefinition(std::string _name)
		: imbValueSetFile("preset", _name, FILEEXTENSION_PRESET, "Preset", "") { // dataObject(_name, _label, _description, _unit, _helpUrl) {
	//	: dataObject(_name, _label, _description, _unit, _helpUrl) {

		elementClassRole = "imbSynthPresetDefinition";

		//Add(&contributor);
		//Add(&assignedID);
		Add(&content);

		Add(&presetType);
		Add(&presetName);
		Add(&presetNote);
		
	}

	~imbSynthPresetDefinition();
};

