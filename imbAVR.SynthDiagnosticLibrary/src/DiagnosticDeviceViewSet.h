#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "DynamicScreenView.h"

#include "RowTemplates.h"
#include "MidiConfig.h"
#include "GuiScreenViewSet.h"
#include "GuiScreenControl.h"

#include "DeviceRegistration.h"
#include "DiagnosticData.h"
#include "TransferLink.h"
#include "SignalControlManager.h"
#include "MonitorMessage.h"

class DiagnosticDeviceViewSet:public GuiScreenControl
{

public:

	DynamicScreenView screenView;

//	DiagnosticDeviceManager * diagnosticDevice;


	//RowHeader view0_r0 = RowTemplates::RowHeading("Overview");
	//RowTwoByteFields view0_r1; // = RowTemplates::RowWithTwoByteFields("SYBF", &diagnosticDevice->deviceLink_SynthControlToSignal.bufferIndex, "SIBF", &diagnosticDevice->deviceLink_SignalGen.bufferIndex);


	//RowHeader view1_r0 = RowTemplates::RowHeading("Synth state");
	//RowTwoByteFields view1_r1; // amp attack time, amp decay time
	//RowTwoByteFields view1_r2; // amp release time, amp --
	//RowTwoByteFields view1_r3; // amp sustain val, amp init val

	//RowHeader view2_r0 = RowTemplates::RowHeading("Synth state B");



	//RowHeader view3_r0 = RowTemplates::RowHeading("Signal state");


	//RowHeader view4_r0 = RowTemplates::RowHeading("Signal instructions");


	//RowHeader view5_r0 = RowTemplates::RowHeading("MIDI messages");

	//RowHeader view6_r0 = RowTemplates::RowHeading("Log messages");
	//RowTextAndPrefix view6_r1; // = RowTemplates::RowTextWithPrefix("1", &diagnosticDevice->Data.LogMessages[0]);
	//RowTextAndPrefix view6_r2; // = RowTemplates::RowTextWithPrefix("2", &diagnosticDevice->Data.LogMessages[1]);
	//RowTextAndPrefix view6_r3; // = RowTemplates::RowTextWithPrefix("3", &diagnosticDevice->Data.LogMessages[2]);
	//RowTextAndPrefix view6_r4; // = RowTemplates::RowTextWithPrefix("4", &diagnosticDevice->Data.LogMessages[3]);
	//RowTextAndPrefix view6_r5; // = RowTemplates::RowTextWithPrefix("5", &diagnosticDevice->Data.LogMessages[4]);


	//RowHeader view7_r0 = RowTemplates::RowHeading("Other");

	DiagnosticData * Data;
	TransferLink * deviceLink_SynthControlToSignal;
	TransferLink * deviceLink_SynthControlToDiagnostic;
	SignalControlManagerClass * SignalControlManager;
	MonitorMessage * msg;
	DeviceRegistration * deviceRegistration;
	

	DevicePort * devicePort_SignalGen;
	DevicePort * devicePort_SynthControlToSignal;
	DevicePort * devicePort_SynthControlToDiagnostic;

	DiagnosticDeviceViewSet();

	void Deploy(GuiScreen * Screen);

	

	

	void RenderClassHeader(TransferLink * link, String title, GuiScreen * Screen, ACEMegaHostTFTClass * Display);

	void RenderScreen(GuiScreen * Screen, ACEMegaHostTFTClass * Display);

};

