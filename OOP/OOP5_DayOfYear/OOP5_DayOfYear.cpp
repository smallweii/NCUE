#include<iostream>
using namespace std;

class DayOfYear{
	private:
		int day;
	
	public:
		static string month[12]; // �x�s�^���� 
		static int DayOfMonth[12]; // �x�s����������Ѽ� 
		
		DayOfYear(int d) // constructor 
		{
			day = d; // ��ϥΪ̿�J�� d assign�� day 
		}
		DayOfYear(string month, int DayOfMonth) // constructor
		{
			;
		}
		
		DayOfYear operator++(); // overloaded prefix ++ operator
		DayOfYear operator++(int); // overloaded postfix ++ operator
		DayOfYear operator--(); // overloaded prefix -- operator
		DayOfYear operator--(int); // overloaded postfix -- operator
		
		void translate(int day); // ��Ѽ��ন��� 
		void check(); // �ˬd�e��U�@�ѬO�_���~ 
		void print(); // �L�X�e��U�@�Ѫ���� 
};
int m, mon; // global variable
string DayOfYear::month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int DayOfYear::DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DayOfYear DayOfYear::operator++() // overloaded prefix ++ operator
{
	day++;
	return *this;
}
DayOfYear DayOfYear::operator++(int) // overloaded postfix ++ operator
{
	DayOfYear temp = *this;
	day++;
	return temp;
}
DayOfYear DayOfYear::operator--() // overloaded prefix -- operator
{
	day--;
	return *this;
}
DayOfYear DayOfYear::operator--(int) // overloaded postfix -- operator
{
	DayOfYear temp = *this;
	day--;
	return temp;
}
void DayOfYear::translate(int d) // ��Ѽ��ন��� 
{
	for (int i = 0; i < 12; i++) {
		if (d - DayOfMonth[i] <= 0) {
			m = i;
			day = d;
			break;
		}
		else
			d -= DayOfMonth[i];
	}
	if (day < 1 || day > DayOfMonth[m]) { // �Y�ˬd����O�_���~ 
		cout << endl << "Error : The day is outside the range of days from the month given." << endl;
		exit(1); // �b�����`���ΤU�A���_�{�������� 
	}
}
void DayOfYear::check() // �ˬd�e��U�@�ѬO�_���~ 
{
	mon = m;
	if (mon == 0 && day == 0) { // �N��1/0�A����12/31(Day1���e�@�� Day0�|�����D) 
		mon = 11;
		day = 31;
	}
	else if (mon == 11 && day == 32) { // �N��12/32�A����1/1(Day365����@�� Day366�|�����D) 
		mon = 0;
		day = 1;
	}
	else if (day > DayOfMonth[mon]) { // 1/32����2/1 
		mon++;
		day = 1;
	}
	else if (day == 0) { // 2/0����1/31 
		mon--;
		day = DayOfMonth[mon];
	}
	else // ���`�����N�Ӵΰ� �ˬd���� 
		mon = m;
}
void DayOfYear::print() // �L�X�e��U�@�Ѫ���� 
{
	cout << month[mon] << " " << day << endl;
}
int main()
{
	int d;
	char answer;
	
	do{
		cout << "Please enter a day from 1 to 365 : ";
		cin >> d;
		while (d < 1 || d > 365) // �W�X�d��N���s��J 
		{
			cout << "Out of the range!" << endl;
			cout << "Please enter a day from 1 to 365 : ";
			cin >> d;
		} 
		DayOfYear Date(d); // �إ��x�s���A�� DayOfYear������s Date 
		
		cout << "Day " << d << " would be ";
		Date.translate(d);
		Date.check();
		Date.print();
		
		cout << "Previous day is ";
		--Date; // overloaded operator(�^��e�@��)
		Date.check();
		Date.print();
		
		++Date; // overloaded operator(�^�줵��)
		Date.check();
		cout << "Next day is ";
		++Date; // overloaded operator(�^���@��)
		Date.check();
		Date.print();
		
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;	
}
