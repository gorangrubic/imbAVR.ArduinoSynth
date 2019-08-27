
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
