// 
// 
// 

#include "SignalControlManager.h"

#define SUNIT_i SignalUnits[i]

byte SignalControlManagerClass::AddSignalUnit(byte pin)
{
	SignalUnits[ActiveUnitCount].pin = pin;
	pinMode(pin, OUTPUT);
	ActiveUnitCount++;

	return ActiveUnitCount - 1;
}

byte SignalControlManagerClass::RollPattern(byte pwmPattern, int bits)
{

	if (bits > 0) {
		int phase_shift = abs(bits);
		byte right_trim = pwmPattern << (8 - phase_shift);
		pwmPattern = pwmPattern >> phase_shift;
		pwmPattern = pwmPattern | right_trim;
	}
	else {
		int phase_shift = abs(bits);
		byte right_trim = pwmPattern >> (8 - phase_shift);
		pwmPattern = pwmPattern << phase_shift;
		pwmPattern = pwmPattern | right_trim;
	}

	return pwmPattern;
}

byte SignalControlManagerClass::DoublePitchInPattern(byte pattern)
{
	byte patternDbl;

	for (size_t i = 0; i < 4; i++)
	{
		int b = bitRead(pattern, i*2);
		bitWrite(patternDbl, i, b);
		bitWrite(patternDbl, 4+i, b);
	}

	if (patternDbl == B00000000 || patternDbl == B11111111) {
		patternDbl == B10101010;
	}

	return patternDbl;
}

String SignalControlManagerClass::Describe(SignalInstruction instruction, unsigned int index=0)
{
	String output = "i[";
	output += index;
	output += "]S[";
	output += instruction.SignalID;
	output += "]F[";
	output += instruction.Frequency;
	output += "]W[";
	output += instruction.pwmPattern;
	output += "]P[";
	output += instruction.Phase;
	output += "]";

	/*
	serialOut->print("SID ");
	serialOut->println(instruction.SignalID);

	serialOut->print("FRQ ");
	serialOut->println(instruction.Frequency);

	serialOut->print("WFM ");
	serialOut->println(instruction.pwmPattern);

	byte phase_shift = (instruction.Phase & B11110000) >> 4;

	serialOut->print("Phase ");
	serialOut->println(phase_shift);
	*/
	output += "[";
	output += bitRead(instruction.Phase, 0);
	output += bitRead(instruction.Phase, 1);
	output += bitRead(instruction.Phase, 2);
	output += bitRead(instruction.Phase, 3);
	output += "]";
	

	return output;


}

#define FREQUENCY_MIN_LIMIT 31

#define FREQUENCY_DBL_LIMIT 200

#define FREQUENCY_PWM_LIMIT 1720

#define MSPERCLOCK 490.0


void SignalControlManagerClass::DescribeAll(HardwareSerial * serialOut) {

	for (size_t i = 0; i < ActiveUnitCount; i++)
	{
		//String msg = "[" + i + "]";

		serialOut->print("[");
		serialOut->print(i);
		serialOut->print("]");

		serialOut->print("[");
		serialOut->print(SignalUnits[i].sClockPerPWMStep);
		serialOut->print(":");
		serialOut->print(SignalUnits[i].sClockPerPWMStepB);
		serialOut->print("]");

		serialOut->print("[");
		serialOut->print(SignalUnits[i].freq);
		serialOut->print("]");

		serialOut->print("[");
		serialOut->print(SignalUnits[i].pwmPatternByte, BIN);
		serialOut->println("]");


	}
}



void SignalControlManagerClass::Perform(SignalInstruction instruction)
{
	byte phase_shift = (instruction.Phase & B11110000) >> 4;

	if (bitRead(instruction.Phase, 0) == 1) SignalUnits[instruction.SignalID].pwmStepIndex = 0;
	if (bitRead(instruction.Phase, 1) == 1) SignalUnits[instruction.SignalID].sClockIndex = 0;
	if (bitRead(instruction.Phase, 2) == 1) SignalUnits[instruction.SignalID].pwmStepIndex += phase_shift;
	if (bitRead(instruction.Phase, 3) == 1) SignalUnits[instruction.SignalID].sClockIndex += phase_shift;

	if (instruction.Frequency < FREQUENCY_MIN_LIMIT) {
		instruction.Frequency = instruction.Frequency * 2;
	}

	SignalUnits[instruction.SignalID].freq = instruction.Frequency;

	if (instruction.Frequency > FREQUENCY_DBL_LIMIT) {

		instruction.Frequency = instruction.Frequency / 2;
		instruction.pwmPattern = DoublePitchInPattern(instruction.pwmPattern);
	}

	

	SignalUnits[instruction.SignalID].pwmPatternByte = instruction.pwmPattern;

	float wavelength = 1 / (float) ((float)instruction.Frequency / (float)PWMCycleSize);

	float sClockPerPWMStep = wavelength * CycleCompensation;

	float sClockPerPWMStepA = floor(sClockPerPWMStep);
	float sClockPerPWMStepB = floor((sClockPerPWMStep - sClockPerPWMStepA) * 10);

	SignalUnits[instruction.SignalID].sClockPerPWMStep = constrain(sClockPerPWMStepA, 1, 255);
	SignalUnits[instruction.SignalID].sClockPerPWMStepB = constrain(sClockPerPWMStepB, 1, 255);




}

void SignalControlManagerClass::loop() 
{
	CycleIndex++;

	for (size_t i = 0; i < ActiveUnitCount; i++)
	{
		// CYCLE index control ----------------------------------------------------------------------------------------
		SUNIT_i.sClockIndex++;

		bool sClockTick = false;

		if (CycleIndex < SUNIT_i.sClockPerPWMStepB) {
			sClockTick = SUNIT_i.sClockIndex > SUNIT_i.sClockPerPWMStep;
		}
		else {
			sClockTick = SUNIT_i.sClockIndex >= SUNIT_i.sClockPerPWMStep;
		}

		/*if (CycleIndex >= 10) {
			
		}
		else {
			sClockTick = SUNIT_i.sClockIndex >= (SUNIT_i.sClockPerPWMStep + SUNIT_i.sClockPerPWMStepB);
		}*/

		if (sClockTick) {
			
			SUNIT_i.pwmStepIndex ++;
			
			if (SUNIT_i.pwmStepIndex >= PWMCycleSize) {
				SUNIT_i.pwmStepIndex = SUNIT_i.pwmStepIndex % PWMCycleSize;
			}

			digitalWrite(SUNIT_i.pin, bitRead(SUNIT_i.pwmPatternByte, SUNIT_i.pwmStepIndex));

			SUNIT_i.sClockIndex = 0;
		}
		

		
		// ---------------------------------------------------------------------------------------- CYCLE index control 

		/*
			// SIGNAL generation  -----------------------------------------------------------------------------------------
			if (bitRead(SUNIT_i.pwmPatternByte, SUNIT_i.pwmStepIndex)==0) {
				digitalWrite(SUNIT_i.pin, LOW);
			}
			else {
				digitalWrite(SUNIT_i.pin, HIGH);
			}
			// ------------------------------------------------------------------------------------------ SIGNAL generation  
		*/
	}

	
	if (CycleIndex >= 10) {
		CycleIndex = 0;
	}
}
