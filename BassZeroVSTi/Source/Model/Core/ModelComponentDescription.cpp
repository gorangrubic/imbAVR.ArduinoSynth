/*
  ==============================================================================

    ModelComponentDescription.cpp
    Created: 8 Oct 2019 5:36:31am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentDescription.h"

void ModelComponentDescription::SetDescription(juce::String _shortName, juce::String _longName, std::shared_ptr<ParameterController> _parameterControllerPtr)
  {
	if (NamePrefix.isEmpty()) {
		ShortName = _shortName;
	}
	else {
		ShortName = NamePrefix + "_" + _shortName;
	}

	if (LongName.isEmpty()) {
		LongName = NamePrefix + " " + _shortName;
	}
	else {
		LongName = _longName;
	}

	parameterControllerPtr = _parameterControllerPtr; //std::shared_ptr<ParameterController>(_parameterControllerPtr);
  }

//ModelComponentDescription::ModelComponentDescription() :ShortName{ "" }, LongName{ "" }, NamePrefix{""}
//  {
//  }
