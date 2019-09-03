/*
 Name:		imbAVR.ino
 Created:	8/30/2019 8:52:37 PM
 Author:	gorangrubic
*/

// the setup function runs once when you press reset or power the board


#include <EasyTransferI2C.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <SoftEasyTransfer.h>

#include <SignalControlManager.h>
#include <SignalControlUnit.h>
#include <SignalControlLink.h>



//define slave i2c address
#define I2C_SLAVE_ADDRESS 9
unsigned int tIndex = 0;
unsigned int demoIndex = 0;

SignalControlLink link;

#define LED 2
#define LEDB 3

#define SIGNAL_DEVICE_SERIAL_RX 8
#define SIGNAL_DEVICE_SERIAL_TX 9
#define SIGNAL_DEVICE_BAUDRATE  19200

SoftwareSerial SoftSerial(SIGNAL_DEVICE_SERIAL_RX, SIGNAL_DEVICE_SERIAL_TX);

void setup() {

	demoIndex = 0;

	link.setup();
	

	//link.setupMaster(I2C_SLAVE_ADDRESS);
	Serial.begin(DEFAULT_BAUDRATE);

	SoftSerial.begin(SIGNAL_DEVICE_BAUDRATE);

	//link.serialOut = &Serial;

	pinMode(LED, OUTPUT);
	pinMode(LEDB, OUTPUT);
}

bool LED_ON = true;

#define BLINK_DELAY 25

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


#define TPERIOD 1
#define DEMOLIMIT 25

// the loop function runs over and over again until power down or reset
void loop() {

	

	bool doBlink = true;

	

	if (tIndex == 0) {
		digitalWrite(LEDB, HIGH);

		switch (demoIndex)
		{

		case 1:
			// set tones
			
			link.send(&SoftSerial, 0, 55);
			link.send(&SoftSerial, 1, 73);
			link.send(&SoftSerial, 2, 98);
			link.send(&SoftSerial, 3, 110);
			link.send(&SoftSerial, 4, 220);

			break;


		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
			link.send(&SoftSerial, 0, 110, WAVEFORM_HALFCYCLE, 0);
			link.send(&SoftSerial, 1, 110, WAVEFORM_HALFCYCLE, demoIndex - 6);

			break;

		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
			link.send(&SoftSerial, 0, 110, WAVEFORM_HALFCYCLE, 0);
			link.send(&SoftSerial, 1, 110, WAVEFORM_HALFCYCLE, demoIndex - 16, true, true, false, true);
			break;


		default:
			doBlink = false;
			break;
		}
	
		if (doBlink)
		{
			Serial.print("Instruction: ");
			Serial.println(demoIndex);

			//Serial.println(SignalControlManagerClass::Describe(link.instruction));
			ledBeep(demoIndex);
		}
	}

	


	if (tIndex == 0) {
		digitalWrite(LEDB, LOW);
	}

	tIndex++;

	if (tIndex > TPERIOD) {
		tIndex = 0;
		demoIndex++;
	}

	if (demoIndex > DEMOLIMIT) {
		demoIndex = 0;
	}

	ledBeep(1);

	

	delay(1000);
}

