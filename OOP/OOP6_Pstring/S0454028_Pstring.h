#include<iostream>
using namespace std;
#ifndef PSTRING_H
#define PSTRING_H

class Pstring:public string{ // �إߤ@�ӥs Pstring�� derived calss�~�ӱq STL string class 
	private:
		string str; // �x�s�ϥΪ̿�J���r�� 
	
	public:
		Pstring(string s):string(s)
		{
			str = s; // constructor
		}
		bool isPalindrome(); // �P�_�O�_���^�� 
};
#endif
