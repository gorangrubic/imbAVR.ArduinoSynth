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
#include "SynthDeviceModel.h"
#include <vector>
#include <list>

enum ModelComponentTypeEnum {

	Modulation,
	MacroControl,

};

class SynthDeviceModelComponentBase {
 
protected:

	
	void BuildParameters();
    public:
    
	   String NamePrefix;
       String ShortName;
	   String LongName;

	   SynthDeviceModel * Root;
	   SynthDeviceModelComponentBase * Parent;

	   void PreDeploy(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName);

	   void AddChild(SynthDeviceModelComponentBase* child);

	   void AddBoolParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, bool initValue = false, int _ccID=-1, bool _isAutomated=false);

	   void AddEnumParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, std::vector<String> * items, String initValue = "", int _ccID = -1, bool _isAutomated = false);

	   void AddCCParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, int initValue = 0, int minValue = 0, int maxValue = 127,int _ccID = -1, bool _isAutomated = false);

	   void AddParameter(imbControlParameter * output,String _parameterID, String _parameterLabel,
		   float minValue, float maxValue, float initValue,
		   String _parameterUnit,
		   int _ccID, bool _isAutomatizable, imbControlParameterType _type);

	   std::list<SynthDeviceModelComponentBase*> ChildComponents;

	   std::vector<imbControlParameter*> Parameters;

	   
	   juce::AudioProcessorParameterGroup processorParameterGroup;

	   
	 
	   /// <summary>
	   /// Deploys this instance.
	   /// </summary>
	   virtual void Deploy() = 0;
	   
       
	   SynthDeviceModelComponentBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName);

	   SynthDeviceModelComponentBase();

};