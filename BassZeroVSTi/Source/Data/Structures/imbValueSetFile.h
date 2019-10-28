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
#include "../Source/Data/Structures/imbDictionary.h"

class imbValueSetFile:public dataObject {
 
protected:

	
		
		std::unique_ptr<FileChooser> fc;

	public:

		std::string _lastFilepath = "";

		imbIndexByString<File> FindRelatedFiles(std::string parentFilepath="", std::string relFileExtension = "*", std::string relNameInsert="*") {

			if (parentFilepath.empty()) parentFilepath = _lastFilepath;

			File p_file = File(parentFilepath);
			File p_dir = p_file.getParentDirectory();

			imbIndexByString<File> output;

			std::string searchNeedle = "";
			Array<File> fs;

			searchNeedle = GetRelatedFilepath(relNameInsert, relFileExtension, parentFilepath);
			fs = p_dir.findChildFiles((int)File::findFiles, isRelatedContentInSubdirectory, searchNeedle);

			/*if (isRelatedContentInSubdirectory) {

			} else {
				searchNeedle = GetRelatedFilepath(relNameInsert, relFileExtension, parentFilepath);
				fs = p_dir.findChildFiles((int)File::findFiles, isRelatedContentInSubdirectory, searchNeedle);
			}
			*/

			for each (auto var in fs)
			{
				auto rn = GetRelatedNameInsert(var.getFullPathName().toStdString(), parentFilepath);
				output.Set(rn, var);
			}
			return output;
			
		}

		File GetRelatedFile(std::string relNameInsert, std::string relFileExtension, std::string parentFilepath) {

			return File(GetRelatedFilepath(relNameInsert, relFileExtension, parentFilepath));
		}

		std::string GetRelatedNameInsert(std::string relFilepath, std::string parentFilepath="") {
			
			File r_file = File(relFilepath);
			String rn = r_file.getFileNameWithoutExtension(); // .toStdString();

			std::string pn = "";

			if (parentFilepath.empty()) {
				auto i = rn.indexOf(imbGeneralTools::namePartSeparator());
				rn = rn.substring(0,i);
			}
			else {
				File p_file = File(parentFilepath);
				pn = p_file.getFileNameWithoutExtension().toStdString();
				rn = rn.substring(0, pn.size());
			}

			return rn.toStdString();
		}


		std::string GetRelatedFilepath(std::string relNameInsert, std::string relFileExtension, std::string parentFilepath) {

			File p_file = File(parentFilepath);
			File p_dir = p_file.getParentDirectory();

			std::string output = ""; // imbGeneralTools::Append(p_dir.getFullPathName().toStdString(), p_file.getFileNameWithoutExtension().toStdString(), "_");

			if (isRelatedContentInSubdirectory) {
				
				output = imbGeneralTools::Append(p_dir.getFullPathName().toStdString(), p_file.getFileNameWithoutExtension().toStdString(), imbGeneralTools::filepathSeparator());
				output = imbGeneralTools::Append(output, relNameInsert, imbGeneralTools::filepathSeparator());
				output = imbGeneralTools::Append(output, relFileExtension, imbGeneralTools::extensionSeparator());
				//p_dir = File(subdir);

				//std::string subdir = output = imbGeneralTools::Append(p_dir.getFullPathName().toStdString(), p_file.getFileNameWithoutExtension().toStdString(), imbGeneralTools::filepathSeparator());
				//p_dir = File(subdir); // p_file.getParentDirectory();

			}
			else {
				output = imbGeneralTools::Append(p_dir.getFullPathName().toStdString(), p_file.getFileNameWithoutExtension().toStdString(), imbGeneralTools::filepathSeparator());
				output = imbGeneralTools::Append(output, relNameInsert, imbGeneralTools::namePartSeparator());
				output = imbGeneralTools::Append(output, relFileExtension, imbGeneralTools::extensionSeparator());

			/*	searchNeedle = GetRelatedFilepath(relNameInsert, relFileExtension, parentFilepath);
				fs = p_dir.findChildFiles((int)File::findFiles, true, searchNeedle);*/
			}

			return output;
		}


		void CloneAndSave(std::string sourceFilepath, std::string targetFilepath, imbValueSetFile * source= nullptr) {
			if (source == nullptr) {

				Clone(sourceFilepath);
			}
			else {

				if (sourceFilepath.empty()) sourceFilepath = source->_lastFilepath;

				Clone(source);
			}
			
			if (isRelatedContentEnabled) {
				bool subdir_made = false;
				auto rel_files = source->FindRelatedFiles(sourceFilepath);
				for each (auto rn in rel_files.GetKeys())
				{
					File source_relfile = rel_files.Get(rn, false);
					auto target_relfile = GetRelatedFile(rn, source_relfile.getFileExtension().toStdString(), targetFilepath);
					
					if (isRelatedContentInSubdirectory) {
						if (!subdir_made)
						{
							subdir_made = true;
							target_relfile.getParentDirectory().createDirectory();
						}
					}

					source_relfile.copyFileTo(target_relfile);
				}
			}

			SaveFile(targetFilepath);
		};

		void Clone(std::string sourceFilepath) {
			LoadFile(sourceFilepath, true);

		}

		void Clone(imbValueSetFile * source) {

			imbValueSet ivs;
			source->SaveTo(ivs);
			LoadFrom(ivs);
			if (_lastFilepath.empty()) {
				if (!source->_lastFilepath.empty()) {
					_lastFilepath = source->_lastFilepath;
				}
			}
		};

		/* it will prevent existing file to be overwriten */
		bool isFileOverwriteProtected = false;

		/* enables related files */
		bool isRelatedContentEnabled = true;

		/* related files are in subdirectory, rather than siblings */
		bool isRelatedContentInSubdirectory = false;

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

		imbValueSetFile(std::string _defaultFilename = "", std::string _namePrefix = "", std::string _extension = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", bool _isRelatedContentEnabled=false, bool _isRelatedContentInSubdirectory=false) :dataObject(_namePrefix, _label,  _description, _unit, _helpUrl) {
			
			isRelatedContentEnabled = _isRelatedContentEnabled;
			isRelatedContentInSubdirectory = _isRelatedContentInSubdirectory;

			//if (_id == "") _id = _defaultFilename;

			if (!_extension.empty()) filenameExtension = _extension;
			if (!_defaultFilename.empty()) filenameDefault = _defaultFilename;
		}
};