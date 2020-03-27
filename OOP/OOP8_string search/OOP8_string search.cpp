#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
using namespace std;

class Search{ // �إߤ@�ӥs Search�� class 
	public :
		fstream file; // �ŧi fstream����s file 
		string str; // �ŧi�H�r�ꫬ�A���r��s str 
		Search(char *filename, string s); // constructor�ΨӶ}��  
		~Search(); // destructor�Ψ�����  
		void search(); // ��r�� 
};
Search::Search(char *filename, string s) // constructor�ΨӶ}�� 
{
	file.open(filename);
	str = s; // ��ϥΪ̿�J���r�� s assign�� str 
	if (!file) { // �ˬd�ɮ׬O�_���\�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
}
Search::~Search() // destructor�Ψ����� 
{
	file.close();
}
void Search::search() // ��r�� 
{
	char ch, test[100] = {0};
	int i = 0, times = 0;
	
	while (file.peek() != EOF) { // �Y���O�ɮ׵����N�i�� 
		if (file.peek() != '.' && file.peek() != ' ') { // �Y���O�y���M�Ů�N�i�� 
			file >> ch; // Ū�Ӧr�� 
			test[i] = ch; // ��r���s��}�C 
			i++;
		} else if (file.peek() == ' ') { // �Y�O�Ů�N�i�� 
			file >> ch; // �]���Ů�Ū����A�ҥH��Ū�Ů檺�U�@�Ӧr�� 
			test[i] = ' '; // ����ݪŮ檺��m�s���Ů� 
			i++;
			test[i] = ch; // ��Ů檺�U�@�Ӧr������m�s���Ӧr�� 
			i++;
		} else { // ���y�����@�y�A�Y�O�y���N�i�� 
			file >> ch;
			for (int j = 0; j < i; j++) {
				if (test[j] == str[0]) { // �Y�Ĥ@�Ӧ��@�˴N�~��� 
					bool check = 1, appear = 0;
					
					for (int k = 0; k < str.length(); k++) {
						if (test[j + k] != str[k]) { // ��줣�@�˪��N�i�� 
							check = 0; // �S���r�� 
							break;
						}
					}
					if (check) { // �����r��N�i�� 
						times++;
						if (appear == 0) { // �Y����r��S�X�{�L�N�L 
							for (int l = 0; l < i; l++)
								cout << test[l];
							cout << "." << endl;
							appear = 1; // �Y����r��X�{�L�b�P�y�A�L�ӥy�@���N�n 
						}
					}
				}
			}
			i = 0; // �U�@�y���� 
		}
	}
	if (times == 1)
		cout << times << " time" << endl; // ��� 
	else
		cout << times << " times" << endl; // �Ƽ� 
}
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
