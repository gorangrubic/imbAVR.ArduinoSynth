/*
  ==============================================================================

    imbSynthParameterEditor.h
    Created: 16 Oct 2019 11:14:40pm
    Author:  gorangrubic

  ==============================================================================
*/
#pragma once
#include "../../../JuceLibraryCode/JuceHeader.h"
/* custom editor for imbControlParameter */
class imbSynthParameterEditor {
 
    	
	public:
	
		virtual void SetValue(float value) = 0;
		virtual float GetValue() = 0;

		//==============================================================================
		/** You can assign a lambda to this callback object to have it called when the slider value is changed. */
		std::function<void()> onValueChange;
		
};