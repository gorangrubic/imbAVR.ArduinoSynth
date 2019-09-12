#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "spiLinkBuffer.h"


template<typename TData, byte ISize>
class spiReceiver
{

	boolean process_it;

	void TrimBuffer(byte lefttrim);

	void AddInstanceBuffer(TData instance);

	byte transactionSize;

public:
	
	void setup();

	byte InstanceBufferIndex = 0;
	TData InstanceBuffer[ISize];

	void ClearInstanceBuffer();

	byte DataBufferIndex = 0;
	char DataBuffer[(sizeof(TData) + 2 ) * 2];

	boolean loop();



	void Receive(byte input);
};

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::TrimBuffer(byte lefttrim)
{
	if (DataBufferIndex == 0) return;
	if (lefttrim >= DataBufferIndex) {
		DataBufferIndex = 0;
		return;
	}
	for (size_t i = 0; i < lefttrim; i++)
	{
		DataBuffer[i] = DataBuffer[lefttrim + i];
	}
	DataBufferIndex = DataBufferIndex - lefttrim;

	
	return;
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::AddInstanceBuffer(TData instance)
{
	if (InstanceBufferIndex < ISize) {
		InstanceBuffer[InstanceBufferIndex] = instance;
		InstanceBufferIndex++;
	}
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::setup()
{
	transactionSize = sizeof(TData);

	//pinMode(MISO, OUTPUT);
	// turn on SPI in slave mode
//	SPCR |= _BV(SPE);

	
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::ClearInstanceBuffer()
{
	InstanceBufferIndex = 0;
}

template<typename TData, byte ISize>
inline boolean spiReceiver<TData, ISize>::loop()
{

	if (process_it) {

		while (DataBufferIndex >= transactionSize) {

			spiLinkDataInstance<TData> wrapper;

			for (size_t i = 0; i < transactionSize; i++)
			{
				wrapper.bytes[i] = DataBuffer[i];
			}

			AddInstanceBuffer(wrapper.instance);

			TrimBuffer(transactionSize);
		}

		return true;
	}
	else {
		return false;
	}
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::Receive(byte c)
{
	DataBuffer[DataBufferIndex] = c;
	DataBufferIndex++;
	if (DataBufferIndex >= transactionSize) {
		process_it = true;
	}
}
