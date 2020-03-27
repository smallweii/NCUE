#include<iostream>
#include<fstream>
#include<ctype.h>
#include"S0454028_Encryption.h"
using namespace std;

Encryption::Encryption(char *inFileName, char *outFileName, int num) // constructor�ΨӶ}�� 
{
	inFile.open(inFileName);
	outFile.open(outFileName, ios::app); // �q�w�s�b�ɪ�������g�ä��M������ 
	key = num; // ��ϥΪ̿�J���[�K�� num assign�� key 
	
	if (!inFile) { // �ˬd�ɮ׬O�_���\�}��  
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	if (!outFile) {
		cout << "Can't open the file!" << endl;
		exit(1);
	}
}
Encryption::~Encryption() // destructor�Ψ����� 
{
	inFile.close();
	outFile.close();
}
void Encryption::doFilter(ifstream &in, ofstream &out) // �}�ɫ᪺�ʧ@ 
{
	encrypt();
}
void Encryption::encrypt() // �[�K 
{
	char ch, transCh;
	
	inFile.get(ch); // �q inFileŪ�J�@�Ӧr�� 
	while (!inFile.fail()) { // �YŪ��r���N�i�ӡAŪ����r���N���X�j�� 
		transCh = transform(ch);
		outFile.put(transCh); // �ഫ�����@�Ӧr���g�J outFile 
		inFile.get(ch);
	}
	outFile.put('\n'); // ����Ÿ��g�J outFile  
	outFile.put('\n');
}
