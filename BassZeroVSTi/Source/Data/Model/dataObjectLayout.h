/*
  ==============================================================================

    dataObjectLayout.h
    Created: 27 Oct 2019 6:30:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Utility/imbGeneralTools.h"
#include "dataLayoutBlock.h"
#include "dataElementBase.h"

#include "dataObjectLayoutViewSettings.h"
#include "dataObjectPropertyViewSettings.h"

class dataObjectLayout :
	public dataLayoutBlock {

public:

	dataObjectLayoutViewSettings settings;

	dataLayoutBlock * currentBlock = nullptr;

	void Add(dataElementBase * _element, dataObjectPropertyViewSettings * propViewSettings=nullptr) {
		if (currentBlock != nullptr) {
		}
		else {
			add(_element, propViewSettings);
		}

	}



	void Add(dataLayoutBlockBase * _block) {

		auto block = static_cast<dataLayoutBlock*>(_block);
		block->parent = this;
		blocks.Add(block);
		block->order = blocks.size();

	}



	dataLayoutBlock * OpenBlock(std::string _label = "", std::string _description = "", std::string _hexColor = "") {

		dataLayoutBlock block = dataLayoutBlock(nullptr, _label, _description, _hexColor);

		if (currentBlock != nullptr) {
			currentBlock->add(static_cast<dataLayoutBlockBase*>(&block));
		}
		else {
			currentBlock = &block;
		}

		return &block;
	}

	void CloseBlock() {

		if (currentBlock->parent != nullptr) {
			currentBlock = static_cast<dataLayoutBlock*>(currentBlock->parent);
		}
	}

	dataObjectLayout(dataElementBase * _dataParent) {

		SetSource(_dataParent);

		//bool doSetLabel, bool doSetDescription, bool doSetColor = false
	};
};
