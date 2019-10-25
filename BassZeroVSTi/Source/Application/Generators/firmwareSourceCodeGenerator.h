/*
  ==============================================================================

    firmwareSourceCodeGenerator.h
    Created: 25 Oct 2019 3:32:22am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"

class firmwareSourceCodeGenerator {
    
 
    public:
    
        imbSourceCodeBuilder &builder;
        SynthDeviceModel &model;
        
    
        void GenerateCCMapDefines();
        
        void GenerateCCEnumConversions();
        
        void GenerateEnumConversion(dataEnumDictionary &list);
        
        void GenerateModulationSourceDeclarations();
        void GenerateModulationSourceDeclarations();
        
        void GenerateSignalSources();
        
        
        
        void DataObjectToClass(dataObject &source);
                
        
}