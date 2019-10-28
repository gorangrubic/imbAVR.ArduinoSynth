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

  std::string dataElementBase::GetPrefix(std::string parentPathPrefix)
  {
	  return std::string();
  }

  std::string dataElementBase::GetParameterPath(std::shared_ptr<dataElementBase> var, std::string prefix)
  {
	  return std::string();
  }

  void dataElementBase::SetHelp(std::string _parameterHelp, std::string _parameterHelpUrl, std::string _parameterUnit)
  {
	if (!_parameterHelp.empty()) parameterHelp = _parameterHelp;
	if (!_parameterHelpUrl.empty()) parameterHelpUrl = _parameterHelpUrl;
	if (!_parameterUnit.empty()) parameterUnit = _parameterUnit;
  }


  std::string dataElementBase::GetPrefix(std::string parentPathPrefix)
  {
	  if (!parameterIDPath.empty()) return parameterIDPath;

	  std::string prefix = parameterID;
	  if (!parentPathPrefix.empty()) {
		  if (!parameterID.empty()) {
			  prefix = parentPathPrefix + "." + parameterID;
		  }
		  else {
			  prefix = parentPathPrefix;
		  }
	  }
	  return prefix;
  }

  std::string dataElementBase::GetParameterPath(std::shared_ptr<dataElementBase> var, std::string prefix)
  {
	  std::string p = "";
	  if (prefix.empty()) {
		  p = var->parameterID;
	  }
	  else {
		  p = prefix + "." + var->parameterID;
	  }
	  return p;
  }
