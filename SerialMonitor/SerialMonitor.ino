/*
 Name:		SerialMonitor.ino
 Created:	8/18/2019 12:10:42 AM
 Author:	gorangrubic
*/

#define BAUDRATE 115200
#define MON_RX 4
#define MON_TX 5


// the setup function runs once when you press reset or power the board
#include <SoftwareSerial.h>

// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial portOne(MON_RX, MON_TX);

void setup() {
	// Open serial communications and wait for port to open:
	Serial.begin(BAUDRATE);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}


	// Start each software serial port
	portOne.begin(BAUDRATE);
}

// the loop function runs over and over again until power down or reset
void loop() {
	// By default, the last intialized port is listening.
   // when you want to listen on a port, explicitly select it:
	portOne.listen();



	// while there is data coming in, read it
	// and send to the hardware serial port:
	while (portOne.available() > 0) {
		char inByte = portOne.read();
		Serial.write(inByte);
	}

}
