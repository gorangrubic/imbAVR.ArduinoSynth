#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <map>

class ccTranslationMap
{
    
    
public:

    std::map<unsigned int, unsigned int> mapOfEntries;
    
    void Set(unsigned int target, unsigned int output);

	/* Sets target and output to id - if not already declared*/
	void SetDefault(unsigned int id);


	unsigned int Get(unsigned int id, bool AddDefault = true);

	ccTranslationMap();
	~ccTranslationMap();
};

