#include <stdio.h>
#include <stdlib.h>
static double sumx=0;
static double sumy=0;

void spot(double a,double b,double d,int x)
{
    double x1,x2,y1,y2;
    
    x1=a+d/2;
    x2=a-d/2;
    y1=b+d/2;
    y2=b-d/2;
    
    if(x<0)
       return;
    else
    {
       if(x1>0&&y1>0)
       {
          sumx+=x1;
          sumy+=y1;
       }
       
       if(x1>0&&y2>0)
       {
          sumx+=x1;
          sumy+=y2;
       }
       
       if(x2>0&&y1>0)
       {
          sumx+=x2;
          sumy+=y1;
       }
       
       if(x2>0&&y2>0)
       {
          sumx+=x2;
          sumy+=y2;
       }
       
       spot(x1,y1,d/2,x-1);
       spot(x1,y2,d/2,x-1);
       spot(x2,y1,d/2,x-1);
       spot(x2,y2,d/2,x-1);
    }
}

int main()
{
    double a,b,d;
    int x;
    
    printf("請輸入正方形中心點座標(a,b)：");
    scanf("%lf %lf",&a,&b);
    printf("請輸入正方形每邊長度d：");
    scanf("%lf",&d);
    printf("請輸入重覆次數x：");
    scanf("%d",&x);
    
    spot(a,b,d,x);
    
    printf("X軸座標值總合為：%.0lf\n",sumx);
    printf("Y軸座標值總合為：%.0lf\n",sumy);
    
    system("pause");
    return 0;
}
