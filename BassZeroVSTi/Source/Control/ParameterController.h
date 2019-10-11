#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "imbControlParameterEnumerations.h"
#include "imbEnumerationList.h"

/// <summary>
/// Manages all synth parameters, assigns ccID to imbControlParameters
/// </summary>
class ParameterController
{

	
public:

	juce::AudioProcessorValueTreeState * parameters;

	imbEnumerationList ListOfPitchUnits;
	imbEnumerationList ListOfModulationModes;
	imbEnumerationList ListOfModulationFunctions;
	imbEnumerationList ListOfModulationParameters;

	imbEnumerationList ListOfSignalUnits;

	imbEnumerationList ListOfMacroLinks;

	imbEnumerationList ListOfSources;

	imbEnumerationList ListOfLFOFunctions;


	unsigned int PageSize = 47;
	unsigned int PageColumnCount = 8;
	unsigned int StartingCCID = 10;
	unsigned int RowCCIDSpan = 8;
	unsigned int RowInColumnCount = 3;
	//unsigned int CurrentCCID = 10;


	unsigned int CurrentColumn = 1;
	unsigned int CurrentPage = 0;
	unsigned int CurrentRow = 0;

	void Setup(juce::AudioProcessorValueTreeState * _parameters);
	
	/// <summary>
	/// Gets proper next identifier, according to given message type.
	/// </summary>
	/// <param name="_msgFormat">The MSG format.</param>
	/// <returns></returns>
	unsigned int GetProperID(imbControlParameterMessageType _msgFormat);

	
	unsigned int CurrentSysExclusinveID = 0;

	unsigned int GetSystemExclusiveID();



	/// <summary>
	/// Gets the knob ccid.
	/// </summary>
	/// <param name="_row">The row - from bottom to top.</param>
	/// <param name="_page">The page - page index. Leave -1 to use current page index</param>
	/// <param name="_column">The column - from left to right. Leave -1 to use current column index</param>
	/// <returns></returns>
	unsigned int GetKnobCCID(int _row=-1, int _page = -1, int _column = -1);

	/// <summary>
	/// Moves CurrentColumn and (optionally) CurrentPage to specified index value(s)
	/// </summary>
	/// <param name="_column">The column index to set</param>
	/// <param name="_page">The page index to set. Leave -1 to keep current page index.</param>
	void MoveTo(int _column=-1, int _page = -1);

	/// <summary>
	/// Moves to next column (CurrentColumn++) and next page if current column reached PageColumnCount
	/// </summary>
	/// <returns>true if CurrentPage is changed</returns>
	bool NextColumn();

	bool Next();

	ParameterController();
	~ParameterController();
};

