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

	/* all contained children */
	SharedPointerVector<dataElementBase> children;



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

	

	SharedPointerVector<dataObjectPropertyBase> properties;
	
	std::string name;

	std::string GetPrefix(std::string parentPathPrefix = "");
	std::string GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix);

	void AddProperty(dataObjectPropertyBase * _property);

	dataObjectPropertyBase * FindProperty(std::string _propertyID);

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

	

	dataElementContainer(std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none):dataElementBase(_name,_label,_description,_unit,_helpUrl,_parClass,_features) {
		
		features |= dataElementFeatures::isElementContainer;
		
		//isContainer = true;
	}

};