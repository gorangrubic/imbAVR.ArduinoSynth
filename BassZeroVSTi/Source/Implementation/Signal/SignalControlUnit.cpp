#include "SignalControlUnit.h"

void SignalControlUnitClass::ResetClocks(bool reset_pwmIndex, bool reset_sClock, bool reset_changes)
{
	pwmContinualSClockIndexChange = 0;

	if (reset_pwmIndex) {
		pwmStepIndex = 0;
	}

	if (reset_sClock) {
		sClockIndex = 0;
	}

	if (reset_changes) {
		PhaseChange.RateIndex = 0;
		PhaseChange.PeriodIndex = 0;
		PWMChange.RateIndex = 0;
		PWMChange.PeriodIndex = 0;
		PitchChange.RateIndex = 0;
		PitchChange.PeriodIndex = 0;
	}
}

