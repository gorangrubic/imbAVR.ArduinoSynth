#include "LCDLabel.h"



void LCDLabel::print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
{
	unsigned int y = Screen->GetYPosition(row->Row);
	
	Screen->FillBackground(row, Display, BackColor, Screen->generalMarginY, Screen->generalMarginX, row->RowHeight);

	Display->setCursor(x, y);
	Display->setTextColor(TextColor);
	Display->print(label);
}
