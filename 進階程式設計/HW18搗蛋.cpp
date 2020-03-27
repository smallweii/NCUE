#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file; // �ŧi fstream���� 
    file.open("T18.txt", ios::in); // Ū�����A�U�}���ɮ� 
    if (!file) // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
    {
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    int n, x1, y1, x2, y2, m, a, b;
    if (file >> n) // ���X�ո�� 
    {
        while (file >> x1 >> y1 >> x2 >> y2) // �t�� 1�B2���y�� 
        {
			if (file >> m) // ���X�ӷo�J 
            {
                int arr[10][2] = {0};
				for (int i = 0; i < m; i++)
                {
                	file >> a >> b; // �C�ӷo�J���y�� 
					arr[i][0] = a;
                	arr[i][1] = b;
				}
				int ra[10] = {0}, rb[10] = {0};
				for (int i = 0; i < m; i++)
				{
					ra[i] = (arr[i][0] - x1) * (arr[i][0] - x1) + (arr[i][1] - y1) * (arr[i][1] - y1); // �C�ӷo�J��t�� 1���Z�� 
					rb[i] = (arr[i][0] - x2) * (arr[i][0] - x2) + (arr[i][1] - y2) * (arr[i][1] - y2); // �C�ӷo�J��t�� 2���Z�� 
				}
				int min_a[10] = {0};
				for (int i = 0; i < m; i++) // �C�ӷo�J��t�� 1���Z������ 
				{
					int max = 0;
					for (int j = 0; j < m; j++)
						if (ra[i] < ra[j])
							if (rb[j] > max)
								max = rb[j];
					min_a[i] = ra[i] + max;
				}
				int min_b[10] = {0};
				for (int i = 0; i < m; i++) // �C�ӷo�J��t�� 2���Z������ 
				{
					int max = 0;
					for (int j = 0; j < m; j++)
						if (rb[i] < rb[j])
							if (ra[j] > max)
								max = ra[j];
					min_b[i] = rb[i] + max;
				}
				int min = 10000;
				for (int i = 0; i < m; i++)
				{
					if (min_a[i] < min)
						min = min_a[i];
					if (min_b[i] < min)
						min = min_b[i];
				}
				cout << min << endl;
            }
        }
    }
    file.close(); // ���� 
    system("pause");
    return 0;
}
