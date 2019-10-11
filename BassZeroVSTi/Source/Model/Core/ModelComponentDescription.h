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
    	    String NamePrefix;
            String ShortName;
	        String LongName;

			/// <summary>
/// The parameter controller - machanism for CC / SysExc ID synthnronization
/// </summary>
			ParameterController * parameterControllerPtr;
	        
			void SetDescription(String _shortName, String _longName, ParameterController * _parameterControllerPtr);

	        ModelComponentDescription();

};