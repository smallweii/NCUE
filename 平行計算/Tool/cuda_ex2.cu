//一維陣列相加的範例程式

#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

#define DataSize 16

void GenerateNumbers(int *number, int size, int k)//隨機產生資料
{
     int i;
	   srand(k * time(NULL));
     for (i = 0; i < size; i++)
         number[i] = rand() % 100;
}

__global__ void Compare_A(int *Da, int *Dc)//kernel function
{
	int tx = threadIdx.x;     //thread的x軸id
	int bx = blockIdx.x;	    //block的x軸id
	int bn = blockDim.x;		//block的x軸有幾個thread
	int id = bx*bn+tx;		//計算矩陣座標
	
	//Dc[id] = Da[id] + Db[id];
	if (Da[id*2] >= Da[id*2+1])
		Dc[id] = Da[id*2];
	else
		Dc[id] = Da[id*2+1];
}

int main()
{
	int *Ha, *Hc; //CPU
	int size = DataSize * sizeof(int);
	
	Ha = (int*)malloc(size);				//配置矩陣空間
	//Hb = (int*)malloc(size);				//配置矩陣空間
	Hc = (int*)malloc(size);				//配置矩陣空間
	
	GenerateNumbers(Ha, DataSize, 2);		//產生矩陣資料
	//GenerateNumbers(Hb, DataSize, 6);		//產生矩陣資料

	
	/* dim3 由CUDA提供的三維向量型態 (X,Y,Z)
		CUDA限制每個block的thread上限為1024, (X*Y*Z)<=1024
		grid的block上限為65535, (X*Y)<=65535.  block最多2維而已
	*/	
	dim3 block(DataSize/2, 1, 1);			//配置thread維度、大小  
	dim3 grid(2, 1, 1);						//配置block維度、大小	

	
	
	int *Da, *Dc; //GPU
	cudaMalloc((void**)&Da, size);			//配置GPU矩陣空間
	//cudaMalloc((void**)&Db, size);			//配置GPU矩陣空間
	cudaMalloc((void**)&Dc, size);			//配置GPU矩陣空間

	cudaMemcpy(Da, Ha, size, cudaMemcpyHostToDevice);		//複製資料到GPU
	//cudaMemcpy(Db, Hb, size, cudaMemcpyHostToDevice);		//複製資料到GPU

	Compare_A <<< grid, block >>> (Da, Dc);			//呼叫kernel
	cudaThreadSynchronize();

	cudaMemcpy(Hc, Dc, size, cudaMemcpyDeviceToHost);		//複製資料(比較後的結果)回CPU

	int i;
	printf("A\n");
	for (i = 0; i < DataSize; i++)
		printf("%3d ", Ha[i]);
	
	//printf("\nB\n");
	//for (i = 0; i < DataSize; i++)
		//printf("%3d ", Hb[i]);
	printf("\nC\n");
	for (i = 0; i < DataSize/2; i++)
		printf("%3d ", Hc[i]);
	printf("\n");

	
	//釋放記憶體空間
		free(Ha); free(Hc);
	
		cudaFree(Da); cudaFree(Dc);
}
