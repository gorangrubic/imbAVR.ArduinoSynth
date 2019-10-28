/*
  ==============================================================================

    imbSynthThemeBase.h
    Created: 28 Oct 2019 5:08:21am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Application/GeneralDefinitions.h"
#include "../Source/Utility/Header.h"

class imbSynthGridDefinition {

public:
	imbSynthColourPair GridColor = imbSynthColourPair("#ebebeb", "#dcdcdc", "#1f619e");

	float MajorGrid_Size = 10.0;
	float MidGrid_Size = 5.0;
	float MinorGrid_Size = 2.5;

	float MajorGrid_Alpha = 0.5;
	float MidGrid_Alpha = 0.25;
	float MinorGrid_Alpha = 0.1;

	bool showHorizontal = true;
	bool showVertical = true;
	bool showHorizontalRuler = true;
	bool showVerticalRuler = true;
	bool showHorizontalGuides = true;
	bool showVerticalGuides = true;
	bool showHorizontalCursorPosition = true;
	bool showVerticalCursorPosition = true;
};

class imbSynthColourPair {

public:
	Colour color_primar = imbGeneralTools::ColorFromHex(juce::String(IMBCOLOR_DARKGRAY));
	Colour color_secundar = imbGeneralTools::ColorFromHex(juce::String(IMBCOLOR_BLUE));
	Colour color_contrar = imbGeneralTools::ColorFromHex(juce::String(IMBCOLOR_BLUE));

	imbSynthColourPair(std::string primar, std::string secundar, std::string contrar);
};

class imbSynthThemeBase {

	public:
		Rectangle<int> spaceUnit_big = Rectangle<int>(200, 24);
		Rectangle<int> spaceUnit_mid = Rectangle<int>(150, 18);
		Rectangle<int> spaceUnit_small = Rectangle<int>(150, 12);

		imbSynthColourPair color_neutral = imbSynthColourPair("#ebebeb", "#dcdcdc", "#353535");
		imbSynthColourPair color_neutral_negative = imbSynthColourPair("#353535", "#3d3d3d", "#FFFFFF");
		imbSynthColourPair color_first = imbSynthColourPair("#1f619e", "#21598d", "#f6f6f6");
		imbSynthColourPair color_second = imbSynthColourPair("#20966e", "#158760", "#f6f6f6");
		imbSynthColourPair color_third = imbSynthColourPair("#ed6716", "#ed7b16", "#f6f6f6");

		imbSynthGridDefinition main_grid = imbSynthGridDefinition();
		

};