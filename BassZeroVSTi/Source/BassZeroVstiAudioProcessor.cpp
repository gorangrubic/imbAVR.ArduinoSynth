/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "BassZeroVstiAudioProcessor.h"
#include "BassZeroVstiAudioProcessorEditor.h"

//==============================================================================
//BassZeroVstiAudioProcessor::BassZeroVstiAudioProcessor()
//{
//}

BassZeroVstiAudioProcessor::~BassZeroVstiAudioProcessor()
{
}



//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new BassZeroVstiAudioProcessor();
}
