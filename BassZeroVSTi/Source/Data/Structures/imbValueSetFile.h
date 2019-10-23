/*
  ==============================================================================

    imbValueSetFile.h
    Created: 22 Oct 2019 8:29:36pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbValueSet.h"

#include "../Source/Data/Model/dataObject.h"
class imbValueSetFile:public dataObject {
 
protected:

	
	

		std::unique_ptr<FileChooser> fc;

	public:

		std::string filenameExtension = "txt";
		std::string filenameDefault = "valueset";

		std::string GetFilename(std::string filename);

		//bool LoadFile(std::string directoryPath, std::string filename, bool saveDefault);
		bool LoadFile(std::string filepath, bool saveDefault);

		bool LoadFileDialog(std::string filepath);

		//bool SaveFile(std::string directoryPath, std::string filename);
		bool SaveFile(std::string filepath);
		bool SaveFileDialog(std::string filepath);

	
		//virtual std::string GetDefaultFilename() = 0;

		imbValueSetFile(std::string _defaultFilename = "", std::string _namePrefix = "", std::string _extension = "") :dataObject(_namePrefix) {
			
			if (!_extension.empty()) filenameExtension = _extension;
			if (!_defaultFilename.empty()) filenameDefault = _defaultFilename;
		}
};