#ifndef _MIDISOUNDCONTROL_h
#define _MIDISOUNDCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//
//#define NOTE_B0  31
//#define NOTE_C1  33
//#define NOTE_CS1 35
//#define NOTE_D1  37
//#define NOTE_DS1 39
//#define NOTE_E1  41
//#define NOTE_F1  44
//#define NOTE_FS1 46
//#define NOTE_G1  49
//#define NOTE_GS1 52
//#define NOTE_A1  55
//#define NOTE_AS1 58
//#define NOTE_B1  62
//#define NOTE_C2  65
//#define NOTE_CS2 69
//#define NOTE_D2  73
//#define NOTE_DS2 78
//#define NOTE_E2  82
//#define NOTE_F2  87
//#define NOTE_FS2 93
//#define NOTE_G2  98
//#define NOTE_GS2 104
//#define NOTE_A2  110
//#define NOTE_AS2 117
//#define NOTE_B2  123
//#define NOTE_C3  131
//#define NOTE_CS3 139
//#define NOTE_D3  147
//#define NOTE_DS3 156
//#define NOTE_E3  165
//#define NOTE_F3  175
//#define NOTE_FS3 185
//#define NOTE_G3  196
//#define NOTE_GS3 208
//#define NOTE_A3  220
//#define NOTE_AS3 233
//#define NOTE_B3  247
//#define NOTE_C4  262
//#define NOTE_CS4 277
//#define NOTE_D4  294
//#define NOTE_DS4 311
//#define NOTE_E4  330
//#define NOTE_F4  349
//#define NOTE_FS4 370
//#define NOTE_G4  392
//#define NOTE_GS4 415
//#define NOTE_A4  440
//#define NOTE_AS4 466
//#define NOTE_B4  494
//#define NOTE_C5  523
//#define NOTE_CS5 554
//#define NOTE_D5  587
//#define NOTE_DS5 622
//#define NOTE_E5  659
//#define NOTE_F5  698
//#define NOTE_FS5 740
//#define NOTE_G5  784
//#define NOTE_GS5 831
//#define NOTE_A5  880
//#define NOTE_AS5 932
//#define NOTE_B5  988
//#define NOTE_C6  1047
//#define NOTE_CS6 1109
//#define NOTE_D6  1175
//#define NOTE_DS6 1245
//#define NOTE_E6  1319
//#define NOTE_F6  1397
//#define NOTE_FS6 1480
//#define NOTE_G6  1568
//#define NOTE_GS6 1661
//#define NOTE_A6  1760
//#define NOTE_AS6 1865
//#define NOTE_B6  1976
//#define NOTE_C7  2093
//#define NOTE_CS7 2217
//#define NOTE_D7  2349
//#define NOTE_DS7 2489
//#define NOTE_E7  2637
//#define NOTE_F7  2794
//#define NOTE_FS7 2960
//#define NOTE_G7  3136
//#define NOTE_GS7 3322
//#define NOTE_A7  3520
//#define NOTE_AS7 3729
//#define NOTE_B7  3951
//#define NOTE_C8  4186
//#define NOTE_CS8 4435
//#define NOTE_D8  4699
//#define NOTE_DS8 4978
//
//static const uint16_t sNotePitches[] = {
//	NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1,
//	NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2,
//	NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
//	NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3,
//	NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4,
//	NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
//	NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5,
//	NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6,
//	NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
//	NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7,
//	NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8,
//};
//
//// Conversion from MIDI pitch codes to frequencies in Hz
static const float midiPitchFrequency[] = {
	   8.176,     8.662,     9.177,     9.723,    10.301,    10.913,    11.562,    12.250,    12.978,    13.750,    14.568,    15.434,
	  16.352,    17.324,    18.354,    19.445,    20.602,    21.827,    23.125,    24.500,    25.957,    27.500,    29.135,    30.868,
	  32.703,    34.648,    36.708,    38.891,    41.203,    43.654,    46.249,    48.999,    51.913,    55.000,    58.270,    61.735,
	  65.406,    69.296,    73.416,    77.782,    82.407,    87.307,    92.499,    97.999,   103.826,   110.000,   116.541,   123.471,
	 130.813,   138.591,   146.832,   155.563,   164.814,   174.614,   184.997,   195.998,   207.652,   220.000,   233.082,   246.942,
	 261.626,   277.183,   293.665,   311.127,   329.628,   349.228,   369.994,   391.995,   415.305,   440.000,   466.164,   493.883,
	 523.251,   554.365,   587.330,   622.254,   659.255,   698.456,   739.989,   783.991,   830.609,   880.000,   932.328,   987.767,
	1046.502,  1108.731,  1174.659,  1244.508,  1318.510,  1396.913,  1479.978,  1567.982,  1661.219,  1760.000,  1864.655,  1975.533,
	2093.005,  2217.461,  2349.318,  2489.016,  2637.020,  2793.826,  2959.955,  3135.963,  3322.438,  3520.000,  3729.310,  3951.066,
	4186.009,  4434.922,  4698.636,  4978.032,  5274.041,  5587.652,  5919.911,  6271.927,  6644.875,  7040.000,  7458.620,  7902.133,
	8372.018,  8869.844,  9397.273,  9956.063, 10548.082, 11175.303, 11839.822, 12543.854,
};
//

