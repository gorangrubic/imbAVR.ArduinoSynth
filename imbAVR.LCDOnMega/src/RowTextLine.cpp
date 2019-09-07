// 
// 
// 

#include "RowTextLine.h"

RowTextLine::RowTextLine(String * text)
{
	Field.SetValue(text);
}

byte RowTextLine::Deploy(GuiScreen screen)
{
	screen.DeployField(&Field, this);
}

void RowTextLine::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
}

void RowTextLine::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	Field.print(Display, Screen, this, Screen->ScreenWidth);
}
