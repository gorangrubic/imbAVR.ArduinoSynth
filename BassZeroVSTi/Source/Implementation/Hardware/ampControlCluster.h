// ampControlCluster.h

#ifndef _AMPCONTROLCLUSTER_h
#define _AMPCONTROLCLUSTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class ampControlCluster {


	byte pin_clock;

	byte pin_vol1;
	byte pin_vol2;
	byte pin_vol3;

	byte checkVolume(byte volume);
	uint16_t packData(byte volume, byte channel);
	void setVolume(byte vol1, byte vol2, byte vol3, byte channel);

public:
	void init(byte pinClock, byte pinVol1, byte pinVol2, byte pinVol3);

	
	void setVolume(byte vol1A, byte vol1B, byte vol2A, byte vol2B, byte vol3A, byte vol3B);
	
};