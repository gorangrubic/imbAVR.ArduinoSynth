// 
// 
// 

#include "ampControlCluster.h"

void ampControlCluster::init(byte pinClock, byte pinVol1, byte pinVol2, byte pinVol3) {
	pin_clock = pinClock;
	pin_vol1 = pinVol1;
	pin_vol2 = pinVol2;
	pin_vol3 = pinVol3;

	pinMode(pin_clock, OUTPUT);
	pinMode(pin_vol1, OUTPUT);
	pinMode(pin_vol2, OUTPUT);
	pinMode(pin_vol3, OUTPUT);
}

byte ampControlCluster::checkVolume(byte volume) {

	return (volume > 100) ? 0 : (((volume * 83) / -100) + 83);
}

uint16_t ampControlCluster::packData(byte volume, byte channel) {

	uint16_t data = 0;

	volume = (volume > 100) ? 0 : (((volume * 83) / -100) + 83);

	data |= (channel << 0); // D0 (channel select: 0=ch1, 1=ch2)
	data |= (1 << 1); // D1 (individual/both select: 0=both, 1=individual)
	data |= ((21 - (volume / 4)) << 2); // D2...D6 (ATT1: coarse attenuator: 0,-4dB,-8dB, etc.. steps of 4dB)
	data |= ((3 - (volume % 4)) << 7); // D7...D8 (ATT2: fine attenuator: 0...-1dB... steps of 1dB)
	data |= (0b11 << 9); // D9...D10 // D9 & D10 must both be 1

	return data;

}

void ampControlCluster::setVolume(byte vol1A, byte vol1B, byte vol2A, byte vol2B, byte vol3A, byte vol3B) 
{
	setVolume(vol1A, vol2A, vol3A, 0);
	setVolume(vol1B, vol2B, vol3B, 1);

}

void ampControlCluster::setVolume(byte vol1, byte vol2, byte vol3, byte channel)
{
	uint8_t bits;
	
	uint16_t data1 = packData(vol1, channel); // control word is built by OR-ing in the bits
	uint16_t data2 = packData(vol2, channel);
	uint16_t data3 = packData(vol3, channel);

	// convert attenuation to volume
	//volume = (volume > 100) ? 0 : (((volume * 83) / -100) + 83); // remember 0 is full volume!

	//data |= (channel << 0); // D0 (channel select: 0=ch1, 1=ch2)
	//data |= (both << 1); // D1 (individual/both select: 0=both, 1=individual)
	//data |= ((21 - (volume / 4)) << 2); // D2...D6 (ATT1: coarse attenuator: 0,-4dB,-8dB, etc.. steps of 4dB)
	//data |= ((3 - (volume % 4)) << 7); // D7...D8 (ATT2: fine attenuator: 0...-1dB... steps of 1dB)
	//data |= (0b11 << 9); // D9...D10 // D9 & D10 must both be 1

	for (bits = 0; bits < 11; bits++) { // send out 11 control bits
		_delay_us(2); // pg.4 - M62429P/FP datasheet
		digitalWrite(pin_vol1, LOW);
		digitalWrite(pin_vol2, LOW);
		digitalWrite(pin_vol3, LOW);
		_delay_us(2);
		digitalWrite(pin_clock, LOW);
		// digitalWrite(_CLK_PIN, 0);
		_delay_us(2);
		digitalWrite(pin_vol1, (data1 >> bits) & 0x01);
		digitalWrite(pin_vol2, (data2 >> bits) & 0x01);
		digitalWrite(pin_vol3, (data3 >> bits) & 0x01);
		//digitalWrite(_DAT_PIN, (data >> bits) & 0x01);
		_delay_us(2);

		digitalWrite(pin_clock, HIGH);
		

	//	digitalWrite(_CLK_PIN, 1);
	}

	_delay_us(2);
	digitalWrite(pin_vol1, 1);
	digitalWrite(pin_vol2, 1);
	digitalWrite(pin_vol3, 1);

	//digitalWrite(_DAT_PIN, 1); // final clock latches data in
	_delay_us(2);
	digitalWrite(pin_clock, LOW);

	//digitalWrite(_CLK_PIN, 0);

	//return data; // return bit pattern in case you want it :)
}
