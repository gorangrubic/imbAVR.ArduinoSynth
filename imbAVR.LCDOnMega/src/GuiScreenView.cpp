// 
// 
// 

#include "GuiScreenView.h"

#include "GuiDrawingTools.h"


byte GuiScreenView::AddRow(RowBase * row, GuiScreen * Screen)
{
	Rows[ActiveRows] = row;
	Rows[ActiveRows]->Row = ActiveRows;

	Rows[ActiveRows]->Deploy(Screen);
	//Rows[ActiveRows]->Deploy(*Screen);

	ActiveRows++;
}



GuiScreenView::GuiScreenView()
{
}

inline void GuiScreenView::RenderElement(LCDElement * element, unsigned int chw, unsigned int y, unsigned int h, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state) {
	
	unsigned int x = chw * element->Cx;
	unsigned int w = chw * element->Cw;

	GuiScreenPallete * pallete = &Screen->PalleteA;
	if ((element->options & B00000010) == B00000010) {
		pallete = &Screen->PalleteB;
	}

	unsigned int Forecolor = pallete->LabelColor;
	unsigned int Backcolor = pallete->LabelBackColor;

	if (element->elementType != ELEMENTTYPE_LABEL) {
		Forecolor = pallete->FieldColor;
		Backcolor = pallete->FieldBackColor;
	}

	if ((element->options & B00000100) == B00000100) {
		Forecolor = pallete->CriticalColor;
	}

	bool inverseColors = ((element->options & B00000001) == B00000001);
	if ((element->options & B00001000) == B00001000) {
		if ((state & B00000100) == B00000100) inverseColors != inverseColors;
	}

	if (inverseColors) {
		unsigned int color = Backcolor;
		Backcolor = Forecolor;
		Forecolor = color;
	}


	element->Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);
}

void GuiScreenView::Render(GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state)
{
	byte yC = 0;
	for (size_t i = 0; i < ActiveRows; i++)
	{
		RowBase * row = Rows[i];

		//Display->print("Rendering ");
		//Display->println(i);

		row->Render(Screen, Display, state, yC);

		yC += row->RowHeight;
	}

}