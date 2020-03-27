#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file; // �ŧi fstream���� 
	file.open("T15.txt", ios::in); // Ū�����A�U�}���ɮ� 
	if (!file) // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
	{
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	int n;
	while (file >> n)
	{
		if (n)
		{
			
			int num, i, j, count, standard, max = 0;
			num = n;
			standard = 0;
			while (num) // ���J���Ʀr���X�� 1 
			{
				if (num % 2 == 1)
					standard++;
				num /= 2;
			}
			for (i = 2; i <= n; i++) // ���� 
			{
				for (j = 2; j <= n - 1; j++)
				{
					if (i % j == 0)
						break;
				}
				if (j == i)
				{
					count = 0;
					while (j) // ���Ʀ��X�� 1 
					{
						if (j % 2 == 1)
							count++;
						j /= 2;
					}
					if (count == standard && i > max)
						max = i;
				}
			}
			cout << max << endl;
	    }
	}
	file.close(); // ���� 
	system("pause");
	return 0;
}
