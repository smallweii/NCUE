#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024

// �C��ۭ�:(2^8)*(2^8)=2^16,�@�C���@��:��(2^9)��,�s�x�}�C��:(2^16)*(2^9)=2^25,�@��(2^25)*(2^9)*(2^9)=2^43 < 2^32 

__global__ void Add(unsigned long *Da,unsigned long *Db,int high,int width)
{
	int tx = threadIdx.x;
	int bx = blockIdx.x;
	int bn = blockDim.x;
	//int gn = gridDim.x;
	int id = bx*bn+tx;				
	
	//for(int i=id;i<(high*width);i+=(bn*gn))
	  //Da[i] = 255 - Da[i];
	
	unsigned long tmp = 0;
	
	for (int i = 0; i < 512; i++) { // 512*512���x�} 
		tmp += Da[bx*512+i] * Da[i*512+tx];
	}
	Db[bx*512+tx] = tmp;
	__syncthreads();
	
	int i = bn/2; // �C��block����threads�Ӱ�
	
	while (i != 0) {
		if (tx < i) {
		  Db[id] += Db[id + i];
		}
		__syncthreads();
		i /= 2;
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
	
	unsigned int nthread, nblock;
	
	if(width > 1024) { // �ۭ��n����width*high�A��thread���פ���W�L1024
        nthread = 1024; 
        nblock = width * high / 1024;
    } else {
        nthread = width;
        nblock = high;
    }
	dim3 block(nthread, 1, 1); // �@��block��1024��threads
	dim3 grid(nblock, 1, 1); // �@��grid��256��block
	
	unsigned long Dimg[512*512]; // CPU
	for (int j = 0; j < 512*512; j++) { // �t�mCPU�x�}�Ŷ�
		Dimg[j] = img[j]; // �T�O�@��pixel�������A�Ӥp�N�e����0�A���|�Y��e�����ȡA�u�O�^��
	}
	
	unsigned long *Da; // GPU�A4ytes
	cudaMalloc((void**)&Da, (sizeof(unsigned long)*(width*high))); // �t�mGPU�x�}�Ŷ�
	
	cudaMemcpy(Da, Dimg, (sizeof(unsigned long)*(width*high)), cudaMemcpyHostToDevice); //�ƻs��ƨ�GPU
	
	unsigned long *Db; // GPU�A4ytes
	cudaMalloc((void**)&Db, (sizeof(unsigned long)*(width*high))); // �t�mGPU�x�}�Ŷ�
	
	Add <<< grid, block >>> (Da,Db,high,width); // �I�skernel
	cudaThreadSynchronize();
	
	cudaMemcpy(Dimg, Db, (sizeof(unsigned long)*(width*high)), cudaMemcpyDeviceToHost); // �ƻs���(���G)�^CPU
	
	fclose(fp);
	
	unsigned long sum = 0;
	/*for (int i = 0; i < 512*512; i++) {
		sum += Dimg[i];
	}*/
	for (int i = 0; i < nthread*nblock; i += nthread) {
		sum += Dimg[i];
	}
	sum /= (512*512);
	
	printf("\n%3lu\n", sum);
}
