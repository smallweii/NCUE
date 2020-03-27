#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100],b[100];
	int na,nb,i,j,count=0;
	printf("Please input the string 1:");
	scanf("%s",a);
	printf("Please input the string 2:");
	scanf("%s",b);
	
	na=strlen(a);
	nb=strlen(b);
	
	for(i=0;i<=na-1;i++)
	{
		for(j=0;j<=nb-1;j++)
		{
			if(a[j+i]==b[j])
			{
				if(j==nb-1)
				count++;
			}
			else
			break;
		}
	}
	if(count>0)
	{
		printf("String 2 is a substring of string 1\n");
		printf("Repeat %d times",count);
	}
	else
	printf("String 2 is not a substring of string 1");
	
	system("pause");
	return 0;
}
