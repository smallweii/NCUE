#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int n1, n2, length, width, len[20], wid[20];
    
    fstream file;//�ŧifstream����
    file.open("T9.txt", ios::in);//Ū�����A�U�}���ɮ�
    if (!file)//�ˬd�ɮ׬O�_���\�}�ҡA�Y!file���u�A�ɮ׫h�L�k�}��
    {
        cout << "Can't open the file!" << endl;
        exit(1);//�b�����`���ΤU�A���_�{�������� 
    }
    if (file >> n1)
    {
        while (file >> n2)
        {
            int i = 0;
            while (file >> length >> width)
            {
                len[i] = length;
                wid[i] = width;
                i++;
                if (i == n2)
                    break;
            }
            for (int j = 0; j < n2; j++)//bubble sort
                for (int i = 0; i < n2 - 1 ; i++)
                {
                    if (len[i+1] * wid[i+1] > len[i] * wid[i])//�Y�᭱���n>�e�����n�N(���� �e��)�@�_�����A���F�e�j��p���ƦC 
                    {
                        int temp;
                        temp = len[i+1];
                        len[i+1] = len[i];
                        len[i] = temp;
                    
                        temp = wid[i+1];
                        wid[i+1] = wid[i];
                        wid[i] = temp;
                    }
                }
            int max = 1, count[20] = {0};    
            for (int j = 0; j < n2; j++)//��
            {    
                int l = len[j], w = wid[j];
				count[j] = 1;
                for (int i = j; i < n2 - 1; i++)//�|�W�h 
                {   
                    if (len[i+1] <= l && wid[i+1] <= w)
                    {
                        count[j]++;
                        l = len[i+1];
                        w = wid[i+1];
                    }
                    else if (wid[i+1] <= l && len[i+1] <= w)
                    {
                        count[j]++;
                        l = wid[i+1];
                        w = len[i+1];
                    }
                }	
            }
            for (int i = 0; i < n2; i++)
            {	
				if (count[i] > max)
            		max = count[i];
			}
            cout << max << endl;
        }
    }
    file.close();//���� 
    system("pause");
    return 0;
}
