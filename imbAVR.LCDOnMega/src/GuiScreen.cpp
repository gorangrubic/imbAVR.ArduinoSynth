#include "GuiScreen.h"





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


