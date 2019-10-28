/*
  ==============================================================================

    imbSynthLibraryManager.h
    Created: 27 Oct 2019 4:06:17am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataEnumDictionary.h"
#include "../Source/Application/Files/SynthApplicationFolder.h"
#include "../Source/Application/GeneralDefinitions.h"
#include "imbSynthPresetLibrary.h"
#include "imbSynthPresetGroup.h"
#include "imbSynthPresetDefinition.h"
#include "../Source/Application/SynthEnumDictionaries.h"
#include "imbSynthLibraryContributor.h"
#include <unordered_set>

class imbSynthLibraryManager
{
public:

	SynthApplicationFolder * directory;

	//dataObjectCollection libraries;

	dataEnumDictionary * list_library;
	dataEnumDictionary * list_contributors;
	dataEnumDictionary * list_groups;
	
	imbIndexByString<imbSynthPresetLibrary&> libraries;
	imbIndexByString<imbSynthLibraryContributor&> contributors;
	

	
	void Load(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset=true);

	void LoadAuthors(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset = true);

	void LoadLibraries(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset = true);

	void LoadPresetAndGroups(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset, imbSynthPresetLibrary &l);


	void RefreshDictionaries(SynthEnumDictionaries & dictionaries);


	void SaveLibrary(imbSynthPresetLibrary &l, imbSynthPresetLibrary * source_library = nullptr);

	void SaveAuthor(imbSynthLibraryContributor &c, imbSynthPresetLibrary &l, imbSynthLibraryContributor *source_author = nullptr);

	void SaveGroup(imbSynthPresetLibrary &l, imbSynthPresetGroup &g, imbSynthPresetGroup *source_group = nullptr);

	void SavePreset(imbSynthPresetDefinition &p, imbSynthPresetLibrary &l, imbSynthPresetGroup &g, imbSynthPresetDefinition *source_preset = nullptr);



	imbSynthPresetLibrary CreateLibrary(std::string _id="", std::string _group_id = "", bool forceDialog=true);

	imbSynthLibraryContributor CreateAuthor(imbSynthPresetLibrary &l, std::string _id = "", bool forceDialog=true);

	imbSynthPresetGroup CreateGroup(imbSynthPresetLibrary &l, std::string _id = "", bool forceDialog=true);

	imbSynthPresetDefinition CreatePreset(imbSynthPresetLibrary &l, imbSynthPresetGroup & g, std::string _id = "", bool forceDialog=true);
	

	imbSynthLibraryManager();
	~imbSynthLibraryManager();

private:

};

inline void imbSynthLibraryManager::Load(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset)
{

	directory = folder;

	list_contributors = &dictionaries.contributors;
	list_library = &dictionaries.libraries;
	list_groups = &dictionaries.groups;

	// --- loading authors
	LoadAuthors(folder, dictionaries, reset);
	
	// --- loading libraries
	LoadLibraries(folder, dictionaries, reset);

	// refresh dictionaries
	RefreshDictionaries(dictionaries);
}

inline void imbSynthLibraryManager::LoadAuthors(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset)
{
	if (reset) {
		contributors.ClearAll();
		//dictionaries.libraries//.AddEntry
	}

	auto authorFiles = directory->thisDir.findChildFiles((int)File::findFiles, true, FILEEXTENSION_CONTRIBUTOR);
	for each (auto var in authorFiles)
	{
		imbSynthLibraryContributor c = imbSynthLibraryContributor(var.getFileNameWithoutExtension().toStdString());
		c.LoadFile(var.getFullPathName().toStdString(), true);

		//c.checksum = c.GetCheckSum();
		auto cid = c.ID.GetStringValue().toStdString();

		if (!contributors.Contains(cid)) {
			contributors.Set(cid, c);
			//dictionaries.contributors.AddEntry(cid, c.FullName.Get(), c.GetAuthorDescription());
		}
	}

}

inline void imbSynthLibraryManager::LoadLibraries(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset)
{

	if (reset) {
		libraries.ClearAll();
		//dictionaries.libraries//.AddEntry
	}


	// --- loading libraries

	auto libraryFiles = directory->thisDir.findChildFiles((int)File::findFiles, true, FILEEXTENSION_LIBRARY);

	for each (auto var in libraryFiles)
	{
		auto libraryFileName = var.getFileNameWithoutExtension();
		auto libraryDir = var.getParentDirectory();

		auto libraryPath = libraryDir.getFullPathName().toStdString();

		imbSynthPresetLibrary library = imbSynthPresetLibrary(libraryFileName.toStdString());

		library.LoadFile(libraryPath, true);
		library.libraryDir = libraryDir;

		LoadPresetAndGroups(folder, dictionaries, reset, library);
	}

	
}

inline void imbSynthLibraryManager::LoadPresetAndGroups(SynthApplicationFolder * folder, SynthEnumDictionaries & dictionaries, bool reset, imbSynthPresetLibrary & library)
{
	
	if (reset) library.RemoveAll();

	// --- loading presets and groups
	auto presetFiles = library.libraryDir.findChildFiles((int)File::findFiles, true, FILEEXTENSION_PRESET);

	for each (auto p_var in presetFiles)
	{
		auto p_dir = p_var.getParentDirectory();
		std::string p_dir_path = "";
		std::string groupName = "";
		//if (p_dir == libraryDir)

		p_dir_path = p_dir.getRelativePathFrom(library.libraryDir).toStdString();

		groupName = p_dir.getFileNameWithoutExtension().toStdString();

		imbSynthPresetGroup* g;

		if (!library.Contains(groupName)) {

			auto group = imbSynthPresetGroup(groupName, "");

			auto groupFilepath = imbGeneralTools::Append(p_dir_path, group.GetFilename(""), "/");
			group.LoadFile(p_dir_path, true);

			group.p_dir = p_dir;
			group.p_dir_path = p_dir_path;

			group.features |= dataElementFeatures::_features::isTemporary;

			

			library.Add(group);
			g = &group;
		}
		else {
			g = library.GetMemberByPath<imbSynthPresetGroup>(groupName);
		}

		std::string presetFilename = p_var.getFileNameWithoutExtension().toStdString();
		//std::string presetFilename = "";

		imbSynthPresetDefinition p = imbSynthPresetDefinition(presetFilename);
		p.LoadFile(p_var.getFullPathName().toStdString(), false);
		p.presetFilename = presetFilename;
		p.features |= dataElementFeatures::_features::isTemporary;

		g->Add(p);

		//imbDictionary<std::string, File> 
	}

	//for each (imbSynthPresetGroup * g in library.GetAllWithClassRole<imbSynthPresetGroup>("imbSynthPresetGroup"))
	//{
	//	g->Deploy();
	//}

	library.Deploy();
	library.DeployEnums(dictionaries);
	libraries.Set(library.parameterID, library);  //. Add(&library);
}

inline void imbSynthLibraryManager::RefreshDictionaries(SynthEnumDictionaries & dictionaries)
{
	dictionaries.groups.RemoveAll();

	dictionaries.libraries.RemoveAll();
	for each (imbSynthPresetLibrary* var in libraries.GetValues_ptr())
	{
		dictionaries.libraries.AddEntry(var->libraryName.Get(), var->libraryName.Get(), var->libraryDescription.Get(), "", var->libraryUrl.Get());
		for each (imbSynthPresetGroup * g in var->GetAllWithClassRole<imbSynthPresetGroup>("imbSynthPresetGroup"))
		{
			dictionaries.groups.AddEntry(g->parameterIDPath, g->groupName.Get(), g->groupDescription.Get());
		}
	}

	dictionaries.contributors.RemoveAll();
	for each (imbSynthLibraryContributor * var in contributors.GetValues_ptr())
	{
		dictionaries.contributors.AddEntry(var->ID.Get(), var->FullName.Get(), var->GetAuthorDescription(), "", var->Web.Get());
	}

}



inline void imbSynthLibraryManager::SaveLibrary(imbSynthPresetLibrary & l, imbSynthPresetLibrary * source_library)
{

	auto l_dir_path = imbGeneralTools::Append(directory->GetFolderPath(), l.libraryName.Get(), imbGeneralTools::filepathSeparator());
	auto l_path = imbGeneralTools::Append(l_dir_path, l.GetFilename(""), imbGeneralTools::filepathSeparator());


	l.libraryDir = File(l_dir_path);
	l.libraryDir.createDirectory();

	if (source_library != nullptr) {
		//l.CloneAndSave(l_path, source_library);

		l.Clone(source_library);
		auto l_groups = l.GetAllWithClassRole<imbSynthPresetGroup>("imbSynthPresetGroup");
		for each (auto l_g in l_groups)
		{
			auto n_g= CreateGroup(l, l_g->groupName.Get(), false);

			SaveGroup(l, n_g, l_g);
		}
		source_library->libraryDir.copyDirectoryTo(l.libraryDir);
	}


	l.libraryDirectoryPath = l_dir_path;

	l.SaveFile(l_path);

}

inline void imbSynthLibraryManager::SaveAuthor(imbSynthLibraryContributor & c, imbSynthPresetLibrary & l, imbSynthLibraryContributor * source_author)
{
	auto c_path = imbGeneralTools::Append(l.libraryDir.getFullPathName().toStdString(), c.GetFilename(c.ID.Get()), imbGeneralTools::filepathSeparator());

	if (source_author != nullptr) {
		c.CloneAndSave(source_author->_lastFilepath, c_path, source_author);
	}
	else {
		c.SaveFile(c_path);
	}
}

inline void imbSynthLibraryManager::SaveGroup(imbSynthPresetLibrary & l, imbSynthPresetGroup & g, imbSynthPresetGroup * source_group)
{
	auto g_path = imbGeneralTools::Append(l.libraryDir.getFullPathName().toStdString(), g.GetFilename(""), imbGeneralTools::filepathSeparator());
	if (source_group != nullptr) {

		g.Clone(source_group);
		auto l_presets = g.GetAllWithClassRole<imbSynthPresetDefinition>("imbSynthPresetDefinition");
		for each (auto g_p in l_presets)
		{
			auto n_p = CreatePreset(l, g, g_p->presetName.Get(), false);
			SavePreset(n_p, l, g, g_p);
		}
	}
	else {
		g.SaveFile(g_path);
	}
	
		
}

inline void imbSynthLibraryManager::SavePreset(imbSynthPresetDefinition & p, imbSynthPresetLibrary & l, imbSynthPresetGroup & g, imbSynthPresetDefinition * source_preset)
{
	auto p_path = imbGeneralTools::Append(g.p_dir.getFullPathName().toStdString(), p.GetFilename(""), imbGeneralTools::filepathSeparator());
	
	if (source_preset != nullptr) {
		p.CloneAndSave(source_preset->_lastFilepath, p_path, source_preset);
	}
	else {
		p.SaveFile(p_path);
	}
}


inline imbSynthPresetLibrary imbSynthLibraryManager::CreateLibrary(std::string _id, std::string _group_id, bool forceDialog=true)
{
	imbSynthPresetLibrary * source_library;

	std::string newLibraryName;

	AlertWindow w("New library",
		"Specify name for new preset library and initial group. Names must be valid directory names. Optionally, select existing library to clone content from. ",
		AlertWindow::QuestionIcon);

	if (_group_id.empty()) _group_id = "Main";
	if (_id.empty()) _id = "NewLibrary";


	w.addTextEditor("LibraryName", _id, "New library name");

	w.addTextEditor("BaseGroup", _group_id, "Initial group name");

	auto existing = list_library->GetEntryIDs();

	w.addComboBox("CloneExisting", existing, "Clone existing"); // // , { "option 1", "option 2", "option 3", "option 4" }, "some options");

	w.addButton("Create", 1, KeyPress(KeyPress::returnKey, 0, 0));
	w.addButton("Cancel", 0, KeyPress(KeyPress::escapeKey, 0, 0));

	if (libraries.Contains(_id)) {
		forceDialog = true;
	}

	if (forceDialog) {

		if (w.runModalLoop() != 0) // is they picked 'ok'
		{
			// this is the item they chose in the drop-down list..
			auto optionIndexChosen = w.getComboBoxComponent("CloneExisting")->getSelectedItemIndex();
			ignoreUnused(optionIndexChosen);

			if (optionIndexChosen > 0) {

				auto ls = existing[optionIndexChosen - 1];

				source_library = &libraries.Get(ls.toStdString());
			}
		
			// this is the text they entered..
			newLibraryName = w.getTextEditorContents("LibraryName").toStdString();
			_group_id = w.getTextEditorContents("BaseGroup").toStdString();
		} 

	}
	else {
		newLibraryName = _id;
	}

	if (newLibraryName.empty()) {
		if (source_library != nullptr) newLibraryName = source_library->libraryName.Get() + " Clone";
	}

	if (newLibraryName.empty()) {
		if (imbSynthTools::showMessageBox("Invalid library name ", "Library creation failed due invalid library name specified [" + newLibraryName + "], do you want to retry?", "Retry", "Cancel", AlertWindow::AlertIconType::QuestionIcon) != 0) {
			return CreateLibrary(_id, _group_id);
		}

	}



	auto finalLibraryName = libraries.GetUniqueKey(newLibraryName);

	auto l = imbSynthPresetLibrary(finalLibraryName);
	l.libraryName.Set(finalLibraryName);

	if (source_library == nullptr) {
		auto g = CreateGroup(l, _group_id, false);
	}

	SaveLibrary(l, source_library);


	return l;
}

inline imbSynthLibraryContributor imbSynthLibraryManager::CreateAuthor(imbSynthPresetLibrary & l, std::string _id, bool forceDialog)
{
	return imbSynthLibraryContributor(_id);
}

inline imbSynthPresetGroup imbSynthLibraryManager::CreateGroup(imbSynthPresetLibrary & l, std::string _id, bool forceDialog)
{
	auto g = imbSynthPresetGroup(_id, "");
	l.Add(g);
	return g;
}

inline imbSynthPresetDefinition imbSynthLibraryManager::CreatePreset(imbSynthPresetLibrary & l, imbSynthPresetGroup & g, std::string _id, bool forceDialog)
{
	return imbSynthPresetDefinition(_id);
}



imbSynthLibraryManager::imbSynthLibraryManager()
{
}

imbSynthLibraryManager::~imbSynthLibraryManager()
{
}