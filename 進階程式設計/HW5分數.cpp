#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}

void print(int s, int m)
{
	int bring;					 
	if(s>m && s%m!=0)// 37/6
    {
        bring=s/m;
		s%=m;
        printf("%d %d/%d",bring,s,m);
	}
	else if(s>=m && s%m==0)// 12/6 or 6/6
	{
		bring=s/m;
		printf("%d",bring);
	}
	else if(s<m)// 1/6 or 0/1
	{
		if(s!=0)
		   printf("%d/%d",s,m);
		else
		   printf("0");
	}
	printf("\n");
}

int main()
{
    int a,b,c,e,f,g,son,mom,s,m;
    char d;
    
    FILE *DataIn;
    DataIn = fopen("T5.txt","r");
    printf("VALUE1\tOP\tVALUE2\t\tANSWER\n");
    printf("---------------------------------------\n");
    if(DataIn != NULL)
    {
       while(fscanf(DataIn,"%d %d %d %c %d %d %d",&a,&b,&c,&d,&e,&f,&g) != EOF)
       {
		  if(a!=0)
		     printf("%d ",a);
		  else
		     printf("  ");
		  if(b!=0)
		     printf("%d/%d\t%c\t",b,c,d);
		  else
		     printf("   \t%c\t",d);
		  if(e!=0)
		     printf("%d ",e);
		  else
		     printf("  ");
		  if(f!=0)
		     printf("%d/%d\t=\t",f,g);
		  else
		     printf("   \t=\t");
		     
		  switch(d)
          {
             case'+':
                     son=(a*c+b)*g+(e*g+f)*c;
                     mom=c*g;
                     s=son/gcd(son,mom);
                     m=mom/gcd(son,mom);
                     print(s,m);
					 break;   
             case'-':
             	     son=(a*c+b)*g-(e*g+f)*c;
                     mom=c*g;
                     s=son/gcd(son,mom);
                     m=mom/gcd(son,mom);
                     print(s,m);
					 break;   
             case'*':
             	     son=(a*c+b)*(e*g+f);
                     mom=c*g;
                     s=son/gcd(son,mom);
                     m=mom/gcd(son,mom);
                     print(s,m);
					 break;
             case'/':
			         son=(a*c+b)*g;
                     mom=c*(e*g+f);
					 s=son/gcd(son,mom);
                     m=mom/gcd(son,mom);
                     print(s,m);
					 break;
          }
       } 
    }
    fclose(DataIn);
    system("pause");
    return 0;
}
