/*
  ==============================================================================

    dataObject.cpp
    Created: 22 Oct 2019 9:04:37pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataObject.h"



void dataObject::RemoveAll()
{
	children.clear();
	properties.clear();
	objects.clear();
	ownedElements.clear();
}

void dataObject::RemoveEntry(std::string _propertyID)
{
	RemovePointerByID(_propertyID, children);
	RemovePointerByID(_propertyID, properties);
	RemovePointerByID(_propertyID,objects);
	RemoveByID(_propertyID, ownedElements);
	
}

//dataObjectLayout dataObject::GetLayout(dataObjectLayoutViewSettings * viewoverride)
//{
//	return dataObjectLayout();
//}

void dataObject::Add(dataObject * _object, dataObjectLayoutViewSettings *_viewSettings=nullptr)
{
	objects.Add(_object);
	add(_object);
	_object->layout.settings.Apply(_viewSettings);

	layout.Add(_object);
}

void dataObject::Add(dataObjectPropertyBase * _property, bool addToLayoutBlock = true, dataObjectPropertyViewSettings * _viewSettings=nullptr)
{
	AddProperty(_property);

	if (addToLayoutBlock) layout.Add(_property);
}

void dataObject::Add(dataObject _object, dataObjectPropertyViewSettings *_viewSettings = nullptr)
{
	//std::unique_ptr<dataElementBase> ptr = std::make_unique<dataElementBase>(_object);
	layout.Add(_object, *_viewSettings);
	ownedElements.push_back(_object);
	objects.Add(&_object);
	add(&_object);
}

void dataObject::Add(dataObjectProperty _property, bool addToLayoutBlock = true, dataObjectPropertyViewSettings * _viewSettings = nullptr)
{
	ownedElements.push_back(_property);

	AddProperty(&_property);
	add(&_property);

	if (addToLayoutBlock) layout.Add(_property);
}



//void dataObject::Add(dataObjectPropertyBase * _property)
//{
//	properties.Add(_property);
//}



void dataObject::SaveTo(imbValueSet & output, std::string parentPathPrefix)
{
	std::string prefix = GetPrefix(parentPathPrefix);

	for each (auto var in properties)
	{
		std::string p = GetParameterPath(var, prefix);

		//std::shared_ptr<dataObjectPropertyBase> prop = var;

		if (var->features.HasFlag(dataElementFeatures::_features::isTemporary)) {

		}
		else {
			output.AddValue(p, var->GetStringValue().toStdString());
		}
	}

	for each (auto var in objects)
	{
		if (var->features.HasFlag(dataElementFeatures::_features::isTemporary)) {

		}
		else {
			var->SaveTo(output, prefix);
		}
		
	}
}

void dataObject::LoadFrom(imbValueSet & output, std::string parentPathPrefix)
{
	std::string prefix = GetPrefix(parentPathPrefix);
	
	for each (std::shared_ptr<dataObjectPropertyBase> var in properties)
	{
		std::string p = GetParameterPath(var, prefix);
		
		std::string dv = var->GetStringValue().toStdString();

		auto v = output.Get(p, dv);

		var->SetStrValue(v);
	}

	for each (auto var in objects)
	{
		var->LoadFrom(output, prefix);
	}
}

void dataObject::CallUpdate(bool update_all, bool update_gui, bool update_tooltip)
{
	for each (std::shared_ptr<dataObjectPropertyBase> var in properties)
	{
		if (update_all) {
			var->updateAll();
		}
		else {
			if (update_gui) {
				var->updateGUI();
			} 
			if (update_tooltip) {
				var->updateTooltip();
			}
		}
		
	}

	for each (auto var in objects)
	{
		var->CallUpdate(update_all, update_gui, update_tooltip);
	}
}

void dataObject::Deploy(std::string prefix)
{
	deploy(prefix);	
}

void dataObject::DeployEnums(SynthEnumDictionaries & dictionaries)
{
}
