/*
 Name:		CommunicationsTestClient.ino
 Created:	9/11/2019 5:03:05 PM
 Author:	gorangrubic
*/


#include <SPI.h>


#include <SoftwareSerial.h>


#include "customMessage.h"

#include "spiSender.h"



void log(String msg) {
	Serial.println(msg);
}

int pinSS = 10;

spiSender<customMessage> dataSender = spiSender<customMessage>(pinSS);

void log(customMessage msg) {

	Serial.print("A ");
	Serial.println(msg.parameterA);

	Serial.print("B ");
	Serial.println(msg.parameterB);

	Serial.print("C ");
	Serial.println(msg.parameterC);

	Serial.print("D ");
	Serial.println(msg.parameterD);
	
}

unsigned int i = 5;

void setup() {

	Serial.begin(38400);
	digitalWrite(pinSS, HIGH);

	SPI.begin();
	
	SPI.setClockDivider(SPI_CLOCK_DIV8);

	dataSender.protocol = B00000100; // SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE;

	dataSender.protocol = B00000001; // SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE;

	dataSender.protocol = B00000011; // SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE;

}

customMessage msg;

unsigned int MSG_COUNT = 0;

void loop() {


	

	if (MSG_COUNT < 10000) {

		MSG_COUNT++;

		msg.parameterA = i * 100;
		msg.parameterB = i * 200;
		msg.parameterC = i * 5;
		msg.parameterD = i * 1;

		i++;

		if (i > 10) i = 0;

		dataSender.Send(msg);


		log(msg);

		delay(500);
	}
}

