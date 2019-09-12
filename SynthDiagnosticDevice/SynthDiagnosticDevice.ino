/*
 Name:		SynthDiagnosticDevice.ino
 Created:	8/22/2019 7:59:33 PM
 Author:	gorangrubic
*/

// the setup function runs once when you press reset or power the board


// Connect data pins LCD_D 0-7 to arduino UNO:
//LCD_D 0 -- D8
// LCD_D 1 -- D9
// LCD_D 2 -- D2
// LCD_D 3 -- D3
// LCD_D 4 -- D4
// LCD_D 5 -- D5
// LCD_D 6 -- D6
// LCD_D 7 -- D7
// Connect command pins:
// LCD_RST -- A4   1 -> 0 min 15 micros 0 -> 1 
// LCD_CS  -- A3   chip select, aktiv LOW
// LCD_RS  -- A2   data/command select, 0 command, 1 data
// LCD_WR  -- A1   0 -> 1, HIGH when not used
// LCD_RD  -- A0   0 -> 1, HIGH when not used

// arduino uno porty:
// B (digital pin 8 to 13) 
// C (analog input pins) 
// D (digital pins 0 to 7)   0 1 are RX TX, don't use 




//
//
////
////#include <DiagnosticDeviceManager.h>
////
////#include "SignalUnitView.h"
////#include "MultiRowBase.h"
////#include "RowSignalInstruction.h"
////#include "RowMIDIMessage.h"
////#include "RowTextLineWithPrefix.h"
////#include "RowTextLine.h"
////#include "RowIntiger.h"
////#include "RowFloat.h"
////#include "RowOneByteField.h"
////#include "RowWithUnit.h"
////#include "RowFourByteFields.h"
////#include "LCDInt16.h"
////#include "LCDFloat.h"
////#include "LCDTextLine.h"
//#include <SoftwareSerial.h>
//#include <MIDI.h>
//
//#include <TM1638.h>
//
//
//#include <gfxfont.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_GFX.h>
//#include "ACEMegaHostTFT.h"
//
//#include "MonitorMessage.h";
//
//#include "HardwareSerial.h"
//
//#include "GuiScreen.h"
//#include "GuiScreenView.h"
//#include "GuiScreenViewSet.h"
//
//#include "LCDByteField.h"
//#include "RowTwoByteFields.h"
//#include "RowHeading.h"
//
//#include "MidiConfig.h"
//
//#include "SignalControlUnit.h"
//#include "SignalControlManager.h"
//
//#include "SynthDeviceControl.h"
//
//

//#include <DeviceRegistration.h>


//byte displayMode = 0;

//RowHeading RowTopHeading = RowHeading(0);
//
//RowTwoByteFields RowFirst = RowTwoByteFields(1);
//RowTwoByteFields RowSecond = RowTwoByteFields(2);
//
//RowHeading RowAmpCtrlHeading = RowHeading(3);
//
//RowTwoByteFields RowAmpCtrlFirst = RowTwoByteFields(4);
//RowTwoByteFields RowAmpCtrlSecond = RowTwoByteFields(5);
//RowTwoByteFields RowAmpCtrlThird = RowTwoByteFields(6);
//
//
//RowHeading RowFltCtrlHeading = RowHeading(7);
//
//RowTwoByteFields RowFltCtrlFirst = RowTwoByteFields(8);
//RowTwoByteFields RowFltCtrlSecond = RowTwoByteFields(9);
//RowTwoByteFields RowFltCtrlThird = RowTwoByteFields(10);
//
//RowTwoByteFields RowFltCtrlFourth = RowTwoByteFields(11);
//

