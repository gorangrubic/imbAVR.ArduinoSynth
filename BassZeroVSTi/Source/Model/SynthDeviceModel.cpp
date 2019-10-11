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

	  // ========================== populates list of sources ===========
	  for each (auto var in modulations.ADSRs)
	  {

		  PARAMCONTROL.ListOfSources.Add(var->ShortName);
	  }

	  for each (auto var in modulations.ENVs)
	  {
		  PARAMCONTROL.ListOfSources.Add(var->ShortName);
		  //ModelConstructionTools::parameterController.ListOfSources.Add(var->ShortName);
	  }

	  for each (auto var in modulations.LFOs)
	  {
		  PARAMCONTROL.ListOfSources.Add(var->ShortName);
		  //	ModelConstructionTools::parameterController.ListOfSources.Add(var->ShortName);
	  }

	  for each (auto var in modulations.MacroControls)
	  {
		  PARAMCONTROL.ListOfSources.Add(var->ShortName);
		  //	ModelConstructionTools::parameterController.ListOfSources.Add(var->ShortName);
	  }

	  for each (auto var in modulations.MIDIs)
	  {
		  PARAMCONTROL.ListOfSources.Add(var->ShortName);
		  //	ModelConstructionTools::parameterController.ListOfSources.Add(var->ShortName);
	  }


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

	  // ==== registrating units and links
	  for each (auto var in OPMCONTROL Units)
	  {
		  CONTROLLER ListOfSignalUnits.Add(var->ShortName);
	  }

	  // ===== links

	  for each (auto var in OPMCONTROL Links)
	  {
		  CONTROLLER ListOfMacroLinks.Add(var->ShortName);
	  }


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

  //SynthDeviceModel::SynthDeviceModel()
  //{
	 // 

  //}
