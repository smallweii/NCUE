#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,j,a[1000],count=0;
	
	printf("Please input a number:");
	scanf("%d",&n);
    for(i=2;i<=n;i++)
	    {
		   for(j=2;j<=n-1;j++)
		   {
			   if(i%j==0)
			   break;
		   }
		   if(j!=i)
		   a[i]=i;
	    }
	for(i=0;i<=n;i++)
	{
	   if(a[i+1]-a[i]==1&&a[i+2]-a[i+1]==1&&a[i+3]-a[i+2]==1)
	   {
	      printf("(%d,%d,%d,%d)",a[i],a[i+1],a[i+2],a[i+3]);
	      count++;
	   }
    }
	printf("\n%d times!!",count);
	system("pause");
	return 0;
}
