// 
// 
// 

#include "avrDisplay.h"

void AvrDisplayClass::init()
{


}


AvrDisplayClass AvrDisplay;

// Connect data pins LCD_D 0-7 to arduino UNO:
// LCD_D 0 -- D8
// LCD_D 1 -- D9
// LCD_D 2 -- D2
// LCD_D 3 -- D3
// LCD_D 4 -- D4
// LCD_D 5 -- D5
// LCD_D 6 -- D6
// LCD_D 7 -- D7
// Connect command pins:
// LCD_RST -- A4   1 -> 0 min 15 micros 0 -> 1 
// LCD_CS  -- A3   chip select, aktiv LOW
// LCD_RS  -- A2   data/command select, 0 command, 1 data
// LCD_WR  -- A1   0 -> 1, HIGH when not used
// LCD_RD  -- A0   0 -> 1, HIGH when not used

// arduino uno porty:
// B (digital pin 8 to 13) 
// C (analog input pins) 
// D (digital pins 0 to 7)   0 1 are RX TX, don't use 

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Touchscreen connection:
#define Y1 A3  // need two analog inputs
#define X1 A2  // 
#define Y2 9   // 
#define X2 8   //

int16_t P_COL = 0; // LCD cursor pointer
int16_t P_ROW = 0;
int16_t T_COL = 0; // TOUCHSCREEN(TS) detected value
int16_t T_ROW = 0;

// TS calibration
uint16_t ROW_F = 110; // TS first row
uint16_t ROW_L = 920; // TS last row
uint16_t COL_F = 110; // TS first column
uint16_t COL_L = 930; // TS last column

uint8_t F_SIZE = 3; // font size
uint16_t F_COLOR = WHITE; // foreground color
uint16_t B_COLOR = 0x0C0C; // background color

// draw keypad
String K_LABEL[] = { "1","2","3","4","5","6","7","8","9","0","<" };
uint16_t K_ROW[] = { 150,150,150,100,100,100,50,50,50,200,200 };
uint16_t K_COL[] = { 10,50,90,10,50,90,10,50,90,50,90 };

void LCD_write(uint8_t d) {
	// ILI9341 reads data pins when WR rises from LOW to HIGH (A1 pin on arduino)
	PORTC = PORTC & B11111101; // WR 0

	// data pins of ILI9341 connected to two arduino ports
	PORTD = (PORTD & B00000011) | ((d)& B11111100);
	PORTB = (PORTB & B11111100) | ((d)& B00000011);

	PORTC = PORTC | B00000010; // WR 1
}

void LCD_command_write(uint8_t d) {
	PORTC = PORTC & B11111011; // LCD_RS = 0, arduino pin A2
	// write data pins
	LCD_write(d);
}

void LCD_data_write(uint8_t d) {
	PORTC = PORTC | B00000100; // LCD_RS = 1, arduino pin A2
	// write data pins
	LCD_write(d);
}

uint8_t LCD_read(void) {
	// CS LOW, WR HIGH, RD HIGH->LOW>HIGH, RS(D/C) HIGH 
	PORTC = PORTC | B00000100; // RS 1

	// LCD_RD - arduino pin A0
	// After RD falls from HIGH to LOW ILI9341 outputs data until RD returns to HIGH
	PORTC = PORTC & B11111110; // RD 0
	BD_as_input(); // Set arduino pins as input
	uint8_t pin72 = PIND & B11111100; // Read data pins 7-2
	uint8_t pin10 = PINB & B00000011; // Read data pins 1-0
	PORTC = PORTC | B00000001; // RD 1
	BD_as_output(); // Re-Set arduino pins as output
	return pin72 | pin10;
}

void BD_as_input() {
	// Pins 7-2 as input, no change for pins 1,0 (RX TX)
	DDRD = DDRD & B00000011;
	// Pins 8-9 as input
	DDRB = DDRB & B11111100;
}

void BD_as_output() {
	// Pins 7-2 as output, no change for pins 1,0 (RX TX)
	DDRD = DDRD | B11111100;
	// Pins 8-9 as output
	DDRB = DDRB | B00000011;
}

