/*
 Name:		imbAVR.ino
 Created:	8/30/2019 11:56:49 AM
 Author:	gorangrubic
*/

#include <SPI.h>
#include <MathTool.h>

#include "spiReceiver.h"

#include "SignalMacroInstruction.h";

#include "SignalControlManager.h"

#include "SignalMacroControl.h"


SignalControlManagerClass SignalControlManager = SignalControlManagerClass();
SignalMacroControl signalMacroControl = SignalMacroControl();


#define LED A7


bool LED_ON = true;

#define BLINK_DELAY 100

void ledBeep(unsigned int blinks) {
	for (size_t i = 0; i < blinks; i++)
	{
		ledToggle();
		delay(BLINK_DELAY);
		ledToggle();
		delay(BLINK_DELAY);
	}

}

void ledToggle() {

	if (LED_ON) {
		digitalWrite(LED, HIGH);
	}
	else {
		digitalWrite(LED, LOW);
	}
	LED_ON = !LED_ON;
}

void receive(int numBytes) {}


spiReceiver<SignalMacroInstruction, 30> DataReceiver;

void setup() {

	pinMode(MISO, OUTPUT);

	SPCR |= _BV(SPE);

	DataReceiver.setup(B00000011);

	SPI.attachInterrupt();



	// for mini
	// --- SignalControlManager.CycleCompensation = 238.75;

	// for nano
	// --- SignalControlManager.CycleCompensation = 477.5;
	// ---- SignalControlManager.CycleCompensation = 16;

	SignalControlManager.CycleCompensation = 31; // 62 / 2;

	SignalControlManager.AddSignalUnit(2); // S0 -- PERKA
	SignalControlManager.AddSignalUnit(3); // S1 -- PERKB
	SignalControlManager.AddSignalUnit(4); // S2 -- FLT_RES
	SignalControlManager.AddSignalUnit(5); // S3 -- FLT_RESB
	SignalControlManager.AddSignalUnit(6); // S4 -- WFA
	SignalControlManager.AddSignalUnit(7); // S5 -- WFB
	

	//TCCR2B = (TCCR2B & B11111000) | 0x03; // setting divisor at timer2 to 16

	TCCR2B = (TCCR2B & B11111000) | 0x02; // setting divisor at timer2 to 8

	//TCCR2B = (TCCR2B & B11111000) | 0x01; // setting divisor at timer2 to 1

	TIMSK2 = (TIMSK2 & B11111110) | 0x01; // enabling overvlow interrupt

	
}

ISR(SPI_STC_vect)
{
	DataReceiver.Receive(SPDR);
}


ISR(TIMER2_OVF_vect) {
	SignalControlManager.loop();
	
}

String input = "";

// the loop function runs over and over again until power down or reset
void loop() {
  
	byte result = DataReceiver.loop();

	if ((result & B11110000) == B11110000) {
		for (size_t i = 0; i < DataReceiver.InstanceBufferIndex; i++)
		{
			signalMacroControl.Run(DataReceiver.InstanceBuffer[i], &SignalControlManager);
			
		}
		DataReceiver.ClearInstanceBuffer();
	}
	else if (result != B00000000) {
		
	}
	
}
