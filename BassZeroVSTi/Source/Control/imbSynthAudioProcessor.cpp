#include "imbSynthAudioProcessor.h"



void imbSynthAudioProcessor::DeployModel()
{
	model->Deploy();

	model->PreDeployModel();
	model->DeployModel();
	model->AfterDeployModel();

//	model->DeployModel();


	model->ConstructParameters(parameters);
}

//AudioProcessorValueTreeState::ParameterLayout imbSynthAudioProcessor::CreateParameterLayout()
//{
//	model->Deploy();
//
//	model->DeployModel();
//	
//	model->ConstructParameters(&parameters);
//
//	//params.push_back(std::make_unique<AudioParameterInt>("ParA", "Par", 0,255,127));
//	//AudioProcessorValueTreeState::ParameterLayout layout = AudioProcessorValueTreeState::ParameterLayout();
//	//layout.add({ model->parameterControllerPtr->params.begin(),  model->parameterControllerPtr->params.end() });
//
//	
//	return { model->parameterControllerPtr->params.begin(),  model->parameterControllerPtr->params.end() };
//
//
//}

void imbSynthAudioProcessor::audioProcessorParameterChanged(AudioProcessor * processor, int parameterIndex, float newValue)
{
}

void imbSynthAudioProcessor::audioProcessorParameterChangeGestureEnd(AudioProcessor * processor, int parameterIndex)
{
}

void imbSynthAudioProcessor::audioProcessorChanged(AudioProcessor * processor)
{
}

//imbSynthAudioProcessor::imbSynthAudioProcessor() : AudioProcessor(BusesProperties()
//#if ! JucePlugin_IsMidiEffect
//#if ! JucePlugin_IsSynth
//	.withInput("Input", AudioChannelSet::stereo(), true)
//#endif
//	.withOutput("Output", AudioChannelSet::stereo(), true)
//#endif
//),
//parameters (*this, nullptr, "PARAMETERS", this->CreateParameterLayout())
//{
//
//}


imbSynthAudioProcessor::~imbSynthAudioProcessor()
{
}
