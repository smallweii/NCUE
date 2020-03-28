#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2,s3,str[6],max;
    
    cout << "輸入：" << endl;
    cout << "     請輸入三個正整數：";
    cin >> s1 >> s2 >> s3;
    cout << "輸出：" << endl;

    str[0] = s1 + s2 + s3;
    str[1] = s1 + s3 + s2;
    str[2] = s2 + s1 + s3;
    str[3] = s2 + s3 + s1;
    str[4] = s3 + s1 + s2;
    str[5] = s3 + s2 + s1;
    
    max = str[0];
    for(int i=1;i<6;i++)
    {
       if(str[i].compare (max) > 0)
          max = str[i];
    }
    cout << "     此三個正整數所能排列出的最大值為：" << max << endl;
    system("pause");
    return 0;
}
