#include "RowHeading.h"

void RowHeading::Deploy(GuiScreen screen, String heading)
{
	y = screen.GetYPosition(Row);
	
	w = screen.ScreenWidth;
	h = screen.GetHeight(1);

	int mid_x = screen.ScreenWidth / 2;
	
	int hw = screen.GetWidth(heading.length());

	x = 0;

	LeftLabel.x = mid_x - (hw / 2);
	LeftLabel.y = y;
	LeftLabel.label = heading;
	
	TextColor = screen.LabelBackColor;
	BackColor = screen.LabelColor;

}

RowHeading::RowHeading(int row)
{
	Row = row;
}

void RowHeading::PrintLabels(ACEMegaHostTFTClass * Display)
{
	Display->fillRect(0, y, w, h, BackColor);
	LeftLabel.TextColor = TextColor;
	LeftLabel.print(Display);
}
