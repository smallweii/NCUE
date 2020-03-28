#include<iostream>
using namespace std;

int main()
{
    int n1, n2, sum = 0, max = 0, big;
    
    cout << "块";
    cin >> n1 >> n2;
    cout << "块" << endl;
    
    for (int n = n1; n <= n2; n++)
    {
        int arr[1000] = {0};
        
        if (n % 2 == 0) //材案计 
        {
            arr[0] = n;
            for (int i = 0; i < 1000; i++)
            {
                if (arr[i] % 2 == 0) //案计 
                    arr[i + 1] = arr[i] / 2;
                else //计 
                {
                     if(arr[i] == 1)
                         continue;
                     else
                         arr[i + 1] = 3 * arr[i] + 1;
                }    
            }
        }
        else //材计 
        {
            arr[0] = n;
            for (int i = 0; i < 1000; i++)
            {
                if (arr[i] % 2 == 0) //案计 
                    arr[i + 1] = arr[i] / 2;
                else //计 
                {
                     if(arr[i] == 1)
                         continue;
                     else
                         arr[i + 1] = 3 * arr[i] + 1;
                }
            }
        }
        for (int i = 0; i < 1000; i++) //赣计羆㎝ 
                sum += arr[i];
        if (sum > max)
        {
            max = sum;
            big = n;
        }
        sum = 0;
    }
    cout << "程计羆㎝" << max << endl;
    cout << "计ぇa1" << big << endl;
    system("pause");
    return 0;
}
