#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,d,d1,d2,t1,t2;
    
    printf("請輸入此次長跑的距離d (單位為公尺)：");
    scanf("%lf",&d);
    printf("請輸入甲、乙兩位運動員的跑步速度(a, b) (單位為公尺/分鐘)：");
    scanf("%lf %lf",&a,&b);
    
    if(a<b)
    {
       d1=d;
       t1=d/a;
       d2=b*t1;
    }
    else
    {
       d2=d;
       t2=d/b;
       d1=a*t2;
    }
    
    printf("甲運動員此次跑步活動跑的距離長度為：%.2lf\n",d1);
    printf("乙運動員此次跑步活動跑的距離長度為：%.2lf\n",d2);
    
    system("pause");
    return 0;
}
