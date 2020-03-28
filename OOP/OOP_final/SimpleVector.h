#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include<iostream>
using namespace std;

template <class T>
class SimpleVector{
    private:
        T *aptr;
        int arraySize;
        void subError() const; // handle subscripts out of range
        
    public:
        SimpleVector() // default constructor
        {
            aptr = 0;
            arraySize = 0;
        }
        SimpleVector(int); // constructor
        SimpleVector(const SimpleVector &); // copy constructor
        ~SimpleVector(); // destructor
        int size() const; // return arraySize
        T &operator[](int); // overloaded [] operator
        void print() const; // output array
};

template <class T>
SimpleVector<T>::SimpleVector(int s) // constructor for SimpleVector class
{
    arraySize = s; // set the size of the array
    aptr = new T [s]; // allocate memory
    for (int count = 0; count < arraySize; count++)
        aptr[count] = T();
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) // copy constructor for SimpleVector class
{
    arraySize = obj.arraySize;
    aptr = new T [arraySize];
    for (int count = 0; count < arraySize; count++)
        aptr[count] = obj[count];
}

template <class T>
SimpleVector<T>::~SimpleVector() // destructor for SimpleVector class
{
    if (arraySize > 0)
        delete [] aptr;
}

template <class T>
void SimpleVector<T>::subError() const // subError function
{
    cout << "Error : Subscript out of range." << endl; // display an error message
    exit(0); // terminate the program when a subscript is out of range
}

template <class T>
T &SimpleVector<T>::operator[](int sub) // overloaded [] operator
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template <class T>
void SimpleVector<T>::print() const // print function
{
    for (int i = 0; i < arraySize; i++)
        cout << aptr[i] << " ";
    cout << endl;
}
#endif
