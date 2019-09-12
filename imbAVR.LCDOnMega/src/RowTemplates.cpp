#include "RowTemplates.h"




RowHeader RowTemplates::RowHeading(String text)
{
	RowHeader row = RowHeader();
	row.Label = row.SetLabel(0, B00000001, text);
	row.Label.SetAligment(LCDElementAligment::middle);
	return row;
}

//Row<2> RowTemplates::RowTextWithPrefix(String prefix, String * text)
//{
//	Row<2> row = Row<2>();
//	LCDLabel prefixLabel = row.SetLabel(0, B00000001, prefix);
//
//	LCDField<String> textField = row.SetField(1, B11000000, text);
//
//	textField.SetAligment(LCDElementAligment::left);
//
//	return row;
//}
//
//Row<4> RowTemplates::RowWithTwoByteFields(String labelA, byte * valueA, String labelB, byte * valueB, FieldValueRenderMode mode)
//{
//	Row<4> row = Row<4>();
//
//	LCDLabel aLabel = row.SetLabel(0, B00000001, labelA);
//
//	LCDField<byte> aField = row.SetField(1, B00000000, valueA, mode);
//
//	LCDLabel bLabel = row.SetLabel(2, B00000001, labelB);
//
//	LCDField<byte> bField = row.SetField(3, B00000000, valueB, mode);
//
//	return row;
//}
//
//Row<8> RowTemplates::RowWithFourByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC, String labelD, byte * valueD, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value)
//{
//	Row<8> row = Row<8>();
//
//	LCDLabel aLabel = row.SetLabel(0, B00000001, labelA);
//
//	LCDField<byte> aField = row.SetField(1, B00000000, valueA, mode);
//
//	LCDLabel bLabel = row.SetLabel(2, B00000001, labelB);
//
//	LCDField<byte> bField = row.SetField(3, B00000000, valueB, mode);
//
//	LCDLabel cLabel = row.SetLabel(4, B00000001, labelC);
//
//	LCDField<byte> cField = row.SetField(5, B00000000, valueC, mode);
//
//	LCDLabel dLabel = row.SetLabel(6, B00000001, labelD);
//
//	LCDField<byte> dField = row.SetField(7, B00000000, valueD, mode);
//
//	return row;
//
//}

RowTextAndPrefix RowTemplates::RowTextWithPrefix(String prefix, String text)
{
	RowTextAndPrefix row = RowTextAndPrefix();
	row.prefixLabel = row.SetLabel(0, B00000001, prefix);

	row.textField = row.SetField(1, B11000000, text);

	row.textField.SetAligment(LCDElementAligment::left);

	return row;
}

RowTwoByteFields RowTemplates::RowWithTwoByteFields(String labelA, byte valueA, String labelB, byte valueB, FieldValueRenderMode mode)
{
	RowTwoByteFields row = RowTwoByteFields();

	row.Labels[0] = row.SetLabel(0, B00000001, labelA);

	row.Properties[0] = row.SetField(1, B00000000, valueA, mode);

	row.Labels[1] = row.SetLabel(2, B00000001, labelB);

	row.Properties[1] = row.SetField(3, B00000000, valueB, mode);

	return row;
}

RowFourByteFields RowTemplates::RowWithFourByteFields(String labelA, byte valueA, String labelB, byte valueB, String labelC, byte  valueC, String labelD, byte  valueD, FieldValueRenderMode mode)
{
	RowFourByteFields row = RowFourByteFields();

	row.Labels[0] = row.SetLabel(0, B00000001, labelA);

	row.Properties[0] = row.SetField(1, B00000000, valueA, mode);

	row.Labels[1] = row.SetLabel(2, B00000001, labelB);

	row.Properties[1] = row.SetField(3, B00000000, valueB, mode);

	row.Labels[2] = row.SetLabel(4, B00000001, labelC);

	row.Properties[2] = row.SetField(5, B00000000, valueC, mode);

	row.Labels[3] = row.SetLabel(6, B00000001, labelD);

	row.Properties[3] = row.SetField(7, B00000000, valueD, mode);

	return row;
}
