#include<iostream>
#include<string>
using namespace std;

int main()
{ 
	string input,str;
	long long int point=0,a,b=1,c=0,sum=0,i,j,ans[30]={0};
	
	cout<<"块:"; 
	cin>>input;
	cout<<"块:"<<input<<"=";
	str=input.substr(point,2);//т碝场だ﹃s1.substr(癬﹍竚﹃) 
	
	if(str=="璽")
	{
		cout<<"-";
		point+=2;
	}
	while(str!="\0")
	{
		c=0;
		str=input.substr(point,2);
		point+=2;
		while(str!="" && str!="货" && str!="窾" && str!="\0")
		{
			if(str=="滁")
			  a=1;    
			else if(str=="禠")
			  a=2;    
			else if(str=="把")
			  a=3;    
			else if(str=="竩")
			  a=4;    
			else if(str=="ヮ") 
			  a=5;
	        else if(str=="嘲") 
			  a=6;    
			else if(str=="琺")
			  a=7;    
			else if(str=="") 
		      a=8;    
			else if(str=="╤") 
			  a=9;    
			else if(str=="箂") 
			  a=0;
			str=input.substr(point,2);
			point+=2;
			if(str=="珺")
			  b=10;   
			else if(str=="ㄕ") 
			  b=100;  
			else if(str=="") 
			  b=1000; 
			else
			{
			    b=1; 
			    point-=2;
			}
			c+=a*b;   	
		    str=input.substr(point,2);
			point+=2;
		}
	    if(str=="") 
		    sum+=c*1000000000000; 
		else if(str=="货") 
		    sum+=c*100000000; 
		else if(str=="窾") 
		    sum+=c*10000; 
		else
		{
		    sum+=c; 
		    point-=2;
		}
	    str=input.substr(point,2);
	    if(str=="\0")
		    break;
	}
    for(i=0;sum!=0;i++)
	{
    	ans[i]=sum%10;
    	sum/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		cout<<ans[j];
		if(j%3==0&&j!=0&&j!=i)
			cout<<",";
	}
	cout<<endl;
	system("pause");
	return 0;
} 
