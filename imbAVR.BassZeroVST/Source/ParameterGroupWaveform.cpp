#include "ParameterGroupWaveform.h"




ParameterGroupWaveform::ParameterGroupWaveform(imbSynthAudioProcessor * _ParentProcessor, String _groupName)
{
	GroupName = _groupName;

	CP_Group = juce::AudioProcessorParameterGroup(GroupName, GroupName, ".");


	CP_Pitch->AP_Parameter = new juce::AudioParameterInt(
		_groupName + "_Pitch",
		"Pitch offset",
		-36, 36,
		0,
		"Semitones");

	ParentProcessor = _ParentProcessor;
	ParentProcessor->addParameter(
		CP_Pitch->AP_Parameter
	);

	ParentProcessor->addParameterGroup(CP_Group);
	CP_Group.addChild(CP_Pitch->AP_Parameter);
	

}

ParameterGroupWaveform::~ParameterGroupWaveform()
{
}
