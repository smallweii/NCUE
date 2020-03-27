#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y1,m1,d1,y2,m2,d2,y,count=0;
    
    printf("請輸入西元開始日期(yyyy/mm/dd)為...");
    scanf("%d/%d/%d",&y1,&m1,&d1);
    printf("請輸入西元結束日期(yyyy/mm/dd)為...");
    scanf("%d/%d/%d",&y2,&m2,&d2);
    
    for(y=y1+1;y<=y2-1;y++)
    {
       if(y%4==0)
       {
          if(y%100==0)
          {
             if(y%400==0)
             count++;
          }
          else
          count++;
       }
    }
    if(y1%4==0)
    {
       if(y1%100==0)
       {
          if(y1%400==0)
          {
             if(m1==1||m1==2)
             count++;
          }
       }
       else
       {
          if(m1==1||m1==2)
          count++;
       }  
    }
    if(y2%4==0)
    {
       if(y2%100==0)
       {
          if(y2%400==0)
          {
             if(m2==2)
             {
                if(d2==29)
                count++;
             }
             else if(m2==3||m2==4||m2==5||m2==6||m2==7||m2==8||m2==9||m2==10||m2==11||m2==12)
             count++;
          }
       }
       else
       {
          if(m2==2)
             {
                if(d2==29)
                count++;
             }
             else if(m2==3||m2==4||m2==5||m2==6||m2==7||m2==8||m2==9||m2==10||m2==11||m2==12)
             count++;
       }  
    }
    printf("此期間的2月29日共有%d次",count);
    system("pause");
    return 0;
}
