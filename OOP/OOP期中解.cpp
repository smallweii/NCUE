#include<iostream>
#include<string>
using namespace std;

int main()
{
    int choice;
    
    cout << "物件導向程式設計期中上機考試" << endl << endl;
    cout << "\t(1) 基本指令應用      (1)" << endl << endl;
    cout << "\t(2) CLASS應用         (1/2)" << endl << endl;
    cout << "\t(3) 身分證字號檢查    (1)" << endl << endl;
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
        			char *str;
        			int size;
            
    			public:
        			Heading(char *space, int length) //constructor
        			{
            			str = new char space[length]; //動態記憶體配置 
            			if (!str)
            			{
                			cout << "Memory allocation error!" << endl;
                			exit(1);
            			}
        			}
        			~Heading() //destructor
        			{
            			delete []str;
            			str = NULL;
					}
			}; 
			string beforestr;
			char afterstr[50];
			Heading head;
                			
			void capitalize(Heading)
			{
    			for (int i = 0; i < sizeof(beforestr); i++)
        			(char)afterstr[i] = (int)beforestr[i] - (int)'a' + (int)'A';
			}
			void display(Heading)
			{
				for (int i = 0; i < sizeof(beforestr); i++)
        			cout << afterstr[i];
    			cout << endl;
			}
			cout << "Please enter a string : ";
            cin >> beforestr;
            cout << endl << "Before : " << beforestr << endl << cout << "After : " << endl;
			head.capitalize();
            head.display();
        }
        if (choice == 3) //(3) 身分證字號檢查 
        {
            char arr[10] = {0}, num[10] = {0};
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
            for (int i = 1; i <= 9; i++)
				num[i] = (int)arr[i] - (int)'0';   
            
            x1 = upper / 10;
            x2 = upper % 10;
            check = x1 + 9 * x2 + 8 * num[1] + 7 * num[2] + 6 * num[3] + 5 * num[4] + 4 * num[5] + 3 * num[6] + 2 * num[7] + 1 * num[8] + num[9];
            
            if (check % 10 == 0)
            {
                if (num[1] == 1 || num[1] == 2)
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
