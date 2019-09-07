// 
// 
// 

#include "TransferLink.h"

#define TRANSFER_SUCCESS (result & B00000011) == B00000011


#define TRANSFER_SENDPROCEDURE	\
RetryIndex = 0;	\
byte result = B00000000; \
byte b[sizeof(structToSend)]; \
memcpy(b, &structToSend, sizeof(structToSend)); \
byte controlByte = 0; \
for (size_t i = 0; i < sizeof(b); i++) \
{ \
	port->write(b[i]); \
	controlByte += b[i]; \
} \
if ((activeHeader.protocol & B00000110) == B00000010) { port->write(controlByte); } \
else if ((activeHeader.protocol & B00000110) == B00000100) { port->write(controlByte); } \
else if ((activeHeader.protocol & B00000110) == B00000110) { \
	port->write(controlByte); \
	port->write(controlByte); \
} \
if ((activeHeader.protocol & B00000100) == B00000100) { \
	while (!TRANSFER_SUCCESS && (RetryIndex < RetryLimit)) { \
		long sentTime = millis(); \
		bool timeOut = false; \
		while (!timeOut) { \
			timeOut = millis() - sentTime < ConfirmationTimeout; \
 			if (port->available()) { \
				byte returnedByte = port->read(); \
				if (returnedByte == controlByte) { \
					result |= B00000011; \
				} \
				else { \
					result |= B00000001; \
				} \
				break; \
			} \
		} \
		if (!TRANSFER_SUCCESS) { \
			RetryIndex++; \
			result = result << 2; \
		} \
	} \
} else { result = B00000011; } return result; \



byte TransferLink::Send(HardwareSerial * port, byte * structToSend) {
	TRANSFER_SENDPROCEDURE	
}

byte TransferLink::Send(SoftwareSerial * port, byte * structToSend) {
	TRANSFER_SENDPROCEDURE
}

TransferClassHeader TransferLink::MakeHeader(byte class_id, byte size, bool twoBytePackages, byte confirmationType, byte retries, byte timeout, bool permanent = true)
{
	TransferClassHeader output;

	output.class_id = class_id;
	output.size = size;
	output.protocol = B00000000;

	if (twoBytePackages) {
		output.protocol |= B00000001;
	}

	switch (confirmationType) {
	case 0b00:
		
		break;
	case 0b01:
		output.protocol |= B00000010;
		break;
	case 0b10:
		output.protocol |= B00000100;
		break;
	default:
	case 0b11:
		output.protocol |= B00000110;
		break;
	
	}

	switch (retries) {
	case 0b00:
		output.protocol |= B00000000;
		break;
	case 0b01:
		output.protocol |= B00001000;
		break;
	case 0b10:
		output.protocol |= B00010000;
		break;
	default:
	case 0b11:
		output.protocol |= B00011000;
		break;

	}

	switch (timeout) {
	case 0b00:
		//output.protocol |= B00000000;
		break;
	case 0b01:
		output.protocol |= B00100000;
		break;
	case 0b10:
		output.protocol |= B01000000;
		break;
	default:
	case 0b11:
		output.protocol |= B01100000;
		break;

	}

	if (permanent) {
		output.protocol |= B10000000;
	}

	output.headerSignature = 0;

	byte b[sizeof(output)];
	memcpy(b, &output, sizeof(output));
	
	output.headerSignature = ComputeControlByte(b, true);

	return output;
}

byte TransferLink::ComputeSignatureByte(TransferClassHeader header) {

	byte b[sizeof(header)];
	memcpy(b, &header, sizeof(header));

	byte headerSignature = ComputeControlByte(b, true);

	/* 0;
	headerSignature += header.class_id;
	headerSignature += header.protocol;
	headerSignature += header.size;*/
	return headerSignature;
}

byte TransferLink::ComputeControlByte(byte * data, boolean isHeader)
{
	byte output = 0;
	byte size = sizeof(data);
	for (size_t i = 0; i < size; i++)
	{
		output += data[i];
	}

	if (isHeader) {
		output = output << 4;
	}

	return output;
}


void TransferLink::TrimBuffer(byte leftTrim) {

	if (bufferIndex == 0) return;
	if (leftTrim >= bufferIndex) {
		bufferIndex = 0;
		return;
	}
	for (size_t i = 0; i < leftTrim; i++)
	{
		buffer[i] = buffer[leftTrim + i];
	}
	bufferIndex = bufferIndex - leftTrim;

	lastBufferChange = millis();

	return;
}

/// <summary>
/// Sets the header.
/// </summary>
/// <param name="header">The header.</param>
void TransferLink::SetHeader(TransferClassHeader header)
{

	lastHeader = activeHeader;
	activeHeader = header;

	byte time_out_bits = (activeHeader.protocol & B01100000) >> 5;

	switch (time_out_bits) {
		case B00:
			ConfirmationTimeout = 60000;
			break;
		case B01:
			ConfirmationTimeout = 10;
			break;
		case B10:
			ConfirmationTimeout = 25;
			break;
		case B11:
			ConfirmationTimeout = 100;
			break;
	}

	byte retry_bits = (activeHeader.protocol & B00011000) >> 3;
	switch (retry_bits) {
	case B00:
		RetryLimit = 1;
		break;
	case B01:
		RetryLimit = 2;
		break;
	case B10:
		RetryLimit = 5;
		break;
	case B11:
		RetryLimit = 10;
		break;
	}


	if ((activeHeader.protocol & B00000110) == B00000000) { NumberOfControlBytes = 0; } 
	else if ((activeHeader.protocol & B00000110) == B00000010) { NumberOfControlBytes = 1; }
	else if ((activeHeader.protocol & B00000110) == B00000100) { NumberOfControlBytes = 1; } 
	else if ((activeHeader.protocol & B00000110) == B00000110) { NumberOfControlBytes = 2; }



}



