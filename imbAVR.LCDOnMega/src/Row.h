#pragma once

#ifndef _ROW_h
#define _ROW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "RowBase.h"
#include "LCDElement.h"

template <byte nElements> class Row : public RowBase
{

protected:

	
	
public:

	Row();
	
	LCDElement *Elements[nElements];

	LCDField<byte> SetField(byte position, byte options, byte * value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDField<int> SetField(byte position, byte options, int * value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDField<float> SetField(byte position, byte options, float * value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDField<String> SetField(byte position, byte options, String * value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDProperty<byte> SetField(byte position, byte options, byte  value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDProperty<int> SetField(byte position, byte options, int  value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDProperty<float> SetField(byte position, byte options, float  value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDProperty<String> SetField(byte position, byte options, String  value, FieldValueRenderMode mode = FieldValueRenderMode::numeric_value);

	LCDLabel SetLabel(byte position, byte options, String text);

	void Render(GuiScreen * screen, ACEMegaHostTFTClass * Display, byte state, byte yC);

	void Deploy(GuiScreen * screen);
	
};

class RowHeader : public Row<1> {
public:
	LCDLabel Label;
	
};


class RowTextAndPrefix : public Row<2> {
public:
	LCDLabel prefixLabel;
	LCDProperty<String> textField;
};

template <byte nLabels, byte nProperty, byte nElements>
class RowLabelAndByteProperty :public Row< nElements> {

public:

	LCDLabel Labels[nLabels];
	LCDProperty<byte> Properties[nProperty];

};

class RowTwoByteFields :public RowLabelAndByteProperty<2,2,4> {

};

class RowFourByteFields :public RowLabelAndByteProperty<4, 4, 8> {

};

#endif
//
//template<byte nElements>
//inline void Row<nElements>::AddElement(LCDElement element)
//{
//	Elements[3] = &element;
//
//}

template<byte nElements>
inline Row<nElements>::Row()
{
	elements_n = nElements;
	//_Elements = *Elements;

}



template<byte nElements>
LCDField<byte> Row<nElements>::SetField(byte position, byte options, byte * value, FieldValueRenderMode mode)
{
	LCDField<byte> field = LCDField<byte>();
	field.value = value;
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;

	return field;
}
template<byte nElements>
LCDField<int> Row<nElements>::SetField(byte position, byte options, int * value, FieldValueRenderMode mode)
{
	LCDField<int> field = LCDField<int>();
	field.value = value;
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;

	return field;
}
template<byte nElements>
LCDField<float> Row<nElements>::SetField(byte position, byte options, float * value, FieldValueRenderMode mode)
{
	LCDField<float> field = LCDField<float>();
	field.value = value;
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;

	return field;
}
template<byte nElements>
LCDField<String> Row<nElements>::SetField(byte position, byte options, String * value, FieldValueRenderMode mode)
{
	LCDField<String> field = LCDField<String>();
	field.value = value;
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;

	return field;
}
template<byte nElements>
LCDProperty<byte> Row<nElements>::SetField(byte position, byte options, byte value, FieldValueRenderMode mode)
{
	LCDProperty<byte> field = LCDProperty<byte>(value);
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;
	return field;
}
template<byte nElements>
LCDProperty<int> Row<nElements>::SetField(byte position, byte options, int value, FieldValueRenderMode mode)
{
	LCDProperty<int> field = LCDProperty<int>(value);
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;
	return field;
}
template<byte nElements>
LCDProperty<float> Row<nElements>::SetField(byte position, byte options, float value, FieldValueRenderMode mode)
{
	LCDProperty<float> field = LCDProperty<float>(value);
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;
	return field;
}
template<byte nElements>
LCDProperty<String> Row<nElements>::SetField(byte position, byte options, String value, FieldValueRenderMode mode)
{
	LCDProperty<String> field = LCDProperty<String>(value);
	field.options = options;
	field.renderMode = mode;
	Elements[position] = &field;
	return field;
}

template<byte nElements>
LCDLabel Row<nElements>::SetLabel(byte position, byte options, String text)
{
	LCDLabel label = LCDLabel(text);
	label.elementType = ELEMENTTYPE_LABEL;
	label.options = options;
	Elements[position] = &label;
	return label;
}
template<byte nElements>
inline void Row<nElements>::Render(GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state, byte yC)
{
	

	unsigned int y = Screen->GetYPosition(yC);
	unsigned int h = Screen->GetYPosition(RowHeight);
	unsigned int chw = Screen->GetWidth(1);

	for (size_t i = 0; i < elements_n; i++)
	{


		LCDElement * element = Elements[i];

		unsigned int x = chw * element->Cx;
		unsigned int w = chw * element->Cw;

		GuiScreenPallete pallete = Screen->PalleteA;
		if ((element->options & B00000010) == B00000010) {
			pallete = Screen->PalleteB;
		}

		unsigned int Forecolor = pallete.LabelColor;
		unsigned int Backcolor = pallete.LabelBackColor;



		if (element->elementType != ELEMENTTYPE_LABEL) {
			Forecolor = pallete.FieldColor;
			Backcolor = pallete.FieldBackColor;
		}

		if ((element->options & B00000100) == B00000100) {
			Forecolor = pallete.CriticalColor;
		}

		
		bool inverseColors = ((element->options & B00000001) == B00000001);
		if ((element->options & B00001000) == B00001000) {
			if ((state & B00000100) == B00000100) inverseColors != inverseColors;
		}

		if (inverseColors) {
			unsigned int color = Backcolor;
			Backcolor = Forecolor;
			Forecolor = color;
		}


		//
		Display->setTextColor(GLCD_CL_WHITE);
		Display->print(" x");
		Display->print(x);
		Display->print(" y");
		Display->print(y);
		Display->print(" w");
		Display->print(w);
		Display->print(" h");
		Display->print(h);
		Display->print(" c");
		Display->print(chw);
		
		Display->print(" e");
		Display->print(element->elementType);

		Display->setTextColor(Forecolor);
		Display->print("forecolor");
		Display->setTextColor(Backcolor);
		Display->print("backcolor");

		Display->println();

		//element->Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);

		switch (element->elementType) {
		case ELEMENTTYPE_LABEL:
			Display->println("-- Label rendering ");
			LCDLabel *label = static_cast<LCDLabel*>(element);
			label->Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);
			break;
		case ELEMENTTYPE_BYTEFIELD:
			Display->println("-- Bytefield rendering ");
			LCDField<byte> * byteField = static_cast<LCDField<byte>*>(element);
			byteField->Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);
			break;
		case ELEMENTTYPE_INTFIELD:
			break;
		case ELEMENTTYPE_STRINGFIELD:
			break;
		case ELEMENTTYPE_FLOATFIELD:
			break;
		}

		//LCDLabel label = element;


		//Elements[i]->Render(Display, x, y, w, h, chw, Forecolor, Backcolor, state);

	}

}
template<byte nElements>
void Row<nElements>::Deploy(GuiScreen * screen)
{
	/*byte cWSum = 0;
	for (size_t i = 0; i < elements_n; i++)
	{
		cWSum += Elements[i]->GetWidthFactor();
	}

	byte cWUnit = screen->GetCharScreenWidth() / cWSum;

	byte cX = 0;
	for (size_t i = 0; i < elements_n; i++)
	{
		Elements[i]->Cw = Elements[i]->GetWidthFactor() * cWUnit;
		Elements[i]->Cx = cX;
		cX += Elements[i]->Cw;
	}*/

}