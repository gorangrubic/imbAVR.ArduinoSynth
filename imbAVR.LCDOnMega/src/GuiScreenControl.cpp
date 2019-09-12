#include "GuiScreenControl.h"



GuiScreenControl::GuiScreenControl()
{
}


GuiScreenControl::~GuiScreenControl()
{
}



void GuiScreenControl::SetFirstCall(bool value)
{
	if (value) {
		bitWrite(state, 0, 1);
	}
	else {
		bitWrite(state, 0, 0);
	}
}


void GuiScreenControl::ToggleAutoviewChange()
{
	if (bitRead(state, 1) == 0) {
		bitWrite(state, 1, 1);
	}
	else {
		bitWrite(state, 1, 0);
	}


}


byte GuiScreenControl::GetCurrentViewID()
{
	return currentView;
}


int GuiScreenControl::GetAutoviewChange()
{
	return bitRead(state, 1);
}


void GuiScreenControl::SetAutoviewChange(bool value)
{
	if (value) {
		bitWrite(state, 1, 1);
	}
	else {
		bitWrite(state, 1, 0);
	}
}


void GuiScreenControl::SetBlinkState(bool value)
{
	if (value) {
		bitWrite(state, 2, 1);
	}
	else {
		bitWrite(state, 2, 0);
	}
}


void GuiScreenControl::nextView()
{
	currentView++;

	if (currentView > nViews) {
		currentView = 0;
	}
	
	SetFirstCall(true);
}


void GuiScreenControl::prevView()
{
	currentView--;
	if (currentView < 0) {
		currentView = nViews;
	}
	
	SetFirstCall(true);
}


void GuiScreenControl::homeView()
{
	if (currentView != 0) SetFirstCall(true);
	currentView = 0;
}


void GuiScreenControl::setView(byte view_id)
{
	view_id = constrain(view_id, 0, nViews - 1);
	if (currentView != view_id) SetFirstCall(true);
	currentView = view_id;
}

void GuiScreenControl::ProcessCommand()
{

	switch (command)
	{
	case COMMAND_AUTOVIEW:
		ToggleAutoviewChange();
		command = 0;
		break;
	case COMMAND_HOMEVIEW:
		homeView();
		command = 0;
		break;
	case COMMAND_NEXTVIEW:
		nextView();
		command = 0;
		break;
	case COMMAND_PREVVIEW:
		prevView();
		command = 0;
		break;
	default:
		break;
	}
}

