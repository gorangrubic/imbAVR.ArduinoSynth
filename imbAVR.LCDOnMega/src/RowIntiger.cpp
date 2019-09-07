// 
// 
// 

#include "RowIntiger.h"

void RowIntiger::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	Field.print(Display, Screen, this, LabelUnit.x - FieldX);
}

byte RowIntiger::Deploy(GuiScreen screen)
{
	DeployBase(screen, &Field);
}

RowIntiger::RowIntiger(String prefix, int * value, String unit)
{
	LabelPrefix.label = prefix;
	LabelUnit.label = unit;
	Field.SetValue(value);
}


