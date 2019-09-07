// RowBase.h

#ifndef _ROWBASE_h
#define _ROWBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <LCDField.h>

#include <GuiScreen.h>
#include <ACEMegaHostTFT.h>

class RowBase : public LCDField {


public:

	unsigned int Row = 0;

	

	virtual void PrintLabels(ACEMegaHostTFTClass * Display) = 0;

	virtual void UpdateFields(ACEMegaHostTFTClass * Display) = 0;
	
	/// <summary>
	/// Returns number of rows (height, in row unit) that this row element takes. Normally, it is 1. 
	/// </summary>
	/// <param name="screen">The screen.</param>
	/// <returns></returns>
	virtual byte Deploy(GuiScreen screen) = 0;

};

#endif

