#include "RowTwoByteFields.h"


byte RowTwoByteFields::Deploy(GuiScreen screen)
{
	int y = screen.GetYPosition(Row);
	int cw = screen.GetCharScreenWidth();

	int column_cw = cw / 2;

	LeftLabel.x = 0;
	LeftField.x = screen.GetXPosition(column_cw - 5);

	RightLabel.x = screen.GetXPosition(column_cw);
	RightField.x = screen.GetXPosition(column_cw + (column_cw - 5));

	screen.DeployLabel(&RightLabel, this);
	screen.DeployLabel(&LeftLabel, this);

	screen.DeployField(&LeftField, this);
	screen.DeployField(&RightField, this);

	return 1;
}

void RowTwoByteFields::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	LeftLabel.print(Display, Screen, this, LeftField.x- LeftLabel.x);
	RightLabel.print(Display, Screen, this, RightField.x - RightLabel.x);
}

void RowTwoByteFields::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	LeftField.print(Display, Screen, this, RightLabel.x - LeftField.x);
	RightField.print(Display, Screen, this, Screen->ScreenWidth - RightField.x);
}

//void RowTwoByteFields::Deploy(GuiScreen screen, uint16_t fieldColor)
//{
//	Deploy(screen);
//	LeftField.TextColor = fieldColor;
//	RightField.TextColor = fieldColor;
//}


//
//void RowTwoByteFields::Set(String leftLabel, String rightLabel, byte * leftValue, byte * rightValue)
//{
//	LeftLabel.label = leftLabel;
//	RightLabel.label = rightLabel;
//	LeftField.SetValue(leftValue);
//	RightField.SetValue(rightValue);
//}

RowTwoByteFields::RowTwoByteFields(String leftLabel, String rightLabel, byte * leftValue, byte *rightValue)
{
	LeftLabel.label = leftLabel;
	RightLabel.label = rightLabel;
	LeftField.SetValue(leftValue);
	RightField.SetValue(rightValue);
}

//RowTwoByteFields::RowTwoByteFields(String leftLabel, String rightLabel, unsigned int row)
//{
//	LeftLabel.label = leftLabel;
//	RightLabel.label = rightLabel;
//	Row = row;
//}

RowTwoByteFields::RowTwoByteFields()
{
	
}
