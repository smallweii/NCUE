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
		
		Pstring pstr(s); // �إߤ@���x�s���A�� Pstring������s pstr 
		bool palindrome = pstr.isPalindrome(); // �ŧi�@�ӥ��L���A���ܼƥs palindrome�A�O�H���� pstr�Ƕi isPalindrome��Ʀ^�Ǫ��� 
		
		if (palindrome == true) // �Y�^��true��ܦ��r�ꬰ�^��A�Ϥ��h�����^�� 
			cout << "The string is a palindrome." << endl;
		else
			cout << "The string is not a palindrome." << endl;
		
		cout << endl << "Again? Enter<y/n> : "; // �i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // �u�n��Jy/Y�j��N�i�~����� 
	
	system("pause");
	return 0;
}
