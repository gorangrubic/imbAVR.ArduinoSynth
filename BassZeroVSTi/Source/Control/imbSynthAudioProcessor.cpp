#include "imbSynthAudioProcessor.h"



AudioProcessorValueTreeState::ParameterLayout imbSynthAudioProcessor::CreateParameterLayout()
{
	std::vector<std::unique_ptr<AudioParameterInt>> params;

	params.push_back(std::make_unique<AudioParameterInt>("ParA", "Par", 0,255,127));

	
	return { params.begin(), params.end() };


}

imbSynthAudioProcessor::imbSynthAudioProcessor() : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
	.withInput("Input", AudioChannelSet::stereo(), true)
#endif
	.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
),
parameters (*this, nullptr, "PARAMETERS", this->CreateParameterLayout())
{

}


imbSynthAudioProcessor::~imbSynthAudioProcessor()
{
}
