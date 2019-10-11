/*
  ==============================================================================

    ModelComponentDescription.h
    Created: 8 Oct 2019 5:36:31am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/ParameterController.h"

class ModelComponentDescription {
 
    public:

		juce::String NamePrefix = juce::String();
		juce::String ShortName = juce::String();
		juce::String LongName = juce::String();

			//String ParentPath;

			//virtual void SetParentPath(String _parentPath) = 0;

			/// <summary>
			/// The parameter controller - machanism for CC / SysExc ID synthnronization
			/// </summary>
			std::shared_ptr<ParameterController> parameterControllerPtr = nullptr;
	        
			void SetDescription(juce::String _shortName, juce::String _longName, std::shared_ptr<ParameterController> _parameterControllerPtr);

			ModelComponentDescription():
				NamePrefix{ "" }, ShortName{ "" }, LongName{ "" } 
			{
			
			};

};