/*
  ==============================================================================

    SynthApplicationFolderCollection.h
    Created: 22 Oct 2019 7:44:06pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthApplicationFolder.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "../Source/Utility/imbGeneralTools.h"

class SynthApplicationFolderCollection {
 
    	
    public:
    
    SharedPointerVector<SynthApplicationFolder> folders;

	SynthApplicationFolder FolderLibrary; // = SynthApplicationFolder("Library", "Directory with preset libraries");
	SynthApplicationFolder FolderOutput; // = SynthApplicationFolder("Output", "Directory with preset libraries");
	SynthApplicationFolder FolderSettings;
	SynthApplicationFolder FolderResources;
	SynthApplicationFolder FolderHelp;
	
	void init();

    SynthApplicationFolderCollection(std::string rootPath="")
	:FolderLibrary("Library", "Directory with preset libraries", rootPath),
		FolderOutput("Output", "Generated outputs", rootPath),
		FolderSettings("Settings", "Configuration parameters and other settings", rootPath),
		FolderResources("Resources", "Data resources", rootPath),
		FolderHelp("Help", "Help documents and resources", rootPath)
	{
		folders.Add(&FolderLibrary);
		folders.Add(&FolderOutput);
		folders.Add(&FolderSettings);
		folders.Add(&FolderResources);
		folders.Add(&FolderHelp);
		
    }




};