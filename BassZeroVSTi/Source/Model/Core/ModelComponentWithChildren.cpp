/*
  ==============================================================================

    ModelComponentWithChildren.cpp
    Created: 8 Oct 2019 5:35:08am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentWithChildren.h"

void ModelComponentWithChildren::AddChild(SynthDeviceModelComponentBase * child)
{
	ChildComponents.push_back(child);
}

  ModelComponentWithChildren::ModelComponentWithChildren()
  {
  }
