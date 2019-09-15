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




	/// <summary>
	/// Makes Mode byte for Signal generator instruction.
	/// </summary>
	/// <param name="IsPWMCycle">if set to <c>true</c>, the PWM byte is  [is PWM cycle].</param>
	/// <param name="IsDoublePrescalar">if set to <c>true</c> [is double prescalar].</param>
	/// <param name="IsSignalON">if set to <c>true</c> [is signal on].</param>
	/// <param name="IsPitchSlave">if set to <c>true</c> [is pitch slave].</param>
	/// <param name="IsPositiveRelation">if set to <c>true</c> [is positive relation].</param>
	/// <param name="IsRelativeDistance">if set to <c>true</c> [is relative distance].</param>
	/// <param name="IsPitchMidiNote">if set to <c>true</c> [is pitch midi note].</param>
	/// <returns></returns>
	static byte MakeModeByte(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote);
};