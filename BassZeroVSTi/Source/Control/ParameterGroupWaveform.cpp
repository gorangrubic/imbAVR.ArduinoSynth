#include "ParameterGroupWaveform.h"




ParameterGroupWaveform::ParameterGroupWaveform(imbSynthAudioProcessor * _ParentProcessor, String _groupName, String _groupLabel)
:imbParameterGroupBase(_ParentProcessor, _groupName, _groupLabel)
{


	



	/*ParentProcessor->addParameterGroup(CP_Group);
	CP_Group.addChild(CP_Pitch->AP_Parameter);
	*/

}

ParameterGroupWaveform::~ParameterGroupWaveform()
{
}
