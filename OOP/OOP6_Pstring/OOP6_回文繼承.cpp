#include<iostream>
using namespace std;

class Pstring:public string{ // �إߤ@�ӥs Pstring�� derived calss�~�ӱq STL string class 
	private:
		string str; // �x�s�ϥΪ̿�J���r�� 
	
	public:
		Pstring(string s):string(s)
		{
			str = s; // constructor
		}
		bool isPalindrome(); // �P�_�O�_���^�� 
};
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