#pragma once
#include <stdint.h>

#ifndef MIDIUSB_h


typedef struct
{
	uint8_t header;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
} midiEventPacket_t;



#endif // !"MIDIUSB_h"



#include "MidiConfig.h"
#include "MathTool.h"




#include "ControlFunctionADSR.h"
#include "ControlFunction2PEnv.h"
#include "ControlFunctionLFO.h"
#include "ControlFunctionChaos.h"
#include "ControlFunctionCombine.h"

#include "MidiSoundControlClassBase.h"

#include "SynthState.h"

#include "spiLinkBuffer.h"
#include "SignalMacroInstruction.h"

#include "InstructionFunction.h"
#include "InstructionConstructor.h"
#include "CSFunctionStereoPan.h"


//
//class MidiSoundControlBase {
//
//public:
//
//	/*
//	* Modulation source functions:
//	* ADSR A	- Attack, Decay, Sustain, Release ENV function
//	* ADSR B	- Attack, Decay, Sustain, Release ENV function
//	* Chaos	- Random function, with time (target position change) and spread (range for target positions) parameters
//	* ENV A	- Two point (A and B; time and value) linear interpolation, looped
//	* ENV B	- Two point (A and B; time and value) linear interpolation, looped
//	* LFO A	- One point (cycle time and peak value) linear interpolation, looped
//	* LFO B	- One point (cycle time and peak value) linear interpolation, looped
//	*/
//
//	ControlFunctionADSR<CC_AmpAttack, CC_AmpDecayTime, CC_AmpRelease, CC_AmpInitLevel, CC_AmpSustainLevel> CF_ADSR_A;
//	ControlFunctionADSR<CC_FLTAttack, CC_FLTDecayTime, CC_FLTRelease, CC_FLTInitLevel, CC_FLTSustainLevel> CF_ADSR_B;
//	ControlFunctionChaos<CC_ChaosTime, CC_ChaosSpread> CF_Chaos;
//	ControlFunction2PEnv<CC_ENVA_ATime, CC_ENVA_BTime, CC_ENVA_ALevel, CC_ENVA_BLevel> CF_ENV_A;
//	ControlFunction2PEnv<CC_ENVB_ATime, CC_ENVB_BTime, CC_ENVB_ALevel, CC_ENVB_BLevel> CF_ENV_B;
//	ControlFunctionLFO<CC_LFOATime, CC_LFOATimeFactor, CC_LFOAValue> CF_LFO_A;
//	ControlFunctionLFO<CC_LFOBTime, CC_LFOBTimeFactor, CC_LFOBValue> CF_LFO_B;
//
//	/*
//	* Modulation target functions:
//	* *_ModSrc		-- assigns modulation source
//	* *_ModAmt		-- controls in what proportion the modulation function affects the controled value
//	* *_Val		-- direct value control (applied in complement proportion to *_ModAmt)
//	*/
//
//	/*
//	* CF_FLT_Cutoff	- Controls cut-off frequency at main low-pass filter circuit
//	* CF_FLT_Dist		- Controls distortion dry/wet mix for the main sound component
//	* CF_FLT_Res		- Controls resonance amount (i.e. Q factor) at main low-pass filer circuit
//	* CF_FLT_Freq		- Controls resonant frequency at main low-pass filter circuit
//	*/
//
//	ControlFunctionCombine<CC_FLT_CutOff_ModSrc, CC_FLT_CutOff_ModAmt, CC_FLT_CutOff_Val> CF_FLT_CutOff;
//	ControlFunctionCombine<CC_FLT_Dist_ModSrc, CC_FLT_Dist_ModAmt, CC_FLT_Dist_Val> CF_FLT_Dist;
//	ControlFunctionCombine<CC_FLT_Res_ModSrc, CC_FLT_Res_ModAmt, CC_FLT_Res_Val> CF_FLT_Res;
//	ControlFunctionCombine<CC_FLT_Freq_ModSrc, CC_FLT_Freq_ModAmt, CC_FLT_Freq_Val> CF_FLT_Freq;
//
//	/*
//	* CF_PERKA_Amp		- Controls volume (amplitude modulation) for PERK A square oscilator
//	* CF_PERKA_Pan		- Controls stereo position (L/R pan) for PERK A square oscilator
//	* CF_PERKB_Amp		- Controls volume (amplitude modulation) for PERK B square oscilator
//	* CF_PERKB_Pan		- Controls stereo position (L/R pan) for PERK B square oscilator
//	*/
//	ControlFunctionCombine<CC_PERKA_Amp_ModSrc, CC_PERKA_Amp_ModAmt, CC_PERKA_Amp_Val> CF_PERKA_Amp;
//	ControlFunctionCombine<CC_PERKA_Pan_ModSrc, CC_PERKA_Pan_ModAmt, CC_PERKA_Pan_Val> CF_PERKA_Pan;
//	ControlFunctionCombine<CC_PERKB_Amp_ModSrc, CC_PERKB_Amp_ModAmt, CC_PERKB_Amp_Val> CF_PERKB_Amp;
//	ControlFunctionCombine<CC_PERKB_Pan_ModSrc, CC_PERKB_Pan_ModAmt, CC_PERKB_Pan_Val> CF_PERKB_Pan;
//
//	/*
//	* CF_MAINCOMPONENT_Pan	- Controls stereo position (L/R pan) for the main component (mix of waveform A and B)
//	*/
//	ControlFunctionCombine<CC_MAINCOMPONENT_Pan_ModSrc, CC_MAINCOMPONENT_Pan_ModAmt, CC_MAINCOMPONENT_Pan_Val> CF_MAINCOMPONENT_Pan;
//
//};

