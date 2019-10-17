/*
  ==============================================================================

    OPMSignalUnitChange.h
    Created: 5 Oct 2019 1:45:04pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../Source/Control/imbControlParameter.h"
#include "..\Source\Model\ModelConstructionTools.h"

#define NameString_Phase "Phase"
#define NameString_Pitch "Pitch"
#define NameString_PWM "PWM"
#define LabelString_Phase "Phase Change"
#define LabelString_Pitch "Pitch Change"
#define LabelString_PWM "Pulse-Width Change"

class OPMSignalUnitChange :
	public SynthDeviceModelComponentBase

	
{
public:

	/*static std::string NameString_Phase = const "Phase";
	static std::string NameString_Pitch = "Pitch";
	static std::string NameString_PWM = juce::String("PWM");
	static std::string LabelString_Phase = juce::String("Phase");
	static std::string LabelString_Pitch = juce::String("Pitch");
	static std::string LabelString_PWM = juce::String("Pulse-Width Change");*/

	//OPMControlModel * opmParent;

	imbControlParameter Enabled;
	imbControlParameter Sync;
	imbControlParameter Chaos;

	imbControlParameter Rate;
	imbControlParameter Period;
	imbControlParameter Change;
	imbControlParameter Function;

	void Deploy(ParameterController & parameterController) ;

	OPMSignalUnitChange();

//	OPMSignalUnitChange(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }
};