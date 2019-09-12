// DiagnosticDeviceManager.h



#ifndef _DIAGNOSTICDEVICEMANAGER_h
#define _DIAGNOSTICDEVICEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//
//#include ""
//#include "DevicePort.h"
//
//#include "DeviceSignature.h"
//#include "DiagnosticData.h"
//
//
//
////#include "LCDField.h"
//#include "RowBase.h"
//
//#include "LCDLabel.h"
//
//
////
////#include <SoftwareSerial.h>
////#include <MIDI.h>
////
////
////
//#include "HardwareSerial.h"
//#include "LCDByteField.h"
//#include "LCDFloat.h"
//#include "LCDInt16.h"
//#include "LCDTextLine.h"
//#include "MultiRowBase.h"
//#include "RowFloat.h"
//#include "RowFourByteFields.h"
////#include "GuiScreen.h"
//#include "RowHeading.h"
//#include "RowIntiger.h"
//#include "RowMIDIMessage.h"
//#include "RowOneByteField.h"
//#include "RowSignalInstruction.h"
//#include "RowTextLine.h"
//#include "RowTextLineWithPrefix.h"
//#include "RowTwoByteFields.h"
//#include "RowWithUnit.h"
//#include "SignalControlManager.h"
//#include "SignalControlUnit.h"
//#include "SignalUnitView.h"
//#include "TransferClassHeader.h"
//#include "TransferLink.h"
//#include <Adafruit_GFX.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <gfxfont.h>
//#include <LightChrono.h>
//#include <MidiConfig.h>
//#include <MidiSoundControl.h>
//#include <MonitorMessage.h>
//#include <SignalControlLink.h>
//#include <SignalControlManager.h>
//
//

#define LED_AUTOCHANGEON 0
#define LED_MIDIMESSAGE 1
#define LED_PCTODIAGNOSTIC 2
#define LED_DIAGNOSTICTOPC 3
#define LED_SYNTHTODIAGNOSTIC 4
#define LED_SIGNALTOSYNTH 5

#define LED_SYNTHTOSIGNAL 6
#define LED_HEARTBEAT 7

#include <TM1638.h>
#include <ACEMegaHostTFT.h>
#include <DevicePort.h>
#include <DeviceRegistration.h>
#include <SoftwareSerial.h>

#include "RowBase.h"
#include "LCDField.h"
#include "LCDLabel.h"

#include "GuiScreen.h"
#include "GuiScreenView.h"
#include "GuiScreenViewSet.h"

#include "DiagnosticData.h"
#include "MonitorMessage.h"
#include "SignalControlLink.h"
#include "LightChrono.h"

#include "DiagnosticDeviceViewSet.h"

//#include "RowHeading.h"
//#include "RowTwoByteFields.h"

class DiagnosticDeviceManager {

public:


	SoftwareSerial PortSynthDebug = SoftwareSerial(A15, A14);

	DeviceRegistration deviceRegistration = DeviceRegistration(DEVICESIGNATURE_DIAGNOSTICDEVICE);
	DevicePort devicePort_SignalGen = DevicePort(&Serial1);
	DevicePort devicePort_SynthControlToSignal = DevicePort(&Serial2);
	DevicePort devicePort_SynthControlToDiagnostic = DevicePort(&PortSynthDebug);

	TransferLink deviceLink_SignalGen;
	TransferLink deviceLink_SynthControlToSignal;
	TransferLink deviceLink_SynthControlToDiagnostic;

	
	ACEMegaHostTFTClass Display = ACEMegaHostTFTClass();


	// define a module on data pin 8, clock pin 9 and strobe pin 7
	TM1638 module = TM1638(A10, A12, A11);





	DiagnosticData Data;

	MonitorMessage msg;


	SignalControlLink link;

	SignalControlManagerClass SignalControlManager = SignalControlManagerClass();


	boolean LogToSerial = true;
	
	LightChrono auto_change_display_chrono;
	LightChrono refresh_display_chrono;
	LightChrono heartbeat_chrono;



	bool displayModeAutochange = true;

	GuiScreen GUI = GuiScreen();
	DiagnosticDeviceViewSet ViewSet;


	byte LedState = B00000000;





	void SynthToSignalTransfer();

	void Log(String logLine);


	void setup();

	void UpdateLedDisplay();

	void LedSet(byte led_id, boolean state);

	void LedToggle(byte led_id);

	void loop();
};

#endif

