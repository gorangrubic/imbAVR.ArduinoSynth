// 
// 
// 

#include "TwoPointENV.h"
#include "MathTool.h"

byte TwoPointENV::Compute(unsigned int cT)
{
	if (cT > ATime) {
		// decay phase
		return MathTool::Interpolation(ALevel, BLevel, cT - ATime, BTime);
	}
	else {
		// attack phase
		return MathTool::Interpolation(BLevel, ALevel, cT, ATime);
	}
}

void TwoPointENV::SetTimes(unsigned int At, unsigned int Bt)
{
	ATime = At * ATimeFactor;
	BTime = Bt * BTimeFactor;

}

void TwoPointENV::SetLevels(byte aLevel, byte bLevel)
{
	ALevel = aLevel;
	BLevel = bLevel;
}
