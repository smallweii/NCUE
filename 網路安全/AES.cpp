/*************************************************************************  
    > File Name: AES.cpp 
    > Author: SongLee  
    > E-mail: lisong.shine@qq.com  
    > Created Time: 2014�~12��12�� �P���� 20��15��50��  
    > Personal Blog: songlee24.github.io  
 ************************************************************************/ 
#include <iostream>
#include <bitset>
#include <string>
using namespace std; 
typedef bitset<8> byte;
typedef bitset<32> word;

const int Nr = 10;  // AES-128�ݭn 10 ���[�K 
const int Nk = 4;   // Nk ��ܿ�Jkey�� word�Ӽ� 

byte S_Box[16][16] = { // S_box�d�� 
	{0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 
	 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
	{0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 
	 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
	{0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 
	 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
	{0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 
	 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
	{0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 
	 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
	{0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 
	 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
	{0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 
	 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
	{0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 
	 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
	{0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 
	 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
	{0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 
	 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
	{0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 
	 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
	{0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 
	 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
	{0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 
	 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
	{0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 
	 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
	{0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 
	 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
	{0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 
	 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}
};

byte Inv_S_Box[16][16] = { // Inverse S-box�d�� 
	{0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 
	 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB},
	{0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 
	 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB},
	{0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 
	 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
	{0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 
	 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
	{0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 
	 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
	{0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 
	 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84},
	{0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 
	 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06},
	{0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 
	 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B},
	{0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 
	 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73},
	{0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 
	 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E},
	{0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 
	 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B},
	{0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 
	 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4},
	{0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 
	 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F},
	{0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 
	 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF},
	{0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 
	 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61},
	{0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 
	 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D}
};

// �C��Rcon[]�d��Akey�X�i���|�Ψ�C�]AES-128�u�ݭn10���^
word Rcon[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 
				 0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};

/**********************************************************************/  
/*                                                                    */  
/*                              AES��k��{                           */  
/*                                                                    */  
/**********************************************************************/ 

/******************************�U���O�[�K���ܴ����**********************/
/**
 *  S-box�ܴ� - �e4�쬰�渹�A��4�쬰�C�� 
 */
void SubBytes(byte mtx[4*4]) // Byte Substitution
{
	for(int i=0; i<16; ++i)
	{
		int row = mtx[i][7]*8 + mtx[i][6]*4 + mtx[i][5]*2 + mtx[i][4]; // ��4 bits���C(��4) 
		int col = mtx[i][3]*8 + mtx[i][2]*4 + mtx[i][1]*2 + mtx[i][0]; // �e4 bits����(�k4) 
		mtx[i] = S_Box[row][col]; // S-box�d�� 
	}
}

/**
 *  �C�ܴ� - ���r�`�`������ 
 */
void ShiftRows(byte mtx[4*4]) // Shift Rows: ��C�C�����P���첾 
{
	// �ĤG�C�`�������@�� 
	byte temp = mtx[4];
	for(int i=0; i<3; ++i)
		mtx[i+4] = mtx[i+5];
	mtx[7] = temp;
	// �ĤT�C�`��������� 
	for(int i=0; i<2; ++i)
	{
		temp = mtx[i+8];
		mtx[i+8] = mtx[i+10];
		mtx[i+10] = temp;
	}
	// �ĥ|�C�`�������T�� 
	temp = mtx[15];
	for(int i=3; i>0; --i)
		mtx[i+12] = mtx[i+11];
	mtx[12] = temp;
}

/**
 *  ������W�����k GF(2^8)
 */
byte GFMul(byte a, byte b) {
	byte p = 0;
	byte hi_bit_set;
	for (int counter = 0; counter < 8; counter++) { // a��8 bits 
		if ((b & byte(1)) != 0) { // ��줸b��1 
			p ^= a; // XOR c(x) 
		}
		hi_bit_set = (byte) (a & byte(0x80));
		a <<= 1; // a����1 bit
		if (hi_bit_set != 0) {
			a ^= 0x1b; /* m(x) = x^8 + x^4 + x^3 + x + 1 */ // 1b��00011011
		}
		b >>= 1; // b�k��1 bit
	}
	return p;
}

/**
 *  ���ܴ�  
 */
void MixColumns(byte mtx[4*4]) // Mix Columns: ��Pc(x)�����V�X���B�� 
{
	byte arr[4];
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			arr[j] = mtx[i+j*4]; // �s�쥻�C�C���줸�� 
																				 // c(x)�x�}�p�U: 
		mtx[i] = GFMul(0x02, arr[0]) ^ GFMul(0x03, arr[1]) ^ arr[2] ^ arr[3];    // 02 03 01 01 
		mtx[i+4] = arr[0] ^ GFMul(0x02, arr[1]) ^ GFMul(0x03, arr[2]) ^ arr[3];  // 01 02 03 01
		mtx[i+8] = arr[0] ^ arr[1] ^ GFMul(0x02, arr[2]) ^ GFMul(0x03, arr[3]);  // 01 01 02 03
		mtx[i+12] = GFMul(0x03, arr[0]) ^ arr[1] ^ arr[2] ^ GFMul(0x02, arr[3]); // 03 01 01 02
	}
}

/**
 *  ��key�[�ܴ� - �N�C�@�C�P�X�ikey�i��XOR 
 */
void AddRoundKey(byte mtx[4*4], word k[4]) // Add Round Key: plaintext XOR key
{
	for(int i=0; i<4; ++i)
	{                                          // k[i]: WWWWWWWWXXXXXXXXYYYYYYYYZZZZZZZZ
		word k1 = k[i] >> 24;                                                            // �k��24 bits: 000000000000000000000000WWWWWWWW
		word k2 = (k[i] << 8) >> 24;   // ������8 bits: XXXXXXXXYYYYYYYYZZZZZZZZ00000000�A�A�k��24 bits: 000000000000000000000000XXXXXXXX
		word k3 = (k[i] << 16) >> 24; // ������16 bits: YYYYYYYYZZZZZZZZ0000000000000000�A�A�k��24 bits: 000000000000000000000000YYYYYYYY
		word k4 = (k[i] << 24) >> 24; // ������24 bits: ZZZZZZZZ000000000000000000000000�A�A�k��24 bits: 000000000000000000000000ZZZZZZZZ
		
		mtx[i] = mtx[i] ^ byte(k1.to_ulong()); // to_ulong(): �G�i����Q�i�� (#include<bitset>)
		mtx[i+4] = mtx[i+4] ^ byte(k2.to_ulong());
		mtx[i+8] = mtx[i+8] ^ byte(k3.to_ulong());
		mtx[i+12] = mtx[i+12] ^ byte(k4.to_ulong());
	}
}

/**************************�U���O�ѱK���f�ܴ����***********************/
/**
 *  �fS-box�ܴ� 
 */
void InvSubBytes(byte mtx[4*4]) // Inverse Byte Substitution
{
	for(int i=0; i<16; ++i)
	{
		int row = mtx[i][7]*8 + mtx[i][6]*4 + mtx[i][5]*2 + mtx[i][4];
		int col = mtx[i][3]*8 + mtx[i][2]*4 + mtx[i][1]*2 + mtx[i][0];
		mtx[i] = Inv_S_Box[row][col]; // Inverse S-box�d�� 
	}
}

/**
 *  �f�C�ܴ� - �H�r�`�����`���k��  
 */
void InvShiftRows(byte mtx[4*4]) // Inverse Shift Rows: ��C�C�����P���첾 
{
	// �ĤG�C�`���k���@��  
	byte temp = mtx[7];
	for(int i=3; i>0; --i)
		mtx[i+4] = mtx[i+3];
	mtx[4] = temp;
	// �ĤT�C�`���k�����  
	for(int i=0; i<2; ++i)
	{
		temp = mtx[i+8];
		mtx[i+8] = mtx[i+10];
		mtx[i+10] = temp;
	}
	// �ĥ|�C�`���k���T��  
	temp = mtx[12];
	for(int i=0; i<3; ++i)
		mtx[i+12] = mtx[i+13];
	mtx[15] = temp;
}

void InvMixColumns(byte mtx[4*4]) // Inverse Mix Columns: ��Pc(x)�����V�X���B�� 
{
	byte arr[4];
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			arr[j] = mtx[i+j*4]; // �s�쥻�C�C���줸�� 
															 // c��1(x)�x�}�p�U:
		mtx[i] = GFMul(0x0e, arr[0]) ^ GFMul(0x0b, arr[1]) 
			^ GFMul(0x0d, arr[2]) ^ GFMul(0x09, arr[3]);     // 0e 0b 0d 09
		mtx[i+4] = GFMul(0x09, arr[0]) ^ GFMul(0x0e, arr[1]) 
			^ GFMul(0x0b, arr[2]) ^ GFMul(0x0d, arr[3]);     // 09 0e 0b 0d
		mtx[i+8] = GFMul(0x0d, arr[0]) ^ GFMul(0x09, arr[1]) 
			^ GFMul(0x0e, arr[2]) ^ GFMul(0x0b, arr[3]);     // 0d 09 0e 0b
		mtx[i+12] = GFMul(0x0b, arr[0]) ^ GFMul(0x0d, arr[1]) 
			^ GFMul(0x09, arr[2]) ^ GFMul(0x0e, arr[3]);     // 0b 0d 09 0e
	}
}

/******************************�U���Okey�X�i����***********************/
/**
 * �N4�� byte �ഫ���@�� word.
 */
word Word(byte& k1, byte& k2, byte& k3, byte& k4) // 1 word = 4 bytes = 32 bits�A���|�աA�@��8 bits 
{
	word result(0x00000000); // result: 00000000000000000000000000000000
	word temp;
	temp = k1.to_ulong();    // K1: 000000000000000000000000WWWWWWWW 
	temp <<= 24;    // ����24 bits: WWWWWWWW000000000000000000000000
	result |= temp; // ��result OR: WWWWWWWW000000000000000000000000 ��result 
	temp = k2.to_ulong();    // K2: 000000000000000000000000XXXXXXXX 
	temp <<= 16;    // ����16 bits: 00000000XXXXXXXX0000000000000000
	result |= temp; // ��result OR: WWWWWWWWXXXXXXXX0000000000000000 ��result 
	temp = k3.to_ulong();    // K3: 000000000000000000000000YYYYYYYY 
	temp <<= 8;      // ����8 bits: 0000000000000000YYYYYYYY00000000
	result |= temp; // ��result OR: WWWWWWWWXXXXXXXXYYYYYYYY00000000 ��result 
	temp = k4.to_ulong();    // K4: 000000000000000000000000ZZZZZZZZ 
	result |= temp; // ��result OR: WWWWWWWWXXXXXXXXYYYYYYYYZZZZZZZZ ��result 
	return result;
}

/**
 *  ���r�` �`�������@��  
 *  �Y��[a0, a1, a2, a3]�ܦ�[a1, a2, a3, a0]
 */
word RotWord(word& rw) // RotWord: ����1 byte = 8 bits (1 word = 4 bytes = 32 bits) 
{                        // �쥻�� rw : WWWWWWWWXXXXXXXXYYYYYYYYZZZZZZZZ 
	word high = rw << 8; // ����8 bits: XXXXXXXXYYYYYYYYZZZZZZZZ00000000 
	word low = rw >> 24; // �k��8 bits: 000000000000000000000000WWWWWWWW 
	return high | low;   // ��̰� OR : XXXXXXXXYYYYYYYYZZZZZZZZWWWWWWWW 
}

/**
 *  ���Jword�����C�@�Ӧr�`�i��S-box�ܴ� 
 */
word SubWord(word sw)
{
	word temp;
	for(int i=0; i<32; i+=8) // 1��word����4�����A�@������8 bits(1 word = 4 bytes = 32 bits)
	{
		int row = sw[i+7]*8 + sw[i+6]*4 + sw[i+5]*2 + sw[i+4]; // ��4 bits���C(��4)
		int col = sw[i+3]*8 + sw[i+2]*4 + sw[i+1]*2 + sw[i]; // �e4 bits����(�k4) 
		byte val = S_Box[row][col]; // S-box�d�� 
		for(int j=0; j<8; ++j)
			temp[i+j] = val[j]; // �d����^��8 bits 
	}
	return temp;
}

/**
 *  key�X�i��� - ��128��key�i���X�i�o�� w[4*(Nr+1)]
 */ 
void KeyExpansion(byte key[4*Nk], word w[4*(Nr+1)])
{
	word temp;
	int i = 0;
	// w[]���e4�ӴN�O��J��key
	while(i < Nk) // ex. i < 4
	{
		w[i] = Word(key[4*i], key[4*i+1], key[4*i+2], key[4*i+3]); // ��l���A 
		++i;
	}

	i = Nk; // ex. i = 4 

	while(i < 4*(Nr+1)) // ex. i < 4*(10+1)=44
	{
		temp = w[i-1]; // �O���e�@��word
		if(i % Nk == 0) // ex. i % 4 == 0
			w[i] = w[i-Nk] ^ SubWord(RotWord(temp)) ^ Rcon[i/Nk-1]; // �C4��word���@���ARcon[]�q0�}�l 
		else 
			w[i] = w[i-Nk] ^ temp;
		++i;
	}
}

/******************************�U���O�[�K�M�ѱK���**************************/
/**
 *  �[�K  
 */
void encrypt(byte in[4*4], word w[4*(Nr+1)])
{
	word key[4];
	for(int i=0; i<4; ++i)
		key[i] = w[i]; // ��lkey�q�̫e���}�l�� 
	AddRoundKey(in, key); // �[�K�e�n��Add Round Key 

	for(int round=1; round<Nr; ++round) // ��1~9�^ 
	{
		SubBytes(in);
		ShiftRows(in);
		MixColumns(in);
		for(int i=0; i<4; ++i)
			key[i] = w[4*round+i]; // �̤��P�^�X�Τ��P��4��word��key 
		AddRoundKey(in, key);
	}
 	// ��10�^ 
	SubBytes(in);
	ShiftRows(in);
	for(int i=0; i<4; ++i)
		key[i] = w[4*Nr+i];
	AddRoundKey(in, key);
}

/**
 *  �ѱK  
 */
void decrypt(byte in[4*4], word w[4*(Nr+1)])
{
	word key[4];
	for(int i=0; i<4; ++i)
		key[i] = w[4*Nr+i]; // ��lkey�q�̫᭱�}�l�� 
	AddRoundKey(in, key); // �ѱK�e�n��Add Round Key 

	for(int round=Nr-1; round>0; --round) // ��1~9�^ 
	{
		InvShiftRows(in);
		InvSubBytes(in);
		for(int i=0; i<4; ++i)
			key[i] = w[4*round+i]; // �̤��P�^�X�Τ��P��4��word��key 
		AddRoundKey(in, key);
		InvMixColumns(in);
	}
	// ��10�^ 
	InvShiftRows(in);
	InvSubBytes(in);
	for(int i=0; i<4; ++i)
		key[i] = w[i];
	AddRoundKey(in, key);
}

/**********************************************************************/  
/*                                                                    */  
/*                              ����                                  */  
/*                                                                    */  
/**********************************************************************/ 
int main()
{
	byte key[16] = {0x2b, 0x7e, 0x15, 0x16, 
					0x28, 0xae, 0xd2, 0xa6, 
					0xab, 0xf7, 0x15, 0x88, 
					0x09, 0xcf, 0x4f, 0x3c};

	byte plain[16] = {0x32, 0x88, 0x31, 0xe0, 
					  0x43, 0x5a, 0x31, 0x37,
					  0xf6, 0x30, 0x98, 0x07,
					  0xa8, 0x8d, 0xa2, 0x34}; 
	// ��Xkey
	cout << "key�O�G";
	for(int i=0; i<16; ++i)
		cout << hex << key[i].to_ulong() << " ";/////////////////////////////////hex?
	cout << endl;

	word w[4*(Nr+1)];
	KeyExpansion(key, w);

	// ��X�ݥ[�K������  
	cout << endl << "�ݥ[�K������G" << endl;
	for(int i=0; i<16; ++i)
	{
		cout << hex << plain[i].to_ulong() << " ";
		if((i+1)%4 == 0)
			cout << endl;
	}
	cout << endl;

	// �[�K�A��X�K��  
	encrypt(plain, w);
	cout << "�[�K�᪺�K��G" << endl;
	for(int i=0; i<16; ++i)
	{
		cout << hex << plain[i].to_ulong() << " ";
		if((i+1)%4 == 0)
			cout << endl;
	}
	cout << endl;

	// �ѱK�A��X����  
	decrypt(plain, w);
	cout << "�ѱK�᪺����G" << endl;
	for(int i=0; i<16; ++i)
	{
		cout << hex << plain[i].to_ulong() << " ";
		if((i+1)%4 == 0)
			cout << endl;
	}
	cout << endl;
	return 0;
}
