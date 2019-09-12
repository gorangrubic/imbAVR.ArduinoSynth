#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SignalMacroInstruction.h"
#include "SignalControlManager.h"

class SignalMacroControl
{
public:
	
	unsigned int master_pitch; 


	byte master_modulation;

	void Run(SignalMacroInstruction instruction, SignalControlManagerClass * manager);
	
	void Run(byte s_id, byte cc_id, byte b2, byte b3, byte b4, SignalControlManagerClass * manager);


};