#include "MonitoredArray.h"


#define CCVALUESMDF(p, v1, v2, v3) CCValues->SetValue(p##_ModSrc, v1, p##_ModAmt, v2, p##_Val, v3)

class MidiSoundControlClass : public MidiSoundControlClassBase
{
 protected:


 public:

	 /*
	* Modulation source functions:
	* ADSR A	- Attack, Decay, Sustain, Release ENV function
	* ADSR B	- Attack, Decay, Sustain, Release ENV function
	* Chaos	- Random function, with time (target position change) and spread (range for target positions) parameters
	* ENV A	- Two point (A and B; time and value) linear interpolation, looped
	* ENV B	- Two point (A and B; time and value) linear interpolation, looped
	* LFO A	- One point (cycle time and peak value) linear interpolation, looped
	* LFO B	- One point (cycle time and peak value) linear interpolation, looped
	*/

	 ControlFunctionADSR<CC_AmpAttack, CC_AmpDecayTime, CC_AmpRelease, CC_AmpInitLevel, CC_AmpSustainLevel> CF_ADSR_A;
	 ControlFunctionADSR<CC_FLTAttack, CC_FLTDecayTime, CC_FLTRelease, CC_FLTInitLevel, CC_FLTSustainLevel> CF_ADSR_B;
	 ControlFunctionChaos<CC_ChaosTime, CC_ChaosSpread, CC_ChaosTimeFactor> CF_Chaos;
	 ControlFunction2PEnv<CC_ENVA_ATime, CC_ENVA_BTime, CC_ENVA_ALevel, CC_ENVA_BLevel> CF_ENV_A;
	 ControlFunction2PEnv<CC_ENVB_ATime, CC_ENVB_BTime, CC_ENVB_ALevel, CC_ENVB_BLevel> CF_ENV_B;
	 ControlFunctionLFO<CC_LFOATime, CC_LFOATimeFactor, CC_LFOAValue> CF_LFO_A;
	 ControlFunctionLFO<CC_LFOBTime, CC_LFOBTimeFactor, CC_LFOBValue> CF_LFO_B;

