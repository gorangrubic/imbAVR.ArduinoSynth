#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/imbSynthStateData.h"

#define GUIREFRESH_TIMEINTERVAL 250

class imbSynthGUIComponent
{
	public:

	std::string NameSuffix;

	bool isInErrorState = false;
	
	void SetEnabled(bool _enabled, bool _error);

	std::shared_ptr<imbSynthStateData> state;
	std::shared_ptr<Component> component;

	void Deploy(std::string _nameSuffix, Component * _component, imbSynthStateData * _state )
	{
		component = std::shared_ptr<Component>(_component);
		state = std::shared_ptr<imbSynthStateData>(_state);
		
		NameSuffix = _nameSuffix;
	}
	
	/* Tells if GUI components are updated by internal source, not user or parameters */
	bool isValueUpdateCall;

	bool blockRefresh;

	/// <summary>
	/// Declares plugin parameters 
	/// </summary>
	/// <param name="params">The parameters.</param>
//	virtual void ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params);

	imbSynthGUIComponent();
	//imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix);
	~imbSynthGUIComponent();
};

