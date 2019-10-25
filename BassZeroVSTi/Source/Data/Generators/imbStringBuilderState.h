/*
  ==============================================================================

    imbStringBuilderState.h
    Created: 24 Oct 2019 11:57:47am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
class imbStringBuilderState {
 
    public:
    
    int tabLevel = 0;
    int blockLevel = 0;
    
    int listLevel = 0;
    
    void StartListNode() {
     
        listLevel++;
    }
    void CloseListNode() {
     
        listLevel--;
        if (listLevel < 0) listLevel = 0;
    }
    void CloseAllListNodes() {
     
        listLevel = 0;
    }
    
    void StartBlock();
    
    void CloseBlock();
    
    void CloseAllBlocks();
    
    void NextTab() {
    
        tabLevel++;
    };
    
    void PrevTab() {
     
        tabLevel--;
        if (tabLevel < 0) tabLevel = 0;
    }
    void RootTab() {
     
        tabLevel = 0;
    }
    
    
}