#include<iostream>
#include<string>
using namespace std;

int main()
{ 
	string input,str;
	long long int point=0,a,b=1,c=0,sum=0,i,j,ans[30]={0};
	
	cout<<"��J:"; 
	cin>>input;
	cout<<"��X:"<<input<<"=";
	str=input.substr(point,2);//��M�����r��s1.substr(�_�l��m�A�r�����) 
	
	if(str=="�t")
	{
		cout<<"-";
		point+=2;
	}
	while(str!="\0")
	{
		c=0;
		str=input.substr(point,2);
		point+=2;
		while(str!="��" && str!="��" && str!="�U" && str!="\0")
		{
			if(str=="��")
			  a=1;    
			else if(str=="�L")
			  a=2;    
			else if(str=="��")
			  a=3;    
			else if(str=="�v")
			  a=4;    
			else if(str=="��") 
			  a=5;
	        else if(str=="��") 
			  a=6;    
			else if(str=="�m")
			  a=7;    
			else if(str=="��") 
		      a=8;    
			else if(str=="�h") 
			  a=9;    
			else if(str=="�s") 
			  a=0;
			str=input.substr(point,2);
			point+=2;
			if(str=="�B")
			  b=10;   
			else if(str=="��") 
			  b=100;  
			else if(str=="�a") 
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
	    if(str=="��") 
		    sum+=c*1000000000000; 
		else if(str=="��") 
		    sum+=c*100000000; 
		else if(str=="�U") 
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
