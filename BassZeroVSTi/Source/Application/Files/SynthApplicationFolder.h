/*
  ==============================================================================

    SynthApplicationFolder.h
    Created: 22 Oct 2019 7:30:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbValueSetFile.h"

class SynthApplicationFolder {
 
    public:
    
    std::string name;
    std::string description;
    std::string parentPath;

	File thisDir;
    
    SynthApplicationFolder(std::string _name,std::string _description="", std::string _parentPath = "");
    
	SynthApplicationFolder();

	std::string GetFilepath(imbValueSetFile &data, std::string filename="");

	std::string GetFilepath(std::string filename);
	juce::File GetFile(std::string filename);

	std::string GetFolderPath();

	void init();

};