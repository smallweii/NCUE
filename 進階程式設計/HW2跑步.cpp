#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,d,d1,d2,t1,t2;
    
    printf("�п�J�������]���Z��d (��쬰����)�G");
    scanf("%lf",&d);
    printf("�п�J�ҡB�A���B�ʭ����]�B�t��(a, b) (��쬰����/����)�G");
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
    
    printf("�ҹB�ʭ������]�B���ʶ]���Z�����׬��G%.2lf\n",d1);
    printf("�A�B�ʭ������]�B���ʶ]���Z�����׬��G%.2lf\n",d2);
    
    system("pause");
    return 0;
}
