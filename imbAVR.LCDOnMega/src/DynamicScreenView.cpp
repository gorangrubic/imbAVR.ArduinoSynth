#include "DynamicScreenView.h"
#include "MathTool.h"
#include "GuiDrawingTools.h"


#define WRITE_TEXT		\
if ((options & B00110000) == B00000000) { Display->setCursor(area.x + margin_x, area.y + margin_y);	 } \
if ((options & B00110000) == B00100000) {	\
	unsigned int tw1 = area.w - (char_w * text.length());	\
	Display->setCursor(area.x + margin_x + (tw1 / 2), area.y + margin_y);	\
}	\
if ((options & B00110000) == B00110000) {	\
	unsigned int tw2 = area.w - (char_w * text.length());	\
	Display->setCursor(area.x + margin_x+tw2, area.y + margin_y);	\
}	\
Display->setTextColor(colors.Forecolor);	\
Display->println(text);			\

void DynamicScreenView::Deploy(GuiScreen * Screen)
{
	cScreenHeight = Screen->GetCharScreenHeight();
	cScreenWidth = Screen->GetCharScreenWidth();
	char_w = Screen->GetWidth(1);
	char_h = Screen->GetHeight(1);
	margin_x = Screen->generalMarginX;
	margin_y = Screen->generalMarginY;
}

ScreenColors DynamicScreenView::GetColors(byte state, byte options, GuiScreen * Screen, bool isField)
{
	ScreenColors output;

	GuiScreenPallete pallete = Screen->PalleteA;
	if ((options & B00000010) == B00000010) {
		pallete = Screen->PalleteB;
	}

	unsigned int Forecolor = pallete.LabelColor;
	unsigned int Backcolor = pallete.LabelBackColor;

	if (isField) {
		Forecolor = pallete.FieldColor;
		Backcolor = pallete.FieldBackColor;
	}

	if ((options & B00000100) == B00000100) {
		Forecolor = pallete.CriticalColor;
	}


	bool inverseColors = ((options & B00000001) == B00000001);
	if ((options & B00001000) == B00001000) {
		if ((state & B00000100) == B00000100) inverseColors != inverseColors;
	}

	if (inverseColors) {
		unsigned int color = Backcolor;
		Backcolor = Forecolor;
		Forecolor = color;
	}

	output.Forecolor = Forecolor;
	output.Backcolor = Backcolor;
	return output;
}

ScreenArea DynamicScreenView::GetArea(byte Columns, byte Column, byte RowHeight, GuiScreen * Screen, byte ColumnWidth)
{
	ScreenArea output;

	unsigned int columnWidth = Screen->ScreenWidth / Columns;

	output.x = columnWidth * Column;
	
	output.w = columnWidth * ColumnWidth;

	if (Column == (Columns - 1)) {
		output.w = Screen->ScreenWidth - output.x;
	}
	output.y = yC * (char_h + (margin_y*2));

	output.h = RowHeight * (char_h + (margin_y * 2));

	return output;
}

void DynamicScreenView::FillArea(ScreenArea area, ACEMegaHostTFTClass * Display, unsigned int Color)
{
	Display->fillRect(area.x, area.y, area.w, area.h, Color);
}

void DynamicScreenView::WriteValue(byte value, FieldValueRenderMode renderMode, byte options, ScreenColors colors, ScreenArea area, ACEMegaHostTFTClass * Display)
{

	String text = "";
	if (renderMode == FieldValueRenderMode::numeric_percentage) {

		float p = MathTool::GetRatio(value, 255, 0, 1);
		p = p * 100;
		text = String(p, 2) + "%";
		WRITE_TEXT
	} else if (renderMode == FieldValueRenderMode::numeric_ratio) {

		
		text = String(MathTool::GetRatio(value, 255, 0, 1), 4);
		WRITE_TEXT

	} else if (renderMode == FieldValueRenderMode::numeric_value) {

		text = String(value);
		WRITE_TEXT
	}
	else if (renderMode == FieldValueRenderMode::graphic_bitBoxArrayHigh4) {
	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value >> 4, 3, Display, colors.Forecolor, colors.Backcolor);
	}
	else if (renderMode == FieldValueRenderMode::graphic_bitBoxArrayLow4) {
	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value, 3, Display, colors.Forecolor, colors.Backcolor);
	}
	else if (renderMode == FieldValueRenderMode::graphic_bitBoxArray) {
	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value, 7, Display, colors.Forecolor, colors.Backcolor);
	}
	else {
	float vr = MathTool::GetRatio(value, 255, 0, 1);
	GuiDrawingTools::drawValue(margin_x, margin_y, area.y, area.x, area.w, area.h, vr, renderMode, Display, colors.Forecolor, colors.Backcolor);
	}
	
}

