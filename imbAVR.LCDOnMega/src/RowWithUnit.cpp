// 
// 
// 

#include "RowWithUnit.h"

void RowWithUnit::DeployBase(GuiScreen screen, LCDField * field)
{

	screen.DeployLabel(&LabelPrefix, this);
	screen.DeployLabel(&LabelUnit, this);

	screen.DeployField(field, this);

	int x = 0;
	int cw = screen.GetCharScreenWidth();



	if (LabelPrefix.label != "") {
		LabelPrefix.x = 0;
		x = screen.GetXPosition((cw / 8) * 3);
	}
	field->x = x;
	FieldX = x;

	if (LabelUnit.label != "") {
		//LabelUnit.x = screen.GetXPosition((cw / 8) * 4);
		x = screen.GetXPosition((cw / 8) * 7);
		LabelUnit.x = x;
	}
	else {
		LabelUnit.x = screen.ScreenWidth;
	}
}

void RowWithUnit::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	if (LabelPrefix.label != "") {
		LabelPrefix.print(Display, Screen, this, FieldX);
	}

	if (LabelUnit.label != "") {
		LabelUnit.print(Display, Screen, this, Screen->ScreenWidth - LabelUnit.x);
	}
}
