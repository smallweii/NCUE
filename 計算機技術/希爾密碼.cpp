#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100],b[100];
	int i,j,k[3][3],n,m,na[100],nb[100];
	
	printf("Please input a 3x3 key matrix (9 integers):");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d",&k[i][j]);
	}
	printf("Please input a string:");
	scanf("%s",a);
	
	n=strlen(a);
	m=n/3;
	
	for(i=0;i<n;i++)
	na[i]=(int)a[i]-(int)'A';
	
	for(i=0;i<m;i++)
	{
		nb[i*3]=(k[0][0]*na[i*3])+(k[0][1]*na[i*3+1])+(k[0][2]*na[i*3+2]);
		nb[i*3]%=26;
		nb[i*3+1]=(k[1][0]*na[i*3])+(k[1][1]*na[i*3+1])+(k[1][2]*na[i*3+2]);
		nb[i*3+1]%=26;
		nb[i*3+2]=(k[2][0]*na[i*3])+(k[2][1]*na[i*3+1])+(k[2][2]*na[i*3+2]);
		nb[i*3+2]%=26;
	}
    
    for(i=0;i<m;i++)
    {
    	b[i*3]=(char)((int)'A'+nb[i*3]);
    	b[i*3+1]=(char)((int)'A'+nb[i*3+1]);
    	b[i*3+2]=(char)((int)'A'+nb[i*3+2]);
	}
    
    printf("The cipher is ");
    for(i=0;i<n;i++)
    printf("%c",b[i]);
	
	system("pause");
	return 0;
}
