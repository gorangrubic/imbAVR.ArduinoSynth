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

#include <TM16XXFonts.h>
#include <TM16XX.h>
#include <TM1640.h>
#include <TM1638QYF.h>
#include <TM1638.h>
#include <InvertedTM1638.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include "ACEMegaHostTFT.h"
#include "MonitorMessage.h";

#include "HardwareSerial.h"
#include "GuiScreen.h"
#include "LCDByteField.h"
#include "RowTwoByteFields.h"
#include "RowHeading.h"
#include "MidiConfig.h"

ACEMegaHostTFTClass Display = ACEMegaHostTFTClass();
GuiScreen GUI = GuiScreen();

TM1638QYF module(49, 51, 53);


#define BAUD_RATE 115200

word mode = 0;
word modeLast = 8;
unsigned long startTime;
byte displayMode = 0;

RowHeading RowTopHeading = RowHeading(0);

RowTwoByteFields RowFirst = RowTwoByteFields(1);
RowTwoByteFields RowSecond = RowTwoByteFields(2);

RowHeading RowAmpCtrlHeading = RowHeading(3);

RowTwoByteFields RowAmpCtrlFirst = RowTwoByteFields(4);
RowTwoByteFields RowAmpCtrlSecond = RowTwoByteFields(5);
RowTwoByteFields RowAmpCtrlThird = RowTwoByteFields(6);


RowHeading RowFltCtrlHeading = RowHeading(7);

RowTwoByteFields RowFltCtrlFirst = RowTwoByteFields(8);
RowTwoByteFields RowFltCtrlSecond = RowTwoByteFields(9);
RowTwoByteFields RowFltCtrlThird = RowTwoByteFields(10);

RowTwoByteFields RowFltCtrlFourth = RowTwoByteFields(11);

void setup() {
	
	
	GUI.TextSize = 2;

	Display.setTextSize(GUI.TextSize);
	Display.begin();
	Display.setRotation(1);
	Display.fillScreen(GLCD_CL_BLACK);
	Display.println("Starting");
	
	RowFirst.Deploy(GUI);
	RowSecond.Deploy(GUI);
	RowTopHeading.Deploy(GUI, "Waveform CCs");
	RowAmpCtrlHeading.Deploy(GUI, "AMP ADSR");

	RowAmpCtrlFirst.Deploy(GUI, GLCD_CL_CYAN);
	RowAmpCtrlSecond.Deploy(GUI, GLCD_CL_CYAN);
	RowAmpCtrlThird.Deploy(GUI, GLCD_CL_CYAN);


	RowFltCtrlHeading.Deploy(GUI, "FLT ADSR");

	RowFltCtrlFirst.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlSecond.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlThird.Deploy(GUI, GLCD_CL_RED);
	RowFltCtrlFourth.Deploy(GUI);

	startTime = millis();
	module.setupDisplay(true, 7);
	mode = 0;

	Serial.begin(BAUD_RATE);
	Serial2.begin(BAUD_RATE);
}

void update(TM1638QYF* module, word* mode) {

	word buttons = module->getButtons();
	unsigned long runningSecs = (millis() - startTime) / 1000;

	// button pressed - change mode
	if (buttons != 0) {
		*mode = buttons >> 1;
		//displayMode = mode;

		

		if (*mode < 128) {
			module->clearDisplay();
			delay(50);
		}
	}

	switch (*mode) {
	case 0:
		displayMode = 0;

		break;
	case 1:
		displayMode = 1;
		break;
	case 2:
		displayMode = 2;
		break;
	case 4:
		displayMode = 3;
		break;
	case 8:
		displayMode = 4;
		break;
	case 16:
		displayMode = 5;
		break;
	case 32:
		displayMode = 6;
		break;
	case 64:
		displayMode = 7;
		break;
	case 128:
		//displayMode = 8;
		break;
	case 256:
		//displayMode = 9;
		break;
	}

	byte dots;
	bitSet(dots, displayMode);

	//module->setDisplayDigit(0, displayMode, true);
	module->setDisplayToDecNumber(0, dots, false);
	/*
	switch (*mode) {
	case 0:
		module->setDisplayToDecNumber(runningSecs, 1 << 6);
		break;
	case 1:
		module->setDisplayToDecNumber(runningSecs, 1 << 5, false);
		break;
	case 2:
		module->setDisplayToHexNumber(runningSecs, 1 << 4);
		break;
	case 4:
		module->setDisplayToHexNumber(runningSecs, 1 << 3, false);
		break;
	case 8:
		module->setDisplayToBinNumber(runningSecs, 1 << 2);
		break;
	case 16:
		char s[9];
		sprintf(s, "Secs %03d", runningSecs % 999);
		module->setDisplayToString(s, 1 << 1);
		break;
	case 32:
		if (runningSecs % 2 == 0) {
			module->setDisplayToString("TM1638QY", 1);
		}
		else {
			module->setDisplayToString(String("LIBRARY "), 1);
		}

		break;
	case 64:
		module->setDisplayToError();
		break;
	case 128:
		module->setDisplayToDecNumber(*mode, 0);
		break;
	case 256:
		module->setDisplayToString("ABCDE", 1 << (runningSecs % 8));
		break;
	default:
		module->setDisplayToBinNumber(buttons & 0xF, buttons >> 8);
	}
	*/
}

