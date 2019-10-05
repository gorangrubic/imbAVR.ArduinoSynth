/*
 Name:		imbAVR.ino
 Created:	8/30/2019 11:56:49 AM
 Author:	gorangrubic
*/

#define SERIAL_DEBUG_MODE 
#define _SERIAL_DEBUG_MODEFULL

#include "LinkQualityMetrics.h"
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


spiReceiver<SignalMacroInstruction, 60> DataReceiver;

void setup() {
	Serial.begin(38400);
	pinMode(MISO, OUTPUT);
	pinMode(MOSI, OUTPUT);

	SPCR |= _BV(SPE);

	DataReceiver.setup(B00011111);

	SPI.attachInterrupt();

	

	// for mini
	// --- SignalControlManager.CycleCompensation = 238.75;

	// for nano
	// --- SignalControlManager.CycleCompensation = 477.5;
	// ---- SignalControlManager.CycleCompensation = 16;

	//SignalControlManager.CycleCompensation = 2; // 62 / 2;

	SignalControlManager.CycleCompensation = 250.75;
	SignalControlManager.TimerPrescalar = TIMER_PRESCALAR_512;

	SignalControlManager.AddSignalUnit(2); // S0 -- PERKA
	SignalControlManager.AddSignalUnit(3); // S1 -- PERKB
	SignalControlManager.AddSignalUnit(4); // S2 -- FLT_RES
	SignalControlManager.AddSignalUnit(5); // S3 -- FLT_RESB
	SignalControlManager.AddSignalUnit(6); // S4 -- WFA
	SignalControlManager.AddSignalUnit(7); // S5 -- WFB

	SignalControlManager.SignalUnits[0].IsPitchSlave = true;
	SignalControlManager.SignalUnits[0].IsPositiveRelation = true;
	SignalControlManager.SignalUnits[0].IsRelativeDistanceMode = true;
	SignalControlManager.SignalUnits[0].pwmContinualMode = true;
	SignalControlManager.SignalUnits[0].pwmByte = 127;
	SignalControlManager.SignalUnits[0].delta_freq = 0;
	SignalControlManager.PerformPitch(120, &SignalControlManager.SignalUnits[0]);

	SignalControlManager.SignalUnits[1].IsPitchSlave = true;
	SignalControlManager.SignalUnits[1].IsPositiveRelation = true;
	SignalControlManager.SignalUnits[1].IsRelativeDistanceMode = true;
	SignalControlManager.SignalUnits[1].pwmContinualMode = true;
	SignalControlManager.SignalUnits[1].pwmByte = 127;
	SignalControlManager.SignalUnits[1].delta_freq = 24;
	SignalControlManager.PerformPitch(12, &SignalControlManager.SignalUnits[1]);

	SignalControlManager.SignalUnits[2].IsPitchSlave = true;
	SignalControlManager.SignalUnits[2].IsPositiveRelation = false;
	SignalControlManager.SignalUnits[2].IsRelativeDistanceMode = false;
	SignalControlManager.SignalUnits[2].pwmContinualMode = false;
	SignalControlManager.SignalUnits[2].delta_freq = 0;
	SignalControlManager.SignalUnits[2].pwmByte = B00001111;
	SignalControlManager.PerformPitch(30, &SignalControlManager.SignalUnits[2]);

	SignalControlManager.SignalUnits[3].isOn = false;
	SignalControlManager.SignalUnits[3].isDisabled = true;

	SignalControlManager.SignalUnits[4].IsPitchSlave = true;
	SignalControlManager.SignalUnits[4].pwmContinualMode = true;
	SignalControlManager.SignalUnits[4].IsPositiveRelation = true;
	SignalControlManager.SignalUnits[4].IsRelativeDistanceMode = true;
	SignalControlManager.SignalUnits[4].pwmByte = 127;
	SignalControlManager.SignalUnits[4].delta_freq = 12;
	SignalControlManager.PerformPitch(110, &SignalControlManager.SignalUnits[4]);

	SignalControlManager.SignalUnits[5].IsPitchSlave = true;
	SignalControlManager.SignalUnits[5].pwmContinualMode = true;
	SignalControlManager.SignalUnits[5].IsPositiveRelation = true;
	SignalControlManager.SignalUnits[5].IsRelativeDistanceMode = true;
	SignalControlManager.SignalUnits[5].pwmByte =127;
	
	SignalControlManager.PerformPitch(110, &SignalControlManager.SignalUnits[5]);
	
	 TCCR2B = (TCCR2B & B11111000) | SignalControlManager.TimerPrescalar; // setting divisor at timer2 to 128

	//TCCR2B = (TCCR2B & B11111000) | 0x04; // setting divisor at timer2 to 16

	//TCCR2B = (TCCR2B & B11111000) | 0x02; // setting divisor at timer2 to 8

	//TCCR2B = (TCCR2B & B11111000) | 0x01; // setting divisor at timer2 to 1

	TIMSK2 = (TIMSK2 & B11111110) | 0x01; // enabling overvlow interrupt

	SignalControlManager.setup();

	Serial.println("start");
}

ISR(SPI_STC_vect)
{
	
	DataReceiver.Receive(SPDR);
}


ISR(TIMER2_OVF_vect) {
	 SignalControlManager.loop();
	
}

LinkQualityMetrics linkQuality;

// the loop function runs over and over again until power down or reset
void loop() {
  
	byte result = DataReceiver.loop();

#ifdef SERIAL_DEBUG_MODE
	if (linkQuality.Count(result)) {
		linkQuality.ShortReport(&Serial);
	}
#endif

	if (bitRead(result,7) == 1) {

		for (size_t i = 0; i < DataReceiver.InstanceBufferIndex; i++)
		{
#ifdef SERIAL_DEBUG_MODEFULL
			SignalMacroInstruction instruction = DataReceiver.InstanceBuffer[i];

			byte b1 = instruction.data >> 24;
			byte b2 = instruction.data >> 16;
			byte b3 = instruction.data >> 8;
			byte b4 = instruction.data;

			byte s_id = (b1 & B11110000) >> 4;
			byte cc_id = b1 & B00001111;
			Serial.println("smi<-" + String(s_id) + ":" + String(cc_id) + "|" + String(b2, BIN) + ":" + String(b3) + ":" + String(b4) + "[" + String(i) + "]" + String(DataReceiver.DataBufferIndex));

			signalMacroControl.Run(instruction, &SignalControlManager);
#else
			SignalMacroInstruction instruction = DataReceiver.InstanceBuffer[i];
			signalMacroControl.Run(instruction, &SignalControlManager);

			//signalMacroControl.Run(DataReceiver.InstanceBuffer[i], &SignalControlManager);
#endif // SERIAL_DEBUG_MODE

		}
		DataReceiver.ClearInstanceBuffer();
		DataReceiver.DataBufferIndex = 0;
	}
	else if (result != 0) {
#ifdef SERIAL_DEBUG_MODEFULL
	//	Serial.println(String(result, BIN) + " : " + String(DataReceiver.DataBufferIndex));
#endif
	}
	
	delay(25);
	
}
