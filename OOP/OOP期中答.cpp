#include<iostream>
#include<string>
using namespace std;

int main()
{
    int choice;
    
    cout << "����ɦV�{���]�p�����W���Ҹ�" << endl << endl;
    cout << "\t(1) �򥻫��O����      (1)" << endl << endl;
    cout << "\t(2) CLASS����         (1/2)" << endl << endl;
    cout << "\t(3) �����Ҧr���ˬd    (2/3)" << endl << endl;
    cout << "\t(4) ���}���t��        (1)" << endl << endl << endl;
    
    while(1){
        cout << "    �п�J�ﶵ : ";
        cin >> choice;
        cout << endl;
        
        if (choice == 1) //(1) �򥻫��O���� 
        {
            int n;
    
            cout << "�п�J����X���E�E���k��C�ơ]1 <= n <= 9�^: ";
            cin >> n;
            cout << "��X : " << endl;
            
            for (int i = 1; i <= n; i++) //�C�@�� 
            {
                for (int j = 1; j <= i; j++)//�C�@�檺�C�Ӽ� 
                {
                    int k;
                    
                    k = i * j;
                    cout << k << " ";
                }
                cout << endl;
            } 
        }
        if (choice == 2) //(2) CLASS���� 
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
        if (choice == 3) //(3) �����Ҧr���ˬd 
        {
            char arr[10];
            int upper, x1, x2, check;
            
            cout << "�п�J���ˬd�������Ҧr�� : ";
            cin >> arr;
            cout << "��X : ";
            
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
                    cout << "�o�O�@�ӥ��T�������Ҧr��" << endl;
            } 
            else
                cout << "�o�O�@�ӿ��~�������Ҧr��" << endl;
        }
        if (choice == 4) //(4) ���}���t�� 
            return 0; 
    }
    system("pause");
    return 0;
}
