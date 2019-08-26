/*
 Name:		imbAVR.ino
 Created:	8/23/2019 3:48:30 PM
 Author:	gorangrubic
*/

// the setup function runs once when you press reset or power the board
#include <LightChrono.h>
#include <Chrono.h>
#include <pitchToNote.h>
#include <pitchToFrequency.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>
#include <frequencyToNote.h>

#include <SPI.h>
#include "ADSRUnit.h"
#include "DigPotUnit.h"
#include "MidiSoundControl.h"

//#define LED 8
#define SOUND_OUT 6

#define PIN_WAVEFORM_A_SHAPER A0
#define PIN_FILTER_GAIN A2
#define PIN_FILTER_FREQ A3

#define PIN_WAVEFORM_B_FILTER 5
#define PIN_WAVEFORM_MIX 9
#define PIN_MASTER_AMP 8


#define Engine_Tick 5
Chrono Engine_Chrono = Chrono();

DigPotUnitClass dp_waveform_a_shaper = DigPotUnitClass(PIN_WAVEFORM_A_SHAPER);
DigPotUnitClass dp_filter_gain = DigPotUnitClass(PIN_FILTER_GAIN);
DigPotUnitClass dp_filter = DigPotUnitClass(PIN_FILTER_FREQ);

// 5
DigPotUnitClass dp_waveform_b_flt = DigPotUnitClass(PIN_WAVEFORM_B_FILTER);
DigPotUnitClass dp_waveform_mix = DigPotUnitClass(PIN_WAVEFORM_MIX);
DigPotUnitClass dp_master_amp = DigPotUnitClass(PIN_MASTER_AMP);


MidiSoundControlClass mainControl = MidiSoundControlClass();

void setup() {

	SPI.begin();

	// mainControl.time_factor = 10 / Engine_Tick;
	pinMode(SOUND_OUT, OUTPUT);
	mainControl.time_factor = 2;
	mainControl.ADSR_Amp.IsDebugOn = false;
	mainControl.ADSR_Filter.IsDebugOn = false;
	mainControl.setPreset(1);
	mainControl.ApplyControls();

	tone(SOUND_OUT, 220, 200);
	delay(200);
	tone(SOUND_OUT, 110, 500);
	delay(500);

}

//bool led_toggle = false;
//
//void ledToggle() {
//
//	if (led_toggle) {
//		digitalWrite(LED, HIGH);
//	}
//	else {
//		digitalWrite(LED, LOW);
//	}
//	led_toggle = !led_toggle;
//
//}


// the loop function runs over and over again until power down or reset
void loop() {
  



	midiEventPacket_t rx;

	do {


		rx = MidiUSB.read();

		switch (rx.header) {
		case 0:
			break; //No pending events
		case 0x9:
			mainControl.noteOn(rx.byte1 & 0xF, rx.byte2, rx.byte3);
			

			//ledToggle();
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

		if (mainControl.tone_on) {
			tone(SOUND_OUT, mainControl.tone_pitch);
		}
		else {
			//
		}
		//dp_amp.Write(mainControl.out_amp_value);
		//dp_filter.Write(mainControl.out_flt_value);
		//dp_dist_mix.Write(mainControl.out_mod_value);

		dp_master_amp.Write(mainControl.out_amp_value);
		dp_filter_gain.Write(mainControl.out_flt_gain);
		dp_filter.Write(mainControl.out_flt_value);

		dp_waveform_b_flt.Write(mainControl.out_waveform_b_flt);
		dp_waveform_a_shaper.Write(mainControl.out_waveform_a_shaper);
		dp_waveform_mix.Write(mainControl.out_waveform_mix);


	    if (mainControl.ADSR_Amp.CurrentState == ADSRUnitState::off) {
			noTone(SOUND_OUT);
		} else {
			
		}


		Engine_Chrono.restart();

	}

}
