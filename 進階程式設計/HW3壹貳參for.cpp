#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100][2],t[100][3]={0};
    int u[30]={0};
    long long int i,j,sum=0,total=0,total1=0,total2=0,total3=0,total4=0,total5=0;
    
    printf("¿é¤J¡G");
    scanf("%s", s);
    printf("¿é¥X¡G%s = ",s);
    
    for(i=0;i<100;i++)
       for(j=0;j<2;j++)
       {
          t[i][j]=s[i][j];
       }
    if(strcmp(t[0],"­t")==0)
       printf("-");
    
	for(i=0;i<100;i++)
    {
	   if(strcmp(t[i],"¹s")==0)
	      sum=0;
	   else if(strcmp(t[i],"³ü")==0)
          sum=1;
       else if(strcmp(t[i],"¶L")==0)
          sum=2; 
       else if(strcmp(t[i],"°Ñ")==0)
          sum=3; 
       else if(strcmp(t[i],"¸v")==0)
          sum=4; 
       else if(strcmp(t[i],"¥î")==0)
          sum=5; 
       else if(strcmp(t[i],"³°")==0)
          sum=6; 
       else if(strcmp(t[i],"¬m")==0)
          sum=7; 
       else if(strcmp(t[i],"®Ã")==0)
          sum=8; 
       else if(strcmp(t[i],"¨h")==0)
          sum=9;
	   else if(strcmp(t[i],"¬B")==0)
       {
		  total1=10*sum;
          sum=0;
       }
       else if(strcmp(t[i],"¨Õ")==0)
       {
          total2=100*sum;;
          sum=0;
       }
       else if(strcmp(t[i],"¥a")==0)
       {
          total3=1000*sum;
		  sum=0;
       }
       else if(strcmp(t[i],"¸U")==0)
       {
          total4=sum;
		  sum=total1+total2+total3+total4;
		  sum*=10000;
		  total4=sum;
          sum=0;
          total1=0;
          total2=0;
          total3=0;
       }
       else if(strcmp(t[i],"»õ")==0)
       {
          total5=sum;
          sum=total1+total2+total3+total5;
          sum*=100000000;
          total5=sum;
          sum=0;
          total1=0;
          total2=0;
          total3=0;
       }
	}
	total=sum+total1+total2+total3+total4+total5;
	
	for(i=0;total!=0;i++)
	{
       u[i]=total%10;
       total/=10;
    }
    for(i=29;i>=0;i--)
    {
       if(u[i]!=0)
          break;    
    }
    for(j=i;j>=0;j--)
    {
       printf("%d",u[j]);
       if(j%3==0 && j!=0)
          printf(",");
    }
    printf("\n");
    system("pause");
    return 0;
}
