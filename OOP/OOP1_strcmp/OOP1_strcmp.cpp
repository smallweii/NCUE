#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

string upperCaseIt(string s);
bool sameString(string s1, string s2);

int main()
{
	string s1, s2;
	char answer;
	
	do {
		cout << "Plase enter two names" << endl << "Name 1: ";//��J���name�Ӥ�� 
		cin >> s1;
		cout << "Name 2: ";
		cin >> s2;
		
		if(sameString(s1, s2) == true)//�i�JsameString�Ӥ���A�Y�^��true��ۦP�A�^��false���P 
			cout << "They are the same." << endl;
		else
	    	cout << "They are not the same." << endl;
	    
		cout << endl << "Do you want to test it again? <enter Y/N>: ";//�i�̿�JY/N�ӧP�_�O�_�~�򭫽ƿ�J  
	    cin >> answer;
	} while (answer == 'Y' || answer == 'y');//�u�n��JY/y�j��N�i�~����� 
	
	system("pause");
	return 0;
}

bool sameString(string s1, string s2)
{
	string upper_s1 = upperCaseIt(s1);//s1�i�JupperCaseIt�ন�j�g�r��upper_s1 
	string upper_s2 = upperCaseIt(s2);//s2�i�JupperCaseIt�ন�j�g�r��upper_s2 
	
	if (upper_s1.compare(upper_s2) == 0)//upper_s1�Mupper_s2����A�Y�ۦP�h�^��true�A���P�h�^��false 
		return true;
	else
		return false;
}

string upperCaseIt(string s)
{
	string upper;
	
	for (int i = 0; i < sizeof(s); i++)
		upper += toupper(s[i]);//�N�r��s���C�Ӧr���ন�j�g�A�A�ΰj��걵���s�r��upper�A�M��^�Ǩ�sameString�̪�upper_s1�Mupper_s2 
	
	return upper;
}
