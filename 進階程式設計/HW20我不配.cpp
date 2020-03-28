#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T20_1.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    char m;
    int n, a[10][11] = {0}, b[10][11] = {0};
    
    for (int i = 0; i < 10; i++) // 儲存研究生和其志願 
        for (int j = 0; j < 11; j++) {
            file >> m >> n;
            a[i][j] = n;
        }
    for (int i = 0; i < 10; i++) // 儲存教授和其志願 
        for (int j = 0; j < 11; j++) {
            file >> m >> n;
            b[i][j] = n;
        }	
    for (int j = 1; j < 11; j++) {
		for (int i = 0; i < 10; i++) {
			int pro, min = 11, stu[10] = {0}, hope, match, memory = 0, temp = 0; // 5,5,6,10,6,5,10,7,3,6
        	
			if (a[i][j]) {
				for (int x = i; x < 10; x++) {
					pro = a[x][j];
					if (pro) { // 同行研究生比較選到的教授 
						memory = 1; // 若選到一樣教授就做記號 
						temp = j;
						//cout << pro << " ";
						break;
					}
				}
				for (int x = 0; x < 10; x++) {
					if (a[x][temp] == pro) {
						stu[x] = a[x][0]; // 選到一樣教授的研究生編號儲存成 stu陣列 
						//cout << stu[x] << " ";
					}	
				}
				for (int x = 0; x < 10; x++) {
					for (int y = 1; y < 11; y++) {
						if (b[pro - 1][y] == stu[x]) { // 研究生編號對應到教授志願 
							hope = y; // 研究生在教授志願的第 y個 
							if (hope < min) {
								min = hope; // 最前面的志願選到該教授 
								match = x;
							}
						}	
					}
				}
				for (int y = 1; y < 11; y++) {
					for (int x = 0; x < 10; x++) {
						if (a[x][y] == pro) { // 若陣列裡有被選走的教授就清為 0 
							a[x][y] = 0;
						}
					}
				}
				for (int y = 2; y < 11; y++)
					a[match][y] = 0;
				a[match][1] = pro;	
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << "A" << i + 1 << ",B" << a[i][1] << endl;
    file.close();
    system("pause");
    return 0;
}
