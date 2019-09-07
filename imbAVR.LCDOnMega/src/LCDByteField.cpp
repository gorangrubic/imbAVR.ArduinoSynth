#include "LCDByteField.h"


void LCDByteField::SetValue(byte * inValue)
{
	value = inValue;
	
}

void LCDByteField::print(ACEMegaHostTFTClass * Display)
{
	if ((Display->redrawScheduled) || (lastValue != *value)) {
		Display->setCursor(x, y);
		Display->setTextColor(BackColor);
		Display->print(lastValue);

		Display->setCursor(x, y);
		Display->setTextColor(TextColor);
		Display->print(*value);

		lastValue = *value;
	}

}
