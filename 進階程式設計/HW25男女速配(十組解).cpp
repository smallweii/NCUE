#include <iostream>  
#include <cstring>  
using namespace std;  
int m[10][10]; // 最多10x10  
int max3(int n, int k, string s)   
{  
   if(n==k) return  ( m[ k ][ s[0]-'0' ] );  
   int c=n-k , r , x = 0;   // x回傳最大值x  
   for(int i=0; i<=c; ++i)  
   {  
      string s1=s;  
      r= max3( n , k+1 , s1.erase(i,1));  
      r += (m[k][ s[i]-'0' ]);   
      if( r > x ) x = r;  
   }  
   return x;  
}  
int main( )  
{  
   int r[10],c[10];  // r[]橫列各列最大值，c[]直行各行最大值  
   int t , g , n ,i,j,k;  
   bool fsl=true;  // 第一組之前不用空列  
   cin >> t;  
   for( g = 1 ; g <= t ; ++g )  
   {  
      memset(r,0,sizeof(r));  
      memset(c,0,sizeof(c));  
      cin >> n; // 各 n位先生小姐  
      for(i=0; i<n; ++i) //由中央 往外一圈圈 填上 i+1   
      {  
          for(j=0; j<n; ++j) //由中央 往外一圈圈 填上 i+1 
         {  
            cin >> k;  
            m[i][j]=k;  
            if( k>r[i] ) r[i]=k;  
            if( k>c[j] ) c[j]=k;                 
         }  
      }  
      int rsco=0 , csco=0;  
      for( k=0; k<n; ++k )  
      {  
         rsco += r[k];  
         csco += c[k];  
      }  
      if(fsl) fsl=false;   else  cout << endl;  
      cout << "第" << g << "組測試資料結果" << endl;  
      cout << "(1)讓所有先生都最滿意的「速配程度」總分為" 
           << rsco << "分" << endl;  
      cout << "(2)讓所有小姐都最滿意的「速配程度」總分為" 
           << csco << "分" << endl;  
      string s="0123456789"; // 最多10個  
      cout << "(3)完美結局最高「速配程度」總分為" 
           << max3(n-1, 0 , s.substr(0,n) ) << "分" << endl;  
   }  
   return 0 ;   
}
