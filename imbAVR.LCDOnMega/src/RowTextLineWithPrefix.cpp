// 
// 
// 

#include "RowTextLineWithPrefix.h"

RowTextLineWithPrefix::RowTextLineWithPrefix(String prefix, String * value, String unit)
{
	LabelPrefix.label = prefix;
	LabelUnit.label = unit;
	Field.SetValue(value);
}
