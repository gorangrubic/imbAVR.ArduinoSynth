/*
  ==============================================================================

    imbSynthTools.cpp
    Created: 8 Oct 2019 1:59:00am
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbSynthTools.h"

std::string imbSynthTools::GetLetter(unsigned int input) {
			switch (input) {
			case 0:
				return "A";
				break;
			case 1:
				return "B";
				break;
			case 2:
				return "C";
				break;
			case 3:
				return "D";
				break;
			case 4:
				return "E";
				break;
			case 5:
				return "F";
				break;
			case 6:
				return "G";
				break;
			case 7:
				return "H";
				break;
			case 8:
				return "I";
				break;
			case 9:
				return "J";
				break;
			}

			return "W";
		}

int imbSynthTools::StringToInt32(juce::String stringValue, float defaultValue)
{
	int v = defaultValue;
	return StringToInt32(stringValue, v);
}

int imbSynthTools::StringToInt32(juce::String stringValue, int defaultValue)
  {
	  if (stringValue.isNotEmpty()) {
		  if (!stringValue.containsIgnoreCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
			  int int_val = stringValue.getIntValue();

			  return int_val;
		  }
	  }

	  return defaultValue;
  }

  float imbSynthTools::ProcessValue(float _value, imbControlParameterType TP)
  {
	  
		  switch (TP) {
		  case imbControlParameterType::Boolean:
			  return _value ? 1.0f : 0.0f;
			  break;
		  default:
			  return _value;
			  break;
		  }

	  
  }

