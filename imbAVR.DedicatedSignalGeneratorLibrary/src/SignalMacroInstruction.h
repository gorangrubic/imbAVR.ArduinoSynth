#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

/// <summary>
/// Instruction for SignalGenerator
/// </summary>
struct SignalMacroInstruction
{
	long data;

};

