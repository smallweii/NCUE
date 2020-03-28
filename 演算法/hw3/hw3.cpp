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

int n = 0; // �ɮת��I���Ӽ� 
bool exist[2000]; // �@�}�l��true�A�Y�Qpop�X�h�h��false�A����Φ��P�_node���L�Q�R�� 
stack<Node> S; // �}�l�s�u���I��stack  
stack<int> I; // �}�l�s�u���I�bnode�����ޭȪ�stack, ��S�Ppop�Mpush 
stack<Node> CCW; // �f�۩��I��stack
int num_node; // ���I�`�Ӽ� 

float GetAngle(float x1, float y1, float x2, float y2) { // �⨤�� 
	float x, y, angle;
	
	x = x2 - x1;
	y = y2 - y1;
	
	if (x == 0) // �Px 
		angle = 180.0 / 2; // 90�� 
	else // �Ĥ@�H�� 
		angle = atan(fabs(y / x)) * 180.0 / PI; // fabs()��������ȡA�O�o#include<cmath>��#define PI 3.1415926 
	
	if (x < 0 && y >= 0) // �ĤG�H�� 
		angle = 180.0 - angle;
	else if (x < 0 && y < 0) // �ĤT�H�� 
		angle = 180.0 + angle;
	else if (x > 0 && y <= 0) // �ĥ|�H�� 
		angle = 2 * 180.0 - angle;
	
	return angle;
}

float GetDist(float x1, float y1, float x2, float y2) { // ��Z�� 
	float x, y, dist;
	
	x = x2 - x1;
	y = y2 - y1;
	dist = x * x + y * y;
	
	return sqrt(dist); // �}�ڸ� 
}

int orientation(Node a, Node b, Node c) { // ��cross��V 
	float cross;
	
	cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	
	if (cross == 0) // �T�I�@�u 
		return 0;
	else if (cross < 0) // ���ɰw: ���� > 180�� 
		return 1;
	else // if (value > 0) �f�ɰw: ���� < 180�� 
		return 2;
}

Node next_node(stack<Node> &S) { // ��top���e�@�ӡA�O�o#include<stack> 
	Node c = S.top(); // �ثetop��c 
	S.pop(); // ��a,b 
	Node b = S.top(); // �ثetop��b
	S.push(c); // ��a,b,c 
	
	return b;
}

Node nnext_node(stack<Node> &S) { // ��top���e��ӡA�O�o#include<stack> 
	Node c = S.top(); // �ثetop��c 
	S.pop(); // ��a,b 
	Node b = S.top(); // �ثetop��b  
	S.pop(); // ��a 
	Node a = S.top(); // �ثetop��a  
	
	S.push(b); // �ثe��a,b 
	S.push(c); // �ثe��a,b,c 
	
	return a;
}

int next_idx(stack<int> &I) { // ��top���e�@�ӡA�O�o#include<stack> 
	int c = I.top(); // �ثetop��c 
	I.pop(); // ��a,b 
	int b = I.top(); // �ثetop��b
	I.push(c); // ��a,b,c 
	
	return b;
}

int nnext_idx(stack<int> &I) { // ��top���e��ӡA�O�o#include<stack> 
	int c = I.top(); // �ثetop��c 
	I.pop(); // ��a,b 
	int b = I.top(); // �ثetop��b  
	I.pop(); // ��a 
	int a = I.top(); // �ثetop��a  
	
	I.push(b); // �ثe��a,b 
	I.push(c); // �ثe��a,b,c 
	
	return a;
}

void quicksort(Node *node, int first, int last) {
	float split = node[first].x;
	int i = first + 1, j = last;
	
	while (i <= j) { // ����еL����A�i�~��� 
		while (node[i].x <= split && i <= last)
			i++;
		while (node[j].x >= split && j >= (first + 1))
			j--;
		
		if (i < j) { // ���node[i].x>split�H��node[j].x<split�nswap 
			swap(node[i].x, node[j].x);
			swap(node[i].y, node[j].y);
			swap(node[i].id, node[j].id);
		}
	}
	
	swap(node[first].x, node[j].x); // ���Х���nswap 
	swap(node[first].y, node[j].y);
	swap(node[first].id, node[j].id);
	
	if (first < (j - 1))
		quicksort(node, first, j - 1); // �k��ۻ��j 
	if ((j + 1) < last)
		quicksort(node, j + 1, last); // ����ۻ��j 
}

void check_quick(Node *node, int first, int last) { // x�ۦP�ɡAy�p���Ʀb�e�� 
	for (int i = first; i < last; i++)
		for (int j = i + 1; j < last + 1; j++)
			if (node[i].x == node[j].x && node[i].y > node[j].y) // x�ۦP��,y�p���n�ƫe�� 
				swap(node[i], node[j]);
}

