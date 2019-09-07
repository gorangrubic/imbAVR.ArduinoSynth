// TransferClassHeader.h

#ifndef _TRANSFERCLASSHEADER_h
#define _TRANSFERCLASSHEADER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



struct TransferClassHeader {
	
	/// <summary>
	/// Application specific class ID
	/// </summary>
	// 0 - is reserved for uncomplete transfer ID
	// 1 - is reserved for header it self -- 
	byte class_id;
	
	/// <summary>
	/// Number of bytes that structure has
	/// </summary>
	byte size;
	
	/// <summary>
	/// Protocol: 
	/// </summary>
	
	// xxxx xxx0 simple stream of bytes
	// xxxx xxx1 two-byte packages, first byte: byte index, second byte: value
	
	// xxxx x00x no confirmation
	// xxxx x01x append control byte at the end of message
	// xxxx x10x confirm with control byte and append it at the end of message
	// xxxx x11x ----- confirm with control byte, compute and include two (same) nested control bytes at end the message

	// xxx0 0xxx retry is disabled
	// xxx0 1xxx retries: 2

	// xxx1 0xxx retries: 5
	// xxx1 1xxx retries: 10

	// x00x xxxx virtually infinite confirmation time out (60s)
	// x01x xxxx confirmation time out: 10 ms
	// x10x xxxx confirmation time out: 25 ms
	// x11x xxxx confirmation time out: 100 ms


	// 0xxx xxxx this header is valid for single-transfer, after it previous header is used again
	// 1xxx xxxx this header is permanent, all transfers that follow will use this protocol
	byte protocol;

		
	/// <summary>
	/// Special control byte -- computed from other values in this struct, in order to confirm that received buffer is actually new class header
	/// </summary>
	byte headerSignature;


};

#endif

