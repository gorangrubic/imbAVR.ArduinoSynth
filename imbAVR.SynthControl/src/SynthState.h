#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include "MonitoredArray.h"



typedef MonitoredArray<16> CCValuesType;
typedef MonitoredArray< 2 > MDFValuesType;
typedef MonitoredArray< 3 > CSValuesType;


struct SynthState {

	//// Received MIDI CC values
	//CCValuesType CCValues;

	//// Computed values of Time-based ControlFunctions (ADSR, LFO...)
	///* position 0 is reserved to OFF */
	//MDFValuesType MDFValues;

	//// Control Synth values -- applied to hardware
	//MDFValuesType CSValues;

	// Received MIDI CC values
	CCValuesType CCValues;

	// Computed values of Time-based ControlFunctions (ADSR, LFO...)
	/* position 0 is reserved to OFF */
	MDFValuesType MDFValues;

	// Control Synth values -- applied to hardware
	CSValuesType CSValues;

	/*byte out_amp_value = 0;

	byte out_mainComponent_pan = 127;
	byte out_mainComponent_gain = 127;

	byte out_flt_value = 64;
	byte out_flt_gain = 0;


	byte out_waveform_b_flt = 0;
	byte out_waveform_a_shaper = 0;

	byte out_waveform_mix = 0;

	byte out_distortion_mix = 127;

	byte out_perkA_amp = 0;
	byte out_perkB_amp = 0;


	byte out_shapeA_pwm = 0;
	byte out_shapeB_pwm = 0;

	

	unsigned int cT = 0;*/
};
