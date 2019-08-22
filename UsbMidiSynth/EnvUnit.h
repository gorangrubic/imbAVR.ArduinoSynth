// EnvUnit.h

#ifndef _ENVUNIT_h
#define _ENVUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EnvUnitClass
{
 protected:


 public:
	void init();
};

extern EnvUnitClass EnvUnit;

#endif