void LCD_init(void) {
	// LCD_RESET 1 - 0 - 1, arduino pin A4
	PORTC = PORTC | B00010000; // 1
	delay(10);
	PORTC = PORTC & B11101111; // 0
	delay(20);
	PORTC = PORTC | B00010000; // 1
	delay(20);

	// CS HIGH, WR HIGH, RD HIGH, CS LOW
	PORTC = PORTC | B00001000; // CS 1
	PORTC = PORTC | B00000010; // WR 1
	PORTC = PORTC | B00000001; // RD 1
	PORTC = PORTC & B11110111; // CS 0

	LCD_command_write(0xF7); // Pump ratio control
	LCD_data_write(0x20); // 

	LCD_command_write(0x3A); // COLMOD: Pixel Format Set
	LCD_data_write(0x55);

	LCD_command_write(0x36); // Memory Access Control 
	// MY  - Row Address Order (bit7)
	// MX  - Column Address Order
	// MV  - Row / Column Exchange
	// ML  - Vertical Refresh Order
	// BGR - RGB-BGR Order
	// MH  - Horizontal Refresh ORDER(bit2)
	LCD_data_write(B00001000);

	LCD_command_write(0x11); // Sleep OUT
	LCD_command_write(0x29); // Display ON

	delay(50);
}

void LCD_rect(int16_t col, int16_t row, int16_t width, int16_t height, int16_t color) {

	LCD_command_write(0x2a); // Column Address Set
	LCD_data_write(row >> 8);
	LCD_data_write(row);
	LCD_data_write((row + height - 1) >> 8);
	LCD_data_write(row + height - 1);
	LCD_command_write(0x2b); // Page Address Set
	LCD_data_write(col >> 8);
	LCD_data_write(col);
	LCD_data_write((col + width - 1) >> 8);
	LCD_data_write(col + width - 1);
	LCD_command_write(0x2c); // Memory Write

	byte chigh = color >> 8;
	byte clow = color;
	int i, j;
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
		{
			LCD_data_write(chigh);
			LCD_data_write(clow);
		}
}

void LCD_clear(byte color) {
	/*
	Accelerate screen clearing sacrifing color depth. Instead of writing
	to data bits high and low byte of the color for each pixel, which takes more
	than 300ms to fill the screen, set once data bits to 0's for black or
	to 1's for white and start changing control bit WR from LOW to HIGH to
	write whole area. It takes cca 70 ms. In this way the color of screen are
	limited to those with the same high and low byte. For example setting color
	to 0x0C fills the screen with color 0x0C0C.
	Writing two pixels in one cycle lowering cycle count from 76800 (240x320) to
	38400 clears screen in less then 30ms.
	*/

	LCD_command_write(0x2a);
	LCD_data_write(0);
	LCD_data_write(0);
	LCD_data_write(0);
	LCD_data_write(0xEC);
	LCD_command_write(0x2b);
	LCD_data_write(0);
	LCD_data_write(0);
	LCD_data_write(1);
	LCD_data_write(0x3F);
	LCD_command_write(0x2c);

	PORTC = PORTC | B00000100; // LCD_RS = 1 - DATA

	PORTD = (PORTD & B00000011) | ((color)& B11111100);
	PORTB = (PORTB & B11111100) | ((color)& B00000011);

	uint16_t x;
	x = 38400; // 240*320/2
	byte wr0 = PORTC & B11111101; // set WR 0
	byte wr1 = PORTC | B00000010; // set WR 1
	for (uint16_t y = 0; y < x; y++)
	{
		PORTC = wr0;
		PORTC = wr1;
		PORTC = wr0;
		PORTC = wr1;

		PORTC = wr0;
		PORTC = wr1;
		PORTC = wr0;
		PORTC = wr1;
	}
}

void Display_integer(int16_t n) {
	String str = String(n);
	byte l = str.length();
	for (size_t i = 0; i < l; i++)
	{
		Display_char(str.charAt(i));
	}
}

void Display_string(String str) {
	byte l = str.length();
	for (size_t i = 0; i < l; i++)
	{
		Display_char(str.charAt(i));
	}
}

