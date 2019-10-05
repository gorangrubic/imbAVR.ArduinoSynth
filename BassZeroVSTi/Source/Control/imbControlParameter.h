/*
  ==============================================================================

    imbAVRParameter.h
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "imbControlParameter.h"
#include "../Model/SynthDeviceModel.h"
#include "../Model/SynthDeviceModelComponentBase.h"
#include <vector>
#include <list>

typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;



struct IntegerListener : public AudioProcessorValueTreeState::Listener
{
	int& workingValue;

	IntegerListener(int& wv) : AudioProcessorValueTreeState::Listener(), workingValue(wv) {}
	void parameterChanged(const String&, float newValue) override
	{
		workingValue = (int)newValue;
	}
};

template<typename EType>
struct EnumListener : public AudioProcessorValueTreeState::Listener
{
	EType& waveform;

	EnumListener(EType& wf) : AudioProcessorValueTreeState::Listener(), waveform(wf) {}
	void parameterChanged(const String&, float newValue) override
	{
		waveform = (EType)((int)newValue);
		
	}
};

struct FloatListener : public AudioProcessorValueTreeState::Listener
{
	float& workingValue;
	float scaleFactor;      // multiply parameter values by this to get working value

	FloatListener(float& wv, float sf = 1.0f) : AudioProcessorValueTreeState::Listener(), workingValue(wv), scaleFactor(sf) {}
	void parameterChanged(const String&, float newValue) override
	{
		workingValue = scaleFactor * newValue;
	}
};

struct BoolListener : public AudioProcessorValueTreeState::Listener
{
	bool& workingValue;

	BoolListener(bool& wv) : AudioProcessorValueTreeState::Listener(), workingValue(wv) {}
	void parameterChanged(const String&, float newValue) override
	{
		workingValue = newValue >= 0.5f;
	}
};


enum imbControlParameterType {
	Integer=0,
	Ratio=1,
	Float=2,
	Enumeration=3,
	Boolean=4

};

class imbControlParameter
{


public:

	
	static float ProcessValue(float _value, imbControlParameterType TP) {
		switch (TP) {
		case imbControlParameterType::Boolean:
			return _value ? 1.0f : 0.0f;
			break;
		default:
			return _value;
			break;
		}

	}

	template<imbControlParameterType TP>
	static float textToFloat(const String& s) {
		//imbControlParameterType TP = imbControlParameterType::Integer;
		switch (TP) {
		case imbControlParameterType::Boolean:
			return s == "yes" ? 1.0f : 0.0f;
		
			break;
		default:
			return s.getFloatValue();
			break;
		}

		return s.getFloatValue(); 
	}
	
	template<imbControlParameterType TP>
	static String floatToText(float fi) {

		//imbControlParameterType TP = imbControlParameterType::Integer;
		switch (TP) {
			case imbControlParameterType::Boolean:
				return fi < 0.5f ? "no" : "yes";
			break;
			default:
				return String((int)fi);
			break;
		}

		return String((int)fi);
	}

	// ============= references

	SynthDeviceModel * Root;
	SynthDeviceModelComponentBase * Parent;
	

	FloatListener Listener;

	std::vector<juce::String> choiceItems;

	AudioProcessorParameter::Category category;

	// ============= setup methods

	void Connect(SynthDeviceModelComponentBase * _parent);
	
	void Setup(String _parameterID, String _parameterLabel, 
                int minValue, int maxValue, int initValue, 
                String _parameterUnit,
                int _ccID=0, bool _isAutomatizable=false, imbControlParameterType typeParameterName=imbControlParameterType::Integer);
	
	
	// ========================== Slider assigment
	Slider* assignedSlider;

	bool SliderMoved(Slider* sliderThatWasMoved);

	void SliderUpdate();



	// ========================== VSTi parameters
	String parameterIDPath;

	String parameterID;
	String parameterLabel;
	String parameterUnit;

	bool isMetaValue;
	bool isAutomatizable;
	bool isDescreteValue;


	//std::unique_ptr<AudioParameterInt> parameter;

	juce::RangedAudioParameter * parameter; // = AudioParameterInt(&parameterID, &parameterID, MinValue, MaxValue, Value);


	// ========================== CC MIDI parameters

	int ccID;

	imbControlParameterType typeParameter;

	float Value = 0;
	float MinValue = 0;
	float MaxValue = 0;
	float IntervalValue = 1;

	/// <summary>
	/// Reads given MIDI message(s) and updates the ccValue, if the message is of CC type and with matching Channel ID. Otherwise ignores the message.
	/// </summary>
	/// <param name="message">The MIDI message to process.</param>
	/// <returns>true if value given by valid CC message was different from existing ccValue</returns>
	bool SetMidiMessage(MidiMessage * message);

	/// <summary>
	/// Creates a MIDI CC message with current ccValue
	/// </summary>
	/// <returns></returns>
	juce::MidiMessage GetMidiMessage();
	
	/// <summary>
	/// Sets the value as current ccValue. 
	/// </summary>
	/// <param name="_newValue">New value to set</param>
	/// <returns>true if given value was different from existing ccValue</returns>
	bool SetValue(int _newValue);

	void detachControl();
	void attachControl(Slider& slider);
	
	SliderAttachment* pSliderAttachment;

	imbControlParameter();

	~imbControlParameter();
};