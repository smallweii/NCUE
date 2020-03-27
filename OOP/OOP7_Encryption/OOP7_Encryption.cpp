#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;

class Encryption{ // 建立一個叫 Encryption的 abstract class 
	public:
		ifstream inFile; // 宣告 ifstream物件叫 inFile
		ofstream outFile; // 宣告 ofstream物件 outFile
		int key; // 宣告以整數型態的加密值叫 key 
		
		Encryption(char *inFileName, char *outFileName, int num); // constructor用來開檔 
		~Encryption(); // destructor用來關檔 
		
		virtual char transform(char ch) const = 0; // 讓 subclass重新定義的 pure virtual function
		void doFilter(ifstream &in, ofstream &out); // 開檔後的動作 
		void encrypt(); // 加密 
};
class SimpleEncryption : public Encryption{ // 建立一個叫 SimpleEncryption的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元加密後的字元回傳 
		{
			return ch + key;
		}
		SimpleEncryption(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class TransformTouppercase : public Encryption{ // 建立一個叫 TransformTouppercase的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元轉大寫後回傳 
		{
			return toupper(ch);
		}
		TransformTouppercase(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
class Copy : public Encryption{ // 建立一個叫 Copy的 derived class從 Encryption繼承 
	public:
		char transform(char ch) const // 把字元複製後回傳 
		{
			return ch;
		}
		Copy(char *inFileName, char *outFileName, int num) : Encryption(inFileName, outFileName, num) // constructor
		{
			;
		}
};
Encryption::Encryption(char *inFileName, char *outFileName, int num) // constructor用來開檔 
{
	inFile.open(inFileName);
	outFile.open(outFileName, ios::app); // 從已存在檔的尾端續寫並不清除原檔 
	key = num; // 把使用者輸入的加密值 num assign給 key 
	
	if (!inFile) { // 檢查檔案是否成功開啟  
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	if (!outFile) {
		cout << "Can't open the file!" << endl;
		exit(1);
	}
}
Encryption::~Encryption() // destructor用來關檔 
{
	inFile.close();
	outFile.close();
}
void Encryption::doFilter(ifstream &in, ofstream &out) // 開檔後的動作 
{
	encrypt();
}
void Encryption::encrypt() // 加密 
{
	char ch, transCh;
	
	inFile.get(ch); // 從 inFile讀入一個字元 
	while (!inFile.fail()) { // 若讀到字元就進來，讀不到字元就跳出迴圈 
		transCh = transform(ch);
		outFile.put(transCh); // 轉換完的一個字元寫入 outFile 
		inFile.get(ch);
	}
	outFile.put('\n'); // 換行符號寫入 outFile  
	outFile.put('\n');
}
int main()
{
	char answer, inFileName[11] = {"origin.txt"}, outFileName[11] = {"result.txt"};
	int num;
	
	do {
		cout << "Please enter a number for the key of encryption (key < 6) : ";
		cin >> num;
		while (num >= 6) { // 防呆，因為 origin檔裡的字元最大到 'y'，若加密值 >=6就重新輸入 
			cout << "Please enter a number for the key of encryption (key < 6) : ";
			cin >> num;
		}
		SimpleEncryption encryption(inFileName, outFileName, num); // 建立一個儲存型態為 SimpleEncryption的物件叫 encryption 
		encryption.doFilter(encryption.inFile, encryption.outFile);
		
		TransformTouppercase touppercase(inFileName, outFileName, num); // 建立一個儲存型態為 TransformTouppercase的物件叫 touppercase 
		touppercase.encrypt();
		
		Copy copy(inFileName, outFileName, num); // 建立一個儲存型態為 Copy的物件叫 copy 
		copy.encrypt();
		
		cout << "Please open result.txt to check the content." << endl; // 可查看已完成全部動作的結果，檔案會續寫 
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	system("pause");
	return 0;
}
