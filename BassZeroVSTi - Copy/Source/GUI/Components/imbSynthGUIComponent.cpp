#include "imbSynthGUIComponent.h"



imbSynthGUIComponent::imbSynthGUIComponent()
{
}


imbSynthGUIComponent::imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix)
{
	NameSuffix = nameSufix;
	SynthState = synthState;
}

imbSynthGUIComponent::~imbSynthGUIComponent()
{
}
