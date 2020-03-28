#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<stack>
#define PI 3.1415926
using namespace std;

struct Node {
	float x;
	float y;
	int id;
	float angle;
};

int n = 0; // 檔案的點的個數 
bool exist[2000]; // 一開始為true，若被pop出去則為false，之後用此判斷node有無被刪掉 
stack<Node> S; // 開始連線放頂點的stack  
stack<int> I; // 開始連線放頂點在node的索引值的stack, 跟S同pop和push 
stack<Node> CCW; // 逆著放頂點的stack
int num_node; // 頂點總個數 

float GetAngle(float x1, float y1, float x2, float y2) { // 算角度 
	float x, y, angle;
	
	x = x2 - x1;
	y = y2 - y1;
	
	if (x == 0) // 同x 
		angle = 180.0 / 2; // 90度 
	else // 第一象限 
		angle = atan(fabs(y / x)) * 180.0 / PI; // fabs()為取絕對值，記得#include<cmath>及#define PI 3.1415926 
	
	if (x < 0 && y >= 0) // 第二象限 
		angle = 180.0 - angle;
	else if (x < 0 && y < 0) // 第三象限 
		angle = 180.0 + angle;
	else if (x > 0 && y <= 0) // 第四象限 
		angle = 2 * 180.0 - angle;
	
	return angle;
}

float GetDist(float x1, float y1, float x2, float y2) { // 算距離 
	float x, y, dist;
	
	x = x2 - x1;
	y = y2 - y1;
	dist = x * x + y * y;
	
	return sqrt(dist); // 開根號 
}

int orientation(Node a, Node b, Node c) { // 算cross方向 
	float cross;
	
	cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	
	if (cross == 0) // 三點共線 
		return 0;
	else if (cross < 0) // 順時針: 內角 > 180度 
		return 1;
	else // if (value > 0) 逆時針: 內角 < 180度 
		return 2;
}

Node next_node(stack<Node> &S) { // 找top的前一個，記得#include<stack> 
	Node c = S.top(); // 目前top為c 
	S.pop(); // 剩a,b 
	Node b = S.top(); // 目前top為b
	S.push(c); // 剩a,b,c 
	
	return b;
}

Node nnext_node(stack<Node> &S) { // 找top的前兩個，記得#include<stack> 
	Node c = S.top(); // 目前top為c 
	S.pop(); // 剩a,b 
	Node b = S.top(); // 目前top為b  
	S.pop(); // 剩a 
	Node a = S.top(); // 目前top為a  
	
	S.push(b); // 目前有a,b 
	S.push(c); // 目前有a,b,c 
	
	return a;
}

int next_idx(stack<int> &I) { // 找top的前一個，記得#include<stack> 
	int c = I.top(); // 目前top為c 
	I.pop(); // 剩a,b 
	int b = I.top(); // 目前top為b
	I.push(c); // 剩a,b,c 
	
	return b;
}

int nnext_idx(stack<int> &I) { // 找top的前兩個，記得#include<stack> 
	int c = I.top(); // 目前top為c 
	I.pop(); // 剩a,b 
	int b = I.top(); // 目前top為b  
	I.pop(); // 剩a 
	int a = I.top(); // 目前top為a  
	
	I.push(b); // 目前有a,b 
	I.push(c); // 目前有a,b,c 
	
	return a;
}

void quicksort(Node *node, int first, int last) {
	float split = node[first].x;
	int i = first + 1, j = last;
	
	while (i <= j) { // 表指標無交錯，可繼續找 
		while (node[i].x <= split && i <= last)
			i++;
		while (node[j].x >= split && j >= (first + 1))
			j--;
		
		if (i < j) { // 找到node[i].x>split以及node[j].x<split要swap 
			swap(node[i].x, node[j].x);
			swap(node[i].y, node[j].y);
			swap(node[i].id, node[j].id);
		}
	}
	
	swap(node[first].x, node[j].x); // 指標交錯要swap 
	swap(node[first].y, node[j].y);
	swap(node[first].id, node[j].id);
	
	if (first < (j - 1))
		quicksort(node, first, j - 1); // 右邊自遞迴 
	if ((j + 1) < last)
		quicksort(node, j + 1, last); // 左邊自遞迴 
}

void check_quick(Node *node, int first, int last) { // x相同時，y小的排在前面 
	for (int i = first; i < last; i++)
		for (int j = i + 1; j < last + 1; j++)
			if (node[i].x == node[j].x && node[i].y > node[j].y) // x相同時,y小的要排前面 
				swap(node[i], node[j]);
}

