#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include "S0454028_Inventory.h"
#include "S0454028_Inventory.cpp"
using namespace std;

int main()
{
	fstream file("inventory.txt", ios::in | ios::out); // 開檔，讀和寫為同檔 
	if (!file) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	char choice, answer;
	Inventory record; // 建立一個儲存型態為 Inventory的物件叫 record 
	
	do {
		cout << "******************************************" << endl
		     << "*                  Menu                  *" << endl
		     << "*   (a) Add new records to the file      *" << endl
		     << "*   (b) Display any record in the file   *" << endl
		     << "*   (c) Change any record in the file    *" << endl
		     << "******************************************" << endl
		     << "Which one do you want to do? Enter<a/b/c> : ";
		cin >> choice;
		
		if (toupper(choice) == 'A')
			AddRecord(record, file);
		if (toupper(choice) == 'B')
			DisplayRecord(record, file);
		if (toupper(choice) == 'C')
			ChangeRecord(record, file);
		
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
		file.clear(); // 清除指標 
		file.seekg(0L, ios::beg); // 把指標移到檔案開頭 
	} while (toupper(answer) == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	file.close(); // 關檔 
	system("pause");
	return 0;
}
