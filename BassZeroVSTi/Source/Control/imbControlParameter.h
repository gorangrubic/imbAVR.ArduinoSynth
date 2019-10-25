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


#include "ParameterController.h"

#include "../Source/GUI/Components/imbSynthParameterEditor.h"

#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/Data/Model/dataObjectProperty.h"
//

//#include "../Model/SynthDeviceModelComponentBase.h"
//#include "../Model/SynthDeviceModel.h"
// #include "../Source/Model/SynthDeviceModelComponentBase.h"



#include <vector>
#include <list>

typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;


//

class imbControlParameter : 
	public dataObjectPropertyBase,
	public AudioProcessorValueTreeState::Listener
	
{



public:





	//AudioProcessorParameter::Category category = AudioProcessorParameter::Category::

	// ============= setup methods

	
	
	void Setup(String _parameterID, String _parameterLabel, 
			float minValue, float maxValue, float initValue,
                String _parameterUnit,
                int _ccID=0, bool _isAutomatizable=false, imbControlParameterType typeParameterName=imbControlParameterType::Integer,
		imbControlParameterMessageType _msgFormat = imbControlParameterMessageType::unspecified);
	


	juce::String valueToString(float v, int maxLen);
	float stringToValue(juce::String input);


/*
	std::function<String> valueToString;
	std::function<float> stringToValue;
*/



	std::string parameterParentPath;

	
	//bool isMetaValue;
	//bool isAutomatizable;
	//bool isDescreteValue;


	// ========================== CC MIDI parameters

	int ccID;

	imbControlParameterType typeParameter;
	imbControlParameterMessageType typeMIDIMessage = imbControlParameterMessageType::ccMIDI;

	//float Value = 0;



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

	void updateAll();

	//void detachControl();
	//void attachControl(Slider* _slider);
	//void attachControl(ComboBox* _comboBox);
	//void attachControl(ToggleButton* _button);
	//void attachControl(imbSynthParameterEditor* _editor);



	
	

	imbControlParameter(); //:Listener(Value, 1.0F) { };
	
	imbControlParameter(parameterClass _class);

	~imbControlParameter();
};