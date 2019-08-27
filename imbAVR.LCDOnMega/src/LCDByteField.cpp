#include "LCDByteField.h"


void LCDByteField::SetValue(byte inValue)
{
	value = inValue;
	
}

void LCDByteField::print(ACEMegaHostTFTClass * Display)
{

	Display->setCursor(x, y);
	Display->setTextColor(BackColor);
	Display->print(lastValue);

	Display->setCursor(x, y);
	Display->setTextColor(TextColor);
	Display->print(value);

	lastValue = value;
}
