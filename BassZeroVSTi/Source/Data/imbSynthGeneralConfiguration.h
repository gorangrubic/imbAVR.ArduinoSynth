#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class imbSynthGeneralConfiguration
{

public:

	PropertiesFile::Options SettingsOption;

	PropertiesFile SettingsFile;
	
	bool LoadSettings(std::string filePath = "");

	bool SaveSettings(std::string filePath = "");

	imbSynthGeneralConfiguration();
	~imbSynthGeneralConfiguration();
};

