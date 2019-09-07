// 
// 
// 

#include "LCDInt16.h"

void LCDInt16Field::SetValue(int * inValue)
{
	value = inValue;
}

void LCDInt16Field::printValue(int v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color)
{
	switch (renderMode) {


	case FieldValueRenderMode::graphic_bitBoxArray:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight()/2, lowByte(v), 8, Display, Color, BackColor);
		Screen->drawBitBoxes(y+ Screen->GetCharScreenHeight() / 2, x, width, Screen->GetCharScreenHeight() / 2, highByte(v), 8, Display, Color, BackColor);
		break;
	case FieldValueRenderMode::graphic_bitBoxArrayLow4:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight() / 2, lowByte(v), 4, Display, Color, BackColor);
		Screen->drawBitBoxes(y + Screen->GetCharScreenHeight() / 2, x, width, Screen->GetCharScreenHeight() / 2, highByte(v), 4, Display, Color, BackColor);

		break;
	case FieldValueRenderMode::graphic_bitBoxArrayHigh4:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight() / 2, lowByte(v) >> 4, 8, Display, Color, BackColor);
		Screen->drawBitBoxes(y + Screen->GetCharScreenHeight() / 2, x, width, Screen->GetCharScreenHeight() / 2, highByte(v) >> 4, 8, Display, Color, BackColor);

		break;


	case FieldValueRenderMode::numeric_percentage:
	case FieldValueRenderMode::numeric_ratio:
	case FieldValueRenderMode::numeric_value:
		Display->setTextColor(Color);
		Display->print(v);
		break;
	default:
		Screen->drawValue(y, x, width, Screen->GetCharScreenHeight(), v, 32767, renderMode, Display, Color, BackColor);
		break;
	}
}

void LCDInt16Field::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
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

