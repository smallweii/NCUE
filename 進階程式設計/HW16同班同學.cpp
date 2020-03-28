#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // 宣告 fstream物件 
    file.open("T16.txt", ios::in); // 讀取狀態下開啟檔案 
    if (!file) // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // 在不正常情形下，中斷程式的執行 
    }
    int n, m;
    
    while (file >> n)
    {
        if (n)
        {
            if (file >> m)
            {
                int a, b, stu[20][20] = {0}, group = 0, s, t = -1;
                
				for (int i = 0; i < m; i++)
                {
                    file >> a >> b;
                    int same_a = 0, same_b = 0, memory_a = 0, memory_b = 0;
                    
                    for (int j = 0; j < 20; j++)
                    	for (int k = 0; k < 20; k++)
                    	{
                    		if (a == stu[j][k]) // 看 a是否出現過 
							{
								same_a = 1;
								memory_a = k;
							}
                    		if (b == stu[j][k]) // 看 b是否出現過 
                    		{
                    			same_b = 1;
                    			memory_b = k;
							}
						}
					if (same_a == 0 && same_b == 0) // a，b都沒出現過 
					{
						group++;
						s = 0;
						t++;
						stu[s][t] = a;
						s++;
						stu[s][t] = b;
					}
					if (same_a == 0 && same_b == 1) // a沒出現過，b出現過 
					{
						s++;
						stu[s][t] = a;
					}
					if (same_a == 1 && same_b == 0) // a出現過，b沒出現過 
					{
						s++;
						stu[s][t] = b;
					}
					if (same_a == 1 && same_b == 1 && memory_a != memory_b) // a，b都出現過且在不同班 
						group--;
                }
                for (int i = 1; i <= n; i++) // 看每個人是否有被分到某班 
				{
					bool here = 0;
					
					for (int j = 0; j < 20; j++)
						for (int k = 0; k < 20; k++)
							if (i == stu[j][k])
								here = 1;
					if (here == 0) // 那人沒被分到班就自成一班 
						group++; 
				} 
                cout << group << endl;
            }
		}
    }
    file.close(); // 關檔 
    system("pause");
    return 0;
}
