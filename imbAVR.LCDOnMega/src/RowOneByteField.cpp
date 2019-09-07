// 
// 
// 

#include "RowOneByteField.h"

byte RowOneByteField::Deploy(GuiScreen screen)
{
	DeployBase(screen, &Field);
}

RowOneByteField::RowOneByteField(String prefix, byte * value, String unit)
{
	LabelPrefix.label = prefix;
	LabelUnit.label = unit;
	Field.SetValue(value);
}



void RowOneByteField::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	Field.print(Display, Screen, this, LabelUnit.x - FieldX);
}
