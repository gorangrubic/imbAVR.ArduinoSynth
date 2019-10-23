/*
  ==============================================================================

    imbEnumerationList.cpp
    Created: 11 Oct 2019 2:42:42am
    Author:  gorangrubic

  ==============================================================================
*/

#include "imbEnumerationList.h"

void imbEnumerationList::Add(String item)
{
	//Items.add(item);

	if (IndexOf(item) == -1) {
		Items.push_back(item);
	}
}

int imbEnumerationList::IndexOf(String item)
  {

	
	int index = -1;

	std::vector<String>::iterator iter = std::find(Items.begin(), Items.end(), item);

	if (iter != Items.end())
	{
		index = std::distance(Items.begin(), iter);
		
	}

	return index;//td::find(Items.begin(),  // Items.indexOf(item, false, 0);

	//int i = 0;
	//int output = -1;
	//for each (String var in Items)
	//{
	//	if (var == item) {
	//		output = i;
	//		break;
	//	}
	//	i++;
	//}
	//return output;
  }

String imbEnumerationList::AtIndex(int i)
{
	if (i < 0) return "";
	if (i >= Count()) return "";
	return Items.at(i);
}

int imbEnumerationList::Count()
{
	return Items.size();
}

void imbEnumerationList::ClearAll()
{
	Items.clear();
}

//StringArray imbEnumerationList::GetItems()
//{
//	return Items;
//	
//}
//
//imbEnumerationList::imbEnumerationList()
//{
//}
