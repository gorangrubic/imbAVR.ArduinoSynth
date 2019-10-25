/*
  ==============================================================================

    dataPatternObject.h
    Created: 25 Oct 2019 3:16:46pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "dataObjectPropertyBase.h"
#include "../Source/Data/Structures/imbValueSet.h"
#include "dataObject.h"
//#include <cstdint>

#include "../Source/Application/SynthApplicationEnvironment.h"

class dataPatternObject:public dataObject {
 
    public:

		
	
		int patternSize = 8;
		parameterValueType cellType;

		void Set(std::vector<float> pattern);

		template<typename T>
		void Set(T byte)
		{
			int bit_sel = 1;
			for (size_t i = 0; i < std::min(sizeof(byte)*8, patternSize); i++)
			{
				auto t = (byte & bit_sel) == bit_sel;

				GetCell(i)->SetBoolValue(t);

				bit_sel = bit_sel << 1;
			}
		};

		template<typename T>
		T Get()
		{
			T output;
			int bit_sel = 1;
			for (size_t i = 0; i < std::min(sizeof(output)*8, patternSize); i++)
			{
				//auto t = (byte & bit_sel) == bit_sel;

				if (GetCell(i)->GetBoolValue())
				{
					output = output | bit_sel;
				}

				bit_sel = bit_sel << 1;
			}
			return output;
		};

		dataObjectProperty * GetCell(int i);

		std::vector<dataObjectProperty *> GetAllCells();
	
		std::string GetCellID(int i);
	
		std::vector<float> GetFloatPattern()
		{
			std::vector<float> output;
			int bit_sel = 1;
			for (size_t i = 0; i < patternSize; i++)
			{

				output.push_back(GetCell(i)->GetFloatValue());

			}
			return output;
		}
	
		std::vector<bool> GetBoolPattern()
		{
			std::vector<bool> output;
			int bit_sel = 1;
			for (size_t i = 0; i < patternSize; i++)
			{
				
				output.push_back(GetCell(i)->GetBoolValue());
				
			}
			return output;
		};


		template<typename T>
		void init(T pattern)
		{
			cellType = parameterValueType::Boolean;
			patternSize = sizeof(pattern) * 8;
			elementClassRole = "dataPatternObject";
			int bit_sel = 1;

			for (size_t i = 0; i < patternSize; i++)
			{
				String cid = "c" + String(i);
				String clabel = "C " + String(i);
				
				auto t = (pattern & bit_sel) == bit_sel;

				Add(&dataBoolProperty(cid.toStdString(), t, clabel.toStdString(), "Pattern cell", "", "", _parClass));

				bit_sel = bit_sel << 1;
			}
			
		};

		dataPatternObject(long long pattern, std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
			:dataObject(_name, _label, _description, "", _helpUrl)
		{
			init<long long>(pattern);
		}

		dataPatternObject(long pattern, std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
			:dataObject(_name, _label, _description, "", _helpUrl)
		{
			init<long>(pattern);
		}
	
		dataPatternObject(short pattern, std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
			:dataObject(_name, _label, _description, "", _helpUrl)
		{
			init<short>(pattern);
		}

		
		dataPatternObject(char pattern, std::string _name = "", std::string _label = "", std::string _description = "" , std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
			:dataObject(_name, _label, _description, "", _helpUrl)
		{
			init<char>(pattern);
		}

		dataPatternObject(std::string _name = "", std::string _label = "", std::string _description = "", std::vector<float> _values = std::vector<float>(), parameterValueType _cellType = parameterValueType::Boolean, std::string _helpUrl = "",
			float minValue = 0, float maxValue = 0, parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
			:dataObject(_name, _label, _description, "", _helpUrl) {
			patternSize = _values.size();
			elementClassRole = "dataPatternObject";

			for (size_t i = 0; i < patternSize; i++)
			{

				String cid = "c" + String(i);
				String clabel = "C " + String(i);
				float v = 0;

				if (i < _values.size()) {
					v = _values.at(i);
				}

				switch (_cellType)
				{
				case parameterValueType::Boolean:
					Add(&dataBoolProperty(cid.toStdString(), (v > 0.5), clabel.toStdString(), "Pattern cell", "", "", _parClass));
					break;
				default:
				case parameterValueType::Float:
					Add(&dataObjectProperty(cid.toStdString(), _cellType, clabel.toStdString(), "Pattern cell", "", "", minValue, maxValue, _parClass, dataElementFeatures::none, v));
					break;
				case parameterValueType::Integer:
					Add(&dataIntProperty(cid.toStdString(), (int)v, clabel.toStdString(), "Pattern cell", "", "", (int)minValue, (int)maxValue, _parClass, dataElementFeatures::none));
					break;
				}
			}
			
		}
};