#include<iostream>
using namespace std;

class Pstring:public string{ // 建立一個叫 Pstring的 derived calss繼承從 STL string class 
	private:
		string str; // 儲存使用者輸入的字串 
	
	public:
		Pstring(string s):string(s)
		{
			str = s; // constructor
		}
		bool isPalindrome(); // 判斷是否為回文 
};
bool Pstring::isPalindrome() // 判斷是否為回文 
{
	int len = str.length();
	bool memory = 0, palindrome;
	
	if (len % 2) { // 字串為奇數個字元(len % 2 = 1就進來)，表示字串若為回文就有中心 
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
	} else { // 反之，字串為偶數個字元(len % 2 = 0)
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
		
		Pstring pstr(s); // 建立一個儲存型態為 Pstring的物件叫 pstr 
		bool palindrome = pstr.isPalindrome(); // 宣告一個布林型態的變數叫 palindrome，是以物件 pstr傳進 isPalindrome函數回傳的值 
		
		if (palindrome == true) // 若回傳true表示此字串為回文，反之則不為回文 
			cout << "The string is a palindrome." << endl;
		else
			cout << "The string is not a palindrome." << endl;
		
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	system("pause");
	return 0;
}
