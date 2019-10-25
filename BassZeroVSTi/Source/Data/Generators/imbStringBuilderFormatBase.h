/*
  ==============================================================================

    imbStringBuilderFormatBase.h
    Created: 24 Oct 2019 11:53:50am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "imbStringBuilderFormatRule.h"

class imbStringBuilderFormatBase {
    
 
    public:
    
    imbStringBuilderFormatRule StartBlockRule;
    imbStringBuilderFormatRule EndBlockRule;
    
    imbStringBuilderFormatListRule AppendListItemRule;
    
    
    imbStringBuilderFormatRule AppendRule;
    imbStringBuilderFormatRule AppendItalicRule;
    imbStringBuilderFormatRule AppendBoldRule;
    imbStringBuilderFormatRule AppendBoldItalicRule;
    imbStringBuilderFormatRule AppendBoldItalicRule;
    imbStringBuilderFormatRule AppendNewLineRule;
    
    imbStringBuilderFormatRule AppendLinkRule;
    imbStringBuilderFormatRule AppendImageRule;
    imbStringBuilderFormatRule AppendCommentRule;
    
    
}