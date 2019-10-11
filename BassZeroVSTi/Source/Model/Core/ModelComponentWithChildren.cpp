/*
  ==============================================================================

    ModelComponentWithChildren.cpp
    Created: 8 Oct 2019 5:35:08am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentWithChildren.h"

void ModelComponentWithChildren::SetParent(SynthDeviceModelComponentBase * _model, ModelComponentWithChildren * _parent)
  {
	model = _model;
	parent = _parent;
	//parameterControllerPtr = _parameterControllerPtr;
  }

  void ModelComponentWithChildren::AddChild(SynthDeviceModelComponentBase * child)
{
	ChildComponents.push_back(child);
}

  ModelComponentWithChildren::ModelComponentWithChildren()
  {
  }
