/*
  ==============================================================================

    BassZeroSynthModel.cpp
    Created: 4 Oct 2019 10:12:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "BassZeroSynthModel.h"

void BassZeroSynthModel::DeployModel(imbSynthAudioProcessor * synthProcessor)
{
	SynthProcessor = synthProcessor;

	ADSR_A = modulations.AddADSR();
	ADSR_B = modulations.AddADSR();

	ENV_A = modulations.AddENV();
	ENV_B = modulations.AddENV();
	ENV_C = modulations.AddENV();

	LFO_A = modulations.AddLFO();
	LFO_B = modulations.AddLFO();
	LFO_C = modulations.AddLFO();
	LFO_D = modulations.AddLFO();
	
}

BassZeroSynthModel::BassZeroSynthModel():SynthDeviceModel("BassZero", "hardy.Veles::BassZero VSTi")
{

}
