#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,week,y,day[12]={31,28,31,30,31,30,31,31,30,31,30,31},m,d,count=0;
    
    printf("Plaese input a number:");
    scanf("%d",&n);
    
    for(y=((n-1)*100+1);y<=n*100;y++)
    {
       week=(y+(int)((y-1)/4)-(int)((y-1)/100)+(int)((y-1)/400))%7;
       if(y%4==0)
       {
          if(y%100==0)
          {
             if(y%400==0)
                day[1]=29;
             else
                day[1]=28;
          }
          else
             day[1]=29;
       }
       else
          day[1]=28;
       for(m=0;m<=11;m++)
          for(d=1;d<=day[m];d++)
          {
             if(week%7==5&&d==13)
             count++;
             week++;
          }
    }
    printf("%d times!!",count);
    system("pause");
    return 0;
}
