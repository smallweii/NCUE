#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string str, arr1[50] = "\0", arr2[50] = "\0", word[9] = {"�@", "�G", "�T", "�|", "��", "��", "�C", "�K", "�E"}, copy = "\0";
	int n, w = 0;
        
	fstream file;//�ŧifstream���� 
    file.open("T11.txt", ios::in);//Ū�����A�U�}���ɮ� 
    if (!file)//�ˬd�ɮ׬O�_���\�}�ҡA�Y!file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!" << endl;
        exit(1);//�b�����`���ΤU�A���_�{�������� 
    }
    if (file >> n)
    {
		while (file >> str)//Ū�������A�YŪ�����ɮ׵����h�^��0�A���Xwhile�j��A��Ū�� 
        {
            int count1[50] = {0};
			for (int i = 1; i < str.length(); i++)
            {
 				int center = 1;
                arr1[i] = str.at(i);//c
				for (int j = 1; i - j >= 0 && i + j < str.length(); j++)//�Y&&�אּ,��||(��@���ߥt�@�������٬O�|���U�]if�i�O�줣���) 
                {		            	
                	if (str.at(i - j) == str.at(i + j))//abcba ������  
                    {
                        count1[i] += center;
                        center = 0;
						count1[i] += 2;
						arr1[i] += str.at(i + j);//cb ��cba
                    }
                    else
                    	break;
                }
            }
            int max = 0, memory;
            for (int i = 0; i < 50; i++)
            {
            	if (count1[i] > max)
            	{
					max = count1[i];
					memory = 1;//�����ߪ����p�Umemory = 1
				}
			}
			int count2[50] = {0};
			for (int i = 0; i < 50; i++)
				arr2[i].clear();//�M��arr2�A�i�ध�e���ݯd 
            for (int i = 0; i < str.length(); i++)
            {
                for (int j = 0; i - j >= 0 && i + j + 1 < str.length(); j++)
                {
                    if (str.at(i - j) == str.at(i + j + 1))//abccba �S���� 
                    {
                        count2[i] += 2;
                        arr2[i] += str.at(i + j + 1);//b ��ba
                    }
                    else
                    	break;
                }
            }
            for (int i = 0; i < 50; i++)
            {
            	if (count2[i] > max)
            	{
					max = count2[i];
					memory = 0;//�S���ߪ����p�Umemory = 0
				}
			}
        	cout << "��" << word[w] << "�մ��ո�ƪ��̪��j��l�r����׬� : " << max << endl;
        	cout << "��" << word[w] << "�մ��ո�ƪ��Ҧ��̪��j��l�r�ꤺ�e�� : ";
        	w++;
			if (max == 0)//�S�j�� 
				cout << "�S���j��r��@����n��" << endl;
			else//���j�� 
			{
				if (memory == 1)//������ 
				{
					for (int i = 0; i < 50; i++)
					{
						if (max == count1[i])
						{
							if (arr1[i] != copy)
							{
								for (int j = arr1[i].length() - 1; j > 0; j--)
									cout << arr1[i].at(j);//a ��ab
								cout << arr1[i] << endl;//ab ��abcba
								copy = arr1[i];
							}
						}
					}
				}	
        		else//�S���� 
        		{
					for (int i = 0; i < 50; i++)
					{
						if (max == count2[i])
						{
							if (arr2[i] != copy)
							{
								for (int j = arr2[i].length() - 1; j >= 0; j--)
									cout << arr2[i].at(j);//a ��ab
								cout << arr2[i] << endl;//ab ��abba	
								copy = arr2[i];
							}
						}
					}
				}
			}
        	cout << endl;
        }
    }
    file.close();//���� 
    system("pause");
    return 0;
}
