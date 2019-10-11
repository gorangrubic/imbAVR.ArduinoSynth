/*
  ==============================================================================

    ModelComponentWithChildren.cpp
    Created: 8 Oct 2019 5:35:08am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelComponentWithChildren.h"

String ModelComponentWithChildren::GetParentPath(ModelComponentDescription current)
{
	
	String output = "";
	/*String lastParentName = "";
	if (parent != nullptr) {
		if (lastParentName != parent->ShortName) {
			if (parent->ShortName != "") {
				output += "." + lastParentName;
				lastParentName = parent->ShortName;
			}
		}
	}*/
	return output;
}

void ModelComponentWithChildren::SetParent(std::shared_ptr<SynthDeviceModelComponentBase> _model, ModelComponentWithChildren * _parent)
{
	model = _model;
	//parent = std::make_shared<ModelComponentWithChildren>(_parent);  //std::shared_ptr<ModelComponentWithChildren>(_parent);

	parent = std::shared_ptr<ModelComponentWithChildren>(_parent);

	//parameterControllerPtr = _parameterControllerPtr;
}


void ModelComponentWithChildren::SetParent(std::shared_ptr<SynthDeviceModelComponentBase> _model, std::shared_ptr<ModelComponentWithChildren> _parent)
  {
	//model = std::make_shared<SynthDeviceModelComponentBase>(&_model); // std::shared_ptr<SynthDeviceModelComponentBase>(_model);
	//parent = std::make_shared<ModelComponentWithChildren>(&_parent);  //std::shared_ptr<ModelComponentWithChildren>(_parent);

	//model =  std::shared_ptr<SynthDeviceModelComponentBase>(_model);
	//parent = std::shared_ptr<ModelComponentWithChildren>(_parent);

	model = _model;
	//parent =_parent;

	//parameterControllerPtr = _parameterControllerPtr;
  }

  void ModelComponentWithChildren::AddChild(SynthDeviceModelComponentBase * child)
{
	 // std::shared_ptr<SynthDeviceModelComponentBase> shared = std::shared_ptr<SynthDeviceModelComponentBase>(child);

	 // Parameters.push_back(shared);
	  
	  ChildComponents.Add(child); //.push_back(shared);
}

  void ModelComponentWithChildren::AddChild(ModelComponentWithChildren * child)
  {
	 // std::shared_ptr<ModelComponentWithChildren> shared = std::shared_ptr<ModelComponentWithChildren>(child);
	  ChildWithChildren.Add(child);
	  //ChildWithChildren.push_back(shared);
  }

  void ModelComponentWithChildren::ConstructComponentAndChildComponentParameters()
  {

	 // group = AudioProcessorParameterGroup(ShortName, LongName, ".");

	  ConstructComponentParameters();

	  for each (auto var in ChildComponents)
	  {
		  var->ConstructComponentParameters();
	  }

	  for each (auto var in ChildWithChildren)
	  {
		  var->ConstructComponentAndChildComponentParameters();
	  }

	/*  if (group != nullptr) {
		  parameterControllerPtr->processor->addParameterGroup(std::unique_ptr<AudioProcessorParameterGroup>(group));
	  }*/
  }

  //ModelComponentWithChildren::ModelComponentWithChildren()
  //{
  //}
