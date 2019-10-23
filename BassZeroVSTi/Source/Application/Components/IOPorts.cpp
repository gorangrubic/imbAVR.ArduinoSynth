/*
  ==============================================================================

    IOPorts.cpp
    Created: 23 Oct 2019 12:53:30am
    Author:  gorangrubic

  ==============================================================================
*/

#include "IOPorts.h"

void IOPorts::deploy()
  {

	auto _inputs = MidiInput::getAvailableDevices();
	auto _outputs = MidiOutput::getAvailableDevices();

	MIDIInputs.ClearAll();
	MIDIInputs.Add("none");
	for (MidiDeviceInfo& newDevice : _inputs)
	{
		MIDIInputs.Add(newDevice.name);
	}

	MIDIOutputs.ClearAll();
	MIDIOutputs.Add("none");
	for (MidiDeviceInfo& newDevice : _outputs)
	{
		MIDIOutputs.Add(newDevice.name);
	}

	SerialPorts.ClearAll();
	SerialPorts.Add("none");
	StringPairArray portlist = SerialPort::getSerialPortPaths();

	for (juce::String var : portlist.getAllKeys())
	{
		SerialPorts.Add(var);
	}

	SerialBaudrates.ClearAll();
	SerialBaudrates.Add("115200");
	SerialBaudrates.Add("57600");
	SerialBaudrates.Add("9600");
	
	
	

  }

