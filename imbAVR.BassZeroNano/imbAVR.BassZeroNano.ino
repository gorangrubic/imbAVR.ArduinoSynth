/*
 Name:		imbAVR.ino
 Created:	8/29/2019 3:57:08 AM
 Author:	gorangrubic
*/




#define SOUND_OUT 10
// #define USE_DIGPOTUNITS // remove _ to turn on the option

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

#define PIN_VOLCLUSTER_CLOCK 5
#define PIN_VOLCLUSTER_VOL1 4
#define PIN_VOLCLUSTER_VOL2 3
#define PIN_VOLCLUSTER_VOL3 2

#define SYNTHDIAG_DEVICE_ON
#define SYNTHDIAG_DEVICE_SERIAL_RX 7
#define SYNTHDIAG_DEVICE_SERIAL_TX 6
#define SYNTHDIAG_DEVICE_BAUDRATE 115200

// #define READ_MIDI_USB 

#define READ_MIDI_SERIAL

#define READ_MIDI_SERIAL_BAUDRATE 115200

#define ENGINE_TIMEFACTOR 2


// If 1 it plays note in given cycle duration
#define DEBUG_NOTE_PLAY 
#define DEBUG_NOTE_PITCH 36
#define DEBUG_NOTE_DURATION 500
#define DEBUG_NOTE_CYCLE_DURATION 1000

#include "SynthDeviceControl.h"


SynthDeviceControl synthDevice = SynthDeviceControl();


void setup() {

	synthDevice.setup();

}

void loop() {


	midiEventPacket_t rx;



	synthDevice.loop(rx);

}

