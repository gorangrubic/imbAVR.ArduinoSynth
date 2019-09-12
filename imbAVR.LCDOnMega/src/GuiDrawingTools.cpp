#include "GuiDrawingTools.h"

#include "MathTool.h"


//
//void GuiDrawingTools::DeployField(GuiScreen * Screen, LCDField * field, RowBase * row, boolean invert)
//{
//
//	if (invert) {
//		field->TextColor = Screen->FieldBackColor;
//		field->BackColor = Screen->FieldColor;
//	}
//	else {
//		field->BackColor = Screen->FieldBackColor;
//		field->TextColor = Screen->FieldColor;
//	}
//
//}
//
//void  GuiDrawingTools::DeployLabel(GuiScreen * Screen, LCDLabel * label, RowBase * row, boolean invert)
//{
//
//	if (invert) {
//		label->TextColor = Screen->LabelBackColor;
//		label->BackColor = Screen->LabelColor;
//	}
//	else {
//		label->BackColor = Screen->LabelBackColor;
//		label->TextColor = Screen->LabelColor;
//	}
//
//
//}
//void GuiDrawingTools::print(LCDField * Field, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width)
//{
//}
//
//void GuiDrawingTools::RenderRow(RowBase * row, ACEMegaHostTFTClass * Display, GuiScreen * Screen, byte yC, byte state)
//{
//	unsigned int y = Screen->GetYPosition(yC);
//	unsigned int h = Screen->GetYPosition(row->RowHeight);
//	unsigned int chw = Screen->GetCharScreenWidth();
//
//	for (size_t i = 0; i < row->elements_n; i++)
//	{
//		unsigned int x = chw * row->_Elements[i].Cx;
//		unsigned int w = chw * row->_Elements[i].Cw;
//
//		GuiScreenPallete * pallete = &Screen->PalleteA;
//		if ((row->_Elements[i].options & B00000010) == B00000010) {
//			pallete = &Screen->PalleteB;
//		}
//
//		unsigned int Forecolor = pallete->LabelColor;
//		unsigned int Backcolor = pallete->LabelBackColor;
//
//		if (row->_Elements[i].elementType != ELEMENTTYPE_LABEL) {
//			Forecolor = pallete->FieldColor;
//			Backcolor = pallete->FieldBackColor;
//		}
//
//		if ((row->_Elements[i].options & B00000100) == B00000100) {
//			Forecolor = pallete->CriticalColor;
//		}
//
//		bool inverseColors = ((row->_Elements[i].options & B00000001) == B00000001);
//		if ((row->_Elements[i].options & B00001000) == B00001000) {
//			if ((state & B00000100) == B00000100) inverseColors != inverseColors;
//		}
//
//		if (inverseColors) {
//			unsigned int color = Backcolor;
//			Backcolor = Forecolor;
//			Forecolor = color;
//		}
//
//		row->_Elements[i].Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);
//
//	}
//
//}

void GuiDrawingTools::drawBitBoxes(unsigned int marginX, unsigned int marginY, unsigned int y, unsigned int x, unsigned int w, unsigned int h, byte bits, byte bitCount, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff)
{
	x = x + (marginX * 2);
	y = y + (marginY * 2);
	w = w - (marginX * 2);
	h = h - (marginY * 2);

	unsigned int dX = w / (bitCount+1);
	unsigned int bW = dX - (marginX * 2);
	unsigned int bH = h - (marginY * 2);

	uint16_t Color = ColorOn;

	for (size_t i = 0; i <= bitCount; i++)
	{
		if (bitRead(bits, bitCount - i) == 0) {
			Display->drawRect(x + (i * dX), y, bW, bH, Color);
		}
		else {
			Display->fillRect(x + (i * dX), y, bW, bH, Color);
		}
		
	}

}

void GuiDrawingTools::drawValue(unsigned int marginX, unsigned int marginY, unsigned int y, unsigned int x, unsigned int w, unsigned int h, float r, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff)
{
	uint16_t Color = ColorOn;
	x = x + (marginX * 2);
	y = y + (marginY * 2);
	w = w - (marginX * 2);
	h = h - (marginY * 2);

	unsigned int d = min(w, h);

	switch (mode) 
	{

	case FieldValueRenderMode::graphic_horizontal_biased_bar:

		r = r - 0.5;
		d = (w / 2) * r; // (d * (1 - r)) / 2;

		Display->fillRect(x + (w / 2), y, d, h, ColorOn);
		Display->fillRect(x + (w / 2), y + (h / 3), -d, h / 3, ColorOff);
		break;
	case FieldValueRenderMode::graphic_horizontal_bar:
		Display->fillRect(x, y, w*r, h, Color);

		break;
	case FieldValueRenderMode::graphic_vertical_bar:
		Display->fillRect(x, y + (h*r), w, h, Color);
		break;
	case FieldValueRenderMode::graphic_vertical_biased_bar:
		Display->fillRect(x, y + (h*r), w, h, Color);


		r = r - 0.5;
		d = (h / 2) * r; // (d * (1 - r)) / 2;

		Display->fillRect(
			x,
			y + (h / 2),
			w,
			d,
			ColorOn);

		Display->fillRect(
			x + (w / 3),
			y + (h / 2),
			-d,
			w - (w / 3),
			ColorOff);

		break;
	case FieldValueRenderMode::graphic_resized_box:
		d = (d * (1 - r)) / 2;
		Display->fillRect(x + d, y + d, w - d, h - d, Color);

		break;
	case FieldValueRenderMode::graphic_resized_circle:
		d = (d * (1 - r)) / 2;
		Display->fillCircle(x + d, y + d, d, Color);
		break;
	case FieldValueRenderMode::graphic_bitBoxArray:
		break;
	case FieldValueRenderMode::graphic_bitBoxArrayLow4:
		break;
	case FieldValueRenderMode::graphic_bitBoxArrayHigh4:
		break;
	case FieldValueRenderMode::graphic_boolean_box:
		if (r < 0.5) {
			Color = ColorOff;
		}
		Display->fillRect(x, y, w, h, Color);
		break;
	case FieldValueRenderMode::graphic_boolean_circle:
		if (r > 0.5) {
			Color = ColorOff;
		}
		d = d / 2;
		Display->fillCircle(x + d, y + d, d, Color);

		break;
	}
}