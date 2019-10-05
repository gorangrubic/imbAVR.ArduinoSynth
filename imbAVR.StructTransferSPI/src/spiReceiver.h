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

	byte readTimes = 1;

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

	unsigned int DataBufferIndex = 0;
	char DataBuffer[(sizeof(TData) + 2 ) * ISize];

	unsigned int DataBufferIndexLimit = 0;

	boolean DataBufferIndexClipDetected = false;


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
		readTimes = 1;
		transactionSize++;


		if ((protocol & B00000010) == B00000010) {
			readTimes++;
		}

		if ((protocol & B00001000) == B00001000) {
			readTimes++;
			//transactionSize += transactionSize;
		}

		if ((protocol & B00010000) == B00010000) {
			readTimes++;
		}
	}
	else {
		readTimes = 1;
	}
	transactionSize = transactionSize * readTimes;

	DataBufferIndexLimit = transactionSize * ISize;
}

template<typename TData, byte ISize>
void spiReceiver<TData, ISize>::ClearInstanceBuffer()
{
	InstanceBufferIndex = 0;
}

#define SPIRECEIVER_LOOP_RESULT_SUCCESS_MASK B10000000

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
			process_it = false;
			return B00000001 | SPIRECEIVER_LOOP_RESULT_SUCCESS_MASK;
		}



		byte result = B00000000;

		if (DataBufferIndexClipDetected) {
			result |= B01000000;
			DataBufferIndexClipDetected = false;
		}
		

		boolean isOk = false;

		//if ((protocol & B00000010) == B000000010) readTimes++;

		spiLinkDataInstance<TData> wrapper;

		unsigned int readIteration = 0;

		
		if (DataBufferIndex >= transactionSize) {

			

			unsigned int readIndex = 0;
			

			//if ((protocol & B00000010) == B00000010) readTimes++;

			//if ((protocol & B00001000) == B00001000) readTimes++;
			//if ((protocol & B00010000) == B00010000) readTimes++;

			while (readIteration < readTimes) {

				isOk = false;

				unsigned int controlByte = 0;
				unsigned int controlSentByte = 0;

				for (size_t i = 0; i < sizeof(TData); i++)
				{
					byte b = DataBuffer[readIndex];
					if ((protocol & B00000001) == B00000001) {
						controlByte = controlByte + b;
						controlByte = controlByte % 256;
					}
					wrapper.bytes[i] = b;
					readIndex++;
				}

				if ((protocol & B00000001) == B00000001) {
					
					controlSentByte = DataBuffer[readIndex];



					//if (readIteration > 0) result = result << 1;

					if (controlByte == controlSentByte) {

					//	bitWrite(result, 0, 1);
						//result |= B00000001;
						isOk = true;
					}
					else {
					//	bitWrite(result, 0, 0);
						//result |= B00000010;
					}

					

					readIndex++;
				}
				else {
					//bitWrite(result, 0, 1);
					//result |= B00000011;
					isOk = true;
				}

				result = (result >> 4) << 4;
				result |= readIteration;

				if (isOk) {

					result |= SPIRECEIVER_LOOP_RESULT_SUCCESS_MASK;

					AddInstanceBuffer(wrapper.instance);

					if (bitRead(protocol, 2) == 0) {
						TrimBuffer(transactionSize * readTimes);
					}
					else {
						DataBufferIndex = 0;
					}
					process_it = false;

					return result;
				}
				

				readIteration++;

			}

			if (bitRead(protocol, 2) == 0) {
				TrimBuffer(transactionSize * readTimes);
			}
			else {
				DataBufferIndex = 0;
			}

			

		}

		result = (result >> 4) << 4;
		result |= readIteration;
		
		process_it = false;
		return result;
	}
	else {
		return B00000000;
	}
}

template<typename TData, byte ISize>
inline void spiReceiver<TData, ISize>::Receive(byte c)
{
	if (DataBufferIndex < DataBufferIndexLimit) {
		DataBuffer[DataBufferIndex] = c;
		DataBufferIndex++;
		if (DataBufferIndex >= transactionSize) {
			process_it = true;
		}
	}
	else {
		DataBufferIndexClipDetected = true;
	}
}
