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

void digPotCluster::CheckAndWrite(int whichPin, byte dp_value) {
	if (lastValues[whichPin] != dp_value) {
		Write(whichPin, dp_value);
		lastValues[whichPin] = dp_value;
	}
}

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

// the heart of the program
void digPotCluster::SetOut(byte myDataOut) {
	// This shifts 8 bits out MSB first, 
	//on the rising edge of the clock,
	//clock idles low

	//internal function setup
	int i = 0;
	int pinState;


	//clear everything out just in case to
	//prepare shift register for bit shifting
	digitalWrite(dataPin, 0);
	digitalWrite(clockPin, 0);

	//for each bit in the byte myDataOut�
	//NOTICE THAT WE ARE COUNTING DOWN in our for loop
	//This means that %00000001 or "1" will go through such
	//that it will be pin Q0 that lights. 
	for (i = 7; i >= 0; i--) {
		digitalWrite(clockPin, 0);

		//if the value passed to myDataOut and a bitmask result 
		// true then... so if we are at i=6 and our value is
		// %11010100 it would the code compares it to %01000000 
		// and proceeds to set pinState to 1.
		if (myDataOut & (1 << i)) {
			pinState = 1;
		}
		else {
			pinState = 0;
		}

		//Sets the pin to HIGH or LOW depending on pinState
		digitalWrite(dataPin, pinState);
		//register shifts bits on upstroke of clock pin  
		digitalWrite(clockPin, 1);
		//zero the data pin after shift to prevent bleed through
		digitalWrite(dataPin, 0);
	}

	//stop shifting
	digitalWrite(clockPin, 0);
}



void digPotCluster::Write(int whichPin, byte dp_value) {
	// the bits you want to send
	byte bitsToSend = 0B11111111;


	digitalWrite(latchPin, LOW);

	bitWrite(bitsToSend, whichPin, 0);


	SetOut(bitsToSend);


	digitalWrite(latchPin, HIGH);



	SPI.transfer(B00010001); // This tells the chip to set the pot
	SPI.transfer(dp_value);     // This tells it the pot position


	digitalWrite(latchPin, LOW);



	bitWrite(bitsToSend, whichPin, 1);

	SetOut(bitsToSend);

	digitalWrite(latchPin, HIGH);




}
