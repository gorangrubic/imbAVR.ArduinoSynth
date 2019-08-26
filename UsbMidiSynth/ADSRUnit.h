// ADSRUnit.h

#ifndef _ADSRUNIT_h
#define _ADSRUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum ADSRUnitState {
	off,
	Attack,
	Decay,
	Sustain,
	Release
};


class ADSRUnitClass
{
protected:


public:

	unsigned int CurrentPosition = 0;
	
	ADSRUnitState CurrentState = ADSRUnitState::off;


	bool IsDebugOn = true;

	//void SetTimes(unsigned int At, unsigned int Dt, unsigned int Rt, byte InitLevel, byte PeakLevel, byte SustainLevel);

	void SetTimes(unsigned int At, unsigned int Dt, unsigned int Rt);

	void SetLevels(byte iL, byte pL, byte sL);

	//void ReportADSR(ADSRUnitClass adsr, byte ampVal, SoftwareSerial portTwo);
	
	unsigned int TotalTime = 0;

	unsigned int AttackTime = 0;

	unsigned int DecayTime = 0;

	unsigned int ReleaseTime = 0;


	byte LastOutput = 0;

	byte InitLevel;
	byte PeakLevel;
	byte SustainLevel;


	/// <summary>
	/// Sets IsActive to true and CurrentPosition to 0
	/// </summary>
	void Restart();

	void NoteOff();

	//void SetState(bool noteOn);

	float GetRatio(unsigned int part, unsigned int total, float whenPartIsZero = 0.0, float whenTotalIsZero = 1.0);

	byte Interpolation(byte from, byte to, unsigned int index, unsigned int length);

	/// <summary>
	/// Moves <c>CurrentPosition</c> for one tick, and returns value at that position
	/// </summary>
	/// <returns></returns>
	byte DoTick(bool);

	void init();
};

//extern ADSRUnitClass ADSRUnit;

#endif

