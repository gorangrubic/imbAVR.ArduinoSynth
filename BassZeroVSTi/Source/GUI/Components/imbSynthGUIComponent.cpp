#include "imbSynthGUIComponent.h"



void imbSynthGUIComponent::SetEnabled(bool _enabled, bool _error)
{
	isInErrorState = _error;
	
	component->setEnabled(!_error);
	
	if (_enabled) {
		component->setAlpha(1.0f);
	}
	else {
		component->setAlpha(0.5f);
	}
}

imbSynthGUIComponent::imbSynthGUIComponent()
{
}

//
//imbSynthGUIComponent::imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix)
//{
//	NameSuffix = nameSufix;
//	state = std::shared_ptr<imbSynthStateData>(synthState);
//}

imbSynthGUIComponent::~imbSynthGUIComponent()
{
}

