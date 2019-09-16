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
/// Utility class for data buffering. Buffer with <c>TData</c>, of size <c>ISize</c>. Max buffer size: 256
/// </summary>
template<typename TData, byte ISize>
class spiLinkBuffer {

	
public:

	byte bufferIndex = 0;

	TData Data[ISize];

	/// <summary>
	/// Returns current buffer index (i.e. allocated space in the buffer)
	/// </summary>
	/// <returns></returns>
	byte GetIndex();


	/// <summary>
	/// Clears the buffer
	/// </summary>
	void ClearAll();

	/// <summary>
	/// Gets the last entry and removes it from buffer
	/// </summary>
	/// <returns></returns>
	TData GetLast();


	/// <summary>
	/// Removes specified number of entries from beginning to <c>lefttrim</c>, copies data from <c>lefttrim</c> to buffer index to position 0, and sets buffer index to 0
	/// </summary>
	/// <param name="lefttrim">The lefttrim.</param>
	void TrimBuffer(byte lefttrim);

	/// <summary>
	/// Adds entry to buffer
	/// </summary>
	/// <param name="instance">The instance.</param>
	/// <returns>true - if the entry is added, false if buffer is full - so couldn't add the entry</returns>
	bool Add(TData instance);

};

#define SPI_TRANSFER_PROTOCOL_USECONTROLBYTE B00000001
#define SPI_TRANSFER_PROTOCOL_DOUBLESENDANDCONTROLBYTE B00000011
#define SPI_TRANSFER_PROTOCOL_DISABLEBUFFERTRIM B00000100

template<typename TData, byte ISize>
inline byte spiLinkBuffer<TData, ISize>::GetIndex()
{
	return bufferIndex;
}

template<typename TData, byte ISize>
inline void spiLinkBuffer<TData, ISize>::ClearAll()
{
	bufferIndex = 0;
}

template<typename TData, byte ISize>
inline TData spiLinkBuffer<TData, ISize>::GetLast()
{
	TData output;

	if (bufferIndex > 1) {
		output = Data[bufferIndex - 1];
		bufferIndex--;
	}

	return output;

}

template<typename TData, byte ISize>
inline void spiLinkBuffer<TData, ISize>::TrimBuffer(byte lefttrim)
{
	if (bufferIndex == 0) return;
	if (lefttrim >= bufferIndex) {
		bufferIndex = 0;
		return;
	}
	for (size_t i = 0; i < lefttrim; i++)
	{
		Data[i] = Data[lefttrim + i];
	}
	bufferIndex = bufferIndex - lefttrim;
}


template<typename TData, byte ISize>
inline bool spiLinkBuffer<TData, ISize>::Add(TData instance)
{
	if (bufferIndex < ISize) {
		Data[bufferIndex] = instance;
		bufferIndex++;
		return true;
	}
	return false;
}