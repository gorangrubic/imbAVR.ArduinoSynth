// 
// 
// 
#include <SignalInstruction.h>
#include "SignalControlLink.h"



void SignalControlLink::setupMaster(int address)
{
	mode = 1;
	i2c_slave_address = address;
	//Wire.begin();
	//start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
	///ETC.begin(details(instruction), &Wire);
	
}

void SignalControlLink::setupSlave(int address)
{
	i2c_slave_address = address;

//	Wire.begin(i2c_slave_address);
	//start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
	//ETC.begin(details(instruction), &Wire);
	//define handler function on receiving data
	
	mode = 1;
	
}

void SignalControlLink::setup(int rx_pin, int tx_pin, unsigned int baudrate)
{
	mode = 0;
	

	// ET.begin(details(instruction), &SoftSerial);
}

/// <summary>
/// Call this from loop(). 
/// </summary>
/// <returns>True if instruction is updated</returns>
bool SignalControlLink::receive()
{
	bool output = false;


	

	return output;
}

String SignalControlLink::readStringChar(String input)
{
	//buffer += input;


	int fromIndex = input.indexOf('[');

	if (fromIndex > -1) {
		int endIndex = input.indexOf(']', fromIndex);

		//do {

		if ((fromIndex > -1) && (endIndex > -1)) {

			String instructionString = input.substring(fromIndex+1, endIndex);
			input = input.substring(endIndex + 1);

			readAsString(instructionString);

			

		}

	}

		return input;

		/*fromIndex = buffer.indexOf('[');
		endIndex = buffer.indexOf(']', fromIndex);

	} while (fromIndex > 0 && endIndex > 0);*/

}

bool SignalControlLink::readAsString(String instructionString)
{


	//serialOut->println("Received:");
	//if (SerialReport) serialOut->println(instructionString);


	int split_index = instructionString.indexOf(" ");
	int i = 0;

	if (split_index == -1) {
		return false;
	}

	while (split_index > 0) {

		String valString = instructionString.substring(0, split_index+1);

		instructionString = instructionString.substring(split_index+1);

		/*if (SerialReport) {
			serialOut->print("val[");
			serialOut->print(i);
			serialOut->print("]=");
			serialOut->println(valString);
		}*/
		

		switch (i) {
			case 0:
				instruction.SignalID = valString.toInt();
				break;
			case 1:
				instruction.Frequency= valString.toInt();
				break;
			case 2:
				instruction.Phase = valString.toInt();
				break;
			case 3:
				instruction.pwmPattern = valString.toInt();
				break;
		
		}

		

		i++;
		split_index = instructionString.indexOf(" ");

		

		if (i > 4) break;
	}

	instructionIndex++;
	return true;

}




