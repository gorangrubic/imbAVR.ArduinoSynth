/*
  ==============================================================================

    OscilatorBase.h
    Created: 4 Oct 2019 10:05:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Model/Components/OPMSignalUnitChange.h"


#include "../Source/Data/Model/dataPatternObject.h"

class OscilatorBase : public dataObject {

public:

	dataBoolProperty Enabled = dataBoolProperty("Enabled", true, "Enabled", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	OscilatorType type = OscilatorType::other;
	
	dataIntProperty Pitch = dataIntProperty("Pitch", 0, "Pitch", "Pitch offset from Note frequency - or Pitch in non-relative mode", "", "", 0, 12, parameterClass::opm);
	dataIntProperty Phase = dataIntProperty("Phase", 0, "Phase", "Phase offset", "", "", 0, 24, parameterClass::opm);


	dataBoolProperty Sync = dataBoolProperty("Sync", true, "Sync", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataBoolProperty RelativeToNote = dataBoolProperty("Sync", true, "Sync", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataBoolProperty PWMCycleMode = dataBoolProperty("PWMCycleMode", true, "PWMCycleMode", "Sets if oscilator is in PWM mode, otherwise follows the WaveformPattern", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataEnumProperty PitchUnit = dataEnumProperty("PitchUnit", 0, "Pitch unit", "Designates unit used for the Pitch parameter", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty Octave = dataIntProperty("Octave", 0, "Octave", "Octave shift", "", "", -2, 2, parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataPatternObject WaveformPattern = dataPatternObject((char)011110000, "WaveformPattern", "Waveform Pattern", "8-steps On/Off pattern, directly controlling HIGH/LOW signal state. The pattern is mapped to single oscilation cycle, i.e. for pattern 11110000 you'll have 50% square pulse waveform. With 10101010 you'll have the same waveform, but pitched for +24 semitones (+2 octaves), as oscilator state will change four times in one oscilation cycle, instead once. This allows asymetric waveform behaviour, like: 11001101 - for more exotic results.","", parameterClass::opm);

	dataPatternObject ModPattern = dataPatternObject((char)011110000, "ModPattern", "ModByte Pattern", "Experimental feature", "", parameterClass::opm);


	ModelModulatedControl PWM = ModelModulatedControl("PWM", "PWM", "Width of the pulse", "", parameterClass::ccSustained);
	ModelModulatedControl Shaper = ModelModulatedControl("Shaper", "Shaper", "Waveform modulation", "", parameterClass::ccLive);
	ModelModulatedControl AMP = ModelModulatedControl("AMP", "AMP", "Amplitude modulation", "", parameterClass::ccLive);

	ModelModulatedControl PAN = ModelModulatedControl("PAN", "PAN", "Stereo position", "", parameterClass::ccLive);

	OPMSignalUnitChange PitchChange = OPMSignalUnitChange("PitchChange", "OPM Pitch change", "", "");
	OPMSignalUnitChange PhaseChange = OPMSignalUnitChange("PhaseChange", "OPM Pitch change", "", "");
	OPMSignalUnitChange PWMChange = OPMSignalUnitChange("PWMChange", "OPM Pitch change", "", "");

	/// <summary>
	  /// Deploys this instance.
	  /// </summary>
	//virtual void Deploy() = 0;

	

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	//virtual void Deploy() = 0;
	
	OscilatorBase(std::string _name = "", std::string _label = "", OscilatorType _type = OscilatorType::other, std::string _description = "", std::string _helpUrl = "")
		: dataObject(_name, _label, _description, "", _helpUrl) {

		type = _type;
		elementClassRole = "OscilatorBase";


		Add(&Enabled);
		Add(&Pitch);
		Add(&PitchChange);
		Add(&PhaseChange);
		Add(&PWMChange);
		
		
		Add(&Sync);
		Add(&RelativeToNote);
		Add(&PWMCycleMode);
		Add(&PitchUnit);
		Add(&Octave);


		Add(&WaveformPattern);
		Add(&ModPattern);

		
		switch (type)
		{
		case OscilatorType::filter:
			break;
		case OscilatorType::waveform:
			Add(&Phase);
			Add(&PWM);

			Add(&Shaper);
			Add(&AMP);
			//Add(&PAN);
			break;
		case OscilatorType::perk:
			Add(&Phase);
			Add(&PWM);

			Add(&Shaper);
			Add(&AMP);
			Add(&PAN);
			break;
		case OscilatorType::other:
			break;
		}
		
	}

	/*OscilatorBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {

	}*/
};