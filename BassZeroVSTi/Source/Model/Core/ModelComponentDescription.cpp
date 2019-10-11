/*
  ==============================================================================

    ModelComponentDescription.cpp
    Created: 8 Oct 2019 5:36:31am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentDescription.h"

void ModelComponentDescription::SetDescription(String _shortName, String _longName, ParameterController * _parameterControllerPtr)
  {
	if (NamePrefix == "") {
		ShortName = _shortName;
	}
	else {
		ShortName = NamePrefix + "_" + _shortName;
	}

	if (LongName == "") {
		LongName = NamePrefix + " " + _shortName;
	}
	else {
		LongName = _longName;
	}

	parameterControllerPtr = _parameterControllerPtr;
  }

  ModelComponentDescription::ModelComponentDescription()
  {
  }