//MonitorMessage msg;
//
//byte mmHeader = 0;
//byte mmDataIndex = 0;
//byte Data[MonitorMessageSize_Bytes];
//
//SignalControlLink link;
//
//SignalControlManagerClass SignalControlManager = SignalControlManagerClass();
//
//
//GuiScreenViewSet ViewSet = GuiScreenViewSet(&GUI);
//
//SoftwareSerial PortSynthDebug = SoftwareSerial(A15, A14);
//
//RowHeading v1_title = RowHeading("Overview");
//
//RowHeading v1_subtitle = RowHeading("-- Overview --");
//
//RowTwoByteFields v1_SCData = RowTwoByteFields("Head", "Buff", mmHeader, mmDataIndex);
//
//RowHeading v2_title = RowHeading("Synth state 1");
//
//RowTwoByteFields v2_1 = RowTwoByteFields("WFRM A", "WFRM B", msg.State.CCValues[CC_WaveformA_Shaper], msg.State.CCValues[CC_WaveformB_Filter]);
//RowTwoByteFields v2_2 = RowTwoByteFields("A/B MIX", "--", msg.State.CCValues[CC_WaveformMix], msg.State.CCValues[CC_WaveformMix]);
////	RowFirst.Set("WFRM A", "WFRM B", msg.State.CCValues[CC_WaveformA_Shaper], msg.State.CCValues[CC_WaveformB_Filter]);
////	RowSecond.Set("A/B MIX", "--", msg.State.CCValues[CC_WaveformMix],0);
//
//
////	
////	RowAmpCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_AmpAttack], msg.State.CCValues[CC_AmpDecayTime]);
////	RowAmpCtrlSecond.Set("Release", "----", msg.State.CCValues[CC_AmpRelease],0);
////	RowAmpCtrlThird.Set("Init", "Sustain", msg.State.CCValues[CC_AmpInitLevel], msg.State.CCValues[CC_AmpSustainLevel]);
//
////	RowFltCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_FLTAttack], msg.State.CCValues[CC_FLTDecayTime]);
////	RowFltCtrlSecond.Set("Release", "Init", msg.State.CCValues[CC_FLTRelease], msg.State.CCValues[CC_FLTInitLevel]);
////	RowFltCtrlThird.Set("Sustain", "Mix", msg.State.CCValues[CC_FLTSustainLevel], msg.State.CCValues[CC_FLT_ADSR_Mix]);
////	RowFltCtrlFourth.Set("Cut-off", "Res", msg.State.CCValues[CC_Cutoff], msg.State.CCValues[CC_Resonance]);
//
//
//RowHeading v3_title = RowHeading("Synth state 2");
//
//RowHeading v4_title = RowHeading("Signal-gen state 1");
//
//RowHeading v5_title = RowHeading("Signal-gen state 2");


//
//#include <TM16XXFonts.h>
//#include <TM16XX.h>
//#include <TM1640.h>
//#include <TM1638QYF.h>
//#include <TM1638.h>
//#include <InvertedTM1638.h>
//#include <gfxfont.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_GFX.h>
//#include <SoftwareSerial.h>


#include <TM16XXFonts.h>
#include <TM16XX.h>
#include <TM1640.h>
#include <TM1638QYF.h>
#include <TM1638.h>
#include <InvertedTM1638.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <DiagnosticDeviceManager.h>
#include <GuiScreenViewSet.h>



DiagnosticDeviceManager diagnosticDevice;

void setup() {
	
	Serial.begin(19200);

	diagnosticDevice.setup();


}



void update() {

	
	
	
	
}




void UpdateDisplay(boolean firstTime) {
	
	



	//if (firstTime) {
	//	Serial.print("Display mode [");


	//	Serial.print(" View ID ");
	//	Serial.print(ViewSet.Views[displayMode].uid);


	//	Serial.print(" Active rows ");
	//	Serial.print(ViewSet.Views[displayMode].ActiveRows);


	//	Serial.print(" Mode ");

	//	Serial.println(displayMode);
	//}

	/*

	//switch (displayMode) {
	//case 0:

	//	Display.fillScreen(GLCD_CL_BLACK);
	//	
	//	Display.setCursor(0, 0);
	//	Display.print("Header: ");
	//	Display.println(mmHeader);
	//	Display.print("Index: ");
	//	Display.print(mmDataIndex);
	//	Display.println("");
	//	

	//	break;
	//case 1:
	//	
	//	



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

	//	//
	//	
	//	if (firstTime) {
	//		Display.fillScreen(GLCD_CL_BLACK);
	//		RowFirst.PrintLabels(&Display);
	//		RowSecond.PrintLabels(&Display);
	//		
	//		RowTopHeading.PrintLabels(&Display);
	//		RowAmpCtrlHeading.PrintLabels(&Display);

	//		RowAmpCtrlFirst.PrintLabels(&Display);
	//		RowAmpCtrlSecond.PrintLabels(&Display);
	//		RowAmpCtrlThird.PrintLabels(&Display);

	//		RowFltCtrlHeading.PrintLabels(&Display);

	//		RowFltCtrlFirst.PrintLabels(&Display);
	//		RowFltCtrlSecond.PrintLabels(&Display);
	//		RowFltCtrlThird.PrintLabels(&Display);
	//		RowFltCtrlFourth.PrintLabels(&Display);

	//	}

	//	RowFirst.UpdateFields(&Display);
	//	RowSecond.UpdateFields(&Display);
	//	

	//	RowAmpCtrlFirst.UpdateFields(&Display);
	//	RowAmpCtrlSecond.UpdateFields(&Display);
	//	RowAmpCtrlThird.UpdateFields(&Display);

	//	RowFltCtrlFirst.UpdateFields(&Display);
	//	RowFltCtrlSecond.UpdateFields(&Display);
	//	RowFltCtrlThird.UpdateFields(&Display);
	//	RowFltCtrlFourth.UpdateFields(&Display);

	//	/*Display.setCursor(0, 0);
	//	Display.print("AMP: ");
	//	Display.getCursorX();
	//	
	//	Display.print(msg.State.out_amp_value);
	//	Display.println("");
	//	Display.print("FLT_f: ");
	//	Display.print(msg.State.out_flt_value);
	//	Display.print("FLT_r: ");
	//	Display.print(msg.State.out_flt_gain);
	//	Display.println("");
	//	Display.print("WF_A: ");
	//	Display.print(msg.State.out_waveform_a_shaper);
	//	Display.print("WF_B: ");
	//	Display.print(msg.State.out_waveform_b_flt);
	//	Display.println("");
	//	Display.print("WFMIX: ");
	//	Display.print();
	//	Display.println("");*/
	//	break;
	//case 2:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);
	//	
	//	Display.println("Synth control buffer");
	//	Display.println(synthControl_buffer);
	//	break;
	//case 3:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);

	//	Display.println("Signal control buffer");
	//	Display.println(signalControl_buffer);
	//	break;
	//case 4:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);

	//	Display.println("Mixed buffer buffer");
	//	Display.println(mixBuffer);
	//	break;
	//case 5:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);
	//	break;
	//case 6:
	//	
	//	break;
	//case 7:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);
	//	break;
	//case 8:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);
	//	break;
	//case 9:
	//	Display.fillScreen(GLCD_CL_BLACK);
	//	Display.setCursor(0, 0);
	//	break;
	//}
	
}





