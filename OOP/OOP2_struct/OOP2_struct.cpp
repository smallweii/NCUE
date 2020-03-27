#include<iostream>
#include<string>
using namespace std;

void sort(struct Student *stu, int n);
float average(struct Student *std, int n);

struct Student{
		string name;
		int score;
		int number;
	};//�إߤ@�ӦW��Student�����c�A�������Hstring�����A��name�B�Hint�����A��score�Mnumber
int main()
{
	int n;
	char answer;
	
	do {
		cout << "How many pairs do you want to test? ";
		cin >> n;
		
		Student *stu;//���c���Ы���ʺA�O����t�m����m 
		stu = new Student[n];//�s�n���Ŷ��A�N��ʺA�O����t�m 
		if (!stu)//�S�n��Ŷ��A�N��O����t�m����  
		{
			cout << "Memory allocation error!" << endl;
			exit(1);//�b�����`���ΤU�A���_�{��������  
		}
		for (int i = 0; i < n; i++)//��J�ǥ̪ͭ��W�r�M���Z 
		{
			stu[i].number = i + 1;
			cout << "Please enter Student" << i + 1 << "'s name: ";
			cin >> stu[i].name;
			cout << "Please enter Student" << i + 1 << "'s score: ";
			cin >> stu[i].score;
			
			while (stu[i].score < 0)//�קK�ϥΪ̿�J�t�ƪ����Z�A�n���D�t�Ƥ~��i�J�H�U�禡 
			{
				cout << stu[i].score << " is a nagetive number!" << endl;
				cout << "Please enter Student" << i + 1 << "'s score: ";//�Y���t�ơA�n�D�ϥΪ̭��s��J���Z 
				cin >> stu[i].score;
			}
		}
		sort(stu, n);//�i�Jsort�禡�ӱq�p��j�Ƨ� 
		cout << endl << "After sort:" << endl;
		for (int i = 0; i < n; i++)
			cout << "Student" << stu[i].number << " "<< stu[i].name << " : " << stu[i].score << endl;
		cout << endl << "The average score is " << average(stu, n) << endl;//�i�Javerage�禡�ӭp�⥭�����Z 
		delete [] stu;//�٪Ŷ� 
		stu = NULL;//�O����w�Q�Q�Χ��A�G����Ы��VNULL 
		
		cout << endl << "Do you want to test it again? <enter y/n>: ";//�i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');//�u�n��JY/y�j��N�i�~����� 
		
	system("pause");
	return 0;
}
void sort(struct Student *stu, int n)
{
	for (int j = 0; j < n; j++)
		for(int i = 0; i < n - 1; i++)
		{
			if (stu[i + 1].score < stu[i].score)//�Y�᭱ < �e��(�W�r ����)�N�@�_�洫 
			{
				Student temp = stu[i + 1];
				stu[i + 1] = stu[i];
				stu[i] = temp;
			}
		}
}
float average(struct Student *stu, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += stu[i].score;
    float ave = (float)sum / n;
    return ave;
}
