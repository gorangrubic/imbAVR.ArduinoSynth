// 
// 
// 

#include "RowFourByteFields.h"

byte RowFourByteFields::Deploy(GuiScreen screen)
{
	int cw = screen.GetCharScreenWidth();

	int column_cw = cw /4;

	for (size_t i = 0; i < 4; i++)
	{
		screen.DeployField(&Fields[i], this);
		screen.DeployLabel(&Labels[i],this);

		int lx = screen.GetXPosition(cw * i); // cw * i;

		int fx = lx - screen.GetXPosition(cw / 2);

		Labels[i].x = lx;
		Fields[i].x = fx;
	}
	

	return 1;
}

void RowFourByteFields::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	for (size_t i = 0; i < 4; i++) Labels[i].print(Display);

}

void RowFourByteFields::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{

	for (size_t i = 0; i < 4; i++) Fields[i].print(Display);
}

RowFourByteFields::RowFourByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC, String labelD, byte * valueD)
{
	Labels[0].label = labelA;
	Labels[1].label = labelB;
	Labels[2].label = labelC;
	Labels[3].label = labelD;

	Fields[0].SetValue(valueA);
	Fields[1].SetValue(valueB);
	Fields[2].SetValue(valueC);
	Fields[3].SetValue(valueD);

}

RowFourByteFields::RowFourByteFields()
{
}

byte RowThreeByteFields::Deploy(GuiScreen screen)
{
	int cw = screen.GetCharScreenWidth();

	int column_cw = cw / 3;

	for (size_t i = 0; i < 3; i++)
	{
		screen.DeployField(&Fields[i], this);
		screen.DeployLabel(&Labels[i], this);

		int lx = screen.GetXPosition(cw * i); // cw * i;

		int fx = lx - screen.GetXPosition(cw / 2);

		Labels[i].x = lx;
		Fields[i].x = fx;
	}


	return 1;
}

void RowThreeByteFields::PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{
	for (size_t i = 0; i < 3; i++) Labels[i].print(Display);
}

void RowThreeByteFields::UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen)
{

	for (size_t i = 0; i < 3; i++) Fields[i].print(Display);
}

RowThreeByteFields::RowThreeByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC)
{
	Labels[0].label = labelA;
	Labels[1].label = labelB;
	Labels[2].label = labelC;
	

	Fields[0].SetValue(valueA);
	Fields[1].SetValue(valueB);
	Fields[2].SetValue(valueC);
	
}

RowThreeByteFields::RowThreeByteFields()
{
}
