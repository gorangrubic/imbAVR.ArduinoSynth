#include "ParameterController.h"





void ParameterController::Setup(juce::AudioProcessorValueTreeState * _parameters)
{
	//parameters = std::make_shared<AudioProcessorValueTreeState>(_parameters);
//	processor = std::make_shared<imbSynthAudioProcessor>(_processor);
}
/// <summary>
/// Gets the proper identifier.
/// </summary>
/// <param name="_msgFormat">The MSG format.</param>
/// <returns></returns>
unsigned int ParameterController::GetProperID(imbControlParameterMessageType _msgFormat) {

	switch (_msgFormat) {
	case imbControlParameterMessageType::unspecified:
	case imbControlParameterMessageType::ccMIDI:
		return GetKnobCCID();
		break;
	case imbControlParameterMessageType::NoMIDI:
		return -1;
		break;
	case imbControlParameterMessageType::sysExMsg:
		return GetSystemExclusiveID();
		break;
	}

	return -1;
}

/// <summary>
/// Gets the next ID number for a system exclusive message, describing an OPM parameter.
/// </summary>
/// <returns></returns>
unsigned int ParameterController::GetSystemExclusiveID()
{
	unsigned int output = CurrentSysExclusinveID;
	CurrentSysExclusinveID++;
	return output;
}



unsigned int ParameterController::GetKnobCCID(int _row, int _page, int _column)
{
	if (_column == -1) _column = CurrentColumn;
	if (_page == -1) _page = CurrentPage;
	if (_row == -1) {
		_row = CurrentRow;
		Next();
	}

	unsigned int output = StartingCCID + (_page * PageSize) + _column + (_row * RowCCIDSpan);


	return output;
}

void ParameterController::MoveTo(int _column, int _page)
{
	if (_column > -1) CurrentColumn = _column;
	if (_page > -1) CurrentPage = _page;

}

bool ParameterController::NextColumn()
{
	CurrentColumn++;
	if (CurrentColumn > PageColumnCount) {
		CurrentPage++;
		CurrentColumn = 0;
		return true;
	}
	else {
		return false;
	}
}

bool ParameterController::Next()
{

	if (CurrentRow < RowInColumnCount) {
		CurrentRow++;
		return false;
	}
	else {
		CurrentRow = 0;
		NextColumn();
		return true;
	}
}
void ParameterController::Reset()
{
	/*ListOfLFOFunctions = imbEnumerationList();

	ListOfMacroLinks = imbEnumerationList();

	ListOfModulationFunctions = imbEnumerationList();

	ListOfModulationModes = imbEnumerationList();

	ListOfModulationParameters = imbEnumerationList();

	ListOfPitchUnits = imbEnumerationList();

	ListOfSignalUnits = imbEnumerationList();

	ListOfSources = imbEnumerationList();
*/

	CurrentColumn = 0U;

	CurrentPage = 0U;
	CurrentRow = 0U;
	CurrentSysExclusinveID = 0U;
	PageColumnCount = 8U;
	PageSize = 47U;
	RowCCIDSpan = 8U;
	RowInColumnCount = 3U;
	StartingCCID = 10U;
}
//
//ParameterController::ParameterController()
//
//{
//}


ParameterController::~ParameterController()
{
}

//void ParameterController::AddParam(AudioProcessorParameter * parameter, AudioProcessorParameterGroup * group)
//{
//
//	
//		group->addChild<AudioProcessorParameter>(parameter);
//
//		//group->addChild(parameter);
//		processor->addParameter(parameter);
//
//		//auto up = std::unique_ptr<AudioProcessorParameter>((AudioProcessorParameter *)parameter);
//		//
//		//AudioProcessorParameterGroup::AudioProcessorParameterNode node = AudioProcessorParameterGroup::AudioProcessorParameterNode(up, group);
//
//
//		//auto upn = std::unique_ptr<AudioProcessorParameterGroup::AudioProcessorParameterNode>(node);
//
//		////auto up = std::unique_ptr< AudioProcessorParameterGroup::AudioProcessorParameterNode>()
//		//
//		////std::unique_ptr<T> up = std::unique_ptr<T>((T*)parameter);
//		//////	parameters->processor.addParameter(parameter);
//
//		//params.push_back(upn);
//	
//}
