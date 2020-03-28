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

__global__ void Add_A(int *Da)//kernel function
{
	int tx = threadIdx.x;     //thread的x軸id
	int bx = blockIdx.x;	    //block的x軸id
	int bn = blockDim.x;		//block的x軸有幾個thread
	int id = bx*bn+tx;		//計算矩陣座標
	
	/*int i = DataSize/2;
	while (i != 0) {
	    if (id < i)
		    Da[id] += Da[id + i];
		__syncthreads();
		i /= 2;
	}*/
	
	int i = DataSize/2;
	for(int j = 0; j < 4; j++) { // log16=4
        if (id < i)
            Da[id] += Da[id + i];
        __syncthreads( );
		i /= 2;
    }
}

int main()
{
	int *Ha; //CPU
	int size = DataSize * sizeof(int);
	
	Ha = (int*)malloc(size);				//配置矩陣空間
	GenerateNumbers(Ha, DataSize, 2);		//產生矩陣資料

	/* dim3 由CUDA提供的三維向量型態 (X,Y,Z)
		CUDA限制每個block的thread上限為1024, (X*Y*Z)<=1024
		grid的block上限為65535, (X*Y)<=65535.  block最多2維而已
	*/	
	dim3 block(DataSize/2, 1, 1);			//配置thread維度、大小  
	dim3 grid(2, 1, 1);		//配置block維度、大小	
	
    int i;
	printf("A\n");
	for (i = 0; i < DataSize; i++)
		printf("%3d ", Ha[i]);
		
	int *Da; //GPU
	cudaMalloc((void**)&Da, size);			//配置GPU矩陣空間
	cudaMemcpy(Da, Ha, size, cudaMemcpyHostToDevice);		//複製資料到GPU

	Add_A <<< grid, block >>> (Da);			//呼叫kernel
	cudaThreadSynchronize();
	
	cudaMemcpy(Ha, Da, size, cudaMemcpyDeviceToHost);		//複製資料(比較後的結果)回CPU
	
	printf("\n%3d\n", Ha[0]);

	//釋放記憶體空間
		free(Ha);
	
		cudaFree(Da);
}
