#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file; // �ŧi fstream���� 
	file.open("T255.txt", ios::in); // Ū�����A�U�}���ɮ� 
	if (!file) { // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	int p;
	
	if (file >> p) { // �@�� p�ո�� 
		int n, m, num = 0, match[50][50] = {0};
		
		while (file >> n) { // �C�ժ��x�}�j�p�� n*n 
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (file >> m) // ��C�ӳt�t�Ȧs���}�C 
						match[i][j] = m;
			int max = 0, male[50] = {0}, sum_male = 0, female[50] = {0}, sum_female = 0;
			string ch[5] = {"�@", "�G", "�T", "�|", "��"};
			
			for (int i = 0; i < n; i++) { // �k��k���t�t�{�סA�C�C��̤j�� 
				max = 0;
				for (int j = 0; j < n; j++)
					if (match[i][j] > max)
						max = match[i][j];
				male[i] = max;
			}
			for (int i = 0; i < n; i++) // �k���N�t�t�`�M 
				sum_male += male[i];
			for (int j = 0; j < n; j++) { // �k��k���t�t�{�סA�C���̤j�� 
				max = 0;
				for (int i = 0; i < n; i++)
					if (match[i][j] > max)
						max = match[i][j];
				female[j] = max;
			}
			for (int j = 0; j < n; j++) // �k���N�t�t�`�M 
				sum_female += female[j];
			cout << "��" << ch[num] << "�մ��ո�Ƶ��G" << endl;
			num++;
			cout << "(a)���Ҧ����ͳ��̺��N���u�t�t�{�סv�`����" << sum_male << "��" << endl;
			cout << "(b)���Ҧ��p�j���̺��N���u�t�t�{�סv�`����" << sum_female << "��" << endl;
			cout << "(c)���������̰��u�t�t�{�סv�`����" << "��" << endl << endl;
		}
	}
	file.close(); // ���� 
	system("pause");
	return 0;
}
