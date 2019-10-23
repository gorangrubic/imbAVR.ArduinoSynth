/*
  ==============================================================================

    SharedPointerVector.h
    Created: 11 Oct 2019 10:10:30am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template<typename T>
class SharedPointerVector:public std::vector<std::shared_ptr<T>> {
  
public:

	//void Add(T);

	//void Add(T&);
	void Add(T*);

	void Add(std::shared_ptr<T>);

	SharedPointerVector();
	~SharedPointerVector();
};

//template<typename T>
//inline void SharedPointerVector<T>::Add(T item)
//{
//	push_back(std::make_shared<T>(item));
//}

//template<typename T>
//inline void SharedPointerVector<T>::Add(T & item)
//{
//	push_back(std::shared_ptr<T>(&item));
//}

template<typename T>
inline void SharedPointerVector<T>::Add(T * item)
{
	push_back(std::shared_ptr<T>(item));
}

template<typename T>
inline void SharedPointerVector<T>::Add(std::shared_ptr<T> item)
{

	push_back(item);
}

template<typename T>
inline SharedPointerVector<T>::SharedPointerVector()
{
}

template<typename T>
inline SharedPointerVector<T>::~SharedPointerVector()
{

}
