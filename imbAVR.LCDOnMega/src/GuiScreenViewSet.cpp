// 
// 
// 

#include "GuiScreenViewSet.h"



GuiScreenView GuiScreenViewSet::CreateView()
{
	ActiveViews++;
	return Views[ActiveViews-1];
}

GuiScreenViewSet::GuiScreenViewSet(GuiScreen * screen)
{

	Screen = screen;

	for (size_t i = 0; i < 8; i++)
	{
		Views[i].uid = i;
		Views[i].Screen = screen;
	}

}

void GuiScreenViewSet::UpdateScreen(byte view_id, ACEMegaHostTFTClass * Display)
{

	Display->setCursor(0, 0);

	view_id = constrain(view_id, 0, ActiveViews);

	bool firstCall = false;
	
	if (view_id != LastViewID) {
		Display->redrawScheduled = true; firstCall = true;
	}

	GuiScreenView * view = &Views[view_id];

	if (firstCall) {

		Display->fillScreen(GLCD_CL_BLACK);
		Display->setCursor(0, 0);
		
		view->PrintLabels(Display);

		
	}

	LastViewID = view_id;

	view->UpdateFields(Display);

	Display->redrawScheduled = false;

}