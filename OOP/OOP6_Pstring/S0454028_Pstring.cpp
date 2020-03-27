#include<iostream>
#include"S0454028_Pstring.h"
using namespace std;

bool Pstring::isPalindrome() // �P�_�O�_���^�� 
{
	int len = str.length();
	bool memory = 0, palindrome;
	
	if (len % 2) { // �r�ꬰ�_�ƭӦr��(len % 2 = 1�N�i��)�A��ܦr��Y���^��N������ 
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
	} else { // �Ϥ��A�r�ꬰ���ƭӦr��(len % 2 = 0)
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
