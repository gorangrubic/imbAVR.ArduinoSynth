#include "imbParameterGroupBase.h"



imbParameterGroupBase::imbParameterGroupBase(imbSynthAudioProcessor * _ParentProcessor, String _groupName, String _groupLabel)
{
    GroupName = _groupName;
	GroupLabel = _groupLabel;
	
	ParentProcessor = _ParentProcessor;

	CP_Group = juce::AudioProcessorParameterGroup(GroupName, GroupLabel, ".");
	
}


imbControlParameter imbParameterGroupBase::AddParameter(String _parameterID, String _parameterLabel, 
int MinValue, int MaxValue, int InitValue, String _parameterUnit) {
 
    
	imbControlParameter output = imbControlParameter();


	auto Parameter = new juce::AudioProcessorValueTreeState(
		_groupName + "_" + Pitch,
		"Pitch offset",
		-36, 36,
		0,
		"Semitones");


	ParentProcessor->addParameter(
		CP_Pitch.Parameter
	);

	CP_Group.

		CP_Group.addChild(CP_Pitch.Parameter);
    
    
}

imbParameterGroupBase::~imbParameterGroupBase()
{
}
