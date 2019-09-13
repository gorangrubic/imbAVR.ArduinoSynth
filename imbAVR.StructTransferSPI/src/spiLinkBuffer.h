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


/// <summary>
/// Buffer with <c>TData</c>, of size <c>ISize</c>. Max buffer size: 256
/// </summary>
template<typename TData, byte ISize>
class spiLinkBuffer {

	byte bufferIndex = 0;
public:
	
	TData Data[ISize];

	/// <summary>
	/// Returns current buffer index (i.e. allocated space in the buffer)
	/// </summary>
	/// <returns></returns>
	byte GetIndex();

	/// <summary>
	/// Removes specified number of entries from beginning to <c>lefttrim</c>, copies data from <c>lefttrim</c> to buffer index to position 0, and sets buffer index to 0
	/// </summary>
	/// <param name="lefttrim">The lefttrim.</param>
	void TrimBuffer(byte lefttrim);	
	/// <summary>
	/// Adds entry to buffer
	/// </summary>
	/// <param name="instance">The instance.</param>
	void Add(TData instance);

};

#define SPI_TRANSFER_PROTOCOL_USECONTROLBYTE B00000001
#define SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE B00000011
#define SPI_TRANSFER_PROTOCOL_DISABLEBUFFERTRIM B00000100

