#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int num = 0, median, p;

int find_mid(int arr_mid[], int left, int right, int k) { // �䤤��� 
	int mid = (left + right) / 2;
	int arr_s1[4], arr_s2[4], arr_s3[4];
	int s1 = 0, s2 = 0, s3 = 0;
	
	for (int i = left; i <= right; i++) {
		if (arr_mid[i] < arr_mid[mid]) { 
			s1++; // ��arr_mid[mid]�p�����X�� 
			arr_s1[s1 - 1] = arr_mid[i];
		}
		else if (arr_mid[i] == arr_mid[mid]) {
			s2++; // ��arr_mid[mid]�@�˪����X�� 
			arr_s2[s2 - 1] = arr_mid[i];
			median = arr_mid[i];
		}
		else { // arr_mid[i] > arr_mid[mid]
			s3++; // ��arr_mid[mid]�j�����X�� 
			arr_s3[s3 - 1] = arr_mid[i];
		}
	}
	if (s1 >= k) // s1
		return median = find_mid(arr_s1, 0, s1 - 1, k);
	else if (s1 + s2 == k) // s2
		return median;
	else if (s1 + s2 < k) // s3
		return median = find_mid(arr_s3, 0, s3 - 1, k - (s1 + s2));
}

int find_p(int a[], int num, int k) { // ���k�p������ 
    int row = 0, column = 0, arr[5][600]; // �̦h3000�� 
    bool full; // �O�_��n�����L�l�� 
    
    for (int i = 0; i < num; i++) {
    	full = false;
		arr[row][column] = a[i];
		row++;
		if (row == 5) {
			row = 0;
			column++;
			full = true;
		}
	}
    if (full == false) {
    	for (int i = row; i < 5; i++) {
    		arr[i][column] = 1000; // �⤣�����ɵL���j�� 
		}
    	column++;
	}
	for (int i = 0; i < 5; i++) // �]�C�C 
		for (int j = 0; j < 5; j++) // bubble sort 
			for (int k = 0; k < 4; k++)
				if (arr[k][i] > arr[k + 1][i]) // �᭱���p�N���e�� 
					swap(arr[k][i], arr[k + 1][i]);
	
	if (column == 1) // �u���@�մN������X�ĴX�p 
		return arr[k - 1][0];
	
	int arr_mid[5];
	for (int i = 0; i < 5; i++)
		arr_mid[i] = arr[2][i];
	
	int left = 0; // 0
	int right = column - 1; // 4
	int mid = (left + right) / 2; // 2
	int index = -1;
	
	// �n���(column-1)/2+1�p���� ex:column=5,�n���3�p���� 
	//                            ex:column=6,�n���3�p���� 
	//                            ex:column=2,�n���1�p���� 
	median = find_mid(arr_mid, left, right, (column - 1) / 2 + 1);
	
	int arr_s1[3000], arr_s2[3000], arr_s3[3000];
	int s1 = 0, s2 = 0, s3 = 0;
	
	for (int i = 0; i < num; i++) {
		if (a[i] < median) {
			arr_s1[s1] = a[i];
			s1++;
		}
		else if (a[i] == median) {
			arr_s2[s2] = a[i];
			p = a[i];
			s2++;
		}
		else { // a[i] > median
			arr_s3[s3] = a[i];
			s3++;
		}
	}
	if (s1 >= k) // s1
		return p = find_p(arr_s1, s1, k);
	else if (s1 + s2 == k) // s2
		return p;
	else if (s1 + s2 < k) // s3
		return p = find_p(arr_s3, s3, k - (s1 + s2));
}

int main() {
	char answer;
	string name;
	
	cout << "�п�J�ɦW(.txt): ";
	cin >> name;
	name += ".txt";
	
	fstream file;
    file.open(name.c_str(), ios::in); // Ū�����A�U�}���ɮ� 
    
    if (!file) { // �ˬd�ɮ׬O�_���\�}�ҡA�Y !file���u�A�ɮ׫h�L�k�}�� 
        cout << "Can't open the file!" << endl;
        exit(1); // �b�����`���ΤU�A���_�{�������� 
    }
    int n, a[3000]; // �̦h3000�� 
    
    while (file >> n) {
		a[num] = n;
		num++;
	}
	do {
		int k; // �ĴX�p������ 
		
		cout << "�аݭn��ĴX�p������: ";
		cin >> k;
		while ((k <= 0) || (k > num)) {
			cout << "�аݭn��ĴX�p������: ";
			cin >> k;
		}
		cout << "�� " << k << " �p�������� " << find_p(a, num, k) << endl;
		cout << endl << "Again? (Y/N) ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
