#include "LCDLabel.h"



//void LCDLabel::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width=0)
//{
//	unsigned int y = Screen->GetYPosition(row->Row);
//	if (width == 0) width = Screen->GetXPosition(Cw);
//
//	//int yStart = Screen->GetYPosition(row->Row) + yMargin;
//	int h = Screen->GetCharScreenHeight() * row->RowHeight;
//
//	Display->fillRect(Screen->GetXPosition(Cx) + Screen->generalMarginX, y, width- Screen->generalMarginX, h - Screen->generalMarginY, BackColor);
//
//	
//	Display->setCursor(Screen->GetXPosition(Cx), y);
//	Display->setTextColor(TextColor);
//	Display->print(label);
//}

LCDLabel::LCDLabel(String _label)
{
	label = _label;
	elementType = ELEMENTTYPE_LABEL;
}

LCDLabel::LCDLabel()
{
	elementType = ELEMENTTYPE_LABEL;
}

void LCDLabel::Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)
{

	Display->println("-- LCDLabel Render");

	// if its first call
	if ((state & B00000001) == B00000001) {

		Display->fillRect(x, y, w, h, Backcolor);

		switch (GetAligment(options)) {
		case LCDElementAligment::left:
			Display->setCursor(x, y);
			break;
		case LCDElementAligment::middle:
			unsigned int tw1 = char_w * label.length();
			Display->setCursor(x + (tw1 / 2), y);
			break;
		case LCDElementAligment::right:
			unsigned int tw2 = char_w * label.length();
			Display->setCursor(x + tw2, y);
			break;
		}

		Display->setTextColor(Forecolor);
		Display->print(label);

	}
}

// xxxx xxx1  - inverse back and text
// xxxx xx1x  - use alternative pallete
// xxxx x1xx  - use critical color for value
// xxxx 1xxx  - blinks
// xx00 xxxx  - right aligment
// xx10 xxxx  - middle aligment
// xx11 xxxx  - left aligment
// 01xx xxxx  - 2 x width
// 10xx xxxx  - 4 x width
// 11xx xxxx  - 8 x width
