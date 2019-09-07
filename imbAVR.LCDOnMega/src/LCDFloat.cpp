// 
// 
// 

#include "LCDFloat.h"

void LCDFloatField::SetValue(float * inValue)
{
	value = inValue;
}
//
//void LCDFloatField::printValue(float v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color)
//{
//}

void LCDFloatField::printValue(float v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color)
{
	switch (renderMode) {


	case FieldValueRenderMode::graphic_bitBoxArray:
	case FieldValueRenderMode::graphic_bitBoxArrayLow4:
	case FieldValueRenderMode::graphic_bitBoxArrayHigh4:
		break;


	case FieldValueRenderMode::numeric_percentage:
		Display->setTextColor(Color);
		
		Display->print(v*100,2);
		Display->print("%");
		break;

	case FieldValueRenderMode::numeric_ratio:
		Display->setTextColor(Color);
		
		Display->print(v, 5);
		break;
	case FieldValueRenderMode::numeric_value:
		Display->setTextColor(Color);
		Display->print(v,2);
		break;
	default:
		Screen->drawValue(y, x, width, Screen->GetCharScreenHeight(), v, renderMode, Display, Color, BackColor);
		break;
	}

}

void LCDFloatField::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
{
	if ((Display->redrawScheduled) || (lastValue != *value)) {

		unsigned int y = Screen->GetYPosition(row->Row);



		switch (renderMode) {

		case FieldValueRenderMode::numeric_percentage:
		case FieldValueRenderMode::numeric_ratio:
		case FieldValueRenderMode::numeric_value:
			printValue(lastValue, Display, Screen, row, width, y, BackColor);
			printValue(*value, Display, Screen, row, width, y, TextColor);
			break;

		default:
			Display->fillRect(x, y, width, Screen->GetCharScreenHeight(), BackColor);
			printValue(*value, Display, Screen, row, width, y, TextColor);

			break;
		}


		lastValue = *value;
	}

}