	 /*
	 * Modulation target functions:
	 * *_ModSrc		-- assigns modulation source
	 * *_ModAmt		-- controls in what proportion the modulation function affects the controled value
	 * *_Val		-- direct value control (applied in complement proportion to *_ModAmt)
	 */

	 /*
	 * CF_FLT_Cutoff	- Controls cut-off frequency at main low-pass filter circuit
	 * CF_FLT_Dist		- Controls distortion dry/wet mix for the main sound component
	 * CF_FLT_Res		- Controls resonance amount (i.e. Q factor) at main low-pass filer circuit
	 * CF_FLT_Freq		- Controls resonant frequency at main low-pass filter circuit
	 */

	 ControlFunctionCombine<CC_FLT_CutOff_ModSrc, CC_FLT_CutOff_ModAmt, CC_FLT_CutOff_Val> CF_FLT_CutOff;
	 ControlFunctionCombine<CC_FLT_Dist_ModSrc, CC_FLT_Dist_ModAmt, CC_FLT_Dist_Val> CF_FLT_Dist;
	 ControlFunctionCombine<CC_FLT_Res_ModSrc, CC_FLT_Res_ModAmt, CC_FLT_Res_Val> CF_FLT_Res;
	 ControlFunctionCombine<CC_FLT_Freq_ModSrc, CC_FLT_Freq_ModAmt, CC_FLT_Freq_Val> CF_FLT_Freq;

	 /*
	 * CF_PERKA_Amp		- Controls volume (amplitude modulation) for PERK A square oscilator
	 * CF_PERKB_Amp		- Controls volume (amplitude modulation) for PERK B square oscilator
	 */
	 ControlFunctionCombine<CC_PERKA_Amp_ModSrc, CC_PERKA_Amp_ModAmt, CC_PERKA_Amp_Val> CF_PERKA_Amp;
	 ControlFunctionCombine<CC_PERKB_Amp_ModSrc, CC_PERKB_Amp_ModAmt, CC_PERKB_Amp_Val> CF_PERKB_Amp;


	 ControlFunctionCombine<CC_PERKA_Pan_ModSrc, CC_PERKA_Pan_ModAmt, CC_PERKA_Pan_Val> CF_PERKA_Pan;
	 ControlFunctionCombine<CC_PERKB_Pan_ModSrc, CC_PERKB_Pan_ModAmt, CC_PERKB_Pan_Val> CF_PERKB_Pan;


	 /*
	* CF_WFB_Shaper		- Controls waveform B shaper
	* CF_WFA_Shaper		- Controls waveform A shaper
	*/
	 ControlFunctionCombine<CC_WaveformB_Shaper_ModSrc, CC_WaveformB_Shaper_ModAmt, CC_WaveformB_Shaper_Val> CF_WFB_Shaper;
	 ControlFunctionCombine<CC_WaveformA_Shaper_ModSrc, CC_WaveformA_Shaper_ModAmt, CC_WaveformA_Shaper_Val> CF_WFA_Shaper;
	