void Display_char(char znak) {
	static const byte ASCII[][5] =
	{
	  {0x00, 0x00, 0x00, 0x00, 0x00}, // 20
	  {0x00, 0x00, 0x5f, 0x00, 0x00}, // 21 !	
	  {0x00, 0x07, 0x00, 0x07, 0x00}, // 22 "
	  {0x14, 0x7f, 0x14, 0x7f, 0x14}, // 23 # 
	  {0x24, 0x2a, 0x7f, 0x2a, 0x12} ,// 24 $
	  {0x23, 0x13, 0x08, 0x64, 0x62}, // 25 %
	  {0x36, 0x49, 0x55, 0x22, 0x50}, // 26 &
	  {0x00, 0x00, 0x07, 0x05, 0x07}, // 27 ' 
	  {0x00, 0x1c, 0x22, 0x41, 0x00}, // 28 (
	  {0x00, 0x41, 0x22, 0x1c, 0x00}, // 29 )
	  {0x14, 0x08, 0x3e, 0x08, 0x14}, // 2a *
	  {0x08, 0x08, 0x3e, 0x08, 0x08}, // 2b +
	  {0x00, 0x50, 0x30, 0x00, 0x00}, // 2c ,
	  {0x08, 0x08, 0x08, 0x08, 0x08}, // 2d -
	  {0x00, 0x60, 0x60, 0x00, 0x00}, // 2e .
	  {0x20, 0x10, 0x08, 0x04, 0x02}, // 2f /
	  {0x3e, 0x51, 0x49, 0x45, 0x3e}, // 30 0
	  {0x00, 0x42, 0x7f, 0x40, 0x00}, // 31 1
	  {0x42, 0x61, 0x51, 0x49, 0x46}, // 32 2
	  {0x21, 0x41, 0x45, 0x4b, 0x31}, // 33 3
	  {0x18, 0x14, 0x12, 0x7f, 0x10}, // 34 4
	  {0x27, 0x45, 0x45, 0x45, 0x39}, // 35 5
	  {0x3c, 0x4a, 0x49, 0x49, 0x30}, // 36 6
	  {0x01, 0x71, 0x09, 0x05, 0x03}, // 37 7
	  {0x36, 0x49, 0x49, 0x49, 0x36}, // 38 8
	  {0x06, 0x49, 0x49, 0x29, 0x1e}, // 39 9
	  {0x00, 0x36, 0x36, 0x00, 0x00}, // 3a :
	  {0x00, 0x56, 0x36, 0x00, 0x00}, // 3b ;
	  {0x08, 0x14, 0x22, 0x41, 0x00}, // 3c <
	  {0x14, 0x14, 0x14, 0x14, 0x14}, // 3d =
	  {0x00, 0x41, 0x22, 0x14, 0x08}, // 3e >
	  {0x02, 0x01, 0x51, 0x09, 0x06}, // 3f ?
	  {0x32, 0x49, 0x79, 0x41, 0x3e}, // 40 @
	  {0x7e, 0x11, 0x11, 0x11, 0x7e}, // 41 A
	  {0x7f, 0x49, 0x49, 0x49, 0x36}, // 42 B
	  {0x3e, 0x41, 0x41, 0x41, 0x22}, // 43 C
	  {0x7f, 0x41, 0x41, 0x22, 0x1c}, // 44 D
	  {0x7f, 0x49, 0x49, 0x49, 0x41}, // 45 E
	  {0x7f, 0x09, 0x09, 0x09, 0x01}, // 46 F
	  {0x3e, 0x41, 0x49, 0x49, 0x7a}, // 47 G
	  {0x7f, 0x08, 0x08, 0x08, 0x7f}, // 48 H
	  {0x00, 0x41, 0x7f, 0x41, 0x00}, // 49 I
	  {0x20, 0x40, 0x41, 0x3f, 0x01}, // 4a J
	  {0x7f, 0x08, 0x14, 0x22, 0x41}, // 4b K
	  {0x7f, 0x40, 0x40, 0x40, 0x40}, // 4c L
	  {0x7f, 0x02, 0x0c, 0x02, 0x7f}, // 4d M
	  {0x7f, 0x04, 0x08, 0x10, 0x7f}, // 4e N
	  {0x3e, 0x41, 0x41, 0x41, 0x3e}, // 4f O
	  {0x7f, 0x09, 0x09, 0x09, 0x06}, // 50 P
	  {0x3e, 0x41, 0x51, 0x21, 0x5e}, // 51 Q
	  {0x7f, 0x09, 0x19, 0x29, 0x46}, // 52 R
	  {0x46, 0x49, 0x49, 0x49, 0x31}, // 53 S
	  {0x01, 0x01, 0x7f, 0x01, 0x01}, // 54 T
	  {0x3f, 0x40, 0x40, 0x40, 0x3f}, // 55 U
	  {0x1f, 0x20, 0x40, 0x20, 0x1f}, // 56 V
	  {0x3f, 0x40, 0x38, 0x40, 0x3f}, // 57 W
	  {0x63, 0x14, 0x08, 0x14, 0x63}, // 58 X
	  {0x07, 0x08, 0x70, 0x08, 0x07}, // 59 Y
	  {0x61, 0x51, 0x49, 0x45, 0x43}, // 5a Z
	  {0x00, 0x7f, 0x41, 0x41, 0x00}, // 5b [
	  {0x02, 0x04, 0x08, 0x10, 0x20}, // 5c Y
	  {0x00, 0x41, 0x41, 0x7f, 0x00}, // 5d ]
	  {0x04, 0x02, 0x01, 0x02, 0x04}, // 5e ^
	  {0x40, 0x40, 0x40, 0x40, 0x40}, // 5f _
	  {0x00, 0x01, 0x02, 0x04, 0x00}, // 60 `
	  {0x20, 0x54, 0x54, 0x54, 0x78}, // 61 a
	  {0x7f, 0x48, 0x44, 0x44, 0x38}, // 62 b
	  {0x38, 0x44, 0x44, 0x44, 0x20}, // 63 c
	  {0x38, 0x44, 0x44, 0x48, 0x7f}, // 64 d
	  {0x38, 0x54, 0x54, 0x54, 0x18}, // 65 e
	  {0x08, 0x7e, 0x09, 0x01, 0x02}, // 66 f
	  {0x0c, 0x52, 0x52, 0x52, 0x3e}, // 67 g
	  {0x7f, 0x08, 0x04, 0x04, 0x78}, // 68 h
	  {0x00, 0x44, 0x7d, 0x40, 0x00}, // 69 i
	  {0x20, 0x40, 0x44, 0x3d, 0x00}, // 6a j
	  {0x7f, 0x10, 0x28, 0x44, 0x00}, // 6b k
	  {0x00, 0x41, 0x7f, 0x40, 0x00}, // 6c l
	  {0x7c, 0x04, 0x18, 0x04, 0x78}, // 6d m
	  {0x7c, 0x08, 0x04, 0x04, 0x78}, // 6e n
	  {0x38, 0x44, 0x44, 0x44, 0x38}, // 6f o
	  {0x7c, 0x14, 0x14, 0x14, 0x08}, // 70 p
	  {0x08, 0x14, 0x14, 0x18, 0x7c}, // 71 q
	  {0x7c, 0x08, 0x04, 0x04, 0x08}, // 72 r
	  {0x48, 0x54, 0x54, 0x54, 0x20}, // 73 s
	  {0x04, 0x3f, 0x44, 0x40, 0x20}, // 74 t
	  {0x3c, 0x40, 0x40, 0x20, 0x7c}, // 75 u
	  {0x1c, 0x20, 0x40, 0x20, 0x1c}, // 76 v
	  {0x3c, 0x40, 0x30, 0x40, 0x3c}, // 77 w
	  {0x44, 0x28, 0x10, 0x28, 0x44}, // 78 x
	  {0x0c, 0x50, 0x50, 0x50, 0x3c}, // 79 y
	  {0x44, 0x64, 0x54, 0x4c, 0x44}, // 7a z
	  {0x00, 0x08, 0x36, 0x41, 0x00}, // 7b {
	  {0x00, 0x00, 0x7f, 0x00, 0x00}, // 7c |
	  {0x00, 0x41, 0x36, 0x08, 0x00}, // 7d }
	  {0x10, 0x08, 0x08, 0x10, 0x08}, // 7e 
	  {0x00, 0x06, 0x09, 0x09, 0x06}  // 7f 
	};

	int8_t size = F_SIZE;
	int16_t color = F_COLOR;
	int16_t bcolor = B_COLOR;

	if ((P_COL + (size * 6)) > 319) {
		P_COL = 0;
		P_ROW += size * (8 + 1);
	}

	LCD_command_write(0x2a); // ROWS
	LCD_data_write(P_ROW >> 8);
	LCD_data_write(P_ROW);
	LCD_data_write(((P_ROW + size * 8) - 1) >> 8);
	LCD_data_write((P_ROW + size * 8) - 1);
	LCD_command_write(0x2b); // COLUMNS
	LCD_data_write(P_COL >> 8);
	LCD_data_write(P_COL);
	LCD_data_write((P_COL + (size * 6)) >> 8);
	LCD_data_write(P_COL + (size * 6));
	LCD_command_write(0x2c);
	byte bchigh = bcolor >> 8;
	byte bclow = bcolor;
	byte fchigh = color >> 8;
	byte fclow = color;
	byte index, nbit, i, j;
	for (index = 0; index < 5; index++) {
		char col = ASCII[znak - 0x20][index];
		for (i = 0; i < size; i++) {
			byte mask = B00000001;
			for (nbit = 0; nbit < 8; nbit++) {
				if (col & mask) {
					for (j = 0; j < size; j++) {
						LCD_data_write(fchigh);
						LCD_data_write(fclow);
					}
				}
				else {
					for (j = 0; j < size; j++) {
						LCD_data_write(bchigh);
						LCD_data_write(bclow);
					}
				}
				mask = mask << 1;
			}
		}
	}
	/*for ( i=0; i<size; i++){
	  for (nbit = 0; nbit < 8; nbit++) {
		for (j=0; j<size; j++){
		  LCD_data_write(bchigh);
		  LCD_data_write(bclow);
		}
	  }
	}*/
	P_COL += size * 6;
}

