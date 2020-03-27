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
		cout << "Plase enter two names" << endl << "Name 1: ";//輸入兩個name來比較 
		cin >> s1;
		cout << "Name 2: ";
		cin >> s2;
		
		if(sameString(s1, s2) == true)//進入sameString來比較，若回傳true表相同，回傳false表不同 
			cout << "They are the same." << endl;
		else
	    	cout << "They are not the same." << endl;
	    
		cout << endl << "Do you want to test it again? <enter Y/N>: ";//可依輸入Y/N來判斷是否繼續重複輸入  
	    cin >> answer;
	} while (answer == 'Y' || answer == 'y');//只要輸入Y/y迴圈就可繼續執行 
	
	system("pause");
	return 0;
}

bool sameString(string s1, string s2)
{
	string upper_s1 = upperCaseIt(s1);//s1進入upperCaseIt轉成大寫字串upper_s1 
	string upper_s2 = upperCaseIt(s2);//s2進入upperCaseIt轉成大寫字串upper_s2 
	
	if (upper_s1.compare(upper_s2) == 0)//upper_s1和upper_s2比較，若相同則回傳true，不同則回傳false 
		return true;
	else
		return false;
}

string upperCaseIt(string s)
{
	string upper;
	
	for (int i = 0; i < sizeof(s); i++)
		upper += toupper(s[i]);//將字串s的每個字母轉成大寫，再用迴圈串接成新字串upper，然後回傳到sameString裡的upper_s1和upper_s2 
	
	return upper;
}
