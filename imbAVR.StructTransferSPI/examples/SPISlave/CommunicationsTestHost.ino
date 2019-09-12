/*
 Name:		CommunicationsTestHost.ino
 Created:	9/11/2019 4:24:01 PM
 Author:	gorangrubic
*/


#include "Arduino.h"

#include <SPI.h>

#include "customMessage.h"
#include "spiReceiver.h"


int pinSS = 53;

customMessage message;

spiReceiver<customMessage, 5> dataReceiver = spiReceiver<customMessage, 5>();

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(38400);
	
	pinMode(MISO, OUTPUT);

	message.parameterA = 0;
	message.parameterB = 0;
	message.parameterC = 0;
	message.parameterD = 0;
	
	 // turn on SPI in slave mode
	SPCR |= _BV(SPE);

	dataReceiver.setup();

	// now turn on interrupts
	SPI.attachInterrupt();

}
unsigned int di = 0;
void log(String msg) {
	
	Display.println(msg);
	
}

void log(customMessage msg) {

	log("A " + String(msg.parameterA));
	log("B " + String(msg.parameterB));
	log("C " + String(msg.parameterC));
	log("D " + String(msg.parameterD));
}

ISR(SPI_STC_vect)
{
	dataReceiver.Receive(SPDR);
}


void loop(void)
{
	if (dataReceiver.loop()) {

		for (size_t i = 0; i < dataReceiver.InstanceBufferIndex; i++)
		{
			log(dataReceiver.InstanceBuffer[i]);
		}
		dataReceiver.ClearInstanceBuffer();
	}

} 


