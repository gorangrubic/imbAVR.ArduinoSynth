/*
  ==============================================================================

    ModelComponentWithChildren.h
    Created: 8 Oct 2019 5:35:08am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/SynthDeviceModelComponentBase.h"
#include "ModelComponentDescription.h"
#include "SharedPointerVector.h"
#include <vector>

#include "../Source/Control/ParameterController.h"
#include "../Source/Control/imbControlParameter.h"

#include "../Source/Model/ModelConstructionTools.h"

class ModelComponentWithChildren:
	public SynthDeviceModelComponentBase {
    
    public:

		std::shared_ptr<SynthDeviceModelComponentBase> model{ nullptr };
		std::shared_ptr<ModelComponentWithChildren> parent{ nullptr };

		/// <summary>
		/// The parameter controller - machanism for CC / SysExc ID synthnronization
		/// </summary>
		//ParameterController * parameterControllerPtr;

		String GetParentPath(ModelComponentDescription current);

		void SetParent(std::shared_ptr<SynthDeviceModelComponentBase> _model, ModelComponentWithChildren * _parent);

		//void SetParent(SynthDeviceModelComponentBase * _model, ModelComponentWithChildren * _parent);
		
    
		void SetParent(std::shared_ptr<SynthDeviceModelComponentBase> _model, std::shared_ptr<ModelComponentWithChildren> _parent);

		void AddChild(SynthDeviceModelComponentBase* child);

		void AddChild(ModelComponentWithChildren* child);

		/* Populates specified vector with all parameters defined in the model*/
		void CollectAllParameterDefinitions(SharedPointerVector<imbControlParameter> & parameters);

		void ConstructComponentAndChildComponentParameters(ParameterController & parameterController, juce::AudioProcessorValueTreeState & parameters);


		
		//std::shared_ptr<imbControlParameter> shared = std::shared_ptr<imbControlParameter>(output);

		//Parameters.push_back(shared);

		SharedPointerVector<SynthDeviceModelComponentBase> ChildComponents;
		SharedPointerVector<ModelComponentWithChildren> ChildWithChildren;
		//std::vector<std::shared_ptr<SynthDeviceModelComponentBase>> ChildComponents { };
		//std::vector<std::shared_ptr<ModelComponentWithChildren>> ChildWithChildren { };

		/*std::vector<SynthDeviceModelComponentBase*> ChildComponents;

		std::vector<ModelComponentWithChildren*> ChildWithChildren;*/

		ModelComponentWithChildren(std::string _namePrefix = "", std::string _shortName = "", std::string _longName = "") : SynthDeviceModelComponentBase(_namePrefix, _shortName, _longName)
		{
		};
};