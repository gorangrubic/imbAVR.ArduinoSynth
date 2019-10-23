/*
  ==============================================================================

    imbValueSet.h
    Created: 17 Oct 2019 3:02:23pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <map>



//#define SEP_COMMENT " \\\\"
//

class imbValueSet {
 
	    

    
    public:
    
		std::vector<std::string> GetAllIDs();
		std::map<std::string, std::string> data;
		std::map<std::string, std::string> comments;


	void AddComment(std::string id, std::string comment = "");
	void AddValue(std::string id, std::string value);

	std::string EscapeValue(std::string value);
	std::string UnescapeValue(std::string value);

    void Add(std::string id, float value, std::string comment="");
    void Add(std::string id, int value, std::string comment="");
    void Add(std::string id, std::string value, std::string comment="");
    
	/* Returns string data or empty string if not found*/
	std::string GetData(std::string id);
	std::string GetComment(std::string id);

    void Set(std::string id, float &value, float defaultValue=0.0);
    void Set(std::string id, int &value, int defaultValue=0);
    void Set(std::string id, std::string &value, std::string defaultValue="");

	float Get(std::string id, float defaultValue = 0.0);
	int Get(std::string id, int defaultValue = 0);
	std::string Get(std::string id, std::string defaultValue = "");



	static std::vector<std::string> split_string(const std::string & str, const std::string & delimiter);
    
    
    std::string ToString();
    void FromString(std::string input);
    
    
    imbValueSet();
    
};