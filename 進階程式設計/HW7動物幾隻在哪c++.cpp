#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string animal, place, ani[200], pla[200];
	int n, number, num[200], i=0;
	
	fstream file;//宣告fstream物件 
	file.open("T7.txt", ios::in);//讀取狀態下開啟檔案 
	if (!file)//檢查檔案是否成功開啟，若!file為真，檔案則無法開啟 
	{
		cout << "Can't open the file!" << endl;
		exit(1);//在不正常情形下，中斷程式的執行 
	}
	if(file >> n)
	{
		while (file >> animal >> number >> place)//讀取紀錄，若讀取至檔案結尾則回傳0 ，跳出while迴圈再次讀取 
		{
			ani[i] = animal;//將動物、數量、地點存至陣列  
			num[i] = number;
			pla[i] = place;
			i++;
		}
	}	
	for (int j = 0; j < 200; j++)//兩兩比較，若(地點跟動物)相同則數量相加(兩項合併)
		for (int k = j+1; k < 200; k++)
		{
			if (ani[j] == ani[k] && pla[j] == pla[k] && num[k] != 0)
			{
				num[j] += num[k];
				num[k] = 0;//合併給他值的數量設為0
			}
		}
	for (int j = 0; j < 200; j++)
	{
		if (num[j] != 0)
			cout << pla[j] << ":" << ani[j] << " " << num[j];//印出合併後的地點和該地點的第一種動物 
	
		for (int k = j+1; k < 200; k++)
		{
			if (pla[j] == pla[k] && num[k] !=0)//與pla[j]地點相同的印出 
			{
				cout << ", " << ani[k] << " " << num[k];
				num[k] = 0;
			}
		}
		if (num[j] != 0)
			cout << endl;
	}
	file.close();//關檔 
	system("pause");
	return 0;
}
