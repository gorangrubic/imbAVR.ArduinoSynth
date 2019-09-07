// 
// 
// 

#include "RowFloat.h"

byte RowFloat::Deploy(GuiScreen screen)
{
	DeployBase(screen, &Field);
}

RowFloat::RowFloat(String prefix, float * value, String unit)
{
	LabelPrefix.label = prefix;
	LabelUnit.label = unit;
	Field.SetValue(value);
}


void RowFloat::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	Field.print(Display, Screen, this, LabelUnit.x - FieldX);
}


