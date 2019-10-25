/*
  ==============================================================================

    imbDictionary.h
    Created: 25 Oct 2019 11:55:50pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"



template<typename TKey, typename TObject>
class imbDictionary
{


public:

	TObject defaultValue;
	
	std::map<TKey, TObject> mapOfEntries;

	void Set(TKey key, TObject output);

	//imbValueSet ToPropertySet();
	//void FromPropertySet(imbValueSet input);
	/* Sets target and output to id - if not already declared*/
	void SetDefault(TKey key);
	
	TObject Get(TKey key, bool AddDefault = true);

	imbDictionary(TObject _defaultValue)
	{
		defaultValue = _defaultValue;
	};
	~imbDictionary()
	{
		
	};
};



template<typename TKey, typename TObject>
inline void imbDictionary<TKey, TObject>::Set(TKey key, TObject output)
{
	if (mapOfEntries.find(key) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(key, output));
	}
	else {
		mapOfEntries[key] = output;
	}
}

template<typename TKey, typename TObject>
inline void imbDictionary<TKey, TObject>::SetDefault(TKey key)
{
	if (mapOfEntries.find(key) == mapOfEntries.end()) {
		mapOfEntries.insert(std::make_pair(key, defaultValue));
	}
	else {

	}
}

template<typename TKey, typename TObject>
inline TObject imbDictionary<TKey, TObject>::Get(TKey key, bool AddDefault)
{
	if (mapOfEntries.find(key) == mapOfEntries.end()) {
		if (AddDefault) {
			mapOfEntries.insert(std::make_pair(key, defaultValue));
			return defaultValue;
		}
		else {
			return defaultValue;
		}
	}
	else {
		return mapOfEntries[key];
	}
}
