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
#include "../Source/Data/Structures/imbValueSet.h"
#include "dataElementContainer.h"


class dataObject: public dataElementContainer {

protected:

	//SharedPointerVector<dataObjectPropertyBase> properties;
	SharedPointerVector<dataObject> objects;

public:


	/*std::string GetPrefix(std::string parentPathPrefix = "");
	std::string GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix);
*/
	//std::string name;

	void Add(dataObject * _object);
	void Add(dataObjectPropertyBase * _property);

	void SaveTo(imbValueSet &output, std::string parentPathPrefix="");
	void LoadFrom(imbValueSet &output, std::string parentPathPrefix = "");

	void CallUpdate(bool update_all=true, bool update_gui=true, bool update_tooltip=true);

	dataObject(std::string _name="", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
	:dataElementContainer(_name, _label, _description,_unit,_helpUrl) {

	}

};