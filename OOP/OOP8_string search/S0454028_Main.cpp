#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
#include "S0454028_Search.h"
#include "S0454028_Search.cpp"
using namespace std;

int main()
{
	char filename[50], answer;
	string s;
	
	do {
		cout << "Please enter the name of a file(ex: filename.txt) : ";
		cin >> filename;
		do {
			cout << "Please enter a string to search for : ";
			cin >> s;
			Search find(filename, s); // 建立一個儲存型態為 Search的物件叫 find 
			find.search();
			cout << endl << "The same file again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
			cin >> answer;
		} while (toupper(answer) == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
		
		cout << endl << "The whole test again? Enter<y/n> : ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	system("pause");
	return 0;
}
