/*
  ==============================================================================

    dataObject.h
    Created: 22 Oct 2019 9:04:37pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "dataObjectPropertyBase.h"
#include "dataObjectProperty.h"
#include "../Source/Data/Structures/imbValueSet.h"
#include "dataElementContainer.h"

//#include "../Source/Application/SynthApplicationEnvironment.h"
#include "../Source/Application/SynthEnumDictionaries.h"
#include "dataObjectLayout.h"


class dataObject: public dataElementContainer {

protected:

	//SharedPointerVector<dataObjectPropertyBase> properties;
	SharedPointerVector<dataObject> objects;

	std::vector<dataElementBase> ownedElements;

	//std::vector<std::unique_ptr<dataElementBase>> ownedElements;
	//std::vector<std::unique_ptr<dataObject>> ownedObjects;
	//std::vector<std::unique_ptr<dataObjectProperty>> ownedProperties;

public:

	void RemoveAll() override;
	void RemoveEntry(std::string _propertyID) override;

	void Add(dataObject * _object, dataObjectPropertyViewSettings * _viewSettings);

	void Add(dataObjectPropertyBase * _property, bool addToLayoutBlock, dataObjectPropertyViewSettings * _viewSettings);

	void Add(dataObject _object, dataObjectPropertyViewSettings * _viewSettings);

	void Add(dataObjectProperty _property, bool addToLayoutBlock, dataObjectPropertyViewSettings * _viewSettings);

	/*std::string GetPrefix(std::string parentPathPrefix = "");
	std::string GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix);
*/
	//std::string name;

	dataObjectLayout layout;

	dataObjectLayout GetCustomLayout(dataObjectLayoutViewSettings *viewoverride = nullptr) {
		
		dataObjectLayout custom_layout = dataObjectLayout(this);
		
		if (viewoverride != nullptr) {
			custom_layout.settings = *viewoverride;
		}
		
		return custom_layout;
	}

	

	void Add(dataObject * _object, dataObjectLayoutViewSettings *viewoverride = nullptr);
	//void Add(dataObjectPropertyBase * _property);
	void Add(dataObjectPropertyBase * _property, bool addToLayoutBlock);

	void Add(dataObject _object, dataObjectLayoutViewSettings *viewoverride = nullptr);

	void Add(dataObjectProperty _property, bool addToLayoutBlock);

	void SaveTo(imbValueSet &output, std::string parentPathPrefix="");
	void LoadFrom(imbValueSet &output, std::string parentPathPrefix = "");

	void CallUpdate(bool update_all=true, bool update_gui=true, bool update_tooltip=true);

	void Deploy(std::string prefix = "") override;

	virtual void DeployEnums(SynthEnumDictionaries & environment);

	dataObject(std::string _name="", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "",parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
	:dataElementContainer(_name, _label, _description,_unit,_helpUrl), layout(this) {
	
		valueType = parameterValueType::dataObject;
		editorOfPreferenceDefault = "dataLayoutComponent";
	}

};