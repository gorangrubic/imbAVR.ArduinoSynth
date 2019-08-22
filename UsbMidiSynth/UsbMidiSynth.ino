/*
 * Simple USBMIDI synth v0.2
 *
 * Plays MIDI notes using square waves on SNDOUT pin
 * Attach piezo or audio amplifier to that pin and send some notes to it
 * Can only play one note at time
 * Tested on Brmlab Leonardo
 *
 * (c) Tomas 'harvie' Mudrunka 2019
 */


#include "SoftwareSerial.h"

#include <pitchToNote.h>
#include <pitchToFrequency.h>
#include "pitchToFrequency.h"
#include <MIDIUSB_Defs.h>
#include <frequencyToNote.h>

#include <inttypes.h>



#include "ADSRUnit.h"
#include "DigPotUnit.h"



#include "MIDIUSB.h"


#include  "Chrono.h"

#include "SPI.h"


#include "MidiSoundControl.h"

const int DIGPOT_FILTER_CS_PIN = 20;
const int DIGPOT_AMP_CS_PIN = 19;


#define LED 8
// #define SNDOUT 3 //Audio output pin

#define SOUND_OUT_1 6

//#define SOUND_OUT_2 9
//#define SOUND_OUT_3 10

#define TEST_TONE 64

//
//#define MON_RX 4
//#define MON_TX 5



#define BAUDRATE 115200

#define MIDI_NOTE_OFF   0b10000000
#define MIDI_NOTE_ON    0b10010000
#define MIDI_CONTROL    0b10110000
#define MIDI_PITCH_BEND 0b11100000

#include "EnvUnit.h"
// #define DEBUG_MODE

#ifdef DEBUG_MODE

Chrono DEBUG_Chrono;
bool DEBUG_NoteOn;
#define DEBUG_Tick 250
#define DEBUG_Pitch 36
#define DEBUG_Volume 50


#endif // DEBUG_MODE

#define Engine_Tick 10
Chrono Engine_Chrono = Chrono();

#include "ADSRUnit.h"

DigPotUnitClass dp_waveform_a_shaper = DigPotUnitClass(A0);
DigPotUnitClass dp_filter_gain = DigPotUnitClass(A2);
DigPotUnitClass dp_filter = DigPotUnitClass(A3);
// A2 - resonance
// A3 cut off


// 5
DigPotUnitClass dp_waveform_b_flt = DigPotUnitClass(5);


DigPotUnitClass dp_waveform_mix = DigPotUnitClass(3);

DigPotUnitClass dp_master_amp = DigPotUnitClass(4);



// DigPotUnitClass dp_waveform_a_shape = DigPotUnitClass(5);




// DigPotUnitClass dp_master_RESERVE = DigPotUnitClass(7);
// DigPotUnitClass dp_master_RESERVE = DigPotUnitClass(2);


//DigPotUnitClass dp_dist_mix = DigPotUnitClass(A2);




//SoftwareSerial portTwo(MON_RX, MON_TX);

MidiSoundControlClass mainControl = MidiSoundControlClass();

bool led_toggle = false;

void ledToggle() {

	if (led_toggle) {
		digitalWrite(LED, HIGH);
	}
	else {
		digitalWrite(LED, LOW);
	}
	led_toggle = !led_toggle;

}

uint16_t OUTPUT_PIN = SOUND_OUT_1;

//void noteOn(byte channel, byte pitch, byte velocity) {
//	mainControl.noteOn(channel, pitch, velocity);
//	
//	//tone(OUTPUT_PIN, mainControl.tone_pitch);
//	
//
//
//}
//
//void noteOff(byte channel, byte pitch, byte velocity) {
//
//	mainControl.noteOff(channel, pitch, velocity);
//
//	
//
//
//}
//
//void controlChange(byte channel, byte control, byte value) {
//	
//	mainControl.controlChange(channel, control, value);
//
//}




