#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,a[4];
	printf("請輸入介於1~3999之間的整數:");
	scanf("%d",&n);
	printf("\n轉成羅馬數字為 ");
	
	a[3]=n%10;
	n/=10;
	a[2]=n%10;
	n/=10;
	a[1]=n%10;
	a[0]=n/10;
	
	if(a[0]==1) printf("M");
	if(a[0]==2) printf("MM");
	if(a[0]==3) printf("MMM");
	
	if(a[1]==1) printf("C");
	if(a[1]==2) printf("CC");
	if(a[1]==3) printf("CCC");
	if(a[1]==4) printf("CD");
	if(a[1]==5) printf("D");
	if(a[1]==6) printf("DC");
	if(a[1]==7) printf("DCC");
	if(a[1]==8) printf("DCCC");
	if(a[1]==9) printf("CM");
	
	if(a[2]==1) printf("X");
	if(a[2]==2) printf("XX");
	if(a[2]==3) printf("XXX");
	if(a[2]==4) printf("XL");
	if(a[2]==5) printf("L");
	if(a[2]==6) printf("LX");
	if(a[2]==7) printf("LXX");
	if(a[2]==8) printf("LXXX");
	if(a[2]==9) printf("XC");
	
	if(a[3]==1) printf("I");
	if(a[3]==2) printf("II");
	if(a[3]==3) printf("III");
	if(a[3]==4) printf("IV");
	if(a[3]==5) printf("V");
	if(a[3]==6) printf("VI");
	if(a[3]==7) printf("VII");
	if(a[3]==8) printf("VIII");
	if(a[3]==9) printf("IX");
	
	system("pause");
	return 0;
}
