// SignalControlLink.h

#ifndef _SIGNALCONTROLLINK_h
#define _SIGNALCONTROLLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
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

#define RXDELAY 1
#define TXDELAY 5

class SignalControlLink {

protected:
	// void receive(int numBytes);

public:

	//String buffer = "";



/// <summary>
/// Optimized protocol, using bytes instead of strings
/// </summary>
	bool ByteCodeProtocol = false;
	byte PackageRetries = 5;
	byte PackageRetryIndex = 0;

	SignalInstruction instruction;

	bool ConfirmationProtocol = false;

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


	void setup(int rx_pin = RXPIN, int tx_pin = TXPIN, unsigned int baudrate = DEFAULT_BAUDRATE);

	void setupMaster(int address);

	void setupSlave(int address);



	String readStringChar(String input);



	//bool readStringChar(String input);



	bool readAsString(String instructionString);



	//String sendAsString();

	bool readInstruction(HardwareSerial * serialOut);

	byte getBytePackage(byte cc_id, SignalInstruction & instructionToSend);

	void sendBytePackage(SoftwareSerial * port, byte cc_id, SignalInstruction & instructionToSend);

	void sendInstruction(SoftwareSerial * port, SignalInstruction & instructionToSend);



	void send(SoftwareSerial * port, byte signalID, unsigned int frequency, byte waveform = WAVEFORM_HALFCYCLE, byte phase_shift = 0, bool resetPWMStep = true, bool resetSClock = true, bool setPWMStep = true, bool setSClock = false);

};


#endif
