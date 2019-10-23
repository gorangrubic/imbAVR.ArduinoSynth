/*
  ==============================================================================

    imbValueSetFile.cpp
    Created: 22 Oct 2019 8:29:36pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbValueSetFile.h"

std::string imbValueSetFile::GetFilename(std::string filename)
{
	juce::String output;

	if (filename.empty()) {
		if (filenameDefault.empty()) {
			filename = name;
		}
		else {
			filename = filenameDefault;
		}
	}

	if (filename.empty()) {
		filename = "noname_file";
	}

	output = juce::String(filename);
	auto ext = juce::String(filenameExtension);
	ext = ext.replace("*", "", true);

	if (!output.endsWith(ext)) {
		output = output + ext; // .append(ext, ext.length());
	}
	return output.toStdString();
}

//bool imbValueSetFile::LoadFile(std::string directoryPath, std::string filename, bool saveDefault)
//{
//	juce::String p = juce::String(directoryPath);
//	if (!p.endsWith("\\")) {
//		p.append("\\",2);
//	}
//	p.append(GetFilename(filename), 500);
//
//	return LoadFile(p.toStdString(), saveDefault);
//
//}

bool imbValueSetFile::LoadFile(std::string filepath, bool saveDefault)
{
	imbValueSet valueSet;
	File targetFile(filepath);
	bool loaded = false;
	if (targetFile.existsAsFile()) {
		valueSet.FromString(targetFile.loadFileAsString().toStdString());
		LoadFrom(valueSet);
		loaded = true;
	}
	
	if (saveDefault) SaveFile(filepath);
	return loaded;
}

bool imbValueSetFile::LoadFileDialog(std::string filepath)
{
	fc.reset(new FileChooser("Choose a file to load...",
		juce::String(filepath),
		filenameExtension, false));

	fc->launchAsync(FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles,
		[&, this](const FileChooser& chooser)
	{
		auto result = chooser.getURLResult();
		auto name = result.isEmpty() ? String()
			: (result.isLocalFile() ? result.getLocalFile().getFullPathName()
				: result.toString(true));

		if (name.isNotEmpty()) {
			LoadFile(name.toStdString(), true);
		}

		/*AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon,
			"Saved",
			"Path: " + name);*/
	});
	return false;
}

//bool imbValueSetFile::SaveFile(std::string directoryPath, std::string filename)
//{
//	juce::String p = juce::String(directoryPath);
//	if (!p.endsWith("\\")) {
//		p.append("\\", 2);
//	}
//	p.append(GetFilename(filename), 500);
//	return SaveFile(p.toStdString());
//}

bool imbValueSetFile::SaveFile(std::string filepath)
{
	imbValueSet valueSet;
	SaveTo(valueSet);

	File targetFile(filepath);
	if (targetFile.existsAsFile()) {
		targetFile.deleteFile();
	}
	else if (targetFile.exists()) {
		return false;
	}
	auto jstr = juce::String(valueSet.ToString());
	targetFile.appendText(jstr);
	return true;
}

bool imbValueSetFile::SaveFileDialog(std::string filepath)
{
	fc.reset(new FileChooser("Choose a file to save...",
		juce::String(filepath),
		filenameExtension, false));
	
	fc->launchAsync(FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles,
		[&, this](const FileChooser& chooser)
	{
		auto result = chooser.getURLResult();
		auto name = result.isEmpty() ? String()
			: (result.isLocalFile() ? result.getLocalFile().getFullPathName()
				: result.toString(true));

		if (name.isNotEmpty()) {
			SaveFile(name.toStdString());
		}

		AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon,
			"Saved",
			"Path: " + name);
	});


	return true;
}
