#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include<iostream>
#include"SimpleVector.h"
using namespace std;

template <class T>
class SortableVector : public SimpleVector<T>{
    public:
        SortableVector(int s) : SimpleVector<T>(s) // constructor
        {
            ;
        }
        SortableVector(SortableVector &); // copy constructor
        SortableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj) // additional constructor
        {
            
        }
        void print_int() const; // print_int function
        void print_double() const; // print_double function
        void print_bool() const; // print_bool function
};

template <class T>
SortableVector<T>::SortableVector(SortableVector &obj) : SimpleVector<T>(obj) // definition of the copy constructor
{
    ;
}

template <class T>
void SortableVector<T>::print_int() const
{
    for (int i = 0; i < SIZE; i++)
        cout << intTable[i] << " ";
    cout << endl;
}

template <class T>
void SortableVector<T>::print_double() const
{
    for (int i = 0; i < SIZE; i++)
        cout << doubleTable[i] << " ";
    cout << endl;
}

template <class T>
void SortableVector<T>::print_bool() const
{
    for (int i = 0; i < SIZE; i++)
        cout << boolTable[i] << " ";
    cout << endl;
}
#endif
