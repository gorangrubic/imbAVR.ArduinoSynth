#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

template<typename TData>
union spiLinkDataInstance {
	TData instance;
	unsigned char bytes[sizeof(TData)];
};

#define SPI_TRANSFER_PROTOCOL_USECONTROLBYTE B00000001
#define SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE B00000011
#define SPI_TRANSFER_PROTOCOL_DISABLEBUFFERTRIM B00000100

