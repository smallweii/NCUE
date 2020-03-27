#include<iostream>
#include"S0454028_Pstring.h"
using namespace std;

bool Pstring::isPalindrome() // 判斷是否為回文 
{
	int len = str.length();
	bool memory = 0, palindrome;
	
	if (len % 2) { // 字串為奇數個字元(len % 2 = 1就進來)，表示字串若為回文就有中心 
		for (int i = 0, j = len - 1; i < len / 2, j > len / 2; i++, j--) {
			if (str.at(i) == str.at(j))
				memory = 1;
			else
				break;
		}
		if (memory)
			palindrome = true;
		else
			palindrome = false;
	} else { // 反之，字串為偶數個字元(len % 2 = 0)
		for (int i = 0, j = len - 1; i < len / 2, j > len / 2 - 1; i++, j--) {
			if (str.at(i) == str.at(j))
				memory = 1;
			else
				break;
		}
		if (memory)
			palindrome = true;
		else
			palindrome = false;
	}
	return palindrome;
}
