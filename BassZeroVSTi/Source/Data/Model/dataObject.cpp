/*
  ==============================================================================

    dataObject.cpp
    Created: 22 Oct 2019 9:04:37pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataObject.h"

//std::string dataObject::GetPrefix(std::string parentPathPrefix)
//{
//	std::string prefix = name;
//	if (!parentPathPrefix.empty()) {
//		if (!name.empty()) {
//			prefix = parentPathPrefix + "." + name;
//		}
//		else {
//			prefix = parentPathPrefix;
//		}
//	}
//	return prefix;
//}
//
//std::string dataObject::GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix)
//{
//	std::string p = "";
//	if (prefix.empty()) {
//		p = var->parameterID;
//	}
//	else {
//		p = prefix + "." + var->parameterID;
//	}
//	return p;
//}

void dataObject::Add(dataObject * _object)
  {
	objects.Add(_object);
  }

void dataObject::Add(dataObjectPropertyBase * _property)
{
	AddProperty(_property);
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

		std::shared_ptr<dataObjectPropertyBase> prop = var;

		output.AddValue(p, prop->GetStringValue().toStdString());
	}

	for each (auto var in objects)
	{
		var->SaveTo(output, prefix);
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
