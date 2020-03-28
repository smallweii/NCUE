#include<iostream>
using namespace std;

int main()
{
    int arr[4][16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 
                      0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 
                      4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 
                      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};
    int data, d[6], a[4], afterarr;
    char answer;
    do{
         cout << "請輸入待S-BOX轉換之6位元資料 : ";
         cin >> data;
         for (int i = 5; i >= 0 ; i--)
         {
             d[i] = data % 10;
             data /= 10;
         }
         int r = d[0] * 2 + d[5] * 1;
         int c = d[1] * 8 + d[2] * 4 + d[3] * 2 + d[4] * 1;
         afterarr = arr[r][c];
         for (int i = 3; i >= 0; i--)
         {
             a[i] = afterarr % 2;
             afterarr /= 2;
         }
         cout << "經S-BOX轉換後之4位元資料為 : " << a[0] << a[1] << a[2] << a[3] << endl;
         cout << endl << "Do you want to test it again? <enter y/n>:" << endl;
         cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    system("pause");
    return 0;
}
