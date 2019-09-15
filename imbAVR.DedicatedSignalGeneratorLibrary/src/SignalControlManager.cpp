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



void SignalControlManagerClass::Receive(byte receivedByte)
{

	

	if (ExpectingValueByte) {

		boolean valueReceived = false;
		switch (CurrentCC) 
		{
			case CCID_PITCHBYTELOW:
			case CCID_CHANGE_PWM:
			case CCID_CHANGE_PHASE:
			case CCID_CHANGE_PITCH:
			case CCID_CHANGE_RESET:
				TempByte = receivedByte;
				valueReceived = false;
				break;
			default:
				valueReceived = true;
				break;
		}


		switch (CurrentSID)
		{
		case 13:
			SetCC(CurrentCC, receivedByte, &SignalUnits[0]);
			SetCC(CurrentCC, receivedByte, &SignalUnits[1]);
			break;
		case 14:
			SetCC(CurrentCC, receivedByte, &SignalUnits[2]);
			SetCC(CurrentCC, receivedByte, &SignalUnits[3]);
			break;
		case 15:
			SetCC(CurrentCC, receivedByte, &SignalUnits[4]);
			SetCC(CurrentCC, receivedByte, &SignalUnits[5]);
			break;
		case 16:
			for (size_t i = 0; i < ActiveUnitCount; i++)
			{
				SetCC(CurrentCC, receivedByte, &SignalUnits[i]);
			}
			break;
		default:
			SetCC(CurrentCC, receivedByte, &SignalUnits[CurrentSID]);
			break;
		}

		if (valueReceived) {
			ExpectingValueByte = false;
		}
	}
	else {



		CurrentSID = receivedByte & B00001111;
		CurrentCC = (receivedByte & B11110000) >> 4;

		
		ExpectingValueByte = true;

	}

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
		serialOut->print(SignalUnits[i].pwmByte, BIN);
		serialOut->println("]");


	}
}

void SignalControlManagerClass::PerformPhaseByte(byte Phase, SignalControlUnitClass * signal) {

	byte phase_shift = (Phase & B11110000) >> 4;

	if (bitRead(Phase, 0) == 1) signal->pwmStepIndex = 0;
	if (bitRead(Phase, 1) == 1) signal->sClockIndex = 0;
	if (bitRead(Phase, 2) == 1) signal->pwmStepIndex += phase_shift;
	if (bitRead(Phase, 3) == 1) signal->sClockIndex += phase_shift;
}

void SignalControlManagerClass::PerformModeByte(byte mode, SignalControlUnitClass * signal) {

	/*signal->pwmContinualMode = ((mode & B00000001) == B00000001);
	if ((mode & B00000010) == B00000010) {
		signal->sClockPrescalar = 2;
	}*/

	signal->isOn = ((mode & B00000100) == B00000100);

	signal->pwmContinualMode = (bitRead(mode, 0) == 1);

	if (bitRead(mode, 1) == 1) {
		signal->sClockPrescalar = 2;
	}
	else {
		signal->sClockPrescalar = 1;
	}
	

	//SUNIT_sid.masterPitchRelationship = b2 >> 4;

	signal->IsPitchSlave = (bitRead(mode, 3) == 1);
	signal->IsPositiveRelation = (bitRead(mode, 4) == 1);
	signal->IsRelativeDistanceMode = (bitRead(mode, 5) == 1);
	signal->IsMidiNote = (bitRead(mode, 6) == 1);


}

void SignalControlManagerClass::PerformPitch(unsigned int Pitch, SignalControlUnitClass * signal) {


	//signal->freq = 
		
	signal->freq = Pitch;

	/*if (instruction.Frequency > FREQUENCY_DBL_LIMIT) {

		instruction.Frequency = instruction.Frequency / 2;
		instruction.pwmPattern = DoublePitchInPattern(instruction.pwmPattern);
	}
*/
		signal->pwmContinualSClockIndexChange = 0;

	//SignalUnits[instruction.SignalID].pwmPatternByte = instruction.pwmPattern;

	float wavelength = 1 / (float)((float)Pitch / (float)PWMCycleSize);

	float sClockPerPWMStep = wavelength * CycleCompensation;

	float sClockPerPWMStepA = floor(sClockPerPWMStep);
	float sClockPerPWMStepB = floor((sClockPerPWMStep - sClockPerPWMStepA) * 10);

	signal->sClockPerPWMStep = constrain(sClockPerPWMStepA, 1, 255);
	signal->sClockPerPWMStepB = constrain(sClockPerPWMStepB, 1, 255);


}



