/*
 Name:		imbAVR.ino
 Created:	8/23/2019 3:48:30 PM
 Author:	gorangrubic
*/




	#define SOUND_OUT 6
	#define _USE_DIGPOTUNITS // remove _ to turn on the option

	#ifdef USE_DIGPOTUNITS

		#define PIN_WAVEFORM_A_SHAPER A2
		#define PIN_WAVEFORM_B_FILTER A3

		#define PIN_FILTER_GAIN A0
		#define PIN_FILTER_FREQ A1

	#endif // USE_DIGPOTUNITS

	#define USE_DIGPOTCLUSTER

	#ifdef USE_DIGPOTCLUSTER 

		#define PIN_DPCLUSTER_DATA A2
		#define PIN_DPCLUSTER_LATCH A3
		#define PIN_DPCLUSTER_CLOCK A4

	#endif

	#define PIN_VOLCLUSTER_CLOCK 9
	#define PIN_VOLCLUSTER_VOL1 10
	#define PIN_VOLCLUSTER_VOL2 11
	#define PIN_VOLCLUSTER_VOL3 12

	#define SYNTHDIAG_DEVICE_ON
	#define SYNTHDIAG_DEVICE_SERIAL_RX 4
	#define SYNTHDIAG_DEVICE_SERIAL_TX 5
	#define SYNTHDIAG_DEVICE_BAUDRATE 115200

	#define READ_MIDI_USB 

	// #define READ_MIDI_SERIAL
	
	#define READ_MIDI_SERIAL_BAUDRATE 115200



#include <MIDIUSB.h>
#include <LightChrono.h>
#include "SynthDeviceControl.h"

	//#include "ADSR.h"
//#include "MathTool.h"

//#include <Chrono.h>
//#include <pitchToNote.h>
//#include <pitchToFrequency.h>
//
//#include <frequencyToNote.h>
//
//#include "SoftwareSerial.h"
//
//#include <SPI.h>
////#include "ADSRUnit.h"
//#include "DigPotUnit.h"
//#include "MidiSoundControl.h"
//#include "MonitorMessage.h"
//#include "ampControlCluster.h"
//#include "digPotCluster.h"
//#include <MIDIUSB_Defs.h>



#define ENGINE_TIMEFACTOR 2


// If 1 it plays note in given cycle duration
#define DEBUG_NOTE_PLAY 
#define DEBUG_NOTE_PITCH 36
#define DEBUG_NOTE_DURATION 500
#define DEBUG_NOTE_CYCLE_DURATION 1000




SynthDeviceControl synthDevice = SynthDeviceControl();


void setup() {

	synthDevice.setup();
	
}

void loop() {


	midiEventPacket_t rx;

#ifdef READ_MIDI_USB

	rx = MidiUSB.read();

#endif // READ_MIDI_USB

	synthDevice.loop(rx);

}



