/*
  ==============================================================================

    PitchAndPhaseControl.cpp
    Created: 15 Oct 2019 2:35:07am
    Author:  gorangrubic

  ==============================================================================
*/

#include "PitchAndPhaseControl.h"

void PitchAndPhaseControl::Deploy(ParameterController & parameterController)
  {

	AddCCParameter(parameterController, &Pitch, "Pitch", "Pitch offset", 0, -64, 64);
	AddCCParameter(parameterController, &Phase, "Phase", "Phase offset", 0, 0, 127);
  }

  PitchAndPhaseControl::PitchAndPhaseControl()
  {
  }
