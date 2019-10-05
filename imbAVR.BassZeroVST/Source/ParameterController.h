#pragma once
/// <summary>
/// Manages all synth parameters, assigns ccID to imbControlParameters
/// </summary>
class ParameterController
{

	
public:

	unsigned int PageSize = 47;
	unsigned int PageColumnCount = 8;
	unsigned int StartingCCID = 10;
	unsigned int RowCCIDSpan = 8;
	//unsigned int CurrentCCID = 10;


	unsigned int CurrentColumn = 1;
	unsigned int CurrentPage = 0;

	/// <summary>
	/// Gets the knob ccid.
	/// </summary>
	/// <param name="_row">The row - from bottom to top.</param>
	/// <param name="_page">The page - page index. Leave -1 to use current page index</param>
	/// <param name="_column">The column - from left to right. Leave -1 to use current column index</param>
	/// <returns></returns>
	unsigned int GetKnobCCID(int _row, int _page = -1, int _column = -1);

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


	ParameterController();
	~ParameterController();
};

