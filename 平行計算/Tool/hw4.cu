#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024
__global__ void Add(unsigned int *Da,int high,int width)
{
	int tx = threadIdx.x;           
	int bx = blockIdx.x;			
	int bn = blockDim.x;
	//int gn = gridDim.x;
	int id = bx*bn+tx;				
	
	//for(int i=id;i<(high*width);i+=(bn*gn))
	  //Da[i] = 255 - Da[i];
	
	int i = 1024/2; // 每個block內的threads來做
	
	while (i != 0) {
		if (tx < i) {
		  Da[id] += Da[id + i];
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
	unsigned char *img; // 可表位元，1 byte = 8 bits
	
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
	
	dim3 block(1024, 1, 1); // 一個block有1024個threads
	dim3 grid(256, 1, 1); // 一個grid有256個block
	
	unsigned int Dimg[512*512]; // CPU
	for (int j = 0; j < 512*512; j++) {
		Dimg[j] = img[j]; // 確保一個pixel之對應，太小就前面補0，不會吃到前面的值，真是英明
	}
	
	unsigned int *Da; // GPU，4ytes
	cudaMalloc((void**)&Da, (sizeof(unsigned int)*(width*high))); // 配置GPU矩陣空間
	
	cudaMemcpy(Da, Dimg, (sizeof(unsigned int)*(width*high)), cudaMemcpyHostToDevice);
	
	Add <<< grid, block >>> (Da,high,width); // 呼叫kernel
	cudaThreadSynchronize();
	
	cudaMemcpy(Dimg, Da, (sizeof(unsigned int)*(width*high)), cudaMemcpyDeviceToHost); // 複製資料到GPU
	
	fclose(fp);
	
	unsigned int sum = 0;
	for (int i = 0; i < 512*512; i += 1024) { // 256個block
		sum += Dimg[i];
	}
	sum /= (512*512);
	
	printf("\n%3d\n", sum);
}
