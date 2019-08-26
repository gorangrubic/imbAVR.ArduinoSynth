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

#include "HardwareSerial.h"

ACEMegaHostTFTClass Display = ACEMegaHostTFTClass();

TM1638QYF module(49, 51, 53);


#define BAUD_RATE 115200

word mode;
unsigned long startTime;

void setup() {
	
	Display.textsize = 2;
	Display.setTextSize(5);
	Display.begin();
	Display.setRotation(1);
	Display.fillScreen(GLCD_CL_BLACK);
	Display.println("Starting");
	
	startTime = millis();
	module.setupDisplay(true, 7);
	mode = 0;

	Serial1.begin(BAUD_RATE);
}

void update(TM1638QYF* module, word* mode) {
	word buttons = module->getButtons();
	unsigned long runningSecs = (millis() - startTime) / 1000;

	// button pressed - change mode
	if (buttons != 0) {
		*mode = buttons >> 1;

		if (*mode < 128) {
			module->clearDisplay();
			delay(100);
		}
	}

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
}

// the loop function runs over and over again until power down or reset
void loop() {

	update(&module, &mode);
}
