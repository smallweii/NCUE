#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int n; // ��¡�ܼ� 

int minCost(bool visit[], float cost[]) {
	int min_cost = 1000;
	int next_v; // �U�@�ӭn�Q���X���I��index 
		
	for (int i = 0; i < n; i++) { // �]cost[] 
		if (visit[i] == false && cost[i] < min_cost) { // �٨S�Q���X�L & ��cost[]�̥ثe�̤p�� 
			min_cost = cost[i];
			next_v = i;
		}
	}
	return next_v;
}

int minDist(bool add[], float dist[]) {
	int min_dist = 1000;
	int next_v; // �U�@�ӭn�Q�[�i�Ӫ��I��index 
		
	for (int i = 0; i < n; i++) { // �]dist[] 
		if (add[i] == false && dist[i] < min_dist) { // �٨S�Q�[�i�� & ��dist[]�̥ثe�̤p�� 
			min_dist = dist[i];
			next_v = i;
		}
	}
	return next_v;
}

string int2str(int i) { // int��string�禡 
	string s;
	stringstream ss(s);
	ss << i; //��int�ܼƼg�J��stringstream
	
	return ss.str();
}

int main() {
	int v1, v2;
	float w, tree[50][50] = {0};
	
	ifstream file_in;
	ofstream file_out;
	
	file_in.open("t2.txt", ios::in); // Ū�����A�U�}���ɮ� 
	file_out.open("t2_out.txt", ios::out); // �g�J���A�U�}���ɮ� 
	
	if (!file_in) { // �ˬd�ɮ׬O�_���\�}�� 
		cout << "Can't open the file!" << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
	
	if (file_in >> n) {
		while (file_in >> v1 >> v2 >> w) { // Ū�������A�YŪ�����ɮ׵����h�^��0�F�Y���Xwhile�j��h�A��Ū��  
			if (v1 == v2) {
				cout << "��ĵ�i " << v1 << " " << v2 << " " << w << " : ����ۤv�s��ۤv" << endl;
				file_out << "��ĵ�i " << v1 << " " << v2 << " " << w << " : ����ۤv�s��ۤv" << endl;
			}
			else if (w != tree[v1 - 1][v2 - 1] && tree[v1 - 1][v2 - 1] != 0) {
				tree[v1 - 1][v2 - 1] = w; // �H��̻\�h�e��
				tree[v2 - 1][v1 - 1] = w;
				cout << "��ĵ�i " << v1 << " " << v2 << " " << w << " : ���V�v������" << endl;
				file_out << "��ĵ�i " << v1 << " " << v2 << " " << w << " : ���V�v������" << endl;
			}
			else if (v1 > n) {
				cout << "��ĵ�i " << v1 << " " << v2 << " " << w << " : node " << v1 << " ���s�b" << endl;
				file_out << "��ĵ�i " << v1 << " " << v2 << " " << w << " : node " << v1 << " ���s�b" << endl;
			}
			else if (v2 > n) {
				cout << "��ĵ�i " << v1 << " " << v2 << " " << w << " : node " << v2 << " ���s�b" << endl;
				file_out << "��ĵ�i " << v1 << " " << v2 << " " << w << " : node " << v2 << " ���s�b" << endl;
			}
			else if (w <= 0) {
				cout << "��ĵ�i " << v1 << " " << v2 << " " << w << " : �v�����ର0�έt��" << endl;
				file_out << "��ĵ�i " << v1 << " " << v2 << " " << w << " : �v�����ର0�έt��" << endl;
			}
			else {
				tree[v1 - 1][v2 - 1] = w;
				tree[v2 - 1][v1 - 1] = w;
			}
		}	
	}
	// Prim Algorithm ------------------------------------------------------------------------------------------------
	cout << "(1)MST����" << endl;
	file_out << "(1)MST����" << endl;
	
	int pre_v[n]; // �e�@���I�O�� 
	bool visit[n]; // �O�_�����X�L 
	float cost[n]; // ���Ӹ�ۤv�H�e���L�����v���A�p�̧�s�����A���L�H���v���A�p�̴N�s�� 
	
	for (int i = 0; i < n; i++) { // �����X����@�I����l�� 
		visit[i] = false;
		cost[i] = 1000;
	}
	
	pre_v[0] = -1; // �Ĥ@���I��root
	cost[0] = 0;
	
	for (int i = 0; i < n; i++) {
		int v = minCost(visit, cost); // �U�@�ӭn�Q���X���I��index 
		
		visit[v] = true;
		
		for (int j = 0; j < n ; j++) { // �P�e�@�ӳQ���X�L���I���۾F & ���Q���X�L & �����H�e���p
			if (tree[v][j] != 0 && visit[j] == false && tree[v][j] < cost[j]) { 
				cost[j] = tree[v][j]; // ��s�ۤv��cost 
				pre_v[j] = v; // �O���ۤv�e�@�ӬO�� 
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
		
	cout << endl << "   MST���v���M : " << sum << endl;
	file_out << endl << "   MST���v���M : " << sum << endl;
	// Dijkstra Algorithm ------------------------------------------------------------------------------------------------
	cout << endl << "(2)�̵u���|�P�Z��" << endl << endl;
	file_out << endl << "(2)�̵u���|�P�Z��" << endl << endl;
	
	bool add[n]; // �I�Q�[�i�h�F�S 
	float dist[n]; // �Ĥ@���I��ۤv���̵u���|�Z�� 
	
	stringstream ss;
	string by_v[n]; // �O���ۤv���z�L�� 
	string str_v; // �I�qint��string 
	
	for (int i = 0; i < n; i++) { // ���[�i����@�I����l�� 
		add[i] = false;
		dist[i] = 1000;
	}
	
	dist[0] = 0; // �Ĥ@���I���X�o�I 
	by_v[0] = -1;
	
	for (int i = 0; i < n; i++) {
		int v = minDist(add, dist); // �U�@�ӭn�Q�[�i�Ӫ��I��index 
		
		add[v] = true;
		
		for (int j = 0; j < n; j++) { // �P��Q�[�i�Ӫ��I���۾F & ���Q�[�i�� & �s���|��H�e���u 
			if (tree[v][j] != 0 && add[j] == false && dist[v] + tree[v][j] < dist[j]) {
				dist[j] = dist[v] + tree[v][j]; // ��s�ۤv��dist 
				
				str_v = int2str(v + 1); // int��string�禡 
				by_v[j] = by_v[v] + str_v; // �O����s�ۤv�쩳�O�z�L�� 
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		cout << "   " << add[0] << " �� " << i + 1 << " ���| : " ;
		file_out << "   " << add[0] << " �� " << i + 1 << " ���| : " ;
		
		cout << add[0] << " �� ";
		file_out << add[0] << " �� ";
		
		for (int j = 2; j < by_v[i].length(); j++) {
			cout << by_v[i].at(j) << " " << by_v[i].at(j) << " �� ";
			file_out << by_v[i].at(j) << " " << by_v[i].at(j) << " �� ";
		}
		cout << i + 1;
		file_out << i + 1;
		
		cout << " �Z�� : " << dist[i] << endl;
		file_out << " �Z�� : " << dist[i] << endl;
	}
	
	cout << endl;
	file_out << endl;
	
	file_in.close();
	file_out.close();
	
	system("pause");
	return 0;
}
