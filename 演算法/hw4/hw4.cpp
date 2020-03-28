#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int arr_temp[3][15] = {0}; // �C�Ӥ����Ҭ�0 

void com(int n, int arr[][15]) { // ��� 
	if (arr_temp[0][0] == 0)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr_temp[i][j] = arr[i][j]; // ��Ĥ@����arr_temp��arr���N 
	
	int tmp[3 * n], a[3 * n];
	int k = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			tmp[k] = arr_temp[i][j]; // ��3*n�}�C�s���@���}�C  
			a[k] = arr[i][j];
			k++;
		}
	}
	for (int i = 0; i < 3 * n; i++) { // ������p���@�����B 
		if ((tmp[i] != a[i]) && (a[i] < tmp[i])) { // �P��o���P�Ʀr�ɡA�p��index��a�}�C�N���Ntmp�}�C 
			for (int j = 0; j < 3 * n; j++) {	
				tmp[j] = a[j];
			}
			break;
		}
		else if ((tmp[i] != a[i]) && (a[i] > tmp[i])) // �P��o���P�Ʀr�ɡA�p��index��tmp�}�C�N�٬Otmp�}�C 
			break;
	}
	k = 0;
	int i = 0, j;
	
	while (k < 3 * n) {
		while (i < 3) {
			j = 0;
			while (j < n) {
				arr_temp[i][j] = tmp[k];
				k++;
				j++;
			}
			i++;
		}
	}
}

void horse(int i, int j, int num, int n, int arr[][15]){
	int go = 0; // �i���U�@�B 
	
	if ((i + 1 < 3) && (j + 2 < n) && (arr[i + 1][j + 2] == 0)) { // �U�@��b�d�򤺥B�����L 
		arr[i + 1][j + 2] = num + 1;
		horse(i + 1, j + 2, num + 1, n, arr);
		arr[i + 1][j + 2] = 0; // ���X��誺���j��A��U�@���k�s�A�A���U��if�ݦ��L��L�� 
	}
	if ((i + 2 < 3) && (j + 1 < n) && (arr[i + 2][j + 1] == 0)) {
		arr[i + 2][j + 1] = num + 1;
		horse(i + 2, j + 1, num + 1, n, arr);
		arr[i + 2][j + 1] = 0;
	}
	if ((i + 1 < 3) && (j - 2 >= 0) && (arr[i + 1][j - 2] == 0)) {
		arr[i + 1][j - 2] = num + 1;
		horse(i + 1, j - 2, num + 1, n, arr);
		arr[i + 1][j - 2] = 0;
	}
	if ((i + 2 < 3) && (j - 1 >= 0) && (arr[i + 2][j - 1] == 0)) {
		arr[i + 2][j - 1] = num + 1;
		horse(i + 2, j - 1, num + 1, n, arr);
		arr[i + 2][j - 1] = 0;
	}
	if ((i - 1 >= 0) && (j - 2 >= 0) && (arr[i - 1][j - 2] == 0)) {
		arr[i - 1][j - 2] = num + 1;
		horse(i - 1, j - 2, num + 1, n, arr);
		arr[i - 1][j - 2] = 0;
	}
	if ((i - 2 >= 0) && (j - 1 >= 0) && (arr[i - 2][j - 1] == 0)) {
		arr[i - 2][j - 1] = num + 1;
		horse(i - 2, j - 1, num + 1, n, arr);
		arr[i - 2][j - 1] = 0;
	}
	if ((i - 1 >= 0) && (j + 2 < n) && (arr[i - 1][j + 2] == 0)) {
		arr[i - 1][j + 2] = num + 1;
		horse(i - 1, j + 2, num + 1, n, arr);
		arr[i - 1][j + 2] = 0;
	}
	if ((i - 2 >= 0) && (j + 1 < n) && (arr[i - 2][j + 1] == 0)) {
		arr[i - 2][j + 1] = num + 1;
		horse(i - 2, j + 1, num + 1, n, arr);
		arr[i - 2][j + 1] = 0;
	}
	
	if (num == 3 * n) // ����̫�@��F 
		com(n, arr);
}

int main() {
	char answer;
	
	do {
		int n; // ��n�� 
		
		cout << "�п�J�@�ӥ����: " << endl;
		cin >> n;
		while (n <= 0) {
			cout << "�п�J�@�ӥ����: " << endl;
			cin >> n;
		}
		cout << "��X: " << endl;
		
		/* �H�U���D�n���e */
		int arr[3][15];
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = 0; // ��l�Ƭҳ]��0��ܨS���L 
		
		int i = 0; // �C 
		int j = 0; // �� 
		int num = 1; // �Ĥ@��O�@�� 
		
		arr[0][0] = num; // 1����[0][0] 
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr_temp[i][j] = 0;
		
		horse(i, j, num, n, arr);
		
		int zero = 0; // �P�_�O�_�������L�A�Y�����L�N���|��0�A�Y���S���L���N�|��0 
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				if (arr_temp[i][j] == 0)
					zero = 1;
		
		if (zero == 1) { // ���S���L�� 
			cout << "0" << endl;
		}
		else { // �����L 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < n; j++) {
					cout << arr_temp[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "Again? (Y/N) ";
		cin >> answer;
		cout << endl;
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