// the loop function runs over and over again until power down or reset
void loop() {


	//update();

	diagnosticDevice.loop();


	//UpdateDisplay(modeLast != displayMode);

	//modeLast = displayMode;

	//char command = ' ';
	//if (Serial.available()) {

	//	command = Serial.read();

	//	switch (command) {
	//	case '0':
	//		displayMode = 0;
	//		break;
	//	case '1':
	//		displayMode = 1;
	//		break;
	//	case '2':
	//		displayMode = 2;
	//		break;
	//	case '3':
	//		displayMode = 3;
	//		break;
	//	case '4':
	//		displayMode = 4;
	//		break;
	//	
	//	case 'C':
	//		synthControl_buffer = "";
	//		signalControl_buffer = "";
	//		break;
	//	}
	//}



	//if (link.ByteCodeProtocol) {

	//	if (Serial1.available()) {
	//		byte b = Serial1.read();
	//		SignalControlManager.Receive(b);

	//		Serial1.write(b);
	//	}

	//}
	//else {


	//	if (Serial1.available() > 5) {

	//		input += Serial1.readString();
	//		Serial1.flush();
	//	}

	//	while (input.indexOf("[") > -1) {

	//		byte lastIndex = link.instructionIndex;

	//		input = link.readStringChar(input);

	//		if (lastIndex != link.instructionIndex) {

	//			SignalControlManager.Perform(link.instruction);

	//		}


	//	}

	//}


	//while (Serial1.available()) {
	//	byte b = Serial1.read();
	//	Serial.write(b);
	//	Serial2.write(b);

	//	synthControl_buffer += b;
	//}
	//
	//while (Serial2.available()) {
	//	byte b = Serial2.read();
	//	Serial.write(b);
	//	Serial1.write(b);

	//	signalControl_buffer += b;
	//}
	
	/*if (synthControl_buffer.length() > buffer_limit) synthControl_buffer = synthControl_buffer.substring(buffer_limit);
	if (signalControl_buffer.length() > buffer_limit) signalControl_buffer = signalControl_buffer.substring(buffer_limit);

	if (mixBuffer.length() > buffer_limit) mixBuffer = mixBuffer.substring(buffer_limit);
*/



	//while (Serial2.available()) {

	////	Serial2.readBytes(&*Data, MonitorMessageSize_Bytes);
	//	//msg.SerialRead(Data);

	//	//mode = 1;

	//	byte b = Serial2.read();
	//	
	//	if (mmHeader >= MonitorMessageHeaderSize) {

	//		if (mmDataIndex >= MonitorMessageSize_Bytes) {
	//			mmHeader = 0;
	//			mmDataIndex = 0;
	//			msg.SerialRead(Data);
	//			mode = 1;
	//		}
	//		else {
	//			Data[mmDataIndex] = b;
	//			mmDataIndex++;
	//		}

	//	}
	//	else {
	//		if (b == MonitorMessageStartChar) {
	//			mmHeader++;
	//			mmDataIndex = 0;
	//		}
	//		
	//	}
	//	
	//}

	//Display.print(mmHeader);

	
}
