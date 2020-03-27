#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count[100]={0},j,i,n=-1;
    char word[100][20],input[20];
    
    FILE *DataIn;
    FILE *DataOut;
    DataIn=fopen("t3.txt","r");
    DataOut=fopen("t4.txt","w");
    if(DataIn!=NULL && DataOut!=NULL)
    {
       while(fscanf(DataIn,"%s",input)==1)
       {
           j=strlen(input);
           if(input[j-1]==','||input[j-1]=='.')
              input[j-1]='\0';
    
           for(i=0;i<=n;i++)
           {
               if(strcmp(word[i],input)==0)
               {
                   count[i]++;
                   break;
               }
           }
           if(i>n)
           {
               n++;
               strcpy(word[n],input);
               count[n]++;
           }
       }
       for(i=0;i<=n;i++)
          fprintf(DataOut,"%s:%d\n",word[i],count[i]);
    }
    fclose(DataIn);
    fclose(DataOut);
    system("pause");
    return 0;
}
