#include "imbSynthGUIComponent.h"



imbSynthGUIComponent::imbSynthGUIComponent()
{
}


imbSynthGUIComponent::imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix)
{
	NameSuffix = nameSufix;
	state = std::shared_ptr<imbSynthStateData>(synthState);
}

imbSynthGUIComponent::~imbSynthGUIComponent()
{
}

