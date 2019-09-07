// DeviceRegistration.h

#ifndef _DEVICEREGISTRATION_h
#define _DEVICEREGISTRATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define REGISTRATION_TIMEOUT 10000





//
//#include "TransferClassHeader.h"
#include "TransferLink.h"
//#include "DeviceSignature.h"
//


class DeviceRegistration {


public:

	
	//long startTime = 0;

	bool bootStart(DevicePort * port, TransferLink * transferLink);

	/// <summary>
	/// Call this at beginning of setup() and wait get return: true with while() { }
	/// </summary>
	/// <returns></returns>
	bool bootLoop(DevicePort * port, TransferLink * transferLink);

	void bootComplete(DevicePort * port);


	byte deviceType = DEVICESIGNATURE_UNKNOWN;

	// bitwise | of all received signatures
	byte devices;


	DeviceRegistration(byte _deviceType);

};


#endif

