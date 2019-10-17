#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/imbSynthStateData.h"

#define GUIREFRESH_TIMEINTERVAL 250

class imbSynthGUIComponent
{
	public:

	String NameSuffix;
	

	std::shared_ptr<imbSynthStateData> state;

	/* Tells if GUI components are updated by internal source, not user or parameters */
	bool isValueUpdateCall;

	bool blockRefresh;

	/// <summary>
	/// Declares plugin parameters 
	/// </summary>
	/// <param name="params">The parameters.</param>
//	virtual void ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params);

	imbSynthGUIComponent();
	imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix);
	~imbSynthGUIComponent();
};

