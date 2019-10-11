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
	Items.add(item);

	//Items.push_back(item);
}

int imbEnumerationList::IndexOf(String item)
  {
	return Items.indexOf(item, false, 0);

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

int imbEnumerationList::Count()
{
	return Items.size();
}

StringArray imbEnumerationList::GetItems()
{
	return Items;
	
}
//
//imbEnumerationList::imbEnumerationList()
//{
//}
