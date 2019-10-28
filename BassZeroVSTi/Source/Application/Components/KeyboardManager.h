#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "juce_serialport\juce_serialport.h"
#include "../Source/Data/Structures/imbEnumerationList.h"
class IOPorts {

public:

	imbEnumerationList MIDIInputs;

	imbEnumerationList MIDIOutputs;

	imbEnumerationList SerialPorts;

	imbEnumerationList SerialBaudrates;


	void deploy();





	IOPorts() {
		deploy();
	}

};