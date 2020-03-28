#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE * BMP1 = fopen("input.bmp","rb");
	FILE * BMP2 = fopen("output.bmp","wb");
	
	unsigned char header[1078];
	fread(header, 1078, 1, BMP1);
	fwrite(header, 1078, 1, BMP2);
	unsigned char tmp;
	
	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			fread(&tmp, 1, 1, BMP1);
			tmp = 255 - tmp;
			fwrite(&tmp, 1, 1, BMP2);
		}
	}
}