MonitorMessage msg;

int mmHeader = 0;
int mmDataIndex = 0;
byte Data[MonitorMessageSize_Bytes];




void UpdateDisplay(boolean firstTime) {
	
	switch (mode) {
	case 0:

		Display.fillScreen(GLCD_CL_BLACK);
		
		Display.setCursor(0, 0);
		Display.print("Header: ");
		Display.println(mmHeader);
		Display.print("Index: ");
		Display.print(mmDataIndex);
		Display.println("");
		

		break;
	case 1:
		
		



		RowFirst.Set("WFRM A", "WFRM B", msg.State.CCValues[CC_WaveformA_Shaper], msg.State.CCValues[CC_WaveformB_Filter]);
		RowSecond.Set("A/B MIX", "--", msg.State.CCValues[CC_WaveformMix],0);


		
		RowAmpCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_AmpAttack], msg.State.CCValues[CC_AmpDecayTime]);
		RowAmpCtrlSecond.Set("Release", "----", msg.State.CCValues[CC_AmpRelease],0);
		RowAmpCtrlThird.Set("Init", "Sustain", msg.State.CCValues[CC_AmpInitLevel], msg.State.CCValues[CC_AmpSustainLevel]);

		RowFltCtrlFirst.Set("Attack", "Decay", msg.State.CCValues[CC_FLTAttack], msg.State.CCValues[CC_FLTDecayTime]);
		RowFltCtrlSecond.Set("Release", "Init", msg.State.CCValues[CC_FLTRelease], msg.State.CCValues[CC_FLTInitLevel]);
		RowFltCtrlThird.Set("Sustain", "Mix", msg.State.CCValues[CC_FLTSustainLevel], msg.State.CCValues[CC_FLT_ADSR_Mix]);
		RowFltCtrlFourth.Set("Cut-off", "Res", msg.State.CCValues[CC_Cutoff], msg.State.CCValues[CC_Resonance]);

		//
		
		if (firstTime) {
			Display.fillScreen(GLCD_CL_BLACK);
			RowFirst.PrintLabels(&Display);
			RowSecond.PrintLabels(&Display);
			
			RowTopHeading.PrintLabels(&Display);
			RowAmpCtrlHeading.PrintLabels(&Display);

			RowAmpCtrlFirst.PrintLabels(&Display);
			RowAmpCtrlSecond.PrintLabels(&Display);
			RowAmpCtrlThird.PrintLabels(&Display);

			RowFltCtrlHeading.PrintLabels(&Display);

			RowFltCtrlFirst.PrintLabels(&Display);
			RowFltCtrlSecond.PrintLabels(&Display);
			RowFltCtrlThird.PrintLabels(&Display);
			RowFltCtrlFourth.PrintLabels(&Display);

		}

		RowFirst.UpdateFields(&Display);
		RowSecond.UpdateFields(&Display);
		

		RowAmpCtrlFirst.UpdateFields(&Display);
		RowAmpCtrlSecond.UpdateFields(&Display);
		RowAmpCtrlThird.UpdateFields(&Display);

		RowFltCtrlFirst.UpdateFields(&Display);
		RowFltCtrlSecond.UpdateFields(&Display);
		RowFltCtrlThird.UpdateFields(&Display);
		RowFltCtrlFourth.UpdateFields(&Display);

		/*Display.setCursor(0, 0);
		Display.print("AMP: ");
		Display.getCursorX();
		
		Display.print(msg.State.out_amp_value);
		Display.println("");
		Display.print("FLT_f: ");
		Display.print(msg.State.out_flt_value);
		Display.print("FLT_r: ");
		Display.print(msg.State.out_flt_gain);
		Display.println("");
		Display.print("WF_A: ");
		Display.print(msg.State.out_waveform_a_shaper);
		Display.print("WF_B: ");
		Display.print(msg.State.out_waveform_b_flt);
		Display.println("");
		Display.print("WFMIX: ");
		Display.print();
		Display.println("");*/
		break;
	case 2:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 4:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 8:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 16:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 32:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 64:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 128:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	case 256:
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		break;
	}
	
}



// the loop function runs over and over again until power down or reset
void loop() {


	

	update(&module, &mode);

	UpdateDisplay(modeLast != mode);

	modeLast = mode;

	
	
	
	while (Serial2.available()) {

	//	Serial2.readBytes(&*Data, MonitorMessageSize_Bytes);
		//msg.SerialRead(Data);

		//mode = 1;

		byte b = Serial2.read();
		
		if (mmHeader >= MonitorMessageHeaderSize) {

			if (mmDataIndex >= MonitorMessageSize_Bytes) {
				mmHeader = 0;
				mmDataIndex = 0;
				msg.SerialRead(Data);
				mode = 1;
			}
			else {
				Data[mmDataIndex] = b;
				mmDataIndex++;
			}

		}
		else {
			if (b == MonitorMessageStartChar) {
				mmHeader++;
				mmDataIndex = 0;
			}
			
		}
		
	}

	//Display.print(mmHeader);

	
}
