#pragma once


#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Row.h"
#include "FieldValueRenderMode.h"

class RowTemplates
{

public:

	template <typename TF> static Row<3> RowWithUnit(String prefix, TF * value, String unit);

	static  RowHeader  RowHeading(String text);

	//static Row<2> RowTextWithPrefix(String prefix, String * text);

	//static Row<4> RowWithTwoByteFields(String labelA, byte * valueA, String labelB, byte * valueB, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	//static Row<8> RowWithFourByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC, String labelD, byte * valueD, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	static RowTextAndPrefix RowTextWithPrefix(String prefix, String text);

	static RowTwoByteFields RowWithTwoByteFields(String labelA, byte valueA, String labelB, byte valueB, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	static RowFourByteFields RowWithFourByteFields(String labelA, byte valueA, String labelB, byte valueB, String labelC, byte  valueC, String labelD, byte  valueD, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);
};

template<typename TF>
inline Row<3> RowTemplates::RowWithUnit(String prefix, TF * value, String unit)
{
	Row<3> row = Row<3>();
	LCDLabel prefixLabel = row.SetLabel(0, B01000001, prefix);

	LCDField<TF> field = row.SetField(1, B10000000, value, FieldValueRenderMode::numeric_value);

	LCDLabel sufixLabel = row.SetLabel(2, B00000001, unit);

	return row;
}
