// 
// 
// 

#include "ADSRUnit.h"



/// <summary>
/// Sets the times.
/// </summary>
/// <param name="At">At - Attack Time, in engine cycle ticks.</param>
/// <param name="Dt">The dt - Decaly Time.</param>
/// <param name="Rt">The rt - Release time</param>
/// <param name="iL">Init Level</param>
/// <param name="pL">Peak Level</param>
/// <param name="sL">Sustain Level</param>
void ADSRUnitClass::SetTimes(unsigned int At, unsigned int  Dt, unsigned int Rt) {

	
	AttackTime = At+1;
	DecayTime = Dt+1;
	
	ReleaseTime = Rt+1;

	
	TotalTime = AttackTime + DecayTime + ReleaseTime;
	
	
}

void ADSRUnitClass::SetLevels(byte iL, byte pL, byte sL) {
	
	InitLevel = iL;
	PeakLevel = pL;
	SustainLevel = sL;

}



/// <summary>
/// Sets IsActive to true and CurrentPosition to 0
/// </summary>
void ADSRUnitClass::Restart() {

	CurrentState = ADSRUnitState::Attack;
	CurrentPosition = 1;
	
}

float ADSRUnitClass::GetRatio(unsigned int part, unsigned int total, float whenPartIsZero=0.0, float whenTotalIsZero=1.0) {

	if (part == 0) return whenPartIsZero;
	if (total == 0) return whenTotalIsZero;

	float result = (float)part / (float)total;

	if (result > 1.0) result = 1.0;
	if (result < 0.0) result = 0.0;

	return result;

}


byte ADSRUnitClass::Interpolation(byte from, byte to, unsigned int index, unsigned int length) {

	bool isPositiveDirection = true;
	byte step = 0;

	if (from > to) {
		isPositiveDirection = false;
		step = from - to;
	}
	else {
		step = to-from;
	}

	step = GetRatio(index, length) * step;

	if (isPositiveDirection) {
		return from + step;
	}
	else {
		return from - step;
	}
}


void ADSRUnitClass::NoteOff() {
	CurrentPosition = AttackTime + DecayTime;
}

/// <summary>
/// Moves <c>CurrentPosition</c> for one tick, and returns value at that position
/// </summary>
/// <returns></returns>
byte ADSRUnitClass::DoTick(bool noteOn) {

	byte output = 0;
	unsigned int Offset = 0;

	bool isChanged = false;

	if (CurrentPosition > TotalTime) {
		CurrentState = ADSRUnitState::off;
		CurrentPosition = 0;
		if (IsDebugOn) {
			// portTwo.print("--");
		}
	}
	else if (CurrentPosition >= (AttackTime + DecayTime)) {
		
		
		
		if (!noteOn) {
			
			CurrentState = ADSRUnitState::Release;


			CurrentPosition++;

			Offset = CurrentPosition - (AttackTime + DecayTime);

			output = Interpolation(SustainLevel, 0, Offset, ReleaseTime);

			if (LastOutput != output) isChanged = true;

			if (IsDebugOn && isChanged) {
				// portTwo.print("R");
				// portTwo.print(Offset);
				// portTwo.print("/");
				// portTwo.print(ReleaseTime);
				// portTwo.print("=");
				// portTwo.print(output);
			}
		}
		else {
			CurrentState = ADSRUnitState::Sustain;
			output = SustainLevel;
			if (LastOutput != output) isChanged = true;
			if (IsDebugOn && isChanged) {
				// portTwo.print("S=");
				// portTwo.print(output);
			}
		}
	}
	else if (CurrentPosition > AttackTime) {
		CurrentState = ADSRUnitState::Decay;
		CurrentPosition++;

		Offset = CurrentPosition - AttackTime;

		output = Interpolation(PeakLevel, SustainLevel, Offset, DecayTime);
		if (LastOutput != output) isChanged = true;
		if (IsDebugOn && isChanged) {
			// portTwo.print("D");
			// portTwo.print(Offset);
			// portTwo.print("/");
			// portTwo.print(DecayTime);
			// portTwo.print("=");
			// portTwo.print(output);
		}
	}
	else if (CurrentPosition > 0) {
		CurrentState = ADSRUnitState::Attack;
		CurrentPosition++;

		Offset = CurrentPosition;
		output = Interpolation(InitLevel, PeakLevel, Offset, AttackTime);
		if (LastOutput != output) isChanged = true;
		if (IsDebugOn && isChanged) {
			// portTwo.print("A");
			// portTwo.print(Offset);
			// portTwo.print("/");
			// portTwo.print(AttackTime);
			// portTwo.print("=");
			// portTwo.print(output);
		}
	}


	if (IsDebugOn && isChanged) {
		// portTwo.println("");
	}

	LastOutput = output;

	return output;
}



void ADSRUnitClass::init()
{


}
