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

int main()
{
	int n;
	
	printf("�п�JA�W�������Ӽ�:");
	scanf("%d",&n);
	
	towers(n,'A','B','C');
	printf("�@��%d�ӨB�J",count);
	
	system("pause");
	return 0;
}
