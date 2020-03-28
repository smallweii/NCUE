#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int rank[2000] = {0}; // �����ܼ� 

void quicksort(float x[], float y[], int first, int last) {
	float split = x[first];
	int i = first + 1, j = last;
	
	while (i <= j) { // ����еL����A�i�~��� 
		while (x[i] < split && i <= last)
			i++;
		while (x[j] > split && j >= (first + 1))
			j--;
		
		if (i < j) { // ��� x[i]>split �H�� x[j]<split �n swap 
			swap(x[i], x[j]);
			swap(y[i], y[j]);
		}
	}
	
	swap(x[first], x[j]); // ���Х���n swap 
	swap(y[first], y[j]);
	
	if (first < (j - 1))
		quicksort(x, y, first, j - 1); // �k��ۻ��j 
	if ((j + 1) < last)
		quicksort(x, y, j + 1, last); // ����ۻ��j 
}

void merge(float x[], float y[], int first, int mid, int last) { // �X�� 
	int nl = mid - first + 1, nr = last - mid, r = 0, temp_r[last - first + 1];
	float left_x[nl], left_y[nl], right_x[nr], right_y[nr];
	
	for (int i = 0; i < nl; i++) {
		left_x[i] = x[i + first];
		left_y[i] = y[i + first];
	}
	for (int j = 0; j < nr; j++) {
		right_x[j] = x[j + mid + 1];
		right_y[j] = y[j + mid + 1];
	}
	
	int i = 0, j = 0, k = first, temp;
	
	while (i < nl && j < nr) {
		if (left_y[i] < right_y[j]) { // ���p 
			r++;
			temp_r[k - first] = rank[i + first];
			x[k] = left_x[i];
			y[k] = left_y[i];
			i++;
		}
		else { // �k�p 
			temp_r[k - first] = rank[j + mid + 1];
			temp_r[k - first] += r;
			x[k] = right_x[j];
			y[k] = right_y[j];
			j++;
		}
		k++;
	}
	
	while (i < nl) { // �u�ѥ��� 
		//r++;
		temp_r[k - first] = rank[i + first];
		x[k] = left_x[i];
		y[k] = left_y[i];
		i++;
		k++;
	}
	
	while (j < nr) { // �u�ѥk�� 
		temp_r[k - first] = rank[j + mid + 1];
		temp_r[k - first] += r;
		x[k] = right_x[j];
		y[k] = right_y[j];
		j++;
		k++;
	}
	
	for (int i = 0; i < last - first + 1; i++)
		rank[i + first] = temp_r[i];
}

void split(float x[], float y[], int first, int last) { // ���� 
	int mid = (first + last) / 2; // ����� 
	
	if (first < mid)
		split(x, y, first, mid); // ����ۻ��j 
	if ((mid + 1) < last)
		split(x, y, mid + 1, last); // �k��ۻ��j 
	
	merge(x, y, first, mid, last);
}

int max_rank(int n, int rank[]) { // ��̤j rank 
	int max = 0;
	
	for (int i = 0; i < n; i++)
		if (rank[i] > max)
			max = rank[i];
	return max;
}

int min_rank(int n, int rank[]) { // ��̤p rank 
	int min = 10000;
	
	for (int i = 0; i < n; i++)
		if (rank[i] < min)
			min = rank[i];
	return min;
}

float avg_rank(int n, int rank[]) { // �D���� rank 
	int sum = 0;
	float avg;
	
	for (int i = 0; i < n; i++)
		sum += rank[i];
	avg = (float)sum / (float)n;
	return avg;
}

int main() {
	float dot_x, dot_y, x[2000], y[2000];
	int n = 0, first, last;
	
	fstream file;
	file.open("test1.txt", ios::in); // Ū�����A�U�}���ɮ� 
	
	if (!file) { // �ˬd�ɮ׬O�_���\�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	
	while (file >> dot_x >> dot_y) { // Ū�������A�YŪ�����ɮ׵����h�^�� 0�F�Y���X while �j��h�A��Ū��  
		x[n] = dot_x; // �N�C�I�� x �M y �y�Цs�ܰ}�C 
		y[n] = dot_y;
		n++;
	}
	
	first = 0;
	last = n - 1;
	quicksort(x, y, first, last);
	split(x, y, first, last);
	
	for (int i = 0; i < n; i++)
		cout << x[i] << "\t" << y[i] << "\t�� rank = " << rank[i] << endl;
	cout << endl;
	cout << "�@�� " << n << " ���I" << endl << endl;
	cout << "�̤j rank = " << max_rank(n, rank) << endl;
	cout << "�̤p rank = " << min_rank(n, rank) << endl;
	cout << "���� rank = " << fixed <<  setprecision(2) << avg_rank(n, rank) << endl << endl; // ��p���I��ĤG�� 
	
	file.close();
	system("pause");
	return 0;
}
