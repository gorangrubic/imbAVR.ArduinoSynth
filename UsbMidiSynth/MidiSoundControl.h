// MidiSoundControl.h

#ifndef _MIDISOUNDCONTROL_h
#define _MIDISOUNDCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "SoftwareSerial.h"
#include "ADSRUnit.h"
#include "pitchToFrequency.h"

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



#define MIDIMSG_SystemEx		B11110000
#define MIDIMSG_SystemExEnd		B11110111

#define MIDIMSG_Timecode		B11110001
#define MIDIMSG_TuneRequest		B11110110


#define CC_ChannelVolume 01
#define CC_Balance 8

#define CC_WaveformA_Shaper 4
#define CC_WaveformB_Filter 3


#define CC_WaveformMix 13

#define CC_Cutoff 29
#define CC_Resonance 21



#define CC_AmpAttack 33

#define CC_AmpDecayTime 25
#define CC_AmpRelease 17


#define CC_AmpInitLevel 32
#define CC_AmpSustainLevel 24



#define CC_FLTAttack 31
#define CC_FLTDecayTime 23
#define CC_FLTRelease 15

#define CC_FLTInitLevel 30
#define CC_FLTSustainLevel 22
#define CC_FLT_ADSR_Mix 14



#define CHANNEL_ID_ALL 0





class MidiSoundControlClass
{
 protected:


 public:


	 byte CCValues[127]; 


	 float tone_pitch = 0;
	 bool tone_on = false;
	 byte tone_velocity = 100;
	// byte amp_ChannelVolume = 127;


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

	 void DoTick();

	 ADSRUnitClass ADSR_Filter = ADSRUnitClass();
	 ADSRUnitClass ADSR_Amp = ADSRUnitClass();

	 //byte flt_Cutoff = 64;
	 //byte flt_ADSR_Mix =64;

	 unsigned int time_factor = 2;

	// unsigned int flt_AttackTime = 10;
	// unsigned int flt_DecayTime = 2;
	// unsigned int flt_ReleaseTime = 10;
	// byte flt_InitLevel = 50;
	// byte flt_SustainLevel = 20;

	// unsigned int amp_AttackTime = 3;
	// unsigned int amp_DecayTime = 10;
	// unsigned int amp_ReleaseTime = 10;
	// byte amp_InitLevel = 10;
	// byte amp_SustainLevel = 90;


	// byte fx_Shaper = 64;
	// byte fx_Modulation = 64;

	// byte amp_Balance = 127;
	

	 byte out_amp_value = 0;
	 byte out_flt_value = 64;
	 byte out_flt_gain = 0;
	 

	 byte out_waveform_b_flt = 0;
	 byte out_waveform_a_shaper = 0;

	 byte out_waveform_mix = 0;


	 //byte out_mod_value = 0;

	 byte channel_id = 0;

	 //void controlChange(byte channel, byte control, byte value);

	void init();
};

extern MidiSoundControlClass MidiSoundControl;

#endif

