/*
  ==============================================================================

    dataContextMenu.h
    Created: 24 Oct 2019 4:06:02pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/dataElementIndexMap.h"

class dataContextMenuItem
{
	
public:
	int id;
	std::string label;
	bool isEnabled;
	bool isTicked;

	std::string elementPathID;
	std::string valueAsString;
	
};

template<typename T>
class dataContextMenuItemWithValue:public dataContextMenuItem
{
public:
	T value;
	
};

class dataContextMenu: public PopupMenu {
 
    public:
	
		int currentID = 0;
		dataElementIndexMap elementIndexMap = dataElementIndexMap("");
		dataElementIndexMap elementValueToSet = dataElementIndexMap("*");

	int AddToIndex(std::string elementPathID, std::string elementValueToSet="*")
	{
		currentID++;
		elementIndexMap.Set(currentID, elementPathID);
		if (elementValueToSet!="*") elementValueToSet.Set(currentID, elementValueToSet);

		return currentID;
	};

		//void addItem(std::string elementPathID,
		//	String itemText,
		//	bool isEnabled = true,
		//	bool isTicked = false);

	dataContextMenu() :PopupMenu()
	{
		
	}
	
};