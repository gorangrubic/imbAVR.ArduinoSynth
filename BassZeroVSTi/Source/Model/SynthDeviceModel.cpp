/*
  ==============================================================================

    SynthDeviceModel.cpp
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModel.h"

#define PARAMCONTROL parameterController
#define CONTROLLER  parameterController.

// modelConstructionTools.parameterController.
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
	  

	  //parameterController.Reset();
	  
	  //modulations = ModulationHub();
	  //components = ComponentHub();
	  //opmControl = OPMControlModel();

	  //MODULATIONS SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));
	  //COMPONENTS SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));
	  //OPMCONTROL SetParent(std::shared_ptr<SynthDeviceModelComponentBase>(this), std::shared_ptr<ModelComponentWithChildren>(this));
	 /* parameterUnique = std::make_unique<ParameterController>(parameterController);
	  parameterUnique->Reset();*/

	 // auto s = std::shared_ptr<ParameterController>(&parameterController);

	//  parameterControllerPtr = s;

	//  ModelComponentDescription::parameterControllerPtr.swap(s);
	  //modulations.parameterControllerPtr.reset(std::shared_ptr<ParameterController>(&parameterController));

	//  MODULATIONS SetDescription("", ""); // , std::shared_ptr<ParameterController>(&parameterController));
	//  COMPONENTS SetDescription("", ""); // std::shared_ptr<ParameterController>(&parameterController));
	//  OPMCONTROL SetDescription("", ""); //, std::shared_ptr<ParameterController>(&parameterController));
  }

  void SynthDeviceModel::AfterDeployModel()
  {

	 


	  PARAMCONTROL.ListOfModulationFunctions.Add("One-shot");
	  PARAMCONTROL.ListOfModulationFunctions.Add("Loop");
	  CONTROLLER ListOfModulationFunctions.Add("Mirror");
	  CONTROLLER ListOfModulationFunctions.Add("Continual");

	  CONTROLLER ListOfPitchUnits.Add("Semitones");
	  CONTROLLER ListOfPitchUnits.Add("Octaves");
	  CONTROLLER ListOfPitchUnits.Add("1 Hz");
	  CONTROLLER ListOfPitchUnits.Add("10 Hz");
	  CONTROLLER ListOfPitchUnits.Add("100 Hz");
	  CONTROLLER ListOfPitchUnits.Add("500 Hz");
	  CONTROLLER ListOfPitchUnits.Add("1000 Hz");
	  CONTROLLER ListOfPitchUnits.Add("2000 Hz");

	  CONTROLLER ListOfModulationParameters.Add("OFF");
	  CONTROLLER ListOfModulationParameters.Add("Rate");
	  CONTROLLER ListOfModulationParameters.Add("Period");
	  CONTROLLER ListOfModulationParameters.Add("Change");

	  CONTROLLER ListOfModulationModes.Add("OFF");
	  CONTROLLER ListOfModulationModes.Add("Pitch");
	  CONTROLLER ListOfModulationModes.Add("PWM");
	  CONTROLLER ListOfModulationModes.Add("Phase");

	  CONTROLLER ListOfLFOFunctions.Add("Triangle");
	  CONTROLLER ListOfLFOFunctions.Add("Ramp Down");
	  CONTROLLER ListOfLFOFunctions.Add("Ramp Up");
	  CONTROLLER ListOfLFOFunctions.Add("Square Pulse");
	  CONTROLLER ListOfLFOFunctions.Add("Sinewave");
	  CONTROLLER ListOfLFOFunctions.Add("Chaos");
	  

		  
		  
		  
		  
		  
		  
	 

		MODULATIONS Deploy(parameterController);
		OPMCONTROL Deploy(parameterController);
		COMPONENTS Deploy(parameterController);
	  
	
  }

  /* MAIN DEPLOY function too call. Executes: PreDeploy, DeployModel and AfterDeploy*/
  void SynthDeviceModel::Deploy()
  {



  }

  void SynthDeviceModel::ConstructParameters(juce::AudioProcessorValueTreeState & parameters)
  {
	 // CONTROLLER Setup(parameters);
	 // modelConstructionTools.parameterController.Setup(parameters, processor);
	  //parameterController.Setup(parameters, processor);

	  MODULATIONS ConstructComponentAndChildComponentParameters(parameterController, parameters);
	  OPMCONTROL ConstructComponentAndChildComponentParameters( parameterController, parameters);
	  COMPONENTS ConstructComponentAndChildComponentParameters(parameterController, parameters);
	  
	  parameters.state = ValueTree("BassZero");

  }

  void SynthDeviceModel::CollectAllParameters(SharedPointerVector<imbControlParameter>& parameters)
  {
	  components.CollectAllParameterDefinitions(parameters);
	  opmControl.CollectAllParameterDefinitions(parameters);
	  modulations.CollectAllParameterDefinitions(parameters);

  }



  void SynthDeviceModel::AddGroup(ControlGroup * output, std::string _shortName, std::string _longName, ControlGroup * group)
  {
	  output->ShortName = _shortName;
	  output->LongName = _longName;
	  Groups.Add(output);
  }

  //SynthDeviceModel::SynthDeviceModel()
  //{
	 // 

  //}
