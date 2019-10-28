#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

/* this class template is taken from: https://stackoverflow.com/questions/1448396/how-to-use-enums-as-flags-in-c/43213134#43213134 */
/* Author: uliwitness (stackoverflow user: https://stackoverflow.com/users/242278/uliwitness ) */
template<class ENUM, class UNDERLYING = typename std::underlying_type<ENUM>::type>
class SafeEnum
{
public:
	SafeEnum() : mFlags(0) {}
	SafeEnum(ENUM singleFlag) : mFlags(singleFlag) {}
	SafeEnum(const SafeEnum& original) : mFlags(original.mFlags) {}

	SafeEnum&   operator |=(ENUM addValue) { mFlags |= addValue; return *this; }
	SafeEnum    operator |(ENUM addValue) { SafeEnum  result(*this); result |= addValue; return result; }
	SafeEnum&   operator &=(ENUM maskValue) { mFlags &= maskValue; return *this; }
	SafeEnum    operator &(ENUM maskValue) { SafeEnum  result(*this); result &= maskValue; return result; }
	SafeEnum    operator ~() { SafeEnum  result(*this); result.mFlags = ~result.mFlags; return result; }


	bool HasFlag(ENUM value)
	{
		UNDERLYING value_base = (UNDERLYING)value;
		
		return mFlags & value_base == value_base;
	}

	explicit operator bool() { return mFlags != 0; }

protected:
	UNDERLYING  mFlags;
};
/*
  ==============================================================================

    SafeEnum.h
    Created: 26 Oct 2019 5:51:25am
    Author:  gorangrubic

  ==============================================================================
*/


