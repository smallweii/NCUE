#include<iostream>
using namespace std;

int main()
{
    int n1, n2, sum = 0, max = 0, big;
    
    cout << "��J�G";
    cin >> n1 >> n2;
    cout << "��X�G" << endl;
    
    for (int n = n1; n <= n2; n++)
    {
        int arr[1000] = {0};
        
        if (n % 2 == 0) //�Ĥ@�Ӭ����� 
        {
            arr[0] = n;
            for (int i = 0; i < 1000; i++)
            {
                if (arr[i] % 2 == 0) //���� 
                    arr[i + 1] = arr[i] / 2;
                else //�_�� 
                {
                     if(arr[i] == 1)
                         continue;
                     else
                         arr[i + 1] = 3 * arr[i] + 1;
                }    
            }
        }
        else //�Ĥ@�Ӭ��_�� 
        {
            arr[0] = n;
            for (int i = 0; i < 1000; i++)
            {
                if (arr[i] % 2 == 0) //���� 
                    arr[i + 1] = arr[i] / 2;
                else //�_�� 
                {
                     if(arr[i] == 1)
                         continue;
                     else
                         arr[i + 1] = 3 * arr[i] + 1;
                }
            }
        }
        for (int i = 0; i < 1000; i++) //�ӼƦC�`�M 
                sum += arr[i];
        if (sum > max)
        {
            max = sum;
            big = n;
        }
        sum = 0;
    }
    cout << "�̤j�ƦC�`�M�G" << max << endl;
    cout << "�ƦC��a1�ȡG" << big << endl;
    system("pause");
    return 0;
}
