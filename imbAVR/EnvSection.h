// EnvSection.h

#ifndef _ENVSECTION_h
#define _ENVSECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EnvSectionClass
{
 protected:


 public:
	void init();
};

extern EnvSectionClass EnvSection;

#endif

