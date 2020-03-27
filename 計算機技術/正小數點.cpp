#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int len1,len2,i,j,a,b,n1[20]={0},n2[20]={0},n3[20]={0},n4[20]={0},x,y,m=74,n=74,sum1[42]={0},sum2[42]={0},carry=0;
	char input1[42],input2[42];
	
	printf("Please input number #1:");
	scanf("%s",input1);
	printf("Please input number #2:");
	scanf("%s",input2);
	
	len1=strlen(input1);
	len2=strlen(input2);
	
	for(i=0;i<=len1-1;i++)
	   if(input1[i]=='.')
	      break;
	      
	for(j=0;j<=len2-1;j++)
	   if(input2[j]=='.')
	      break;
	
	for(a=i-1,b=19;a>=0;a--,b--)//俱计 
	   n1[b]=(int)input1[a]-(int)'0';
	   
	for(a=j-1,b=19;a>=0;a--,b--)
	   n2[b]=(int)input2[a]-(int)'0';
	   
	for(a=i+1,b=0;a<=len1-1;a++,b++)//计 
	   n3[b]=(int)input1[a]-(int)'0';
	   
	for(a=j+1,b=0;a<=len2-1;a++,b++)
	   n4[b]=(int)input2[a]-(int)'0';
    
	for(y=19;y>=0;y--)//计 
	{
	   sum2[y]=n3[y]+n4[y]+carry;
	   carry=0;
	   if(sum2[y]>9)
	   {
	      sum2[y]%=10;
	      carry=1;
	   }
	}
	//计秈俱计 
	for(x=19;x>=0;x--)//俱计 
	{
	   sum1[x]=n1[x]+n2[x]+carry;
	   carry=0;
	   if(sum1[x]>9)
	   {
	      sum1[x]%=10;
		  carry=1;
	   }
	}
	
	for(x=0;x<=19;x++)//т獶0俱计 
	   if(sum1[x]!=0)
	   {
	      m=x;
	      break;
	   }  
	    
	for(y=19;y>=0;y--)//т獶0计 
	   if(sum2[y]!=0)
	   {
	      n=y;
	      break;
	   }
	   
	if(m!=74&&n!=74)
	{
	   printf("The sum is ");
	   
	   for(x=m;x<=19;x++)
	      printf("%d",sum1[x]);
		  	  
 	   printf(".");
 	   
       for(y=0;y<=n;y++)
	      printf("%d",sum2[y]);
	      
	   printf("\n");
	}
	
	if(m==74)//0.123
	{
	   printf("The summ is 0.");
	   
	   
	   for(y=0;y<=n;y++)
	      printf("%d",sum2[y]);
	      
	   printf("\n");
	}
	
	if(n==74)//123
	{
	   printf("The summm is ");
	   
	   
	   for(x=m;x<=19;x++)
	      printf("%d",sum1[x]);
	      
	   printf("\n");
	}
	
	system("pause");
	return 0;
}
