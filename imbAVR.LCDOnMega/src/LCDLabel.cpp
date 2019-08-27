#include "LCDLabel.h"

void LCDLabel::print(ACEMegaHostTFTClass * Display)
{
	Display->setCursor(x, y);
	Display->setTextColor(TextColor);
	Display->print(label);

}
