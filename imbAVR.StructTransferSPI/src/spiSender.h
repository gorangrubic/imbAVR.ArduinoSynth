#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "SPI.h"

#include "spiLinkBuffer.h"


template<typename TData>
class spiSender
{	
	/// <summary>
	/// Chip-select pin
	/// </summary>
	byte pinSS;

	byte pinSSPostDelay;

public:

	byte protocol;

	//spiSender(byte _pinSS);

	void setup(byte _pinSS, byte protocol);

	spiSender();
	
	void Send(TData data);

};

template<typename TData>
inline spiSender<TData>::spiSender(byte _pinSS)
{
	pinSS = _pinSS;
	pinMode(pinSS, OUTPUT);
}

template<typename TData>
inline void spiSender<TData>::Send(TData data)
{

	spiLinkDataInstance<TData> wrapper;
	wrapper.instance = data;

	digitalWrite(pinSS, LOW);
	
	if (protocol == B00000000) {

		for (size_t i = 0; i < sizeof(TData); i++)
		{
			SPI.transfer(wrapper.bytes[i]);
		}

	}
	else {



		byte sendTimes = 1;

		if ((protocol & B00000010) == B00000010) sendTimes++;

		while (sendTimes > 0) {

			byte controlByte = 0;
			for (size_t i = 0; i < sizeof(TData); i++)
			{
				byte b = wrapper.bytes[i];
				if ((protocol & B00000001) == B00000001) {
					controlByte = controlByte + b;
				}
				SPI.transfer(b);
			}

			if ((protocol & B00000001) == B00000001) {
				SPI.transfer(controlByte);
			}
			sendTimes--;
		}
	}

	delay(pinSSPostDelay);
	digitalWrite(pinSS, HIGH);

}
