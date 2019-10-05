/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "juce_audio_processors\utilities\juce_AudioParameterInt.h"

#include "imbSynthAudioProcessor.h"
//#include "juce_audio_processors\processors\juce_AudioProcessorParameterGroup.h"


//==============================================================================
/**
*/
class BassZeroAudioProcessor  : public imbSynthAudioProcessor
{
public:
	
	
	//[UserVariables]   -- You can add your own custom variables in this section.
	juce::AudioProcessorParameterGroup CP_Group_WFA = juce::AudioProcessorParameterGroup("WFA", "Waveform A", ".");
	juce::AudioParameterInt CP_WFA_Pitch;
	juce::AudioParameterInt CP_WFA_PWM;
	juce::AudioParameterInt CP_WFA_PWM;
		//("WFA_Pitch", "Waveform A Pitch", -36, 36);


	juce::AudioProcessorParameterGroup CP_Group_WFB = juce::AudioProcessorParameterGroup("WFB", "Waveform B", ".");
	juce::AudioProcessorParameterGroup CP_Group_PERKA = juce::AudioProcessorParameterGroup("PERKA", "PERK A", ".");
	juce::AudioProcessorParameterGroup CP_Group_PERKB = juce::AudioProcessorParameterGroup("PERKB", "PERK B", ".");
//[/UserVariables]

    //==============================================================================
    BassZeroAudioProcessor();
    ~BassZeroAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BassZeroAudioProcessor)
};
