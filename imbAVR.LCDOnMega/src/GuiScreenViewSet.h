// GuiScreenViewSet.h

#ifndef _GUISCREENVIEWSET_h
#define _GUISCREENVIEWSET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <GuiScreenView.h>


class GuiScreenViewSet {

public:

	GuiScreen * Screen;



	GuiScreenViewSet(GuiScreen * screen);

	byte ActiveViews = 0;

	GuiScreenView Views[8];

	GuiScreenView CreateView();

	bool isFirstCall;

	byte CurrentView = 0;
	byte LastViewID = 255;

	void UpdateScreen(byte view_id, ACEMegaHostTFTClass * Display);
};

#endif

