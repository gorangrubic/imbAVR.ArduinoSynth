#include "ccTranslationMap.h"



void ccTranslationMap::Set(int target, int output)
{
	if (mapOfEntries.find(target) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(target, output));
	}
	else {
		mapOfEntries[target] = output;
	}
}

void ccTranslationMap::SetDefault(int id)
{
	if (mapOfEntries.find(id) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(id, id));
	}
	else {
		
	}
}

imbValueSet ccTranslationMap::ToPropertySet()
{
	imbValueSet output = imbValueSet();
	
	for (std::map<int, int>::iterator it = mapOfEntries.begin(); it != mapOfEntries.end(); ++it)
	{
		output.Add(std::to_string(it->first), it->second);
		//it->second.Method();
	}

	return output;
}

void ccTranslationMap::FromPropertySet(imbValueSet input)
{
	auto allIDs = input.GetAllIDs();

	for each (auto var in allIDs)
	{
		juce::String s = var;
		int t = s.getIntValue();
		int o = input.Get(var, t);
		Set(t, o); 
	}

}

int ccTranslationMap::Get(int id, bool AddDefault)
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
