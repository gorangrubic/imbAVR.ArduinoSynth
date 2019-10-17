#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Utility/imbValueSet.h"
#include <map>

enum ccTranslationMapRole {
	unknown,
	input,
	output

};



class ccTranslationMap
{
    
    
public:

    std::map<int, int> mapOfEntries;
    
    void Set(int target, int output);

	/* Sets target and output to id - if not already declared*/
	void SetDefault(int id);

	imbValueSet ToPropertySet();
	void FromPropertySet(imbValueSet input);

	int Get(int id, bool AddDefault = true);

	ccTranslationMap();
	~ccTranslationMap();
};

