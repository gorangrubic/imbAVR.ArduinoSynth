/*
  ==============================================================================

    SynthApplicationFolderCollection.cpp
    Created: 22 Oct 2019 7:44:06pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthApplicationFolderCollection.h"

void SynthApplicationFolderCollection::init()
  {
	for each (auto var in folders)
	{
		var->init();
	}
  }
