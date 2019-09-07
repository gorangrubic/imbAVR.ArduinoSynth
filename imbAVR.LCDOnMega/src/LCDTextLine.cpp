// 
// 
// 

#include "LCDTextLine.h"

void LCDTextField::SetValue(String * inValue)
{
	value = inValue;
}

void LCDTextField::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
{
	unsigned int y = Screen->GetYPosition(row->Row);

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

