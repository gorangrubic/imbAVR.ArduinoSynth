/*
  ==============================================================================

    dataObjectPropertyViewSettings.h
    Created: 27 Oct 2019 8:48:11pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "dataObjectPropertyEnumerations.h"

class dataObjectPropertyViewSettings {

	public:

		Slider::TextEntryBoxPosition labelPosition = Slider::TextEntryBoxPosition::TextBoxAbove;
		Slider::TextEntryBoxPosition textboxPosition = Slider::TextEntryBoxPosition::TextBoxBelow;
		Slider::SliderStyle sliderType = Slider::SliderStyle::LinearHorizontal;

		guiAttachedComponentType componentType = guiAttachedComponentType::unassigned;

		dataObjectPropertyEnumerations::enumerationEditorModes editorAlternations = dataObjectPropertyEnumerations::enumerationEditorModes::normal;
		

		/* if >2 input field will be bigger for given factor. text editor will turn into multiline mode*/
		int size = 1;

		int snapSteps = 1;

		void DeployLayout(dataObjectPropertyEnumerations::layout layout) {
			switch (layout) {
			case dataObjectPropertyEnumerations::layout::column:
				labelPosition = Slider::TextEntryBoxPosition::TextBoxAbove;
				textboxPosition = Slider::TextEntryBoxPosition::TextBoxBelow;
				break;
			case dataObjectPropertyEnumerations::layout::compactRow:
				labelPosition = Slider::TextEntryBoxPosition::TextBoxLeft;
				break;
			}
		}

		void DeployLayout(dataObjectPropertyEnumerations::sliderModes alternations) {
			switch (alternations) {
			case dataObjectPropertyEnumerations::sliderModes::linear:

				sliderType = Slider::SliderStyle::LinearHorizontal;

				labelPosition = Slider::TextEntryBoxPosition::TextBoxAbove;
				textboxPosition = Slider::TextEntryBoxPosition::TextBoxBelow;
				break;
			case dataObjectPropertyEnumerations::sliderModes::numbers:
				sliderType = Slider::SliderStyle::IncDecButtons;
				break;
			case dataObjectPropertyEnumerations::sliderModes::rotational:
				sliderType = Slider::SliderStyle::RotaryHorizontalVerticalDrag;
				Slider::SliderLayout l;
				
				break;
			}
		}
		dataObjectPropertyViewSettings() {
			
		};

		dataObjectPropertyViewSettings(dataObjectPropertyEnumerations::sliderModes alternations, dataObjectPropertyEnumerations::layout layout = dataObjectPropertyEnumerations::layout::column, int _snapSteps=-1) {
			DeployLayout(layout);
			DeployLayout(alternations);
		};

		dataObjectPropertyViewSettings(int _size, dataObjectPropertyEnumerations::layout layout = dataObjectPropertyEnumerations::layout::column) {
			size = _size;
			DeployLayout(layout);
		};

		dataObjectPropertyViewSettings(guiAttachedComponentType _componentType, dataObjectPropertyEnumerations::enumerationEditorModes alternations = dataObjectPropertyEnumerations::enumerationEditorModes::normal, dataObjectPropertyEnumerations::layout layout = dataObjectPropertyEnumerations::layout::column) {
			
			
			editorAlternations = alternations;
			DeployLayout(layout);
			
		};

		/*dataObjectPropertyViewSettings(int _size, bool _compactMode)

		static dataObjectPropertyViewSettings TextArea(int _size) {
			dataObjectPropertyViewSettings output = dataObjectPropertyViewSettings();

		}

		static dataObjectPropertyViewSettings TextArea(int _size) {
			dataObjectPropertyViewSettings output = dataObjectPropertyViewSettings();

		}*/
};