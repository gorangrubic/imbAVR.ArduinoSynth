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



