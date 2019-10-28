/*
  ==============================================================================

    dataLayoutBlockBase.h
    Created: 27 Oct 2019 5:11:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Utility/imbGeneralTools.h"
#include "dataLayoutBlockViewSettings.h"

class dataLayoutBlockBase:public dataLayoutBlockViewSettings {

public:





	/** Determines the order used to lay out items in their flex container.
	Elements are laid out in ascending order of thus order value. Elements with the same order value
	are laid out in the order in which they appear in the array.
*/
	int order = 0;

	

	dataLayoutBlockBase(std::string _label = "", std::string _description = "") {
		blockLabel = _label;
		blockDescription = _description;
	};
};