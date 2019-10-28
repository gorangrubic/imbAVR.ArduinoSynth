/*
  ==============================================================================

    dataObjectLayoutViewSettings.h
    Created: 27 Oct 2019 6:30:45pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Utility/imbGeneralTools.h"

/* describes dataObject component with FlexItems */
class dataObjectLayoutViewSettings {

public:

	void Apply(dataObjectLayoutViewSettings * source=nullptr) {
		if (source == nullptr) return;
		flexDirection = source->flexDirection;
		flexWrap = source->flexWrap;
		alignContent = source->alignContent;
		alignItems = source->alignItems;
		justifyContent = source->justifyContent;
	}

	//==============================================================================
/** Specifies how flex items are placed in the flex container, and defines the
	direction of the main axis.
*/
	FlexBox::Direction flexDirection = FlexBox::Direction::row;

	/** Specifies whether items are forced into a single line or can be wrapped onto multiple lines.
		If wrapping is allowed, this property also controls the direction in which lines are stacked.
	*/
	FlexBox::Wrap flexWrap = FlexBox::Wrap::noWrap;

	/** Specifies how a flex container's lines are placed within the flex container when
		there is extra space on the cross-axis.
		This property has no effect on single line layouts.
	*/
	FlexBox::AlignContent alignContent = FlexBox::AlignContent::stretch;

	/** Specifies the alignment of flex items along the cross-axis of each line. */
	FlexBox::AlignItems alignItems = FlexBox::AlignItems::stretch;

	/** Defines how the container distributes space between and around items along the main-axis.
		The alignment is done after the lengths and auto margins are applied, so that if there is at
		least one flexible element, with flex-grow different from 0, it will have no effect as there
		won't be any available space.
	*/
	FlexBox::JustifyContent justifyContent = FlexBox::JustifyContent::flexStart;


};