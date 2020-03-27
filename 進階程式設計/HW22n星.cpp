#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T22.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) { // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    char ch, formula[6][5] = {0}, sign[6] = {0};
    int i = 0, j = 0;
    
    while (file.peek() != '\n') {
        file >> ch;
        
        if (ch == 'a' || ch == 'b') {
            formula[i][j] = ch;
            j++;
        } else if (ch == 'n' || ch == '*') {
            sign[i] = ch;
            i++;
            j = 0;
        }
    }
    /*for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++)
            cout << formula[i][j];
        cout << endl;
    }*/
    int num, m = 0;
    
    file >> num;
    file.ignore();
    while (m < num) {
        char test[500] = {0};
        
        for (int i = 0; i < 500; i++) {
            if (file.peek() != '\n') {
                file >> ch;
                test[i] = ch;
            } else {
                file.ignore();
                break;
            }
            //cout << test[i];
        }
        //cout << endl;
		int count[2] = {0}, x = 0, y = 0;
        
		for (int i = 0; i < strlen(test); i++)
			if (test[i] != formula[0][0]) { // b 
				x = i;
				break;
			}
		for (int i = x - 3; i >= 0; i--)
			if (test[i] == formula[0][0]) // a
				count[0]++; // 找 n的次數 
        for (int i = x - 2; i < strlen(test); i++) {
        	y = i;
        	if (test[y] == formula[1][0] && test[y + 1] == formula[1][1] && test[y + 2] == formula[1][2] && test[y + 3] == formula[1][3]) { // aaba
				count[1]++; // 找 *的次數 
				i = y + 3;
			} else
				break;
		}
		if (!count[1]) { // *出現零次 
			count[0] = 0;
			for (int i = 0; i < strlen(test); i++) {
				if (test[i] == formula[0][0]) // a
					count[0]++; // 重找 n的次數 
				else
					break;
			}
		}
		//cout << "n : " << count[0] << "次" << endl;
		//cout << "* : " << count[1] << "次" << endl;
		string str = "\0";
		
		for (int i = 0; i < 6; i++) {
			if (sign[i] == sign[0]) // n
				for (int j = 0; j < count[0]; j++)
					str += formula[i];
			else // *
				for (int j = 0; j < count[1]; j++)
					str += formula[i];
		}
		//cout << str << endl;
		if (str == test)
			cout << "The input string is accepted." << endl;
		else
			cout << "The input string is rejected." << endl;
		m++;
    }
    file.close(); // 關檔 
    system("pause");
    return 0;
}
