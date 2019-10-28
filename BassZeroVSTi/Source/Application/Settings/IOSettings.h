/*
  ==============================================================================

    IOSettings.h
    Created: 23 Oct 2019 3:30:38am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"
#include "../Source/Application/Components/IOPorts.h"

class IOSettings :public dataObject {

public:
	dataBoolProperty UseSerialLinkForMidi = dataBoolProperty("UseSerialLinkForMidi", true, "Use serial for MIDI", "Sends MIDI messages to the device using serial link if no MIDI device found");

	dataBoolProperty EnableDirectMIDIInputs = dataBoolProperty("EnableDirectMIDIInputs", true, "Enable MIDI inputs", "MIDI inputs are enabled");
	dataBoolProperty EnableDirectMIDIOutputs = dataBoolProperty("EnableDirectMIDIOutputs", true);

	dataBoolProperty ForwardInputsToOutputs = dataBoolProperty("ForwardInputsToOutputs", true, "Forward inputs to outputs", "Enables MIDI message forwarding from selected MIDI inputs to outputs");
	dataBoolProperty ForwardVSTHostToOutputs = dataBoolProperty("ForwardVSTHostToOutputs", true, "Forward VST host to outputs", "Enables MIDI message forwarding from DAW/VST host to selected MIDI outputs");

	dataIntProperty IOUpdateCycle = dataIntProperty("IOUpdateCycle", 50, "MIDI IO update cycle", "Period for input/output update", "ms");

	dataEnumProperty MIDIInput1 = dataEnumProperty("MIDIInput1", 0, "MIDI Input 1");
	dataEnumProperty MIDIInput2 = dataEnumProperty("MIDIInput2", 0, "MIDI Input 2");
	dataEnumProperty MIDIInput3 = dataEnumProperty("MIDIInput3", 0, "MIDI Input 3");

	dataEnumProperty MIDIOutput1 = dataEnumProperty("MIDIOutput1", 0, "MIDI Output 1");
	dataEnumProperty MIDIOutput2 = dataEnumProperty("MIDIOutput2", 0, "MIDI Output 2");
	dataEnumProperty MIDIOutput3 = dataEnumProperty("MIDIOutput3", 0, "MIDI Output 3");

	dataEnumProperty MIDIDevice = dataEnumProperty("MIDIDevice", 0, "Synth MIDI device");

	dataEnumProperty SerialPort = dataEnumProperty("SerialPort", 0, "Synth serial port");
	dataEnumProperty SerialBaudrate = dataEnumProperty("SerialBaudrate", 0, "Baudrate on serial port");



	dataIntProperty FullSyncPlayTimeout = dataIntProperty("FullSyncPlayTimeout", 1000, "Full sync timeout", "Time to wait after Play (at DAW or MIDI generator) is off - before syncing all preset parameters to synth", "ms");

	dataIntProperty CCMessagesCycle = dataIntProperty("CCMessagesCycle", 10, "CC messages cycle", "Refresh rate at which CC states are synchronized with synth", "ms");

	dataBoolProperty ConfirmationForNote = dataBoolProperty("ConfirmationForNote", true, "Note On/Off confirmation", "Enforces message received confirmation for MIDI Note On and Note Off messages");
	dataBoolProperty ConfirmationForCC = dataBoolProperty("ConfirmationForCC", true, "CC confirmation", "Enforces message received confirmation for MIDI CC messages");
	dataBoolProperty ConfirmationForOPM = dataBoolProperty("ConfirmationForOPM", true, "OPM confirmation", "Enforces message received confirmation for OPM instructions");

	dataIntProperty ConfirmationRetryLimit = dataIntProperty("ConfirmationRetryLimit", 2, "Confirmation retry limit", "Retry limit for message received confirmation - before giving up");
	dataIntProperty ConfirmationTimeout = dataIntProperty("ConfirmationTimeout", 10, "Confirmation timeout", "Time to wait for confirmation response", "ms");

	dataIntProperty DeviceConnectRetry = dataIntProperty("DeviceConnectRetry", 5000, "Device connect retry", "Time to retry connection with the device", "ms");
	dataIntProperty UIRefreshRate = dataIntProperty("UIRefreshRate", 250, "UI refresh rate", "Refresh rate for certain user interface components", "ms");


	dataIntProperty VSTiBaseClock = dataIntProperty("VSTiBaseClock", 1, "VSTiBaseClock", "", "ms");
	dataIntProperty DeviceBaseClock = dataIntProperty("DeviceBaseClock", 10, "DeviceBaseClock", "", "ms");


	void Deploy(IOPorts &ioPorts);

	IOSettings(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {
		
		Add(&UseSerialLinkForMidi);

		Add(&EnableDirectMIDIInputs);
		Add(&EnableDirectMIDIOutputs);
		Add(&ForwardInputsToOutputs);
		Add(&ForwardVSTHostToOutputs);

		Add(&MIDIInput1);
		Add(&MIDIInput2);
		Add(&MIDIInput3);


		Add(&MIDIOutput1);
		Add(&MIDIOutput2);
		Add(&MIDIOutput3);

		Add(&MIDIDevice);

		Add(&SerialPort);
		Add(&SerialBaudrate);

		Add(&FullSyncPlayTimeout);
		Add(&CCMessagesCycle);

		Add(&ConfirmationForNote);
		Add(&ConfirmationForCC);
		Add(&ConfirmationForOPM);

		Add(&ConfirmationRetryLimit);
		Add(&ConfirmationTimeout);

		Add(&DeviceConnectRetry);
		Add(&UIRefreshRate);

		Add(&IOUpdateCycle);

		Add(&VSTiBaseClock);
		Add(&DeviceBaseClock);
	};

};