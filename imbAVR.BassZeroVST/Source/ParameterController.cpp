#include "ParameterController.h"




unsigned int ParameterController::GetKnobCCID(int _row, int _page, int _column)
{
	if (_column == -1) _column = CurrentColumn;
	if (_page == -1) _page = CurrentPage;

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

ParameterController::ParameterController()
{
}


ParameterController::~ParameterController()
{
}
