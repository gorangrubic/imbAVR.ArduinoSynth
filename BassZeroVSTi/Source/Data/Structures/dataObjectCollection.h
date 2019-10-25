/*
  ==============================================================================

    dataObjectCollection.h
    Created: 25 Oct 2019 11:55:36pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbDictionary.h"
#include "../Source/Data/Model/dataObject.h"

class dataObjectCollection :public imbDictionary<std::string, std::shared_ptr<dataObject>> {

public:

	void Add(dataObject * object);

	dataObject * GetObject(std::string path);

	dataElementBase * FindElement(std::string path);

	void Remove(std::string name);

	void ClearAll();

	dataObjectCollection():imbDictionary(nullptr) {

	};
};
