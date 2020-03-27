#include<iostream>
#include"S0454028_SimpleVector.h"
using namespace std;
#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

template <class T>
class SearchableVector : public SimpleVector<T>{
	public:
		SearchableVector(int s) : SimpleVector<T>(s) // constructor
		{
			;
		}
		SearchableVector(SearchableVector &); // copy constructor
		SearchableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj) // additional constructor
		{
			;
		}
		int SearchItem(T); // SearchItem函式中以T型態當參數 
};

template <class T>
SearchableVector<T>::SearchableVector(SearchableVector &obj) : SimpleVector<T>(obj) // 定義 copy constructor 
{
	;
}

template <class T> 
int SearchableVector<T>::SearchItem(T item) // binary search 
{
	int low = 0, upper = 9, count = 0;
	
	while (low <= upper) {
		int mid = (low + upper) / 2;
	
		if (item < this->operator[](mid))
			upper = mid - 1;
		if (item > this->operator[](mid))
			low = mid + 1;
		if (item == this->operator[](mid))
			return mid;
	}
	return -1;
}
#endif
