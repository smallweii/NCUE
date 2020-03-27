#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    string s1, s2;
    int val_dash, n, m;
	char answer;
    
    do{
    	cout << "請輸入大寫英文長字串 : ";
		cin >> s1;
		cout << "請輸入大寫英文短字串 : ";
		cin >> s2;
		cout << "請輸入間隔符號之座標值 (0 < 間隔座標值 < 50) : ";
    	cin >> val_dash;
    
    	n = s1.length(); // 字串長度 
    	m = s2.length();
    	
    	int val1[100] = {0}, val2[100] = {0}, arr[100][100] = {0}, route[100][100] = {0}, count[100][100] = {0}, x, y, max, path; 
    	
    	for (int i = 0; i <= n; i++) // 轉換出大寫英文座標值 
			val1[i] = (int)s1[i] - (int)'A' + 1;
		for (int i = 0; i <= m; i++)
			val2[i] = (int)s2[i] - (int)'A' + 1;
		 
    	for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				if (i - j <= n - m) { // 只計算需要用到的(畫圈) 
					if (i >= j) { // 不合的不需要做(打叉) 
						if (i - 1 >= 0 && i - 1 >= j)
							x = arr[i - 1][j] + abs(val1[i - 1] - val_dash); // 路徑一 
						else
							x = 0;
						if (i - 1 >= 0 && j - 1 >= 0)
							y = arr[i - 1][j - 1] + abs(val1[i - 1] - val2[j - 1]); // 路徑二 
    					else
    						y = 0;
    					if (x > y) {
    						max = x;
    						path = 1; // 做記號 path = 1 表示選擇路徑一 
						}
						if (x < y) {
							max = y;
							path = 2; // 做記號 path = 2 表示選擇路徑二  
						} 
    					if (x == y) {
    						max = x; // or max = y;
    						path = 3; // 做記號 path = 3 表示選擇路徑一和二都行 
						}
						arr[i][j] = max; // max一直在前面的判斷後被換掉再 assign給 arr[i][j]，而最後換完的 max為答案 
						route[i][j] = path; // path一直在前面的判斷後被換掉再 assign給 route[i][j]，而最後換完的 path"不一定"為答案，因為有些路可能後面是絕路 
					}
					else
						break;
                }
			}
		cout << endl << "距離 : " << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				cout << setw(6) << std::left << arr[i][j];
			cout << endl;
		}
		cout << endl << "路徑 : " << endl;
		cout << "(1代表可以往正上，2代表可以往左上，3代表可以往左上也可以往正上)" << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				cout << setw(6) << std::left << route[i][j];
			cout << endl;
		}
        cout << endl << "過程 : " << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				count[0][0] = 1;
				if (route[i][j] == 1) // 選擇路徑一，可以往正上 
					count[i][j] = count[i - 1][j];
				else if (route[i][j] == 2) { // 選擇路徑二，可以往左上 
				     if (j - 1 < 0)
                        count[i - 1][j - 1] = 0;
					count[i][j] = count[i - 1][j - 1];
                }
				else if (route[i][j] == 3) { // 選擇路徑一和二都行，可以往正上也可以往左上 
				    if (j - 1 < 0)
                        count[i - 1][j - 1] = 0;
                    count[i][j] = count[i - 1][j] + count[i - 1][j - 1];
                }
                cout << setw(6) << std::left << count[i][j];
                path = count[i][j]; // count[i][j]一直在前面的判斷後被換掉再 assign給 path，而最後換完的 count[i][j]即為答案 
			}
			cout << endl;
        }	
		cout << endl << "結果 : " << endl;
		cout << max << endl << "有" << path << "種插入方法可以產生最長的總距離" << endl;
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
    system("pause");
    return 0;
}
