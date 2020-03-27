#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp=fopen("output.txt","w");
	for(int i=0;i<=2;i++)
	{
	   if(i)
	      fprintf(fp,"\n");
	   for(int j=1;j<=9;j++)
	   {
	      for(int k=i*3+1;k<=i*3+3;k++)
	         fprintf(fp,"%2d * %2d = %2d\t",k,j,k*j);
	      fprintf(fp,"\n");
	   }
	}
	fclose(fp);
	system("pause");
	return 0;
}
