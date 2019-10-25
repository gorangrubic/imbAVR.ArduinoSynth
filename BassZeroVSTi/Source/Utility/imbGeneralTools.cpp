/*
  ==============================================================================

    imbGeneralTools.cpp
    Created: 22 Oct 2019 6:28:28pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbGeneralTools.h"
/* Adaptation of Stackoverflow answer: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c */
std::string imbGeneralTools::GetRandomString(int numberOfChars)
{

		static auto& chrs = "0123456789"
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		thread_local static std::mt19937 rg{ std::random_device{}() };
		thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

		std::string s;

		s.reserve(numberOfChars);

		while (numberOfChars--)
			s += chrs[pick(rg)];

		return s;

}

  Colour imbGeneralTools::ColorFromHex(String color_hex)
  {
	  
	  if (color_hex.startsWith("#")) color_hex = color_hex.substring(1);


	  if (color_hex.length() == 6) {
		  unsigned int r, g, b;
		  sscanf(color_hex.getCharPointer(), "%02x%02x%02x", &r, &g, &b);

		  return Colour(r, g, b);
	  }
	  else if (color_hex.length() == 8) {

		  unsigned int a, r, g, b;
		  sscanf(color_hex.getCharPointer(), "%02%02x%02x%02x", &a, &r, &g, &b);

		  return Colour(juce::uint8(r), juce::uint8(g), juce::uint8(b), juce::uint8(a));
		
	  }
	  return Colour();
  }

  Colour imbGeneralTools::ColorFromHex(std::string hexCode)
  {
	  return ColorFromHex(juce::String(hexCode));
  }
