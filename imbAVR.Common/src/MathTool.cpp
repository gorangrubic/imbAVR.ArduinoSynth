
#include "MathTool.h"



float MathTool::GetRatio(unsigned int part, unsigned int total, float whenPartIsZero = 0.0, float whenTotalIsZero = 1.0) {

	if (part == 0) return whenPartIsZero;
	if (total == 0) return whenTotalIsZero;

	float result = (float)part / (float)total;

	if (result > 1.0) result = 1.0;
	if (result < 0.0) result = 0.0;

	return result;

}


byte MathTool::Interpolation(byte from, byte to, unsigned int index, unsigned int length) {

	bool isPositiveDirection = true;
	byte step = 0;

	if (from > to) {
		isPositiveDirection = false;
		step = from - to;
	}
	else {
		step = to - from;
	}

	step = MathTool::GetRatio(index, length) * step;

	if (isPositiveDirection) {
		return from + step;
	}
	else {
		return from - step;
	}
}

byte MathTool::GetPhaseShift(byte CCValue)
{
	byte w = CCValue / 20;
	return w;
}

byte MathTool::GetPWMWaveform(byte CCValue)
{

	byte w = CCValue / 20;

	switch (w) {
	case 0:
		return B10000000;
		break;
	case 1:
		return B11000000;
		break;
	case 2:
		return B11100000;
		break;
	case 3:
		return B11110000;
		break;
	case 4:
		return B11111000;
		break;
	case 5:
		return B11111100;
		break;
	default:
	case 6:
		return B11111110;
		break;
	
	}

	return byte();
}


byte MathTool::GetCCValueForWaveform(byte pwmPattern)
{

	byte w = 0; // CCValue / 20;

	switch (w) {
	case B10000000:
		w = 0;
		break;
	case B11000000:
		w = 1;
		
		break;
	case B11100000:
		w = 2;
		
		break;
	case B11110000:
		w = 3;
		
		break;
	case B11111000:
		w = 4;
		
		break;
	case B11111100:
		w = 5;
		
		break;
	default:
	case B11111110:
		w = 6;
		
		break;

	}

	return w * 20;
}
