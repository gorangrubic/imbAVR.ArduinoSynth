#include "ccTranslationMap.h"



void ccTranslationMap::Set(unsigned int target, unsigned int output)
{
	if (mapOfEntries.find(target) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(target, output));
	}
	else {
		mapOfEntries[target] = output;
	}
}

void ccTranslationMap::SetDefault(unsigned int id)
{
	if (mapOfEntries.find(id) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(id, id));
	}
	else {
		
	}
}

unsigned int ccTranslationMap::Get(unsigned int id, bool AddDefault)
{
	if (mapOfEntries.find(id) == mapOfEntries.end()) {
		if (AddDefault) {
			mapOfEntries.insert(std::make_pair(id, id));
			return id;
		}
		else {
			return 0;
		}
	}
	else {
		return mapOfEntries[id];
	}
}

ccTranslationMap::ccTranslationMap()
{
}


ccTranslationMap::~ccTranslationMap()
{
}
