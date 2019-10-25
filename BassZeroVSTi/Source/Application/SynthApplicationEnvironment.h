/*
  ==============================================================================

    SynthApplicationEnvironment.h
    Created: 23 Oct 2019 3:27:22pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameterEnumerations.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"

#include "../Source/Application/Help/HelpResourcesManager.h"
#include "../Source/Application/Components/IOPorts.h"
#include "../Source/Application/Files/SynthApplicationFolderCollection.h"

#include "../Source/Data/Model/dataEnumDictionary.h"
#include "../Source/Application/SynthEnumDictionaries.h"
#include "../Source/Control/ParameterController.h"


class SynthApplicationEnvironment {
 
    public:

		ParameterController parameterController;

		HelpResourcesManager helpManager;
		IOPorts ioPorts;
    	SynthApplicationFolderCollection folders;

		SynthEnumDictionaries enums;
		

	SynthApplicationEnvironment():
		folders(),
		ioPorts(),
		helpManager(folders.FolderHelp)
	{
		folders.init();
		ioPorts.deploy();
		enums.init();
		
		
	};
    	
};