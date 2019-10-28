/*
  ==============================================================================

    dataLayoutBlockViewSettings.h
    Created: 27 Oct 2019 5:19:29pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Utility/imbGeneralTools.h"

/* describes parameter block */
class dataLayoutBlockViewSettings {

public:

	std::string blockLabel = "";
	std::string blockDescription = "";

	std::string blockLabelBackgroundColor = "";
	std::string blockLabelTextColor = "";

	std::string blockBackgroundColor = "";


	std::string blockDescriptionBackgroundColor = "";
	std::string blockDescriptionColor = "";



	/** Specifies the flex grow factor of this item.
		This indicates the amount of space inside the flex container the item should take up.
	*/
	float flexGrow = 0.0f;

	/** Specifies the flex shrink factor of the item.
		This indicates the rate at which the item shrinks if there is insufficient space in
		the container.
	*/
	float flexShrink = 1.0f;

	/** Specifies the flex-basis of the item.
		This is the initial main size of a flex item in the direction of flow. It determines the size
		of the content-box unless specified otherwise using box-sizing.
	*/
	float flexBasis = 0.0f;

	/** This is the align-self property of the item.
	   This determines the alignment of the item along the cross-axis (perpendicular to the direction
	   of flow).
   */
	FlexItem::AlignSelf alignSelf = FlexItem::AlignSelf::stretch;

	/** The margin to leave around this item. */
	FlexItem::Margin margin;

};