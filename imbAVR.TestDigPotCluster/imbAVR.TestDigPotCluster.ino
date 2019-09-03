/*
 Name:		imbAVR.ino
 Created:	8/28/2019 9:03:41 PM
 Author:	gorangrubic


*/

#include <SPI.h>
#include "SignalInstruction.h"
#include "digPotCluster.h"


digPotCluster dp_cluster = digPotCluster();

#define PIN_DATA A2
#define PIN_LEACH A3
#define PIN_CLOCK A4

void setup() {
	SPI.begin();
	dp_cluster.init(PIN_LEACH, PIN_CLOCK, PIN_DATA);
	Serial.begin(9600);
}

void loop() {
 
	for (size_t i = 0; i < 25; i++)
	{
		byte v = i * 10;
		dp_cluster.Write(v, v, v, v, v, v, v, v);
		delay(100);
		Serial.println(v);
	}
	delay(1000);
}
