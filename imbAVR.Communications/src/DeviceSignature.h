// DeviceSignature.h

#ifndef _DEVICESIGNATURE_h
#define _DEVICESIGNATURE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define DEVICESIGNATURE_UNKNOWN B00000000
#define DEVICESIGNATURE_SYNTHCONTROL B00000001
#define DEVICESIGNATURE_SIGNALGENERATOR B00000010
#define DEVICESIGNATURE_DIAGNOSTICDEVICE B00000100
#define DEVICESIGNATURE_PCVSTI B00001000
#define DEVICESIGNATURE_PCDEVTOOL B00010000

#define DEVICEMESSAGETYPE_HELLOPING B00000001
#define DEVICEMESSAGETYPE_PINBACK B00000010

struct DeviceSignature {
	// 0000 0000 - unknown
	// 0000 0001 - synth control
	// 0000 0010 - signal generator
	// 0000 0100 - diagnostic device
	// 0000 1000 - PC VSTi interface
	// 0001 0000 - PC development tool
	byte deviceType = DEVICESIGNATURE_UNKNOWN;

	//// 0000 0001 - the device is saying Hallo!
	//// 0000 0010 - the device is waving back
	//byte messageType;

	unsigned int maxBaudrate = 115200;
};

#endif

