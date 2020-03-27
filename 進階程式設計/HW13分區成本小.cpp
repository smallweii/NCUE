#include<iostream>
#include<fstream>
//#include<cmath>
using namespace std;

//void abs(int, int);

int main()
{
    fstream file; //�ŧifstream����
    file.open("T13.txt", ios::in); //Ū�����A�U�}���ɮ� 
    if (!file) //�ˬd�ɮ׬O�_���\�}�ҡA�Y!file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!";
        exit(1); //�b�����`���ΤU�A���_�{�������� 
    }
    int num, r, c, n, arr[11][51] = {0};
    if (file >> num)
    {
        while (file >> r >> c)
        {
            int x, y, s, t, sum = 0, min = 1000000000, small1 = 0, small2 = 0;
            
            for (int i = 1; i <= r; i++)
                for (int j = 1; j <= c; j++)
                    if (file >> n)
                        arr[i][j] = n; //��C�ӼƦr�s���}�C 
                        
            for (int x = 1; x <= r; x++) //�C�Ӥ��Ϸ��� 
            {
                for (int y = 1; y <= c; y++)
                {
                    sum = 0;
                    for (int i = 1; i <= r; i++) //��L�H�����Ϭ����ߨӲ��� 
                    {
                        for (int j = 1; j <= c; j++)
                        {
                            sum += (arr[i][j] * (abs(x - i) + abs(y - j)) * 10);
                        }
                    }
                    if (sum < min)
                    {
                        min = sum;
                        small1 = x;
                        small2 = y; 
                    }
                } 
            }
            cout << small1 << " " << small2 << endl << min << endl << endl;
        }
    }
    file.close(); //���� 
    system("pause");
    return 0;
}
