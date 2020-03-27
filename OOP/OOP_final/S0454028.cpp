#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"SortableVector.h" // �ӵ��ѩM�H�U���Ѯ�����L�k����sĶ �I�I�I�I�I�I�I�I�I�I�I�I�I
using namespace std;

int main()
{
    int choice;
    
    cout << "����ɦV�{���]�p�����W���Ҹ�" << endl << endl;
    cout << "\t1. �ƭȦ걵 (1)" << endl << endl << "\t2. Class Templates & Inheritance (1/2)" << endl << endl << "\t3. Exit (1)" << endl << endl << endl;
    
    while (1) {
        cout << "    �п�J�ﶵ�G";
        cin >> choice;
        cout << endl;
        
        if (choice == 1) { // �ƭȦ걵 
            string a, b, c, str1, str2, str3, str4, str5, str6, max;
        
            cout << "�п�J�T�ӥ����(1~9999999)�G";
            cin >> a >> b >> c;
            
            str1 = a + b + c;
            str2 = a + c + b;
            str3 = b + a + c;
            str4 = b + c + a;
            str5 = c + a + b;
            str6 = c + b + a;
            
            max = str1;
            if (str2 > max)
                max = str2;
            if (str3 > max)
                max = str3;
            if (str4 > max)
                max = str4;
            if (str5 > max)
                max = str5;
            if (str6 > max)
                max = str6;
                
            cout << endl << "���T�ӥ���Ʃү�ƦC�X���̤j�Ȭ��G" << max << endl << endl;
        }
        if (choice == 2) { // Class Templates & Inheritance 
            const int SIZE = 10;
            // �H�U���Ѯ�����L�k����sĶ �I�I�I�I�I�I�I�I�I�I�I�I�I 
            SortableVector<int> intTable(SIZE);
            SortableVector<double> doubleTable(SIZE);
            SortableVector<bool> boolTable(SIZE);
            
            for (int i = 0; i < SIZE; i++) {
                intTable[i] = i;
                doubleTable[i] = i * 1.59;
                if (i % 2 == 0) // even 
                    boolTable[i] = 0;
                else // odd
                    boolTable[i] = 1;
            }
            random_shuffle(intTable.begin(), intTable.end()); // randomly shuffle
            cout << endl << "The elements have been shuffled : " << endl;
            intTable.print_int();
    
            sort(intTable.begin(), intTable.end()); // sort
            cout << "The elements have been sorted : " << endl;
            intTable.print_int();
            
            random_shuffle(doubleTable.begin(), doubleTable.end()); // randomly shuffle
            cout << endl << "The elements have been shuffled : " << endl;
            doubleTable.print_double();
    
            sort(doubleTable.begin(), doubleTable.end()); // sort
            cout << "The elements have been sorted : " << endl;
            doubleTable.print_double();
            
            random_shuffle(boolTable.begin(), boolTable.end()); // randomly shuffle
            cout << endl << "The elements have been shuffled : " << endl;
            boolTable.print_bool();
    
            sort(boolTable.begin(), boolTable.end()); // sort
            cout << "The elements have been sorted : " << endl;
            boolTable.print_bool();
        }
        if (choice == 3) // Exit 
            return 0; 
    }
    system("pause");
    return 0; 
}
