/*
  ==============================================================================

    ModelComponentDescription.cpp
    Created: 8 Oct 2019 5:36:31am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentDescription.h"
//
//void ModelComponentDescription::SetDescription(std::string _shortName, std::string _longName, std::shared_ptr<ParameterController> _parameterControllerPtr)
//  {
//	if (_shortName != "") {
//		if (NamePrefix.isEmpty()) {
//			ShortName = _shortName;
//		}
//		else {
//			ShortName = NamePrefix + "_" + _shortName;
//		}
//
//	}
//	if (_longName != "") {
//		if (LongName.isEmpty()) {
//			LongName = NamePrefix + " " + _shortName;
//		}
//		else {
//			LongName = _longName;
//		}
//
//	}
//	//auto s = std::shared_ptr<ParameterController>(_parameterControllerPtr);
//
//	parameterControllerPtr.swap(_parameterControllerPtr); //std::shared_ptr<ParameterController>(_parameterControllerPtr);
//  }

//ModelComponentDescription::ModelComponentDescription() :ShortName{ "" }, LongName{ "" }, NamePrefix{""}
//  {
//  }

//void ModelComponentDescription::SetDescription(std::string _shortName, std::string _longName) {
//	ParameterController &pc = *_parameterControllerPtr;
//	SetDescription(_shortName, _longName, &pc);
//}

void ModelComponentDescription::SetDescription(std::string _shortName, std::string _longName)
{
	if (_shortName != "") {
		if (NamePrefix.isEmpty()) {
			ShortName = _shortName;
		}
		else {
			ShortName = NamePrefix + "_" + _shortName;
		}

	}
	if (_longName != "") {
		if (LongName.isEmpty()) {
			LongName = NamePrefix + " " + _shortName;
		}
		else {
			LongName = _longName;
		}

	}

	//auto s = std::shared_ptr<ParameterController>(_parameterController);
	
	//parameterControllerPtr = _parameterController;

	//auto s = std::shared_ptr<ParameterController>(_parameterController);
	//parameterControllerPtr.swap(std::shared_ptr<ParameterController>(_parameterController)());

	//parameterControllerPtr.swap(s); //std::shared_ptr<ParameterController>(_parameterControllerPtr);
}
