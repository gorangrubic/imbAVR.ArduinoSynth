



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

#define SIGNAL_DEVICE_SERIAL_RX 8
#define SIGNAL_DEVICE_SERIAL_TX 9
#define SIGNAL_DEVICE_BAUDRATE 38400

#include "TwoPointENV.h"


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
// #define DEBUG_NOTE_PLAY 
#define DEBUG_NOTE_PITCH 36
#define DEBUG_NOTE_DURATION 500
#define DEBUG_NOTE_CYCLE_DURATION 1000


#include <MIDIUSB.h>
#include <LightChrono.h>
#include "SynthDeviceControl.h"

SoftwareSerial SoftSerial(SIGNAL_DEVICE_SERIAL_RX, SIGNAL_DEVICE_SERIAL_TX);

SynthDeviceControl synthDevice = SynthDeviceControl();


void setup() {

	synthDevice.setup();
	Serial.begin(SIGNAL_DEVICE_BAUDRATE);
	SoftSerial.begin(SIGNAL_DEVICE_BAUDRATE);
	
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
	synthDevice.loop(rx, &SoftSerial);

	SoftSerial.flush();

	if (Engine_Chrono.hasPassed(EngineTICK)) {

		/*Serial.println(SignalControlManagerClass::Describe(synthDevice.mainControl.signalA_instruction, 0));
		Serial.println(SignalControlManagerClass::Describe(synthDevice.mainControl.signalB_instruction, 1));
		Serial.println(SignalControlManagerClass::Describe(synthDevice.mainControl.signalFLT_instruction, 2));
		Serial.println(SignalControlManagerClass::Describe(synthDevice.mainControl.perkA_instruction, 3));
		Serial.println(SignalControlManagerClass::Describe(synthDevice.mainControl.perkB_instruction, 4));

		synthDevice.mainControl.signalA_instruction.clearCache();
		synthDevice.mainControl.signalB_instruction.clearCache();
		synthDevice.mainControl.signalFLT_instruction.clearCache();
		synthDevice.mainControl.perkA_instruction.clearCache();
		synthDevice.mainControl.perkB_instruction.clearCache();
		*/

		Engine_Chrono.restart();
	}
	
	




#endif // READ_MIDI_USB



	

}
