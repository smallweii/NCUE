#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heading{ //�إߤ@�ӥs Heading�� class 
	private:
		string company;
		string report;
	
	public:
		Heading(string c = "ABC Industries", string r = "Report") //�w�] company name�M report name�� default value
		{
			company = c; //constructor
			report = r;
		}
		friend void show_oneline(Heading); //�ͽ˨�ƪ��쫬 //�ͽ˨�� : �⤣�ݩ�Y class����������Ʀs��� class�̪�����
		friend void show_fourlines(Heading);
};
void show_oneline(Heading head) //�w�q�ͽ˨��(�L�@��)�A�i�s�� Heading�̨p�������� 
{
	cout << endl << head.company << " " << head.report << endl;
}
void show_fourlines(Heading head) //�w�q�ͽ˨��(�L�|��)�A�i�s�� Heading�̨p�������� 
{
	cout << endl;
	for (int i = 0; i < 45; i++) //�m���L�r�� 
		cout << "*";
	cout << endl;
	for (int i = 0; i < 22 - head.company.length() / 2; i++)
		cout << " ";
	cout << head.company << endl; 
	for (int i = 0; i < 22 - head.report.length() / 2; i++)
		cout << " ";
	cout << head.report << endl;
	for (int i = 0; i < 45; i++)
		cout << "*";
	cout << endl;
}
int main()
{
	char answer;
	do{	
		string c, r;
		Heading head1; //�إ��x�s���A�� Heading������s head1
		vector<Heading> head_vec; //�إ��x�s���A�� Heading�� vector�s head_vec 
		do{
			cout << "Please input a company name: ";
			getline(cin, c); //��ϥΪ̿�J���r��A�Y��촫��Ÿ��]��@�Ӱʧ@ 
			cout << "Please input a report name: ";
			getline(cin, r);
			
			if (c[0] && r[0]) //�Y company name�M report name�����O�Ŧr��A�N���ǤJ Heading�� constructor 
			{
				Heading head1(c, r);
				head_vec.push_back(head1); //�� head1����� push�i head_vec�� 
			}
			if (c[0] && !r[0]) //�Y company name���O�Ŧr��A�N�ǤJ Heading�� constructor
			{                  //�H�� report name�O�Ŧr��A�N�ϥ� default value 
				Heading head1(c);
				head_vec.push_back(head1);
			}
			if (!c[0] && r[0]) //�Y company name�O�Ŧr��A�N�ϥ� default value
			{                  //�H�� report name���O�Ŧr��A�N�ǤJ Heading�� constructor
				Heading head1("ABC Industries", r);
				head_vec.push_back(head1);
			}
			if (!c[0] && !r[0]) //�Y company name�M report name���O�Ŧr��A�N���ϥ� default value
			{                   //�r��̪��Ĥ@�Ӧr���S�F��A��ܨϥΪ̨S��J�r��W��
				Heading head1;
				head_vec.push_back(head1);
			}
			cout << endl << "Again? Enter<y/n>: "; //�i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J  
			cin >> answer;
			getchar(); //Ū������Ÿ� 
		} while (answer == 'y' || answer == 'Y'); //�u�n��Jy/Y�j��N�i�~�����  
		
		int format;
		cout << "Which one do you want to show, one-line or four-line format? Enter<1/4>: "; //�ݨϥΪ̭n�L�X�檺�榡 
		cin >> format;
		cout << endl;
		
		if (format == 1) //�ϥΪ̭n�L�@�檺�榡 
		{
			cout << "One-line format:" << endl;
			for (vector<Heading>::iterator it = head_vec.begin(); it != head_vec.end(); it++) //�q head_vec.begin�}�l�L�A�L�� head_vec.end
				show_oneline(*it);
		}
		if (format == 4) //�ϥΪ̭n�L�|�檺�榡 
		{
			cout << "Four-line format:" << endl;
			for (vector<Heading>::iterator it = head_vec.begin(); it != head_vec.end(); it++)
				show_fourlines(*it);  
		}
		cout << endl << "Again? Enter<y/n>: ";
		cin >> answer;
		getchar();
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
