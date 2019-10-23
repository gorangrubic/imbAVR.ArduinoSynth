/*
  ==============================================================================

    dataElementBase.h
    Created: 23 Oct 2019 4:22:46am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class dataElementBase {

public:

	std::string parameterID = "";
	std::string parameterLabel = "";

	// ========================== VSTi parameters
/* Unique parameter ID that is used for ValueTree parameter ID and for storing parameters*/
	std::string parameterIDPath;

	/// <summary>
	/// Short help on this parameter
	/// </summary>
	std::string parameterHelp;

	/// <summary>
	/// URL with more information on the parameter
	/// </summary>
	std::string parameterHelpUrl;


	std::string parameterUnit;

	/// <summary>
	/// Error message
	/// </summary>
	std::string Error;

	/// <summary>
/// Sets additional information on this parameter
/// </summary>
/// <param name="_parameterHelp">The parameter help.</param>
/// <param name="_parameterHelpUrl">The parameter help URL.</param>
/// <param name="_parameterUnit">The parameter unit.</param>
	void SetHelp(std::string _parameterHelp, std::string _parameterHelpUrl = "", std::string _parameterUnit = "");

	dataElementBase(std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") {
		parameterID = _name;
		if (_label.empty()) {
			parameterLabel = parameterID;
		}
		else {
			parameterLabel = _label;
		}
		
		SetHelp(_description, _helpUrl, _unit);
	}
};