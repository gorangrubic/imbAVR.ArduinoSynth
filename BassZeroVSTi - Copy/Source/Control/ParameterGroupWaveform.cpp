#include "ParameterGroupWaveform.h"




ParameterGroupWaveform::ParameterGroupWaveform(imbSynthAudioProcessor * _ParentProcessor, String _groupName, String _groupLabel)
:imbParameterGroupBase(_ParentProcessor, _groupName, _groupLabel)
{


	
	CP_Pitch.Parameter = new juce::AudioProcessorValueTreeState(
		_groupName + "_Pitch",
		"Pitch offset",
		-36, 36,
		0,
		"Semitones");

	
	ParentProcessor->addParameter(
		CP_Pitch.Parameter
	);

	CP_Group.

	CP_Group.addChild(CP_Pitch.Parameter);


	/*ParentProcessor->addParameterGroup(CP_Group);
	CP_Group.addChild(CP_Pitch->AP_Parameter);
	*/

}

ParameterGroupWaveform::~ParameterGroupWaveform()
{
}
