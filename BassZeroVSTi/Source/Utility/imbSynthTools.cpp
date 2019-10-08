/*
  ==============================================================================

    imbSynthTools.cpp
    Created: 8 Oct 2019 1:59:00am
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbSynthTools.h"

String imbSynthTools::GetLetter(unsigned int input) {
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
