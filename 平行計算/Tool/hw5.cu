#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024

// 每格相乘:(2^8)*(2^8)=2^16,一列乘一行:有(2^9)個,新矩陣每格:(2^16)*(2^9)=2^25,共有(2^25)*(2^9)*(2^9)=2^43 < 2^32 

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
	
	for (int i = 0; i < 512; i++) { // 512*512的矩陣 
		tmp += Da[bx*512+i] * Da[i*512+tx];
	}
	Db[bx*512+tx] = tmp;
	__syncthreads();
	
	int i = bn/2; // 每個block內的threads來做
	
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
	
	unsigned int nthread, nblock;
	
	if(width > 1024) { // 相乘要等於width*high，但thread維度不能超過1024
        nthread = 1024; 
        nblock = width * high / 1024;
    } else {
        nthread = width;
        nblock = high;
    }
	dim3 block(nthread, 1, 1); // 一個block有1024個threads
	dim3 grid(nblock, 1, 1); // 一個grid有256個block
	
	unsigned long Dimg[512*512]; // CPU
	for (int j = 0; j < 512*512; j++) { // 配置CPU矩陣空間
		Dimg[j] = img[j]; // 確保一個pixel之對應，太小就前面補0，不會吃到前面的值，真是英明
	}
	
	unsigned long *Da; // GPU，4ytes
	cudaMalloc((void**)&Da, (sizeof(unsigned long)*(width*high))); // 配置GPU矩陣空間
	
	cudaMemcpy(Da, Dimg, (sizeof(unsigned long)*(width*high)), cudaMemcpyHostToDevice); //複製資料到GPU
	
	unsigned long *Db; // GPU，4ytes
	cudaMalloc((void**)&Db, (sizeof(unsigned long)*(width*high))); // 配置GPU矩陣空間
	
	Add <<< grid, block >>> (Da,Db,high,width); // 呼叫kernel
	cudaThreadSynchronize();
	
	cudaMemcpy(Dimg, Db, (sizeof(unsigned long)*(width*high)), cudaMemcpyDeviceToHost); // 複製資料(結果)回CPU
	
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
