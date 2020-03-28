#include <stdio.h>
#include <stdlib.h>

int main()
{
    int counta=0,counte=0,counti=0,counto=0,countu=0;
    char ch;
    
    FILE *DataIn;
    FILE *DataOut;
    DataIn=fopen("t1.txt","r");
    DataOut=fopen("t2.txt","w");
    if(DataIn!=NULL && DataOut!=NULL)
    {
       while((ch=fgetc(DataIn))!=EOF)
       {
          if(ch=='A'||ch=='a') counta++;
          if(ch=='E'||ch=='e') counte++;
          if(ch=='I'||ch=='i') counti++;
          if(ch=='O'||ch=='o') counto++;
          if(ch=='U'||ch=='u') countu++;
       }
    }
    fprintf(DataOut,"A\tE\tI\tO\tU\n");
    fprintf(DataOut,"%d\t%d\t%d\t%d\t%d",counta++,counte++,counti++,counto++,countu++);
    fclose(DataIn);
    fclose(DataOut);
    system("pause");
    return 0;
}
