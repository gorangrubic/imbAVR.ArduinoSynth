/*
  ==============================================================================

    imbAVRParameter.cpp
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/



#include "imbControlParameter.h"



imbControlParameter::imbControlParameter()
{
}


void imbControlParameter::SliderMoved(Slider * sliderThatWasMoved)
{
	if (sliderThatWasMoved == assignedSlider)
	{
		ccValue = assignedSlider->getValue();
	}
}

void imbControlParameter::SliderUpdate()
{
	assignedSlider->setValue(ccValue);
}

bool imbControlParameter::SetMidiMessage(MidiMessage * message)
{
	return false;
}

MidiMessage * imbControlParameter::GetMidiMessage()
{
	return nullptr;
}

imbControlParameter::imbControlParameter(int cc_id)
{
}

imbControlParameter::~imbControlParameter()
{
}