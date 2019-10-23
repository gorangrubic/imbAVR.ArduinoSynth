/*
  ==============================================================================

    MidiGeneratorSettings.h
    Created: 23 Oct 2019 12:52:37am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"

class MidiGeneratorSettings:public dataObject {

public:

	
	dataBoolProperty Enabled = dataBoolProperty("Enabled", false);
	dataIntProperty Velocity = dataIntProperty("Velocity", 100);

	dataIntProperty Pitch = dataIntProperty("Pitch", 0);
	dataIntProperty NoteDuration = dataIntProperty("NoteDuration", 1);
	dataIntProperty LoopDuration = dataIntProperty("LoopDuration", 16);

	dataIntProperty BPM = dataIntProperty("BPM", 120);
	dataBoolProperty BPMFromHost = dataBoolProperty("BPMFromHost", true);


	MidiGeneratorSettings(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {
	
		
		Add(&Enabled);
		Add(&Velocity);
		Add(&Pitch);
		Add(&NoteDuration);
		Add(&LoopDuration);
		Add(&BPM);
		Add(&BPMFromHost);
	}

};