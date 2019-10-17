#include "imbSynthGeneralConfiguration.h"



bool imbSynthGeneralConfiguration::LoadSettings(std::string filePath)
{
	return false;
}

bool imbSynthGeneralConfiguration::SaveSettings(std::string filePat)
{
	return false;
}

imbSynthGeneralConfiguration::imbSynthGeneralConfiguration():
	SettingsOptions(),
	SettingsFile(SettingsOptions)
{



}


imbSynthGeneralConfiguration::~imbSynthGeneralConfiguration()
{
}
