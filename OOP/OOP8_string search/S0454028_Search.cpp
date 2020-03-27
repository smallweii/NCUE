#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
#include "S0454028_Search.h"
using namespace std;

Search::Search(char *filename, string s) // constructor用來開檔 
{
	file.open(filename);
	str = s; // 把使用者輸入的字串 s assign給 str 
	if (!file) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
}
Search::~Search() // destructor用來關檔 
{
	file.close();
}
void Search::search() // 找字串 
{
	char ch, test[100] = {0};
	int i = 0, times = 0;
	
	while (file.peek() != EOF) { // 若不是檔案結尾就進來 
		if (file.peek() != '.' && file.peek() != ' ') { // 若不是句號和空格就進來 
			file >> ch; // 讀該字元 
			test[i] = ch; // 把字元存到陣列 
			i++;
		} else if (file.peek() == ' ') { // 若是空格就進來 
			file >> ch; // 因為空格讀不到，所以先讀空格的下一個字元 
			test[i] = ' '; // 把所屬空格的位置存成空格 
			i++;
			test[i] = ch; // 把空格的下一個字元的位置存成該字元 
			i++;
		} else { // 視句號為一句，若是句號就進來 
			file >> ch;
			for (int j = 0; j < i; j++) {
				if (test[j] == str[0]) { // 若第一個有一樣就繼續比 
					bool check = 1, appear = 0;
					
					for (int k = 0; k < str.length(); k++) {
						if (test[j + k] != str[k]) { // 比到不一樣的就進來 
							check = 0; // 沒找到字串 
							break;
						}
					}
					if (check) { // 有找到字串就進來 
						times++;
						if (appear == 0) { // 若欲找字串沒出現過就印 
							for (int l = 0; l < i; l++)
								cout << test[l];
							cout << "." << endl;
							appear = 1; // 若欲找字串出現過在同句，印該句一次就好 
						}
					}
				}
			}
			i = 0; // 下一句重找 
		}
	}
	if (times == 1)
		cout << times << " time" << endl; // 單數 
	else
		cout << times << " times" << endl; // 複數 
}
