#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string animal, place, ani[200], pla[200];
	int n, number, num[200], i=0;
	
	fstream file;//�ŧifstream���� 
	file.open("T7.txt", ios::in);//Ū�����A�U�}���ɮ� 
	if (!file)//�ˬd�ɮ׬O�_���\�}�ҡA�Y!file���u�A�ɮ׫h�L�k�}�� 
	{
		cout << "Can't open the file!" << endl;
		exit(1);//�b�����`���ΤU�A���_�{�������� 
	}
	if(file >> n)
	{
		while (file >> animal >> number >> place)//Ū�������A�YŪ�����ɮ׵����h�^��0 �A���Xwhile�j��A��Ū�� 
		{
			ani[i] = animal;//�N�ʪ��B�ƶq�B�a�I�s�ܰ}�C  
			num[i] = number;
			pla[i] = place;
			i++;
		}
	}	
	for (int j = 0; j < 200; j++)//������A�Y(�a�I��ʪ�)�ۦP�h�ƶq�ۥ[(�ⶵ�X��)
		for (int k = j+1; k < 200; k++)
		{
			if (ani[j] == ani[k] && pla[j] == pla[k] && num[k] != 0)
			{
				num[j] += num[k];
				num[k] = 0;//�X�ֵ��L�Ȫ��ƶq�]��0
			}
		}
	for (int j = 0; j < 200; j++)
	{
		if (num[j] != 0)
			cout << pla[j] << ":" << ani[j] << " " << num[j];//�L�X�X�᪺֫�a�I�M�Ӧa�I���Ĥ@�ذʪ� 
	
		for (int k = j+1; k < 200; k++)
		{
			if (pla[j] == pla[k] && num[k] !=0)//�Ppla[j]�a�I�ۦP���L�X 
			{
				cout << ", " << ani[k] << " " << num[k];
				num[k] = 0;
			}
		}
		if (num[j] != 0)
			cout << endl;
	}
	file.close();//���� 
	system("pause");
	return 0;
}