	 /* Operation mode specific control functions */
	 ControlFunctionCombine<CC_OPM_MODA_ModSrc, CC_OPM_MODA_ModAmt, CC_OPM_MODA_Val> CF_OPM_MODA;
	 ControlFunctionCombine<CC_OPM_MODB_ModSrc, CC_OPM_MODB_ModAmt, CC_OPM_MODB_Val> CF_OPM_MODB;


	 /*
	 * CF_MAINCOMPONENT_Pan	- Controls stereo position (L/R pan) for the main component (mix of waveform A and B)
	 */
	 ControlFunctionCombine<CC_MASTER_Pan_ModSrc, CC_MASTER_Pan_ModAmt, CC_MASTER_Pan_Val> CF_MASTER_Pan;

	 
	 CSFunctionStereoPan<CS_MASTER_L_AMP, CS_MASTER_R_AMP, 100> CSF_Master_Pan;
	 CSFunctionStereoPan<CS_PERKA_L_AMP, CS_PERKA_R_AMP, 100> CSF_PERKA_Pan;
	 CSFunctionStereoPan<CS_PERKB_L_AMP, CS_PERKB_R_AMP, 100> CSF_PERKB_Pan;


	 InstructionFunction<SID_WaveformA, CID_Live, CS_WAVEFORMA_MODBYTE, CS_WAVEFORMA_PWM, CS_WAVEFORMA_PHASE> IC_WFA_Live;
	 InstructionFunction<SID_WaveformB, CID_Live, CS_WAVEFORMB_MODBYTE, CS_WAVEFORMB_PWM, CS_WAVEFORMB_PHASE> IC_WFB_Live;

	 InstructionFunction<SID_PerkA, CID_Live, CS_PERKA_MODBYTE, CS_PERKA_PWM, CS_PERKA_PHASE> IC_PERKA_Live;
	 InstructionFunction<SID_PerkB, CID_Live, CS_PERKB_MODBYTE, CS_PERKB_PWM, CS_PERKB_PHASE> IC_PERKB_Live;

	 InstructionConstructor<SID_Master, CID_NoteControl> IC_MASTER_NoteControl;

	 InstructionConstructorPreset<SID_FLT_Freq> ICP_FLT_Freq;
	 InstructionConstructorPreset<SID_WaveformA> ICP_WFA;
	 InstructionConstructorPreset<SID_WaveformB> ICP_WFB;
	 InstructionConstructorPreset<SID_PerkA> ICP_PERKA;
	 InstructionConstructorPreset<SID_PerkB> ICP_PERKB;


	 /// <summary>
	 /// Adds the instruction to linkBuffer -- if its not empty instruction
	 /// </summary>
	 /// <param name="instruction">The instruction.</param>
	 void AddInstructionToBuffer(SignalMacroInstruction instruction);

	 
	 /// <summary>
	 /// Current Operation Mode  identifier
	 /// </summary>
	 byte opm_current_id = 0;

	 SynthState State;

	 spiLinkBuffer<SignalMacroInstruction, 20> linkBuffer;

	 unsigned long NoteOnTime;

	 unsigned long NoteOffTime=0;

	// float tone_pitch = 0;
	// bool tone_on = false;
	 byte tone_velocity = 100;
	
	 
	 void setOperationMode(byte opm_id, CCValuesType * CCValues);

	 void setPreset(byte presetID, CCValuesType * CCValues);

	 void noteOn(byte channel, byte pitch, byte velocity);

	 void noteOff(byte channel, byte pitch, byte velocity);

	 void controlChange(byte channel, byte control, byte value);

	 /// <summary>
	 /// Receives a system message
	 /// </summary>
	 /// <param name="sysMsg">The system MSG.</param>
	 /// <param name="paramA">The parameter a.</param>
	 /// <param name="paramB">The parameter b.</param>
	 void systemMessage(byte sysMsg, byte paramA, byte paramB);

	 void ApplyControls();

	 String DescribeState();

	 unsigned int DoTick();


	 unsigned int time_factor = 2;
	 byte gate_margin = 5;


	 byte channel_id = 0;

};

// extern MidiSoundControlClass MidiSoundControl;

#endif
