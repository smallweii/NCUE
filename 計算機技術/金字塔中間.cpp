#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c,d,e;
	
	printf("Please input a number:");
	scanf("%d",&a);
	
	for(b=1;b<=a;b++)
	{
	    for(c=1;c<=a-b;c++)
	    printf(" ");
	    
	    for(d=1;d<=b;d++)
	    printf("%d",b%10);
	   	
	    for(e=b-1;e>=1;e--)
	    printf("%d",b%10);
	    
		printf("\n");
    }
	system("pause");
	return 0;
}