//#define WRITEVALUE															\
//switch (renderMode) {															\
//case FieldValueRenderMode::numeric_percentage:															\
//	float p = MathTool::GetRatio(value, 255, 0, 1);															\
//	p = p * 100;															\
//	text = String(p, 2) + "%";															\
//	WRITE_TEXT															\
//		break;															\
//case FieldValueRenderMode::numeric_ratio:															\
//	float r = MathTool::GetRatio(value, 255, 0, 1);															\
//	text = String(r, 4);															\
//	WRITE_TEXT															\
//		break;															\
//case FieldValueRenderMode::numeric_value:															\
//	text = "" + value;															\
//	WRITE_TEXT															\
//		break;															\
//case FieldValueRenderMode::graphic_bitBoxArrayHigh4:															\
//	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value >> 4, 4, Display, colors.Forecolor, colors.Backcolor);															\
//	break;															\
//case FieldValueRenderMode::graphic_bitBoxArrayLow4:															\
//	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value, 4, Display, colors.Forecolor, colors.Backcolor);															\
//	break;															\
//case FieldValueRenderMode::graphic_bitBoxArray:															\
//	GuiDrawingTools::drawBitBoxes(margin_x, margin_y, area.y, area.x, area.w, area.h, value, 8, Display, colors.Forecolor, colors.Backcolor);															\
//	break;															\
//default:															\
//	float vr = MathTool::GetRatio(value, 255, 0, 1);															\
//	GuiDrawingTools::drawValue(margin_x, margin_y, area.y, area.x, area.w, area.h, vr, renderMode, Display, colors.Forecolor, colors.Backcolor);															\
//	break;															\
//}															\




//
//inline void DynamicScreenView::WriteText(String text, LCDElementAligment aligment, ScreenArea area, ACEMegaHostTFTClass * Display, unsigned int Color)
//{
//	switch (aligment) {
//		default:
//		case LCDElementAligment::left:
//			Display->setCursor(area.x + margin_x, area.y + margin_y);
//			break;
//		case LCDElementAligment::middle:
//			unsigned int tw1 = area.w - (char_w * text.length());
//			Display->setCursor(area.x + margin_x + (tw1 / 2), area.y + margin_y);
//			break;
//		case LCDElementAligment::right:
//			unsigned int tw2 = area.w - (char_w * text.length());
//			Display->setCursor(area.x + margin_x + tw2, area.y + margin_y);
//			break;
//	}
//
//	Display->setTextColor(Color);
//	Display->println(text);
//}

void DynamicScreenView::Reset()
{
	yC = 0;
}

void DynamicScreenView::AddHeader(String text, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight)
{
	if (bitRead(state, 0) == 1) {
		ScreenArea area = GetArea(1, 0, RowHeight, Screen);

		ScreenColors colors = GetColors(state, options, Screen, false);

		FillArea(area, Display, colors.Backcolor);

		WRITE_TEXT

		//WriteText(text, LCDElement::GetAligment(options), area, Display, colors.Forecolor);
	}
	yC += RowHeight;
	xC = 0;

}

void DynamicScreenView::PrintLabel(String text, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight, byte cX, byte cW)
{
	unsigned int y = Screen->GetYPosition(yC);
	unsigned int h = Screen->GetYPosition(RowHeight);
	unsigned int chw = Screen->GetWidth(1);

	unsigned int x = cX * chw;
	unsigned int w = cW * chw;

	GuiScreenPallete pallete = Screen->PalleteA;
	if ((options & B00000010) == B00000010) {
		pallete = Screen->PalleteB;
	}

	unsigned int Forecolor = pallete.LabelColor;
	unsigned int Backcolor = pallete.LabelBackColor;



	//if (elementType != ELEMENTTYPE_LABEL) {
	//	Forecolor = pallete.FieldColor;
	//	Backcolor = pallete.FieldBackColor;
	//}

	if ((options & B00000100) == B00000100) {
		Forecolor = pallete.CriticalColor;
	}


	bool inverseColors = ((options & B00000001) == B00000001);
	if ((options & B00001000) == B00001000) {
		if ((state & B00000100) == B00000100) inverseColors != inverseColors;
	}

	if (inverseColors) {
		unsigned int color = Backcolor;
		Backcolor = Forecolor;
		Forecolor = color;
	}

	Display->fillRect(x, y, w, h, Backcolor);

	switch (LCDElement::GetAligment(options)) {
	default:
	case LCDElementAligment::left:
		Display->setCursor(x, y);
		break;
	case LCDElementAligment::middle:
		unsigned int tw1 = chw * text.length();
		Display->setCursor(x + (tw1 / 2), y);
		break;
	case LCDElementAligment::right:
		unsigned int tw2 = chw * text.length();
		Display->setCursor(x + tw2, y);
		break;
	}

	Display->setTextColor(Forecolor);
	Display->println(text);


}

