#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // �ŧi fstream���� 
    file.open("T20_1.txt", ios::in); // Ū�����A�U�}���ɮ� 
    if (!file) // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    char m;
    int n, a[10][11] = {0}, b[10][11] = {0};
    
    for (int i = 0; i < 10; i++) // �x�s��s�ͩM����@ 
        for (int j = 0; j < 11; j++) {
            file >> m >> n;
            a[i][j] = n;
        }
    for (int i = 0; i < 10; i++) // �x�s�б©M����@ 
        for (int j = 0; j < 11; j++) {
            file >> m >> n;
            b[i][j] = n;
        }	
    for (int j = 1; j < 11; j++) {
		for (int i = 0; i < 10; i++) {
			int pro, min = 11, stu[10] = {0}, hope, match, memory = 0, temp = 0; // 5,5,6,10,6,5,10,7,3,6
        	
			if (a[i][j]) {
				for (int x = i; x < 10; x++) {
					pro = a[x][j];
					if (pro) { // �P���s�ͤ����쪺�б� 
						memory = 1; // �Y���@�˱б´N���O�� 
						temp = j;
						//cout << pro << " ";
						break;
					}
				}
				for (int x = 0; x < 10; x++) {
					if (a[x][temp] == pro) {
						stu[x] = a[x][0]; // ���@�˱бª���s�ͽs���x�s�� stu�}�C 
						//cout << stu[x] << " ";
					}	
				}
				for (int x = 0; x < 10; x++) {
					for (int y = 1; y < 11; y++) {
						if (b[pro - 1][y] == stu[x]) { // ��s�ͽs��������б§��@ 
							hope = y; // ��s�ͦb�б§��@���� y�� 
							if (hope < min) {
								min = hope; // �̫e�������@���ӱб� 
								match = x;
							}
						}	
					}
				}
				for (int y = 1; y < 11; y++) {
					for (int x = 0; x < 10; x++) {
						if (a[x][y] == pro) { // �Y�}�C�̦��Q�飼���б´N�M�� 0 
							a[x][y] = 0;
						}
					}
				}
				for (int y = 2; y < 11; y++)
					a[match][y] = 0;
				a[match][1] = pro;	
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << "A" << i + 1 << ",B" << a[i][1] << endl;
    file.close();
    system("pause");
    return 0;
}
