#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
#include "S0454028_Search.h"
#include "S0454028_Search.cpp"
using namespace std;

int main()
{
	char filename[50], answer;
	string s;
	
	do {
		cout << "Please enter the name of a file(ex: filename.txt) : ";
		cin >> filename;
		do {
			cout << "Please enter a string to search for : ";
			cin >> s;
			Search find(filename, s); // �إߤ@���x�s���A�� Search������s find 
			find.search();
			cout << endl << "The same file again? Enter<y/n> : "; // �i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
			cin >> answer;
		} while (toupper(answer) == 'Y'); // �u�n��Jy/Y�j��N�i�~����� 
		
		cout << endl << "The whole test again? Enter<y/n> : ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	system("pause");
	return 0;
}
