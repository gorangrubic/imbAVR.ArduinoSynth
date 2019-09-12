#include "LCDElement.h"


byte LCDElement::SetInverseBackAndForeground(byte options, bool value)
{
	if (value) {
		bitWrite(options, 0, 1);
	}
	else {
		bitWrite(options, 0, 0);
	}
	return options;
}

byte LCDElement::SetAlternativePallete(byte options, bool value)
{
	if (value) {
		bitWrite(options, 1, 1);
	}
	else {
		bitWrite(options, 1, 0);
	}
	return options;
}

byte LCDElement::SetBlinks(byte options, bool value)
{
	if (value) {
		bitWrite(options, 2, 1);
	}
	else {
		bitWrite(options, 2, 0);
	}
	return options;
}

byte LCDElement::SetAligment(byte options, LCDElementAligment value)
{
	switch (value) {
	case LCDElementAligment::left:
		bitWrite(options, 4, 0);
		bitWrite(options, 5, 0);
		break;
	case LCDElementAligment::middle:
		bitWrite(options, 4, 0);
		bitWrite(options, 5, 1);
		break;
	case LCDElementAligment::right:
		bitWrite(options, 4, 1);
		bitWrite(options, 5, 1);
		break;
	}
	return options;
}

byte LCDElement::SetWidth(byte options, LCDElementWidth value)
{
	switch (value)
	{
	case normal:
		bitWrite(options, 6, 0);
		bitWrite(options, 7, 0);
		break;
	case timesTwo:
		bitWrite(options, 6, 1);
		bitWrite(options, 7, 0);
		break;
	case timesFour:
		bitWrite(options, 6, 1);
		bitWrite(options, 7, 0);
		break;
	case timesEight:
		bitWrite(options, 6, 1);
		bitWrite(options, 7, 1);
		break;
	default:
		break;
	}
	return options;
}

bool LCDElement::IsInverse()
{
	return ((options & B00000001) == B00000001);
}

bool LCDElement::IsAltPallete()
{
	return ((options & B00000010) == B00000010);
}

bool LCDElement::IsBlinking()
{
	return ((options & B00000100) == B00000100);
}



LCDElementAligment LCDElement::GetAligment(byte options)
{
	if ((options & B00110000) == B00000000) {
		return LCDElementAligment::right;
	}
	if ((options & B00110000) == B00100000) {
		return LCDElementAligment::middle;
	}
	if ((options & B00110000) == B00110000) {
		return LCDElementAligment::left;
	}
	return LCDElementAligment::right;
}

byte LCDElement::GetWidthFactor(byte options)
{
	byte widthByte = options & B11000000;
	switch (widthByte) {
	case B00000000:
		return 1;
		break;
	case B01000000:
		return 2;
		break;
	case B10000000:
		return 4;
		break;
	case B11000000:
		return 8;
		break;
	}

	return 1;
}

LCDElement::LCDElement()
{
}

LCDElement::~LCDElement()
{
}

void LCDElement::Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)
{
	Display->println("LCDElement Render");
}

//void LCDElement::Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)
//{
//}


//void LCDElement::Render(ACEMegaHostTFTClass * Display, unsigned int Forecolor, unsigned int Backcolor, unsigned int x, unsigned int y, unsigned int w, unsigned int h, byte state)
//{
//	unsigned int x;
//	unsigned int w
//}