void merge(Node *node, int first, int last) { // �X�� 
	int min_y = node[first].y; // �@�}�l�Ĥ@���I��̥��U�����I 
	int left_down = first; // �̥��U�����I 
	
	for (int i = first + 1; i < last + 1; i++) { // ��̥��U�����I��_�l�I 
		if (node[i].y < min_y) { // ��y�֤p 
			min_y = node[i].y;
			left_down = i;
		}
		else if (node[i].y == min_y) // y�@�˴N��x�֤p 
			if (node[i].x < node[left_down].x)
				left_down = i;
	}
	swap(node[first], node[left_down]); // �̥��U�����I��Ĥ@���I�洫 
	
	node[first].angle = 0.0;
	
	for (int i = first + 1; i < last + 1; i++) // ��ѤU���C�I�P�̥��U�����I�c�������׻P�Z�� 
		if (exist[i] == true)
			node[i].angle = GetAngle(node[first].x, node[first].y, node[i].x, node[i].y);
	
	for (int i = first; i < last + 1; i++) { // ���ץѤp�ƨ�j
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
				if (exist[j] == true) // ���׬ۦP�ɡA�Z���p���ƫe�� 
					if (node[i].angle == node[j].angle && GetDist(node[first].x, node[first].y, node[i].x, node[i].y) > GetDist(node[first].x, node[first].y, node[j].x, node[j].y))
						swap(node[i], node[j]);
	
	for (int i = first + 1; i < last + 1; i++) {
		while (i + 1 < last + 1 && orientation(node[first], node[i], node[i + 1]) == 0) { // ���׬ۦP�ɡA�Z���j���d�� 
			exist[i] = false;
			i++;
		}
	}
	int many = 0; // �P�_�O���O�[�F�e�T�I�F 
	
	for (int i = first; i < last + 1; i++) { // ���[�J�e���I 
		if (many == 2)
			break;
		
		if (exist[i] == true) { // �w�����I 
			if (exist[i] == true) {
				S.push(node[i]);
				I.push(i);
				many++;
			}
		}
	}
	for (int i = I.top() + 1; i < last + 1; i++) {
		if (exist[i] == true) {
			while (S.size() >= 2 && (orientation(next_node(S), S.top(), node[i]) == 1)) { // b,c,node[i]�Bstack��a,b,c 
				exist[I.top()] = false;
				S.pop(); // ���ɰw�N��X�h 
				I.pop();
			}
			S.push(node[i]);
			I.push(i);
			
			// ���פ��P���@�u�ɡA�������I�n�R�� 
			if (orientation(nnext_node(S), next_node(S), node[i]) == 0) { // b,c,node[i]�Bstack��(a,)b,c,node[i] 
				exist[next_idx(I)] = false; // c
				S.pop(); // node[i]
				I.pop();
				S.pop(); // c
				I.pop();
				S.push(node[i]); // stack��a,b,node[i] 
				I.push(i);
			}
		}
	}
	num_node = S.size();
	
	for (int i = 0; i < num_node; i++) {
		CCW.push(S.top());
		S.pop();
	}   //         ����               ||            ����                     ||                            �k�� 
	if ((first == 0 && last == n - 1) || (first == 0 && last == (n - 1) / 2) || (first == ((n - 1) / 2 + 1) && last == n - 1)) {
		if (first == 0 && last == (n - 1) / 2)
			cout << "���䪺Convex hull:" << endl;
		else if (first == ((n - 1) / 2 + 1) && last == n - 1)
			cout << "�k�䪺Convex hull:" << endl;
		else
			cout << "�̫᪺Convex hull:" << endl;
		
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
		cout << "�@�� " << num_node << " �ӳ��I" << endl << endl;
	}
	while(!CCW.empty())
		CCW.pop();
}

void split(Node *node, int first, int last) { // ���� 
	int mid = (first + last) / 2; // �����  
	
	if (first + 0 >= last || first + 1 >= last) // �פ����: ������1��2���I�N���ΦA���F 
		return;
	if (first < mid)
		split(node, first, mid); // ����ۻ��j 
	if ((mid + 1) < last)
		split(node, mid + 1, last); // �k��ۻ��j 
	
	merge(node, first, last);
}

int main() {
	float dot_x, dot_y;
	int first, last;
	
	fstream file;
	file.open("test1.txt", ios::in); // Ū�����A�U�}���ɮ� 
	
	if (!file) { // �ˬd�ɮ׬O�_���\�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	
	Node *node; // ���c���Ы���ʺA�O����t�m����m 
	node = new Node[2000]; // �s�n���Ŷ��A�N��ʺA�O����t�m 
	
	if (!node) { //�S�n��Ŷ��A�N��O����t�m���� 
		cout << "Memory allocation error!" << endl;
		exit(1);
	}
	
	while (file >> dot_x >> dot_y) { // Ū�������A�YŪ�����ɮ׵����h�^��0�F�Y���Xwhile�j��h�A��Ū��  
		node[n].x = dot_x; // �N�C�I��x�My�y�Цs�ܰ}�C 
		node[n].y = dot_y;
		node[n].id = n + 1; // �ۦ浹���I�s��1~n 
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
