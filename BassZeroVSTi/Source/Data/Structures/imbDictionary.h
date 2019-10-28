/*
  ==============================================================================

    imbDictionary.h
    Created: 25 Oct 2019 11:55:50pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template<typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const& input_map) {
	std::vector<TK> retval;
	for (auto const& element : input_map) {
		retval.push_back(element.first);
	}
	return retval;
}

template<typename TK, typename TV>
std::vector<TV> extract_values(std::map<TK, TV> const& input_map) {
	std::vector<TV> retval;
	for (auto const& element : input_map) {
		retval.push_back(element.second);
	}
	return retval;
}

template<typename TK, typename TV>
std::vector<TK*> extract_keys_ptr(std::map<TK, TV> const& input_map) {
	std::vector<TK*> retval;
	for (auto const& element : input_map) {
		retval.push_back(&element.first);
	}
	return retval;
}

template<typename TK, typename TV>
std::vector<TV*> extract_values_ptr(std::map<TK, TV> const& input_map) {
	std::vector<TV*> retval;
	for (auto const& element : input_map) {
		retval.push_back(&element.second);
	}
	return retval;
}


template<typename TKey, typename TObject>
class imbDictionary
{


public:

	void ClearAll() {
		mapOfEntries.clear();
	};

	TObject defaultValue;
	
	std::vector<TKey> GetKeys();
	std::vector<TObject> GetValues();

	std::vector<TKey*> GetKeys_ptr();
	std::vector<TObject*> GetValues_ptr();

	std::map<TKey, TObject> mapOfEntries;

	bool Contains(TKey key);

	int Count() {
		return mapOfEntries.size();
	};

	void Set(TKey key, TObject output);


	//imbValueSet ToPropertySet();
	//void FromPropertySet(imbValueSet input);
	/* Sets target and output to id - if not already declared*/
	void SetDefault(TKey key);
	
	TObject Get(TKey key, bool AddDefault = true);

	imbDictionary()
	{
	
	};

	imbDictionary(TObject _defaultValue)
	{
		defaultValue = _defaultValue;
	};
	~imbDictionary()
	{
		
	};
};


/* Taken from:  http://www.lonecpluspluscoder.com/2015/08/13/an-elegant-way-to-extract-keys-from-a-c-map/  (Timo Geusch) */
template<typename TKey, typename TObject>
inline std::vector<TKey> imbDictionary<TKey, TObject>::GetKeys()
{
	return extract_keys<TKey, TObject>(mapOfEntries);
}

template<typename TKey, typename TObject>
inline std::vector<TObject> imbDictionary<TKey, TObject>::GetValues()
{
	return extract_values<TKey, TObject>(mapOfEntries);
}

template<typename TKey, typename TObject>
inline std::vector<TKey*> imbDictionary<TKey, TObject>::GetKeys_ptr()
{
	return extract_keys_ptr<TKey, TObject>(mapOfEntries);
}

template<typename TKey, typename TObject>
inline std::vector<TObject*> imbDictionary<TKey, TObject>::GetValues_ptr()
{
	return  extract_values_ptr<TKey, TObject>(mapOfEntries);
}

template<typename TKey, typename TObject>
inline bool imbDictionary<TKey, TObject>::Contains(TKey key)
{
	return !(mapOfEntries.find(key) == mapOfEntries.end());
}

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



template<typename TObject>
class imbIndexByString : public imbDictionary<std::string, TObject> {

public:
	std::string SetByUniqueKey(std::string keyProposal, TObject item) {

		auto finalLibraryName = GetUniqueKey(keyProposal);
		Set(keyProposal, item);
	}

	/* if [propose] key exists, creates variation with ordinal suffix */
	std::string GetUniqueKey(std::string propose) {

		auto finalLibraryName = propose;

		int n = 1;
		while (existing.contains(finalLibraryName, true)) {
			n++;
			finalLibraryName = propose + " " + std::to_string(n);
		}

		return Proposal;
	}
};