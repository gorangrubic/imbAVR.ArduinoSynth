// 
// 
// 
#include <SignalInstruction.h>
#include "SignalControlLink.h"

#include "SignalControlManager.h"



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

	
}

byte SignalControlLink::getBytePackage(byte cc_id, SignalInstruction & instructionToSend) {


	byte valueByte = 0;


	switch (cc_id) {

	case CCID_PITCHBYTELOW:
		valueByte = lowByte(instructionToSend.Frequency);
		break;
	case CCID_CHANGE_PWM:
		valueByte = instructionToSend.PWMChange.Change;
		break;
	case CCID_CHANGE_PHASE:
		valueByte = instructionToSend.PhaseChange.Change;
		break;
	case CCID_CHANGE_PITCH:
		valueByte = instructionToSend.PitchChange.Change;
		break;
	case CCID_CHANGE_RESET:
		valueByte = instructionToSend.ResetClock.Change;


		break;

	case CCID_PWMBYTE:
		valueByte = instructionToSend.pwmPattern;
		break;
	case CCID_PHASEBYTE:
		valueByte = instructionToSend.Phase;
		break;
	case CCID_PITCHBYTEHIGH:
		valueByte = highByte(instructionToSend.Frequency);

		break;
	case CCID_MODEBYTE:
		valueByte = instructionToSend.Mode;
		break;
	case CCID_CHANGE_RATE_PHASE:
		valueByte = instructionToSend.PhaseChange.Rate;
		break;
	case CCID_CHANGE_RATE_PITCH:
		valueByte = instructionToSend.PitchChange.Rate;
		break;
	case CCID_CHANGE_RATE_RESET:
		valueByte = instructionToSend.ResetClock.Rate;
		break;
	case CCID_CHANGE_RATE_PWM:
		valueByte = instructionToSend.PWMChange.Rate;
		break;

	}

	return valueByte;
}


/// <summary>
/// Sends the byte package, if the same value, for the same cc_id and signal id was not altready sent. For two-byte cc_ids, call only the first -- second will be sent automatically.
/// </summary>
/// <param name="port">The port.</param>
/// <param name="cc_id">The cc identifier.</param>
/// <param name="instructionToSend">The instruction to send.</param>
void SignalControlLink::sendBytePackage(SoftwareSerial * port, byte cc_id, SignalInstruction & instructionToSend) {


	byte cc_sid_byte = (cc_id << 4) & instructionToSend.SignalID;
	byte valueByte = getBytePackage(cc_id, instructionToSend);

	byte cc_second_id = cc_id;

	
	boolean doSend = true;
	switch (cc_id) {

	case CCID_PITCHBYTELOW:
		cc_second_id = CCID_PITCHBYTEHIGH;
		
		break;
	case CCID_CHANGE_PWM:
		cc_second_id = CCID_CHANGE_RATE_PWM;
		
		break;
	case CCID_CHANGE_PHASE:
		cc_second_id = CCID_CHANGE_RATE_PHASE;
		
		break;
	case CCID_CHANGE_PITCH:
		cc_second_id = CCID_CHANGE_PITCH;
		
		break;
	case CCID_CHANGE_RESET:
		cc_second_id = CCID_CHANGE_RESET;
		

		
		break;
		default:
			break;
	}


	if (cc_id != cc_second_id) {

		instructionToSend.TempByte = valueByte;
		valueByte = getBytePackage(cc_second_id, instructionToSend);

		if (instructionToSend.lastSent[cc_id] == instructionToSend.TempByte && instructionToSend.lastSent[cc_second_id] == valueByte) {
			doSend = false;
		}

	}
	else {
		if (instructionToSend.lastSent[cc_id] == valueByte) {
			doSend = false;
		}
	}

	bool confirmed = true;

	while (!confirmed && (PackageRetryIndex < PackageRetries)) {
		
		if (doSend) {

			if (cc_id != cc_second_id) {

				port->write(cc_sid_byte);

				port->write(instructionToSend.TempByte);

				byte cc_sid_byte2 = (cc_second_id << 4) & instructionToSend.SignalID;

				port->write(cc_sid_byte2);

				port->write(valueByte);


				if (ConfirmationProtocol) {

					delay(TXDELAY);

					while (port->available() < 0) {
						delay(TXDELAY);
					}

					if (port->read() != cc_sid_byte) confirmed = false;
					if (port->read() != instructionToSend.TempByte) confirmed = false;
					if (port->read() != cc_sid_byte2) confirmed = false;
					if (port->read() != valueByte) confirmed = false;

				}

					if (confirmed) {

						instructionToSend.lastSent[cc_id] = instructionToSend.TempByte;
						instructionToSend.lastSent[cc_second_id] = valueByte;
						PackageRetryIndex = 0;
					}
				

			}
			else {

				port->write(cc_sid_byte);

				port->write(valueByte);

				if (ConfirmationProtocol) {

					delay(TXDELAY);

					if (port->read() != cc_sid_byte) confirmed = false;
					if (port->read() != valueByte) confirmed = false;
				}

				if (confirmed) {
					instructionToSend.lastSent[cc_id] = valueByte;
					PackageRetryIndex = 0;
				}
			}
		}
		if (!confirmed) {
			PackageRetryIndex++;
			delay(TXDELAY);

			Serial.print("BytePackage retry");
			Serial.print(PackageRetryIndex);
			Serial.print(" / ");
			Serial.println(PackageRetries);
			PackageRetryIndex = 0;
		}
	}

	if (PackageRetryIndex > 0) {
		Serial.print("BytePackage failed ");
		Serial.print(PackageRetryIndex);
		Serial.println("times.");
		PackageRetryIndex = 0;
	}

}



void SignalControlLink::sendInstruction(SoftwareSerial * port, SignalInstruction & instructionToSend)
{
	unsigned int last = instructionToSend.GetControlByte();
	if (instructionToSend.lastControlByte != last) {

	if (ByteCodeProtocol) {

		sendBytePackage(port, CCID_CHANGE_RATE_PWM, instructionToSend);
		sendBytePackage(port, CCID_PITCHBYTELOW, instructionToSend);

		sendBytePackage(port, CCID_MODEBYTE, instructionToSend);

		sendBytePackage(port, CCID_CHANGE_PWM, instructionToSend);

		sendBytePackage(port, CCID_CHANGE_PHASE, instructionToSend);
		sendBytePackage(port, CCID_CHANGE_PITCH, instructionToSend);
		sendBytePackage(port, CCID_CHANGE_RESET, instructionToSend);

		
	}
	else {

		

			String inst = instructionToSend.GetString(); // sendAsString();
			
			port->println(inst);
		}

	
		instructionToSend.lastControlByte = last;

	}


}

void SignalControlLink::send(SoftwareSerial * port, byte signalID, unsigned int frequency, byte waveform = WAVEFORM_HALFCYCLE, byte phase_shift = 0, bool resetPWMStep = true, bool resetSClock = true, bool setPWMStep = true, bool setSClock = false) {

	instruction.Set(signalID, frequency, waveform, phase_shift, resetPWMStep, resetSClock, setPWMStep, setSClock);

	sendInstruction(port, instruction);
	

}