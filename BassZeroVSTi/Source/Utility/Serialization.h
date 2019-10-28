/*
  ==============================================================================

    Serialization.h
    Created: 27 Oct 2019 7:40:46pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template<typename TData>
union customData {
	TData instance;
	int size = sizeof(TData);
	unsigned char bytes[sizeof(TData)];
};


class Serialization {

public:

	template<typename T>
	static std::vector<unsigned char> toBytes(T &data) {

		std::vector<unsigned char> output;

		customData<T> c;
		c.instance = data;
		for (size_t i = 0; i < c.size; i++)
		{
			output.push_back(c.bytes[i]);
		}

		return output;
	};

	template<typename T>
	static T fromBytes(std::vector<unsigned char> &data) {
		T output;

		customData<T> c;
		std::vector<unsigned char> bytes = toBytes<T>(data);

		for (size_t i = 0; i < c.size; i++)
		{
			c.bytes[i] = bytes.at(i);
		}


		return c.instance;
	};

	template<typename T>
	static std::string toString(T &data, bool useBase64 = false) {

		customData<T> c;
		std::vector<unsigned char> bytes = toBytes<T>(data);
		std::string vl = "";
		
		if (useBase64) {
			vl = base64_encode(c.bytes, c.size);
		}
		else {
			vl = vl.append(c.bytes, c.size);
		}

		return vl;
	};

	template<typename T>
	static T fromString(std::string const& s, bool useBase64=false) {

		std::string vl = "";
		if (useBase64) {
			vl = base64_decode(s);
		}
		else {
			vl = s;
		}

		customData<T> c;

		for (size_t i = 0; i < s.size(); i++)
		{
			c.bytes[i] = s.at(i);
		}

		return c.instance;
	};

	static std::string base64_encode(unsigned char const*, int len);
	static std::string base64_decode(std::string const& s);
};



// #endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */