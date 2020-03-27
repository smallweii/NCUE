#include<iostream>
#include"S0454028_SimpleVector.h"
#include"S0454028_SearchableVector.h"
using namespace std;

int main()
{
	const int SIZE = 10;
	SearchableVector<int> intTable(SIZE);
	SearchableVector<double> doubleTable(SIZE);

	for (int x = 0; x < SIZE; x++) { // store values in the vectors
		intTable[x] = (x * 2);
		doubleTable[x] = (x * 2.14);
	}
	cout << "These values are in intTable : " << endl;
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << " ";
	cout << endl;
	
	cout << "These values are in doubleTable : " << endl;
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << " ";
	cout << endl;

	int result = 0;

	cout << "Searching for 6 in intTable." << endl;
	result = intTable.SearchItem(6);
	if (result == -1)
		cout << "6 was not found in intTable." << endl;
	else
		cout << "6 was found at subscript " << result << endl;
	
	cout << "Searching for 12.84 in doubleTable." << endl;
	result = doubleTable.SearchItem(12.84);
	if (result == -1)
		cout << "12.84 was not found in doubleTable." << endl;
	else
		cout << "12.84 was found at subscript " << result << endl;
	
	system("pause");
	return 0;
}
