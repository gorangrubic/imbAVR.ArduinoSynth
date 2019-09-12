/*
 Name:		imbAVR.ino
 Created:	8/30/2019 11:56:49 AM
 Author:	gorangrubic
*/

#include <MathTool.h>

#include "spiReceiver.h"

#include "SignalInstruction.h"

#include "SignalControlManager.h"
#include "SignalControlUnit.h"
#include "SignalControlLink.h"



#define SIGNAL_DEVICE_SERIAL_RX 8
#define SIGNAL_DEVICE_SERIAL_TX 9
#define SIGNAL_DEVICE_BAUDRATE 19200

// how many hardware clock ticks is counted as single software tick



SignalControlManagerClass SignalControlManager = SignalControlManagerClass();

//SignalControlLink link;



//define slave i2c address
#define I2C_SLAVE_ADDRESS 9


#define LED A7
#define LEDB A6




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


spiReceiver<SignalChangeInstruction, 10> DataReceiver;

void setup() {

	DataReceiver.setup(B00000011);

	

	//pinMode(LED, OUTPUT);
	
	//link.setup(SIGNAL_DEVICE_SERIAL_RX, SIGNAL_DEVICE_SERIAL_TX, SIGNAL_DEVICE_BAUDRATE);
	
	//link.setupSlave(I2C_SLAVE_ADDRESS);
	//define handler function on receiving data
	//Wire.onReceive(receive);


	//SoftSerial.listen();
	

	//link.serialOut = &Serial;
	//link.SerialReport = false;

	//ledBeep(10);

	// for mini
	//SignalControlManager.CycleCompensation = 238.75;



	// for nano
	//SignalControlManager.CycleCompensation = 477.5;

	//SignalControlManager.CycleCompensation = 16;

	SignalControlManager.CycleCompensation = 31; // 62 / 2;

	SignalControlManager.AddSignalUnit(2); // S0
	SignalControlManager.AddSignalUnit(3); // S1
	SignalControlManager.AddSignalUnit(4); // S2
	SignalControlManager.AddSignalUnit(5); // S3
	SignalControlManager.AddSignalUnit(6); // S4
	SignalControlManager.AddSignalUnit(7); // S5

	//SignalControlManager.AddSignalUnit(8); // S6
	//SignalControlManager.AddSignalUnit(9); // S7


	SignalInstruction demoInstruction = SignalInstruction();

	demoInstruction.Set(0, 110, B11110000, 0, true, true, true, true);
	SignalControlManager.Perform(demoInstruction);


	demoInstruction.Set(1, 220, B11110000, 0, true, true, true, true);
	SignalControlManager.Perform(demoInstruction);


	//TCCR2B = (TCCR2B & B11111000) | 0x03; // setting divisor at timer2 to 16

	TCCR2B = (TCCR2B & B11111000) | 0x02; // setting divisor at timer2 to 8

	//TCCR2B = (TCCR2B & B11111000) | 0x01; // setting divisor at timer2 to 1

	TIMSK2 = (TIMSK2 & B11111110) | 0x01; // enabling overvlow interrupt

	//SignalControlManager.DescribeAll(&Serial);
	//Serial.println("Starting");
	
}





ISR(TIMER2_OVF_vect) {
	SignalControlManager.loop();
	
}

String input = "";

// the loop function runs over and over again until power down or reset
void loop() {
  

	/*if (SoftSerial.available()) {
		input = SoftSerial.readString();
		Serial.println("ss:" + input);
	} */
	
	//else if (Serial.available()) {

	////String input = link.SoftSerial.readString();

	//	input = Serial.readString();
	//	Serial.println("hs:" + input);
	//}
	//


	/*if (link.ByteCodeProtocol) {

		if (SoftSerial.available()) {
			byte b = SoftSerial.read();
			SignalControlManager.Receive(b);

			if (link.ConfirmationProtocol) SoftSerial.write(b);
		}

	}
	else {


		if (SoftSerial.available() > 5) {

			input += SoftSerial.readString();
			SoftSerial.flushInput();
		}

		while (input.indexOf("[") > -1) {

			byte lastIndex = link.instructionIndex;

			input = link.readStringChar(input);

			if (lastIndex != link.instructionIndex) {

				SignalControlManager.Perform(link.instruction);

			}


		}

	}*/
	
}
