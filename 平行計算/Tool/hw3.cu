#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024
__global__ void Add(unsigned int *Da,int high,int width,int half)
{
	int tx = threadIdx.x;           
	int bx = blockIdx.x;			
	int bn = blockDim.x;
	//int gn = gridDim.x;
	int id = bx*bn+tx;				
	
	//for(int i=id;i<(high*width);i+=(bn*gn))
	  //Da[i] = 255 - Da[i];
	
	if (id < half) {
		Da[id] += Da[id + half];
	}
}
int main()
{
	FILE *fp = NULL;
	unsigned int high, width, offset;
	unsigned char *head;
	unsigned char *img; // �i��줸�A1 byte = 8 bits
	
	high = 0;
	width = 0;
	offset = 0;

	fp = fopen("lena.bmp","rb");

	fseek(fp, 10, SEEK_SET);
	fread(&offset, sizeof(unsigned int), 1, fp);

	fseek(fp, 18, SEEK_SET);
	fread(&width, sizeof(unsigned int), 1, fp);

	fseek(fp, 22, SEEK_SET);
	fread(&high, sizeof(unsigned int), 1, fp);

	img = (unsigned char*)malloc(sizeof(unsigned char)*(width*high));
	fseek(fp, offset, SEEK_SET);
	fread(img, sizeof(char), (width*high), fp);

	head =(unsigned char*)malloc(sizeof(unsigned char)*(offset));
	fseek(fp, 0, SEEK_SET);
	fread(head, sizeof(unsigned char), offset, fp);
	
	dim3 block(1024, 1, 1); // �@��block��1024��threads
	dim3 grid(256, 1, 1); // �@��grid��256��block
	
	unsigned int Dimg[512*512]; // CPU
	for (int j = 0; j < 512*512; j++) {
		Dimg[j] = img[j]; // �T�O�@��pixel�������A�Ӥp�N�e����0�A���|�Y��e�����ȡA�u�O�^��
	}
	
	unsigned int *Da; // GPU�A4ytes
	cudaMalloc((void**)&Da, (sizeof(unsigned int)*(width*high))); // �t�mGPU�x�}�Ŷ�
	
	cudaMemcpy(Da, Dimg, (sizeof(unsigned int)*(width*high)), cudaMemcpyHostToDevice);
	
	int round = 0, half = 512*512;
	while (round < 18) { // lg(512*512)=lg(2^9*2^9)=lg(2^9)+lg(2^9)=9+9=18
		half /= 2;
		Add <<< grid, block >>> (Da,high,width,half); // �I�skernel
		cudaThreadSynchronize();
		round++;
	}
	
	cudaMemcpy(Dimg, Da, (sizeof(unsigned int)*(width*high)), cudaMemcpyDeviceToHost); // �ƻs��ƨ�GPU
	
	fclose(fp);
	
	Dimg[0] /= (512*512);
	printf("\n%3d\n", Dimg[0]);
}
