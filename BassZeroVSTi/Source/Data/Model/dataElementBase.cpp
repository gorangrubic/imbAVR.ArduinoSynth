/*
  ==============================================================================

    dataElementBase.cpp
    Created: 23 Oct 2019 4:22:46am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataElementBase.h"


Colour dataElementBase::GetEntryColor()
  {
	if (!entryColorHex.empty()) {
		return imbGeneralTools::ColorFromHex(entryColorHex);
	} else
	{
		return imbGeneralTools::ColorFromHex(String("#00000000"));
	}
  }

  void dataElementBase::SetHelp(std::string _parameterHelp, std::string _parameterHelpUrl, std::string _parameterUnit)
  {
	if (!_parameterHelp.empty()) parameterHelp = _parameterHelp;
	if (!_parameterHelpUrl.empty()) parameterHelpUrl = _parameterHelpUrl;
	if (!_parameterUnit.empty()) parameterUnit = _parameterUnit;
  }
