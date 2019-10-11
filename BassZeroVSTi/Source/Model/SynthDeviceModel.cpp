/*
  ==============================================================================

    SynthDeviceModel.cpp
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModel.h"

  void SynthDeviceModel::PreDeployModel()
  {
	  //modulations.model = this;
	  //modulations.parameterControllerPtr = &this->parameterController;

	  modulations.SetParent(this, this);
	  components.SetParent(this, this);
	  opmControl.SetParent(this, this);

	  modulations.SetDescription("MOD", "Modulation sources", &this->parameterController);
	  components.SetDescription("MAIN", "Main components", &this->parameterController);
	  opmControl.SetDescription("OPM", "Operation Mode control", &this->parameterController);
  }

  void SynthDeviceModel::AfterDeployModel()
  {


	
  }

  void SynthDeviceModel::Deploy()
  {
  }

  SynthDeviceModel::SynthDeviceModel()
  {
	  

  }
