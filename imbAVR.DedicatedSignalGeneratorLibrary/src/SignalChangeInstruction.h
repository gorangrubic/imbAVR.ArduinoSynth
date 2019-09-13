#pragma once

#include "SignalMacroInstruction.h"

class SignalChangeInstruction
{
	public:
		byte RateIndex = 0;
		byte PeriodIndex = 0;
	
		byte Rate = 256;
		
		// change = 1 => -126, change = 255 = +126
		byte Change = 0;
	
	
	
		/*
		* 0 - continual / unlimited
		* 1 - one-shot / limited
		* 2 -  loop
		* 3 - mirror / bounce
		*/
		byte mode;
	
		/*
		* 0 - 64 x rate
		*/
		byte period = 64;
	
		void SetBytes(byte b2, byte b3, byte options);
	
		void SetOptions(byte options);


	
		byte GetOptions();
	
		void PerformPeriod();
	
};

