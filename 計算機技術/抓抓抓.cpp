#include <stdio.h>
#include <stdlib.h>

int main()
{
	int j;
	
	printf("enter an integer:");
	while(scanf("%d",&j)!=1){
	   while(getchar()!='\n')
	      ;
	   printf("enter an integer:");
	} 
	printf("j=%d",j);
	
	system("pause");
	return 0;
}
