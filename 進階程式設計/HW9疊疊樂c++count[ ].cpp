#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int n1, n2, length, width, len[20], wid[20];
    
    fstream file;//宣告fstream物件
    file.open("T9.txt", ios::in);//讀取狀態下開啟檔案
    if (!file)//檢查檔案是否成功開啟，若!file為真，檔案則無法開啟
    {
        cout << "Can't open the file!" << endl;
        exit(1);//在不正常情形下，中斷程式的執行 
    }
    if (file >> n1)
    {
        while (file >> n2)
        {
            int i = 0;
            while (file >> length >> width)
            {
                len[i] = length;
                wid[i] = width;
                i++;
                if (i == n2)
                    break;
            }
            for (int j = 0; j < n2; j++)//bubble sort
                for (int i = 0; i < n2 - 1 ; i++)
                {
                    if (len[i+1] * wid[i+1] > len[i] * wid[i])//若後面面積>前面面積就(長度 寬度)一起互換，為了前大後小的排列 
                    {
                        int temp;
                        temp = len[i+1];
                        len[i+1] = len[i];
                        len[i] = temp;
                    
                        temp = wid[i+1];
                        wid[i+1] = wid[i];
                        wid[i] = temp;
                    }
                }
            int max = 1, count[20] = {0};    
            for (int j = 0; j < n2; j++)//當底
            {    
                int l = len[j], w = wid[j];
				count[j] = 1;
                for (int i = j; i < n2 - 1; i++)//疊上去 
                {   
                    if (len[i+1] <= l && wid[i+1] <= w)
                    {
                        count[j]++;
                        l = len[i+1];
                        w = wid[i+1];
                    }
                    else if (wid[i+1] <= l && len[i+1] <= w)
                    {
                        count[j]++;
                        l = wid[i+1];
                        w = len[i+1];
                    }
                }	
            }
            for (int i = 0; i < n2; i++)
            {	
				if (count[i] > max)
            		max = count[i];
			}
            cout << max << endl;
        }
    }
    file.close();//關檔 
    system("pause");
    return 0;
}
