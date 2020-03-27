#include<iostream>
#include<fstream>
#include<ctype.h>
#include"S0454028_Encryption.h"
using namespace std;

Encryption::Encryption(char *inFileName, char *outFileName, int num) // constructor用來開檔 
{
	inFile.open(inFileName);
	outFile.open(outFileName, ios::app); // 從已存在檔的尾端續寫並不清除原檔 
	key = num; // 把使用者輸入的加密值 num assign給 key 
	
	if (!inFile) { // 檢查檔案是否成功開啟  
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	if (!outFile) {
		cout << "Can't open the file!" << endl;
		exit(1);
	}
}
Encryption::~Encryption() // destructor用來關檔 
{
	inFile.close();
	outFile.close();
}
void Encryption::doFilter(ifstream &in, ofstream &out) // 開檔後的動作 
{
	encrypt();
}
void Encryption::encrypt() // 加密 
{
	char ch, transCh;
	
	inFile.get(ch); // 從 inFile讀入一個字元 
	while (!inFile.fail()) { // 若讀到字元就進來，讀不到字元就跳出迴圈 
		transCh = transform(ch);
		outFile.put(transCh); // 轉換完的一個字元寫入 outFile 
		inFile.get(ch);
	}
	outFile.put('\n'); // 換行符號寫入 outFile  
	outFile.put('\n');
}
