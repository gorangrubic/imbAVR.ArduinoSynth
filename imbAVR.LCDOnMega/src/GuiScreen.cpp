#include "GuiScreen.h"





void GuiScreen::DeployField(LCDField * field, RowBase * row, boolean invert)
{
	field->y = GetYPosition(row->Row);
	if (invert) {
		field->TextColor = FieldBackColor;
		field->BackColor = FieldColor;
	}
	else {
		field->BackColor = FieldBackColor;
		field->TextColor = FieldColor;
	}
	
}

void GuiScreen::DeployLabel(LCDLabel * label, RowBase * row, boolean invert)
{
	label->y = GetYPosition(row->Row);
	if (invert) {
		label->TextColor = LabelBackColor;
		label->BackColor = LabelColor;
	}
	else {
		label->BackColor = LabelBackColor;
		label->TextColor = LabelColor;
	}

	
}

void GuiScreen::drawBitBoxes(unsigned int y, unsigned int x, unsigned int w, unsigned int h, byte bits, byte bitCount, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff)
{
	x = x + generalMarginX * 2;
	y = y + generalMarginY * 2;
	w = w - generalMarginX * 2;
	h = h - generalMarginY * 2;

	unsigned int dX = w / bitCount;
	unsigned int bW = dX - generalMarginX * 2;
	unsigned int bH = h - generalMarginX * 2;

	uint16_t Color = ColorOn;

	for (size_t i = 0; i < bitCount; i++)
	{
		if (bitRead(bits, i) == 0) {
			Color = ColorOff;
		}
		else {
			Color = ColorOn;
		}
		Display->fillRect(x + (i * dX), y, bW, bH, Color);
	}
	
}

void GuiScreen::drawValue(unsigned int y, unsigned int x, unsigned int w, unsigned int h, float r, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff)
{
	uint16_t Color = ColorOn;
	x = x + generalMarginX * 2;
	y = y + generalMarginY * 2;
	w = w - generalMarginX * 2;
	h = h - generalMarginY * 2;

	unsigned int d = min(w, h);

	switch (mode) {

	case FieldValueRenderMode::graphic_horizontal_biased_bar:

		r = r - 0.5;
		d = (w/2) * r; // (d * (1 - r)) / 2;

		Display->fillRect(x+(w/2), y, d, h, ColorOn);
		Display->fillRect(x + (w / 2), y+(h/3), -d, h/3, ColorOff);
		break;
	case FieldValueRenderMode::graphic_horizontal_bar:
		Display->fillRect(x, y, w*r, h, Color);

		break;
	case FieldValueRenderMode::graphic_vertical_bar:
		Display->fillRect(x, y+(h*r), w, h, Color);
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
		Display->fillRect(x+d, y+d, w-d, h-d, Color);

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

void GuiScreen::drawValue(unsigned int y, unsigned int x, unsigned int width, unsigned int height, int v, unsigned int total, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff)
{

	float r = MathTool::GetRatio(v, total, 1, 0);
	drawValue(y, x, width, height, r, mode, Display, ColorOn, ColorOff);

	
}

void GuiScreen::FillBackground(RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin, byte xMargin, byte rowHeight)
{
	int yStart = GetYPosition(row->Row) + yMargin;
	int h = GetCharScreenHeight() * rowHeight;

	Display->fillRect(xMargin, yStart, ScreenWidth - xMargin,h  - yMargin, Color);
}

void GuiScreen::FillBackground(uint16_t xStart, uint16_t xEnd, RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin, byte xMargin, byte rowHeight)
{
	int yStart = GetYPosition(row->Row) + yMargin;
	int h = GetCharScreenHeight() * rowHeight;

	Display->fillRect(xStart + xMargin, yStart, xEnd - xStart - xMargin, h - yMargin, Color);
}

int GuiScreen::GetWidth(byte characters)
{
	return (6 * TextSize) * characters;
}

int GuiScreen::GetHeight(byte characters)
{
	return (8 * TextSize) * characters;
}

int GuiScreen::GetCharScreenWidth()
{
	return ScreenWidth / GetWidth(1);
}

int GuiScreen::GetCharScreenHeight()
{
	return ScreenHeight / GetHeight(1);
}

int GuiScreen::GetYPosition(unsigned int row)
{
	return row * GetHeight(1);
}

int GuiScreen::GetXPosition(unsigned int character)
{
	return character * GetWidth(1);
}


