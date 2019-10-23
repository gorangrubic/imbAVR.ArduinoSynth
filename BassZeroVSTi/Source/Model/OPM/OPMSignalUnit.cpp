/*
  ==============================================================================

    OPMSignalUnit.cpp
    Created: 4 Oct 2019 9:29:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "OPMSignalUnit.h"



std::shared_ptr<OPMSignalUnitChange> OPMSignalUnit::GetUnitChange(String name)
{
	std::shared_ptr<OPMSignalUnitChange> output = nullptr;

	for each (auto var in ChangeUnits)
	{
		if (var->ShortName.equalsIgnoreCase(name)) {
			output = var;
			break;
		}
	}

	return output;
}

OPMSignalUnit::OPMSignalUnit()
{
}

//OPMSignalUnit::OPMSignalUnit(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {
//
//}
void OPMSignalUnit::Deploy(ParameterController & parameterController)
{


	AddBoolParameter(parameterController,&Enabled, "Enabled", "Signal/Oscilator enabled", true, -1, false, imbControlParameterMessageType::sysExMsg);
	AddBoolParameter(parameterController, &Sync, "Sync", "Oscilator reset with Note On", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(parameterController, &RelativeToNote, "Relative", "Frequency is relative to MIDI Note", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(parameterController, &DoublePrescalar, "DoublePrescalar", "Double pitch [+12]", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(parameterController, &PWMCycleMode, "PWMCycleMode", "Continual Pulse Width from 0 to 100%", true, -1, false, imbControlParameterMessageType::sysExMsg);


	AddEnumParameter(parameterController, &PitchUnit, "PitchUnit", "Pitch Unit", &parameterController.ListOfPitchUnits, 0, -1,
		false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(parameterController, &WaveformPattern, "PWMPattern", "Waveform pattern", 64, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	WaveformPattern.SetHelp("8-steps On/Off pattern, directly controlling HIGH/LOW signal state. The pattern is mapped to single oscilation cycle, i.e. for pattern 11110000 you'll have 50% square pulse waveform. With 10101010 you'll have the same waveform, but pitched for +24 semitones (+2 octaves), as oscilator state will change four times in one oscilation cycle, instead once. This allows asymetric waveform behaviour, like: 11001101 - for more exotic results.");

	AddCCParameter(parameterController, &ModByte, "ModByte", "ModByte pattern", 64, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	ModByte.SetHelp("Experimental data point");

	DoublePrescalar.SetHelp("The main clock of the oscilator will jump for two steps per one clock tick. In other words, resulting frequency will be doubled (+1 octave). This is 'cheap' alternative to simple +12 semitones pitch increase: it needs less computation workload at MCU but decreases resolution of WaveformPattern interpretation. When [PWMCycleMode] is [True] it has lesser influence.");

	PWMCycleMode.SetHelp("When [True], width of the pulse is continual (from 0% to 100%) and controlled by PWM parameter of the oscilator. Otherwise, the pulse is driven by WaveformPattern - allowing asymetric pulse widths / customized waveform results.");

	// ======================= Rapid modulation of Signal generator unit properties



	for each (auto var in ChangeUnits)
	{
		auto modMode = var->ShortName.replace(ShortName + "_", "", true);

		parameterController.ListOfModulationModes.Add(modMode);
		//parameterController.ListOfSignalUnits.Add(var->ShortName);
		
		var->Deploy(parameterController);
	}


	//PhaseChange.Deploy(parameterController);

	//PWMChange.SetDescription("PWM", "Pulse-Width Change");
	//AddChild(&PWMChange);
	//ChangeUnits.Add(&PWMChange);
	//PWMChange.Deploy(parameterController);

	//PitchChange.SetDescription("Pitch", "Pitch Change");
	//AddChild(&PitchChange);
	//ChangeUnits.Add(&PhaseChange);
	//PitchChange.Deploy(parameterController);


}

void OPMSignalUnit::AddChangeUnit(OPMSignalUnitChange * output, std::string _shortName, std::string _longName, ControlGroup * group)
{
	output->NamePrefix = ShortName;
	output->SetDescription(_shortName, _longName);
	//PhaseChange.PreDeploy("Phase", "Phase Change");
	
	AddChild(output);
	ChangeUnits.Add(output);
}