void merge(Node *node, int first, int last) { // 合併 
	int min_y = node[first].y; // 一開始第一個點當最左下角的點 
	int left_down = first; // 最左下角的點 
	
	for (int i = first + 1; i < last + 1; i++) { // 找最左下角的點當起始點 
		if (node[i].y < min_y) { // 比y誰小 
			min_y = node[i].y;
			left_down = i;
		}
		else if (node[i].y == min_y) // y一樣就比x誰小 
			if (node[i].x < node[left_down].x)
				left_down = i;
	}
	swap(node[first], node[left_down]); // 最左下角的點跟第一個點交換 
	
	node[first].angle = 0.0;
	
	for (int i = first + 1; i < last + 1; i++) // 算剩下的每點與最左下角的點構成的角度與距離 
		if (exist[i] == true)
			node[i].angle = GetAngle(node[first].x, node[first].y, node[i].x, node[i].y);
	
	for (int i = first; i < last + 1; i++) { // 角度由小排到大
		float min = 360.0;
		int k;
		
		if (exist[i] == true) {
			for (int j = i; j < last + 1; j++){
				if (exist[j] == true) {	
					if (node[j].angle < min) {
						min = node[j].angle;
						k = j;
					}
				}
			}
			swap(node[i], node[k]);
		}
	}
	for (int i = first + 1; i < last; i++)
		if (exist[i] == true)
			for (int j = i + 1; j < last + 1; j++)
				if (exist[j] == true) // 角度相同時，距離小的排前面 
					if (node[i].angle == node[j].angle && GetDist(node[first].x, node[first].y, node[i].x, node[i].y) > GetDist(node[first].x, node[first].y, node[j].x, node[j].y))
						swap(node[i], node[j]);
	
	for (int i = first + 1; i < last + 1; i++) {
		while (i + 1 < last + 1 && orientation(node[first], node[i], node[i + 1]) == 0) { // 角度相同時，距離大的留著 
			exist[i] = false;
			i++;
		}
	}
	int many = 0; // 判斷是不是加了前三點了 
	
	for (int i = first; i < last + 1; i++) { // 先加入前兩點 
		if (many == 2)
			break;
		
		if (exist[i] == true) { // 已為頂點 
			if (exist[i] == true) {
				S.push(node[i]);
				I.push(i);
				many++;
			}
		}
	}
	for (int i = I.top() + 1; i < last + 1; i++) {
		if (exist[i] == true) {
			while (S.size() >= 2 && (orientation(next_node(S), S.top(), node[i]) == 1)) { // b,c,node[i]且stack為a,b,c 
				exist[I.top()] = false;
				S.pop(); // 順時針就踢出去 
				I.pop();
			}
			S.push(node[i]);
			I.push(i);
			
			// 角度不同但共線時，中間的點要刪掉 
			if (orientation(nnext_node(S), next_node(S), node[i]) == 0) { // b,c,node[i]且stack為(a,)b,c,node[i] 
				exist[next_idx(I)] = false; // c
				S.pop(); // node[i]
				I.pop();
				S.pop(); // c
				I.pop();
				S.push(node[i]); // stack為a,b,node[i] 
				I.push(i);
			}
		}
	}
	num_node = S.size();
	
	for (int i = 0; i < num_node; i++) {
		CCW.push(S.top());
		S.pop();
	}   //         全部               ||            左邊                     ||                            右邊 
	if ((first == 0 && last == n - 1) || (first == 0 && last == (n - 1) / 2) || (first == ((n - 1) / 2 + 1) && last == n - 1)) {
		if (first == 0 && last == (n - 1) / 2)
			cout << "左邊的Convex hull:" << endl;
		else if (first == ((n - 1) / 2 + 1) && last == n - 1)
			cout << "右邊的Convex hull:" << endl;
		else
			cout << "最後的Convex hull:" << endl;
		
		Node arr[CCW.size()];
		int ccw_size = CCW.size(), j = 0;
		
		while(!CCW.empty()) {
			Node top = CCW.top();
			arr[j] = top;
			j++;
			CCW.pop();
		}
		int min = 1000, min_x;
		
		for (int i = 0; i < ccw_size; i++) {
			if (arr[i].x < min) {
				min = arr[i].x;
				min_x = i;
			}
		}
		for (int i = min_x; i < ccw_size; i++)
			cout << arr[i].id << ". (" << arr[i].x << ", " << arr[i].y << ")" << endl;
		for (int i = 0; i < min_x; i++)
			cout << arr[i].id << ". (" << arr[i].x << ", " << arr[i].y << ")" << endl;
		cout << "共有 " << num_node << " 個頂點" << endl << endl;
	}
	while(!CCW.empty())
		CCW.pop();
}

void split(Node *node, int first, int last) { // 分割 
	int mid = (first + last) / 2; // 中位數  
	
	if (first + 0 >= last || first + 1 >= last) // 終止條件: 全部剩1或2個點就不用再切了 
		return;
	if (first < mid)
		split(node, first, mid); // 左邊自遞迴 
	if ((mid + 1) < last)
		split(node, mid + 1, last); // 右邊自遞迴 
	
	merge(node, first, last);
}

int main() {
	float dot_x, dot_y;
	int first, last;
	
	fstream file;
	file.open("test1.txt", ios::in); // 讀取狀態下開啟檔案 
	
	if (!file) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	
	Node *node; // 結構指標指到動態記憶體配置的位置 
	node = new Node[2000]; // 新要的空間，代表動態記憶體配置 
	
	if (!node) { //沒要到空間，代表記憶體配置失敗 
		cout << "Memory allocation error!" << endl;
		exit(1);
	}
	
	while (file >> dot_x >> dot_y) { // 讀取紀錄，若讀取至檔案結尾則回傳0；若跳出while迴圈則再次讀取  
		node[n].x = dot_x; // 將每點的x和y座標存至陣列 
		node[n].y = dot_y;
		node[n].id = n + 1; // 自行給頂點編號1~n 
		n++;
	}
	
	for (int i = 0; i <= 2000; i++)
	    exist[i] = true;
	
	first = 0;
	last = n - 1;
	
	quicksort(node, first, last);
	check_quick(node, first, last);
	split(node, first, last);
	
	file.close();
	system("pause");
	return 0;
}
