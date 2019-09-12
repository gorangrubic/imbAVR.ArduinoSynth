// DevicePort.h

#ifndef _DEVICEPORT_h
#define _DEVICEPORT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "DeviceSignature.h"

#include "SoftwareSerial.h"
#include "HardwareSerial.h"



class DevicePort {

public:
	DeviceSignature Signature;

	SoftwareSerial * softwarePort;
	HardwareSerial * hardwarePort;

	// 0 - hardware
	// 1 - software
	byte portType = 0;

	DevicePort(SoftwareSerial * softSerial);
	DevicePort(HardwareSerial * hardSerial);


	// initially max baudrate, after boot procedure: baudrate negotiated between two devices
	// specified in 100s, i.e. 1152 is 115200
	unsigned int baudrate = 1152;

	byte read();
	void write(byte data);
	int available();
	void flush();
	void begin(unsigned int rate);
	void end();

};

#endif

