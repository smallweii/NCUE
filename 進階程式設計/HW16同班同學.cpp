#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // �ŧi fstream���� 
    file.open("T16.txt", ios::in); // Ū�����A�U�}���ɮ� 
    if (!file) // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    int n, m;
    
    while (file >> n)
    {
        if (n)
        {
            if (file >> m)
            {
                int a, b, stu[20][20] = {0}, group = 0, s, t = -1;
                
				for (int i = 0; i < m; i++)
                {
                    file >> a >> b;
                    int same_a = 0, same_b = 0, memory_a = 0, memory_b = 0;
                    
                    for (int j = 0; j < 20; j++)
                    	for (int k = 0; k < 20; k++)
                    	{
                    		if (a == stu[j][k]) // �� a�O�_�X�{�L 
							{
								same_a = 1;
								memory_a = k;
							}
                    		if (b == stu[j][k]) // �� b�O�_�X�{�L 
                    		{
                    			same_b = 1;
                    			memory_b = k;
							}
						}
					if (same_a == 0 && same_b == 0) // a�Ab���S�X�{�L 
					{
						group++;
						s = 0;
						t++;
						stu[s][t] = a;
						s++;
						stu[s][t] = b;
					}
					if (same_a == 0 && same_b == 1) // a�S�X�{�L�Ab�X�{�L 
					{
						s++;
						stu[s][t] = a;
					}
					if (same_a == 1 && same_b == 0) // a�X�{�L�Ab�S�X�{�L 
					{
						s++;
						stu[s][t] = b;
					}
					if (same_a == 1 && same_b == 1 && memory_a != memory_b) // a�Ab���X�{�L�B�b���P�Z 
						group--;
                }
                for (int i = 1; i <= n; i++) // �ݨC�ӤH�O�_���Q����Y�Z 
				{
					bool here = 0;
					
					for (int j = 0; j < 20; j++)
						for (int k = 0; k < 20; k++)
							if (i == stu[j][k])
								here = 1;
					if (here == 0) // ���H�S�Q����Z�N�ۦ��@�Z 
						group++; 
				} 
                cout << group << endl;
            }
		}
    }
    file.close(); // ���� 
    system("pause");
    return 0;
}
