#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MonitoredArray.h"
#include "SynthState.h"

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
class ControlFunctionADSR
{

public:

	byte TimeFactor = 2;

	unsigned int AttackTime = 0;

	unsigned int DecayTime = 0;

	unsigned int ReleaseTime = 0;


	byte InitLevel;
	byte PeakLevel;
	byte SustainLevel;


	
	void Update(CCValuesType * CCValues);
	byte Compute(unsigned int cT, bool IsReleaseStage);
};

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
inline void ControlFunctionADSR<ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel>::Update(CCValuesType* CCValues)
{
	if (CCValues->IsChanged(ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel)) {

		AttackTime = CCValues[ccAttack] * TimeFactor + 1;
		DecayTime = CCValues[ccDecay]*TimeFactor + 1;

		ReleaseTime = CCValues[ccRelease]*TimeFactor + 1;

		InitLevel = CCValues[ccInitLevel];
		PeakLevel = 127;
		SustainLevel = CCValues[ccSustainLevel];
	}
}

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
byte ControlFunctionADSR<ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel>::Compute(unsigned int cT, bool IsReleaseStage)
{
	if (IsReleaseStage) {
		if (cT > ReleaseTime) return 0;
		return MathTool::Interpolation(SustainLevel, 0, cT, ReleaseTime);
	}
	else {
		if (cT >= (AttackTime + DecayTime)) {
			// sustain phase
			return SustainLevel;
		}
		else if (cT > AttackTime) {
			// decay phase
			return MathTool::Interpolation(PeakLevel, SustainLevel, cT - AttackTime, DecayTime);
		}
		else {
			// attack phase
			return  MathTool::Interpolation(InitLevel, PeakLevel, cT, AttackTime);
		}
	}
}
