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

#define STRLEN 127
class ModelComponentDescription {
 
    public:

		juce::String NamePrefix { juce::String("", STRLEN) };
		juce::String ShortName { juce::String("", STRLEN) };
		juce::String LongName { juce::String("", STRLEN) };
		juce::String GroupName { juce::String("", STRLEN) };

			//String ParentPath;

			//virtual void SetParentPath(String _parentPath) = 0;

			

			//void SetDescription(std::string _shortName, std::string _longName, std::shared_ptr<ParameterController> _parameterControllerPtr);

			void SetDescription(std::string _shortName, std::string _longName); //, std::shared_ptr<ParameterController> _parameterControllerPtr);

			//void SetDescription(std::string _shortName, std::string _longName, ParameterController* _parameterController);

			ModelComponentDescription(std::string _namePrefix="", std::string _shortName="", std::string _longName="")
			{
				if (_namePrefix != "") NamePrefix = juce::String(_namePrefix);
				if (_shortName != "") ShortName = juce::String(_shortName);
				if (_longName != "") LongName = juce::String(_longName);
				
			};

};