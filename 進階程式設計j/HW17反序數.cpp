#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // �ŧi fstream���� 
    file.open("T17.txt", ios::in); // Ū�����A�U�}���ɮ� 
    if (!file) // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    int num;
    
    if (file >> num)
    {
        int times = 1;
        
        while (times <= num)
        {
            int i = 0, n, arr[1000], count[1000] = {0};
            while (file >> n)
            {
                arr[i] = n;
                i++;
            
                if (file.get() == '\n' || file.eof())
                    break;
            }
            for (int j = 0; j < i; j++) // �C�Ӽƽ��y���� 
            {
                for (int k = 0; k < j; k++)
                {
                    if (arr[k] > arr[j]) // ��L�j�o�Ʀb�L�e�� 
                        count[j]++;
                }
                for (int k = j + 1; k < i; k++)
                {    
                    if (arr[j] > arr[k]) // ��L�p�o�Ʀb�L�᭱ 
                        count[j]++;
                }
            }
            int max = -1, x = 0;
            
            for (int j = 0; j < i; j++)
                if (count[j] > max)
                {
                    max = count[j];
                    x = j;
                }
            cout << "�ϧǼƳ̤j���Ʀr���G" << arr[x];
            
            for (int j = 0; j < i; j++)
                if (max == count[j] && x != j)
                    cout << "," << arr[j];
                    
            cout << "\t�̤j�ϧǼƬ��G" << max << endl;
            times++;
        }
    }
    file.close(); // ���� 
    system("pause");
    return 0;
}
