#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption{ // 建立一個叫 Encryption的 abstract class 
	public:
		ifstream inFile; // 宣告 ifstream物件叫 inFile
		ofstream outFile; // 宣告 ofstream物件 outFile
		int key; // 宣告以整數型態的加密值叫 key 
		
		Encryption(char *inFileName, char *outFileName, int num); // constructor用來開檔 
		~Encryption(); // destructor用來關檔 
		
		virtual char transform(char ch) const = 0; // 讓 subclass重新定義的 pure virtual function
		void doFilter(ifstream &in, ofstream &out); // 開檔後的動作 
		void encrypt(); // 加密 
};
class SimpleEncryption : public Encryption{ // 建立一個叫 SimpleEncryption的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元加密後的字元回傳 
		{
			return ch + key;
		}
		SimpleEncryption(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class TransformTouppercase : public Encryption{ // 建立一個叫 TransformTouppercase的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元轉大寫後回傳 
		{
			return toupper(ch);
		}
		TransformTouppercase(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class Copy : public Encryption{ // 建立一個叫 Copy的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元複製後回傳 
		{
			return ch;
		}
		Copy(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
#endif
