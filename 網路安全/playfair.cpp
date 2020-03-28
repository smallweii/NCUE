#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	int choice;
	
	cout << "歡迎使用《Playfair Cipher》\n";
	cout << "1. 加密\n2. 解密\n\n";
	cout << "請輸入選項: ";
	cin >> choice;
	cout << endl;
	
	if (choice == 1) { // 加密 
		string key;
		bool repeat;
		
		do { // 檢核key 
			repeat = false;
			
			cout << "請輸入key: ";
			cin >> key;
			cout << endl;
			
			for (int i = 0; i < key.length(); i++) {
				if (islower(key[i])) // 若為小寫 
					key[i] = toupper(key[i]); // 就把key轉大寫 
				if (key[i] == 'J')
					key[i] = 'I'; // J通通轉成I來看 
			}
			for (int i = 0; i < key.length() - 1; i++) // 檢查key的字母是否有重複 
				for (int j = i + 1; j < key.length(); j++)
					if (key[i] == key[j])
						repeat = true;
						
			if (repeat == true)
				cout << "※Warning: key的字母有重複(I/J算同字母)\n\n";
		} while (repeat == true); // key的字母重複 
		
		char arr[5][5] = {""}; // 存key的表格 
		int row = 0, col = 0;
		
		for (int i = 0; i < key.length(); i++) { // 把key填入前面表格 
			arr[row][col] = key[i];
			col++;
			if (col == 5) {
				row++;
				col = 0;
			}
		}
		for (int i = 0; i <= 25; i++) { // 後面依序填入 A:65 →Z:90 
			bool letter = false;
			
			for (int j = 0; j < key.length(); j++) {
				if (i == 9) { // J:74
					letter = true;
					break;
				}
				if ((char)(65 + i) == key[j]) // 填過的就不再填 
					letter = true; // 填過了 
			}
			if (letter == false) {
				arr[row][col] = (char)(65 + i);
				col++;
				if (col == 5) {
					row++;
					col = 0;
				}
			}
		}
		string filename;
		
		cout << "請輸入欲加密的檔名(XXX.txt): ";
		cin >> filename;
		cout << endl;
		ifstream fin(filename.c_str()); // 讀使用者輸入的檔名 
		
		if (!fin) { // 檢查檔案是否成功開啟，若!fin為真，檔案則無法開啟 
			cout << "Can't open the file!" << endl;
			exit(1); // 在不正常情形下，中斷程式的執行 
		}
		char ch;
		string plain = "", plain2 = "";
		int n = 0;
		
		while (fin >> ch) {
			ch = toupper(ch);
			if (ch == 'J')
				ch = 'I'; // J通通轉成I來看 
			plain += ch;
			n++;
		}
		for (int i = 0; i < n; i += 2) {
			if (i == (plain.length() - 1)) { // 字串為奇數 
				plain2 += plain[i];
				plain2 += 'X';
			}
			else if (plain[i] != plain[i + 1]) {
				plain2 += plain[i];
				plain2 += plain[i + 1];
			} else if (plain[i] == plain[i + 1]) {
				plain.insert(i + 1,"X"); // 從第i+1個位置開始插入字串"X"，並返回新的字串 
				n = plain.length(); // n++
				plain2 += plain[i];
				plain2 += 'X';
			}
		}
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
		string cipher = "";
		
		for (int i = 0; i < plain2.length(); i += 2) { // 兩兩一組各找r,c值再比較 
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (plain2[i] == arr[j][k]) {
						r1 = j;
						c1 = k;
					}
					if (plain2[i + 1] == arr[j][k]) {
						r2 = j;
						c2 = k;
					}
				}
			}
			if (r1 == r2) { // 同列 
				cipher += arr[r1][(c1 + 1) % 5];
				cipher += arr[r1][(c2 + 1) % 5];
			} else if (c1 == c2) { // 同行 
				cipher += arr[(r1 + 1) % 5][c1];
				cipher += arr[(r2 + 1) % 5][c1];
			} else if ((r1 != r2) && (c1 != c2)) { // 不同列不同行 
				cipher += arr[r1][c2];
				cipher += arr[r2][c1];
			}
		}
		fstream fout;
		
		fout.open("c1.txt", ios::out); //在寫入模式下開啟c1.txt檔 
		fout << cipher << endl;
	} else if (choice == 2) { // 解密 
		string key;
		bool repeat;
		
		do { // 檢核key 
			repeat = false;
			
			cout << "請輸入key: ";
			cin >> key;
			cout << endl;
			
			for (int i = 0; i < key.length(); i++) {
				if (islower(key[i])) // 若為小寫 
					key[i] = toupper(key[i]); // 就把key轉大寫 
				if (key[i] == 'J')
					key[i] = 'I'; // J通通轉成I來看 
			}
			for (int i = 0; i < key.length() - 1; i++) // 檢查key的字母是否有重複 
				for (int j = i + 1; j < key.length(); j++)
					if (key[i] == key[j])
						repeat = true;
						
			if (repeat == true)
				cout << "※Warning: key的字母有重複(I/J算同字母)\n\n";
		} while (repeat == true); // key的字母重複 
		
		char arr[5][5] = {""}; // 存key的表格 
		int row = 0, col = 0;
		
		for (int i = 0; i < key.length(); i++) { // 把key填入前面表格 
			arr[row][col] = key[i];
			col++;
			if (col == 5) {
				row++;
				col = 0;
			}
		}
		for (int i = 0; i <= 25; i++) { // 後面依序填入 A:65 →Z:90 
			bool letter = false;
			
			for (int j = 0; j < key.length(); j++) {
				if (i == 9) { // J:74
					letter = true;
					break;
				}
				if ((char)(65 + i) == key[j]) // 填過的就不再填 
					letter = true; // 填過了 
			}
			if (letter == false) {
				arr[row][col] = (char)(65 + i);
				col++;
				if (col == 5) {
					row++;
					col = 0;
				}
			}
		}
		string filename;
		
		cout << "請輸入欲解密的檔名(XXX.txt): ";
		cin >> filename;
		cout << endl;
		ifstream fin(filename.c_str()); // 讀使用者輸入的檔名 
		
		if (!fin) { // 檢查檔案是否成功開啟，若!fin為真，檔案則無法開啟 
			cout << "Can't open the file!" << endl;
			exit(1); // 在不正常情形下，中斷程式的執行 
		}
		char ch;
		string cipher = "", plain = "";
		
		while (fin >> ch) {
			ch = toupper(ch);
			if (ch == 'J')
				ch = 'I'; // J通通轉成I來看 
			cipher += ch;
		}
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0, n = 0;
		
		for (int i = 0; i < cipher.length(); i += 2) { // 兩兩一組各找r,c值再比較 
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (cipher[i] == arr[j][k]) {
						r1 = j;
						c1 = k;
					}
					if (cipher[i + 1] == arr[j][k]) {
						r2 = j;
						c2 = k;
					}
				}
			}
			if (r1 == r2) { // 同列 
				if (c1 == 0)
					c1 = 5;
				if (c2 == 0)
					c2 = 5;
				plain += arr[r1][(c1 - 1) % 5];
				plain += arr[r1][(c2 - 1) % 5];
			} else if (c1 == c2) { // 同行 
				if (r1 == 0)
					r1 = 5;
				if (r2 == 0)
					r2 = 5;
				plain += arr[(r1 - 1) % 5][c1];
				plain += arr[(r2 - 1) % 5][c1];
			} else if ((r1 != r2) && (c1 != c2)) { // 不同列不同行 
				plain += arr[r1][c2];
				plain += arr[r2][c1];
			}
		}
		n = plain.length();
		for (int i = 0; i < n; i++) {
			if ((plain[i] == 'X') && (plain[i - 1] == plain[i + 1]) && (i % 2 == 1)) {
				plain.erase(i, 1); // 從第i個位置開始刪除1個字串，並返回新的字串 
				n = plain.length(); // n--
			}
		}
		fstream fout;
		
		fout.open("p1.txt", ios::out); //在寫入模式下開啟p1.txt檔 
		fout << plain << endl;
	}
	system("pause");
	return 0;
} 
