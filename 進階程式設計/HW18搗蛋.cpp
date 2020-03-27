#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T18.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    int n, x1, y1, x2, y2, m, a, b;
    if (file >> n) // 有幾組資料 
    {
        while (file >> x1 >> y1 >> x2 >> y2) // 系統 1、2的座標 
        {
			if (file >> m) // 有幾個搗蛋 
            {
                int arr[10][2] = {0};
				for (int i = 0; i < m; i++)
                {
                	file >> a >> b; // 每個搗蛋的座標 
					arr[i][0] = a;
                	arr[i][1] = b;
				}
				int ra[10] = {0}, rb[10] = {0};
				for (int i = 0; i < m; i++)
				{
					ra[i] = (arr[i][0] - x1) * (arr[i][0] - x1) + (arr[i][1] - y1) * (arr[i][1] - y1); // 每個搗蛋跟系統 1的距離 
					rb[i] = (arr[i][0] - x2) * (arr[i][0] - x2) + (arr[i][1] - y2) * (arr[i][1] - y2); // 每個搗蛋跟系統 2的距離 
				}
				int min_a[10] = {0};
				for (int i = 0; i < m; i++) // 每個搗蛋跟系統 1的距離當基準 
				{
					int max = 0;
					for (int j = 0; j < m; j++)
						if (ra[i] < ra[j])
							if (rb[j] > max)
								max = rb[j];
					min_a[i] = ra[i] + max;
				}
				int min_b[10] = {0};
				for (int i = 0; i < m; i++) // 每個搗蛋跟系統 2的距離當基準 
				{
					int max = 0;
					for (int j = 0; j < m; j++)
						if (rb[i] < rb[j])
							if (ra[j] > max)
								max = ra[j];
					min_b[i] = rb[i] + max;
				}
				int min = 10000;
				for (int i = 0; i < m; i++)
				{
					if (min_a[i] < min)
						min = min_a[i];
					if (min_b[i] < min)
						min = min_b[i];
				}
				cout << min << endl;
            }
        }
    }
    file.close(); // 關檔 
    system("pause");
    return 0;
}
