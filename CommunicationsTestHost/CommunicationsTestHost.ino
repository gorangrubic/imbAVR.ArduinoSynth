/*
 Name:		CommunicationsTestHost.ino
 Created:	9/11/2019 4:24:01 PM
 Author:	gorangrubic
*/

#include "customMessage.h"
#include "Arduino.h"

// the setup function runs once when you press reset or power the board

#include <SPI.h>
#include <SoftwareSerial.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>


#include <ACEMegaHostTFT.h>

#include <DevicePort.h>
#include <TransferLink.h>

#include "customMessage.h"

#include "spiReceiver.h"

ACEMegaHostTFTClass Display;

int pinSS = 53;

customMessage message;

char buf[100];
volatile byte pos;
volatile boolean process_it;

bool newMessage = false;


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

	// get ready for an interrupt 
	pos = 0;   // buffer empty
	process_it = false;

	
	
	Display.setTextSize(2);
	Display.begin();
	Display.setRotation(1);
	Display.fillScreen(GLCD_CL_BLACK);

	Display.println("Started");
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
	/*if (newMessage) {

		log(message);
		log(pos);
		newMessage = false;
	}*/

	if (dataReceiver.loop()) {
		//log(String(dataReceiver.InstanceBufferIndex));

		for (size_t i = 0; i < dataReceiver.InstanceBufferIndex; i++)
		{
			log(i);
			log(dataReceiver.InstanceBuffer[i]);

		}
		dataReceiver.ClearInstanceBuffer();
	}

	/*if (dataReceiver.InstanceBufferIndex > 3) {
		
	}*/
/*
	if (process_it)
	{
		buf[pos] = 0;
		customMessageUnion msgUnion;

		for (size_t i = 0; i < sizeof(b_s); i++)
		{
			msgUnion.bytes[i] = buf[i];
		}

		message = msgUnion.message;
		newMessage = true;
		pos = 0;
		process_it = false;
	}  */
} 


