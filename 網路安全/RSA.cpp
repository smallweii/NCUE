#include<iostream>
#include<cmath>
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

int inverse(long long int e, long long int euler) { // ed = 1 mod ��(n)�A��e��inverse 
	long long int Q = 0, A1 = 1, A2 = 0, A3 = euler, B1 = 0, B2 = 1, B3 = e, tmp1, tmp2, tmp3;
	
	while (B3 != 1) {
		Q = A3 / B3;
		tmp1 = A1;
		tmp2 = A2;
		tmp3 = A3;
		A1 = B1;
		A2 = B2;
		A3 = B3;
		B1 = tmp1 - Q * A1;
		B2 = tmp2 - Q * A2;
		B3 = tmp3 - Q * A3;
	}
	return B2;
}

int encrpyt_decrypt(long long int m, long long int e, long long int n) { // �[�K: C = M ^ e mod n / �ѱK: M = C ^ d mod n 
	long long int tmp = m;
	
	for (int i = 1; i < e; i++) {
		tmp *= m;
		if (tmp > n) tmp %= n; 
	}
	return tmp;
}

int main() {
	long long int p, q;
	
	cout << "�mRSA�[�K�ѱK���n" << endl;
	cout << "�п�J���p: ";
	while (cin >> p) {
		if (isPrime(p) == false) cout << "p������� !!!" << endl << "�п�J���p: ";
		else                     break;
	}
	cout << "�п�J���q: ";
	while (cin >> q) {
		if (isPrime(q) == false) cout << "q������� !!!" << endl << "�п�J���q: ";
		else                     break;
	}
	long long int n = 0, euler = 0, e, m, d, c, mm;
	
	n = p * q;
	euler = (p - 1) * (q - 1);
	cout << "n = p * q = " << n << endl << "��(n) = (p - 1)(q - 1) = " << euler << endl;
	cout << "�п�J�[�K���_e(1<e<��(n)�B�P��(n)����): ";
	while (cin >> e) {
		if (e <= 1 || e >= euler) cout << "e���b1<e<��(n)�d�� !!!" << endl;
		if (gcd(e, euler) != 1) cout << "e���P��(n)���� !!!" << endl;
		if (1 < e && e < euler && gcd(e, euler) == 1) break;
		cout << "�п�J�[�K���_e(1<e<��(n)�B�P��(n)����): ";
	}
	cout << "�п�J����M: ";
	cin >> m;
	d = inverse(e, euler); // ed = 1 mod ��(n)
	c = encrpyt_decrypt(m, e, n); // C = M ^ e mod n
	mm = encrpyt_decrypt(c, d, n); // P = C ^ d mod n
	cout << endl << "�[�K�L�{: " << m << " ^ " << e << " mod " << n << " = " << c << endl;
	cout << "�K��: " << c << endl;
	cout << "�ѱK���_d: " << d << endl;
	cout << "�ѱK�L�{: " << c << " ^ " << d << " mod " << n << " = " << mm << endl;
	cout << "����: " << mm << endl;
	system("pause");
	return 0;
}
