/*
 Name:		imbAVR.ino
 Created:	9/11/2019 12:27:27 PM
 Author:	gorangrubic
*/

#include <SPI.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include "SoftwareSerial.h"
#include "HardwareSerial.h"

#include <SoftwareSerial.h>
#include "src/DevicePort.h"
#include "src/TransferLink.h"

#include "src/ACEMegaHostTFT.h"
#include "src/DynamicScreenView.h"

#include "arduino.h"
#include <pins_arduino.h> 


struct customMessage {
	unsigned int parameterA;
	unsigned int parameterB;
	byte parameterC;
	byte parameterD;
};


TransferLink hostLink;
DevicePort hostPort = DevicePort(&Serial1);

ACEMegaHostTFTClass Display;


customMessage message;

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(115200);

	hostLink.SetHeader(TransferLink::MakeHeader(4, sizeof(customMessage), false, 0x00));

	Display.setTextSize(2);
	Display.begin();
	Display.setRotation(1);
	Display.fillScreen(GLCD_CL_BLACK);

}
unsigned int di = 0;
void log(String msg) {
	if (di > 14) {
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
		di = 0;
	}
	
	Serial.println(msg);
	Display.println(msg);
	di++;
}

void log(customMessage msg) {
	
		Display.fillScreen(GLCD_CL_BLACK);
		Display.setCursor(0, 0);
	di = 0;
	
	log("A " + msg.parameterA);
	log("B " + msg.parameterB);
	log("C " + msg.parameterC);
	log("D " + msg.parameterD);
}

// the loop function runs over and over again until power down or reset
void loop() {
	
	byte result = hostLink.Receive(&hostPort);
	byte classID = result >> 4;

	bool dataReceived = false;

	if ((result & B00001111) == B00000000) {
		log("No bytes received");
	}

	if ((result & B00001111) == B00000001) {
		log("Transfer not complete");
	}

	if ((result & B00001111) == B00000010) {
		log("Buffer index overflow");
	}

	if ((result & B00001111) == B00000011) {
		log("Data received successfully [cid " + String(classID) + "]" );
		dataReceived = true;
	}

	if ((result & B00001111) == B00000100) {
		log("Control byte mismatched");
	}

	if ((result & B00001111) == B00001100) {
		log("Buffer flushed time out");
	}


	if (dataReceived) {

		TransferLink * link = &hostLink;

		TRANSFER_LOADDATA(message, link)

		log(message);
	}

	delay(1000);

}
