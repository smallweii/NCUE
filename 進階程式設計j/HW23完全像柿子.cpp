#include<iostream>
#include<string.h>
#include<ctype.h>
#include<cmath>
using namespace std;

int main()
{
    char answer;
    
	do {
		string poly;
		char item[100] = {0};
    
        cout << "輸入 : ";
        cin >> poly;
        cout << "單位項 : " << endl;
        
        for (int i = 0; i < poly.length(); i++) {
            if (poly[i] != '+' && poly[i] != '\'') {
                for (int j = 0; j < 100; j++) {
                    if (item[j] == poly[i])
                        break;
                    else if (item[j] == 0) {
                        item[j] = poly[i]; // 沒重複的單位項 
                        cout << item[j];
                        break;
                    }
                }    
            }
        }
        int k = 0, x = 0;
        string str[100];
        
        for (int i = 0; i < poly.length(); i++) { // 首項和+跟+之間的 
            if (poly[i] == '+') {
                for (int j = k; j < i; j++) {
                    str[x] += poly[j];
                }
                k = i + 1; // 從+的下一個開始跑 
                x++;
            }
        }
        for (int i = k; i < poly.length(); i++) { // 末項 
            str[x] += poly[i];
        }
        cout << endl << "每項 : " << endl;
        for (int i = 0; i <= x; i++) { // 印每項 
            for (int j = 0; j < str[i].length(); j++) {
                cout << str[i][j];
            }
            cout << endl;
        }
        int y = 0, z = 0;
        string sign[100];
        
        for (int i = 0; i < poly.length(); i++) {
            if (poly[i] != '+') {
				if (poly[i] != '\'') { // 後面沒 '的字元對應到 0 
                	sign[y][z] = '0';
                	z++;
            	} else { // 後面有 '的字元對應到 1 
            		sign[y][z - 1] = '1';
            		z++;
				}
			} else { // 找到 +就換行比 
				y++;
				z = 0;
			}
        }
        cout << "對應項 : " << endl;
        for (int i = 0; i <= x; i++) { // 印每項對應的 0or1 
            for (int j = 0; j < str[i].length(); j++) {
                cout << sign[i][j];
            }
            cout << endl;
        }
        int place = 0;
        string result[100]; // 存全部插完的項，包含重複的 
        
        cout << "缺項 : " << endl;
        for (int i = 0; i <= x ; i++) {
        	int lack = 0;
        	string total_lack;
        	
        	for (int j = 0; j < strlen(item); j++) { // 找每項缺的單位項 
        		bool appear = 0;
        		
				for (int k = 0; k < str[i].length(); k++) {
        			if (item[j] == str[i][k]) {
        				appear = 1; // 有出現過 
						break;
					}
				}
				if (appear == 0) { // 沒出現過 
					total_lack += item[j];
					lack++;
				}
			}
			cout << total_lack;
    		int times = pow(2, lack), place2 = 0; // times為缺幾項就該項變成有 2^(缺幾項)項 
    		string temp[times];
    		
			temp[0] = str[i];
			for (int j = 0; j < lack; j++) { // 跑一次插一個字元進去 
				for (int k = 0; k < pow(2, j); k++) { // 插第一個字元要跑兩次 第二個字元要跑四次 以此類推 
					int insert_place = 0; // 檢查插入的字元要在哪裡 
					string part_lack;
					
					part_lack += total_lack[j]; // 把字元轉換成字串 以便下面函數使用 
					for (insert_place = 0; insert_place < temp[k].length(); insert_place++) { // 算字元要插在第幾個 
						if (insert_place == 0 && total_lack[j] < temp[k][insert_place]) // 比首項小 
							break;
						else if (temp[k][insert_place] < total_lack[j] && total_lack[j] < temp[k][insert_place + 1]) { // 介於兩字元間 
							insert_place++;
							break;
						}
						else if (insert_place == temp[k].length() - 1 && temp[k][insert_place] < total_lack[j]) { // 比末項大 
							insert_place++;
							break;
						}
					}
					temp[place2 + 1] = temp[k];
					temp[k].insert(insert_place, part_lack);
					place2++;
					temp[place2].insert(insert_place, part_lack + '\'');
				}
			}
			for (int j = 0; j < times; j++)
				result[place + j] = temp[j];
			place += times;
		}
        cout << endl << "輸出 : " << result[0];
        for (int i = 1; i < place; i++) {
        	bool again = 0;
        	
        	for (int j = 0; j < i; j++)
        		if (result[i] == result[j])
        			again = 1;
        	if (again == 0) // 沒重複才印 
        		cout << "+" << result[i];
		}
		cout << endl << endl << "Again? Enter<y/n> : ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    system("pause");
    return 0;
}
