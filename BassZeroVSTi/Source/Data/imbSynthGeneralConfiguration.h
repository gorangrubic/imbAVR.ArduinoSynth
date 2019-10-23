#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbValueSetFile.h"
#include "../Application/GeneralDefinitions.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"
#include "../Source/Application/Components/MidiGeneratorSettings.h"
#include "../Source/Application/Components/IOSettings.h"
#include "../Source/Application/Components/ViewSettings.h"
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

