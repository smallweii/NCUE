#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char choose, colon, answer;
    int hr, min, s, t, zhr, zmin, zs, ehr, emin, es;
    
    do{
        cout << "�п�ܭ��@�ӬP�y���ɶ����A�G(a)�a�y�ɶ�  (b)Z�P�y�ɶ��G";
        cin >> choose;
        cout << "�п�J���ծɶ�(�榡 �ɮɡG�����G���)�G";
        cin >> hr >> colon >> min >> colon >> s;
    
        if (choose == 'a' || choose == 'A')
        {
            t = hr * 60 * 60 + min * 60 + s;
            zs = t % 30;
            zmin = (t / 30) % 48;
            zhr = t / 30 / 48;
        
            cout << "���ծɶ��G" << endl << "�a�y�ɶ�\t\t" << "Z�P�y�ɶ�" << endl;
            cout << setfill('0') << setw(2) << hr << ":" << setw(2) << min << ":" << setw(2) << s << "\t\t" << setw(2) << zhr << ":" << setw(2) << zmin << ":" << setw(2) << zs << endl;
            cout << "��:��:��\t\t" << "��:��:��" << endl;
            cout << "\nDo you wnat to test it again? <enter:y/n>:";
            cin >> answer;
        }
        else if (choose == 'b' || choose == 'B')
        {
            t = hr * 48 * 30 + min * 30 + s;
            es = t % 60;
            emin = (t / 60) % 60;
            ehr = t / 60 / 60;
        
            cout << "���ծɶ��G" << endl << "�a�y�ɶ�\t\t" << "Z�P�y�ɶ�" << endl;
            cout << setfill('0') << setw(2) << ehr << ":" << setw(2) << emin << ":" << setw(2) << es << "\t\t" << setw(2) << hr << ":" << setw(2) << min << ":" << setw(2) << s << endl;
            cout << "��:��:��\t\t" << "��:��:��" << endl;
            cout << "\nDo you wnat to test it again? <enter:y/n>:";
            cin >> answer;
        }
    } while (answer == 'y' || answer == 'Y');
    system("pause");
    return 0;
}
