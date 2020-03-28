#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file; // 宣告 fstream物件 
	file.open("T15.txt", ios::in); // 讀取狀態下開啟檔案 
	if (!file) // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
	{
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	int n;
	while (file >> n)
	{
		if (n)
		{
			
			int num, i, j, count, standard, max = 0;
			num = n;
			standard = 0;
			while (num) // 算輸入的數字有幾個 1 
			{
				if (num % 2 == 1)
					standard++;
				num /= 2;
			}
			for (i = 2; i <= n; i++) // 找質數 
			{
				for (j = 2; j <= n - 1; j++)
				{
					if (i % j == 0)
						break;
				}
				if (j == i)
				{
					count = 0;
					while (j) // 算質數有幾個 1 
					{
						if (j % 2 == 1)
							count++;
						j /= 2;
					}
					if (count == standard && i > max)
						max = i;
				}
			}
			cout << max << endl;
	    }
	}
	file.close(); // 關檔 
	system("pause");
	return 0;
}
