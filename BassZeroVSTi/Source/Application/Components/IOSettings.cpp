/*
  ==============================================================================

    IOSettings.cpp
    Created: 23 Oct 2019 3:30:38am
    Author:  gorangrubic

  ==============================================================================
*/

#include "IOSettings.h"

void IOSettings::Deploy(IOPorts & ioPorts)
  {
	MIDIInput1.SetSource(&ioPorts.MIDIInputs);
	MIDIInput2.SetSource(&ioPorts.MIDIInputs);
	MIDIInput3.SetSource(&ioPorts.MIDIInputs);

	MIDIOutput1.SetSource(&ioPorts.MIDIOutputs);
	MIDIOutput2.SetSource(&ioPorts.MIDIOutputs);
	MIDIOutput3.SetSource(&ioPorts.MIDIOutputs);

	MIDIDevice.SetSource(&ioPorts.MIDIOutputs);

	SerialPort.SetSource(&ioPorts.SerialPorts);
	SerialBaudrate.SetSource(&ioPorts.SerialBaudrates);
  }
