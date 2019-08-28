/*
 Name:		imbAVR.ino
 Created:	8/23/2019 3:48:30 PM
 Author:	gorangrubic
*/

// the setup function runs once when you press reset or power the board



#include "ADSR.h"
#include "MathTool.h"
#include <LightChrono.h>
#include <Chrono.h>
#include <pitchToNote.h>
#include <pitchToFrequency.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>
#include <frequencyToNote.h>

#include "SoftwareSerial.h"

#include <SPI.h>
#include "ADSRUnit.h"
#include "DigPotUnit.h"
#include "MidiSoundControl.h"
#include "MonitorMessage.h"
#include "ampControlCluster.h"
#include "digPotCluster.h"

//#define LED 8
#define SOUND_OUT 6

#define PIN_WAVEFORM_A_SHAPER A2
#define PIN_WAVEFORM_B_FILTER A3

#define PIN_FILTER_GAIN A0
#define PIN_FILTER_FREQ A1




#define SERIAL_ON
#define SERIAL_BAUD_RATE 115200

#define Engine_Tick 500
Chrono Engine_Chrono = Chrono();


DigPotUnitClass dp_waveform_a_shaper = DigPotUnitClass(PIN_WAVEFORM_A_SHAPER);
DigPotUnitClass dp_waveform_b_flt = DigPotUnitClass(PIN_WAVEFORM_B_FILTER);

DigPotUnitClass dp_filter = DigPotUnitClass(PIN_FILTER_FREQ);
DigPotUnitClass dp_filter_gain = DigPotUnitClass(PIN_FILTER_GAIN);

//

//
//// 5

// DigPotUnitClass dp_waveform_mix = DigPotUnitClass(PIN_WAVEFORM_MIX);
//DigPotUnitClass dp_master_amp = DigPotUnitClass(PIN_MASTER_AMP);


// CH0 --> waveform_a_shaper
// CH1 --> waveform_b_filter
// CH2 --> empty
// CH3 --> empty
// CH4 --> empty

//digPotCluster dp_cluster = digPotCluster();


// vol1 --> master amp
// vol2 --> waveform mixer (A/B)
// vol3 --> empty
ampControlCluster vol_cluster = ampControlCluster();

MidiSoundControlClass mainControl = MidiSoundControlClass();
SoftwareSerial PortTwo = SoftwareSerial(4, 5);

void setup() {

	SPI.begin();

	//master_amp.init(8, 2);




	//SPI.beginTransaction(SPISettings.)
	// mainControl.time_factor = 10 / Engine_Tick;
	pinMode(SOUND_OUT, OUTPUT);
	mainControl.time_factor = 2;
	//mainControl.ADSR_Amp.IsDebugOn = false;
	//mainControl.ADSR_Filter.IsDebugOn = false;
	mainControl.setPreset(1);
	mainControl.ApplyControls();


	vol_cluster.init(9, 8, 7, 10);

	

	//dp_cluster.init(3, 2, A3);

#ifdef SERIAL_ON

	Serial.begin(SERIAL_BAUD_RATE);
	PortTwo.begin(SERIAL_BAUD_RATE);
#endif // SERIAL_ON


	tone(SOUND_OUT, 220, 200);
	delay(200);
	tone(SOUND_OUT, 110, 500);
	delay(500);

	//dp_cluster.Debug();
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

byte Data[MonitorMessageSize_Bytes];

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
		case  0xF:

			mainControl.systemMessage(rx.byte1 & 0xF, rx.byte2, rx.byte3);
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

	
	unsigned int cT = mainControl.DoTick();

	
	//dp_amp.Write(mainControl.out_amp_value);
	
	
	//dp_dist_mix.Write(mainControl.out_mod_value);

	//dp_master_amp.Write(mainControl.State.out_amp_value);

	//dp_cluster.Write(mainControl.State.out_waveform_a_shaper, mainControl.State.out_waveform_b_flt, mainControl.State.out_amp_value, mainControl.State.out_flt_value, mainControl.State.out_flt_gain, 0, 0, 0);

	float wf_mix_ratio = MathTool::GetRatio(mainControl.State.out_waveform_mix, 100, 1, 0);
	


	vol_cluster.setVolume(mainControl.State.out_amp_value, mainControl.State.out_amp_value, 50 + (wf_mix_ratio * 50), 100 - (wf_mix_ratio * 50), 100, 100);

	dp_waveform_b_flt.Write(mainControl.State.out_waveform_b_flt);
	dp_waveform_a_shaper.Write(mainControl.State.out_waveform_a_shaper);

	
	dp_filter_gain.Write(mainControl.State.out_flt_gain);
	dp_filter.Write(mainControl.State.out_flt_value);

	/*
	dp_waveform_mix.Write(mainControl.State.out_waveform_mix);
	
	master_amp.setBoth(mainControl.State.out_amp_value);
	*/

	if (mainControl.tone_on) {
		tone(SOUND_OUT, mainControl.tone_pitch);
	}
	else {
		noTone(SOUND_OUT);
	}
	
	
	

	

	//Serial.write((const char*)msg, sizeof(MonitorMessage));  // 2 bytes.

	if (Engine_Chrono.hasPassed(Engine_Tick)) {

	
#ifdef SERIAL_ON


		for (size_t i = 0; i < MonitorMessageHeaderSize; i++)
		{
			PortTwo.write(MonitorMessageStartChar);
		}

		MonitorMessage msg;

		msg.State = mainControl.State; // .CCValues = mainControl.CCValues;
		msg.cT = cT;
		msg.SerialWrite(Data);

		for (size_t i = 0; i < MonitorMessageSize_Bytes; i++)
		{
			PortTwo.write(Data[i]);
		}

#endif // SERIAL_ON

		Engine_Chrono.restart();

	}

}



