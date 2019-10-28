#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Header.h"

#include "../GeneralDefinitions.h"

#include "MidiGeneratorSettings.h"
#include "IOSettings.h"
#include "ViewSettings.h"
class imbSynthGeneralConfiguration
	:public imbValueSetFile
	
{

public:

	MidiGeneratorSettings Generator = MidiGeneratorSettings("Generator", "MIDI Generator", "Testing purpose MIDI Note on/off message generator", "", "");
	IOSettings ioSettings = IOSettings("IOSettings", "Input/Output settings", "", "");
	ViewSettings viewSettings = ViewSettings("ViewSettings", "", "");

	dataStringProperty NeedleMIDIDevice = dataStringProperty("NeedleMIDIDevice", "Pro Micro|BassZero", "MIDI device needle");
	dataStringProperty NeedleSerialPort = dataStringProperty("NeedleSerialPort", "COM16|COM46|COM35", "");
	dataStringProperty NeedleMIDIInput = dataStringProperty("NeedleMIDIInput", "Novation", "");
	dataStringProperty NeedleMIDIOutput = dataStringProperty("NeedleMIDIOutput", "MIDI Out", "");

	dataBoolProperty SaveLogToFile = dataBoolProperty("SaveLogToFile", true, "Save log to file");
	dataBoolProperty FactoryPresetsReadOnly = dataBoolProperty("FactoryPresetsReadOnly", true, "");

	imbSynthGeneralConfiguration(IOPorts &ioPorts) :imbValueSetFile("configuration", "", FILEEXTENSION_SETTINGS) {
	
		Add(&NeedleMIDIDevice);
		Add(&NeedleSerialPort);
		Add(&NeedleMIDIInput);
		Add(&NeedleMIDIOutput);

		Add(&SaveLogToFile);
		Add(&FactoryPresetsReadOnly);

		Add(&ioSettings);
		Add(&Generator);

		ioSettings.Deploy(ioPorts);
	};
	~imbSynthGeneralConfiguration();
};

