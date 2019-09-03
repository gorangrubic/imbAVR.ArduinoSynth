// SignalControlLink.h

#ifndef _SIGNALCONTROLLINK_h
#define _SIGNALCONTROLLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

#include <SignalControlManager.h>
#include <SignalInstruction.h>
#include <SoftwareSerial.h>
//#include <SoftEasyTransfer.h>
//#include <Wire.h>
//#include <EasyTransferI2C.h>





#define STRPROTOCOL_START [
#define STRPROTOCOL_SPLIT |
#define STRPROTOCOL_END ]

#define DEFAULT_BAUDRATE 9600
#define RXPIN 8
#define TXPIN 9

#define RXDELAY 100
#define TXDELAY 50

class SignalControlLink {

protected:
	// void receive(int numBytes);

public:

	//String buffer = "";

	

	SignalInstruction instruction;

	byte instructionIndex = 0;

	byte i2c_slave_address;

	byte mode = 1;

	//HardwareSerial * serialOut;

	//SoftwareSerial SoftSerial = SoftwareSerial(RXPIN, TXPIN);
//
	bool SerialReport;

	//// mode 1
	//EasyTransferI2C ETC;

	//// mode 0
	//SoftEasyTransfer ET;
	

	void setup(int rx_pin= RXPIN, int tx_pin= TXPIN, unsigned int baudrate= DEFAULT_BAUDRATE);

	void setupMaster(int address);

	void setupSlave(int address);

	bool receive();

	String readStringChar(String input);

	

	//bool readStringChar(String input);

	

	bool readAsString(String instructionString);

	

	//String sendAsString();

	bool readInstruction(HardwareSerial * serialOut);

	void sendInstruction(SoftwareSerial * port, SignalInstruction & instructionToSend);

	

	void send(SoftwareSerial * port, byte signalID, unsigned int frequency, byte waveform = WAVEFORM_HALFCYCLE, byte phase_shift = 0, bool resetPWMStep = true, bool resetSClock = true, bool setPWMStep = true, bool setSClock = false);

};
