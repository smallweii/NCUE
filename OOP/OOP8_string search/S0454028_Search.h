#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
using namespace std;
#ifndef SEARCH_H
#define SEARCH_H

class Search{ // �إߤ@�ӥs Search�� class 
	public :
		fstream file; // �ŧi fstream����s file 
		string str; // �ŧi�H�r�ꫬ�A���r��s str 
		Search(char *filename, string s); // constructor�ΨӶ}��  
		~Search(); // destructor�Ψ�����  
		void search(); // ��r�� 
};
#endif
