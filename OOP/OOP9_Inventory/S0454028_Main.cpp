#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include "S0454028_Inventory.h"
#include "S0454028_Inventory.cpp"
using namespace std;

int main()
{
	fstream file("inventory.txt", ios::in | ios::out); // �}�ɡAŪ�M�g���P�� 
	if (!file) { // �ˬd�ɮ׬O�_���\�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	char choice, answer;
	Inventory record; // �إߤ@���x�s���A�� Inventory������s record 
	
	do {
		cout << "******************************************" << endl
		     << "*                  Menu                  *" << endl
		     << "*   (a) Add new records to the file      *" << endl
		     << "*   (b) Display any record in the file   *" << endl
		     << "*   (c) Change any record in the file    *" << endl
		     << "******************************************" << endl
		     << "Which one do you want to do? Enter<a/b/c> : ";
		cin >> choice;
		
		if (toupper(choice) == 'A')
			AddRecord(record, file);
		if (toupper(choice) == 'B')
			DisplayRecord(record, file);
		if (toupper(choice) == 'C')
			ChangeRecord(record, file);
		
		cout << endl << "Again? Enter<y/n> : "; // �i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
		cin >> answer;
		file.clear(); // �M������ 
		file.seekg(0L, ios::beg); // ����в����ɮ׶}�Y 
	} while (toupper(answer) == 'Y'); // �u�n��Jy/Y�j��N�i�~����� 
	
	file.close(); // ���� 
	system("pause");
	return 0;
}
