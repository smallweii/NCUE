#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
using namespace std;
#ifndef SEARCH_H
#define SEARCH_H

class Search{ // 建立一個叫 Search的 class 
	public :
		fstream file; // 宣告 fstream物件叫 file 
		string str; // 宣告以字串型態的字串叫 str 
		Search(char *filename, string s); // constructor用來開檔  
		~Search(); // destructor用來關檔  
		void search(); // 找字串 
};
#endif
