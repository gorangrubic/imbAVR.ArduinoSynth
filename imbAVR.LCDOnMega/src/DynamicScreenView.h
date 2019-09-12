#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "LCDElement.h"
#include "GuiScreen.h"
#include "FieldValueRenderMode.h"


struct ScreenArea {
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
};

struct ScreenColors {
	unsigned int Forecolor;
	unsigned int Backcolor;
};

class DynamicScreenView
{
	

public:

	byte cScreenWidth;
	byte cScreenHeight;

	byte char_w;
	byte char_h;

	byte margin_x;
	byte margin_y;

	void Deploy(GuiScreen * Screen);

	ScreenColors GetColors(byte state, byte options, GuiScreen * Screen, bool isField);

	ScreenArea GetArea(byte Columns, byte Column, byte RowHeight,GuiScreen * Screen, byte ColumnWidth = 1);

	void FillArea(ScreenArea area, ACEMegaHostTFTClass * Display, unsigned int Color);

	void WriteValue(byte value, FieldValueRenderMode renderMode, byte options, ScreenColors colors, ScreenArea area, ACEMegaHostTFTClass * Display);

	//void WriteText(String text, LCDElementAligment aligment, ScreenArea area, ACEMegaHostTFTClass * Display, unsigned int Color);

	byte yC = 0;
	byte xC = 0;

	void Reset();

	void AddHeader(String text, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight = 1);

	void PrintLabel(String text, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight, byte cX, byte cW);

	void AddHalfWidthLabelAndByteValue(String label, byte value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight = 1, bool SecondHalf=false);

	void AddHalfWidthLabelAndUIntValue(String text, unsigned int value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight, bool SecondHalf);

	void AddLabelAndUIntValue(String text, unsigned int value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight);

	void AddLabelAndByteValue(String label, byte value, FieldValueRenderMode renderMode, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte options, byte RowHeight);

	DynamicScreenView();
	~DynamicScreenView();
};

