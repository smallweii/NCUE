#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;

string Int_to_String(int n) { // 整數轉字串 
	ostringstream stream;
	
	stream << n;
	return stream.str();
}
string HexToBin(string hex) { // 16進位轉二進位 
	string temp_bin = "", binary = ""; // 64
	char buffer[64];
	
	for (int i = 0; i < hex.length(); i++) { // 16
		if (hex[i] == 'a' || hex[i] == 'A')      temp_bin = itoa(10, buffer, 2); // 將整數轉為存成２進制之字串 
		else if (hex[i] == 'b' || hex[i] == 'B') temp_bin = itoa(11, buffer, 2);
		else if (hex[i] == 'c' || hex[i] == 'C') temp_bin = itoa(12, buffer, 2);
		else if (hex[i] == 'd' || hex[i] == 'D') temp_bin = itoa(13, buffer, 2);
		else if (hex[i] == 'e' || hex[i] == 'E') temp_bin = itoa(14, buffer, 2);
		else if (hex[i] == 'f' || hex[i] == 'F') temp_bin = itoa(15, buffer, 2);
		else                                     temp_bin = itoa((int)hex[i] - '0', buffer, 2);
		
		if (temp_bin.length() < 4) {
			int len = temp_bin.length();
			
			for (int j = 0; j < 4 - len; j++)
				temp_bin = "0" + temp_bin;
		}
		binary += temp_bin;
	}
	return binary;
}
string BinToHex(string bin) { // 二進位轉16進位 
	string hex = ""; // 16
	int sum;
	
	for (int i = 0; i < 64; i += 4) {
		sum = 0;
		if (bin[i] == '1')     sum += 8;
		if (bin[i + 1] == '1') sum += 4;
		if (bin[i + 2] == '1') sum += 2;
		if (bin[i + 3] == '1') sum += 1;
		
		if (sum == 10)      hex += "a";
		else if (sum == 11) hex += "b";
		else if (sum == 12) hex += "c";
		else if (sum == 13) hex += "d";
		else if (sum == 14) hex += "e";
		else if (sum == 15) hex += "f";
		else 				hex += Int_to_String(sum); // 整數轉字串 
	}
	return hex;
}
string Bin_64_ToHex(string bin[64]) { // 二進位轉16進位 
	string hex = ""; // 16
	int sum;
	
	for (int i = 0; i < 64; i += 4) {
		sum = 0;
		if (bin[i] == "1")     sum += 8;
		if (bin[i + 1] == "1") sum += 4;
		if (bin[i + 2] == "1") sum += 2;
		if (bin[i + 3] == "1") sum += 1;
		
		if (sum == 10)      hex += "a";
		else if (sum == 11) hex += "b";
		else if (sum == 12) hex += "c";
		else if (sum == 13) hex += "d";
		else if (sum == 14) hex += "e";
		else if (sum == 15) hex += "f";
		else 				hex += Int_to_String(sum); // 整數轉字串 
	}
	return hex;
}
string Bin_32_ToHex(string bin[32]) { // 二進位轉16進位 
	string hex = ""; // 16
	int sum;
	
	for (int i = 0; i < 32; i += 4) {
		sum = 0;
		if (bin[i] == "1")     sum += 8;
		if (bin[i + 1] == "1") sum += 4;
		if (bin[i + 2] == "1") sum += 2;
		if (bin[i + 3] == "1") sum += 1;
		
		if (sum == 10)      hex += "a";
		else if (sum == 11) hex += "b";
		else if (sum == 12) hex += "c";
		else if (sum == 13) hex += "d";
		else if (sum == 14) hex += "e";
		else if (sum == 15) hex += "f";
		else 				hex += Int_to_String(sum); // 整數轉字串 
	}
	return hex;
}
int main() {
	int choice;
	char choice2;
	string kk[16][48], kk_kcg[16][48];
	
	cout << "歡迎使用《DES Cipher》\n";
	cout << "1. 加密\n2. 解密\n\n";
	cout << "請輸入選項: ";
	cin >> choice;
	cout << "a. 輸入key\nb. 從檔案讀key\n\n";
	cout << "請輸入選項: ";
	cin >> choice2;
	cout << endl;
	
	string key = ""; // 16
	
	if (choice2 == 'a') { // 輸入key
		cout << "請輸入key: ";
		cin >> key;
		cout << endl;
	} else if (choice2 == 'b') { // 從檔案讀key
		string key_filename;
	
		cout << "請輸入key的檔名(XXX.txt): ";
		cin >> key_filename;
		cout << endl;
		ifstream fin(key_filename.c_str()); // 讀使用者輸入的檔名 
	
		if (!fin) { // 檢查檔案是否成功開啟，若!fin為真，檔案則無法開啟 
			cout << "Can't open the file!" << endl;
			exit(1); // 在不正常情形下，中斷程式的執行 
		}
		char ch;
	
		while (fin >> ch)
			key += ch;
	}
	string key_bin = "", key_bin_kcg = ""; // 64
	
	key_bin = HexToBin(key);
	key_bin_kcg = key_bin;
	if (key_bin_kcg.at(3) == '0') // 從左邊數來第3個bit改變  
			key_bin_kcg.at(3) = '1'; // 0變1 
		else
			key_bin_kcg.at(3) = '0'; // 1變0 
	
	/* Permuted Choice One(PC-1) */
	string key_bin_pc1[56], key_bin_pc1_kcg[56];
	int pc1[56] = {57, 49, 41, 33, 25, 17, 9,
				   1, 58, 50, 42, 34, 26, 18,
				   10, 2, 59, 51, 43, 35, 27,
				   19, 11, 3, 60, 52, 44, 36,
				   63, 55, 47, 39, 31, 23, 15,
				   7, 62, 54, 46, 38, 30, 22,
				   14, 6, 61, 53, 45, 37, 29,
				   21, 13, 5, 28, 20, 12, 4};
	
	for (int i = 0; i < 64; i++)
		for (int j = 0; j < 56; j++)
			if (pc1[j] == i + 1) {
				key_bin_pc1[j] = key_bin[i];
				key_bin_pc1_kcg[j] = key_bin_kcg[i];
			}
	// 分28 28
	string ci[28], di[28], ci_kcg[28], di_kcg[28];
	int kx = 0, ky = 28;
	
	for (int i = 0; i < 28; i++) {
		ci[i] = key_bin_pc1[kx];
		ci_kcg[i] = key_bin_pc1_kcg[kx];
		kx++;
	}
	for (int i = 0; i < 28; i++) {
		di[i] = key_bin_pc1[ky];
		di_kcg[i] = key_bin_pc1_kcg[ky];
		ky++;
	}
	///* 以下為一回合, 共有16回合 *///
	for (int round = 1; round <= 16; round++) {
		// 分28 28
		string ci1[28], di1[28], ci1_kcg[28], di1_kcg[28];
		int c = 0, d = 0;
		
		for (int i = 0; i < 28; i++) {
			ci1[i] = ci[c];
			ci1_kcg[i] = ci_kcg[c];
			c++;
		}
		for (int i = 0; i < 28; i++) {
			di1[i] = di[d];
			di1_kcg[i] = di_kcg[d];
			d++;
		}
		string ci1_ls[28], di1_ls[28], ci1_ls_kcg[28], di1_ls_kcg[28];
		int left_shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1}; // 看round決定每個bit要左移幾bit 
		
		if (left_shift[round - 1] == 1) { // 左移1bit 
			for (int i = 0; i < 28; i++) {
				if (i == 27) {
					ci1_ls[i] = ci1[0];
					ci1_ls_kcg[i] = ci1_kcg[0];
				} else {
					ci1_ls[i] = ci1[i + 1];
					ci1_ls_kcg[i] = ci1_kcg[i + 1];
				}
			}
		} else { // 左移2bits 
			for (int i = 0; i < 28; i++) {
				if (i == 26) {
					ci1_ls[i] = ci1[0];
					ci1_ls_kcg[i] = ci1_kcg[0];
				} else if (i == 27) {
					ci1_ls[i] = ci1[1];
					ci1_ls_kcg[i] = ci1_kcg[1];
				} else {
					ci1_ls[i] = ci1[i + 2];
					ci1_ls_kcg[i] = ci1_kcg[i + 2];
				}
			}
		}
		if (left_shift[round - 1] == 1) { // 左移1bit 
			for (int i = 0; i < 28; i++) {
				if (i == 27) {
					di1_ls[i] = di1[0];
					di1_ls_kcg[i] = di1_kcg[0];
				} else {
					di1_ls[i] = di1[i + 1];
					di1_ls_kcg[i] = di1_kcg[i + 1];
				}
			}
		} else { // 左移2bits 
			for (int i = 0; i < 28; i++) {
				if (i == 26) {
					di1_ls[i] = di1[0];
					di1_ls_kcg[i] = di1_kcg[0];
				} else if (i == 27) {
					di1_ls[i] = di1[1];
					di1_ls_kcg[i] = di1_kcg[1];
				} else {
					di1_ls[i] = di1[i + 2];
					di1_ls_kcg[i] = di1_kcg[i + 2];
				}
			}
		}
		for (int i = 0; i < 28; i++) {
			ci[i] = ci1_ls[i];
			ci_kcg[i] = ci1_ls_kcg[i];
		}
		for (int i = 0; i < 28; i++) {
			di[i] = di1_ls[i];
			di_kcg[i] = di1_ls_kcg[i];
		}
		// 各自左移完合併成56再PC-2挑48
		string cd_lf[56], cd_lf_kcg[56];
		int cd = 0;
		
		for (int i = 0; i < 28; i++) {
			cd_lf[cd] = ci1_ls[i];
			cd_lf_kcg[cd] = ci1_ls_kcg[i];
			cd++;
		}
		for (int i = 0; i < 28; i++) {
			cd_lf[cd] = di1_ls[i];
			cd_lf_kcg[cd] = di1_ls_kcg[i];
			cd++;
		}
		/* Permuted Choice Two(PC-2) */
		string key_bin_pc2[48], key_bin_pc2_kcg[48];
		int pc2[48] = {14, 17, 11, 24, 1, 5, 3, 28,
					   15, 6, 21, 10, 23, 19, 12, 4,
					   26, 8, 16, 7, 27, 20, 13, 2,
					   41, 52, 31, 37, 47, 55, 30, 40,
					   51, 45, 33, 48, 44, 49, 39, 56,
					   34, 53, 46, 42, 50, 36, 29, 32};
		
		for (int i = 0; i < 56; i++)
			for (int j = 0; j < 48; j++)
				if (pc2[j] == i + 1) {
					key_bin_pc2[j] = cd_lf[i];
					key_bin_pc2_kcg[j] = cd_lf_kcg[i];
				}
		for (int i = 0; i < 48; i++) {
			kk[round - 1][i] = key_bin_pc2[i];
			kk_kcg[round - 1][i] = key_bin_pc2_kcg[i];
		}
	}
	///* 以下為常用Table *///
	/* Initial Permutation (IP) */
	int ip[64] = {58, 50, 42, 34, 26, 18, 10, 2,
				  60, 52, 44, 36, 28, 20, 12, 4,
				  62, 54, 46, 38, 30, 22, 14, 6,
				  64, 56, 48, 40, 32, 24, 16, 8,
				  57, 49, 41, 33, 25, 17, 9, 1,
				  59, 51, 43, 35, 27, 19, 11, 3,
				  61, 53, 45, 37, 29, 21, 13, 5,
				  63, 55, 47, 39, 31, 23, 15, 7};
	/* Expansion Permutation (E) */
	int exp[48] = {32, 1, 2, 3, 4, 5,
				   4, 5, 6, 7, 8, 9,
				   8, 9, 10, 11, 12, 13,
				   12, 13, 14, 15, 16, 17,
				   16, 17, 18, 19, 20, 21,
				   20, 21, 22, 23, 24, 25,
				   24, 25, 26, 27, 28, 29,
				   28, 29, 30, 31, 32, 1};
	/* S-box */
	int s1[4][16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
					 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
					 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
					 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};
	int s2[4][16] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
					 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
					 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9 ,3, 2, 15, 
					 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};
	int s3[4][16] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
					 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
					 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
					 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};
	int s4[4][16] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
					 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
					 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
					 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};
	int s5[4][16] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
					 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
					 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
					 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};
	int s6[4][16] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
					 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
					 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
					 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};
	int s7[4][16] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
					 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
					 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
					 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};
	int s8[4][16] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
					 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
					 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
					 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};
	/* Permutation (P) */
	int p[32] = {16, 7, 20, 21, 29, 12, 28, 17,
				 1, 15, 23, 26, 5, 18, 31, 10,
				 2, 8, 24, 14, 32, 27, 3, 9,
				 19, 13, 30, 6, 22, 11, 4, 25};
	/* Inverse Initial Permutation (IPˉ1) */
	int iip[64] = {40, 8, 48, 16, 56, 24, 64, 32,
				   39, 7, 47, 15, 55, 23, 63, 31,
				   38, 6, 46, 14, 54, 22, 62, 30,
				   37, 5, 45, 13, 53, 21, 61, 29,
				   36, 4, 44, 12, 52, 20, 60, 28,
				   35, 3, 43, 11, 51, 19, 59, 27,
				   34, 2, 42, 10, 50, 18, 58, 26,
				   33, 1, 41, 9, 49, 17, 57, 25};
	if (choice == 1) { // 加密 //////////////////////////////////////////////////////////////////
		string filename;
		
		cout << "請輸入欲加密的檔名(XXX.txt): ";
		cin >> filename;
		cout << endl;
		ifstream fin(filename.c_str()); // 讀使用者輸入的檔名 
		
		if (!fin) { // 檢查檔案是否成功開啟，若!fin為真，檔案則無法開啟 
			cout << "Can't open the file!" << endl;
			exit(1); // 在不正常情形下，中斷程式的執行 
		}
		char ch;
		string plain = ""; // 16
		
		while (fin >> ch)
			plain += ch;
		
		string plain_bin = "", plain_bin_cg = "", plain_bin_kcg = ""; // 64
		fstream fout;
		
		plain_bin = HexToBin(plain);
		plain_bin_cg = plain_bin;
		plain_bin_kcg = plain_bin;
		
		if (plain_bin_cg.at(3) == '0') // 從左邊數來第3個bit改變  
			plain_bin_cg.at(3) = '1'; // 0變1 
		else
			plain_bin_cg.at(3) = '0'; // 1變0 
		
		fout.open("b1.txt", ios::out); //在寫入模式下開啟b1.txt檔 
		fout << plain_bin << endl;
		
		string lr[64], lr_cg[64], lr_kcg[64];
		
		for (int i = 0; i < 64; i++)
			for (int j = 0; j < 64; j++)
				if (ip[j] == i + 1) {
					lr[j] = plain_bin[i];
					lr_cg[j] = plain_bin_cg[i];
					lr_kcg[j] = plain_bin_kcg[i];
				}
		// 分32 32 
		string li[32], ri[32], li_cg[32], ri_cg[32], li_kcg[32], ri_kcg[32];
		int px = 0, py = 32;
		string li_hex = "", ri_hex = "", li_hex_cg = "", ri_hex_cg = "", li_hex_kcg = "", ri_hex_kcg = ""; // 8
		
		for (int i = 0; i < 32; i++) {
			li[i] = lr[px];
			li_cg[i] = lr_cg[px];
			li_kcg[i] = lr_kcg[px];
			px++;
		}
		li_hex = Bin_32_ToHex(li);
		for (int i = 0; i < 32; i++) {
			ri[i] = lr[py];
			ri_cg[i] = lr_cg[py];
			ri_kcg[i] = lr_kcg[py];
			py++;
		}
		ri_hex = Bin_32_ToHex(ri);
		cout << "Round        Ki           Li       Ri" << endl;
		cout << " IP                    " << li_hex << " " << ri_hex << endl;
		
		string lr_hex[16], lr_hex_cg[16], lr_hex_kcg[16];
		int difference[16], difference_kcg[16];
		
		///* 以下為一回合, 共有16回合 *///
		for (int round = 1; round <= 16; round++) {
			if (round < 10) cout << "  " << round << "   ";
			else            cout << " " << round << "   ";
			
			string ki[64], ki_hex = ""; // 16
			int k = 0;
				
			for (int i = 0; i < 48; i += 6) {
				ki[k] = "0";
				ki[k + 1] = "0";
				ki[k + 2] = kk[round - 1][i];
				ki[k + 3] = kk[round - 1][i + 1];
				ki[k + 4] = kk[round - 1][i + 2];
				ki[k + 5] = kk[round - 1][i + 3];
				ki[k + 6] = kk[round - 1][i + 4];
				ki[k + 7] = kk[round - 1][i + 5];
				k += 8;
			}
			ki_hex = Bin_64_ToHex(ki);
			cout << ki_hex << " ";
			
			// 分32 32 
			string li1[32], ri1[32], li1_cg[32], ri1_cg[32], li1_kcg[32], ri1_kcg[32];
			int l = 0, r = 0;
			
			for (int i = 0; i < 32; i++) {
				li1[i] = li[l];
				li1_cg[i] = li_cg[l];
				li1_kcg[i] = li_kcg[l];
				l++;
			}
			for (int i = 0; i < 32; i++) {
				ri1[i] = ri[r];
				ri1_cg[i] = ri_cg[r];
				ri1_kcg[i] = ri_kcg[r];
				r++;
			}
			//* Ri=Li-1⊕F(Ri-1,Ki) *//
			/* F(Ri-1,Ki) */
			string bin_exp[48], bin_exp_cg[48], bin_exp_kcg[48];
			
			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 48; j++)
						if (exp[j] == i + 1) {
							bin_exp[j] = ri1[i];
							bin_exp_cg[j] = ri1_cg[i];
							bin_exp_kcg[j] = ri1_kcg[i];
						}
			// bin_exp2[] XOR key_bin_pc2_2[]
			bool exp_b, pc2_b;
			string xor1[48], xor1_cg[48], xor1_kcg[48];
			
			for (int i = 0; i < 48; i++) {
				if (bin_exp[i] == "0") exp_b = 0;
				else                   exp_b = 1;
				if (kk[round - 1][i] == "0") pc2_b = 0;
				else                         pc2_b = 1;
				if (exp_b ^ pc2_b == 0) xor1[i] = "0";
				else                    xor1[i] = "1";
			}
			for (int i = 0; i < 48; i++) {
				if (bin_exp_cg[i] == "0") exp_b = 0;
				else                      exp_b = 1;
				if (kk[round - 1][i] == "0") pc2_b = 0;
				else                         pc2_b = 1;
				if (exp_b ^ pc2_b == 0) xor1_cg[i] = "0";
				else                    xor1_cg[i] = "1";
			}
			for (int i = 0; i < 48; i++) {
				if (bin_exp_kcg[i] == "0") exp_b = 0;
				else                       exp_b = 1;
				if (kk_kcg[round - 1][i] == "0") pc2_b = 0;
				else                             pc2_b = 1;
				if (exp_b ^ pc2_b == 0) xor1_kcg[i] = "0";
				else                    xor1_kcg[i] = "1";
			}
			// 每6bits一組進S-box挑4bits
			string x1[6], x2[6], x3[6], x4[6], x5[6], x6[6], x7[6], x8[6], 
				   x1_cg[6], x2_cg[6], x3_cg[6], x4_cg[6], x5_cg[6], x6_cg[6], x7_cg[6], x8_cg[6],
				   x1_kcg[6], x2_kcg[6], x3_kcg[6], x4_kcg[6], x5_kcg[6], x6_kcg[6], x7_kcg[6], x8_kcg[6];
			int x = 0, sr = 0, sc = 0;
			char buffer_sbox[4];
			string xs1 = "", xs2 = "", xs3 = "", xs4 = "", xs5 = "", xs6 = "", xs7 = "", xs8 = "",
				   xs1_cg = "", xs2_cg = "", xs3_cg = "", xs4_cg = "", xs5_cg = "", xs6_cg = "", xs7_cg = "", xs8_cg = "",
				   xs1_kcg = "", xs2_kcg = "", xs3_kcg = "", xs4_kcg = "", xs5_kcg = "", xs6_kcg = "", xs7_kcg = "", xs8_kcg = ""; // 4
			
			///////////////////// s1 /////////////////////
			for (int i = 0; i < 6; i++) {
				x1[i] = xor1[x];
				x1_cg[i] = xor1_cg[x];
				x1_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x1[0] == "0" && x1[5] == "0")      sr = 0;
			else if (x1[0] == "0" && x1[5] == "1") sr = 1;
			else if (x1[0] == "1" && x1[5] == "0") sr = 2;
			else if (x1[0] == "1" && x1[5] == "1") sr = 3;
			
			if (x1[1] == "1") sc += 8;
			if (x1[2] == "1") sc += 4;
			if (x1[3] == "1") sc += 2;
			if (x1[4] == "1") sc += 1;
			
			xs1 = itoa(s1[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs1.length() < 4) {
				int len = xs1.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs1 = "0" + xs1;
			}
			sc = 0;
			if (x1_cg[0] == "0" && x1_cg[5] == "0")      sr = 0;
			else if (x1_cg[0] == "0" && x1_cg[5] == "1") sr = 1;
			else if (x1_cg[0] == "1" && x1_cg[5] == "0") sr = 2;
			else if (x1_cg[0] == "1" && x1_cg[5] == "1") sr = 3;
			
			if (x1_cg[1] == "1") sc += 8;
			if (x1_cg[2] == "1") sc += 4;
			if (x1_cg[3] == "1") sc += 2;
			if (x1_cg[4] == "1") sc += 1;
			
			xs1_cg = itoa(s1[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs1_cg.length() < 4) {
				int len = xs1_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs1_cg = "0" + xs1_cg;
			}
			sc = 0;
			if (x1_kcg[0] == "0" && x1_kcg[5] == "0")      sr = 0;
			else if (x1_kcg[0] == "0" && x1_kcg[5] == "1") sr = 1;
			else if (x1_kcg[0] == "1" && x1_kcg[5] == "0") sr = 2;
			else if (x1_kcg[0] == "1" && x1_kcg[5] == "1") sr = 3;
			
			if (x1_kcg[1] == "1") sc += 8;
			if (x1_kcg[2] == "1") sc += 4;
			if (x1_kcg[3] == "1") sc += 2;
			if (x1_kcg[4] == "1") sc += 1;
			
			xs1_kcg = itoa(s1[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs1_kcg.length() < 4) {
				int len = xs1_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs1_kcg = "0" + xs1_kcg;
			}
			///////////////////// s2 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x2[i] = xor1[x];
				x2_cg[i] = xor1_cg[x];
				x2_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x2[0] == "0" && x2[5] == "0")      sr = 0;
			else if (x2[0] == "0" && x2[5] == "1") sr = 1;
			else if (x2[0] == "1" && x2[5] == "0") sr = 2;
			else if (x2[0] == "1" && x2[5] == "1") sr = 3;
			
			if (x2[1] == "1") sc += 8;
			if (x2[2] == "1") sc += 4;
			if (x2[3] == "1") sc += 2;
			if (x2[4] == "1") sc += 1;
			
			xs2 = itoa(s2[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs2.length() < 4) {
				int len = xs2.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs2 = "0" + xs2;
			}
			sc = 0;
			if (x2_cg[0] == "0" && x2_cg[5] == "0")      sr = 0;
			else if (x2_cg[0] == "0" && x2_cg[5] == "1") sr = 1;
			else if (x2_cg[0] == "1" && x2_cg[5] == "0") sr = 2;
			else if (x2_cg[0] == "1" && x2_cg[5] == "1") sr = 3;
			
			if (x2_cg[1] == "1") sc += 8;
			if (x2_cg[2] == "1") sc += 4;
			if (x2_cg[3] == "1") sc += 2;
			if (x2_cg[4] == "1") sc += 1;
			
			xs2_cg = itoa(s2[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs2_cg.length() < 4) {
				int len = xs2_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs2_cg = "0" + xs2_cg;
			}
			sc = 0;
			if (x2_kcg[0] == "0" && x2_kcg[5] == "0")      sr = 0;
			else if (x2_kcg[0] == "0" && x2_kcg[5] == "1") sr = 1;
			else if (x2_kcg[0] == "1" && x2_kcg[5] == "0") sr = 2;
			else if (x2_kcg[0] == "1" && x2_kcg[5] == "1") sr = 3;
			
			if (x2_kcg[1] == "1") sc += 8;
			if (x2_kcg[2] == "1") sc += 4;
			if (x2_kcg[3] == "1") sc += 2;
			if (x2_kcg[4] == "1") sc += 1;
			
			xs2_kcg = itoa(s2[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs2_kcg.length() < 4) {
				int len = xs2_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs2_kcg = "0" + xs2_kcg;
			}
			///////////////////// s3 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x3[i] = xor1[x];
				x3_cg[i] = xor1_cg[x];
				x3_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x3[0] == "0" && x3[5] == "0")      sr = 0;
			else if (x3[0] == "0" && x3[5] == "1") sr = 1;
			else if (x3[0] == "1" && x3[5] == "0") sr = 2;
			else if (x3[0] == "1" && x3[5] == "1") sr = 3;
			
			if (x3[1] == "1") sc += 8;
			if (x3[2] == "1") sc += 4;
			if (x3[3] == "1") sc += 2;
			if (x3[4] == "1") sc += 1;
			
			xs3 = itoa(s3[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs3.length() < 4) {
				int len = xs3.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs3 = "0" + xs3;
			}
			sc = 0;
			if (x3_cg[0] == "0" && x3_cg[5] == "0")      sr = 0;
			else if (x3_cg[0] == "0" && x3_cg[5] == "1") sr = 1;
			else if (x3_cg[0] == "1" && x3_cg[5] == "0") sr = 2;
			else if (x3_cg[0] == "1" && x3_cg[5] == "1") sr = 3;
			
			if (x3_cg[1] == "1") sc += 8;
			if (x3_cg[2] == "1") sc += 4;
			if (x3_cg[3] == "1") sc += 2;
			if (x3_cg[4] == "1") sc += 1;
			
			xs3_cg = itoa(s3[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs3_cg.length() < 4) {
				int len = xs3_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs3_cg = "0" + xs3_cg;
			}
			sc = 0;
			if (x3_kcg[0] == "0" && x3_kcg[5] == "0")      sr = 0;
			else if (x3_kcg[0] == "0" && x3_kcg[5] == "1") sr = 1;
			else if (x3_kcg[0] == "1" && x3_kcg[5] == "0") sr = 2;
			else if (x3_kcg[0] == "1" && x3_kcg[5] == "1") sr = 3;
			
			if (x3_kcg[1] == "1") sc += 8;
			if (x3_kcg[2] == "1") sc += 4;
			if (x3_kcg[3] == "1") sc += 2;
			if (x3_kcg[4] == "1") sc += 1;
			
			xs3_kcg = itoa(s3[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs3_kcg.length() < 4) {
				int len = xs3_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs3_kcg = "0" + xs3_kcg;
			}
			///////////////////// s4 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x4[i] = xor1[x];
				x4_cg[i] = xor1_cg[x];
				x4_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x4[0] == "0" && x4[5] == "0")      sr = 0;
			else if (x4[0] == "0" && x4[5] == "1") sr = 1;
			else if (x4[0] == "1" && x4[5] == "0") sr = 2;
			else if (x4[0] == "1" && x4[5] == "1") sr = 3;
			
			if (x4[1] == "1") sc += 8;
			if (x4[2] == "1") sc += 4;
			if (x4[3] == "1") sc += 2;
			if (x4[4] == "1") sc += 1;
			
			xs4 = itoa(s4[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs4.length() < 4) {
				int len = xs4.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs4 = "0" + xs4;
			}
			sc = 0;
			if (x4_cg[0] == "0" && x4_cg[5] == "0")      sr = 0;
			else if (x4_cg[0] == "0" && x4_cg[5] == "1") sr = 1;
			else if (x4_cg[0] == "1" && x4_cg[5] == "0") sr = 2;
			else if (x4_cg[0] == "1" && x4_cg[5] == "1") sr = 3;
			
			if (x4_cg[1] == "1") sc += 8;
			if (x4_cg[2] == "1") sc += 4;
			if (x4_cg[3] == "1") sc += 2;
			if (x4_cg[4] == "1") sc += 1;
			
			xs4_cg = itoa(s4[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs4_cg.length() < 4) {
				int len = xs4_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs4_cg = "0" + xs4_cg;
			}
			sc = 0;
			if (x4_kcg[0] == "0" && x4_kcg[5] == "0")      sr = 0;
			else if (x4_kcg[0] == "0" && x4_kcg[5] == "1") sr = 1;
			else if (x4_kcg[0] == "1" && x4_kcg[5] == "0") sr = 2;
			else if (x4_kcg[0] == "1" && x4_kcg[5] == "1") sr = 3;
			
			if (x4_kcg[1] == "1") sc += 8;
			if (x4_kcg[2] == "1") sc += 4;
			if (x4_kcg[3] == "1") sc += 2;
			if (x4_kcg[4] == "1") sc += 1;
			
			xs4_kcg = itoa(s4[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs4_kcg.length() < 4) {
				int len = xs4_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs4_kcg = "0" + xs4_kcg;
			}
			///////////////////// s5 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x5[i] = xor1[x];
				x5_cg[i] = xor1_cg[x];
				x5_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x5[0] == "0" && x5[5] == "0")      sr = 0;
			else if (x5[0] == "0" && x5[5] == "1") sr = 1;
			else if (x5[0] == "1" && x5[5] == "0") sr = 2;
			else if (x5[0] == "1" && x5[5] == "1") sr = 3;
			
			if (x5[1] == "1") sc += 8;
			if (x5[2] == "1") sc += 4;
			if (x5[3] == "1") sc += 2;
			if (x5[4] == "1") sc += 1;
			
			xs5 = itoa(s5[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs5.length() < 4) {
				int len = xs5.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs5 = "0" + xs5;
			}
			sc = 0;
			if (x5_cg[0] == "0" && x5_cg[5] == "0")      sr = 0;
			else if (x5_cg[0] == "0" && x5_cg[5] == "1") sr = 1;
			else if (x5_cg[0] == "1" && x5_cg[5] == "0") sr = 2;
			else if (x5_cg[0] == "1" && x5_cg[5] == "1") sr = 3;
			
			if (x5_cg[1] == "1") sc += 8;
			if (x5_cg[2] == "1") sc += 4;
			if (x5_cg[3] == "1") sc += 2;
			if (x5_cg[4] == "1") sc += 1;
			
			xs5_cg = itoa(s5[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs5_cg.length() < 4) {
				int len = xs5_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs5_cg = "0" + xs5_cg;
			}
			sc = 0;
			if (x5_kcg[0] == "0" && x5_kcg[5] == "0")      sr = 0;
			else if (x5_kcg[0] == "0" && x5_kcg[5] == "1") sr = 1;
			else if (x5_kcg[0] == "1" && x5_kcg[5] == "0") sr = 2;
			else if (x5_kcg[0] == "1" && x5_kcg[5] == "1") sr = 3;
			
			if (x5_kcg[1] == "1") sc += 8;
			if (x5_kcg[2] == "1") sc += 4;
			if (x5_kcg[3] == "1") sc += 2;
			if (x5_kcg[4] == "1") sc += 1;
			
			xs5_kcg = itoa(s5[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs5_kcg.length() < 4) {
				int len = xs5_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs5_kcg = "0" + xs5_kcg;
			}
			///////////////////// s6 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x6[i] = xor1[x];
				x6_cg[i] = xor1_cg[x];
				x6_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x6[0] == "0" && x6[5] == "0")      sr = 0;
			else if (x6[0] == "0" && x6[5] == "1") sr = 1;
			else if (x6[0] == "1" && x6[5] == "0") sr = 2;
			else if (x6[0] == "1" && x6[5] == "1") sr = 3;
			
			if (x6[1] == "1") sc += 8;
			if (x6[2] == "1") sc += 4;
			if (x6[3] == "1") sc += 2;
			if (x6[4] == "1") sc += 1;
			
			xs6 = itoa(s6[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs6.length() < 4) {
				int len = xs6.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs6 = "0" + xs6;
			}
			sc = 0;
			if (x6_cg[0] == "0" && x6_cg[5] == "0")      sr = 0;
			else if (x6_cg[0] == "0" && x6_cg[5] == "1") sr = 1;
			else if (x6_cg[0] == "1" && x6_cg[5] == "0") sr = 2;
			else if (x6_cg[0] == "1" && x6_cg[5] == "1") sr = 3;
			
			if (x6_cg[1] == "1") sc += 8;
			if (x6_cg[2] == "1") sc += 4;
			if (x6_cg[3] == "1") sc += 2;
			if (x6_cg[4] == "1") sc += 1;
			
			xs6_cg = itoa(s6[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs6_cg.length() < 4) {
				int len = xs6_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs6_cg = "0" + xs6_cg;
			}
			sc = 0;
			if (x6_kcg[0] == "0" && x6_kcg[5] == "0")      sr = 0;
			else if (x6_kcg[0] == "0" && x6_kcg[5] == "1") sr = 1;
			else if (x6_kcg[0] == "1" && x6_kcg[5] == "0") sr = 2;
			else if (x6_kcg[0] == "1" && x6_kcg[5] == "1") sr = 3;
			
			if (x6_kcg[1] == "1") sc += 8;
			if (x6_kcg[2] == "1") sc += 4;
			if (x6_kcg[3] == "1") sc += 2;
			if (x6_kcg[4] == "1") sc += 1;
			
			xs6_kcg = itoa(s6[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs6_kcg.length() < 4) {
				int len = xs6_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs6_kcg = "0" + xs6_kcg;
			}
			///////////////////// s7 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x7[i] = xor1[x];
				x7_cg[i] = xor1_cg[x];
				x7_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x7[0] == "0" && x7[5] == "0")      sr = 0;
			else if (x7[0] == "0" && x7[5] == "1") sr = 1;
			else if (x7[0] == "1" && x7[5] == "0") sr = 2;
			else if (x7[0] == "1" && x7[5] == "1") sr = 3;
			
			if (x7[1] == "1") sc += 8;
			if (x7[2] == "1") sc += 4;
			if (x7[3] == "1") sc += 2;
			if (x7[4] == "1") sc += 1;
			
			xs7 = itoa(s7[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs7.length() < 4) {
				int len = xs7.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs7 = "0" + xs7;
			}
			sc = 0;
			if (x7_cg[0] == "0" && x7_cg[5] == "0")      sr = 0;
			else if (x7_cg[0] == "0" && x7_cg[5] == "1") sr = 1;
			else if (x7_cg[0] == "1" && x7_cg[5] == "0") sr = 2;
			else if (x7_cg[0] == "1" && x7_cg[5] == "1") sr = 3;
			
			if (x7_cg[1] == "1") sc += 8;
			if (x7_cg[2] == "1") sc += 4;
			if (x7_cg[3] == "1") sc += 2;
			if (x7_cg[4] == "1") sc += 1;
			
			xs7_cg = itoa(s7[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs7_cg.length() < 4) {
				int len = xs7_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs7_cg = "0" + xs7_cg;
			}
			sc = 0;
			if (x7_kcg[0] == "0" && x7_kcg[5] == "0")      sr = 0;
			else if (x7_kcg[0] == "0" && x7_kcg[5] == "1") sr = 1;
			else if (x7_kcg[0] == "1" && x7_kcg[5] == "0") sr = 2;
			else if (x7_kcg[0] == "1" && x7_kcg[5] == "1") sr = 3;
			
			if (x7_kcg[1] == "1") sc += 8;
			if (x7_kcg[2] == "1") sc += 4;
			if (x7_kcg[3] == "1") sc += 2;
			if (x7_kcg[4] == "1") sc += 1;
			
			xs7_kcg = itoa(s7[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs7_kcg.length() < 4) {
				int len = xs7_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs7_kcg = "0" + xs7_kcg;
			}
			///////////////////// s8 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x8[i] = xor1[x];
				x8_cg[i] = xor1_cg[x];
				x8_kcg[i] = xor1_kcg[x];
				x++;
			}
			if (x8[0] == "0" && x8[5] == "0")      sr = 0;
			else if (x8[0] == "0" && x8[5] == "1") sr = 1;
			else if (x8[0] == "1" && x8[5] == "0") sr = 2;
			else if (x8[0] == "1" && x8[5] == "1") sr = 3;
			
			if (x8[1] == "1") sc += 8;
			if (x8[2] == "1") sc += 4;
			if (x8[3] == "1") sc += 2;
			if (x8[4] == "1") sc += 1;
			
			xs8 = itoa(s8[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs8.length() < 4) {
				int len = xs8.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs8 = "0" + xs8;
			}
			sc = 0;
			if (x8_cg[0] == "0" && x8_cg[5] == "0")      sr = 0;
			else if (x8_cg[0] == "0" && x8_cg[5] == "1") sr = 1;
			else if (x8_cg[0] == "1" && x8_cg[5] == "0") sr = 2;
			else if (x8_cg[0] == "1" && x8_cg[5] == "1") sr = 3;
			
			if (x8_cg[1] == "1") sc += 8;
			if (x8_cg[2] == "1") sc += 4;
			if (x8_cg[3] == "1") sc += 2;
			if (x8_cg[4] == "1") sc += 1;
			
			xs8_cg = itoa(s8[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs8_cg.length() < 4) {
				int len = xs8_cg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs8_cg = "0" + xs8_cg;
			}
			sc = 0;
			if (x8_kcg[0] == "0" && x8_kcg[5] == "0")      sr = 0;
			else if (x8_kcg[0] == "0" && x8_kcg[5] == "1") sr = 1;
			else if (x8_kcg[0] == "1" && x8_kcg[5] == "0") sr = 2;
			else if (x8_kcg[0] == "1" && x8_kcg[5] == "1") sr = 3;
			
			if (x8_kcg[1] == "1") sc += 8;
			if (x8_kcg[2] == "1") sc += 4;
			if (x8_kcg[3] == "1") sc += 2;
			if (x8_kcg[4] == "1") sc += 1;
			
			xs8_kcg = itoa(s8[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs8_kcg.length() < 4) {
				int len = xs8_kcg.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs8_kcg = "0" + xs8_kcg;
			}
			string sbox = "", sbox_cg = "", sbox_kcg = "";
			string pp[32], pp_cg[32], pp_kcg[32];
			
			sbox = xs1 + xs2 + xs3 + xs4 + xs5 + xs6 + xs7 + xs8;
			sbox_cg = xs1_cg + xs2_cg + xs3_cg + xs4_cg + xs5_cg + xs6_cg + xs7_cg + xs8_cg;
			sbox_kcg = xs1_kcg + xs2_kcg + xs3_kcg + xs4_kcg + xs5_kcg + xs6_kcg + xs7_kcg + xs8_kcg;
			
			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 32; j++)
					if (p[j] == i + 1) {
						pp[j] = sbox[i];
						pp_cg[j] = sbox_cg[i];
						pp_kcg[j] = sbox_kcg[i];
					}
			// Li-1[] XOR pp[]
			bool li1_b, pp_b;
			string xor2[32], xor2_cg[32], xor2_kcg[32];
			
			for (int i = 0; i < 32; i++) {
				if (li1[i] == "0") li1_b = 0;
				else               li1_b = 1;
				if (pp[i] == "0") pp_b = 0;
				else              pp_b = 1;
				if (li1_b ^ pp_b == 0) xor2[i] = "0";
				else                   xor2[i] = "1";
			}
			for (int i = 0; i < 32; i++) {
				if (li1_cg[i] == "0") li1_b = 0;
				else                  li1_b = 1;
				if (pp_cg[i] == "0") pp_b = 0;
				else                 pp_b = 1;
				if (li1_b ^ pp_b == 0) xor2_cg[i] = "0";
				else                   xor2_cg[i] = "1";
			}
			for (int i = 0; i < 32; i++) {
				if (li1_kcg[i] == "0") li1_b = 0;
				else                   li1_b = 1;
				if (pp_kcg[i] == "0") pp_b = 0;
				else                  pp_b = 1;
				if (li1_b ^ pp_b == 0) xor2_kcg[i] = "0";
				else                   xor2_kcg[i] = "1";
			}
			for (int i = 0; i < 32; i++) {
				li[i] = ri1[i];
				li_cg[i] = ri1_cg[i];
				li_kcg[i] = ri1_kcg[i];
			}
			li_hex = Bin_32_ToHex(li);
			li_hex_cg = Bin_32_ToHex(li_cg);
			li_hex_kcg = Bin_32_ToHex(li_kcg);
			cout << li_hex << " ";
			
			for (int i = 0; i < 32; i++) {
				ri[i] = xor2[i];
				ri_cg[i] = xor2_cg[i];
				ri_kcg[i] = xor2_kcg[i];
			}
			ri_hex = Bin_32_ToHex(ri);
			ri_hex_cg = Bin_32_ToHex(ri_cg);
			ri_hex_kcg = Bin_32_ToHex(ri_kcg);
			cout << ri_hex << endl;
			
			lr_hex[round - 1] = li_hex + ri_hex;
			lr_hex_cg[round - 1] = li_hex_cg + ri_hex_cg;
			lr_hex_kcg[round - 1] = li_hex_kcg + ri_hex_kcg;
			difference[round - 1] = 0;
			difference_kcg[round - 1] = 0;
			
			for (int i = 0; i < 32; i++) {
				if (li[i] != li_cg[i]) difference[round - 1]++;
				if (ri[i] != ri_cg[i]) difference[round - 1]++;
			}
			for (int i = 0; i < 32; i++) {
				if (li[i] != li_kcg[i]) difference_kcg[round - 1]++;
				if (ri[i] != ri_kcg[i]) difference_kcg[round - 1]++;
			}
			
			if (round == 16) { //////////////////////////////////////////////
				cout << " IP-1                  ";
				for (int i = 0; i < 32; i++) {
					li[i] = xor2[i];
					li_cg[i] = xor2_cg[i];
					li_kcg[i] = xor2_kcg[i];
				}
				for (int i = 0; i < 32; i++) {
					ri[i] = ri1[i];
					ri_cg[i] = ri1_cg[i];
					ri_kcg[i] = ri1_kcg[i];
				}
				string cipher_bin[64], cipher_bin_cg[64], cipher_bin_kcg[64], cipher_bin_iip[64], cipher_bin_iip_cg[64], cipher_bin_iip_kcg[64];
				int cp = 0;
				
				for (int i = 0; i < 32; i++) {
					cipher_bin[cp] = li[i];
					cipher_bin_cg[cp] = li_cg[i];
					cipher_bin_kcg[cp] = li_kcg[i];
					cp++;
				}
				for (int i = 0; i < 32; i++) {
					cipher_bin[cp] = ri[i];
					cipher_bin_cg[cp] = ri_cg[i];
					cipher_bin_kcg[cp] = ri_kcg[i];
					cp++;
				}
				for (int i = 0; i < 64; i++)
					for (int j = 0; j < 64; j++)
						if (iip[j] == i + 1) {
							cipher_bin_iip[j] = cipher_bin[i];
							cipher_bin_iip_cg[j] = cipher_bin_cg[i];
							cipher_bin_iip_kcg[j] = cipher_bin_kcg[i];
						}
				string cipher = "", cipher_cg = "", cipher_kcg = ""; // 16
				int difference_cp = 0, difference_cp_kcg = 0;
				
				cipher = Bin_64_ToHex(cipher_bin_iip);
				cipher_cg = Bin_64_ToHex(cipher_bin_iip_cg);
				cipher_kcg = Bin_64_ToHex(cipher_bin_iip_kcg);
				
				for (int i = 0; i < 64; i++) {
					if (cipher_bin_iip[i] != cipher_bin_iip_cg[i]) difference_cp++;
					if (cipher_bin_iip[i] != cipher_bin_iip_kcg[i]) difference_cp_kcg++;
				}
				for (int i = 0; i < 8; i++)
					cout << cipher[i];
				cout << " ";
				for (int i = 8; i < 16; i++)
					cout << cipher[i];
				
				fstream fout2;
				
				fout2.open("c2.txt", ios::out); //在寫入模式下開啟c2.txt檔 
				fout2 << cipher << endl;
				
				cout << endl << endl << "【崩塌效應】" << endl;
				cout << "(1) 改變 Plaintext: " << endl << "Round                  δ" << endl;
				cout << "      " << plain << " 1" << endl << "      " << BinToHex(plain_bin_cg) << endl;
				for (int round2 = 1; round2 <= 16; round2++) {
					if (round2 < 10) cout << "  " << round2 << "   ";
					else             cout << " " << round2 << "   ";
					cout << lr_hex[round2 - 1] << " " << difference[round2 - 1] << endl << "      " << lr_hex_cg[round2 - 1] << endl;
					if (round2 == 16) cout << " IP-1 " << cipher << " " << difference_cp << endl << "      " << cipher_cg << endl << endl;
				}
				cout << "(2) 改變 Key: " << endl << "Round                  δ" << endl;
				cout << "      " << plain << " 0" << endl << "      " << BinToHex(plain_bin) << endl;
				for (int round2 = 1; round2 <= 16; round2++) {
					if (round2 < 10) cout << "  " << round2 << "   ";
					else             cout << " " << round2 << "   ";
					cout << lr_hex[round2 - 1] << " " << difference_kcg[round2 - 1] << endl << "      " << lr_hex_kcg[round2 - 1] << endl;
					if (round2 == 16) cout << " IP-1 " << cipher << " " << difference_cp_kcg << endl << "      " << cipher_kcg << endl << endl;
				}
			}
		}
	} else if (choice == 2) { // 解密 //////////////////////////////////////////////////////////////////
		string filename;
		
		cout << "請輸入欲解密的檔名(XXX.txt): ";
		cin >> filename;
		ifstream fin(filename.c_str()); // 讀使用者輸入的檔名 
		
		if (!fin) { // 檢查檔案是否成功開啟，若!fin為真，檔案則無法開啟 
			cout << "Can't open the file!" << endl;
			exit(1); // 在不正常情形下，中斷程式的執行 
		}
		char ch;
		string cipher = ""; // 16
		
		while (fin >> ch)
			cipher += ch;
		
		string cipher_bin = ""; // 64
		fstream fout;
		
		cipher_bin = HexToBin(cipher);		
		fout.open("b2.txt", ios::out); //在寫入模式下開啟b2.txt檔 
		fout << cipher_bin << endl;
		
		string lr[64];
		
		for (int i = 0; i < 64; i++)
			for (int j = 0; j < 64; j++)
				if (ip[j] == i + 1)
					lr[j] = cipher_bin[i];
		
		// 分32 32 
		string li[32], ri[32];
		int px = 0, py = 32;
		string li_hex = "", ri_hex = ""; // 8
		
		for (int i = 0; i < 32; i++) {
			li[i] = lr[px];
			px++;
		}
		li_hex = Bin_32_ToHex(li);
		for (int i = 0; i < 32; i++) {
			ri[i] = lr[py];
			py++;
		}
		ri_hex = Bin_32_ToHex(ri);
		cout << "Round        Ki           Li       Ri" << endl;
		cout << " IP                    " << li_hex << " " << ri_hex << endl;
		
		///* 以下為一回合, 共有16回合 *///
		for (int round = 1; round <= 16; round++) {
			if (round < 10) cout << "  " << round << "   ";
			else            cout << " " << round << "   ";
			
			string ki[64], ki_hex = ""; // 16
			int k = 0;
				
			for (int i = 0; i < 48; i += 6) {
				ki[k] = "0";
				ki[k + 1] = "0";
				ki[k + 2] = kk[16 - round][i];
				ki[k + 3] = kk[16 - round][i + 1];
				ki[k + 4] = kk[16 - round][i + 2];
				ki[k + 5] = kk[16 - round][i + 3];
				ki[k + 6] = kk[16 - round][i + 4];
				ki[k + 7] = kk[16 - round][i + 5];
				k += 8;
			}
			ki_hex = Bin_64_ToHex(ki);
			cout << ki_hex << " ";
				
			// 分32 32 
			string li1[32], ri1[32];
			int l = 0, r = 0;
			
			for (int i = 0; i < 32; i++) {
				li1[i] = li[l];
				l++;
			}
			for (int i = 0; i < 32; i++) {
				ri1[i] = ri[r];
				r++;
			}
			//* Ri=Li-1⊕F(Ri-1,Ki) *//
			/* F(Ri-1,Ki) */
			string bin_exp[48];
			
			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 48; j++)
						if (exp[j] == i + 1)
							bin_exp[j] = ri1[i];
			
			// bin_exp2[] XOR key_bin_pc2_2[]
			bool exp_b, pc2_b;
			string xor1[48];
			
			for (int i = 0; i < 48; i++) {
				if (bin_exp[i] == "0") exp_b = 0;
				else                    exp_b = 1;
				if (kk[16 - round][i] == "0") pc2_b = 0; ///////////////
				else                          pc2_b = 1;
				if (exp_b ^ pc2_b == 0) xor1[i] = "0";
				else                    xor1[i] = "1";
			}
			// 每6bits一組進S-box挑4bits
			string x1[6], x2[6], x3[6], x4[6], x5[6], x6[6], x7[6], x8[6];
			int x = 0, sr = 0, sc = 0;
			char buffer_sbox[4];
			string xs1 = "", xs2 = "", xs3 = "", xs4 = "", xs5 = "", xs6 = "", xs7 = "", xs8 = ""; // 4
			
			///////////////////// s1 /////////////////////
			for (int i = 0; i < 6; i++) {
				x1[i] = xor1[x];
				x++;
			}
			if (x1[0] == "0" && x1[5] == "0")      sr = 0;
			else if (x1[0] == "0" && x1[5] == "1") sr = 1;
			else if (x1[0] == "1" && x1[5] == "0") sr = 2;
			else if (x1[0] == "1" && x1[5] == "1") sr = 3;
			
			if (x1[1] == "1") sc += 8;
			if (x1[2] == "1") sc += 4;
			if (x1[3] == "1") sc += 2;
			if (x1[4] == "1") sc += 1;
			
			xs1 = itoa(s1[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs1.length() < 4) {
				int len = xs1.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs1 = "0" + xs1;
			}
			///////////////////// s2 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x2[i] = xor1[x];
				x++;
			}
			if (x2[0] == "0" && x2[5] == "0")      sr = 0;
			else if (x2[0] == "0" && x2[5] == "1") sr = 1;
			else if (x2[0] == "1" && x2[5] == "0") sr = 2;
			else if (x2[0] == "1" && x2[5] == "1") sr = 3;
			
			if (x2[1] == "1") sc += 8;
			if (x2[2] == "1") sc += 4;
			if (x2[3] == "1") sc += 2;
			if (x2[4] == "1") sc += 1;
			
			xs2 = itoa(s2[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs2.length() < 4) {
				int len = xs2.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs2 = "0" + xs2;
			}
			///////////////////// s3 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x3[i] = xor1[x];
				x++;
			}
			if (x3[0] == "0" && x3[5] == "0")      sr = 0;
			else if (x3[0] == "0" && x3[5] == "1") sr = 1;
			else if (x3[0] == "1" && x3[5] == "0") sr = 2;
			else if (x3[0] == "1" && x3[5] == "1") sr = 3;
			
			if (x3[1] == "1") sc += 8;
			if (x3[2] == "1") sc += 4;
			if (x3[3] == "1") sc += 2;
			if (x3[4] == "1") sc += 1;
			
			xs3 = itoa(s3[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs3.length() < 4) {
				int len = xs3.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs3 = "0" + xs3;
			}
			///////////////////// s4 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x4[i] = xor1[x];
				x++;
			}
			if (x4[0] == "0" && x4[5] == "0")      sr = 0;
			else if (x4[0] == "0" && x4[5] == "1") sr = 1;
			else if (x4[0] == "1" && x4[5] == "0") sr = 2;
			else if (x4[0] == "1" && x4[5] == "1") sr = 3;
			
			if (x4[1] == "1") sc += 8;
			if (x4[2] == "1") sc += 4;
			if (x4[3] == "1") sc += 2;
			if (x4[4] == "1") sc += 1;
			
			xs4 = itoa(s4[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs4.length() < 4) {
				int len = xs4.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs4 = "0" + xs4;
			}
			///////////////////// s5 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x5[i] = xor1[x];
				x++;
			}
			if (x5[0] == "0" && x5[5] == "0")      sr = 0;
			else if (x5[0] == "0" && x5[5] == "1") sr = 1;
			else if (x5[0] == "1" && x5[5] == "0") sr = 2;
			else if (x5[0] == "1" && x5[5] == "1") sr = 3;
			
			if (x5[1] == "1") sc += 8;
			if (x5[2] == "1") sc += 4;
			if (x5[3] == "1") sc += 2;
			if (x5[4] == "1") sc += 1;
			
			xs5 = itoa(s5[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs5.length() < 4) {
				int len = xs5.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs5 = "0" + xs5;
			}
			///////////////////// s6 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x6[i] = xor1[x];
				x++;
			}
			if (x6[0] == "0" && x6[5] == "0")      sr = 0;
			else if (x6[0] == "0" && x6[5] == "1") sr = 1;
			else if (x6[0] == "1" && x6[5] == "0") sr = 2;
			else if (x6[0] == "1" && x6[5] == "1") sr = 3;
			
			if (x6[1] == "1") sc += 8;
			if (x6[2] == "1") sc += 4;
			if (x6[3] == "1") sc += 2;
			if (x6[4] == "1") sc += 1;
			
			xs6 = itoa(s6[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs6.length() < 4) {
				int len = xs6.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs6 = "0" + xs6;
			}
			///////////////////// s7 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x7[i] = xor1[x];
				x++;
			}
			if (x7[0] == "0" && x7[5] == "0")      sr = 0;
			else if (x7[0] == "0" && x7[5] == "1") sr = 1;
			else if (x7[0] == "1" && x7[5] == "0") sr = 2;
			else if (x7[0] == "1" && x7[5] == "1") sr = 3;
			
			if (x7[1] == "1") sc += 8;
			if (x7[2] == "1") sc += 4;
			if (x7[3] == "1") sc += 2;
			if (x7[4] == "1") sc += 1;
			
			xs7 = itoa(s7[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs7.length() < 4) {
				int len = xs7.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs7 = "0" + xs7;
			}
			///////////////////// s8 /////////////////////
			sc = 0;
			for (int i = 0; i < 6; i++) {
				x8[i] = xor1[x];
				x++;
			}
			if (x8[0] == "0" && x8[5] == "0")      sr = 0;
			else if (x8[0] == "0" && x8[5] == "1") sr = 1;
			else if (x8[0] == "1" && x8[5] == "0") sr = 2;
			else if (x8[0] == "1" && x8[5] == "1") sr = 3;
			
			if (x8[1] == "1") sc += 8;
			if (x8[2] == "1") sc += 4;
			if (x8[3] == "1") sc += 2;
			if (x8[4] == "1") sc += 1;
			
			xs8 = itoa(s8[sr][sc], buffer_sbox, 2); // 將整數轉為存成２進制之字串 
			if (xs8.length() < 4) {
				int len = xs8.length();
				
				for (int i = 0; i < 4 - len; i++)
					xs8 = "0" + xs8;
			}
			string sbox = "", pp[32];
			
			sbox = xs1 + xs2 + xs3 + xs4 + xs5 + xs6 + xs7 + xs8;
			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 32; j++)
					if (p[j] == i + 1)
						pp[j] = sbox[i];
			
			// Li-1[] XOR pp[]
			bool li1_b, pp_b;
			string xor2[32];
			
			for (int i = 0; i < 32; i++) {
				if (li1[i] == "0") li1_b = 0;
				else               li1_b = 1;
				if (pp[i] == "0") pp_b = 0;
				else              pp_b = 1;
				if (li1_b ^ pp_b == 0) xor2[i] = "0";
				else                   xor2[i] = "1";
			}
			for (int i = 0; i < 32; i++)
				li[i] = ri1[i];
			li_hex = Bin_32_ToHex(li);
			cout << li_hex << " ";
			
			for (int i = 0; i < 32; i++)
				ri[i] = xor2[i];
			ri_hex = Bin_32_ToHex(ri);
			cout << ri_hex << endl;
			
			if (round == 16) {
				cout << " IP-1                  ";
				for (int i = 0; i < 32; i++)
					li[i] = xor2[i];
				for (int i = 0; i < 32; i++)
					ri[i] = ri1[i];
				
				string plain_bin[64], plain_bin_iip[64], plain = ""; // 16
				int pl = 0;
				
				for (int i = 0; i < 32; i++) {
					plain_bin[pl] = li[i];
					pl++;
				}
				for (int i = 0; i < 32; i++) {
					plain_bin[pl] = ri[i];
					pl++;
				}
				for (int i = 0; i < 64; i++)
					for (int j = 0; j < 64; j++)
						if (iip[j] == i + 1)
							plain_bin_iip[j] = plain_bin[i];
				
				plain = Bin_64_ToHex(plain_bin_iip);
				for (int i = 0; i < 8; i++)
					cout << plain[i];
				cout << " ";
				for (int i = 8; i < 16; i++)
					cout << plain[i];
				cout << endl << endl;
				
				fstream fout2;
				
				fout2.open("p2.txt", ios::out); //在寫入模式下開啟p2.txt檔 
				fout2 << plain << endl;
			}
		}
	}
	system("pause");
	return 0;
} 
