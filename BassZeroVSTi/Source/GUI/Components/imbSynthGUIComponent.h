#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/imbSynthStateData.h"


class imbSynthGUIComponent
{
public:
	String NameSuffix;
	imbSynthStateData * SynthState;	

	/// <summary>
	/// Declares plugin parameters 
	/// </summary>
	/// <param name="params">The parameters.</param>
	virtual void ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params);

	imbSynthGUIComponent();
	imbSynthGUIComponent(imbSynthStateData * synthState, String nameSufix);
	~imbSynthGUIComponent();
};

