#include<iostream>
#include<fstream>
//#include<cmath>
using namespace std;

//void abs(int, int);

int main()
{
    fstream file; //宣告fstream物件
    file.open("T13.txt", ios::in); //讀取狀態下開啟檔案 
    if (!file) //檢查檔案是否成功開啟，若!file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!";
        exit(1); //在不正常情形下，中斷程式的執行 
    }
    int num, r, c, n, arr[11][51] = {0};
    if (file >> num)
    {
        while (file >> r >> c)
        {
            int x, y, s, t, sum = 0, min = 1000000000, small1 = 0, small2 = 0;
            
            for (int i = 1; i <= r; i++)
                for (int j = 1; j <= c; j++)
                    if (file >> n)
                        arr[i][j] = n; //把每個數字存成陣列 
                        
            for (int x = 1; x <= r; x++) //每個分區當中心 
            {
                for (int y = 1; y <= c; y++)
                {
                    sum = 0;
                    for (int i = 1; i <= r; i++) //其他以此分區為中心來移動 
                    {
                        for (int j = 1; j <= c; j++)
                        {
                            sum += (arr[i][j] * (abs(x - i) + abs(y - j)) * 10);
                        }
                    }
                    if (sum < min)
                    {
                        min = sum;
                        small1 = x;
                        small2 = y; 
                    }
                } 
            }
            cout << small1 << " " << small2 << endl << min << endl << endl;
        }
    }
    file.close(); //關檔 
    system("pause");
    return 0;
}
