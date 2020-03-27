#include<iostream>
#include<fstream>
#include<ctype.h>
#include"S0454028_Encryption.h"
#include"S0454028_Encryption.cpp"
using namespace std;

int main()
{
	char answer, inFileName[11] = {"origin.txt"}, outFileName[11] = {"result.txt"};
	int num;
	
	do {
		cout << "Please enter a number for the key of encryption (key < 6) : ";
		cin >> num;
		while (num >= 6) { // 防呆，因為 origin檔裡的字元最大到 'y'，若加密值 >=6就重新輸入 
			cout << "Please enter a number for the key of encryption (key < 6) : ";
			cin >> num;
		}
		SimpleEncryption encryption(inFileName, outFileName, num); // 建立一個儲存型態為 SimpleEncryption的物件叫 encryption 
		encryption.doFilter(encryption.inFile, encryption.outFile);
		
		TransformTouppercase touppercase(inFileName, outFileName, num); // 建立一個儲存型態為 TransformTouppercase的物件叫 touppercase 
		touppercase.encrypt();
		
		Copy copy(inFileName, outFileName, num); // 建立一個儲存型態為 Copy的物件叫 copy 
		copy.encrypt();
		
		cout << "Please open result.txt to check the content." << endl; // 可查看已完成全部動作的結果，檔案會續寫 
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	system("pause");
	return 0;
}
