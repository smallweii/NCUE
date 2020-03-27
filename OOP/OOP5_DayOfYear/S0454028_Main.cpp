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
		while (d < 1 || d > 365) // 超出範圍就重新輸入 
		{
			cout << "Out of the range!" << endl;
			cout << "Please enter a day from 1 to 365 : ";
			cin >> d;
		} 
		DayOfYear Date(d); // 建立儲存型態為 DayOfYear的物件叫 Date 
		
		cout << "Day " << d << " would be ";
		Date.translate(d);
		Date.check();
		Date.print();
		
		cout << "Previous day is ";
		--Date; // overloaded operator(回到前一天)
		Date.check();
		Date.print();
		
		++Date; // overloaded operator(回到今天)
		Date.check();
		cout << "Next day is ";
		++Date; // overloaded operator(回到後一天)
		Date.check();
		Date.print();
		
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;	
}
