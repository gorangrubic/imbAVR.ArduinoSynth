#include "LCDField.h"

void LCDField::setPosition(ACEMegaHostTFTClass * Display)
{
	x = Display->getCursorX();
	y = Display->getCursorY();
}
