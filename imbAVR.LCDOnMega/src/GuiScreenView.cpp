// 
// 
// 

#include "GuiScreenView.h"



byte GuiScreenView::AddRow(RowBase *row)
{
	

	Rows[ActiveRows] = row;
	Rows[ActiveRows]->Row = ActiveRows;

	Rows[ActiveRows]->Deploy(*Screen);

	ActiveRows++;
}

GuiScreenView::GuiScreenView(byte id, GuiScreen * screen)
{
	uid = id;
	Screen = screen;

}

GuiScreenView::GuiScreenView()
{
}

void GuiScreenView::PrintLabels(ACEMegaHostTFTClass * Display)
{
	for (size_t i = 0; i < ActiveRows; i++)
	{
		
		Rows[i]->PrintLabels(Display);
		

		//Rows[i].
	}

}

void GuiScreenView::UpdateFields(ACEMegaHostTFTClass * Display)
{
	for (size_t i = 0; i < ActiveRows; i++)
	{
		

		Rows[i]->UpdateFields(Display);

		//Rows[i].
	}
}



