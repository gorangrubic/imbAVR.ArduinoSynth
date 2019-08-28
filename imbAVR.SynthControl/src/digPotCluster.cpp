#include "digPotCluster.h"



void digPotCluster::init(byte latch_pin, byte clock_pin, byte data_pin)
{
	latchPin = latch_pin;
	clockPin = clock_pin;
	dataPin = data_pin;

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);

	for (size_t i = 0; i < 8; i++)
	{
		Write(i, 0);
		lastValues[i] = 0;
	}

}

void digPotCluster::Write(byte dp1, byte dp2, byte dp3, byte dp4, byte dp5, byte dp6, byte dp7, byte dp8)
{

	CheckAndWrite(0, dp1);
	CheckAndWrite(1, dp2);
	CheckAndWrite(2, dp3);
	CheckAndWrite(3, dp4);
	CheckAndWrite(4, dp5);
	CheckAndWrite(5, dp6);
	CheckAndWrite(6, dp7);
	CheckAndWrite(7, dp8);

}

void digPotCluster::CheckAndWrite(byte dp_id, byte dp_value) {
	if (dp_id > 7) return;

	if (lastValues[dp_id] != dp_value) {
		Write(dp_id, dp_value);
		lastValues[dp_id] = dp_value;
	}
}

#ifdef DEBUG_CODE

void digPotCluster::Debug() {

	byte bitsToSend = 0B00000000;

	
	for (size_t i = 0; i < 8; i++)
	{
		digitalWrite(latchPin, LOW);

		bitWrite(bitsToSend, i, 0);
		SetOut(bitsToSend);

		digitalWrite(latchPin, HIGH);

		delay(1000);


		digitalWrite(latchPin, LOW);

		bitWrite(bitsToSend, i, 1);
		SetOut(bitsToSend);

		delay(1000);

		digitalWrite(latchPin, HIGH);
	}

}

#endif



void digPotCluster::SetOut(byte data) {


	int i = 0;
	int pinState;


	digitalWrite(dataPin, 0);
	digitalWrite(clockPin, 0);


	for (i = 7; i >= 0; i--) {
		digitalWrite(clockPin, 0);


		if (data & (1 << i)) {
			pinState = 1;
		}
		else {
			pinState = 0;
		}

		digitalWrite(dataPin, pinState);

		digitalWrite(clockPin, 1);
	
		digitalWrite(dataPin, 0);
	}


	digitalWrite(clockPin, 0);
}



void digPotCluster::Write(byte dp_id, byte dp_value) {
	
	if (dp_id > 7) return;

	byte bitsToSend = 0B11111111;


	digitalWrite(latchPin, LOW);

	bitWrite(bitsToSend, dp_id, 0);


	SetOut(bitsToSend);


	digitalWrite(latchPin, HIGH);



	SPI.transfer(B00010001); 
	SPI.transfer(dp_value);    


	digitalWrite(latchPin, LOW);



	bitWrite(bitsToSend, dp_id, 1);

	SetOut(bitsToSend);

	digitalWrite(latchPin, HIGH);




}
