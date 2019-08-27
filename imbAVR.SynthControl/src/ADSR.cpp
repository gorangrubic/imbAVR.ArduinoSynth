#include "ADSR.h"
#include "MathTool.h"


byte ADSRFunction::ComputeADS(unsigned int cT)
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

byte ADSRFunction::ComputeR(unsigned int cT)
{
	if (cT > ReleaseTime) return 0;
	return MathTool::Interpolation(SustainLevel, 0, cT, ReleaseTime);
}

/// <summary>
/// Sets the times.
/// </summary>
/// <param name="At">At - Attack Time, in engine cycle ticks.</param>
/// <param name="Dt">The dt - Decaly Time.</param>
/// <param name="Rt">The rt - Release time</param>
/// <param name="iL">Init Level</param>
/// <param name="pL">Peak Level</param>
/// <param name="sL">Sustain Level</param>
void ADSRFunction::SetTimes(unsigned int At, unsigned int  Dt, unsigned int Rt) {


	AttackTime = At + 1;
	DecayTime = Dt + 1;

	ReleaseTime = Rt + 1;



}

void ADSRFunction::SetLevels(byte iL, byte pL, byte sL) {

	InitLevel = iL;
	PeakLevel = pL;
	SustainLevel = sL;

}

ADSRFunction::ADSRFunction()
{
}


ADSRFunction::~ADSRFunction()
{
}
