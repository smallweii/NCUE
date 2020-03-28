#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<cstdlib>
using namespace std;

bool isPrime(long long int p) { // �P�_�O�_����� 
	int k = 0;
	
	for (int i = 2; i < p; i++) {
		if (p % i == 0) {
			k = 0;
			break;
		} else
			k = 1;
	}
	if (k == 0) return false;
	else        return true;
}

int gcd(long long int s, long long int n) { // ��̤j���]�� 
	if (s > n) {
		int temp = n;
		n = s;
		s = temp;
	}
	while (s != 0) { // ����۰��k 
		int m = n % s;
		n = s;
		s = m;
	}
	return n;
}

string Int_to_String(long long int n) { // �����r�� 
	ostringstream stream;
	
	stream << n;
	return stream.str();
}

void uniform_distribution(int k, long long int b[]) { // ���Rbit�O�_�����ä��t 
	string bin_str = "", temp_str, bin;
	int num, cnt[256] = {0}, max = -1, min = 1001;
	char buffer[k];
	
	cout << "�ik = " << k << "�j" << endl << "binary string: ";
	for (int i = 0; i < 1000 * k; i++) {
		cout << b[i];
		bin_str += Int_to_String(b[i]);
	}
	for (int i = 0; i < bin_str.length(); i += k) { // �]1000�� 
		temp_str = "";
		for (int j = 0; j < k; j++) // �Ck�Ӥ@�� 
			temp_str += bin_str[i + j];
		num = 0;
		for (int l = 1; l <= k; l++) // �G�i����Q�i�� 
			if (temp_str[k - l] == '1') // �q�k��}�lŪ 
				num += (int)pow(2, l - 1);
		cnt[num]++;
	}
	for (int i = 0; i < (int)pow(2, k); i++) {
		bin = itoa(i, buffer, 2); // �N����ର�s�����i��r�� 
		if (bin.length() < k) {
			int len = bin.length();
			
			for (int j = len; j < k; j++)
				bin = "0" + bin;
		}
		cout << endl << bin << "�����v��" << cnt[i] << "/1000"; 
	}
	for (int i = 0; i < (int)pow(2, k); i++)
		if (cnt[i] > max)
			max = cnt[i];
	for (int i = 0; i < (int)pow(2, k); i++)
		if (cnt[i] < min)
			min = cnt[i];
	
	cout << endl << "�t�Ȭ�";
	if (max == min) cout << "0" << endl;
	else            cout << max - min << "/1000" << endl;
}

int main() {
	long long int p, q;
	
	cout << "�mBBS�üƲ��;��n" << endl;
	cout << "�п�J���p�Bp = 3 mod 4: "; // p = 3 mod 4 (ex.7,11,15,...)
	while (cin >> p) {
		if (isPrime(p) == false) cout << "p������� !!!" << endl;
		if (p % 4 != 3) cout << "p���ŦXp = 3 mod 4 !!!" << endl;
		if (isPrime(p) == true && p % 4 == 3) break;
		cout << "�п�J���p�Bp = 3 mod 4: ";
	}
	cout << "�п�J���q�Bq = 3 mod 4: ";
	while (cin >> q) {
		if (isPrime(q) == false) cout << "q������� !!!" << endl;
		if (q % 4 != 3) cout << "q���ŦXq = 3 mod 4 !!!" << endl;
		if (isPrime(q) == true && q % 4 == 3) break;
		cout << "�п�J���q�Bq = 3 mod 4: ";
	}
	long long int n = 0, s;
	
	n = p * q;
	cout << "n = p * q = " << n << endl;
	cout << "�п�J�@�Ӿ��s(�Pn����): ";
	while (cin >> s) {
		if (gcd(s, n) != 1) cout << "s���Pn���� !!!" << endl << "�п�J�@�Ӿ��s(�Pn����): ";
		else                break;
	}
	long long int x[8001], b[8000];
	string bin_str = "";
	
	x[0] = (s * s) % n;
	for (int i = 1; i <= 8000; i++) {
		x[i] = (x[i - 1] * x[i - 1]) % n;
		b[i - 1] = x[i] % 2;
	}
	for (int k = 1; k <= 8; k++)
		uniform_distribution(k, b);
	
	system("pause");
	return 0;
}
