#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   int count[100]={0},j,i,n=-1,temp2;
   char word[100][20],input[20],temp[100][20];
 
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
     for(j=0;j<n-1;j++)
        for(i=0;i<n-1;i++)
           if(strcmp(word[i],word[i+1])==1)
           {
              strcpy(temp[i],word[i]); 
              strcpy(word[i],word[i+1]);
              strcpy(word[i+1],temp[i]);
              
              temp2=count[i];
              count[i]=count[i+1];
              count[i+1]=temp2;
           }
     for(i=0;i<=n;i++)
     fprintf(DataOut,"%s:%d\n",word[i],count[i]);  
   }
   fclose(DataIn);
   fclose(DataOut);
   system("pause");
   return 0;
}
