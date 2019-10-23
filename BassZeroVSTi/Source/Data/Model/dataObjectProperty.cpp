/*
  ==============================================================================

    dataObjectProperty.cpp
    Created: 22 Oct 2019 9:05:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataObjectProperty.h"



  void dataObjectProperty::updateAll()
  {
	  updateGUI();
	  updateTooltip();
  }

  bool dataObjectProperty::SetValue(float _newValue)
  {
	  return setValue(_newValue);
  }






