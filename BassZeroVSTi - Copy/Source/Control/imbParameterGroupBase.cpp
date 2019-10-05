#include "imbParameterGroupBase.h"



imbParameterGroupBase::imbParameterGroupBase(imbSynthAudioProcessor * _ParentProcessor, String _groupName, String _groupLabel)
{
    GroupName = _groupName;
	GroupLabel = _groupLabel;
	
	ParentProcessor = _ParentProcessor;

	CP_Group = juce::AudioProcessorParameterGroup(GroupName, GroupLabel, ".");
}


imbParameterGroupBase::~imbParameterGroupBase()
{
}
