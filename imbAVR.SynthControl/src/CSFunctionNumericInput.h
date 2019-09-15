#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "SynthState.h"
#include "SignalMacroInstruction.h"


template<byte csID, byte ccN0, byte ccN1, byte ccN2, byte ccN3, byte ccN4, byte ccN5, byte ccN6, byte ccN7, byte ccN8, byte ccN9>
class CSFunctionNumericInput
{
public:

	bool Update(CSValuesType * CSValues, CCValuesType * CCValues);


};



template<byte csID, byte ccN0, byte ccN1, byte ccN2, byte ccN3, byte ccN4, byte ccN5, byte ccN6, byte ccN7, byte ccN8, byte ccN9>
inline bool CSFunctionNumericInput<csID, ccN0, ccN1, ccN2, ccN3, ccN4, ccN5, ccN6, ccN7, ccN8, ccN9>::Update(CSValuesType * CSValues, CCValuesType * CCValues)
{
	
	if (CCValues->IsChanged(ccN0)) CSValues->SetValue(csID, 0);
	if (CCValues->IsChanged(ccN1)) CSValues->SetValue(csID, 1);
	if (CCValues->IsChanged(ccN2)) CSValues->SetValue(csID, 2);
	if (CCValues->IsChanged(ccN3)) CSValues->SetValue(csID, 3);
	if (CCValues->IsChanged(ccN4)) CSValues->SetValue(csID, 4);
	if (CCValues->IsChanged(ccN5)) CSValues->SetValue(csID, 5);
	if (CCValues->IsChanged(ccN6)) CSValues->SetValue(csID, 6);
	if (CCValues->IsChanged(ccN7)) CSValues->SetValue(csID, 7);
	if (CCValues->IsChanged(ccN8)) CSValues->SetValue(csID, 8);
	if (CCValues->IsChanged(ccN9)) CSValues->SetValue(csID, 9);
	
	return CSValues->IsChanged(csID);

}
