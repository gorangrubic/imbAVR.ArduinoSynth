/*
  ==============================================================================

    SynthApplicationFolder.cpp
    Created: 22 Oct 2019 7:30:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthApplicationFolder.h"
#include <iostream>
#include <stdio.h>
#include <io.h>

SynthApplicationFolder::SynthApplicationFolder(std::string _name, std::string _description, std::string _parentPath)
  {
	name = _name;
	description = _description;

	if (_parentPath.empty()) {
		parentPath = File::getCurrentWorkingDirectory().getFullPathName().toStdString();
	}
	else {
		parentPath = _parentPath;
	}

  }

SynthApplicationFolder::SynthApplicationFolder()
{
}

std::string SynthApplicationFolder::GetFilepath(imbValueSetFile & data, std::string filename)
{
	filename = data.GetFilename(filename);

	return GetFilepath(filename);

}



std::string SynthApplicationFolder::GetFilepath(std::string filename)
{
	return thisDir.getFullPathName().toStdString() + "/" + filename;
}

juce::File SynthApplicationFolder::GetFile(std::string filename)
{
	return juce::File(GetFilepath(filename));
}

std::string SynthApplicationFolder::GetFolderPath()
{
	return thisDir.getFullPathName().toStdString();
}

void SynthApplicationFolder::init()
{	
	thisDir = File(parentPath + "/" + name);

	if (!thisDir.exists()) {
		
		Result r = thisDir.createDirectory();
		if (!r.wasOk()) {
			AlertWindow w("Directory [" + name + "] creation failed", "Output path: " + thisDir.getFullPathName(), AlertWindow::InfoIcon);
			w.addButton("Ok", 0, KeyPress(KeyPress::returnKey, 0, 0));

			w.runModalLoop();
		}
	}

}
