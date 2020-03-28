//一維陣列相加的範例程式

#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

#define DataSize 16*16 // 16*16矩陣

void GenerateNumbers(int *number, int size, int k)//隨機產生資料
{
     int i;
	   srand(k * time(NULL));
     for (i = 0; i < size; i++)
         number[i] = rand() % 100;
}

__global__ void kernel(int *Da, int *Db, int *Dc)//kernel function
{
	int tx = threadIdx.x;      //thread的x軸id
	int ty = threadIdx.y;      //thread的y軸id
	int tmp = 0;
	int n = 16;

	for (int i = 0; i < n; i++)
        tmp += Da[ty*n+i] * Db[i*n+tx];
    Dc[ty*n+tx] = tmp;
}

int main()
{
	int *Ha, *Hb, *Hc; //CPU
	int size = DataSize * sizeof(int);
	
	Ha = (int*)malloc(size);				//配置矩陣空間
	Hb = (int*)malloc(size);				//配置矩陣空間
	Hc = (int*)malloc(size);				//配置矩陣空間
	
	GenerateNumbers(Ha, DataSize, 2);		//產生矩陣資料
	GenerateNumbers(Hb, DataSize, 6);		//產生矩陣資料

	
	/* dim3 由CUDA提供的三維向量型態 (X,Y,Z)
		CUDA限制每個block的thread上限為1024, (X*Y*Z)<=1024
		grid的block上限為65535, (X*Y)<=65535.  block最多2維而已
	*/	
	
	dim3 block(16, 16, 1);	 //配置thread維度、大小  
	dim3 grid(1, 1, 1);	     //配置block維度、大小
	
	int *Da, *Db, *Dc; //GPU
	cudaMalloc((void**)&Da, size);			//配置GPU矩陣空間
	cudaMalloc((void**)&Db, size);			//配置GPU矩陣空間
	cudaMalloc((void**)&Dc, size);			//配置GPU矩陣空間

	cudaMemcpy(Da, Ha, size, cudaMemcpyHostToDevice);		//複製資料到GPU
	cudaMemcpy(Db, Hb, size, cudaMemcpyHostToDevice);		//複製資料到GPU

	kernel <<< grid, block >>> (Da, Db, Dc);			//呼叫kernel
	cudaThreadSynchronize();

	cudaMemcpy(Hc, Dc, size, cudaMemcpyDeviceToHost);		//複製資料(比較後的結果)回CPU

	int i;
	printf("A\n");
	for (i = 0; i < DataSize; i++) {
		printf("%3d ", Ha[i]);
		if (i % 16 == 15)
			printf("\n");
	}
	
	printf("\nB\n");
	for (i = 0; i < DataSize; i++) {
		printf("%3d ", Hb[i]);
		if (i % 16 == 15)
			printf("\n");
	}
		
	printf("\nC\n");
	for (i = 0; i < DataSize; i++) {
		printf("%3d ", Hc[i]);
		if (i % 16 == 15)
			printf("\n");
	}
	printf("\n");
	
	//釋放記憶體空間
		free(Ha); free(Hb); free(Hc);
	
		cudaFree(Da); cudaFree(Db); cudaFree(Dc);
}
