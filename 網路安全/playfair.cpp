#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	int choice;
	
	cout << "�w��ϥΡmPlayfair Cipher�n\n";
	cout << "1. �[�K\n2. �ѱK\n\n";
	cout << "�п�J�ﶵ: ";
	cin >> choice;
	cout << endl;
	
	if (choice == 1) { // �[�K 
		string key;
		bool repeat;
		
		do { // �ˮ�key 
			repeat = false;
			
			cout << "�п�Jkey: ";
			cin >> key;
			cout << endl;
			
			for (int i = 0; i < key.length(); i++) {
				if (islower(key[i])) // �Y���p�g 
					key[i] = toupper(key[i]); // �N��key��j�g 
				if (key[i] == 'J')
					key[i] = 'I'; // J�q�q�নI�Ӭ� 
			}
			for (int i = 0; i < key.length() - 1; i++) // �ˬdkey���r���O�_������ 
				for (int j = i + 1; j < key.length(); j++)
					if (key[i] == key[j])
						repeat = true;
						
			if (repeat == true)
				cout << "��Warning: key���r��������(I/J��P�r��)\n\n";
		} while (repeat == true); // key���r������ 
		
		char arr[5][5] = {""}; // �skey����� 
		int row = 0, col = 0;
		
		for (int i = 0; i < key.length(); i++) { // ��key��J�e����� 
			arr[row][col] = key[i];
			col++;
			if (col == 5) {
				row++;
				col = 0;
			}
		}
		for (int i = 0; i <= 25; i++) { // �᭱�̧Ƕ�J A:65 ��Z:90 
			bool letter = false;
			
			for (int j = 0; j < key.length(); j++) {
				if (i == 9) { // J:74
					letter = true;
					break;
				}
				if ((char)(65 + i) == key[j]) // ��L���N���A�� 
					letter = true; // ��L�F 
			}
			if (letter == false) {
				arr[row][col] = (char)(65 + i);
				col++;
				if (col == 5) {
					row++;
					col = 0;
				}
			}
		}
		string filename;
		
		cout << "�п�J���[�K���ɦW(XXX.txt): ";
		cin >> filename;
		cout << endl;
		ifstream fin(filename.c_str()); // Ū�ϥΪ̿�J���ɦW 
		
		if (!fin) { // �ˬd�ɮ׬O�_���\�}�ҡA�Y!fin���u�A�ɮ׫h�L�k�}�� 
			cout << "Can't open the file!" << endl;
			exit(1); // �b�����`���ΤU�A���_�{�������� 
		}
		char ch;
		string plain = "", plain2 = "";
		int n = 0;
		
		while (fin >> ch) {
			ch = toupper(ch);
			if (ch == 'J')
				ch = 'I'; // J�q�q�নI�Ӭ� 
			plain += ch;
			n++;
		}
		for (int i = 0; i < n; i += 2) {
			if (i == (plain.length() - 1)) { // �r�ꬰ�_�� 
				plain2 += plain[i];
				plain2 += 'X';
			}
			else if (plain[i] != plain[i + 1]) {
				plain2 += plain[i];
				plain2 += plain[i + 1];
			} else if (plain[i] == plain[i + 1]) {
				plain.insert(i + 1,"X"); // �q��i+1�Ӧ�m�}�l���J�r��"X"�A�ê�^�s���r�� 
				n = plain.length(); // n++
				plain2 += plain[i];
				plain2 += 'X';
			}
		}
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
		string cipher = "";
		
		for (int i = 0; i < plain2.length(); i += 2) { // ���@�զU��r,c�ȦA��� 
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (plain2[i] == arr[j][k]) {
						r1 = j;
						c1 = k;
					}
					if (plain2[i + 1] == arr[j][k]) {
						r2 = j;
						c2 = k;
					}
				}
			}
			if (r1 == r2) { // �P�C 
				cipher += arr[r1][(c1 + 1) % 5];
				cipher += arr[r1][(c2 + 1) % 5];
			} else if (c1 == c2) { // �P�� 
				cipher += arr[(r1 + 1) % 5][c1];
				cipher += arr[(r2 + 1) % 5][c1];
			} else if ((r1 != r2) && (c1 != c2)) { // ���P�C���P�� 
				cipher += arr[r1][c2];
				cipher += arr[r2][c1];
			}
		}
		fstream fout;
		
		fout.open("c1.txt", ios::out); //�b�g�J�Ҧ��U�}��c1.txt�� 
		fout << cipher << endl;
	} else if (choice == 2) { // �ѱK 
		string key;
		bool repeat;
		
		do { // �ˮ�key 
			repeat = false;
			
			cout << "�п�Jkey: ";
			cin >> key;
			cout << endl;
			
			for (int i = 0; i < key.length(); i++) {
				if (islower(key[i])) // �Y���p�g 
					key[i] = toupper(key[i]); // �N��key��j�g 
				if (key[i] == 'J')
					key[i] = 'I'; // J�q�q�নI�Ӭ� 
			}
			for (int i = 0; i < key.length() - 1; i++) // �ˬdkey���r���O�_������ 
				for (int j = i + 1; j < key.length(); j++)
					if (key[i] == key[j])
						repeat = true;
						
			if (repeat == true)
				cout << "��Warning: key���r��������(I/J��P�r��)\n\n";
		} while (repeat == true); // key���r������ 
		
		char arr[5][5] = {""}; // �skey����� 
		int row = 0, col = 0;
		
		for (int i = 0; i < key.length(); i++) { // ��key��J�e����� 
			arr[row][col] = key[i];
			col++;
			if (col == 5) {
				row++;
				col = 0;
			}
		}
		for (int i = 0; i <= 25; i++) { // �᭱�̧Ƕ�J A:65 ��Z:90 
			bool letter = false;
			
			for (int j = 0; j < key.length(); j++) {
				if (i == 9) { // J:74
					letter = true;
					break;
				}
				if ((char)(65 + i) == key[j]) // ��L���N���A�� 
					letter = true; // ��L�F 
			}
			if (letter == false) {
				arr[row][col] = (char)(65 + i);
				col++;
				if (col == 5) {
					row++;
					col = 0;
				}
			}
		}
		string filename;
		
		cout << "�п�J���ѱK���ɦW(XXX.txt): ";
		cin >> filename;
		cout << endl;
		ifstream fin(filename.c_str()); // Ū�ϥΪ̿�J���ɦW 
		
		if (!fin) { // �ˬd�ɮ׬O�_���\�}�ҡA�Y!fin���u�A�ɮ׫h�L�k�}�� 
			cout << "Can't open the file!" << endl;
			exit(1); // �b�����`���ΤU�A���_�{�������� 
		}
		char ch;
		string cipher = "", plain = "";
		
		while (fin >> ch) {
			ch = toupper(ch);
			if (ch == 'J')
				ch = 'I'; // J�q�q�নI�Ӭ� 
			cipher += ch;
		}
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0, n = 0;
		
		for (int i = 0; i < cipher.length(); i += 2) { // ���@�զU��r,c�ȦA��� 
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (cipher[i] == arr[j][k]) {
						r1 = j;
						c1 = k;
					}
					if (cipher[i + 1] == arr[j][k]) {
						r2 = j;
						c2 = k;
					}
				}
			}
			if (r1 == r2) { // �P�C 
				if (c1 == 0)
					c1 = 5;
				if (c2 == 0)
					c2 = 5;
				plain += arr[r1][(c1 - 1) % 5];
				plain += arr[r1][(c2 - 1) % 5];
			} else if (c1 == c2) { // �P�� 
				if (r1 == 0)
					r1 = 5;
				if (r2 == 0)
					r2 = 5;
				plain += arr[(r1 - 1) % 5][c1];
				plain += arr[(r2 - 1) % 5][c1];
			} else if ((r1 != r2) && (c1 != c2)) { // ���P�C���P�� 
				plain += arr[r1][c2];
				plain += arr[r2][c1];
			}
		}
		n = plain.length();
		for (int i = 0; i < n; i++) {
			if ((plain[i] == 'X') && (plain[i - 1] == plain[i + 1]) && (i % 2 == 1)) {
				plain.erase(i, 1); // �q��i�Ӧ�m�}�l�R��1�Ӧr��A�ê�^�s���r�� 
				n = plain.length(); // n--
			}
		}
		fstream fout;
		
		fout.open("p1.txt", ios::out); //�b�g�J�Ҧ��U�}��p1.txt�� 
		fout << plain << endl;
	}
	system("pause");
	return 0;
} 
