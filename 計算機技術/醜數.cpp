#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,count=1,a;
	printf("Please input a number:");
	scanf("%d",&n);
	printf("1,");
	
	for(i=2;count<=n-1;i++)
	{
		a=i;
		
		while(a%2==0)
		a/=2;
		
		while(a%3==0)
		a/=3;
		
		while(a%5==0)
		a/=5;
		
		if(a==1)
	    {
           printf("%d,",i);
		   count++;
	    }
	}
	system("pause");
	return 0;
}
