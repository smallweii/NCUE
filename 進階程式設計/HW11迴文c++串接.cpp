#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string str, arr1[50] = "\0", arr2[50] = "\0", word[9] = {"一", "二", "三", "四", "五", "六", "七", "八", "九"}, copy = "\0";
	int n, w = 0;
        
	fstream file;//宣告fstream物件 
    file.open("T11.txt", ios::in);//讀取狀態下開啟檔案 
    if (!file)//檢查檔案是否成功開啟，若!file為真，檔案則無法開啟 
    {
        cout << "Can't open the file!" << endl;
        exit(1);//在不正常情形下，中斷程式的執行 
    }
    if (file >> n)
    {
		while (file >> str)//讀取紀錄，若讀取至檔案結尾則回傳0，跳出while迴圈再次讀取 
        {
            int count1[50] = {0};
			for (int i = 1; i < str.length(); i++)
            {
 				int center = 1;
                arr1[i] = str.at(i);//c
				for (int j = 1; i - j >= 0 && i + j < str.length(); j++)//若&&改為,表||(其一成立另一不成立還是會往下跑if可是抓不到值) 
                {		            	
                	if (str.at(i - j) == str.at(i + j))//abcba 有中心  
                    {
                        count1[i] += center;
                        center = 0;
						count1[i] += 2;
						arr1[i] += str.at(i + j);//cb →cba
                    }
                    else
                    	break;
                }
            }
            int max = 0, memory;
            for (int i = 0; i < 50; i++)
            {
            	if (count1[i] > max)
            	{
					max = count1[i];
					memory = 1;//有中心的情況下memory = 1
				}
			}
			int count2[50] = {0};
			for (int i = 0; i < 50; i++)
				arr2[i].clear();//清空arr2，可能之前有殘留 
            for (int i = 0; i < str.length(); i++)
            {
                for (int j = 0; i - j >= 0 && i + j + 1 < str.length(); j++)
                {
                    if (str.at(i - j) == str.at(i + j + 1))//abccba 沒中心 
                    {
                        count2[i] += 2;
                        arr2[i] += str.at(i + j + 1);//b →ba
                    }
                    else
                    	break;
                }
            }
            for (int i = 0; i < 50; i++)
            {
            	if (count2[i] > max)
            	{
					max = count2[i];
					memory = 0;//沒中心的情況下memory = 0
				}
			}
        	cout << "第" << word[w] << "組測試資料的最長迴文子字串長度為 : " << max << endl;
        	cout << "第" << word[w] << "組測試資料的所有最長迴文子字串內容為 : ";
        	w++;
			if (max == 0)//沒迴文 
				cout << "沒有迴文字串哦曉維好高" << endl;
			else//有迴文 
			{
				if (memory == 1)//有中心 
				{
					for (int i = 0; i < 50; i++)
					{
						if (max == count1[i])
						{
							if (arr1[i] != copy)
							{
								for (int j = arr1[i].length() - 1; j > 0; j--)
									cout << arr1[i].at(j);//a →ab
								cout << arr1[i] << endl;//ab →abcba
								copy = arr1[i];
							}
						}
					}
				}	
        		else//沒中心 
        		{
					for (int i = 0; i < 50; i++)
					{
						if (max == count2[i])
						{
							if (arr2[i] != copy)
							{
								for (int j = arr2[i].length() - 1; j >= 0; j--)
									cout << arr2[i].at(j);//a →ab
								cout << arr2[i] << endl;//ab →abba	
								copy = arr2[i];
							}
						}
					}
				}
			}
        	cout << endl;
        }
    }
    file.close();//關檔 
    system("pause");
    return 0;
}
