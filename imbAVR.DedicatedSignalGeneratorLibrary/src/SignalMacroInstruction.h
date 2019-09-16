#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// #define SMI_UNPACKED_FORM

/// <summary>
/// Instruction for SignalGenerator
/// </summary>
struct SignalMacroInstruction
{
#ifdef SMI_UNPACKED_FORM
	byte sid;
	byte cid;
	byte b2;
	byte b3;
	byte b4;
#else
	long data;
#endif //  UNPACKED_FORM

	

};

