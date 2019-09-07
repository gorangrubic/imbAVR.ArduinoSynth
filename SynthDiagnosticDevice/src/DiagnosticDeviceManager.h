// DiagnosticDeviceManager.h

#ifndef _DIAGNOSTICDEVICEMANAGER_h
#define _DIAGNOSTICDEVICEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



#include <SignalControlManager.h>
#include <MidiConfig.h>
#include <MidiSoundControl.h>
#include <MonitorMessage.h>


#include "GuiScreen.h"
#include "GuiScreenView.h"
#include "GuiScreenViewSet.h"

#include "DiagnosticData.h"

#include <TM1638.h>


#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include "ACEMegaHostTFT.h"

#include <SoftwareSerial.h>

#include "src/DiagnosticData.h"

class DiagnosticDeviceManager {

public:

	unsigned int baudrate_signal_device = 19200;
	unsigned int baudrate_mainserial = 57600;
	

	ACEMegaHostTFTClass Display = ACEMegaHostTFTClass();


	// define a module on data pin 8, clock pin 9 and strobe pin 7
	


	GuiScreen GUI = GuiScreen();

	byte displayMode = 0;


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

	GuiScreenViewSet ViewSet = GuiScreenViewSet(&GUI);

	SoftwareSerial PortSynthDebug = SoftwareSerial(A15, A14);



	RowHeading v1_title = RowHeading("Overview");

	RowHeading v1_subtitle = RowHeading("-- Overview --");

	RowTwoByteFields v1_SCData = RowTwoByteFields("Head", "Buff", mmHeader, mmDataIndex);

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

	void loop();
};

#endif

