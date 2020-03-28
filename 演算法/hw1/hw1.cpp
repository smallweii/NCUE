#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int rank[2000] = {0}; // 全域變數 

void quicksort(float x[], float y[], int first, int last) {
	float split = x[first];
	int i = first + 1, j = last;
	
	while (i <= j) { // 表指標無交錯，可繼續找 
		while (x[i] < split && i <= last)
			i++;
		while (x[j] > split && j >= (first + 1))
			j--;
		
		if (i < j) { // 找到 x[i]>split 以及 x[j]<split 要 swap 
			swap(x[i], x[j]);
			swap(y[i], y[j]);
		}
	}
	
	swap(x[first], x[j]); // 指標交錯要 swap 
	swap(y[first], y[j]);
	
	if (first < (j - 1))
		quicksort(x, y, first, j - 1); // 右邊自遞迴 
	if ((j + 1) < last)
		quicksort(x, y, j + 1, last); // 左邊自遞迴 
}

void merge(float x[], float y[], int first, int mid, int last) { // 合併 
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
		if (left_y[i] < right_y[j]) { // 左小 
			r++;
			temp_r[k - first] = rank[i + first];
			x[k] = left_x[i];
			y[k] = left_y[i];
			i++;
		}
		else { // 右小 
			temp_r[k - first] = rank[j + mid + 1];
			temp_r[k - first] += r;
			x[k] = right_x[j];
			y[k] = right_y[j];
			j++;
		}
		k++;
	}
	
	while (i < nl) { // 只剩左區 
		//r++;
		temp_r[k - first] = rank[i + first];
		x[k] = left_x[i];
		y[k] = left_y[i];
		i++;
		k++;
	}
	
	while (j < nr) { // 只剩右區 
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

void split(float x[], float y[], int first, int last) { // 分割 
	int mid = (first + last) / 2; // 中位數 
	
	if (first < mid)
		split(x, y, first, mid); // 左邊自遞迴 
	if ((mid + 1) < last)
		split(x, y, mid + 1, last); // 右邊自遞迴 
	
	merge(x, y, first, mid, last);
}

int max_rank(int n, int rank[]) { // 找最大 rank 
	int max = 0;
	
	for (int i = 0; i < n; i++)
		if (rank[i] > max)
			max = rank[i];
	return max;
}

int min_rank(int n, int rank[]) { // 找最小 rank 
	int min = 10000;
	
	for (int i = 0; i < n; i++)
		if (rank[i] < min)
			min = rank[i];
	return min;
}

float avg_rank(int n, int rank[]) { // 求平均 rank 
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
	file.open("test1.txt", ios::in); // 讀取狀態下開啟檔案 
	
	if (!file) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	
	while (file >> dot_x >> dot_y) { // 讀取紀錄，若讀取至檔案結尾則回傳 0；若跳出 while 迴圈則再次讀取  
		x[n] = dot_x; // 將每點的 x 和 y 座標存至陣列 
		y[n] = dot_y;
		n++;
	}
	
	first = 0;
	last = n - 1;
	quicksort(x, y, first, last);
	split(x, y, first, last);
	
	for (int i = 0; i < n; i++)
		cout << x[i] << "\t" << y[i] << "\t→ rank = " << rank[i] << endl;
	cout << endl;
	cout << "共有 " << n << " 個點" << endl << endl;
	cout << "最大 rank = " << max_rank(n, rank) << endl;
	cout << "最小 rank = " << min_rank(n, rank) << endl;
	cout << "平均 rank = " << fixed <<  setprecision(2) << avg_rank(n, rank) << endl << endl; // 到小數點後第二位 
	
	file.close();
	system("pause");
	return 0;
}
