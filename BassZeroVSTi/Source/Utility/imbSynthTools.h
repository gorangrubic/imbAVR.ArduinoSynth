/*
  ==============================================================================

    imbSynthTools.h
    Created: 8 Oct 2019 1:59:00am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameterEnumerations.h"

//#include "../Source/Model/ModelConstructionTools.h"
#include <vector>

class imbSynthTools {
 
    public:
    

		static int StringToInt32(juce::String stringValue, float defaultValue);

		static float StringToFloat(juce::String stringValue, float defaultValue);

		static int StringToInt32(juce::String stringValue, int defaultValue);


		//static void imbSynthTools::SetParameter(AudioProcessorParameterGroup * group, imbControlParameter p)
		//{

		//	NormalisableRange<float> valueRange = NormalisableRange<float>(p.MinValue, p.MaxValue, p.IntervalValue);

		//	/*pt p = pt(parameterIDPath, parameterID, parameterLabel, valueRange, Value, nullptr, nullptr, isMetaValue, isAutomatizable, isDescreteValue, category, typeParameter == imbControlParameterType::Boolean);
		//	parameter = &p;
		//	parameter->addListener(this);
		//	std::unique_ptr<RangedAudioParameter> ptr = std::unique_ptr<RangedAudioParameter>(&p);*/

		//	//parameterControllerPtr->parameters->createAndAddParameter(ptr);

		//	auto pe = modelConstructionTools.parameterController.parameters->createAndAddParameter(p.parameterIDPath, p.parameterID, p.parameterLabel, valueRange, p.Value, nullptr, nullptr, p.isMetaValue, p.isAutomatizable, p.isDescreteValue, p.category, p.typeParameter == imbControlParameterType::Boolean);
		//	

		//}


		static float ProcessValue(float _value, imbControlParameterType TP);
		
		
		template<imbControlParameterType TP>
		static float textToFloat(const String& s) {
			imbControlParameterType TP = imbControlParameterType::Integer;
			switch (TP) {
			case imbControlParameterType::Boolean:
				return s == "yes" ? 1.0f : 0.0f;

				break;
			default:
				return s.getFloatValue();
				break;
			}

			return s.getFloatValue();
		}

		template<imbControlParameterType TP>
		static String floatToText(float fi) {

			imbControlParameterType TP = imbControlParameterType::Integer;
			switch (TP) {
			case imbControlParameterType::Boolean:
				return fi < 0.5f ? "no" : "yes";
				break;
			default:
				return String((int)fi);
				break;
			}

			return String((int)fi);
		}

		static std::string GetLetter(unsigned int input);
    

		template <typename T>
		std::pair<bool, int > findInVector(const std::vector<T>  & vecOfElements, const T  & element)
		{
			std::pair<bool, int > result;

			// Find given element in vector
			auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);

			if (it != vecOfElements.end())
			{
				result.second = distance(vecOfElements.begin(), it);
				result.first = true;
			}
			else
			{
				result.first = false;
				result.second = -1;
			}

			return result;
		}

		template<typename T>
		static int GetIndex(std::vector<T> items, T toFind) {
			int i = 0;
			//std::vector<T> items_data = &items;

			for each (T var in items)
			{
				if (var == toFind) {
					break;
				}
				i++;
			}

			if (i >= items->size()) {
				return -1;
			}

			return i;
		}

    
};