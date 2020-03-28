#include <iostream>
using namespace std;

int main()
{
    int num,a,b,c,min,sum;
    
    FILE *DataIn;
    DataIn = fopen("T8.txt","r");
    if(DataIn != NULL)
    {
       if((fscanf(DataIn,"%d",&num)) == 1)
       {
          cout << "块" << endl;
          while(fscanf(DataIn,"%d %d %d",&a,&b,&c) != EOF)
          {
             min=a*50+b*80+c*100;
             for(int i=0;i<=a;i+=2)
                for(int j=0;j<=b;j+=2)
                {
				   sum=a*50+b*80+c*100;
				   sum-=25*i/2;
				   sum-=80*j/2;
				   sum-=(sum/1100)*100;
                   
				   if(sum < min)
                      min=sum;
                      
                   /*if(i%2 == 0)             //Α案计  
                      price_a=(i/2)*75;
                   else                     //Α计  
                      price_a=(i-1)/2*75+50;
                   sum=sum+price_a+(a-i)*50;
                      
                   if(j%2 == 0)             //竡Α案计  
                      price_b=(j/2)*80;
                   else                     //竡Α计  
                      price_b=(j+1)/2*80;
                   sum=sum+price_b+(b-j)*80;
             
                   z=c*100;
                   if(sum>=1000 && c>0)     //骸癳疭秸  
                   {
                      free=(sum/1000)*100;
                      if(free>=z)
                         sum=sum;
                      else
                         sum=sum+(z-free);
                   }
                   else if(sum<1000 && c>0) //⊿骸 
                      sum+=z;*/
                }
             cout << min << endl; 
          }
       }
    }
    fclose(DataIn);
    system("pause");
    return 0;
}
