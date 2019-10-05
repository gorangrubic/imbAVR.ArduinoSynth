/*
  ==============================================================================

    SynthDeviceModel.h
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "Components\Distortion.h"
#include "Components\Mixer.h"
#include "Components\OscilatorWaveform.h"
#include "Components\OscilatorPerk.h"
#include "Components\ResonanceFilter.h"

#include "Modulation\ModulationFunctionADSR.h"
#include "Modulation\ModulationFunctionENV.h"
#include "Modulation\ModulationFunctionLFO.h"
#include "Modulation\ModulationSourceMacroControl.h"
#include "Modulation\ModulationSourceMIDI.h"
#include "Modulation\ModulationSourceBase.h"
#include "Modulation\ModulationHub.h"

#include "SynthDeviceModelComponentBase.h"

#include <vector>

#include "../Control/imbSynthAudioProcessor.h";



class SynthDeviceModel:SynthDeviceModelComponentBase {
 
protected:

	void PreDeployModel();
	void AfterDeployModel();
    
    public:
    
		imbSynthAudioProcessor * SynthProcessor;

		ParameterController parameterController;

		static String GetLetter(unsigned int input) {
			switch (input) {
			case 0:
				return "A";
				break;
			case 1:
				return "B";
				break;
			case 2:
				return "C";
				break;
			case 3:
				return "D";
				break;
			case 4:
				return "E";
				break;
			case 5:
				return "F";
				break;
			case 6:
				return "G";
				break;
			case 7:
				return "H";
				break;
			case 8:
				return "I";
				break;
			case 9:
				return "J";
				break;
			}

			return "W";
		}

		template<typename T>
		static int GetIndex(std::vector<T>* items, T toFind) {
			int i = 0;
			
			for each (T var in items)
			{
				if (var == toFind) {
					break;
				}
				i++;
			}

			if (i >= items->size) {
				return -1;
			}

			return i;
		}

		/// <summary>
/// Deploys this instance.
/// </summary>
		void Deploy() override;

		virtual void DeployModel(imbSynthAudioProcessor * synthProcessor) = 0;

		//std::vector<ModulationFunctionADSR> ModADSRs;
		//std::vector<ModulationFunctionENV> ModENVs;
		//std::vector<ModulationFunctionLFO> ModLFOs;
		//std::vector<ModulationSourceMacroControl> MacroControls;
		//std::vector<ModulationSourceMIDI> MIDIs;

		ModulationHub modulations;

		SynthDeviceModel(String _shortName, String _longName) :SynthDeviceModelComponentBase(NULL, NULL, _shortName, _longName) {
		
		}
    
};