bool SignalControlLink::readInstruction(HardwareSerial * serialOut) {

	//if (mode == 1) {
	//	//return ETC.receiveData();
	//} 
	//if (mode == 0) {
	//	bool output = readAsString(serialOut); //ET.receiveData();
	//	//delay(RXDELAY);
	//	return output;
	//}
	//bool output = true;

	//byte data[SIGNALINSTRUCTION_SIZE];
	//SoftSerial.readBytes(data, SIGNALINSTRUCTION_SIZE);


	//bool prefix = false;

	//byte prefixFirstByte = SoftSerial.read();

	//while (prefixFirstByte != SIGNAL_STARTBYTE) {
	//	prefixFirstByte = SoftSerial.read();
	//}

	//byte prefixSecondByte = SoftSerial.read();

	//while ((prefixFirstByte == SIGNAL_STARTBYTE && prefixSecondByte == SIGNAL_ENDBYTE)) {
	//	prefixFirstByte = SoftSerial.read();
	//	prefixSecondByte = SoftSerial.read();
	//}

	//
	//
	//
	//
	////data[0] = startByte;

	//

	//byte i = 1;
	//// data[i];
	////i++;

	//
	//byte SignalID = 0; // data[0] >> 4; i++;

	//byte f1 = 0;//data[1]; i++;
	//byte f2 = 0; // data[2]; i++;


	//byte phase = 0; //data[3]; i++;
	//byte pwmPattern = 0; // = data[4]; i++;

	///*byte controlByteTest = 0;
	//for (size_t y = 1; y < i; y++)
	//{
	//	controlByteTest += data[y];
	//}

	//byte controlByte = data[i]; i++;;*/

	//while (i < SIGNALINSTRUCTION_SIZE) {

	//	if (i <= SIGNALINSTRUCTION_DATASIZE) {
	//		data[i] = SoftSerial.read();

	//		if (i == 1) SignalID = data[i] >> 4;
	//		if (i == 2) f1= data[i];
	//		if (i == 3) f2 = data[i];
	//		if (i == 4) phase = data[i];
	//		if (i == 5) pwmPattern = data[i];


	//	}
	//	else {
	//		byte b = SoftSerial.read();
	//		data[i] = b;
	//		if (b != SIGNAL_ENDBYTE) {
	//			output = false;
	//			serialOut->print("End byte ");
	//			serialOut->print(i);
	//			serialOut->println("not found ");
	//			break;
	//		}
	//	}
	//	
	//	i++;
	//}


	//if (SignalID >= 16) {
	//	output = false;
	//	serialOut->print("SignalID ");
	//	serialOut->print(SignalID);
	//	serialOut->println("out of range");

	//}

	//if (output) {

	//	instructionIndex++;

	//	unsigned int freq = f1;
	//	freq = freq << 8;
	//	freq = freq | f2;

	//	instruction.Frequency = freq;
	//	instruction.SignalID = SignalID;
	//	instruction.Phase = phase;
	//	instruction.pwmPattern = pwmPattern;
	//}
	//else {

	//	for (size_t y = 0; y < i+1; y++)
	//	{
	//		
	//			serialOut->print("b[");
	//			serialOut->print(y);
	//			serialOut->print("]=");
	//			serialOut->println(data[y]);
	//	}
	//}
	//
	//return output;
}



void SignalControlLink::sendInstruction(SoftwareSerial * port, SignalInstruction & instructionToSend)
{

	unsigned int last = instructionToSend.GetControlByte();
	if (instructionToSend.lastControlByte != last) {

		String inst = instructionToSend.GetString(); // sendAsString();
		instructionToSend.lastControlByte = last;
		port->println(inst);
	}

	

	//SoftSerial.print(inst);

	/*if (mode == 1) {
		ETC.sendData(i2c_slave_address);
		return;
	}
*/

	//if (mode == 0) {

	//	

	//	//ET.sendData();

	//	delay(TXDELAY);
	//}

	//instructionIndex++;

	//byte data[SIGNALINSTRUCTION_SIZE];
	//byte i = 0;

	//for (size_t y = 0; y < SIGNALINSTRUCTION_PREFIXSIZE; y++)
	//{
	//	data[i] = SIGNAL_STARTBYTE; i++;
	//	data[i] = SIGNAL_ENDBYTE; i++;
	//}

	//data[i] = SIGNAL_STARTBYTE; i++;

	//	data[i] = instruction.SignalID << 4; i++;

	//	data[i] = lowByte(instruction.Frequency); i++;

	//	data[i] = highByte(instruction.Frequency); i++;

	//	data[i] = instruction.Phase; i++;

	//	data[i] = instruction.pwmPattern; i++;
	//	///**/
	//	//byte controlByte = 0;
	//	//for (size_t y = 1; y < i; y++)
	//	//{
	//	//	controlByte += data[y];
	//	//}

	//	//data[i] = controlByte; i++;

	//	for (size_t y = i; y < SIGNALINSTRUCTION_SIZE; y++)
	//	{
	//		data[y] = SIGNAL_ENDBYTE;

	//		
	//	}

	//SoftSerial.write(data, SIGNALINSTRUCTION_SIZE);

}

void SignalControlLink::send(SoftwareSerial * port, byte signalID, unsigned int frequency, byte waveform = WAVEFORM_HALFCYCLE, byte phase_shift = 0, bool resetPWMStep = true, bool resetSClock = true, bool setPWMStep = true, bool setSClock = false) {

	instruction.Set(signalID, frequency, waveform, phase_shift, resetPWMStep, resetSClock, setPWMStep, setSClock);

	sendInstruction(port, instruction);
	

}