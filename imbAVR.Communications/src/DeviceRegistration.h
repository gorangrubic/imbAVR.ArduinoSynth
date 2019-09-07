// DeviceRegistration.h

#ifndef _DEVICEREGISTRATION_h
#define _DEVICEREGISTRATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define REGISTRATION_TIMEOUT 5000

#define DEVICESIGNATURE_UNKNOWN B00000000
#define DEVICESIGNATURE_SYNTHCONTROL B00000001
#define DEVICESIGNATURE_SIGNALGENERATOR B00000010
#define DEVICESIGNATURE_DIAGNOSTICDEVICE B00000100
#define DEVICESIGNATURE_PCVSTI B00001000
#define DEVICESIGNATURE_PCDEVTOOL B00010000


#define TRANSFERCLASSID_DEVICESIGNATURE 2
#define TRANSFERCLASSID_MONITORMESSAGE 3
#define TRANSFERCLASSID_SIGNALINSTRUCTION 4
#define TRANSFERCLASSID_MIDIMESSAGE 5

#include "TransferLink.h"
#include "TransferClassHeader.h"

struct DeviceSignature {
	// 0000 0000 - unknown
	// 0000 0001 - synth control
	// 0000 0010 - signal generator
	// 0000 0100 - diagnostic device
	// 0000 1000 - PC VSTi interface
	// 0001 0000 - PC development tool
	byte deviceType = DEVICESIGNATURE_UNKNOWN;

	// 0000 0001 - the device is saying Hallo!
	// 0000 0010 - the device is waving back
	byte messageType;

	unsigned int maxBaudrate;
};


class DevicePort {

public:
	DeviceSignature Signature;
	
	SoftwareSerial * softwarePort;
	HardwareSerial * hardwarePort;

	// 0 - hardware
	// 1 - software
	byte portType = 0;

	DevicePort(SoftwareSerial * softSerial);
	DevicePort(SoftwareSerial * hardSerial);
	
	TransferLink transferLink;

};


class DeviceRegistration {


public:

	
	long startTime = 0;

	bool bootStart(DevicePort * port);

	/// <summary>
	/// Call this at beginning of setup() and wait get return: true with while() { }
	/// </summary>
	/// <returns></returns>
	bool bootLoop(DevicePort * port);

	void bootComplete(DevicePort * port);


	DeviceSignature signature;

	// bitwise | of all received signatures
	byte devices;

	void ReadSignature(DeviceSignature received);

	DeviceRegistration(byte deviceType, unsigned int maxBaudrate);

};


#endif

