#include<iostream>
#include"S0454028_Pstring.h"
#include"S0454028_Pstring.cpp"
using namespace std;

int main()
{
	string s;
	char answer;
	
	do {
		cout << "Please enter a string : ";
		cin >> s;
		
		Pstring pstr(s); // 建立一個儲存型態為 Pstring的物件叫 pstr 
		bool palindrome = pstr.isPalindrome(); // 宣告一個布林型態的變數叫 palindrome，是以物件 pstr傳進 isPalindrome函數回傳的值 
		
		if (palindrome == true) // 若回傳true表示此字串為回文，反之則不為回文 
			cout << "The string is a palindrome." << endl;
		else
			cout << "The string is not a palindrome." << endl;
		
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	system("pause");
	return 0;
}
