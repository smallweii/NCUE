#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char choose, colon, answer;
    int hr, min, s, t, zhr, zmin, zs, ehr, emin, es;
    
    do{
        cout << "請選擇哪一個星球的時間型態：(a)地球時間  (b)Z星球時間：";
        cin >> choose;
        cout << "請輸入測試時間(格式 時時：分分：秒秒)：";
        cin >> hr >> colon >> min >> colon >> s;
    
        if (choose == 'a' || choose == 'A')
        {
            t = hr * 60 * 60 + min * 60 + s;
            zs = t % 30;
            zmin = (t / 30) % 48;
            zhr = t / 30 / 48;
        
            cout << "測試時間：" << endl << "地球時間\t\t" << "Z星球時間" << endl;
            cout << setfill('0') << setw(2) << hr << ":" << setw(2) << min << ":" << setw(2) << s << "\t\t" << setw(2) << zhr << ":" << setw(2) << zmin << ":" << setw(2) << zs << endl;
            cout << "時:分:秒\t\t" << "時:分:秒" << endl;
            cout << "\nDo you wnat to test it again? <enter:y/n>:";
            cin >> answer;
        }
        else if (choose == 'b' || choose == 'B')
        {
            t = hr * 48 * 30 + min * 30 + s;
            es = t % 60;
            emin = (t / 60) % 60;
            ehr = t / 60 / 60;
        
            cout << "測試時間：" << endl << "地球時間\t\t" << "Z星球時間" << endl;
            cout << setfill('0') << setw(2) << ehr << ":" << setw(2) << emin << ":" << setw(2) << es << "\t\t" << setw(2) << hr << ":" << setw(2) << min << ":" << setw(2) << s << endl;
            cout << "時:分:秒\t\t" << "時:分:秒" << endl;
            cout << "\nDo you wnat to test it again? <enter:y/n>:";
            cin >> answer;
        }
    } while (answer == 'y' || answer == 'Y');
    system("pause");
    return 0;
}
