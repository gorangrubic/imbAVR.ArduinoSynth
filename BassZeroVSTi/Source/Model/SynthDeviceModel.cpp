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
	  /*
	  modulations = std::make_unique<ModulationHub>(new  ModulationHub());
	  components = std::make_unique<ComponentHub>(new ComponentHub());
	  opmControl = std::make_unique<OPMControlModel>(new OPMControlModel());
	  */
	  //modulations = std::unique_ptr<ModulationHub>(); //  std::make_unique<ModulationHub>();
	  //components = std::unique_ptr<ComponentHub>();
	  //opmControl = std::unique_ptr<OPMControlModel>();

	  this->parameterController = ParameterController();
	  

	  //MODULATIONS SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));
	  //COMPONENTS SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));
	  //OPMCONTROL SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));

	  parameterControllerPtr = std::make_shared<ParameterController>(this->parameterController);

	  MODULATIONS SetDescription(MODHUB_ID, MODHUB_LABEL, parameterControllerPtr);
	  COMPONENTS SetDescription(COMP_ID, COMP_LABEL, parameterControllerPtr);
	  OPMCONTROL SetDescription(OPM_ID, OPM_LABEL, parameterControllerPtr);
  }

  void SynthDeviceModel::AfterDeployModel()
  {

	  MODULATIONS Deploy();
	  OPMCONTROL Deploy();
	  COMPONENTS Deploy();
	  
	
  }

  /* MAIN DEPLOY function too call. Executes: PreDeploy, DeployModel and AfterDeploy*/
  void SynthDeviceModel::Deploy()
  {

	  PreDeployModel();
	  DeployModel();
	  AfterDeployModel();

  }

  void SynthDeviceModel::ConstructParameters(juce::AudioProcessorValueTreeState * parameters, AudioProcessor * processor)
  {
	  parameterController.Setup(parameters, processor);

	  MODULATIONS ConstructComponentAndChildComponentParameters();
	  OPMCONTROL ConstructComponentAndChildComponentParameters();
	  COMPONENTS ConstructComponentAndChildComponentParameters();
	  


  }

  //SynthDeviceModel::SynthDeviceModel()
  //{
	 // 

  //}
