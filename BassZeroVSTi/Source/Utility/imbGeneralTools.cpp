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
