#pragma once
#ifndef _ROWBASE_h
#define _ROWBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include <ACEMegaHostTFT.h>

//#include <LCDField.h>


#include "FieldValueRenderMode.h"
#include "LCDElement.h"
#include "LCDField.h"
#include "LCDLabel.h"
#include <GuiScreen.h>

class RowBase {

protected:
	

public:

	//LCDElement _Elements[];



	unsigned int Row = 0;

	byte RowHeight = 1;

	byte elements_n;


	virtual void Render(GuiScreen * screen, ACEMegaHostTFTClass * Display, byte state, byte yC) = 0;

	virtual void Deploy(GuiScreen * screen) = 0;

 //void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

 //void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);
	//
	///// <summary>
	///// Returns number of rows (height, in row unit) that this row element takes. Normally, it is 1. 
	///// </summary>
	///// <param name="screen">The screen.</param>
	///// <returns></returns>



	// Inherited via RowBase
	 //void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

};



//template <typename TF>
//inline LCDField<TF> RowBase::SetField<TF>(byte position, byte options, TF * value, FieldValueRenderMode mode)
//{
//	LCDField<TF> field = LCDField<TF>();
//	field.value = value;
//	field.options = options;
//	field.renderMode = mode;
//	_Elements[position] = field;
//
//	return field;
//}

#endif


