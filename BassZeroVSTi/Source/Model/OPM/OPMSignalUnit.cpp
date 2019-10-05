/*
  ==============================================================================

    OPMSignalUnit.cpp
    Created: 4 Oct 2019 9:29:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "OPMSignalUnit.h"



OPMSignalUnit::OPMSignalUnit()
{
}

//OPMSignalUnit::OPMSignalUnit(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {
//
//}
void OPMSignalUnit::Deploy()
{
	AddCCParameter

	// ======================= Rapid modulation of Signal generator unit properties
	PhaseChange.PreDeploy(Root, this, "Phase", "Phase Change");
	AddChild(&PhaseChange);
	PhaseChange.Deploy();

	PWMChange.PreDeploy(Root, this, "PWM", "Pulse-Width Modulation Change");
	AddChild(&PWMChange);
	PWMChange.Deploy();

	PitchChange.PreDeploy(Root, this, "Pitch", "Pitch Change");
	AddChild(&PitchChange);
	PitchChange.Deploy();


}
