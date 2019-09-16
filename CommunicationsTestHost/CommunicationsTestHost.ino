/*
 Name:		CommunicationsTestHost.ino
 Created:	9/11/2019 4:24:01 PM
 Author:	gorangrubic
*/


#include "Arduino.h"

#include <SPI.h>

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>

#include <ACEMegaHostTFT.h>
#include "customMessage.h"
#include "spiReceiver.h"
#include "MathTool.h"

#include "SignalMacroInstruction.h"

ACEMegaHostTFTClass Display;

int pinSS = 53;

customMessage message;

unsigned int MSG_COUNT;
unsigned int MSG_FAIL;
unsigned int MSG_PASS;
unsigned int MSG_LOST;
int last_d = -1;


spiReceiver<SignalMacroInstruction, 30> dataReceiver = spiReceiver<SignalMacroInstruction, 30>();

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


	dataReceiver.setup(B00000111);

	// now turn on interrupts
	SPI.attachInterrupt();

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

byte overflowTest = 0;

// #define ISCOMTEST

void log(SignalMacroInstruction instruction) {

	byte b1 = instruction.data >> 24;
	byte b2 = instruction.data >> 16;
	byte b3 = instruction.data >> 8;
	byte b4 = instruction.data;

	byte s_id = (b1 & B11110000) >> 4;
	byte cc_id = b1 & B00001111;
	log("smi->" + String(s_id) + ":" + String(cc_id) + "|" + String(b2) + ":" + String(b3) + ":" + String(b4) + "[" + String(dataReceiver.InstanceBufferIndex) + "]");
	//Serial.println("smi->" + String(s_id) + ":" + String(cc_id) + "|" + String(b2) + ":" + String(b3) + ":" + String(b4) + "[" + String(index) + "]");
}

#ifdef  ISCOMTEST

void log(customMessage msg) {


	//overflowTest += 50;
	






	bool correct = false;
	
	if ((msg.parameterA + msg.parameterB + msg.parameterC + msg.parameterD) == 0) {
		correct = true;
	}
	else if ((msg.parameterA / msg.parameterD == 100) && (msg.parameterB / msg.parameterD == 200) && (msg.parameterC / msg.parameterD == 5)) {
		correct = true;
	}

	MSG_COUNT++;
	if (correct) {
		MSG_PASS++;
	}
	else {
		MSG_FAIL++;
	}

	//Display.fillScreen(GLCD_CL_BLACK);
	//Display.setCursor(0, 0);
//	di = 0;


	/*
	Serial.println("A " + String(msg.parameterA));
	Serial.println("B " + String(msg.parameterB));
	Serial.println("C " + String(msg.parameterC));
	Serial.println("D " + String(msg.parameterD));
	*/

	if (last_d == -1) {
		
	}
	else {

		int dD = (msg.parameterD - last_d);
		if (dD == 1) {}
		else if (dD == 0) {

		}
		else if (dD == -10) {

		}
		else {
			MSG_LOST += abs(dD - 1);
		}
	}
	last_d = msg.parameterD;

	//log("B " + String(msg.parameterB));
	//log("C " + String(msg.parameterC));
	//log("D " + String(msg.parameterD));
	//log("o " + String(overflowTest));
	log("M " + String(MSG_COUNT));
	//float error_rate = MathTool::GetRatio(MSG_FAIL, MSG_COUNT, 0, 0);

	log(" Err: " + String(MSG_FAIL));

	//float loss_rate = MathTool::GetRatio(MSG_LOST, MSG_COUNT, 0, 0);

	log(" Loss: " + String(MSG_LOST));
}

#endif

ISR(SPI_STC_vect)
{
	dataReceiver.Receive(SPDR);
}



void loop(void)
{
	byte result = dataReceiver.loop();
	if ((result & B11110000) == B11110000) {
		//log(String(dataReceiver.InstanceBufferIndex));

		for (size_t i = 0; i < dataReceiver.InstanceBufferIndex; i++)
		{
			log(dataReceiver.InstanceBuffer[i]);

		}
		dataReceiver.ClearInstanceBuffer();


		
	}
	else if (result != B00000000) {
		log(String(result, BIN));
	}

} 


