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

#include "../Source/Control/ParameterController.h"
#include "../Source/Control/imbControlParameter.h"

class ModelComponentWithChildren {
    
    public:

		SynthDeviceModelComponentBase * model;
		ModelComponentWithChildren * parent;

		/// <summary>
		/// The parameter controller - machanism for CC / SysExc ID synthnronization
		/// </summary>
		//ParameterController * parameterControllerPtr;


		void SetParent(SynthDeviceModelComponentBase * _model, ModelComponentWithChildren * _parent);
		
    
		void AddChild(SynthDeviceModelComponentBase* child);

		

		std::list<SynthDeviceModelComponentBase*> ChildComponents;

		ModelComponentWithChildren();
};