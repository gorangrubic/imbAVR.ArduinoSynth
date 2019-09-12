#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define COMMAND_HOMEVIEW 1
#define COMMAND_PREVVIEW 2
#define COMMAND_NEXTVIEW 3
#define COMMAND_AUTOVIEW 4

#define COMMAND_VIEWCMD_A 5
#define COMMAND_VIEWCMD_B 6
#define COMMAND_VIEWCMD_C 7
#define COMMAND_VIEWCMD_D 8


class GuiScreenControl
{
protected:
	byte currentView = 0;


	void SetFirstCall(bool value);



	void SetBlinkState(bool value);

public:
	void ToggleAutoviewChange();

	byte GetCurrentViewID();

	int GetAutoviewChange();

	byte nViews = 8;

	//byte ActiveViews = nViews;

	byte command = 0;


	// xxxx xxx1 - is first call
	// xxxx xx1x - is auto view change on
	// xxxx x1xx - is blink state on
	byte state = B00000000;


	void SetAutoviewChange(bool value);


	/* Moves current view to next */
	void nextView();

	/* Moves current view to previous */
	void prevView();

	/* Moves current view to 0 */
	void homeView();

	/* Sets current view to specified */
	void setView(byte view_id);


	void ProcessCommand();

	//virtual void RenderScreen(GuiScreen * Screen, ACEMegaHostTFTClass * Display) = 0;

public:
	GuiScreenControl();
	~GuiScreenControl();
};

