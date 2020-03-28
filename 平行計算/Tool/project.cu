#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define DataSize 1024
__global__ void Mirror(unsigned int *Da, unsigned int *Dc, int high,int width)
{
	int tx = threadIdx.x;           
	int bx = blockIdx.x;			
	int bn = blockDim.x;
	int id = bx*bn+tx;
        
    Dc[id] = Da[bx * bn + bn - 1 - tx];
}
__global__ void Filter_func(unsigned int *Da, unsigned int *Dc, int high,int width, unsigned int *Filter, int filtersum)
{
	int tx = threadIdx.x;           
	int bx = blockIdx.x;			
	int bn = blockDim.x;
	int id = bx*bn+tx;
 	
 	__shared__ unsigned int share[512 * 3];
 	
    if(bx == 0 || bx == bn - 1){
        if(bx == 0){
            share[tx + bn] = Da[id];
            share[tx + 2* bn] = Da[id + bn];
        }else{
            share[tx + bn] = Da[id];
            share[tx] = Da[id - bn]; 
        }
    }else{
        share[tx] = Da[id - bn];
        share[tx + bn] = Da[id];
        share[tx + 2 * bn] = Da[id + bn];
    }
    __syncthreads();
        
    int sum = 0;
        
    if(bx != 0 && tx % 512 != 0) // ���W�S�W�X�d��
	    sum += Filter[0] * share[tx - 1];	

    if(bx != 0) // �W���S�W�X�d��
        sum += Filter[1] * share[tx];

    if(bx != 0 && (tx + 1) % 512 != 0) // �k�W�S�W�X�d��
        sum += Filter[2] * share[tx + 1];

    if(tx % 512 != 0) // ����S�W�X�d��
        sum += Filter[3] * share[tx + bn - 1];

    sum += Filter[4] * share[tx + bn];

    if((tx + 1) % 512 != 0) // �k��S�W�X�d��
        sum += Filter[5] * share[tx + bn + 1];

    if(bx != bn - 1 && tx % 512 != 0) // ���U�S�W�X�d�� 
        sum += Filter[6] * share[tx + 2 * bn - 1];

    if(bx != bn - 1) // �U���S�W�X�d��
        sum += Filter[7] * share[tx + 2 * bn];

    if(bx != bn - 1 && (tx + 1) % 512 != 0) // �k�U�S�W�X�d��
        sum += Filter[8] * share[tx + 2 * bn + 1];
     
    Dc[id] = sum / filtersum;
}        
int main()
{
	FILE *fp = NULL;
	unsigned int high, width, offset, nthread, nblock;
	unsigned char *head;
	unsigned char *img;
    unsigned int *da;
    unsigned int filter[9] = {1,2,1,2,4,2,1,2,1};
    char c, sel;
        
    printf("What do you want to do?\n(a)Filter the picture\n(b)Mirror the picture\n");
    scanf("%c", &sel);
    getchar();
    
    if(sel == 'A' || sel == 'a'){
        printf("Do you want to input filter values by yourself? (Y/N)\n");
        scanf("%c", &c);
    	getchar();
    
        if(c == 'Y' || c == 'y'){
            printf("Please input 9 filter values:\n");
            for(int i = 0; i < 9; ++i)
                scanf("%d", &filter[i]);
                getchar();
        }
    }
	high = 0;
	width = 0;
	offset = 0;

	fp = fopen("lena.bmp","rb"); // rb�Oread binary

	fseek(fp, 10, SEEK_SET); // ���в���fp�q�Y�⪺��10��byte�A�]��offset��bheader����10~13��byte
	fread(&offset, sizeof(unsigned int), 1, fp); // �qfpŪ1��unsigned int���j�p�s��offset

	fseek(fp, 18, SEEK_SET); // ���в���fp�q�Y�⪺��18��byte�A�]��width��bheader����18~21��byte
	fread(&width, sizeof(unsigned int), 1, fp); // �qfpŪ1��unsigned int���j�p�s��width

	fseek(fp, 22, SEEK_SET); // ���в���fp�q�Y�⪺��22��byte�A�]��high��bheader����22~25��byte
	fread(&high, sizeof(unsigned int), 1, fp); // �qfpŪ1��unsigned int���j�p�s��high

	img = (unsigned char*)malloc(sizeof(unsigned char)*(width*high)); // �t�m�@��width*high��byte�Ƥj�p��img(unsigned char�O1byte)
    da = (unsigned int*)malloc(sizeof(unsigned int)*(width*high));
	fseek(fp, offset, SEEK_SET); // ���в���fp�q�Y��offset��byte����m�A�]��offset�s����m�O�}�l�spixel����m
	fread(img, sizeof(char), (width*high), fp); // �qfpŪwidth*high��char���j�p(=unsigned char���j�p)�s��img

	head =(unsigned char*)malloc(sizeof(unsigned char)*(offset)); // �t�m�@��offset��byte�Ƥj�p��img
	fseek(fp, 0, SEEK_SET); // ���в���fp���@�}�l�A�q�Y����m��offset����m�O����Y��
	fread(head, sizeof(unsigned char), offset, fp); // �qfpŪoffset��unsigned char���j�p(=unsigned char���j�p)�s��head
	
    if(width > 1024){ // ���_�ӭn����width*high�Athread���פ���W�L1024
        nthread = 1024; 
        nblock = high * width / 1024;
    }else{
        nthread = width;
        nblock = high;
    }
	dim3 block(nthread, 1, 1); 
    dim3 grid(nblock, 1, 1);
	
    for(int i = 0; i < high * width; ++i)
        da[i] = img[i];

    int filtersum = 0;
    for(int i = 0; i < 9; ++i)
        filtersum += filter[i];

	unsigned int *Da;
	cudaMalloc((void**)&Da, (sizeof(unsigned int)*(width*high)));
    unsigned int *Dc;
	cudaMalloc((void**)&Dc, (sizeof(unsigned int)*(width*high)));
    unsigned int *Filter;
	cudaMalloc((void**)&Filter, (sizeof(unsigned int)*9));
	
	cudaMemcpy(Da, da, (sizeof(unsigned int)*(width*high)), cudaMemcpyHostToDevice);
    if(sel == 'A' || sel == 'a'){
	    Filter_func <<< nblock, nthread >>> (Da,Dc,high,width,Filter,filtersum);
        cudaMemcpy(Filter, filter, (sizeof(unsigned int)*9), cudaMemcpyHostToDevice);
    }else if(sel == 'B' || sel == 'b'){
        Mirror <<< nblock, nthread >>> (Da,Dc,high,width);
    }
	cudaThreadSynchronize();
    cudaMemcpy(da, Dc, (sizeof(unsigned int)*(width*high)), cudaMemcpyDeviceToHost);	

    for(int i = 0; i < high * width; ++i)
        img[i] = da[i];
      
	fp = fopen("lena3.bmp","wb+");
	fwrite(head, sizeof(unsigned char), offset, fp);
	fwrite(img, sizeof(unsigned int), (width*high), fp);
	fclose(fp);
}
