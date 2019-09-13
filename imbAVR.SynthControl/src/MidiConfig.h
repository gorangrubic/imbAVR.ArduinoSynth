#pragma once

#define CC_ChannelVolume 01
#define CC_Balance 8


//
//#define CC_WaveformA_OctaveUp 35
//#define CC_WaveformB_OctaveUp 36
//
//
//#define CC_PerkA_OctaveUp 38
//#define CC_PerkB_OctaveUp 39

#define CC_ChaosTime 121
#define CC_ChaosSpread 113
#define CC_ChaosTimeFactor 105


#define CC_MAINCOMPONENT_Pan_ModSrc 120
#define CC_MAINCOMPONENT_Pan_ModAmt 112
#define CC_MAINCOMPONENT_Pan_Val 104

// ---

#define CC_OperationModes 24


#define CC_PERKB_Pan_ModSrc 80
#define CC_PERKB_Pan_ModAmt 72
#define CC_PERKB_Pan_Val 64

#define CC_PERKB_MonoStereo 55

#define CC_PERKB_Amp_ModSrc 79
#define CC_PERKB_Amp_ModAmt 71
#define CC_PERKB_Amp_Val 63

#define CC_PERKB_PWM 54


//#define CC_Cutoff 29
//#define CC_Resonance 21
//#define CC_Distortion 13
//#define CC_FLTPitch 4

#define CC_PERKA_Pan_ModSrc 78
#define CC_PERKA_Pan_ModAmt 70
#define CC_PERKA_Pan_Val 62

#define CC_PERKA_MonoStereo 53

#define CC_PERKA_Amp_ModSrc 77
#define CC_PERKA_Amp_ModAmt 69
#define CC_PERKA_Amp_Val 61

#define CC_PERKA_PWM 53

//#define CC_PERKA_Amp_Val 57;



#define CC_FLT_Res_ModSrc 76
#define CC_FLT_Res_ModAmt 68
#define CC_FLT_Res_Val 60

#define CC_FLT_CutOff_ModSrc 75
#define CC_FLT_CutOff_ModAmt 67
#define CC_FLT_CutOff_Val 59


#define CC_FLT_Dist_ModSrc 74
#define CC_FLT_Dist_ModAmt 66
#define CC_FLT_Dist_Val 58


#define CC_FLT_Freq_ModSrc 73
#define CC_FLT_Freq_ModAmt 65
#define CC_FLT_Freq_Val 57

#define CC_PERKB_PITCH 51
#define CC_PERKA_PITCH 50

#define CC_WAVEFORMB_PITCH 49
#define CC_WAVEFORMA_PITCH 48

// SCREEN 1

#define CC_WaveformMix 9
#define CC_WaveformA_PWM 6
#define CC_WaveformB_PWM 5
#define CC_WaveformA_Shaper 7
#define CC_WaveformB_Shaper 8

#define CC_AmpAttack 33
#define CC_AmpDecayTime 25
#define CC_AmpRelease 17
#define CC_AmpInitLevel 32
#define CC_AmpSustainLevel 24
#define CC_AmpModificationSource 16

#define CC_FLTAttack 31
#define CC_FLTDecayTime 23
#define CC_FLTRelease 15

#define CC_FLTInitLevel 30
#define CC_FLTSustainLevel 22
#define CC_FLT_ADSR_Mix 14



#define CC_LFOATime 29
#define CC_LFOATimeFactor 21
#define CC_LFOAValue 13

#define CC_LFOBTime 28
#define CC_LFOBTimeFactor 20
#define CC_LFOBValue 12


#define CC_ENVA_ATime 26
#define CC_ENVA_BTime 10
#define CC_ENVA_ALevel 18
#define CC_ENVA_BLevel 1

#define CC_ENVB_ATime 27
#define CC_ENVB_BTime 11
#define CC_ENVB_ALevel 19
#define CC_ENVB_BLevel 2

// ----------------------

#define CS_WAVEFORMA_MOD 0
#define CS_WAVEFORMB_MOD 1
#define CS_WAVEFORMAB_MIX 2
#define CS_MAINCOMPONENT_AMP 3
#define CS_MAINCOMPONENT_PAN 4
#define CS_FLT_CutOff 5
#define CS_FLT_Resonance 6
#define CS_FLT_Freq 7

#define CS_DIST_Mix 8

#define CS_PERKA_AMP 9
#define CS_PERKB_AMP 10
#define CS_PERKA_PAN 11
#define CS_PERKB_PAN 12

#define CS_WAVEFORMA_PWM 13
#define CS_WAVEFORMB_PWM 14
#define CS_PERKA_PWM 15
#define CS_PERKB_PWM 16



#define MDF_OFF 0
#define MDF_ADSR_A 1
#define MDF_ADSR_B 2
#define MDF_Chaos 3
#define MDF_ENV_A 4
#define MDF_ENV_B 5
#define MDF_LFO_A 6
#define MDF_LFO_B 7
#define MDF_VEL 8

#define CHANNEL_ID_ALL 0