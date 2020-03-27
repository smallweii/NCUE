#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input1[50],input2[50],input3[50];
    int num,n,i,sum=0;
    
    FILE *DataIn;
    DataIn=fopen("T4.txt","r");
    if(DataIn!=NULL)
    {
       if((fscanf(DataIn,"%d",&num))==1)
       {
          while(fscanf(DataIn,"%s",input1)==1&&fscanf(DataIn,"%s",input2)==1)
          {
             sum=0;
             n=strlen(input1);
             for(i=0;i<n;i++)
             {
                input1[i]=(int)input1[i]-(int)'0';
                input2[i]=(int)input2[i]-(int)'0';
                input3[i]=input1[i]-input2[i];
                if(input3[i]<0)
                {
                   input3[i]*=-1;
                }
                sum+=input3[i];
             }
             printf("%d\n",sum);
          }
       } 
    }
    fclose(DataIn);
    system("pause");
    return 0;
}
