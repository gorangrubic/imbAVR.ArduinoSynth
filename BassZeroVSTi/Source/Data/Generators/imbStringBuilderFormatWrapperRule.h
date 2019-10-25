/*
  ==============================================================================

    imbStringBuilderFormatWrapperRule.h
    Created: 24 Oct 2019 12:42:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "imbStringBuilderFormatRule.h"

class imbStringBuilderFormatWrapperRule:public imbStringBuilderFormatRule {

    std::string prefix {""};
    std::string suffix {""};
    
    enum class StateVariable {
     
        none=0,
        tabLevel,
        listLevel,
        blockLevel
    }
    
    StateVariable doRepeatSuffixVariable = StateVariable::none;
    StateVariable doRepeatPrefixVariable = StateVariable::none;
    
    std::string Repeat(StateVariable var, std::string input,imbStringBuilderState &state) {
     
        std::string output = "";
        
        int i = 1;
        
        switch (StateVariable) {
         
            case StateVariable::none:
            break;
            case StateVariable::tabLevel:
            break;
            case StateVariable::listLevel:
            break;
            case StateVariable::blockLevel:
                i = state.blockLevel;
            break;
        }
        
        
    }
    
 public:   
 
    std::string GetPrefix(imbStringBuilderState &state) {
        
        int i = 1;
        
        
        
        return prefix;
    }
    
    std::string GetSuffix(imbStringBuilderState &state) {
        return suffix;
    }
    
    std::string GetFormatted(std::string content, imbStringBuilderState &state) {
     
        return GetPrefix(state) + content + GetSuffix(state);
        
    }
    
    imbStringBuilderFormatWrapperRule(std::string _prefix, std::string _suffix) {
        prefix = _prefix;
        suffix = _suffix;
    }
}