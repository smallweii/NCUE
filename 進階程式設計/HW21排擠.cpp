#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T21.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) { // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    int n, m;
    
    if (file >> n) { // 有幾組資料 
        while (file >> m) { // 每組資料有幾個數字 
            int M, num[31] = {0};
            
            for (int i = 0; i < m; i++) {
                file >> M; // 每組資料的數字 
                num[i] = M;
            }
            int d = 2, arr[31][31] = {0}, arr2[31][31] = {0};
            
            while (d < m) { // 斜的跑陣列 差 
                for (int i = 1, j = i + d; i <= m, j <= m; i++, j++) {
            		int big, small, max = 0, min = 100000;
            	
                    if (d == 2) {
                        arr[i][j] = num[i - 1] * num[i] * num[j - 1];
                        arr2[i][j] = num[i - 1] * num[i] * num[j - 1];
                    } else {
                        for (int k = i + 1; k < j; k++) {
                            big = arr[i][k] + arr[k][j] + num[i - 1] * num[k - 1] * num[j - 1];
                            small = arr2[i][k] + arr2[k][j] + num[i - 1] * num[k - 1] * num[j - 1];
                            if (big > max)
                                max = big;
                            if (small < min)
                                min = small;
                        }
                        arr[i][j] = max;
                        arr2[i][j] = min;
                    }    
                }
                d++;  
            }
            cout << "數列縮減的最大效益值為 " << setw(10) << std::left << arr[1][m] << "最小效益值為 " << arr2[1][m] << endl << endl;
        }
    }
    file.close(); // 關檔 
    system("pause");
    return 0;
}
