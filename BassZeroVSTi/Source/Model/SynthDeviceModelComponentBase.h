/*
  ==============================================================================

    SynthDeviceModelComponentBase.h
    Created: 1 Oct 2019 10:58:56am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Control/imbControlParameter.h"
#include "../Source/Model/Core/SharedPointerVector.h"
//#include "SynthDeviceModel.h"
#include "Core/ModelComponentDescription.h"
#include "..\Source\Model\ModelConstructionTools.h"
//#include "Core/ModelComponentWithChildren.h"
#include <vector>
//#include <list>



class SynthDeviceModelComponentBase:
	public ModelComponentDescription {
 

	
	
    public:
    
		void ConstructComponentParameters(ParameterController & parameterController, juce::AudioProcessorValueTreeState & parameters);

		
		SharedPointerVector<imbControlParameter> Parameters;

		/* Returns parameter with name == parameterID */
		std::shared_ptr<imbControlParameter> GetParameter(juce::String name);


		template<typename T>
		bool AttachParameter(juce::String name, T * guiComponent) {
			auto p = GetParameter(name);
			if (p != nullptr) {
				p->attachControl(guiComponent);
				return true;
			}
			else {
				// parameter not found
				return false;
			}
		}

	   void AddBoolParameter(ParameterController & parameterController, imbControlParameter * output, String _parameterID, String _parameterLabel, bool initValue = false, int _ccID=-1, bool _isAutomated=false, imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified, String _parameterParentPath = "");

	   

	   void AddEnumParameter(ParameterController & parameterController, imbControlParameter * output, String _parameterID, String _parameterLabel, imbEnumerationList * items, int initIndexValue=0, int _ccID = -1, bool _isAutomated = false, imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified, String _parameterParentPath = "");

	   void AddCCParameter(ParameterController & parameterController, imbControlParameter * output, String _parameterID, String _parameterLabel, int initValue = 0, int minValue = 0, int maxValue = 127,int _ccID = -1, bool _isAutomated = true,  imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified, String _parameterParentPath = "");

	   void AddParameter(ParameterController & parameterController, imbControlParameter * output,String _parameterID, String _parameterLabel,
		   float minValue, float maxValue, float initValue,
		   String _parameterUnit,
		   int _ccID, bool _isAutomatizable, imbControlParameterType _type, imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified, String _parameterParentPath = "");


	  // void BuildParameters();

	   

	   
	//   juce::AudioProcessorParameterGroup processorParameterGroup;

	   
	 
	   /// <summary>
	   /// Deploys this instance.
	   /// </summary>
	   //void Deploy() = 0;
	  // virtual void Deploy() = 0;
	   
       
	   //SynthDeviceModelComponentBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
	   //{

		  // : Root(_root),
			 //  Parent(_parent),
			 //  ShortName(_shortName),
			 //  LongName(_longName)
	   //};

	   SynthDeviceModelComponentBase(std::string _namePrefix = "", std::string _shortName = "", std::string _longName = "")
		   :ModelComponentDescription(_namePrefix, _shortName, _longName) 
	   {
	   
	   };

};