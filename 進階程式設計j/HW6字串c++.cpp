#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2,s3,str[6],max;
    
    cout << "��J�G" << endl;
    cout << "     �п�J�T�ӥ���ơG";
    cin >> s1 >> s2 >> s3;
    cout << "��X�G" << endl;

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
    cout << "     ���T�ӥ���Ʃү�ƦC�X���̤j�Ȭ��G" << max << endl;
    system("pause");
    return 0;
}
