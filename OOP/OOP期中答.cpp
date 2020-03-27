#include<iostream>
#include<string>
using namespace std;

int main()
{
    int choice;
    
    cout << "物件導向程式設計期中上機考試" << endl << endl;
    cout << "\t(1) 基本指令應用      (1)" << endl << endl;
    cout << "\t(2) CLASS應用         (1/2)" << endl << endl;
    cout << "\t(3) 身分證字號檢查    (2/3)" << endl << endl;
    cout << "\t(4) 離開本系統        (1)" << endl << endl << endl;
    
    while(1){
        cout << "    請輸入選項 : ";
        cin >> choice;
        cout << endl;
        
        if (choice == 1) //(1) 基本指令應用 
        {
            int n;
    
            cout << "請輸入欲輸出的九九乘法表列數（1 <= n <= 9）: ";
            cin >> n;
            cout << "輸出 : " << endl;
            
            for (int i = 1; i <= n; i++) //每一行 
            {
                for (int j = 1; j <= i; j++)//每一行的每個數 
                {
                    int k;
                    
                    k = i * j;
                    cout << k << " ";
                }
                cout << endl;
            } 
        }
        if (choice == 2) //(2) CLASS應用 
        {
            class Heading{
                private:
                    string str;
                
                public:
                    Heading(char *space);
                    Heading(int length)
                    {
                        int *size = new int[length];
                        if (!size)
                        {
                            cout << "Memory allocation error!" << endl;
                            exit(1);
                        }
                    }
                    //friend void capitalize(Heading);
                    //friend void display(Heading);
            };
            /*void capitalize(Heading)
            {
                for (int i = 0; i < sizeof(beforestr); i++)
                    (char)afterstr[i] = (int)head.str[i] - (int)'a' + (int)'A';
            }
            void display(Heading)
            {
                for (int i = 0; i < sizeof(beforestr); i++)
                    cout << afterstr[i];
                cout << endl;
            }*/
            //int main()
            //{
                string beforestr;
                //Heading head;
                
                cout << "Please enter a string : ";
                cin >> beforestr;
                cout << endl << "Before : " << beforestr << endl << cout << "After : " << endl;
                
                //head.capitalize();
                //head.display();
                
                //delete []size;
                //size = NULL;
                
                //system("pause");
                //return 0;
            //}
        }
        if (choice == 3) //(3) 身分證字號檢查 
        {
            char arr[10];
            int upper, x1, x2, check;
            
            cout << "請輸入欲檢查之身分證字號 : ";
            cin >> arr;
            cout << "輸出 : ";
            
            if (65 <= (int)arr[0] && (int)arr[0] <= 72) //A~H
                upper = (int)arr[0] - (int)'A' + 10;
            if (74 <= (int)arr[0] && (int)arr[0] <= 78) //J~N
                upper = (int)arr[0] - (int)'A' + 9;
            if (80 <= (int)arr[0] && (int)arr[0] <= 90) //P~Z
                upper = (int)arr[0] - (int)'A' + 8;
            
            x1 = upper / 10;
            x2 = upper % 10;
            check = x1 + 9 * x2 + 8 * arr[1] + 7 * arr[2] + 6 * arr[3] + 5 * arr[4] + 4 * arr[5] + 3 * arr[6] + 2 * arr[7] + 1 * arr[8] + arr[9];
            
            if (check % 10 == 0)
            {
                if (arr[1] == 1 || arr[1] == 2)
                    cout << "這是一個正確的身分證字號" << endl;
            } 
            else
                cout << "這是一個錯誤的身分證字號" << endl;
        }
        if (choice == 4) //(4) 離開本系統 
            return 0; 
    }
    system("pause");
    return 0;
}
