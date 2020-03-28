#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int n; // 痊癒變數 

int minCost(bool visit[], float cost[]) {
	int min_cost = 1000;
	int next_v; // 下一個要被拜訪的點的index 
		
	for (int i = 0; i < n; i++) { // 跑cost[] 
		if (visit[i] == false && cost[i] < min_cost) { // 還沒被拜訪過 & 找cost[]裡目前最小的 
			min_cost = cost[i];
			next_v = i;
		}
	}
	return next_v;
}

int minDist(bool add[], float dist[]) {
	int min_dist = 1000;
	int next_v; // 下一個要被加進來的點的index 
		
	for (int i = 0; i < n; i++) { // 跑dist[] 
		if (add[i] == false && dist[i] < min_dist) { // 還沒被加進來 & 找dist[]裡目前最小的 
			min_dist = dist[i];
			next_v = i;
		}
	}
	return next_v;
}

string int2str(int i) { // int轉string函式 
	string s;
	stringstream ss(s);
	ss << i; //把int變數寫入到stringstream
	
	return ss.str();
}

int main() {
	int v1, v2;
	float w, tree[50][50] = {0};
	
	ifstream file_in;
	ofstream file_out;
	
	file_in.open("t2.txt", ios::in); // 讀取狀態下開啟檔案 
	file_out.open("t2_out.txt", ios::out); // 寫入狀態下開啟檔案 
	
	if (!file_in) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	
	if (file_in >> n) {
		while (file_in >> v1 >> v2 >> w) { // 讀取紀錄，若讀取至檔案結尾則回傳0；若跳出while迴圈則再次讀取  
			if (v1 == v2) {
				cout << "※警告 " << v1 << " " << v2 << " " << w << " : 不能自己連到自己" << endl;
				file_out << "※警告 " << v1 << " " << v2 << " " << w << " : 不能自己連到自己" << endl;
			}
			else if (w != tree[v1 - 1][v2 - 1] && tree[v1 - 1][v2 - 1] != 0) {
				tree[v1 - 1][v2 - 1] = w; // 以後者蓋去前者
				tree[v2 - 1][v1 - 1] = w;
				cout << "※警告 " << v1 << " " << v2 << " " << w << " : 雙向權重不符" << endl;
				file_out << "※警告 " << v1 << " " << v2 << " " << w << " : 雙向權重不符" << endl;
			}
			else if (v1 > n) {
				cout << "※警告 " << v1 << " " << v2 << " " << w << " : node " << v1 << " 不存在" << endl;
				file_out << "※警告 " << v1 << " " << v2 << " " << w << " : node " << v1 << " 不存在" << endl;
			}
			else if (v2 > n) {
				cout << "※警告 " << v1 << " " << v2 << " " << w << " : node " << v2 << " 不存在" << endl;
				file_out << "※警告 " << v1 << " " << v2 << " " << w << " : node " << v2 << " 不存在" << endl;
			}
			else if (w <= 0) {
				cout << "※警告 " << v1 << " " << v2 << " " << w << " : 權重不能為0或負數" << endl;
				file_out << "※警告 " << v1 << " " << v2 << " " << w << " : 權重不能為0或負數" << endl;
			}
			else {
				tree[v1 - 1][v2 - 1] = w;
				tree[v2 - 1][v1 - 1] = w;
			}
		}	
	}
	// Prim Algorithm ------------------------------------------------------------------------------------------------
	cout << "(1)MST的邊" << endl;
	file_out << "(1)MST的邊" << endl;
	
	int pre_v[n]; // 前一個點是誰 
	bool visit[n]; // 是否有拜訪過 
	float cost[n]; // 拿來跟自己以前走過的比權重，小者更新紀錄再跟其他人比權重，小者就連邊 
	
	for (int i = 0; i < n; i++) { // 未拜訪任何一點的初始化 
		visit[i] = false;
		cost[i] = 1000;
	}
	
	pre_v[0] = -1; // 第一個點當root
	cost[0] = 0;
	
	for (int i = 0; i < n; i++) {
		int v = minCost(visit, cost); // 下一個要被拜訪的點的index 
		
		visit[v] = true;
		
		for (int j = 0; j < n ; j++) { // 與前一個被拜訪過的點有相鄰 & 未被拜訪過 & 此邊比以前的小
			if (tree[v][j] != 0 && visit[j] == false && tree[v][j] < cost[j]) { 
				cost[j] = tree[v][j]; // 更新自己的cost 
				pre_v[j] = v; // 記錄自己前一個是誰 
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		cout << "   " << pre_v[i] + 1 << " - " << i + 1 << " : " << tree[pre_v[i]][i] << endl;
		file_out << "   " << pre_v[i] + 1 << " - " << i + 1 << " : " << tree[pre_v[i]][i] << endl;
	}
	
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += cost[i];
		
	cout << endl << "   MST的權重和 : " << sum << endl;
	file_out << endl << "   MST的權重和 : " << sum << endl;
	// Dijkstra Algorithm ------------------------------------------------------------------------------------------------
	cout << endl << "(2)最短路徑與距離" << endl << endl;
	file_out << endl << "(2)最短路徑與距離" << endl << endl;
	
	bool add[n]; // 點被加進去了沒 
	float dist[n]; // 第一個點到自己的最短路徑距離 
	
	stringstream ss;
	string by_v[n]; // 記錄自己有透過誰 
	string str_v; // 點從int轉string 
	
	for (int i = 0; i < n; i++) { // 未加進任何一點的初始化 
		add[i] = false;
		dist[i] = 1000;
	}
	
	dist[0] = 0; // 第一個點為出發點 
	by_v[0] = -1;
	
	for (int i = 0; i < n; i++) {
		int v = minDist(add, dist); // 下一個要被加進來的點的index 
		
		add[v] = true;
		
		for (int j = 0; j < n; j++) { // 與剛被加進來的點有相鄰 & 未被加進來 & 新路徑比以前的短 
			if (tree[v][j] != 0 && add[j] == false && dist[v] + tree[v][j] < dist[j]) {
				dist[j] = dist[v] + tree[v][j]; // 更新自己的dist 
				
				str_v = int2str(v + 1); // int轉string函式 
				by_v[j] = by_v[v] + str_v; // 記錄更新自己到底是透過誰 
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		cout << "   " << add[0] << " → " << i + 1 << " 路徑 : " ;
		file_out << "   " << add[0] << " → " << i + 1 << " 路徑 : " ;
		
		cout << add[0] << " → ";
		file_out << add[0] << " → ";
		
		for (int j = 2; j < by_v[i].length(); j++) {
			cout << by_v[i].at(j) << " " << by_v[i].at(j) << " → ";
			file_out << by_v[i].at(j) << " " << by_v[i].at(j) << " → ";
		}
		cout << i + 1;
		file_out << i + 1;
		
		cout << " 距離 : " << dist[i] << endl;
		file_out << " 距離 : " << dist[i] << endl;
	}
	
	cout << endl;
	file_out << endl;
	
	file_in.close();
	file_out.close();
	
	system("pause");
	return 0;
}
