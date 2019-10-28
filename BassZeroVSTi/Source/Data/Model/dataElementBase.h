/*
  ==============================================================================

    dataElementBase.h
    Created: 23 Oct 2019 4:22:46am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Utility/imbGeneralTools.h"

class dataElementBase {


protected:

	

public:

	parameterValueType valueType = parameterValueType::Float;

	/* if the element contains other elements */
	dataElementFeatures::features features;

	parameterClass parClass = parameterClass::ccLive;

	virtual int GetCheckSum(bool forValue = true, bool forStructure = false) = 0;

	/* custom pseudo class id */
	std::string elementClassRole = "";
	std::string editorOfPreferenceDefault = "";
	std::string editorOfPreference = "";

	std::string GetEditorOfPreference() {

		if (editorOfPreference.empty()) {

			if (editorOfPreferenceDefault.empty()) {
				editorOfPreferenceDefault = dataObjectPropertyEnumerations::GetDefaultEditorOfPreference(valueType);
			}

			return editorOfPreferenceDefault;
		}

		return editorOfPreference;
	}

	/* Color-code */
	std::string entryColorHex;
	Colour GetEntryColor();

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

	std::string GetPrefix(std::string parentPathPrefix = "");
	std::string GetParameterPath(std::shared_ptr<dataElementBase> var, std::string prefix);

	/// <summary>
/// Sets additional information on this parameter
/// </summary>
/// <param name="_parameterHelp">The parameter help.</param>
/// <param name="_parameterHelpUrl">The parameter help URL.</param>
/// <param name="_parameterUnit">The parameter unit.</param>
	void SetHelp(std::string _parameterHelp, std::string _parameterHelpUrl = "", std::string _parameterUnit = "");

	dataElementBase(std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none) {

		features |= dataElementFeatures::_features::doAllowCopyPaste;
		
		
		parClass = _parClass;
		features |= _features;

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