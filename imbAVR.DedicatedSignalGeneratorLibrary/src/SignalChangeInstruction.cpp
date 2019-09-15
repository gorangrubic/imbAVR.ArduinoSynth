#include "SignalChangeInstruction.h"

void SignalChangeInstruction::SetBytes(byte b2, byte b3, byte options)
{

	Change = b2;
	Rate = b3;
	SetOptions(options);
}

void SignalChangeInstruction::SetOptions(byte options)
{
	mode = options >> 6;
	period = options & B00111111;

}

byte SignalChangeInstruction::GetOptions()
{
	byte options = mode << 6;
	options |= period;

	return options;
}

void SignalChangeInstruction::PerformPeriod()
{

	PeriodIndex++;

	if (PeriodIndex > period) {
		if (mode == 1) Change = 0;
		else if (mode == 2) PeriodIndex = 0;
		else if (mode == 3) {
			Change -= Change;
			PeriodIndex = 0;
		}
	}
}
