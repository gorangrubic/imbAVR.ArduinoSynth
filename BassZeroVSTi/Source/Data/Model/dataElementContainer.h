/*
  ==============================================================================

    dataElementContainer.h
    Created: 23 Oct 2019 11:57:38am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Data/Model/dataElementBase.h"
#include "../Source/Data/Model/dataObjectPropertyBase.h"

#include "dataObjectProperty.h"
#include "dataIntProperty.h"
#include "dataEnumProperty.h"
#include "dataStringProperty.h"
#include "dataBoolProperty.h"
#include "dataEnumEntryProperty.h"

class dataElementContainer : public dataElementBase {



protected:

	/* to be called after tree is completly built. sets property parameterIDPath */
	void deploy(std::string prefix);

	void deployAutomation(juce::AudioProcessorValueTreeState & parameters);

	/* registers the item into children vector*/
	void add(dataElementBase * item);

	

	/*template<typename T>
	void add(std::vector<T> items) {

		for (size_t i = 0; i < length; i++)
		{

		}
	}
*/
	/* all contained children */
	SharedPointerVector<dataElementBase> children;
	template<typename T>
	void RemoveByID(juce::String _id, std::vector<T> & collection)
	{

		T * dEB = nullptr;
		size_t i = -1;
		for (size_t pi = 0; pi < collection.size(); pi++)
		{
			if (collection[pi].parameterID == _propertyID) {
				i = pi;
				dEB = collection[pi].get();
				break;
			}
		}

		if (i != -1) {

			collection.erase(collection.begin() + i, collection.begin() + i + 1);
		}

	}

	template<typename T>
	void RemovePointerByID(juce::String _id, SharedPointerVector<T> & collection)
	{
		
		T * dEB = nullptr;
		size_t i = -1;
		for (size_t pi = 0; pi < collection.size(); pi++)
		{
			if (collection[pi]->parameterID == _propertyID) {
				i = pi;
				dEB = collection[pi].get();
				break;
			}
		}

		if (i != -1) {

			collection.erase(collection.begin() + i, collection.begin() + i + 1);
		}

	}

	template<typename T>
	std::shared_ptr<T> GetPointerByID(juce::String _id, SharedPointerVector<T> & collection)
	{
		std::shared_ptr<T> output = nullptr;

		//juce::String needleString = juce::String(name);

		for each (auto var in collection)
		{
			if (var->parameterID == _id) {
				output = var;
				break;
			}
		}

		return output;
	}

	
	
public:
	template<typename T>
	std::vector<T*> GetAllWithClassRole(juce::String _classRole)
	{
		std::vector<T*> output;

		//juce::String needleString = juce::String(name);

		for each (auto var in children)
		{
			if (var->elementClassRole == _classRole) {
				output.push_back(var.get());
			}
		}

		return output;
	}

	virtual void RemoveAll();

	virtual void RemoveEntry(std::string _propertyID);

	SharedPointerVector<dataObjectPropertyBase> properties;
	
	/* if [propose] key exists, creates variation with ordinal suffix */
	std::string GetUniqueKey(std::string propose) {

		auto finalLibraryName = propose;

		int n = 1;
		while (Contains(finalLibraryName)) {
			n++;
			finalLibraryName = propose + " " + std::to_string(n);
		}

		return finalLibraryName;
	}
	
	void AddProperty(dataObjectPropertyBase * _property);

	dataObjectPropertyBase * FindProperty(std::string _propertyID);


	int GetCheckSum(bool forValue = true, bool forStructure = false);

	/*int GetCheckSum() {

		int output;

		for each (std::shared_ptr<dataElementBase> var in children)
		{
			var->parameterIDPath = GetParameterPath(var, parameterIDPath);

			if (var->features.HasFlag(dataElementFeatures::isElementContainer)) {
				dataElementContainer * c = static_cast<dataElementContainer *>(var.get());
				
			}
			else if (var->features.HasFlag(dataElementFeatures::isProperty)) {
				dataObjectPropertyBase * p = static_cast<dataObjectPropertyBase *>(var.get());
				if (p->valueType != dataObject)
				output += p->GetIntValue();

			}
		}

		
		return output;

	}*/

	bool Contains(std::string _propertyID) {

		for each (auto var in children)
		{
			if (var->parameterID == _propertyID) {
				return true;
			}
		}
		return false;
	}

	dataElementContainer * GetParentOfPath(std::string relativePath)
	{
		juce::String s = relativePath;
		int pathDotPos = s.lastIndexOf(".");
		if (pathDotPos == -1) {
			return nullptr;
		}
		s = s.substring(pathDotPos);

		return GetMemberByPath<dataElementContainer>(s.toStdString());
		//dataElementBase * 
	}

	template<typename T>
	/* returns dataObjectBase child at given path. if not found, returns nullptr */
	/* T must be dataElementBase */
	T * GetMemberByPath(std::string relativePath) {

		juce::String s = relativePath;
		std::string needle = s;
		int pathDotPos = s.indexOf(".");
		
		if (pathDotPos == -1) {
			auto p = GetPointerByID(needle, children);
			return dynamic_cast<T>(p);
		}
		else {

			needle = s.substring(0, pathDotPos);
			std::string pathRest = s.substring(pathDotPos);

			auto p = GetPointerByID(needle, children);
			dataElementBase * de = dynamic_cast<dataElementBase*>(p);
			if (de->isContainer) {
				return de->GetMemberByPath<T>(pathRest);
			}
			else {
				return nullptr;
			}
		}
	}
	
	/* to be called after tree is completly built. sets property paths */
	virtual void Deploy(std::string prefix);

	/// <summary>
	/// Collects all properties from self and children. 
	/// </summary>
	/// <param name="allProperties">All properties.</param>
	/// <param name="parClass">Selects only properties of specified class, when the class is other than parameterClass::unspecified</param>
	void GetAllProperties(std::vector<dataObjectPropertyBase*> &allProperties, parameterClass parClass = parameterClass::unspecified);

	dataElementContainer(std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none):dataElementBase(_name,_label,_description,_unit,_helpUrl,_parClass,_features) {
		
		features |= dataElementFeatures::isElementContainer;
		
		//isContainer = true;
	}

};