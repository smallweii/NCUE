#include <iostream>  
#include <cstring>  
using namespace std;  
int m[10][10]; // �̦h10x10  
int max3(int n, int k, string s)   
{  
   if(n==k) return  ( m[ k ][ s[0]-'0' ] );  
   int c=n-k , r , x = 0;   // x�^�ǳ̤j��x  
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
   int r[10],c[10];  // r[]��C�U�C�̤j�ȡAc[]����U��̤j��  
   int t , g , n ,i,j,k;  
   bool fsl=true;  // �Ĥ@�դ��e���ΪŦC  
   cin >> t;  
   for( g = 1 ; g <= t ; ++g )  
   {  
      memset(r,0,sizeof(r));  
      memset(c,0,sizeof(c));  
      cin >> n; // �U n����ͤp�j  
      for(i=0; i<n; ++i) //�Ѥ��� ���~�@��� ��W i+1   
      {  
          for(j=0; j<n; ++j) //�Ѥ��� ���~�@��� ��W i+1 
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
      cout << "��" << g << "�մ��ո�Ƶ��G" << endl;  
      cout << "(1)���Ҧ����ͳ��̺��N���u�t�t�{�סv�`����" 
           << rsco << "��" << endl;  
      cout << "(2)���Ҧ��p�j���̺��N���u�t�t�{�סv�`����" 
           << csco << "��" << endl;  
      string s="0123456789"; // �̦h10��  
      cout << "(3)���������̰��u�t�t�{�סv�`����" 
           << max3(n-1, 0 , s.substr(0,n) ) << "��" << endl;  
   }  
   return 0 ;   
}
