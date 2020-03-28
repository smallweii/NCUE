#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int from[50][50]; // 紀錄目前LCS的長度是打哪來 
string s1, s2, lcs[50];
int n = 0;
int len; // LCS的長度 

void LCS(int i, int j) {
	if (n == len)
		return;
	if (from[i][j] == 1) { // 左上方 
		lcs[n] = s1[i - 1];
		n++;
		LCS(i - 1, j - 1);
	}
	else if (from[i][j] == 2) // 左方 
		LCS(i, j - 1);
	else // 上方 
		LCS(i - 1, j);
}

int main() {		
	cout << "請輸入兩個字串(以空格隔開): ";
	cin >> s1 >> s2;
	
	int arr[s1.length() + 1][s2.length() + 1]; // 紀錄目前LCS的長度 
	
	for (int i = 0; i < s1.length() + 1; i++) // 第0行設為0 
		arr[i][0] = 0;
	for (int i = 0; i < s2.length() + 1; i++) // 第0列設為0 
		arr[0][i] = 0;
	
	cout << "\t\t";
	for (int i = 0; i < s2.length(); i++)
		cout << s2[i] << "\t";
	cout << endl << "\t";
	for (int i = 0; i < s2.length() + 1; i++)
		cout << 0 << "\t";
	cout << endl;
	
	for (int i = 1; i < s1.length() + 1; i++) {
		cout << s1[i - 1] << "\t" << 0 << "\t";
		for (int j = 1; j < s2.length() + 1; j++) {
			if (s1[i - 1] == s2[j - 1]) { // 左上方 
				arr[i][j] = arr[i - 1][j - 1] + 1;
				cout << arr[i][j] << "\t";
				from[i][j] = 1;
			}
			else { // 選左方或上方較大的長度 
				if (arr[i][j - 1] >= arr[i - 1][j]) { // 左方 
					arr[i][j] = arr[i][j - 1];
					cout << arr[i][j - 1] << "\t";
					from[i][j] = 2;
				}
				else { // 上方 
					arr[i][j] = arr[i - 1][j];
					cout << arr[i][j] << "\t";
					from[i][j] = 3;
				}
			}
		}
		cout << endl;
	}
	len = arr[s1.length()][s2.length()]; // LCS的長度 
	
	LCS(s1.length(), s2.length());
	
	cout << "LCS為 ";
	for (int i = n - 1; i >= 0; i--)
		cout << lcs[i];
	cout << endl;
	
	system("pause");
	return 0;
}
