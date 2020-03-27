#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption{ // �إߤ@�ӥs Encryption�� abstract class 
	public:
		ifstream inFile; // �ŧi ifstream����s inFile
		ofstream outFile; // �ŧi ofstream���� outFile
		int key; // �ŧi�H��ƫ��A���[�K�ȥs key 
		
		Encryption(char *inFileName, char *outFileName, int num); // constructor�ΨӶ}�� 
		~Encryption(); // destructor�Ψ����� 
		
		virtual char transform(char ch) const = 0; // �� subclass���s�w�q�� pure virtual function
		void doFilter(ifstream &in, ofstream &out); // �}�ɫ᪺�ʧ@ 
		void encrypt(); // �[�K 
};
class SimpleEncryption : public Encryption{ // �إߤ@�ӥs SimpleEncryption�� derived class�q Encryption�~�� 
	public:
		char transform(char ch) const // ��r���[�K�᪺�r���^�� 
		{
			return ch + key;
		}
		SimpleEncryption(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class TransformTouppercase : public Encryption{ // �إߤ@�ӥs TransformTouppercase�� derived class�q Encryption�~�� 
	public:
		char transform(char ch) const // ��r����j�g��^�� 
		{
			return toupper(ch);
		}
		TransformTouppercase(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class Copy : public Encryption{ // �إߤ@�ӥs Copy�� derived class�q Encryption�~�� 
	public:
		char transform(char ch) const // ��r���ƻs��^�� 
		{
			return ch;
		}
		Copy(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
#endif
