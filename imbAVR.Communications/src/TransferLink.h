// TransferLink.h

#ifndef _TRANSFERLINK_h
#define _TRANSFERLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#define TL_CONFIRMATIONTYPE_OFF 0x

#include "TransferClassHeader.h";
#include "DeviceRegistration.h";

#define TRANSFERLINK_MAXCLASSID 16

class TransferLink {

public:

	byte buffer[256];
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

	unsigned int bufferFlushTimeout = 1000;
	

	

	static TransferClassHeader MakeHeader(byte class_id, byte size, bool twoBytePackages, byte confirmationType, byte retries, byte timeout, bool permanent);

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
	 
	/// </summary>
	/// <param name="port">The port.</param>
	/// <returns></returns>
	byte Receive(HardwareSerial * port);

	byte Receive(SoftwareSerial * port);

	byte Receive(DevicePort * port);

	/// <summary>
	/// Loads data from buffer to struct and trims the buffer. To be called after Receive result confirmed that buffer contains properly loaded data
	/// </summary>
	/// <param name="structToLoadInto">The structure to load into.</param>
	void LoadDataToStruct(byte * structToLoadInto);
	
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
	byte Send(HardwareSerial * port, byte * structToSend);


	byte Send(SoftwareSerial * port, byte * structToSend);


	byte Send(DevicePort * port, byte * structToSend);
	
};

#endif

