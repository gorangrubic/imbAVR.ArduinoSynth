// ACEMegaHostTFT.h

#ifndef _ACEMEGAHOSTTFT_h
#define _ACEMEGAHOSTTFT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_GFX.h>
//typedef uint32_t Pio;

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>

#include "avr/pgmspace.h"


#include "pins_arduino.h"
#include "wiring_private.h"

class ACEMegaHostTFTClass : public Adafruit_GFX
{

public:


	// when true - it will force all LCD fields to reprint values
	bool redrawScheduled = true;

	unsigned int textsize = 1;

	ACEMegaHostTFTClass(void);

	int16_t	leftTab = 0;
	void setLeftTab(uint16_t _leftTab);

	void	drawCustomFont(int16_t x, int16_t y, unsigned char c,
		uint16_t color, uint16_t bg, uint8_t size);

	// SWTFT(void);

	void     begin(uint16_t id = 0x9325);
	void     drawPixel(int16_t x, int16_t y, uint16_t color);
	/////////////////////////////////////////
	void     writeA16B3(uint16_t address, uint8_t ub, uint8_t mb, uint8_t lb);
	void     drawPixel3(int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b);
	void     drawLine3Byte(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t r, uint8_t g, uint8_t b);
	//////////////////////////////////////////
	void     drawFastHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);
	void     drawFastVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);
	void     fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c);
	void     fillScreen(uint16_t color);
	void     reset(void);
	void     setRegisters8(uint8_t *ptr, uint8_t n);
	void     setRegisters16(uint16_t *ptr, uint8_t n);
	void     setRotation(uint8_t x);
	// These methods are public in order for BMP examples to work:
	void     setAddrWindow(int x1, int y1, int x2, int y2);
	void     pushColors(uint16_t *data, uint8_t len, boolean first);

	uint16_t color565(uint8_t r, uint8_t g, uint8_t b),
		readPixel(int16_t x, int16_t y),
		readID(void);

#define swap(a, b) { int16_t t = a; a = b; b = t; }

	//size_t	write(uint8_t c);

private:

	void  init(),
		// These items may have previously been defined as macros
		// If not, function versions are declared:
#ifndef write8
		write8(uint8_t value),
#endif
#ifndef setWriteDir
		setWriteDir(void),
#endif
#ifndef setReadDir
		setReadDir(void),
#endif
#ifndef writeRegister8
		writeRegister8(uint8_t a, uint8_t d),
#endif
#ifndef writeRegister16
		writeRegister16(uint16_t a, uint16_t d),
#endif
#ifndef writeRegisterPair
		writeRegisterPair(uint8_t aH, uint8_t aL, uint16_t d),
#endif
		setLR(void),
		flood(uint16_t color, uint32_t len);
	uint8_t  driver;

#ifndef read8
	uint8_t  read8fn(void);
#define  read8isFunctionalized
#endif

#ifndef USE_ADAFRUIT_SHIELD_PINOUT

#ifdef __AVR__
	volatile uint8_t *csPort, *cdPort, *wrPort, *rdPort;
	uint8_t           csPinSet, cdPinSet, wrPinSet, rdPinSet,
		csPinUnset, cdPinUnset, wrPinUnset, rdPinUnset,
		_reset;
#endif
#if defined(__SAM3X8E__)
	RwReg *csPort, *cdPort, *wrPort, *rdPort;
	//Pio *csPort, *cdPort, *wrPort, *rdPort;
	uint32_t          csPinSet, cdPinSet, wrPinSet, rdPinSet,
		csPinUnset, cdPinUnset, wrPinUnset, rdPinUnset,
		_reset;
#endif

#endif

};

// For compatibility with sketches written for older versions of library.
// Color function name was changed to 'color565' for parity with 2.2" LCD
// library.
#define Color565 color565


#endif


// Color definitions for 64k color mode
// Bits 0..4 -> Blue 0..4
// Bits 5..10 -> Green 0..5
// Bits 11..15 -> Red 0..4
#define GLCD_CL_BLACK 0x0000
#define GLCD_CL_WHITE 0xFFFF
#define GLCD_CL_GRAY 0x7BEF
#define GLCD_CL_LIGHT_GRAY 0xC618
#define GLCD_CL_GREEN 0x07E0
#define GLCD_CL_LIME 0x87E0
#define GLCD_CL_BLUE 0x001F
#define GLCD_CL_RED 0xF800
#define GLCD_CL_AQUA 0x5D1C
#define GLCD_CL_YELLOW 0xFFE0
#define GLCD_CL_MAGENTA 0xF81F
#define GLCD_CL_CYAN 0x07FF
#define GLCD_CL_DARK_CYAN 0x03EF
#define GLCD_CL_ORANGE 0xFCA0
#define GLCD_CL_PINK 0xF97F
#define GLCD_CL_BROWN 0x8200
#define GLCD_CL_VIOLET 0x9199
#define GLCD_CL_SILVER 0xA510
#define GLCD_CL_GOLD 0xA508
#define GLCD_CL_NAVY 0x000F
#define GLCD_CL_MAROON 0x7800
#define GLCD_CL_PURPLE 0x780F
#define GLCD_CL_OLIVE 0x7BE0