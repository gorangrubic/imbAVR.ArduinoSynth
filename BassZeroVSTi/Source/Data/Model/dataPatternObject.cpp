/*
  ==============================================================================

    dataPatternObject.cpp
    Created: 25 Oct 2019 3:16:46pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataPatternObject.h"

void dataPatternObject::Set(std::vector<float> pattern)
{
}

dataObjectProperty * dataPatternObject::GetCell(int i)
{
	return GetMemberByPath<dataObjectProperty>(GetCellID(i));
	
}

std::vector<dataObjectProperty*> dataPatternObject::GetAllCells()
{
	std::vector<dataObjectProperty *> output;

	for (size_t i = 0; i < patternSize; i++)
	{
		output.push_back(GetCell(i));
	}
	
	return output;
}

std::string dataPatternObject::GetCellID(int i)
{
	return String(i).toStdString();
}



