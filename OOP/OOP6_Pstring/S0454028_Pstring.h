#include<iostream>
using namespace std;
#ifndef PSTRING_H
#define PSTRING_H

class Pstring:public string{ // 建立一個叫 Pstring的 derived calss繼承從 STL string class 
	private:
		string str; // 儲存使用者輸入的字串 
	
	public:
		Pstring(string s):string(s)
		{
			str = s; // constructor
		}
		bool isPalindrome(); // 判斷是否為回文 
};
#endif
