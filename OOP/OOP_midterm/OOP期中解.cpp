#include<iostream>
#include<string>
using namespace std;

int main()
{
    int choice;
    
    cout << "����ɦV�{���]�p�����W���Ҹ�" << endl << endl;
    cout << "\t(1) �򥻫��O����      (1)" << endl << endl;
    cout << "\t(2) CLASS����         (1/2)" << endl << endl;
    cout << "\t(3) �����Ҧr���ˬd    (1)" << endl << endl;
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
        			char *str;
        			int size;
            
    			public:
        			Heading(char *space, int length) //constructor
        			{
            			str = new char space[length]; //�ʺA�O����t�m 
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
        if (choice == 3) //(3) �����Ҧr���ˬd 
        {
            char arr[10] = {0}, num[10] = {0};
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
            for (int i = 1; i <= 9; i++)
				num[i] = (int)arr[i] - (int)'0';   
            
            x1 = upper / 10;
            x2 = upper % 10;
            check = x1 + 9 * x2 + 8 * num[1] + 7 * num[2] + 6 * num[3] + 5 * num[4] + 4 * num[5] + 3 * num[6] + 2 * num[7] + 1 * num[8] + num[9];
            
            if (check % 10 == 0)
            {
                if (num[1] == 1 || num[1] == 2)
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
