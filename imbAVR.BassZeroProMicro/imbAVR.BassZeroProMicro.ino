



//#define SOUND_OUT 6


#define _USE_DIGPOTUNITS // remove _ to turn on the option



#define USE_DIGPOTCLUSTER

#ifdef USE_DIGPOTCLUSTER 

#define PIN_DPCLUSTER_DATA 2
#define PIN_DPCLUSTER_LATCH 3
#define PIN_DPCLUSTER_CLOCK 4

#endif

//#define PIN_VOLCLUSTER_CLOCK A1
//#define PIN_VOLCLUSTER_VOL1 A2
//#define PIN_VOLCLUSTER_VOL2 A0
//#define PIN_VOLCLUSTER_VOL3 A3

#define SYNTHDIAG_DEVICE_ON
#define SYNTHDIAG_DEVICE_SERIAL_RX 10
#define SYNTHDIAG_DEVICE_SERIAL_TX 7
#define SYNTHDIAG_DEVICE_BAUDRATE 57600

#define READ_MIDI_USB 

// #define READ_MIDI_SERIAL

#define READ_MIDI_SERIAL_BAUDRATE 115200


#define ENGINE_TIMEFACTOR 2


// If 1 it plays note in given cycle duration
// #define DEBUG_NOTE_PLAY 
#define DEBUG_NOTE_PITCH 36
#define DEBUG_NOTE_DURATION 500
#define DEBUG_NOTE_CYCLE_DURATION 1000


#include <MIDIUSB.h>
#include <LightChrono.h>
#include "SynthDeviceControl.h"


SynthDeviceControl synthDevice = SynthDeviceControl();


void setup() {

	synthDevice.setup();
	Serial.begin(SYNTHDIAG_DEVICE_BAUDRATE);
	
	//SoftSerial.begin(SIGNAL_DEVICE_BAUDRATE);
	
}


LightChrono Engine_Chrono = LightChrono();
#define EngineTICK 5000

byte lastControl = 0;
void loop() {


	midiEventPacket_t rx;

#ifdef READ_MIDI_USB

	rx = MidiUSB.read();

	/*while (SoftSerial.available()) {
		SoftSerial.read();
	}

	while (Serial.available()) {
		Serial.read();
	}
*/
	synthDevice.loop(rx);

	

#endif // READ_MIDI_USB



	

}
