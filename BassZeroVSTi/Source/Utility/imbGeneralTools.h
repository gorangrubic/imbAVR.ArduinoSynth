/*
  ==============================================================================

    imbGeneralTools.h
    Created: 22 Oct 2019 6:28:28pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <string>

class imbGeneralTools {


	public:

		/* returns random string*/
		static std::string GetRandomString(int numberOfChars);

		/* makes color from Boris >:) */
		static Colour ColorFromHex(String hexCode);


		/* makes color from Boris >:) */
		static Colour ColorFromHex(std::string hexCode);

};