/*
  ==============================================================================

    imbValueSet.cpp
    Created: 17 Oct 2019 3:02:23pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbValueSet.h"



std::vector<std::string> imbValueSet::GetAllIDs()
{
	std::vector<std::string> output;
	for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
	{
		output.push_back(it->first);

	}
	return output;
}

void imbValueSet::AddComment(std::string id, std::string comment)
{
	if (!comment.empty()) {
		//comment = EscapeValue(comment);
		if (comments.find(id) == comments.end()) {
			comments.insert(id, comment);
		}
		else {
			comments[id] = comment;
		}
	}
}

void imbValueSet::AddValue(std::string id, std::string value)
{
	if (!value.empty()) {
		
		//value = EscapeValue(value);

		if (data.find(id) == data.end()) {
			data.insert(id, value);
		}
		else {
			data[id] = value;
		}
	}

}

std::string imbValueSet::EscapeValue(std::string value)
{
	juce::String v = juce::String(value);
	v = v.replace("\"", "''");
	v = v.replace("\n", "[newline]");

	return v.toStdString();
}

std::string imbValueSet::UnescapeValue(std::string value)
{
	juce::String v = juce::String(value);
	v = v.replace("''", "\"");
	v = v.replace("[newline]", "\n");

	return v.toStdString();
	return std::string();
}

void imbValueSet::Add(std::string id, float value, std::string comment)
{
	AddValue(id, std::to_string(value));
	AddComment(id, comment);
}

void imbValueSet::Add(std::string id, int value, std::string comment)
{
	AddValue(id, std::to_string(value));
	AddComment(id, comment);
}

void imbValueSet::Add(std::string id, std::string value, std::string comment)
{
	AddValue(id, value);
	AddComment(id, comment);
}

std::string imbValueSet::GetData(std::string id)
{
	if (data.find(id) == data.end()) {
		return "";
	}
	else {
		return data[id];
	}
}

std::string imbValueSet::GetComment(std::string id)
{
	if (comments.find(id) == comments.end()) {
		return "";
	}
	else {
		return comments[id];
	}
}

void imbValueSet::Set(std::string id, float & value, float defaultValue)
{
	if (data.find(id) == data.end()) {
		value = defaultValue;
	}
	else {
		std::string d = GetData(id);
		if (d.empty()) {
			value = 0;
		}
		else {
			juce::String s = juce::String(d);
			value = s.getFloatValue();
		}
	}
}

void imbValueSet::Set(std::string id, int & value, int defaultValue)
{
	if (data.find(id) == data.end()) {
		value = defaultValue;
	}
	else {
		std::string d = GetData(id);
		if (d.empty()) {
			value = 0;
		}
		else {
			juce::String s = juce::String(d);
			value = s.getIntValue();
		}
	}
}

void imbValueSet::Set(std::string id, std::string & value, std::string defaultValue)
{
	if (data.find(id) == data.end()) {
		value = defaultValue;
	}
	else {
		std::string d = GetData(id);
		if (d.empty()) {
			value = "";
		}
		else {
			//juce::String s = juce::String(d);
			value = d; // s.getFloatValue();
		}
	}
}

float imbValueSet::Get(std::string id, float defaultValue)
{
	juce::String s = GetData(id);
	if (s.isEmpty()) return defaultValue;
	return s.getFloatValue();
}

int imbValueSet::Get(std::string id, int defaultValue)
{
	juce::String s = GetData(id);
	if (s.isEmpty()) return defaultValue;
	return s.getIntValue();
}

std::string imbValueSet::Get(std::string id, std::string defaultValue)
{
	juce::String s = GetData(id);
	if (s.isEmpty()) return defaultValue;
	return s.toStdString();
}

std::vector<std::string> imbValueSet::split_string(const std::string& str,
	const std::string& delimiter)
{
	std::vector<std::string> strings;

	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = str.find(delimiter, prev)) != std::string::npos)
	{
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + 1;
	}

	// To get the last substring (or only, if delimiter is not found)
	strings.push_back(str.substr(prev));

	return strings;
}

std::string imbValueSet::ToString()
{
	juce::String output = "";

	for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
	{
		juce::String line = "";
		line.append(it->first + " = ",50);
		line.append("\"", 5);
		line.append(EscapeValue(it->second), 1000);
		line.append("\";", 5);
		
		std::string c = GetComment(it->first);
		if (!c.empty()) {
			line.append(" \\\\", 10);
			line.append(EscapeValue(c), 1000);
		}

		output.append(line + "\n", 5000);
		
	}
}

void imbValueSet::FromString(std::string input)
{
	auto lines = split_string(input, "\n");

	for each (auto var in lines)
	{

		std::string::size_type pos = 0;
		pos = var.find(" = ", 1);
		if (pos > std::string::npos) {

			auto valuePart = var.substr(pos + 3);
			auto idPart = var.substr(0, pos);

			auto from = valuePart.find("\"");
			auto to = valuePart.find("\";");
			auto val = valuePart.substr(from, to - from);

			AddValue(idPart, UnescapeValue(val));

			// extracting comment
			pos = valuePart.find(" \\\\", 1);
			if (pos != std::string::npos) {
				auto commentPart = valuePart.substr(pos + 3);
				AddComment(idPart, commentPart);
			}
		}
	}
	juce::String inv = juce::String(input);
	
}

imbValueSet::imbValueSet()
{

}
