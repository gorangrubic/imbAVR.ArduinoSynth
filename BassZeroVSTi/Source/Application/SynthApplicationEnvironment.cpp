/*
  ==============================================================================

    SynthApplicationEnvironment.cpp
    Created: 23 Oct 2019 3:27:22pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthApplicationEnvironment.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
void SynthApplicationEnvironment::init()
  {
	enum_parameterClass.AddEntry((int)parameterClass::unspecified, "Other", "Unspecified parameter class", "#181f22");
	enum_parameterClass.AddEntry((int)parameterClass::ccLive, "CC Live", "Control parameters, applied during both Note On or Off", "#ed6216");
	enum_parameterClass.AddEntry((int)parameterClass::ccSustained, "CC Sustained", "Control parameters, applied in Note off period", "#029d4d");
	enum_parameterClass.AddEntry((int)parameterClass::opm, "OPM", "OPM parameters, applied when synth (DAW, MIDI generator) is not activly playing", "#397daa");
	enum_parameterClass.AddEntry((int)parameterClass::configuration, "Settings", "Static configuration parameters", "#181f22");
	
	enum_presetNamePrefix.AddEntry("BS", "Bassline", "");
	enum_presetNamePrefix.AddEntry("PL", "Plucked", "");
	enum_presetNamePrefix.AddEntry("LD", "Lead", "");
	enum_presetNamePrefix.AddEntry("SY", "Synth", "");
	enum_presetNamePrefix.AddEntry("KY", "Key", "");
	enum_presetNamePrefix.AddEntry("PD", "Pad", "");
	enum_presetNamePrefix.AddEntry("SQ", "Sequence", "");

	enum_presetNamePrefix.AddEntry("KD", "Kick drum", "");
	enum_presetNamePrefix.AddEntry("DR", "Drums", "");
	enum_presetNamePrefix.AddEntry("SN", "Snare", "");
	enum_presetNamePrefix.AddEntry("PR", "Percussions", "");
	enum_presetNamePrefix.AddEntry("HI", "High hat", "");

	enum_presetNamePrefix.AddEntry("FX", "Effect", "");
	enum_presetNamePrefix.AddEntry("UL", "Uplifter", "");
	enum_presetNamePrefix.AddEntry("DL", "Downlifter", "");
	enum_presetNamePrefix.AddEntry("IN", "Incoming FX", "");
	enum_presetNamePrefix.AddEntry("OU", "Outcoming FX", "");
	enum_presetNamePrefix.AddEntry("NS", "Noise", "");
	
	enum_pitchUnits.AddEntry("Semitones", "Semitones", "Semitone - 12 in one octave");
	enum_pitchUnits.AddEntry("Octaves", "Octaves", "Octave - 12 semitones");
	enum_pitchUnits.AddEntry("1Hz", "1 Hz", "");
	enum_pitchUnits.AddEntry("10Hz", "10 Hz", "");
	enum_pitchUnits.AddEntry("100Hz", "100 Hz", "");
	enum_pitchUnits.AddEntry("500Hz", "500 Hz", "");
	enum_pitchUnits.AddEntry("1000Hz", "1000 Hz", "");
	enum_pitchUnits.AddEntry("2000Hz", "2000 Hz", "");

	enum_signalUnitChangeParameter.AddEntry("Rate");
	enum_signalUnitChangeParameter.AddEntry("Period");
	enum_signalUnitChangeParameter.AddEntry("Change");

	enum_signalUnitChange.AddEntry("Pitch");
	enum_signalUnitChange.AddEntry("PWM");
	enum_signalUnitChange.AddEntry("Phase");

	enum_signalUnitChangeMode.AddEntry("OneShot", "One-shot","Performs change only in the first Period");
	enum_signalUnitChangeMode.AddEntry("Loop","","Repeats the same value oscilation in each Period.");
	enum_signalUnitChangeMode.AddEntry("Mirror","","Performs change in inverse direction on every second Period.");
	enum_signalUnitChangeMode.AddEntry("Continual","","Keeps appling change, regardless Period.");

	enum_LFOFunctions.AddEntry("Triangle", "Triangle", "Starting with 0, reaching Value at middle of cycle, decreasing back to 0");
	enum_LFOFunctions.AddEntry("Down", "Ramp down", "Starting with Value, decreasing to 0");
	enum_LFOFunctions.AddEntry("Up", "Ramp up", "Starting with 0, increasing to Value");
	enum_LFOFunctions.AddEntry("Square", "Square pulse", "Half of the cycle the value is Value, other half it is 0");
	enum_LFOFunctions.AddEntry("Sine", "Sinewave", "Sine curve, starting and ending with 0");
	enum_LFOFunctions.AddEntry("Chaos", "Chaos", "CHAOS function moves from Last Target Value to Current Target Value, where New Target Value is set to random value between 0 and Spread, after each cycle(Time x Time Factor).");
	

	enum_macroControlModes.AddEntry("Normal", "Normal", "Normal macro control mode, value is settable by user via GUI or DAW automation");
	enum_macroControlModes.AddEntry("Velocity", "Velocity", "Value of the macro control is combined with note velocity");
	enum_macroControlModes.AddEntry("Pitchbend", "Pitchbend", "Value of the macro control is combined with pitchbend MIDI data");
	enum_macroControlModes.AddEntry("Aftertouch", "Aftertouch", "Value of the macro control is combined with Aftertouch MIDI data");

	folders.init();
	ioPorts.deploy();
  }