void DynamicScreenView::AddHalfWidthLabelAndByteValue(String text, byte value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight, bool SecondHalf)
{
	byte startColumn = 0;
	if (SecondHalf) startColumn = 2;

	ScreenArea area;
	
	

	ScreenColors colors;
	
	if (bitRead(state, 0) == 1) {
		area = GetArea(4, startColumn, RowHeight, Screen);
		colors = GetColors(state, options, Screen, false);

		FillArea(area, Display, colors.Backcolor);
		
		WRITE_TEXT

		//WriteText(label, LCDElement::GetAligment(options), area, Display, colors.Forecolor);
	}
	
	colors = GetColors(state, options, Screen, false);
	
	area = GetArea(4, startColumn+1, RowHeight, Screen);

	FillArea(area, Display, colors.Backcolor);

	if (renderMode == FieldValueRenderMode::numeric_value) {
		text = String(value);
		WRITE_TEXT
	}
	else {
		WriteValue(value, renderMode, options, colors, area, Display);
	}

	

	//

	//;

	
	if (SecondHalf) {
		yC++;
	}

}

void DynamicScreenView::AddHalfWidthLabelAndUIntValue(String text, unsigned int value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight, bool SecondHalf)
{
	byte startColumn = 0;
	if (SecondHalf) startColumn = 2;

	ScreenArea area;



	ScreenColors colors;

	if (bitRead(state, 0) == 1) {
		area = GetArea(4, startColumn, RowHeight, Screen);
		colors = GetColors(state, options, Screen, false);

		FillArea(area, Display, colors.Backcolor);

		WRITE_TEXT

			//WriteText(label, LCDElement::GetAligment(options), area, Display, colors.Forecolor);
	}

	colors = GetColors(state, options, Screen, false);

	area = GetArea(4, startColumn + 1, RowHeight, Screen);

	FillArea(area, Display, colors.Backcolor);
	text = String(value);
	WRITE_TEXT
	

	if (SecondHalf) {
		yC++;
	}

}

void DynamicScreenView::AddLabelAndUIntValue(String text, unsigned int value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight)
{
	ScreenArea area;

	ScreenColors colors;

	if (bitRead(state, 0) == 1) {
		area = GetArea(4, 0, RowHeight, Screen, 1);
		colors = GetColors(state, options, Screen, false);

		FillArea(area, Display, colors.Backcolor);
		WRITE_TEXT
			//WriteText(label, LCDElement::GetAligment(options), area, Display, colors.Forecolor);
	}

	colors = GetColors(state, options, Screen, true);

	area = GetArea(4, 1, RowHeight, Screen, 3);

	FillArea(area, Display, colors.Backcolor);

	text = String(value);
	WRITE_TEXT

	//WriteText(String(value), LCDElement::GetAligment(options), area, Display, colors.Forecolor);


	yC += RowHeight;
}


void DynamicScreenView::AddLabelAndByteValue(String text, byte value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight)
{
	

	ScreenArea area;

	ScreenColors colors;

	if (bitRead(state, 0) == 1) {
		area = GetArea(4, 0, RowHeight, Screen,1);
		colors = GetColors(state, options, Screen, false);

		FillArea(area, Display, colors.Backcolor);
		WRITE_TEXT
		//WriteText(label, LCDElement::GetAligment(options), area, Display, colors.Forecolor);
	}

	colors = GetColors(state, options, Screen, true);

	area = GetArea(4, 1, RowHeight, Screen,3);

	FillArea(area, Display, colors.Backcolor);

	WriteValue(value, renderMode, options, colors, area, Display);

	//WriteText(String(value), LCDElement::GetAligment(options), area, Display, colors.Forecolor);

	
	yC += RowHeight;
	
}


DynamicScreenView::DynamicScreenView()
{
}


DynamicScreenView::~DynamicScreenView()
{
}
