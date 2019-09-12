/*
 Name:		imbAVR.ino
 Created:	9/11/2019 12:26:53 PM
 Author:	gorangrubic
*/



// the setup function runs once when you press reset or power the board
//#include <SPI.h>
//#include <gfxfont.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_GFX.h>
//#include <ACEMegaHostTFT.h>
#include <SoftwareSerial.h>

#include "src/DevicePort.h";
#include "src/TransferLink.h"

struct customMessage {
	unsigned int parameterA;
	unsigned int parameterB;
	byte parameterC;
	byte parameterD;
};

unsigned int di = 0;
void log(String msg) {

	Serial.println(msg);

}

void log(customMessage msg) {

	log("A " + msg.parameterA);
	log("B " + msg.parameterB);
	log("C " + msg.parameterC);
	log("D " + msg.parameterD);
}

SoftwareSerial SoftSerial = SoftwareSerial(8, 9);
TransferLink hostLink;
DevicePort hostPort = DevicePort(&SoftSerial);

unsigned int i = 5;

void setup() {

	Serial.begin(115200);

	hostLink.SetHeader(TransferLink::MakeHeader(4, sizeof(customMessage), false, 0x00));
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	customMessage msg;

	msg.parameterA = i * 100;
	msg.parameterB = i * 200;
	msg.parameterC = i * 5;
	msg.parameterD = i * 1;

	log(msg);

	i++;

	TransferLink * link = &hostLink;

	TRANSFER_SENDDATA(link, &hostPort, msg)

	delay(2500);
}
