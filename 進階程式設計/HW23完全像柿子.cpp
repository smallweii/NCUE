#include<iostream>
#include<string.h>
#include<ctype.h>
#include<cmath>
using namespace std;

int main()
{
    char answer;
    
	do {
		string poly;
		char item[100] = {0};
    
        cout << "��J : ";
        cin >> poly;
        cout << "��춵 : " << endl;
        
        for (int i = 0; i < poly.length(); i++) {
            if (poly[i] != '+' && poly[i] != '\'') {
                for (int j = 0; j < 100; j++) {
                    if (item[j] == poly[i])
                        break;
                    else if (item[j] == 0) {
                        item[j] = poly[i]; // �S���ƪ���춵 
                        cout << item[j];
                        break;
                    }
                }    
            }
        }
        int k = 0, x = 0;
        string str[100];
        
        for (int i = 0; i < poly.length(); i++) { // �����M+��+������ 
            if (poly[i] == '+') {
                for (int j = k; j < i; j++) {
                    str[x] += poly[j];
                }
                k = i + 1; // �q+���U�@�Ӷ}�l�] 
                x++;
            }
        }
        for (int i = k; i < poly.length(); i++) { // ���� 
            str[x] += poly[i];
        }
        cout << endl << "�C�� : " << endl;
        for (int i = 0; i <= x; i++) { // �L�C�� 
            for (int j = 0; j < str[i].length(); j++) {
                cout << str[i][j];
            }
            cout << endl;
        }
        int y = 0, z = 0;
        string sign[100];
        
        for (int i = 0; i < poly.length(); i++) {
            if (poly[i] != '+') {
				if (poly[i] != '\'') { // �᭱�S '���r�������� 0 
                	sign[y][z] = '0';
                	z++;
            	} else { // �᭱�� '���r�������� 1 
            		sign[y][z - 1] = '1';
            		z++;
				}
			} else { // ��� +�N����� 
				y++;
				z = 0;
			}
        }
        cout << "������ : " << endl;
        for (int i = 0; i <= x; i++) { // �L�C�������� 0or1 
            for (int j = 0; j < str[i].length(); j++) {
                cout << sign[i][j];
            }
            cout << endl;
        }
        int place = 0;
        string result[100]; // �s�������������A�]�t���ƪ� 
        
        cout << "�ʶ� : " << endl;
        for (int i = 0; i <= x ; i++) {
        	int lack = 0;
        	string total_lack;
        	
        	for (int j = 0; j < strlen(item); j++) { // ��C���ʪ���춵 
        		bool appear = 0;
        		
				for (int k = 0; k < str[i].length(); k++) {
        			if (item[j] == str[i][k]) {
        				appear = 1; // ���X�{�L 
						break;
					}
				}
				if (appear == 0) { // �S�X�{�L 
					total_lack += item[j];
					lack++;
				}
			}
			cout << total_lack;
    		int times = pow(2, lack), place2 = 0; // times���ʴX���N�Ӷ��ܦ��� 2^(�ʴX��)�� 
    		string temp[times];
    		
			temp[0] = str[i];
			for (int j = 0; j < lack; j++) { // �]�@�����@�Ӧr���i�h 
				for (int k = 0; k < pow(2, j); k++) { // ���Ĥ@�Ӧr���n�]�⦸ �ĤG�Ӧr���n�]�|�� �H������ 
					int insert_place = 0; // �ˬd���J���r���n�b���� 
					string part_lack;
					
					part_lack += total_lack[j]; // ��r���ഫ���r�� �H�K�U����ƨϥ� 
					for (insert_place = 0; insert_place < temp[k].length(); insert_place++) { // ��r���n���b�ĴX�� 
						if (insert_place == 0 && total_lack[j] < temp[k][insert_place]) // �񭺶��p 
							break;
						else if (temp[k][insert_place] < total_lack[j] && total_lack[j] < temp[k][insert_place + 1]) { // �����r���� 
							insert_place++;
							break;
						}
						else if (insert_place == temp[k].length() - 1 && temp[k][insert_place] < total_lack[j]) { // �񥽶��j 
							insert_place++;
							break;
						}
					}
					temp[place2 + 1] = temp[k];
					temp[k].insert(insert_place, part_lack);
					place2++;
					temp[place2].insert(insert_place, part_lack + '\'');
				}
			}
			for (int j = 0; j < times; j++)
				result[place + j] = temp[j];
			place += times;
		}
        cout << endl << "��X : " << result[0];
        for (int i = 1; i < place; i++) {
        	bool again = 0;
        	
        	for (int j = 0; j < i; j++)
        		if (result[i] == result[j])
        			again = 1;
        	if (again == 0) // �S���Ƥ~�L 
        		cout << "+" << result[i];
		}
		cout << endl << endl << "Again? Enter<y/n> : ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    system("pause");
    return 0;
}