void SignalControlManagerClass::loop()
{
	CycleIndex++;

	for (size_t i = 0; i < ActiveUnitCount; i++)
	{
		if (!SUNIT_i.isOn) continue;


		// CYCLE index control ----------------------------------------------------------------------------------------
		SUNIT_i.sClockIndex++;



		/*if (CycleIndex >= 10) {

		}
		else {
			sClockTick = SUNIT_i.sClockIndex >= (SUNIT_i.sClockPerPWMStep + SUNIT_i.sClockPerPWMStepB);
		}*/


		bool sClockTick = false;

		if (CycleIndex < SUNIT_i.sClockPerPWMStepB) {
			sClockTick = SUNIT_i.sClockIndex > SUNIT_i.sClockPerPWMStep;
		}
		else {
			sClockTick = SUNIT_i.sClockIndex >= SUNIT_i.sClockPerPWMStep;
		}


		if (!SUNIT_i.pwmContinualMode) {

			

			if (sClockTick) {


				SUNIT_i.pwmStepIndex++;

				if (SUNIT_i.pwmStepIndex >= PWMCycleSize) {
					SUNIT_i.pwmStepIndex = SUNIT_i.pwmStepIndex % PWMCycleSize;
				}

				digitalWrite(SUNIT_i.pin, bitRead(SUNIT_i.pwmByte, SUNIT_i.pwmStepIndex));

				SUNIT_i.sClockIndex = 0;
			}


		}
		else {

			if (SUNIT_i.pwmContinualSClockIndexChange == 0) {

				SUNIT_i.pwmContinualSClockIndexChange = floor(((float)SUNIT_i.pwmByte / 255.0) * (SUNIT_i.sClockPerPWMStep * 8));

			}


			if (SUNIT_i.sClockIndex < SUNIT_i.pwmContinualSClockIndexChange) {
				digitalWrite(SUNIT_i.pin, HIGH);
			}
			else {
				digitalWrite(SUNIT_i.pin, LOW);
			}


			if (sClockTick) {

				SUNIT_i.pwmStepIndex++;
				
				if (SUNIT_i.pwmStepIndex >= PWMCycleSize) {
					SUNIT_i.pwmStepIndex = SUNIT_i.pwmStepIndex % PWMCycleSize;
					SUNIT_i.sClockIndex = 0;
				}

			}

		}

		if (SUNIT_i.sClockIndex == 0) {

			// EXECUTING CHANGES

			if (SUNIT_i.PhaseChange.Change != 0) {

				SUNIT_i.PhaseChange.RateIndex++;

				if (SUNIT_i.PhaseChange.RateIndex > SUNIT_i.PhaseChange.Rate) {
					PerformPhaseByte(SUNIT_i.PhaseChange.Change, &SUNIT_i);
					SUNIT_i.PhaseChange.RateIndex = 0;

					if (SUNIT_i.PhaseChange.mode > 0) {

						SUNIT_i.PhaseChange.PerformPeriod();
					}
				}
			}
			
			if (SUNIT_i.PWMChange.Change != 0) {

				SUNIT_i.PWMChange.RateIndex++;

				if (SUNIT_i.PWMChange.RateIndex > SUNIT_i.PWMChange.Rate) {

					if (SUNIT_i.pwmContinualMode) {
						SUNIT_i.pwmByte += (SUNIT_i.PWMChange.Change - 126);
					}
					else {
						
						SUNIT_i.pwmByte = MathTool::GetCCValueForWaveform(SUNIT_i.pwmByte) + ((SUNIT_i.PWMChange.Change - 126)* SUNIT_i.PWMChange.PeriodIndex) / 6.0;
					}
					SUNIT_i.PWMChange.RateIndex = 0;

					if (SUNIT_i.PWMChange.mode > 0) {

						SUNIT_i.PWMChange.PerformPeriod();

					}
				}
			}

			if (SUNIT_i.PitchChange.Change != 0) {

				SUNIT_i.PitchChange.RateIndex++;

				if (SUNIT_i.PitchChange.RateIndex > SUNIT_i.PitchChange.Rate) {
					PerformPitch(SUNIT_i.freq + ((SUNIT_i.PitchChange.Change - 126) * SUNIT_i.PitchChange.PeriodIndex), &SUNIT_i);
					SUNIT_i.PitchChange.RateIndex = 0;
					if (SUNIT_i.PitchChange.mode > 0) {

						SUNIT_i.PitchChange.PerformPeriod();
					}
				}
			}
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
