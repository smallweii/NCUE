#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    fstream file; // �ŧi fstream���� 
    file.open("T21.txt", ios::in); // Ū�����A�U�}���ɮ� 
    if (!file) { // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    int n, m;
    
    if (file >> n) { // ���X�ո�� 
        while (file >> m) { // �C�ո�Ʀ��X�ӼƦr 
            int M, num[31] = {0};
            
            for (int i = 0; i < m; i++) {
                file >> M; // �C�ո�ƪ��Ʀr 
                num[i] = M;
            }
            int d = 2, arr[31][31] = {0}, arr2[31][31] = {0};
            
            while (d < m) { // �ת��]�}�C �t 
                for (int i = 1, j = i + d; i <= m, j <= m; i++, j++) {
            		int big, small, max = 0, min = 100000;
            	
                    if (d == 2) {
                        arr[i][j] = num[i - 1] * num[i] * num[j - 1];
                        arr2[i][j] = num[i - 1] * num[i] * num[j - 1];
                    } else {
                        for (int k = i + 1; k < j; k++) {
                            big = arr[i][k] + arr[k][j] + num[i - 1] * num[k - 1] * num[j - 1];
                            small = arr2[i][k] + arr2[k][j] + num[i - 1] * num[k - 1] * num[j - 1];
                            if (big > max)
                                max = big;
                            if (small < min)
                                min = small;
                        }
                        arr[i][j] = max;
                        arr2[i][j] = min;
                    }    
                }
                d++;  
            }
            cout << "�ƦC�Y��̤j�įq�Ȭ� " << setw(10) << std::left << arr[1][m] << "�̤p�įq�Ȭ� " << arr2[1][m] << endl << endl;
        }
    }
    file.close(); // ���� 
    system("pause");
    return 0;
}
