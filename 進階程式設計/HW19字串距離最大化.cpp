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
    	cout << "�п�J�j�g�^����r�� : ";
		cin >> s1;
		cout << "�п�J�j�g�^��u�r�� : ";
		cin >> s2;
		cout << "�п�J���j�Ÿ����y�Э� (0 < ���j�y�Э� < 50) : ";
    	cin >> val_dash;
    
    	n = s1.length(); // �r����� 
    	m = s2.length();
    	
    	int val1[100] = {0}, val2[100] = {0}, arr[100][100] = {0}, route[100][100] = {0}, count[100][100] = {0}, x, y, max, path; 
    	
    	for (int i = 0; i <= n; i++) // �ഫ�X�j�g�^��y�Э� 
			val1[i] = (int)s1[i] - (int)'A' + 1;
		for (int i = 0; i <= m; i++)
			val2[i] = (int)s2[i] - (int)'A' + 1;
		 
    	for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				if (i - j <= n - m) { // �u�p��ݭn�Ψ쪺(�e��) 
					if (i >= j) { // ���X�����ݭn��(���e) 
						if (i - 1 >= 0 && i - 1 >= j)
							x = arr[i - 1][j] + abs(val1[i - 1] - val_dash); // ���|�@ 
						else
							x = 0;
						if (i - 1 >= 0 && j - 1 >= 0)
							y = arr[i - 1][j - 1] + abs(val1[i - 1] - val2[j - 1]); // ���|�G 
    					else
    						y = 0;
    					if (x > y) {
    						max = x;
    						path = 1; // ���O�� path = 1 ��ܿ�ܸ��|�@ 
						}
						if (x < y) {
							max = y;
							path = 2; // ���O�� path = 2 ��ܿ�ܸ��|�G  
						} 
    					if (x == y) {
    						max = x; // or max = y;
    						path = 3; // ���O�� path = 3 ��ܿ�ܸ��|�@�M�G���� 
						}
						arr[i][j] = max; // max�@���b�e�����P�_��Q�����A assign�� arr[i][j]�A�ӳ̫ᴫ���� max������ 
						route[i][j] = path; // path�@���b�e�����P�_��Q�����A assign�� route[i][j]�A�ӳ̫ᴫ���� path"���@�w"�����סA�]�����Ǹ��i��᭱�O���� 
					}
					else
						break;
                }
			}
		cout << endl << "�Z�� : " << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				cout << setw(6) << std::left << arr[i][j];
			cout << endl;
		}
		cout << endl << "���| : " << endl;
		cout << "(1�N��i�H�����W�A2�N��i�H�����W�A3�N��i�H�����W�]�i�H�����W)" << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				cout << setw(6) << std::left << route[i][j];
			cout << endl;
		}
        cout << endl << "�L�{ : " << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				count[0][0] = 1;
				if (route[i][j] == 1) // ��ܸ��|�@�A�i�H�����W 
					count[i][j] = count[i - 1][j];
				else if (route[i][j] == 2) { // ��ܸ��|�G�A�i�H�����W 
				     if (j - 1 < 0)
                        count[i - 1][j - 1] = 0;
					count[i][j] = count[i - 1][j - 1];
                }
				else if (route[i][j] == 3) { // ��ܸ��|�@�M�G����A�i�H�����W�]�i�H�����W 
				    if (j - 1 < 0)
                        count[i - 1][j - 1] = 0;
                    count[i][j] = count[i - 1][j] + count[i - 1][j - 1];
                }
                cout << setw(6) << std::left << count[i][j];
                path = count[i][j]; // count[i][j]�@���b�e�����P�_��Q�����A assign�� path�A�ӳ̫ᴫ���� count[i][j]�Y������ 
			}
			cout << endl;
        }	
		cout << endl << "���G : " << endl;
		cout << max << endl << "��" << path << "�ش��J��k�i�H���ͳ̪����`�Z��" << endl;
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
    system("pause");
    return 0;
}
