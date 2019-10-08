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
	AddBoolParameter(&Enabled, "Enabled", "Signal/Oscilator enabled", true, -1, false, imbControlParameterMessageType::sysExMsg);
	AddBoolParameter(&Sync, "Sync", "Oscilator reset with Note On", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(&RelativeToNote, "Relative", "Frequency is relative to MIDI Note", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(&DoublePrescalar, "DoublePrescalar", "Double pitch [+12]", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(&PWMCycleMode, "PWMCycleMode", "Continual Pulse Width from 0 to 100%", true, -1, false, imbControlParameterMessageType::sysExMsg);


	/*AddEnumParameter(&PitchUnit, "PitchUnit", "Pitch Unit", &opmParent->ListOfPitchUnits, "Semitones", -1,
		false, imbControlParameterMessageType::sysExMsg);*/

	AddCCParameter(&WaveformPattern, "PWMPattern", "Waveform pattern", 64, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	WaveformPattern.SetHelp("8-steps On/Off pattern, directly controlling HIGH/LOW signal state. The pattern is mapped to single oscilation cycle, i.e. for pattern 11110000 you'll have 50% square pulse waveform. With 10101010 you'll have the same waveform, but pitched for +24 semitones (+2 octaves), as oscilator state will change four times in one oscilation cycle, instead once. This allows asymetric waveform behaviour, like: 11001101 - for more exotic results.");

	AddCCParameter(&ModByte, "ModByte", "ModByte pattern", 64, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	ModByte.SetHelp("Experimental data point");

	DoublePrescalar.SetHelp("The main clock of the oscilator will jump for two steps per one clock tick. In other words, resulting frequency will be doubled (+1 octave). This is 'cheap' alternative to simple +12 semitones pitch increase: it needs less computation workload at MCU but decreases resolution of WaveformPattern interpretation. When [PWMCycleMode] is [True] it has lesser influence.");

	PWMCycleMode.SetHelp("When [True], width of the pulse is continual (from 0% to 100%) and controlled by PWM parameter of the oscilator. Otherwise, the pulse is driven by WaveformPattern - allowing asymetric pulse widths / customized waveform results.");

	// ======================= Rapid modulation of Signal generator unit properties
	PhaseChange.PreDeploy(Root, this, "Phase", "Phase Change");
	AddChild(&PhaseChange);
	PhaseChange.Deploy();

	PWMChange.PreDeploy(Root, this, "PWM", "Pulse-Width Change");
	AddChild(&PWMChange);
	PWMChange.Deploy();

	PitchChange.PreDeploy(Root, this, "Pitch", "Pitch Change");
	AddChild(&PitchChange);
	PitchChange.Deploy();


}
