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


template<typename TData, byte ISize>
class spiLinkBuffer
{
	byte InstanceBufferIndex = 0;
	TData InstanceBuffer[ISize];

	byte DataBufferIndex = 0;
	char DataBuffer[(sizeof(TData)*2)+5];

	boolean process_it;

public:

};

