#pragma once

#include "ADSR.h"
#include "MathTool.h"
#include <LightChrono.h>
#include <MIDI.h>
#include <SoftwareSerial.h>

#include <SignalControlManager.h>
#include <SignalControlUnit.h>


#include <SPI.h>

#include "DigPotUnit.h"
#include "MidiSoundControl.h"
#include "MonitorMessage.h"
#include "ampControlCluster.h"
#include "digPotCluster.h"

#include "spiSender.h"
#include "SignalMacroInstruction.h"

//#ifndef SOUND_OUT


//#define SOUND_OUT 10
//
//	#define _USE_DIGPOTUNITS // remove _ to turn on the option
//
//	#ifdef USE_DIGPOTUNITS
//
//		#define PIN_WAVEFORM_A_SHAPER A2
//		#define PIN_WAVEFORM_B_FILTER A3
//
//		#define PIN_FILTER_GAIN A0
//		#define PIN_FILTER_FREQ A1
//
//	#endif // USE_DIGPOTUNITS
//
//	#define USE_DIGPOTCLUSTER
//
//	#ifdef USE_DIGPOTCLUSTER 
//
//		#define PIN_DPCLUSTER_DATA 2
//		#define PIN_DPCLUSTER_LATCH 3
//		#define PIN_DPCLUSTER_CLOCK 4
//
//	#endif
//
//#define PIN_VOLCLUSTER_CLOCK A1
//#define PIN_VOLCLUSTER_VOL1 9
//#define PIN_VOLCLUSTER_VOL2 A2
//#define PIN_VOLCLUSTER_VOL3 10
//
//#define SYNTHDIAG_DEVICE_ON
//#define SYNTHDIAG_DEVICE_SERIAL_RX 5
//#define SYNTHDIAG_DEVICE_SERIAL_TX 6
//#define SYNTHDIAG_DEVICE_BAUDRATE 115200
//
//
//#define SIGNAL_DEVICE_SERIAL_RX 7
//#define SIGNAL_DEVICE_SERIAL_TX 8
//#define SIGNAL_DEVICE_BAUDRATE 57600
//
//// #define READ_MIDI_USB 
//
//#define READ_MIDI_SERIAL
//#define READ_MIDI_SERIAL_BAUDRATE 115200
//
//
//// If 1 it plays note in given cycle duration
//// #define DEBUG_NOTE_PLAY 
//#define DEBUG_NOTE_PITCH 36
//#define DEBUG_NOTE_DURATION 500
//#define DEBUG_NOTE_CYCLE_DURATION 1000
//
//#endif // !SOUND_OUT
//
//
//
//
//
//// #define READ_MIDI_USB 
//
////#define READ_MIDI_SERIAL
//
//#define READ_MIDI_SERIAL_BAUDRATE 31250
//#define READ_MIDI_SERIAL_RX A6
//#define READ_MIDI_SERIAL_TX A7

#define USE_DIGPOTCLUSTER

#ifdef USE_DIGPOTCLUSTER 

#define PIN_DPCLUSTER_DATA 2
#define PIN_DPCLUSTER_LATCH 3
#define PIN_DPCLUSTER_CLOCK 4

#endif

#define PIN_VOLCLUSTER_CLOCK A1

// A3 is waveform mix
#define PIN_VOLCLUSTER_VOL1 A3

// A2 Perk stereo mix
#define PIN_VOLCLUSTER_VOL2 A2

// final amp modulation
#define PIN_VOLCLUSTER_VOL3 A0

#define SYNTHDIAG_DEVICE_ON
#define SYNTHDIAG_DEVICE_SERIAL_RX 10
#define SYNTHDIAG_DEVICE_SERIAL_TX 7
#define SYNTHDIAG_DEVICE_BAUDRATE 57600

#define READ_MIDI_USB 

// #define READ_MIDI_SERIAL

#define READ_MIDI_SERIAL_BAUDRATE 115200



#define ENGINE_TIMEFACTOR 2






#define Engine_Tick 500




class SynthDeviceControl
{
public:

	spiSender<SignalMacroInstruction> SignalGeneratorLink;

	//SignalControlLink link;
	

	LightChrono Engine_Chrono = LightChrono();

	LightChrono MidiRead_Chrono = LightChrono();


#ifdef DEBUG_NOTE_PLAY

	LightChrono DebugNote_Chrono = LightChrono();

#endif // DEBUG_NOTE_PLAY





#ifdef USE_DIGPOTCLUSTER

	// CH0 --> waveform_a_shaper
	// CH1 --> waveform_b_filter
	// CH2 --> empty
	// CH3 --> empty
	// CH4 --> empty

	digPotCluster dp_cluster = digPotCluster();

#endif // USE_DIGPOTCLUSTER


	// vol1 --> PERKA L/R
	// vol2 --> PERKB L/R
	// vol3 --> MASTER L/R
	ampControlCluster vol_cluster = ampControlCluster();

	MidiSoundControlClass mainControl = MidiSoundControlClass();

#ifdef READ_MIDI_SERIAL

	//SoftwareSerial PortMidi = SoftwareSerial(READ_MIDI_SERIAL_RX, READ_MIDI_SERIAL_TX);
#endif // READ_MIDI_SERIAL


#ifdef SYNTHDIAG_DEVICE_ON

	//SoftwareSerial PortTwo = SoftwareSerial(SYNTHDIAG_DEVICE_SERIAL_RX, SYNTHDIAG_DEVICE_SERIAL_TX);

#endif // SERIAL_ON

	byte Data[MonitorMessageSize_Bytes];


	


	SynthDeviceControl();
	~SynthDeviceControl();
	void setup();
	String DescribeMidi(midiEventPacket_t rx);

	void loop(midiEventPacket_t rx);

	
	




};

