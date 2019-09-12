#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
class ControlFunctionADSR
{

	unsigned int AttackTime = 0;

	unsigned int DecayTime = 0;

	unsigned int ReleaseTime = 0;


	byte InitLevel;
	byte PeakLevel;
	byte SustainLevel;

public:



	byte ComputeADS(unsigned int cT);
	byte ComputeR(unsigned int cT);

	void Update(MonitoredArray<16> * CCValues);
};

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
inline void ControlFunctionADSR<ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel>::Update(MonitoredArray<16>* CCValues)
{
	if (CCValues->IsChanged(ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel)) {

		AttackTime = CCValues[ccAttack] + 1;
		DecayTime = CCValues[ccDecay] + 1;

		ReleaseTime = CCValues[ccRelease] + 1;

		InitLevel = CCValues[ccInitLevel];
		PeakLevel = 127;
		SustainLevel = CCValues[ccSustainLevel];
	}
}

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
byte ControlFunctionADSR<ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel>::ComputeADS(unsigned int cT)
{
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

template<byte ccAttack, byte ccDecay, byte ccRelease, byte ccInitLevel, byte ccSustainLevel>
byte ControlFunctionADSR<ccAttack, ccDecay, ccRelease, ccInitLevel, ccSustainLevel>::ComputeR(unsigned int cT)
{
	if (cT > ReleaseTime) return 0;
	return MathTool::Interpolation(SustainLevel, 0, cT, ReleaseTime);
}
