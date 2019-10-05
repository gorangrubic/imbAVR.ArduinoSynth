#pragma once
class imbParameterGroupBase
{
public:

	String GroupName;
	imbSynthAudioProcessor * _ParentProcessor

	imbParameterGroupBase(imbSynthAudioProcessor * _ParentProcessor, String _groupName, String _groupLabel);
	~imbParameterGroupBase();
};

