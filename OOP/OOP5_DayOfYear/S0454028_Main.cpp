#include<iostream>
#include"S0454028_DayOfYear.h"
#include"S0454028_DayOfYear.cpp"
using namespace std;

int main()
{
	int d;
	char answer;
	
	do{
		cout << "Please enter a day from 1 to 365 : ";
		cin >> d;
		while (d < 1 || d > 365) // �W�X�d��N���s��J 
		{
			cout << "Out of the range!" << endl;
			cout << "Please enter a day from 1 to 365 : ";
			cin >> d;
		} 
		DayOfYear Date(d); // �إ��x�s���A�� DayOfYear������s Date 
		
		cout << "Day " << d << " would be ";
		Date.translate(d);
		Date.check();
		Date.print();
		
		cout << "Previous day is ";
		--Date; // overloaded operator(�^��e�@��)
		Date.check();
		Date.print();
		
		++Date; // overloaded operator(�^�줵��)
		Date.check();
		cout << "Next day is ";
		++Date; // overloaded operator(�^���@��)
		Date.check();
		Date.print();
		
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;	
}
