/*
  ==============================================================================

    imbAVRParameter.h
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "imbControlParameterEnumerations.h"
#include "imbEnumerationList.h"
#include "ParameterController.h"

#include "../Source/GUI/Components/imbSynthParameterEditor.h"


//

//#include "../Model/SynthDeviceModelComponentBase.h"
//#include "../Model/SynthDeviceModel.h"
// #include "../Source/Model/SynthDeviceModelComponentBase.h"



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


class imbProcessorParameterListener : public AudioProcessorParameter::Listener {

	void parameterValueChanged(int parameterIndex, float newValue);

	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting);

	imbProcessorParameterListener() {};
};

using pt = AudioProcessorValueTreeState::Parameter;

class imbControlParameter : public AudioProcessorValueTreeState::Listener
	
{

private:
	/* indicating if GUI is currently updated by internal source */
	bool isGUIUpdating = false;
	bool isStateUpdating = false;

public:


	imbControlParameterComponentType componentType;

	imbEnumerationList * enumerationList;

	// ============= references

	
	//SynthDeviceModelComponentBase * Parent;
	//SynthDeviceModel * Root;
	

	//imbProcessorParameterListener Listener;

//	std::vector<juce::String> choiceItems;

	AudioProcessorParameter::Category category = AudioProcessorParameter::Category::genericParameter;

	// ============= setup methods

	
	
	void Setup(String _parameterID, String _parameterLabel, 
			float minValue, float maxValue, float initValue,
                String _parameterUnit,
                int _ccID=0, bool _isAutomatizable=false, imbControlParameterType typeParameterName=imbControlParameterType::Integer,
		imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified);
	
	
	// ========================== Slider assigment
	//Slider* assignedSlider;

	//bool SliderMoved(Slider* sliderThatWasMoved);

	//void SliderUpdate();

	juce::String valueToString(float v, int maxLen);
	float stringToValue(juce::String input);


/*
	std::function<String> valueToString;
	std::function<float> stringToValue;
*/
	// ========================== VSTi parameters
	String parameterIDPath;
	String parameterParentPath;
	String parameterID;
	String parameterLabel;
	String parameterUnit;
	
	/// <summary>
	/// Short help on this parameter
	/// </summary>
	String parameterHelp;

	/// <summary>
	/// URL with more information on the parameter
	/// </summary>
	String parameterHelpUrl;
	
	/// <summary>
	/// Error message
	/// </summary>
	String Error;
	


	/// <summary>
	/// Sets additional information on this parameter
	/// </summary>
	/// <param name="_parameterHelp">The parameter help.</param>
	/// <param name="_parameterHelpUrl">The parameter help URL.</param>
	/// <param name="_parameterUnit">The parameter unit.</param>
	void SetHelp(String _parameterHelp, String _parameterHelpUrl = "", String _parameterUnit = "");

	bool isMetaValue;
	bool isAutomatizable;
	bool isDescreteValue;


	//std::unique_ptr<AudioParameterInt> parameter;

	//pt * parameter; // = AudioParameterInt(&parameterID, &parameterID, MinValue, MaxValue, Value);

	//RangedAudioParameter * rangedParameter;
	//std::unique_ptr<RangedAudioParameter> ptr;

	//void SetParameter(std::shared_ptr<ParameterController> parameterControllerPtr, AudioProcessorParameterGroup * group);

	// ========================== CC MIDI parameters

	int ccID;

	imbControlParameterType typeParameter;
	imbControlParameterMessageType typeMIDIMessage = imbControlParameterMessageType::ccMIDI;

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
	bool SetValue(float _newValue);

	void detachControl();
	void attachControl(Slider* _slider);
	void attachControl(ComboBox* _comboBox);
	void attachControl(ToggleButton* _button);
	void attachControl(imbSynthParameterEditor* _editor);

	void attachState(juce::AudioProcessorValueTreeState & parameters);

	void updateGUI();
	void updateState();
	void updateTooltip();
	
	std::shared_ptr<Slider> pSlider;
	std::shared_ptr<ComboBox> pComboBox;
	std::shared_ptr<ToggleButton> pToggleButton;
	std::shared_ptr<imbSynthParameterEditor> pParameterEditor;
	std::shared_ptr<juce::RangedAudioParameter> pParameter;

	void parameterChanged(const String&, float newValue) override;
	


	std::function<void(imbControlParameter * parameter)> onGUIFocus;
	
	

	imbControlParameter(); //:Listener(Value, 1.0F) { };

	~imbControlParameter();
};