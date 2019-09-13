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
	
	byte protocol;

	spiReceiver();

	/// <summary>
	/// Call setup after adjusting the protocol bytes. 
	/// </summary>
	void setup(byte _protocol=B00000000);

	byte InstanceBufferIndex = 0;
	TData InstanceBuffer[ISize];

	void ClearInstanceBuffer();

	byte DataBufferIndex = 0;
	char DataBuffer[(sizeof(TData) + 2 ) * ISize];

	/* returns TRUE if new instance was received, this should be called from the main loop() */
	byte loop();


	/* this should be called from SPI interupt */
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
inline spiReceiver<TData, ISize>::spiReceiver()
{
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::setup(byte _protocol)
{
	protocol = _protocol;

	transactionSize = sizeof(TData);

	if ((protocol & B00000001) == B00000001) {
		transactionSize++;
	}

	if ((protocol & B00000010) == B00000010) {
		transactionSize += transactionSize;
	}
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::ClearInstanceBuffer()
{
	InstanceBufferIndex = 0;
}

#define SPIRECEIVER_LOOP_RESULT_RECEIVING B00000000
#define SPIRECEIVER_LOOP_RESULT_RECEIVED B00000001
#define SPIRECEIVER_LOOP_RESULT_FIRSTOK B00000011
#define SPIRECEIVER_LOOP_RESULT_FIRSTFAIL B00000010
#define SPIRECEIVER_LOOP_RESULT_SECONDFAIL_FIRSTFAIL B00001010
#define SPIRECEIVER_LOOP_RESULT_SECONDOK_FIRSTFAIL B00001110
// SPIRECEIVER_LOOP_RESULT_SECONDOK_FIRSTFAIL B1111xxxx -- if success

template<typename TData, byte ISize>
inline byte spiReceiver<TData, ISize>::loop()
{

	if (process_it) {

		

		if (bitRead(protocol, 0) == 0) {
			while (DataBufferIndex >= transactionSize) {

				spiLinkDataInstance<TData> wrapper;

				for (size_t i = 0; i < transactionSize; i++)
				{
					wrapper.bytes[i] = DataBuffer[i];
				}

				AddInstanceBuffer(wrapper.instance);

				if (bitRead(protocol, 2) == 0) {
					TrimBuffer(transactionSize);
				}
				else {
					DataBufferIndex = 0;
				}
				
			}
			return B11110011;
		}



		byte result = B00000000;

		

		boolean isOk = false;

		//if ((protocol & B00000010) == B000000010) readTimes++;

		spiLinkDataInstance<TData> wrapper;

		
		if (DataBufferIndex >= transactionSize) {

			byte readTimes = 1;

			unsigned int readIndex = 0;
			unsigned int readIteration = 0;

			if ((protocol & B00000010) == B00000010) readTimes++;

			while (readIteration < readTimes) {

				isOk = false;

				byte controlByte = 0;
				byte controlSentByte = 0;

				for (size_t i = 0; i < sizeof(TData); i++)
				{
					byte b = DataBuffer[readIndex];
					if ((protocol & B00000001) == B00000001) {
						controlByte = controlByte + b;
					}
					wrapper.bytes[i] = b;
					readIndex++;
				}

				if ((protocol & B00000001) == B00000001) {
					
					controlSentByte = DataBuffer[readIndex];

					if (readIteration > 0) result = result << 2;

					if (controlByte == controlSentByte) {

						result |= B00000011;
						isOk = true;
					}
					else {
						result |= B00000010;
					}
					readIndex++;
				}
				else {
					result |= B00000011;
					isOk = true;
				}

				if (isOk) {

					result |= B11110000;

					AddInstanceBuffer(wrapper.instance);

					DataBufferIndex = 0;

					return result;
				}
				

				readIteration++;

			}

			DataBufferIndex = 0;

			//result = B00000001;

			////while (readTimes > 0) {

			//byte controlByte = 0;
			//byte controlSentByte = 0;

			//for (size_t i = 0; i < sizeof(TData); i++)
			//{
			//	if ((protocol & B00000001) == B00000001) {
			//		controlByte = controlByte + DataBuffer[i];
			//	}

			//	wrapper.bytes[i] = DataBuffer[i];
			//}

			//if ((protocol & B00000001) == B00000001) {
			//	controlSentByte = DataBuffer[sizeof(TData)];

			//	if (controlByte == controlSentByte) {
			//		isOk = true;
			//	}
			//}
			//else {
			//	isOk = true;
			//}

			//if (isOk) {
			//	result |= B00000011;
			//}
			//else {
			//	result = B00000010;
			//}

			//if (!isOk) {

			//	// if its not ok, reads the second copy
			//	if ((protocol & B00000010) == B00000010) {

			//		controlByte = 0;
			//		unsigned int start = sizeof(TData) + 1;
			//		//unsigned int end = start + sizeof(TData); // sizeof(TData) + 1;

			//		for (size_t i = 0; i < sizeof(TData); i++)
			//		{
			//			byte b = DataBuffer[i + start];
			//			if ((protocol & B00000001) == B00000001) {
			//				controlByte = controlByte + b;
			//			}

			//			wrapper.bytes[i] = b;
			//		}

			//		controlSentByte = DataBuffer[start * 2];

			//		isOk = (controlByte == controlSentByte);

			//		if (isOk) {
			//			result = B00001111;
			//		}
			//		else {
			//			result = B00001010;
			//		}
			//	}

			//}

			//if (isOk) {
			//	result |= B11110000;
			//}


			////	readTimes--;
			////}


		}

		

		return result;
	}
	else {
		return B00000000;
	}
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::Receive(byte c)
{
	if (DataBufferIndex < sizeof(DataBuffer)) {
		DataBuffer[DataBufferIndex] = c;
		DataBufferIndex++;
		if (DataBufferIndex >= transactionSize) {
			process_it = true;
		}
	}
}
