/*
  ==============================================================================

    ModelConstructionTools.h
    Created: 8 Oct 2019 6:04:33am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../Control/imbControlParameterEnumerations.h"
#include "../Control/imbControlParameter.h"

#include "../Model/SynthDeviceModelComponentBase.h"
#include "../Model/SynthDeviceModel.h"

class ModelConstructionTools {
    
    public:
    
		static void Connect(imbControlParameter parameter, SynthDeviceModelComponentBase * _parent);
};