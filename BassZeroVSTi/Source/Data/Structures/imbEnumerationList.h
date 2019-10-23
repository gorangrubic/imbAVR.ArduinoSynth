/*
  ==============================================================================

    imbEnumerationList.h
    Created: 11 Oct 2019 2:42:42am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class imbEnumerationList {

	
	public:

		std::vector<String> Items;

		//StringArray Items;

		void Add(String item);

		/* -1 if not found */
		int IndexOf(String item);

		String AtIndex(int i);

		int Count();

		void ClearAll();

		imbEnumerationList() {};
};