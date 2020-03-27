#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[11];
	int a1,a2,i,n[10],y,d9;
	printf("請輸入身份證字號:");
	scanf("%s",input);
	
	switch(input[0])
	{
		case'A':a1=1,a2=0;
		break;
		case'B':a1=1,a2=1;
		break;
		case'C':a1=1,a2=2;
		break;
		case'D':a1=1,a2=3;
		break;
		case'E':a1=1,a2=4;
		break;
		case'F':a1=1,a2=5;
		break;
		case'G':a1=1,a2=6;
		break;
		case'H':a1=1,a2=7;
		break;
		case'J':a1=1,a2=8;
		break;
		case'K':a1=1,a2=9;
		break;
		case'L':a1=2,a2=0;
		break;
		case'M':a1=2,a2=1;
		break;
		case'N':a1=2,a2=2;
		break;
		case'P':a1=2,a2=3;
		break;
		case'Q':a1=2,a2=4;
		break;
		case'R':a1=2,a2=5;
		break;
		case'S':a1=2,a2=6;
		break;
		case'T':a1=2,a2=7;
		break;
		case'U':a1=2,a2=8;
		break;
		case'V':a1=2,a2=9;
		break;
		case'X':a1=3,a2=0;
		break;
		case'Y':a1=3,a2=1;
		break;
	}
	for(i=1;i<=9;i++)
	{
		n[i]=(int)input[i]-(int)'0';
	}
	y=a1+a2*9+n[1]*8+n[2]*7+n[3]*6+n[4]*5+n[5]*4+n[6]*3+n[7]*2+n[8]*1;
	d9=10-(y%10);
	
	if(d9==10)
	d9=0;
	
	if(d9==n[9])
	printf("身份證字號正確!!");
	else
	printf("身份證字號錯誤!!");
	
	system("pause");
	return 0;
}
