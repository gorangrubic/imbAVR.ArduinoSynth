/*
  ==============================================================================

    dataBindingEntry.cpp
    Created: 24 Oct 2019 11:48:49am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataBindingEntry.h"


void dataBindingEntry::attachControlBase(Component * _component)
  {
  }

  void dataBindingEntry::mouseDown(const MouseEvent & event)
{

	if (event.mods.isRightButtonDown()) {
		if (onShowContextMenu != nullptr) {
			auto menu = onShowContextMenu(parameterIDPath);

			//PopupMenu::Options ops();

			//menu.showMenuAsync(ops, )
		}
	}
}


void dataBindingEntry::mouseEnter(const MouseEvent & event)
{
	if (onGUIFocus != nullptr) onGUIFocus(parameterIDPath);
}


juce::Rectangle<int> dataBindingEntry::getBounds()
{

	switch (componentType) {

	case guiAttachedComponentType::combobox:
		return pComboBox->getBounds();
		break;
	case guiAttachedComponentType::slider:
		return pSlider->getBounds();
		break;
	case guiAttachedComponentType::unassigned:

		break;
	case guiAttachedComponentType::checkbox:
		return pToggleButton->getBounds();
		break;
	case guiAttachedComponentType::imbParameterComponent:
		return pParameterEditor->getBounds();
		break;
	case guiAttachedComponentType::texteditor:
		//pTextEditor->setText(GetStringValue(), false);
		return pTextEditor->getBounds();
		break;
	case guiAttachedComponentType::imbComponent:
		break;
	case guiAttachedComponentType::component:
		break;
	case guiAttachedComponentType::contextMenu:
		break;
	case guiAttachedComponentType::textlabel:
		return pLabel->getBounds();
		break;
	}
}



void dataBindingEntry::attachControlAsParent(Component * _component)
{
	componentType = guiAttachedComponentType::parentComponent;

	attachControlBase(dynamic_cast<juce::Component*>(_component));
}

void dataBindingEntry::attachControl(Slider * _editor)
{
	componentType = guiAttachedComponentType::slider;
	pSlider = std::shared_ptr<Slider>(_editor);//new SliderAttachment(valueTreeState, parameterIDPath, slider);
	pSlider->onValueChange = [&, this] {
		float f = (float)pSlider->getValue();
		if (onFloatValueChange != nullptr)	onFloatValueChange(f, parameterIDPath);
	};	
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}

void dataBindingEntry::attachControl(ComboBox * _editor)
{
	componentType = guiAttachedComponentType::combobox;
	pComboBox = std::shared_ptr<ComboBox>(_editor);
	pComboBox->onChange = [&, this] {
		if (onFloatValueChange != nullptr) onFloatValueChange((float)pComboBox->getSelectedId(),parameterIDPath);
	};	
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}

void dataBindingEntry::attachControl(ToggleButton * _editor)
{
	componentType = guiAttachedComponentType::checkbox;
	pToggleButton = std::shared_ptr<ToggleButton>(_editor);
	pToggleButton->onStateChange = [&, this] {
		if (pToggleButton->getState()) {
			if (onFloatValueChange != nullptr) onFloatValueChange(1, parameterIDPath);
		}
		else {
			if (onFloatValueChange != nullptr) onFloatValueChange(0, parameterIDPath);
		}
	};
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}

void dataBindingEntry::attachControl(TextEditor * _editor)
{
	componentType = guiAttachedComponentType::texteditor;

	pTextEditor = std::shared_ptr<TextEditor>(_editor);
	pTextEditor->onTextChange = [&, this] {
		if (onStringValueChange != nullptr) onStringValueChange(pTextEditor->getText().toStdString(), parameterIDPath);
	};
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}

void dataBindingEntry::attachControl(Label * _editor)
{
	componentType = guiAttachedComponentType::textlabel;
	pLabel = std::shared_ptr<Label>(_editor);
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}

void dataBindingEntry::attachControl(imbSynthParameterEditor * _editor)
{
	componentType = guiAttachedComponentType::imbParameterComponent;
	pParameterEditor = std::shared_ptr<imbSynthParameterEditor>(_editor);
	pParameterEditor->onValueChange = [&, this] {
		if (onFloatValueChange != nullptr) onFloatValueChange(0, parameterIDPath);
	};
	attachControlBase(dynamic_cast<juce::Component*>(_editor));
}
