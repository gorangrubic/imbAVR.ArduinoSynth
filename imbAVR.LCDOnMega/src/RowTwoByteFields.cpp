#include "RowTwoByteFields.h"


byte RowTwoByteFields::Deploy(GuiScreen screen)
{
	int y = screen.GetYPosition(Row);
	int cw = screen.GetCharScreenWidth();

	int column_cw = cw / 2;

	LeftField.y = y;
	LeftLabel.y = y;
	RightField.y = y;
	RightLabel.y = y;

	LeftLabel.x = 0;
	LeftField.x = screen.GetXPosition(column_cw - 5);

	RightLabel.x = screen.GetXPosition(column_cw);
	RightField.x = screen.GetXPosition(column_cw + (column_cw - 5));

	LeftField.TextColor = screen.FieldColor;
	RightField.TextColor = screen.FieldColor;

	LeftLabel.TextColor = screen.LabelColor;
	RightLabel.TextColor = screen.LabelColor;

	return 1;
}

//void RowTwoByteFields::Deploy(GuiScreen screen, uint16_t fieldColor)
//{
//	Deploy(screen);
//	LeftField.TextColor = fieldColor;
//	RightField.TextColor = fieldColor;
//}

void RowTwoByteFields::PrintLabels(ACEMegaHostTFTClass * Display)
{
	LeftLabel.print(Display);
	RightLabel.print(Display);
}

void RowTwoByteFields::UpdateFields(ACEMegaHostTFTClass * Display)
{

	LeftField.print(Display);
	RightField.print(Display);
}

void RowTwoByteFields::Set(String leftLabel, String rightLabel, byte * leftValue, byte * rightValue)
{
	LeftLabel.label = leftLabel;
	RightLabel.label = rightLabel;
	LeftField.SetValue(leftValue);
	RightField.SetValue(rightValue);
}

RowTwoByteFields::RowTwoByteFields(String leftLabel, String rightLabel, byte * leftValue, byte *rightValue)
{
	LeftLabel.label = leftLabel;
	RightLabel.label = rightLabel;
	LeftField.SetValue(leftValue);
	RightField.SetValue(rightValue);
}

RowTwoByteFields::RowTwoByteFields(String leftLabel, String rightLabel, unsigned int row)
{
	LeftLabel.label = leftLabel;
	RightLabel.label = rightLabel;
	Row = row;
}

RowTwoByteFields::RowTwoByteFields(unsigned int row)
{
	Row = row;
}
