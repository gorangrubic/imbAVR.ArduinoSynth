/*
  ==============================================================================

    dataLayoutBlock.h
    Created: 27 Oct 2019 5:11:33pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
//#include "../Source/Data/Structures/dataElementIndexMap.h"

#include "dataElementBase.h"

#include "../Source/Utility/imbGeneralTools.h"
#include "dataLayoutBlockBase.h"
#include "dataElementBase.h"
#include "dataObjectPropertyViewSettings.h"


class dataLayoutBlock:public dataLayoutBlockBase {

public:

	

	dataElementBase * dataSource = nullptr;

	dataLayoutBlockBase * parent = nullptr;

	SharedPointerVector<dataLayoutBlockBase> blocks;

	

	SharedPointerMap<dataElementBase*, dataObjectPropertyViewSettings> elements;
	

	void SetSource(dataElementBase * _dataSource) {

		if (_dataSource != nullptr) {

			dataSource = _dataSource;

			if (blockLabel.empty() && dataSource->features.HasFlag(dataElementFeatures::allowToShowLabel)) blockLabel = dataSource->parameterLabel;
			if (blockDescription.empty() && dataSource->features.HasFlag(dataElementFeatures::allowToShowDescription)) blockLabel = dataSource->parameterLabel;
			if (blockLabelBackgroundColor.empty() && dataSource->features.HasFlag(dataElementFeatures::allowToUseColor)) blockLabelBackgroundColor = dataSource->entryColorHex;

			if ((!doShowHelpIcon) && dataSource->features.HasFlag(dataElementFeatures::allowToShowHelpIcon)) doShowHelpIcon = true;
			//if (blockLabel.empty() && dataSource->features.HasFlag(dataElementFeatures::allowToShowLabel)) blockLabel = dataSource->parameterLabel;
		}
		
	}

	dataLayoutBlock(dataElementBase * _dataSource=nullptr, std::string _label="", std::string _description = "", std::string _hexColor = ""):dataLayoutBlockBase() {
		
		blockLabel = _label;
		blockDescription = _description;
		blockLabelBackgroundColor = _hexColor;

		SetSource(_dataSource);		
	};

	bool doShowHelpIcon = false;

	void add(dataElementBase * _element, dataObjectPropertyViewSettings * propViewSettings) {
		elements.Add(_element, propViewSettings);
	};

	void add(dataLayoutBlockBase * _block) {

		auto block = static_cast<dataLayoutBlock*>(_block);
		block->parent = this;
		blocks.Add(block);
		block->order = blocks.size();

	};


};

