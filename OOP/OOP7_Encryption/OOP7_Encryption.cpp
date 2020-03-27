#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;

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
