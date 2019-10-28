/*
  ==============================================================================

    UserInterfaceManager.h
    Created: 27 Oct 2019 1:40:07am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/Header.h"

class UserInterfaceManager : public
{

public:

	/* Displays message box. Returns 0 if Cancel selected, 1 if ok */
	static bool openObjectEditor(dataObject & target, std::string title, std::string message, std::string okButtonText = "", std::string cancelButtonText = "", AlertWindow::AlertIconType icon = AlertWindow::InfoIcon)
	{


		AlertWindow w(title,
			message,
			icon);

		if (okButtonText.empty()) okButtonText = "Close";

		if (!okButtonText.empty()) w.addButton(okButtonText, 1, KeyPress(KeyPress::returnKey, 0, 0));
		if (!cancelButtonText.empty()) w.addButton(cancelButtonText, 0, KeyPress(KeyPress::escapeKey, 0, 0));

		w.addCustomComponent()
		return w.runModalLoop();

	}


	
};