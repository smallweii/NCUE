#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,l,spend,min=0,a,b,c,d;
    
    printf("�п�J�����`�H�ơG");
    scanf("%d",&n);
    
    for(i=0;i<=n/4+1;i++)
       for(j=0;j<=n/7+1;j++)
          for(k=0;k<=n/13+1;k++)
          {
             if((n-i*4-j*7-k*13)%16==0&&(n-i*4-j*7-k*13)>=0)
                l=(n-i*4-j*7-k*13)/16;
             else if((n-i*4-j*7-k*13)%16!=0&&(n-i*4-j*7-k*13)>=0)
                l=(n-i*4-j*7-k*13)/16+1;
             
             spend=i*2500+j*3800+k*6400+l*7500;
             if(min==0)
                min=spend;
             if(spend<min)
             {
                min=spend;
                a=i;
                b=j;
                c=k;
                d=l;
             }
          }
    printf("�ֻ̤ݭn%d��\n�|���Ш�%d�x\n�Ӱȥ�Ȩ�%d�x\n�p���ڤh%d�x\n�����ڤh%d�x\n",min,a,b,c,d);
    system("pause");
    return 0;
}
