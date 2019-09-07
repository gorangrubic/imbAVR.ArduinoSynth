#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

struct SynthState {


	byte CCValues[127];

	byte out_amp_value = 0;

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

	

	unsigned int cT = 0;
};
