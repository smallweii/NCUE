#include <stdio.h>
#include <stdlib.h>

static int count=0;

void towers(int n,char from,char aux,char to)
{
	if(n==1)
	{
	   printf("ring %d:%c=>%c\n",n,from,to);
	   count++;
	}
	else
	{
	   towers(n-1,from,to,aux);
	   printf("ring %d:%c=>%c\n",n,from,to);
	   count++;
	   towers(n-1,aux,from,to);
	}
}

void double_hanoi(int n,char from,char aux,char to)
{
    if(n==2)
    {
       towers(n-1,from,to,aux);
       printf("ring %d:%c=>%c\n",n,from,to);
       count++;
       return;
    }
    
    if(n==4)
    {
       towers(n-1,from,to,aux);
       printf("ring %d:%c=>%c\n",n,from,to);
       count++;
       towers(n-3,aux,to,from);
       printf("ring %d:%c=>%c\n",n-2,aux,to);
       count++;
       towers(n-3,from,to,aux);
       return;
    }
    
    towers(n-1,from,to,aux);
    printf("ring %d:%c=>%c\n",n,from,to);
    count++;
    towers(n-3,aux,to,from);
    printf("ring %d:%c=>%c\n",n-2,aux,to);
    count++;
    towers(n-4,from,aux,to);
    printf("ring %d:%c=>%c\n",n-3,from,aux);
    count++;
    
    if(n>6)
    {
       towers(n-6,to,aux,from);
       printf("ring %d:%c=>%c\n",n-5,to,aux);
       count++;
       double_hanoi(n-6,from,aux,to);
	}
}

int main()
{
	int n;
	printf("請輸入A柱中的環個數:");
	scanf("%d",&n);
	double_hanoi(n,'A','B','C');
	printf("共需%d個步驟",count);
	system("pause");
	return 0;
}	
