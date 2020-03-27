#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,a[4],i;
	printf("請輸入介於1~3999之間的整數:");
	scanf("%d",&n);
	printf("\n轉成羅馬數字為 ");
	
	a[0]=n/1000;
	n%=1000;
	a[1]=n/100;
	n%=100;
	a[2]=n/10;
	a[3]=n%10;
	
	if(1<=a[0]&&a[0]<=3)
	{
		for(i=1;i<=a[0];i++)
		printf("M");
	}
	if(1<=a[1]&&a[1]<=3)
	{
		for(i=1;i<=a[1];i++)
		printf("C");
	}
	if(a[1]==4) printf("CD");
	if(a[1]==5) printf("D");
	if(6<=a[1]&&a[1]<=8)
	{
		printf("D");
		for(i=6;i<=a[1];i++)
		printf("C");
	}
	if(a[1]==9) printf("CM");
	if(1<=a[2]&&a[2]<=3)
	{
		for(i=1;i<=a[2];i++)
		printf("X");
	}
	if(a[2]==4) printf("XL");
	if(a[2]==5) printf("L");
	if(6<=a[2]&&a[2]<=8)
	{
		printf("L");
		for(i=6;i<=a[2];i++)
		printf("X");
	}
	if(a[2]==9) printf("XC");
	if(1<=a[3]&&a[3]<=3)
	{
		for(i=1;i<=a[3];i++)
		printf("I");
	}
	if(a[3]==4) printf("IV");
	if(a[3]==5) printf("V");
	if(6<=a[3]&&a[3]<=8)
	{
		printf("V");
		for(i=6;i<=a[3];i++)
		printf("I");
	}
	if(a[3]==9) printf("IX");
	
	system("pause");
	return 0;
}
