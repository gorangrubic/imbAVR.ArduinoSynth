/*
  ==============================================================================

    modelDocumentationGenerator.h
    Created: 25 Oct 2019 3:41:00am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"

#include "../Source/Data/Generators/imbMarkdownBuilder.h"

class modelDocumentationGenerator {

public:

	imbMarkdownBuilder &builder;
	SynthDeviceModel &model;


	modelDocumentationGenerator(imbMarkdownBuilder &_builder, SynthDeviceModel &_model) :builder{ _builder }, model{ _model }
	{

	}
};