#ifndef _GUISCREENVIEWSET_h
#define _GUISCREENVIEWSET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <GuiScreenView.h>

template <byte nViews> class GuiScreenViewSet {

protected:
	byte currentView = 0;


	void SetFirstCall(bool value);



	void SetBlinkState(bool value);

public:
	void ToggleAutoviewChange();

	byte GetCurrentViewID();

	int GetAutoviewChange();

	GuiScreenViewSet();

	//byte ActiveViews = nViews;

	GuiScreenView Views[nViews];

	
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


	void RenderScreen(GuiScreen * Screen, ACEMegaHostTFTClass * Display);
};

//GuiScreenView GuiScreenViewSet::CreateView()
//{
//	ActiveViews++;
//	return Views[ActiveViews-1];
//}

template<byte nViews>
GuiScreenViewSet<nViews>::GuiScreenViewSet()
{
}

//template<byte nViews>
//GuiScreenViewSet<nViews>::GuiScreenViewSet(GuiScreen * _screen)
//{
//	Screen = Screen;
//
//	for (size_t i = 0; i < nViews; i++)
//	{
//		Views[i].uid = i;
//		Views[i].Screen = screen;
//	}
//}

template<byte nViews>
void GuiScreenViewSet<nViews>::SetFirstCall(bool value)
{
	if (value) {
		bitWrite(state, 0, 1);
	}
	else {
		bitWrite(state, 0, 0);
	}
}

template<byte nViews>
void GuiScreenViewSet<nViews>::ToggleAutoviewChange()
{
	if (bitRead(state, 1) == 0) {
		bitWrite(state, 1, 1);
	}
	else {
		bitWrite(state, 1, 0);
	}

	
}

template<byte nViews>
inline byte GuiScreenViewSet<nViews>::GetCurrentViewID()
{
	return currentView;
}

template<byte nViews>
inline int GuiScreenViewSet<nViews>::GetAutoviewChange()
{
	return bitRead(state, 1);
}

template<byte nViews>
void GuiScreenViewSet<nViews>::SetAutoviewChange(bool value)
{
	if (value) {
		bitWrite(state, 1, 1);
	}
	else {
		bitWrite(state, 1, 0);
	}
}

template<byte nViews>
void GuiScreenViewSet<nViews>::SetBlinkState(bool value)
{
	if (value) {
		bitWrite(state, 2, 1);
	}
	else {
		bitWrite(state, 2, 0);
	}
}

template<byte nViews>
void GuiScreenViewSet<nViews>::nextView()
{
	if (currentView == (nViews - 1)) {
		currentView = 0;
	}
	else {
		currentView++;
	}
	SetFirstCall(true);
}

template<byte nViews>
void GuiScreenViewSet<nViews>::prevView()
{
	if (currentView == 0) {
		currentView = nViews - 1;
	}
	else {
		currentView++;
	}
	SetFirstCall(true);
}

template<byte nViews>
void GuiScreenViewSet<nViews>::homeView()
{
	if (currentView != 0) SetFirstCall(true);
	currentView = 0;
}

template<byte nViews>
void GuiScreenViewSet<nViews>::setView(byte view_id)
{
	view_id = constrain(view_id, 0, nViews - 1);
	if (currentView != view_id) SetFirstCall(true);
	currentView = view_id;
}

template<byte nViews>
void GuiScreenViewSet<nViews>::RenderScreen(GuiScreen * Screen, ACEMegaHostTFTClass * Display)
{
	bool firstCall = ((state & B00000001) == B00000001);

	//GuiScreenView * view = &;

	//Display->print("Rendering ");
	//Display->println(currentView);
	//
	//Display->print("Active rows ");
	//Display->println(Views[currentView].ActiveRows);

	Views[currentView].Render(Screen, Display, state);

	SetFirstCall(false);
}

#endif