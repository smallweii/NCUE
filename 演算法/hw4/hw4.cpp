#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int arr_temp[3][15] = {0}; // 每個元素皆為0 

void com(int n, int arr[][15]) { // 比較 
	if (arr_temp[0][0] == 0)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr_temp[i][j] = arr[i][j]; // 把第一次的arr_temp用arr取代 
	
	int tmp[3 * n], a[3 * n];
	int k = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			tmp[k] = arr_temp[i][j]; // 把3*n陣列存成一維陣列  
			a[k] = arr[i][j];
			k++;
		}
	}
	for (int i = 0; i < 3 * n; i++) { // 有找到更小的一次馬步 
		if ((tmp[i] != a[i]) && (a[i] < tmp[i])) { // 同格卻不同數字時，小的index的a陣列就取代tmp陣列 
			for (int j = 0; j < 3 * n; j++) {	
				tmp[j] = a[j];
			}
			break;
		}
		else if ((tmp[i] != a[i]) && (a[i] > tmp[i])) // 同格卻不同數字時，小的index的tmp陣列就還是tmp陣列 
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
	int go = 0; // 可走下一步 
	
	if ((i + 1 < 3) && (j + 2 < n) && (arr[i + 1][j + 2] == 0)) { // 下一格在範圍內且未走過 
		arr[i + 1][j + 2] = num + 1;
		horse(i + 1, j + 2, num + 1, n, arr);
		arr[i + 1][j + 2] = 0; // 跳出剛剛的遞迴後，把下一格歸零，再往下找if看有無其他路 
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
	
	if (num == 3 * n) // 走到最後一格了 
		com(n, arr);
}

int main() {
	char answer;
	
	do {
		int n; // 有n行 
		
		cout << "請輸入一個正整數: " << endl;
		cin >> n;
		while (n <= 0) {
			cout << "請輸入一個正整數: " << endl;
			cin >> n;
		}
		cout << "輸出: " << endl;
		
		/* 以下為主要內容 */
		int arr[3][15];
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = 0; // 初始化皆設為0表示沒走過 
		
		int i = 0; // 列 
		int j = 0; // 行 
		int num = 1; // 第一格是一號 
		
		arr[0][0] = num; // 1號放[0][0] 
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				arr_temp[i][j] = 0;
		
		horse(i, j, num, n, arr);
		
		int zero = 0; // 判斷是否有全走過，若全走過就不會有0，若有沒走過的就會有0 
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				if (arr_temp[i][j] == 0)
					zero = 1;
		
		if (zero == 1) { // 有沒走過的 
			cout << "0" << endl;
		}
		else { // 全走過 
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
