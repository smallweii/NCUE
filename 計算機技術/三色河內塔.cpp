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

void trible_hanoi(int n,char from,char aux,char to)
{
    if(n==3)
    {
       towers(n-1,from,to,aux);
       printf("ring %d:%c=>%c\n",n,from,to);
       count++;
       towers(n-2,aux,to,from);
       return;
    }
    
    towers(n-1,from,to,aux);
    printf("ring %d:%c=>%c\n",n,from,to);
    count++;
    towers(n-3,aux,from,to);
    printf("ring %d:%c=>%c\n",n-2,aux,from);
    count++;
    towers(n-5,to,aux,from);
    printf("ring %d:%c=>%c\n",n-4,to,aux);
    count++;
    
    if(n>6)
       trible_hanoi(n-6,from,aux,to);
}

int main()
{
	int n;
	printf("請輸入A柱中的環個數:");
	scanf("%d",&n);
	trible_hanoi(n,'A','B','C');
	printf("共需%d個步驟",count);
	system("pause");
	return 0;
}