void Display_clear_char(byte n) {
	// delete n chars
	int8_t size = F_SIZE;
	int16_t bcolor = B_COLOR;

	LCD_command_write(0x2a); // ROWS
	LCD_data_write(P_ROW >> 8);
	LCD_data_write(P_ROW);
	LCD_data_write(((P_ROW + size * 8) - 1) >> 8);
	LCD_data_write((P_ROW + size * 8) - 1);
	LCD_command_write(0x2b); // COLUMNS
	LCD_data_write(P_COL >> 8);
	LCD_data_write(P_COL);
	LCD_data_write((P_COL + (size * 6 * n)) >> 8);
	LCD_data_write(P_COL + (size * 6 * n));
	LCD_command_write(0x2c);

	byte bchigh = bcolor >> 8;
	byte bclow = bcolor;
	int16_t cyc = size * 8 * size * 6 * n;
	for (int16_t i = 0; i < cyc; i++) {
		LCD_data_write(bchigh);
		LCD_data_write(bclow);
	}
}

byte ReadTouch(void) {
	//Y1 A3  
	//X1 A2   
	//Y2 9   
	//X2 8   
	int16_t row, col;
	int8_t touch, wait_touch, valid;
	wait_touch = 1;
	valid = 0;
	while (wait_touch) {
		pinMode(Y1, INPUT);
		pinMode(Y2, INPUT_PULLUP);

		pinMode(X1, OUTPUT);
		pinMode(X2, OUTPUT);
		digitalWrite(X1, LOW);
		digitalWrite(X2, LOW);

		touch = !digitalRead(Y1); // 0 - touched
		if (touch) {
			//delay(5);
			digitalWrite(X1, HIGH);   // X variant A
			//digitalWrite(X2, HIGH);   // X variant B
			delay(1);
			row = analogRead(Y1);
			delay(4);
			if (abs(analogRead(Y1) - row) > 3) { return 0; }
			delay(3);
			if (abs(analogRead(Y1) - row) > 3) { return 0; }
			//if (analogRead(Y1)!=row) { return 0;}

			pinMode(X1, INPUT);
			pinMode(X2, INPUT_PULLUP);

			pinMode(Y1, OUTPUT);
			pinMode(Y2, OUTPUT);
			//digitalWrite(Y1, HIGH);  // Y variant A
			//digitalWrite(Y2, LOW);  // Y variant A
			digitalWrite(Y1, LOW);  // Y variant B
			digitalWrite(Y2, HIGH);  // Y variant B
			delay(1);
			col = analogRead(X1);
			delay(4);
			if (abs(analogRead(X1) - col) > 3) { return 0; }
			delay(3);
			if (abs(analogRead(X1) - col) > 3) { return 0; }
			//if (analogRead(X1)!=col) { return 0;}

			//digitalWrite(Y1, LOW);  // Y variant A
			digitalWrite(Y2, LOW);  // Y variant B
			//delay(5);
			touch = !digitalRead(X1); // 0 - dotyk
			if (touch) {
				int16_t rows = ROW_L - ROW_F;
				int16_t cols = COL_L - COL_F;
				float row1 = float(row - ROW_F) / rows * 240;
				float col1 = float(col - COL_F) / cols * 320;
				T_ROW = int(row1);
				T_COL = int(col1);
				valid = 1;
			}
			wait_touch = 0;
		}
	}
	// Re-Set A2 A3 8 9 for ILI9341
	BD_as_output();
	DDRC = DDRC | B00011111; // A0-A4 as outputs  

	// To find out values for calibration F_ROW, L_ROW, F_COL, F_COL
	// /* 
	B_COLOR = 0x0C0C;
	F_SIZE = 2;
	P_COL = 230;
	P_ROW = 200;
	Display_integer(row);
	P_COL = 280;
	P_ROW = 200;
	Display_integer(col);

	P_COL = 230;
	P_ROW = 220;
	Display_clear_char(3);
	Display_integer(T_ROW);
	P_COL = 280;
	P_ROW = 220;
	Display_clear_char(3);
	Display_integer(T_COL);
	B_COLOR = GREEN;
	F_SIZE = 3;
	// */
	// Draw a point where touched
	LCD_rect(T_COL - 1, T_ROW - 1, 2, 2, F_COLOR);

	return valid;
}

