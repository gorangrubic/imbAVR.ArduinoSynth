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

  void ModelComponentWithChildren::CollectAllParameterDefinitions(SharedPointerVector<imbControlParameter>& parameters)
  {
	  for each (auto var in Parameters)
	  {
		  parameters.Add(var);
	  }

	  for each (auto varComp in ChildComponents)
	  {
		  for each (auto var in varComp->Parameters)
		  {
			  parameters.Add(var);
		  }
	  }

	  for each (auto var in ChildWithChildren)
	  {
		  var->CollectAllParameterDefinitions(parameters);
	  }
  }

  void ModelComponentWithChildren::ConstructComponentAndChildComponentParameters(ParameterController & parameterController, juce::AudioProcessorValueTreeState & parameters)
  {

	 // group = AudioProcessorParameterGroup(ShortName, LongName, ".");

	  ConstructComponentParameters(parameterController, parameters);

	  for each (auto var in ChildComponents)
	  {
		  var->ConstructComponentParameters(parameterController, parameters);
	  }

	  for each (auto var in ChildWithChildren)
	  {
		  var->ConstructComponentAndChildComponentParameters(parameterController, parameters);
	  }

	/*  if (group != nullptr) {
		  parameterControllerPtr->processor->addParameterGroup(std::unique_ptr<AudioProcessorParameterGroup>(group));
	  }*/
  }

  //ModelComponentWithChildren::ModelComponentWithChildren()
  //{
  //}
