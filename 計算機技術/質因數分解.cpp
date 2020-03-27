#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,m,a[1000];
    
    printf("Please input a number:");
    scanf("%d",&n);
    printf("%d=",n);
          
    while(n!=1)
    {
       for(i=2;i<=n;i++)
       {
          if(n%i==0)
          {
             m=n;
             n/=i;
             if(n!=1)
                printf("%d*",i);
             break;
          }
       }
    }
    printf("%d",m);
    system("pause");
    return 0;
}
