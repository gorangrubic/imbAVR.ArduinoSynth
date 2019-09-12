#include "GuiScreen.h"

#include "MathTool.h"



GuiScreen::GuiScreen()
{
	PalleteB.CriticalColor = GLCD_CL_CYAN;

	PalleteB.LabelColor = GLCD_CL_LIGHT_GRAY;
	PalleteB.LabelBackColor = GLCD_CL_PURPLE;

	PalleteB.FieldColor = GLCD_CL_WHITE;
	PalleteB.FieldBackColor = GLCD_CL_ORANGE;
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