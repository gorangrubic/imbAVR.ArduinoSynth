// DiagnosticDeviceManager.h

#ifndef _DIAGNOSTICDEVICEMANAGER_h
#define _DIAGNOSTICDEVICEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif




#include <DiagnosticDeviceManager.h>
#include "SignalUnitView.h"
#include "MultiRowBase.h"
#include "RowSignalInstruction.h"
#include "RowMIDIMessage.h"
#include "RowTextLineWithPrefix.h"
#include "RowTextLine.h"
#include "RowIntiger.h"
#include "RowFloat.h"
#include "RowOneByteField.h"
#include "RowWithUnit.h"
#include "RowFourByteFields.h"
#include "LCDInt16.h"
#include "LCDFloat.h"
#include "LCDTextLine.h"
#include <SoftwareSerial.h>
#include <MIDI.h>

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include "ACEMegaHostTFT.h"

#include "HardwareSerial.h"

#include "LCDByteField.h"
#include "RowTwoByteFields.h"
#include "RowHeading.h"

#include "SignalControlUnit.h"
#include "SignalControlManager.h"



#include <SignalControlManager.h>
#include <MidiConfig.h>
#include <MidiSoundControl.h>
#include <MonitorMessage.h>


#include "GuiScreen.h"
#include "GuiScreenView.h"
#include "GuiScreenViewSet.h"

#include "DiagnosticData.h"

#include <TM1638.h>

#include <LightChrono.h>
#include <SignalControlLink.h>

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include "ACEMegaHostTFT.h"

#include <SoftwareSerial.h>

#define LED_AUTOCHANGEON 0
#define LED_MIDIMESSAGE 1
#define LED_PCTODIAGNOSTIC 2
#define LED_DIAGNOSTICTOPC 3
#define LED_SYNTHTODIAGNOSTIC 4
#define LED_SIGNALTOSYNTH 5

#define LED_SYNTHTOSIGNAL 6
#define LED_HEARTBEAT 7

#include <DeviceRegistration.h>

class DiagnosticDeviceManager {

public:


	SoftwareSerial PortSynthDebug = SoftwareSerial(A15, A14);

	DeviceRegistration deviceRegistration = DeviceRegistration(DEVICESIGNATURE_DIAGNOSTICDEVICE, 115200);
	DevicePort devicePort_SignalGen = DevicePort(Serial1);
	DevicePort devicePort_SynthControlToSignal = DevicePort(Serial2);
	DevicePort devicePort_SynthControlToDiagnostic = DevicePort(PortSynthDebug);

	TransferLink transferLink;

	unsigned int baudrate_signal_device = 19200;
	unsigned int baudrate_mainserial = 57600;
	

	ACEMegaHostTFTClass Display = ACEMegaHostTFTClass();


	// define a module on data pin 8, clock pin 9 and strobe pin 7
	// define a module on data pin 8, clock pin 9 and strobe pin 7
	TM1638 module = TM1638(A10, A12, A11);


	GuiScreen GUI = GuiScreen();

	byte displayMode = 0;
	byte lastDisplayMode = 255;

	bool displayModeAutochange = true;

	DiagnosticData Data;

	MonitorMessage msg;

	byte mmHeader = 0;
	byte mmDataIndex = 0;
	byte mmData[MonitorMessageSize_Bytes];

	SignalControlLink link;

	SignalControlManagerClass SignalControlManager = SignalControlManagerClass();


	boolean LogToSerial = true;
	
	LightChrono auto_change_display_chrono;
	LightChrono refresh_display_chrono;
	LightChrono heartbeat_chrono;

	GuiScreenViewSet ViewSet = GuiScreenViewSet(&GUI);


	byte LedState = B00000000;


	RowHeading v1_title = RowHeading("Overview");

	RowHeading v1_subtitle = RowHeading("-- Overview --");

	RowTwoByteFields v1_SCData = RowTwoByteFields("Head", "Buff", &mmHeader, &mmDataIndex);

	RowHeading v2_title = RowHeading("Synth state 1");

	RowTwoByteFields v2_1 = RowTwoByteFields("WFRM A", "WFRM B", msg.State.CCValues[CC_WaveformA_Shaper], msg.State.CCValues[CC_WaveformB_Filter]);
	RowTwoByteFields v2_2 = RowTwoByteFields("A/B MIX", "--", msg.State.CCValues[CC_WaveformMix], msg.State.CCValues[CC_WaveformMix]);
	//	RowFirst.Set("WFRM A", "WFRM B", msg.State.CCValues[CC_WaveformA_Shaper], msg.State.CCValues[CC_WaveformB_Filter]);
	//	RowSecond.Set("A/B MIX", "--", msg.State.CCValues[CC_WaveformMix],0);


	//	
	//	RowAmpCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_AmpAttack], msg.State.CCValues[CC_AmpDecayTime]);
	//	RowAmpCtrlSecond.Set("Release", "----", msg.State.CCValues[CC_AmpRelease],0);
	//	RowAmpCtrlThird.Set("Init", "Sustain", msg.State.CCValues[CC_AmpInitLevel], msg.State.CCValues[CC_AmpSustainLevel]);

	//	RowFltCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_FLTAttack], msg.State.CCValues[CC_FLTDecayTime]);
	//	RowFltCtrlSecond.Set("Release", "Init", msg.State.CCValues[CC_FLTRelease], msg.State.CCValues[CC_FLTInitLevel]);
	//	RowFltCtrlThird.Set("Sustain", "Mix", msg.State.CCValues[CC_FLTSustainLevel], msg.State.CCValues[CC_FLT_ADSR_Mix]);
	//	RowFltCtrlFourth.Set("Cut-off", "Res", msg.State.CCValues[CC_Cutoff], msg.State.CCValues[CC_Resonance]);


	RowHeading v3_title = RowHeading("Synth state 2");

	RowHeading v4_title = RowHeading("Signal-gen state 1");

	RowHeading v5_title = RowHeading("Signal-gen state 2");


	void SynthToSignalTransfer();

	void Log(String logLine);


	void setup();

	void UpdateLedDisplay();

	void LedSet(byte led_id, boolean state);

	void LedToggle(byte led_id);

	void loop();
};

#endif

