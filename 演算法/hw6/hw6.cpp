#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int from[50][50]; // �����ثeLCS�����׬O������ 
string s1, s2, lcs[50];
int n = 0;
int len; // LCS������ 

void LCS(int i, int j) {
	if (n == len)
		return;
	if (from[i][j] == 1) { // ���W�� 
		lcs[n] = s1[i - 1];
		n++;
		LCS(i - 1, j - 1);
	}
	else if (from[i][j] == 2) // ���� 
		LCS(i, j - 1);
	else // �W�� 
		LCS(i - 1, j);
}

int main() {		
	cout << "�п�J��Ӧr��(�H�Ů�j�}): ";
	cin >> s1 >> s2;
	
	int arr[s1.length() + 1][s2.length() + 1]; // �����ثeLCS������ 
	
	for (int i = 0; i < s1.length() + 1; i++) // ��0��]��0 
		arr[i][0] = 0;
	for (int i = 0; i < s2.length() + 1; i++) // ��0�C�]��0 
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
			if (s1[i - 1] == s2[j - 1]) { // ���W�� 
				arr[i][j] = arr[i - 1][j - 1] + 1;
				cout << arr[i][j] << "\t";
				from[i][j] = 1;
			}
			else { // �索��ΤW����j������ 
				if (arr[i][j - 1] >= arr[i - 1][j]) { // ���� 
					arr[i][j] = arr[i][j - 1];
					cout << arr[i][j - 1] << "\t";
					from[i][j] = 2;
				}
				else { // �W�� 
					arr[i][j] = arr[i - 1][j];
					cout << arr[i][j] << "\t";
					from[i][j] = 3;
				}
			}
		}
		cout << endl;
	}
	len = arr[s1.length()][s2.length()]; // LCS������ 
	
	LCS(s1.length(), s2.length());
	
	cout << "LCS�� ";
	for (int i = n - 1; i >= 0; i--)
		cout << lcs[i];
	cout << endl;
	
	system("pause");
	return 0;
}
