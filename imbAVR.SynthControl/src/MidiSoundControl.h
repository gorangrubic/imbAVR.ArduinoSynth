// MidiSoundControl.h

#ifndef _MIDISOUNDCONTROL_h
#define _MIDISOUNDCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif





#include "ADSR.h"
#include "SynthState.h"


#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

static const uint16_t sNotePitches[] = {
	NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1,
	NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2,
	NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
	NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3,
	NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4,
	NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
	NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5,
	NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6,
	NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
	NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7,
	NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8,
};

// Conversion from MIDI pitch codes to frequencies in Hz
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

#include "TwoPointENV.h"


#define signalA_SID 4
#define signalB_SID 3
#define signalFLT_SID 2
#define perkA_SID 0
#define perkB_SID 1



class MidiSoundControlClass
{
 protected:


 public:

	 SynthState State;

	 SignalInstruction signalA_instruction;
	 SignalInstruction signalB_instruction;

	 SignalInstruction signalFLT_instruction;

	 SignalInstruction perkA_instruction;
	 SignalInstruction perkB_instruction;


	// byte CCValues[127]; 

	 unsigned long NoteOnTime;

	 unsigned long NoteOffTime=0;

	 float tone_pitch = 0;
	 bool tone_on = false;
	 byte tone_velocity = 100;
	// byte amp_ChannelVolume = 127;

	 byte gate_margin = 5;

	 void setPreset(byte presetID);

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

	 //ADSRUnitClass ADSR_Filter = ADSRUnitClass();
	 //ADSRUnitClass ADSR_Amp = ADSRUnitClass();
	 
	 ADSRFunction ADSR_Amp = ADSRFunction();
	 ADSRFunction ADSR_Filter = ADSRFunction();

	 TwoPointENV ENV_PerkAmp = TwoPointENV();
	 TwoPointENV ENV_PerkPitch = TwoPointENV();

	 

	 unsigned int time_factor = 2;


	// byte out_amp_value = 0;
	// byte out_flt_value = 64;
	// byte out_flt_gain = 0;
	 

	// byte out_waveform_b_flt = 0;
	// byte out_waveform_a_shaper = 0;

	// byte out_waveform_mix = 0;


	 byte channel_id = 0;


	void init();
};

// extern MidiSoundControlClass MidiSoundControl;

#endif
