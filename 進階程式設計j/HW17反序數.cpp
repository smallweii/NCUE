#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T17.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    int num;
    
    if (file >> num)
    {
        int times = 1;
        
        while (times <= num)
        {
            int i = 0, n, arr[1000], count[1000] = {0};
            while (file >> n)
            {
                arr[i] = n;
                i++;
            
                if (file.get() == '\n' || file.eof())
                    break;
            }
            for (int j = 0; j < i; j++) // 每個數輪流當中心 
            {
                for (int k = 0; k < j; k++)
                {
                    if (arr[k] > arr[j]) // 比他大卻排在他前面 
                        count[j]++;
                }
                for (int k = j + 1; k < i; k++)
                {    
                    if (arr[j] > arr[k]) // 比他小卻排在他後面 
                        count[j]++;
                }
            }
            int max = -1, x = 0;
            
            for (int j = 0; j < i; j++)
                if (count[j] > max)
                {
                    max = count[j];
                    x = j;
                }
            cout << "反序數最大的數字為：" << arr[x];
            
            for (int j = 0; j < i; j++)
                if (max == count[j] && x != j)
                    cout << "," << arr[j];
                    
            cout << "\t最大反序數為：" << max << endl;
            times++;
        }
    }
    file.close(); // 關檔 
    system("pause");
    return 0;
}
