#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024
__global__ void Add(unsigned char *Da,int high,int width)
{
	int tx = threadIdx.x;           
	int bx = blockIdx.x;			
	int bn = blockDim.x;
	int gn = gridDim.x;
	int id = bx*bn+tx;				

	for(int i=id;i<(high*width);i+=(bn*gn))
		Da[i] = 255 - Da[i];

}
int main()
{
	FILE *fp = NULL;
	unsigned int high, width, offset;
	unsigned char *head;
	unsigned char *img;
	
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

	head =(unsigned char*)malloc(sizeof(unsigned int)*(offset));
	fseek(fp, 0, SEEK_SET);
	fread(head, sizeof(unsigned char), offset, fp);
	
	dim3 block(1024, 1, 1);
	dim3 grid(2, 1, 1);
	
	unsigned char *Da;
	cudaMalloc((void**)&Da, (sizeof(unsigned char)*(width*high)));
	
	cudaMemcpy(Da, img, (sizeof(unsigned char)*(width*high)), cudaMemcpyHostToDevice);
	
	Add <<< grid, block >>> (Da,high,width);
	cudaThreadSynchronize();
	
	cudaMemcpy(img, Da, (sizeof(unsigned char)*(width*high)), cudaMemcpyDeviceToHost);
	
	fclose(fp);

	fp = fopen("lena2.bmp","wb+");
	fwrite(head, sizeof(unsigned char), offset, fp);
	fwrite(img, sizeof(unsigned char), (width*high), fp);
	fclose(fp);

}