const char* pitch_name(byte pitch) {
	static const char* names[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
	return names[pitch % 12];
}

int pitch_octave(byte pitch) {
	return (pitch / 12) - 1;
}

bool LEDSTATE = true;





void setup() {
  
  SPI.begin();

  // mainControl.time_factor = 10 / Engine_Tick;

  mainControl.ApplyControls();

  tone(SOUND_OUT_1, 220, 200);
  delay(200);
  tone(SOUND_OUT_1, 110, 500);
  delay(500);
  

#ifdef DEBUG_MODE

  mainControl.ADSR_Amp.IsDebugOn = true;
  mainControl.ADSR_Filter.IsDebugOn = false;

  tone(SOUND_OUT_1, 220, 200);
  delay(200);
  tone(SOUND_OUT_1, 110, 500);
  delay(500);


#else
  mainControl.ADSR_Amp.IsDebugOn = false;
  mainControl.ADSR_Filter.IsDebugOn = false;

#endif

  Serial.begin(BAUDRATE);
  //portTwo.begin(BAUDRATE);

  pinMode(LED, OUTPUT);

  //portTwo.print("Start");
}

void loop() {
  

#ifdef DEBUG_MODE

	if (DEBUG_Chrono.hasPassed(DEBUG_Tick)) {
		DEBUG_Chrono.restart(); // Restart the chronometer.

		if (!DEBUG_NoteOn) {

			mainControl.noteOn(1 & 0xF, DEBUG_Pitch, DEBUG_Volume);
			tone(SOUND_OUT_1, 220, 500);

			//noteOn(
			//	1 & 0xF,  //channel
			//	DEBUG_Pitch,        //pitch
			//	DEBUG_Volume        //velocity
			//);

		}
		else {

			mainControl.noteOff(1 & 0xF, DEBUG_Pitch, DEBUG_Volume);

			//noteOff(
			//	1 & 0xF,  //channel
			//	DEBUG_Pitch,        //pitch
			//	DEBUG_Volume         //velocity
			//);
		}

		DEBUG_NoteOn = !DEBUG_NoteOn;
		// Do something here...
	}

#endif // DEBUG_MODE

	
	

	midiEventPacket_t rx;

	do {


		rx = MidiUSB.read();

		switch (rx.header) {
		case 0:
			break; //No pending events

		case 0x9:

			mainControl.noteOn(rx.byte1 & 0xF, rx.byte2, rx.byte3);
		
			ledToggle();
			//noteOn(
			//	rx.byte1 & 0xF,  //channel
			//	rx.byte2,        //pitch
			//	rx.byte3         //velocity
			//);
			break;

		case 0x8:

			mainControl.noteOff(rx.byte1 & 0xF, rx.byte2, rx.byte3);
			
			//noteOff(
			//	rx.byte1 & 0xF,  //channel
			//	rx.byte2,        //pitch
			//	rx.byte3         //velocity
			//);
			break;

		case 0xB:

			mainControl.controlChange(rx.byte1 & 0xF, rx.byte2, rx.byte3);

			
			//controlChange(
			//	rx.byte1 & 0xF,  //channel
			//	rx.byte2,        //control
			//	rx.byte3         //value
			//);
			break;
		//case B1111:

		//	// system common messages
		//	mainControl.systemMessage(rx.byte1, rx.byte2, rx.byte3);
		//	break;

		//default:
			//portTwo.print("Unhandled MIDI message: ");
			//portTwo.print(rx.header, HEX);
			//portTwo.print("-");
			//portTwo.print(rx.byte1, HEX);
			//portTwo.print("-");
			//portTwo.print(rx.byte2, HEX);
			//portTwo.print("-");
			//portTwo.println(rx.byte3, HEX);
		}

	} while (rx.header != 0);


	if (Engine_Chrono.hasPassed(Engine_Tick)) {

		mainControl.DoTick();


		//dp_amp.Write(mainControl.out_amp_value);
		//dp_filter.Write(mainControl.out_flt_value);
		//dp_dist_mix.Write(mainControl.out_mod_value);

	/*	dp_master_amp.Write(mainControl.out_amp_value);
		dp_filter_gain.Write(mainControl.out_flt_gain);
		dp_filter.Write(mainControl.out_flt_value);

		dp_waveform_b_flt.Write(mainControl.out_waveform_b_flt);
		dp_waveform_a_shaper.Write(mainControl.out_waveform_a_shaper);
		dp_waveform_mix.Write(mainControl.out_waveform_mix);

*/
		if (mainControl.ADSR_Amp.CurrentState == ADSRUnitState::off) {
			// noTone(OUTPUT_PIN);
		}
		else {
			tone(OUTPUT_PIN, mainControl.tone_pitch);
		}


		Engine_Chrono.restart();

	}
}
