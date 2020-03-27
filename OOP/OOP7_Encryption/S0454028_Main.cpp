#include<iostream>
#include<fstream>
#include<ctype.h>
#include"S0454028_Encryption.h"
#include"S0454028_Encryption.cpp"
using namespace std;

int main()
{
	char answer, inFileName[11] = {"origin.txt"}, outFileName[11] = {"result.txt"};
	int num;
	
	do {
		cout << "Please enter a number for the key of encryption (key < 6) : ";
		cin >> num;
		while (num >= 6) { // ���b�A�]�� origin�ɸ̪��r���̤j�� 'y'�A�Y�[�K�� >=6�N���s��J 
			cout << "Please enter a number for the key of encryption (key < 6) : ";
			cin >> num;
		}
		SimpleEncryption encryption(inFileName, outFileName, num); // �إߤ@���x�s���A�� SimpleEncryption������s encryption 
		encryption.doFilter(encryption.inFile, encryption.outFile);
		
		TransformTouppercase touppercase(inFileName, outFileName, num); // �إߤ@���x�s���A�� TransformTouppercase������s touppercase 
		touppercase.encrypt();
		
		Copy copy(inFileName, outFileName, num); // �إߤ@���x�s���A�� Copy������s copy 
		copy.encrypt();
		
		cout << "Please open result.txt to check the content." << endl; // �i�d�ݤw���������ʧ@�����G�A�ɮ׷|��g 
		cout << endl << "Again? Enter<y/n> : "; // �i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // �u�n��Jy/Y�j��N�i�~����� 
	
	system("pause");
	return 0;
}
