#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif


#include "ACEMegaHostTFT.h"
#include "FieldValueRenderMode.h"
#include "MathTool.h"
#include "LCDElement.h"
#include "GuiDrawingTools.h"

#define TYPEID_STRING 1
#define TYPEID_INT 2
#define TYPEID_BYTE 3
#define TYPEID_FLOAT 4

template <typename T>
class LCDField : public LCDElement {

protected:
	
	void setElementType();
	byte typeID(String * a) { return TYPEID_STRING; }
	byte typeID(int * a) { return TYPEID_INT; }
	byte typeID(byte * a) { return TYPEID_BYTE; }
	byte typeID(float * a) { return TYPEID_FLOAT; }
	byte typeID(String a) { return TYPEID_STRING; }
	byte typeID(int a) { return TYPEID_INT; }
	byte typeID(byte a) { return TYPEID_BYTE; }
	byte typeID(float a) { return TYPEID_FLOAT; }

public:

	typedef T type; 

	T * value;

	void SetValuePointer(T * _value);

	T lastValue;

	FieldValueRenderMode renderMode = FieldValueRenderMode::numeric_value;

	LCDField();

	LCDField(T * _value);

	virtual void Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)  override;


	float GetRatio(int forValue);
	float GetRatio(float forValue);


	float GetRatio(String forValue);

	float GetRatio(byte forValue);


};


template<typename T>
inline void LCDField<T>::setElementType()
{
	switch (typeID(value))
	{
		case TYPEID_BYTE:
			elementType = ELEMENTTYPE_BYTEFIELD;
			break;
		case TYPEID_INT:
			elementType = ELEMENTTYPE_INTFIELD;
			break;
		case TYPEID_FLOAT:
			elementType = ELEMENTTYPE_FLOATFIELD;
			break;
		case TYPEID_STRING:
			elementType = ELEMENTTYPE_STRINGFIELD;
			break;
		default:
			break;
	}
}

template<typename T>
inline void LCDField<T>::SetValuePointer(T * _value)
{
	value = _value;
}

template<typename T>
inline LCDField<T>::LCDField()
{
	setElementType();
	
}

template<typename T>
inline LCDField<T>::LCDField(T * _value)
{
	setElementType();

	value = _value;
}

template<typename T>
inline void LCDField<T>::Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state)
{

	Display->println("-- LCDField Render");

	// if its first call
	if ((state & B00000001) == B00000001) {
		Display->fillRect(x, y, w, h, Backcolor);
	}


	if (((state & B00000001) == B00000001) || (lastValue != *value)) {

		if (renderMode == FieldValueRenderMode::numeric_value) {

			Display->setCursor(x, y);
			Display->setTextColor(Backcolor);
			Display->print(lastValue);

			Display->setCursor(x, y);
			Display->setTextColor(Forecolor);
			Display->print(*value);

			lastValue = *value;
		
		} else {

			float lastValueR = GetRatio(lastValue);
			float newValueR = GetRatio(*value);

			switch (renderMode)
			{
			case FieldValueRenderMode::numeric_ratio:
				
				Display->setCursor(x, y);

				Display->setTextColor(Backcolor);
				Display->print(lastValueR,3);

				Display->setCursor(x, y);
				Display->setTextColor(Forecolor);
				Display->print(newValueR, 3);
				break;
			case FieldValueRenderMode::numeric_percentage:
				Display->setCursor(x, y);
				Display->setTextColor(Backcolor);
				Display->print(lastValueR * 100);
				Display->print("%");

				Display->setCursor(x, y);
				Display->setTextColor(Forecolor);
				Display->print(newValueR * 100);
				Display->print("%");
				break;

			default:

				Display->fillRect(x, y, w, h, Backcolor);

				GuiDrawingTools::drawValue(1, 1, y, x, w, h, newValueR, renderMode, Display, Forecolor, Backcolor);

				break;
			}


		}

	}
}

template<typename T>
inline float LCDField<T>::GetRatio(int forValue)
{
	return MathTool::GetRatio(forValue, 32767, 1, 0);
}

template<typename T>
inline float LCDField<T>::GetRatio(byte forValue)
{
	return MathTool::GetRatio(forValue, 255, 1, 0);
}

template<typename T>
inline float LCDField<T>::GetRatio(float forValue)
{
	return forValue;
}

template<typename T>
inline float LCDField<T>::GetRatio(String forValue)
{
	return 0.0f;
}


template <typename T>
class LCDProperty : public LCDField<T> {

public:
	T currentValue;

	LCDProperty();

	LCDProperty(T _value);
};


template<typename T>
inline LCDProperty<T>::LCDProperty()
{
	SetValuePointer(&currentValue);
}

template<typename T>
inline LCDProperty<T>::LCDProperty(T _value)
{
	currentValue = _value;
	SetValuePointer(&currentValue);
	
}
