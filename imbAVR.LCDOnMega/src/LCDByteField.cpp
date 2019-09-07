#include "LCDByteField.h"

#define COMPUTE_BYTERATIO float r = MathTool::GetRatio(v, 255, 1, 0); \
int d = min(Screen->GetCharScreenHeight(), width); \

void LCDByteField::printValue(byte v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color)
{
	switch (renderMode) {


	case FieldValueRenderMode::graphic_bitBoxArray:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight(), v, 8, Display, Color, BackColor);
		break;
	case FieldValueRenderMode::graphic_bitBoxArrayLow4:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight(), v, 4, Display, Color, BackColor);
		break;
	case FieldValueRenderMode::graphic_bitBoxArrayHigh4:
		Screen->drawBitBoxes(y, x, width, Screen->GetCharScreenHeight(), v>>4, 4, Display, Color, BackColor);
		break;

		
	case FieldValueRenderMode::numeric_percentage:
		Display->setTextColor(Color);
		byte p = MathTool::GetRatio(v, 255, 1, 0) * 100;
		Display->print(p);
		Display->print("%");
		break;

	case FieldValueRenderMode::numeric_ratio:
		Display->setTextColor(Color);
		float r = MathTool::GetRatio(v, 255, 1, 0);
		Display->print(r,3);
		break;
	case FieldValueRenderMode::numeric_value:
		Display->setTextColor(Color);
		Display->print(v);
		break;
	default:
		Screen->drawValue(y, x, width, Screen->GetCharScreenHeight(), v, 255, renderMode, Display, Color, BackColor);
		break;
	}

}

void LCDByteField::SetValue(byte * inValue)
{
	value = inValue;
	
}

void LCDByteField::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
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

