#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif


#include "ACEMegaHostTFT.h"


enum LCDElementAligment {
	right,
	middle,
	left
};

enum LCDElementWidth {
	normal,
	timesTwo,
	timesFour,
	timesEight
};


#define ELEMENTTYPE_LABEL 1
#define ELEMENTTYPE_BYTEFIELD 2
#define ELEMENTTYPE_INTFIELD 3
#define ELEMENTTYPE_FLOATFIELD 4
#define ELEMENTTYPE_STRINGFIELD 5

class LCDElement
{
public:

	// xxxx xxxx

	// xxxx xxx1  - inverse back and text
	// xxxx xx1x  - use alternative pallete
	// xxxx x1xx  - use critical color for value
	// xxxx 1xxx  - blinks
	// xx00 xxxx  - right aligment
	// xx10 xxxx  - middle aligment
	// xx11 xxxx  - left aligment
	// 01xx xxxx  - 2 x width
	// 10xx xxxx  - 4 x width
	// 11xx xxxx  - 8 x width

	byte options = B00000000;

	// 0000 0001 - LCDLabel
	// 0000 0010 - LCDField<Byte>
	// 0000 0011 - LCDField<Int16>
	// 0000 0100 - LCDField<Float>
	// 0000 0101 - LCDField<String>
	byte elementType=0;

	static byte SetInverseBackAndForeground(byte options, bool value = true);
	static byte SetAlternativePallete(byte options, bool value=true);
	static byte SetBlinks(byte options, bool value = true);
	static byte SetAligment(byte options, LCDElementAligment value = LCDElementAligment::middle);
	static byte SetWidth(byte options, LCDElementWidth value = LCDElementWidth::timesTwo);

	bool IsInverse();
	bool IsAltPallete();
	bool IsBlinking();
	static LCDElementAligment GetAligment(byte options);
	static byte GetWidthFactor(byte options);

	/* horizontal position in the row, expressed in character widths, assigned during row deployment*/
	byte Cx = 0;
	/* width computed during row deployement */
	byte Cw = 1;

	LCDElement();
	virtual ~LCDElement();

	virtual void Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)=0;

};

