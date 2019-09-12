// TransferLink.h

#ifndef _TRANSFERLINK_h
#define _TRANSFERLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#define TL_CONFIRMATIONTYPE_OFF 0x

#include "TransferClassHeader.h"

#include "SoftwareSerial.h"
#include "HardwareSerial.h"

#include "DevicePort.h"

#define RECEIVERESULTMASK_FAIL B00001100
#define RECEIVERESULTMASK_SUCCESS B00000011

#define IS_RECEIVE_RESULTSUCCESS(result) (result & B00000011) == B00000011


#define TRANSFER_LOADDATA(structToLoadInto, transferLink) \
memcpy(&structToLoadInto, &transferLink->buffer, sizeof(structToLoadInto)); \
transferLink->TrimBuffer(sizeof(structToLoadInto) + transferLink->NumberOfControlBytes); \

#define TRANSFER_SENDDATA(transferLink, port, structToSend) \
byte b[sizeof(structToSend)]; \
memcpy(b, (byte *)&structToSend, sizeof(structToSend)); \
transferLink->Send(port, b); \

#define TRANSFERLINK_MAXCLASSID 16


#define TRANSFERCLASSID_DEVICESIGNATURE 2
#define TRANSFERCLASSID_MONITORMESSAGE 3
#define TRANSFERCLASSID_SIGNALINSTRUCTION 4
#define TRANSFERCLASSID_MIDIMESSAGE 5


#define TRANSFERLINK_BUFFERSIZE 255


class TransferLink {

public:

	byte buffer[TRANSFERLINK_BUFFERSIZE];
	byte bufferIndex = 0;



	unsigned int BufferCheckTick = 5; // miliseconds
	long lastBufferChange = 0;
	bool BufferChecked = false;

	TransferClassHeader activeHeader;
	TransferClassHeader lastHeader;

	byte RetryIndex = 0;
	byte RetryLimit = 0;

	byte NumberOfControlBytes = 0;

	
	unsigned int ConfirmationTimeout = 50;

	unsigned int bufferFlushTimeout = 2500;
	

	

	static TransferClassHeader MakeHeader(byte class_id, byte size, bool twoBytePackages=false, byte confirmationType= 0b11, byte retries= 0b10, byte timeout= 0b10, bool permanent=true);

	static byte ComputeSignatureByte(TransferClassHeader header);

	static byte ComputeControlByte(byte * data, boolean isHeader=false);

	/// <summary>
	/// Removes specified number of bytes from the bugger
	/// </summary>
	/// <param name="leftTrim">The left trim.</param>
	void TrimBuffer(byte leftTrim);

	void SetHeader(TransferClassHeader header);
	
	/// <summary>
	/// Reads available bytes from the port, returns: 
	/// xxxx 0000 -- class_id (0-16, where 0 and 1 are reserved)
	/// 0000 xxxx -- status message
	/// ---- 0000 : no bytes received
	/// ---- 0001 : transfer not complete
	/// ---- 0010 : buffer index overflow
	/// ---- 0011 : data received successfully
	/// ---- 0100 : control bytes missmatched
	/// ---- 1100 : buffer flushed for time out, no data received
	 
	void ReceiveStart();

	/// </summary>
	/// <param name="port">The port.</param>
	/// <returns></returns>
	byte Receive(HardwareSerial * port);

	byte Receive(SoftwareSerial * port);

	byte Receive(DevicePort * port);
	
	/// <summary>
	/// fills the buffer with specified byte package
	/// </summary>
	/// <param name="bytePackage">The byte package.</param>
	/// <param name="port">The port - to send confirmation onto.</param>
	/// <returns></returns>
	byte Receive(byte * bytePackage, DevicePort * port);

	/// <summary>
/// Loads data from buffer to struct and trims the buffer. To be called after Receive result confirmed that buffer contains properly loaded data
/// </summary>
/// <param name="structToLoadInto">The structure to load into.</param>
	//void LoadDataToStruct(byte * structToLoadInto);

	//byte BufferCheck(DevicePort * port);

	


	//void LoadDataToStruct(byte * structToLoadInto);
	
	/// <summary>
	/// Sends given structure via specified port, returns result: on last four tries (2 bits per try): 
	/// 0x00 time out
	/// 0x01 control byte mistmatch
	/// 0x11 success
	/// 0x10 failed, retry limit reached
	/// </summary>
	/// <param name="port">The port.</param>
	/// <param name="structToSend">The structure to send.</param>
	/// <returns></returns>
	byte Send(HardwareSerial * port, byte * b);


	byte Send(SoftwareSerial * port, byte * b);


	byte Send(DevicePort * port, byte * b);

	
	
};

#endif

