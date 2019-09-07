#include "RowHeading.h"



byte RowHeading::Deploy(GuiScreen screen)
{
	/*y = screen.GetYPosition(Row);
	
	w = screen.ScreenWidth;
	h = screen.GetHeight(1);*/
	screen.DeployLabel(&LeftLabel, this, true);

	int mid_x = screen.ScreenWidth / 2;
	
	int hw = screen.GetWidth(LeftLabel.label.length());

	x = 0;

	LeftLabel.x = mid_x - (hw / 2);
	
	 //= heading;
	
	/*TextColor = screen.LabelBackColor;
	BackColor = screen.LabelColor;*/

	return 1;
}

RowHeading::RowHeading(String heading)
{
	LeftLabel.label = heading;
}


RowHeading::RowHeading()
{
	
}

void RowHeading::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	Screen->FillBackground(this, Display, Screen->BackColor, Screen->generalMarginX, Screen->generalMarginY, RowHeight);
	

	
	LeftLabel.print(Display,Screen,this, Screen->ScreenWidth);
}

void RowHeading::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
}