uint16_t D_COL, D_ROW;

void setup()
{
	Serial.begin(9600);
	// Set pins 1-8 as output
	BD_as_output();

	// Set pins A0-A4 as output
	DDRC = DDRC | B00011111;

	LCD_init();

	LCD_clear(0x0C);

	B_COLOR = GREEN;
	F_COLOR = BLACK;
	// draw a keypad
	for (int i = 0; i < 11; i++) {
		P_COL = K_COL[i];
		P_ROW = K_ROW[i];
		LCD_rect(P_COL, P_ROW, 30, 30, GREEN);
		P_COL = K_COL[i] + 8;
		P_ROW = K_ROW[i] + 4;
		Display_string(K_LABEL[i]);
	}

	D_COL = 10; // where to display number from keypad 
	D_ROW = 10;
}

void loop()
{
	byte touch = ReadTouch();
	if (touch) {
		for (int i = 0; i < 11; i++) {
			if (T_COL > K_COL[i] && T_COL<K_COL[i] + 30 && T_ROW>K_ROW[i] && T_ROW < K_ROW[i] + 30) {
				P_COL = K_COL[i];
				P_ROW = K_ROW[i];
				LCD_rect(P_COL, P_ROW, 30, 30, RED);
				P_COL = K_COL[i] + 8;
				P_ROW = K_ROW[i] + 4;
				B_COLOR = RED;
				Display_string(K_LABEL[i]);
				if (K_LABEL[i] == "<") {
					if (D_COL > 10) {
						D_COL -= F_SIZE * 6;
						P_COL = D_COL;
						P_ROW = D_ROW;
						B_COLOR = 0x0C0C;
						Display_clear_char(1);
					}
				}
				else if ((D_COL + (F_SIZE * 6)) < 320) {
					P_COL = D_COL;
					P_ROW = D_ROW;
					B_COLOR = 0x0C0C;
					Display_string(K_LABEL[i]);
					D_COL = P_COL;
					D_ROW = P_ROW;
				}
				delay(100);
				P_COL = K_COL[i];
				P_ROW = K_ROW[i];
				LCD_rect(P_COL, P_ROW, 30, 30, GREEN);
				P_COL = K_COL[i] + 8;
				P_ROW = K_ROW[i] + 4;
				B_COLOR = GREEN;
				Display_string(K_LABEL[i]);
			}
		}
	}
}