#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file; // 宣告 fstream物件 
	file.open("T255.txt", ios::in); // 讀取狀態下開啟檔案 
	if (!file) { // 檢查檔案是否成功開啟，若 !file為真，檔案則無法開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	int p;
	
	if (file >> p) { // 共有 p組資料 
		int n, m, num = 0, match[50][50] = {0};
		
		while (file >> n) { // 每組的矩陣大小為 n*n 
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (file >> m) // 把每個速配值存成陣列 
						match[i][j] = m;
			int max = 0, male[50] = {0}, sum_male = 0, female[50] = {0}, sum_female = 0;
			string ch[5] = {"一", "二", "三", "四", "五"};
			
			for (int i = 0; i < n; i++) { // 男對女的速配程度，每列找最大值 
				max = 0;
				for (int j = 0; j < n; j++)
					if (match[i][j] > max)
						max = match[i][j];
				male[i] = max;
			}
			for (int i = 0; i < n; i++) // 男滿意速配總和 
				sum_male += male[i];
			for (int j = 0; j < n; j++) { // 女對男的速配程度，每行找最大值 
				max = 0;
				for (int i = 0; i < n; i++)
					if (match[i][j] > max)
						max = match[i][j];
				female[j] = max;
			}
			for (int j = 0; j < n; j++) // 女滿意速配總和 
				sum_female += female[j];
			cout << "第" << ch[num] << "組測試資料結果" << endl;
			num++;
			cout << "(a)讓所有先生都最滿意的「速配程度」總分為" << sum_male << "分" << endl;
			cout << "(b)讓所有小姐都最滿意的「速配程度」總分為" << sum_female << "分" << endl;
			cout << "(c)完滿結局最高「速配程度」總分為" << "分" << endl << endl;
		}
	}
	file.close(); // 關檔 
	system("pause");
	return 0;
}
