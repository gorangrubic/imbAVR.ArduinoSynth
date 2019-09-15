#pragma once
#define CHANNEL_ID_ALL 0

#define CC_ChannelVolume 01
#define CC_Balance 8

#define CC_ChaosTime 121
#define CC_ChaosSpread 113
#define CC_ChaosTimeFactor 105


#define CC_MASTER_Pan_ModSrc 120
#define CC_MASTER_Pan_ModAmt 112
#define CC_MASTER_Pan_Val 104


#define CC_OPM_MODA_ModSrc 127
#define CC_OPM_MODA_ModAmt 119
#define CC_OPM_MODA_Val 111

#define CC_OPM_MODB_ModSrc 126
#define CC_OPM_MODB_ModAmt 118
#define CC_OPM_MODB_Val 110

#define CC_OPM_VAL_A 125
#define CC_OPM_VAL_B 117
#define CC_OPM_VAL_C 109


// ---------------------------------------------- SCREEN 2

#define CC_OperationModes 24




#define CC_PERKB_Amp_ModSrc 79
#define CC_PERKB_Amp_ModAmt 71
#define CC_PERKB_Amp_Val 63

#define CC_PERKB_PWM 54

#define CC_PERKA_Amp_ModSrc 77
#define CC_PERKA_Amp_ModAmt 69
#define CC_PERKA_Amp_Val 61

#define CC_PERKA_PWM 53


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

// ---------------------------------------------- SCREEN 1

#define CC_WaveformMix 9

#define CC_WaveformA_SigGen_mod 55
#define CC_WaveformB_SigGen_mod 56

#define CC_WaveformA_PWM 6
#define CC_WaveformB_PWM 5

#define CC_WaveformA_Phase 55
#define CC_WaveformB_Phase 56

#define CC_PERKA_SigGen_mod 57
#define CC_PERKB_SigGen_mod 58

#define CC_PERKA_Phase 57
#define CC_PERKB_Phase 58

#define CC_PERKA_Pan_ModSrc 81
#define CC_PERKA_Pan_ModAmt 73
#define CC_PERKA_Pan_Val 65


#define CC_PERKB_Pan_ModSrc 82
#define CC_PERKB_Pan_ModAmt 74
#define CC_PERKB_Pan_Val 66

//
//#define CC_SIGEN_Mod_ModSrc 55

//#define CC_WaveformB_Shaper_ModSrc 80
//#define CC_WaveformB_Shaper_ModAmt 72
//#define CC_WaveformB_Shaper_Val 64


#define CC_WaveformB_Shaper_ModSrc 80
#define CC_WaveformB_Shaper_ModAmt 72
#define CC_WaveformB_Shaper_Val 64

#define CC_WaveformA_Shaper_ModSrc 78
#define CC_WaveformA_Shaper_ModAmt 70
#define CC_WaveformA_Shaper_Val 62


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

// ======================================== Control values

#define CS_WAVEFORMA_MOD 0
#define CS_WAVEFORMB_MOD 1
#define CS_WAVEFORMAB_MIX 2
#define CS_PERKA_L_AMP 3
#define CS_PERKA_R_AMP 4
#define CS_FLT_CutOff 5
#define CS_FLT_Resonance 6
#define CS_FLT_Freq 7

#define CS_DIST_Mix 8

#define CS_PERKB_L_AMP 9
#define CS_PERKB_R_AMP 10
#define CS_MASTER_L_AMP 11
#define CS_MASTER_R_AMP 12

#define CS_WAVEFORMA_PWM 13
#define CS_WAVEFORMB_PWM 14
#define CS_PERKA_PWM 15
#define CS_PERKB_PWM 16

#define CS_WAVEFORMA_PHASE 17
#define CS_WAVEFORMB_PHASE 18
#define CS_PERKA_PHASE 19
#define CS_PERKB_PHASE 20

#define CS_WAVEFORMA_MODBYTE 21
#define CS_WAVEFORMB_MODBYTE 22
#define CS_PERKA_MODBYTE 23
#define CS_PERKB_MODBYTE 24

#define CS_OPM_MODA 25
#define CS_OPM_MODB 26
#define CS_OPM_VALA 27
#define CS_OPM_VALB 28
#define CS_OPM_VALC 29


// ======================================== MDF 

#define MDF_OFF 0
#define MDF_ADSR_A 1
#define MDF_ADSR_B 2
#define MDF_Chaos 3
#define MDF_ENV_A 4
#define MDF_ENV_B 5
#define MDF_LFO_A 6
#define MDF_LFO_B 7
#define MDF_VEL 8

// ======================================= Signal ID


#define SID_WaveformA 4
#define SID_WaveformB 5
#define SID_FLT_Freq 2
#define SID_FLT_FreqB 3
#define SID_PerkA 0
#define SID_PerkB 1

#define SID_Group1 13
#define SID_Group2 14
#define SID_Group3 15
#define SID_Master 16


// ===================================== ID of signal instruction CC 

#define CID_NoteControl 1
#define CID_PWM 2
#define CID_Phase 3
#define CID_Pitch 4
#define CID_Live 5



// ======================================= Synth Operation Modes

#define OPM_BassLine 0
#define OPM_LeadSynth 1
#define OPM_KickDrum 2
#define OPM_ShortFX 3
#define OPM_LongFX 4
#define OPM_Keys 5
#define OPM_FatSynth 6
#define OPM_Uplifters 7
#define OPM_Downlifters 8
#define OPM_ChaosFX 9