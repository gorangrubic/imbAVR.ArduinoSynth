#include "MonitorMessage.h"



void MonitorMessage::SerialWrite(byte Data[MonitorMessageSize_Bytes])
{
	/*
*/

	
	
	//byte Data[MonitorMessageSize_Bytes];

	Data[0] = lowByte(cT);
	Data[1] = highByte(cT);

	Data[2] = State.out_amp_value;
	Data[3] = State.out_flt_gain;
	Data[4] = State.out_flt_value;
	Data[5] = State.out_waveform_a_shaper;
	Data[6] = State.out_waveform_b_flt;
	Data[7] = State.out_waveform_mix;

	Data[8] = 0;
	Data[9] = 0;
	

	//Serial.write(cT);

	for (size_t i = 0; i < 127; i++)
	{
		Data[i + 10] = State.CCValues[i];
	}
	

	//Serial.write(State.out_amp_value);
	//Serial.write(State.out_flt_gain);
	//Serial.write(State.out_flt_value);

	//Serial.write(State.out_waveform_a_shaper);
	//Serial.write(State.out_waveform_b_flt);
	//Serial.write(State.out_waveform_mix);

	
}

void MonitorMessage::SerialRead(byte Data[MonitorMessageSize_Bytes])
{
	cT = Data[0] & Data[1];

	State.out_amp_value = Data[2];
	State.out_flt_gain = Data[3];
	State.out_flt_value = Data[4];
	State.out_waveform_a_shaper = Data[5];
	State.out_waveform_b_flt = Data[6];
	State.out_waveform_mix = Data[7];
	
	for (size_t i = 0; i < 127; i++)
	{
		State.CCValues[i] = Data[i + 10];
	}


}
