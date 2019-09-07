#include "RowHeading.h"



byte RowHeading::Deploy(GuiScreen screen)
{
	y = screen.GetYPosition(Row);
	
	w = screen.ScreenWidth;
	h = screen.GetHeight(1);

	int mid_x = screen.ScreenWidth / 2;
	
	int hw = screen.GetWidth(LeftLabel.label.length());

	x = 0;

	LeftLabel.x = mid_x - (hw / 2);
	LeftLabel.y = y;
	 //= heading;
	
	TextColor = screen.LabelBackColor;
	BackColor = screen.LabelColor;

	return 1;
}

RowHeading::RowHeading(String heading)
{
	LeftLabel.label = heading;
}


RowHeading::RowHeading()
{
	
}

void RowHeading::PrintLabels(ACEMegaHostTFTClass * Display)
{
	Display->fillRect(0, y, w, h, BackColor);
	LeftLabel.TextColor = TextColor;
	LeftLabel.print(Display);
}

void RowHeading::UpdateFields(ACEMegaHostTFTClass * Display)
{
}