#define TRANSFER_RECEIVE																										\
																							\
																										\
	byte result = B00000000;																										\
	if (port->available()) {																										\
																										\
		if (bufferIndex < sizeof(buffer)) {																										\
																										\
			bufferIndex++;																										\
			buffer[bufferIndex] = port->read();																										\
			lastBufferChange = millis();																										\
		}																										\
	}																										\
																											\
	long sinceLastBufferChange = millis() - lastBufferChange;																										\
																										\
																											\
	if (sinceLastBufferChange > bufferFlushTimeout) {																										\
																																				\
		result |= B00001100;																										\
		TrimBuffer(bufferIndex);																										\
		return result;																										\
	} else if (!BufferChecked && (sinceLastBufferChange > BufferCheckTick)) {																										\
																										\
		BufferChecked = true;														\
														\
		byte controlByte = 0;														\
																	\
														\
		if (bufferIndex >= (activeHeader.size + NumberOfControlBytes)) {														\
			for (size_t i = 0; i < activeHeader.size; i++) 														\
			{														\
				controlByte += buffer[i];														\
			}														\
														\
			boolean controlBytesConfirmed = true;														\
														\
			for (size_t i = activeHeader.size; i < (activeHeader.size + NumberOfControlBytes); i++)														\
			{														\
				if (controlByte != buffer[i]) {														\
														\
					controlBytesConfirmed = false;														\
					break;														\
				}														\
			}														\
														\
			if (controlBytesConfirmed) {														\
				result |= activeHeader.class_id << 4;														\
				result |= B00000011;														\
			}														\
			else {														\
				result |= B00000100;														\
				TrimBuffer((activeHeader.size + NumberOfControlBytes));														\
			}														\
														\
														\
			if ((activeHeader.protocol & B00000100) == B00000100) {														\
														\
				port->write(controlByte);														\
				port->flush();														\
			}														\
														\
		} 														\
														\
														\
															\
		if ((result & B00000011) != B00000011) {\
																	\
																		\
																									\
																									\
			if (bufferIndex >= (sizeof(TransferClassHeader) + NumberOfControlBytes)) {																									\
																									\
				boolean isHeader = true;																									\
																													\
																									\
				for (size_t i = 0; i < sizeof(TransferClassHeader); i++)																									\
				{																									\
					controlByte += buffer[i];																									\
				}																									\
																									\
				boolean controlBytesConfirmed = true;																									\
																									\
				for (size_t i = sizeof(TransferClassHeader); i < (sizeof(TransferClassHeader) + NumberOfControlBytes); i++)																									\
				{																									\
					if (controlByte != buffer[i]) {																									\
																									\
						controlBytesConfirmed = false;																									\
						break;																									\
					}																									\
				}																									\
																									\
				isHeader = !controlBytesConfirmed;																									\
																									\
				if (controlBytesConfirmed) {																									\
																									\
																														\
					TransferClassHeader newHeader;																									\
																									\
					memcpy(&newHeader, &buffer, sizeof(TransferClassHeader));						\
																									\
					if (newHeader.class_id > TRANSFERLINK_MAXCLASSID) {																									\
						isHeader = false;																									\
					}																									\
																									\
					byte signature = newHeader.headerSignature;																									\
																									\
					newHeader.headerSignature = 0;																									\
																									\
					byte controlSignature = TransferLink::ComputeSignatureByte(newHeader);																									\
																									\
					if (signature != controlSignature) {																									\
						isHeader = false;																									\
					}																									\
																									\
					if (isHeader) {																									\
																									\
						SetHeader(newHeader);																									\
																									\
						result |= 1 << 4;																									\
						result |= B00000011;																									\
																									\
						TrimBuffer(sizeof(TransferClassHeader));																									\
					}																									\
					else {																									\
																									\
					}																									\
																										\
				}																									\
																													\
				if ((activeHeader.protocol & B00000100) == B00000100) {																									\
																									\
					port->write(controlByte);																									\
					port->flush();																									\
				}																									\
																									\
			}																									\
		}																									\
																									\
	}																									\
	else {																									\
		BufferChecked = false;																									\
	}																									\
																										\

byte TransferLink::Receive(HardwareSerial * port)
{
	TRANSFER_RECEIVE
		return result;
}

byte TransferLink::Receive(SoftwareSerial * port)
{
	TRANSFER_RECEIVE
		return result;
}

void TransferLink::LoadDataToStruct(byte * structToLoadInto)
{

	memcpy(&structToLoadInto, &buffer, sizeof(structToLoadInto));
	TrimBuffer(sizeof(structToLoadInto) + NumberOfControlBytes);

}
