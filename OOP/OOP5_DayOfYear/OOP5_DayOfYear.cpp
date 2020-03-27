#include<iostream>
using namespace std;

class DayOfYear{
	private:
		int day;
	
	public:
		static string month[12]; // 儲存英文月份 
		static int DayOfMonth[12]; // 儲存月份對應的天數 
		
		DayOfYear(int d) // constructor 
		{
			day = d; // 把使用者輸入的 d assign給 day 
		}
		DayOfYear(string month, int DayOfMonth) // constructor
		{
			;
		}
		
		DayOfYear operator++(); // overloaded prefix ++ operator
		DayOfYear operator++(int); // overloaded postfix ++ operator
		DayOfYear operator--(); // overloaded prefix -- operator
		DayOfYear operator--(int); // overloaded postfix -- operator
		
		void translate(int day); // 把天數轉成月日 
		void check(); // 檢查前後各一天是否有誤 
		void print(); // 印出前後各一天的月日 
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
void DayOfYear::translate(int d) // 把天數轉成月日 
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
	if (day < 1 || day > DayOfMonth[m]) { // 若檢查日期是否有誤 
		cout << endl << "Error : The day is outside the range of days from the month given." << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
}
void DayOfYear::check() // 檢查前後各一天是否有誤 
{
	mon = m;
	if (mon == 0 && day == 0) { // 代表1/0，應為12/31(Day1的前一天 Day0會有問題) 
		mon = 11;
		day = 31;
	}
	else if (mon == 11 && day == 32) { // 代表12/32，應為1/1(Day365的後一天 Day366會有問題) 
		mon = 0;
		day = 1;
	}
	else if (day > DayOfMonth[mon]) { // 1/32應為2/1 
		mon++;
		day = 1;
	}
	else if (day == 0) { // 2/0應為1/31 
		mon--;
		day = DayOfMonth[mon];
	}
	else // 正常的月日就太棒啦 檢查完畢 
		mon = m;
}
void DayOfYear::print() // 印出前後各一天的月日 
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
		while (d < 1 || d > 365) // 超出範圍就重新輸入 
		{
			cout << "Out of the range!" << endl;
			cout << "Please enter a day from 1 to 365 : ";
			cin >> d;
		} 
		DayOfYear Date(d); // 建立儲存型態為 DayOfYear的物件叫 Date 
		
		cout << "Day " << d << " would be ";
		Date.translate(d);
		Date.check();
		Date.print();
		
		cout << "Previous day is ";
		--Date; // overloaded operator(回到前一天)
		Date.check();
		Date.print();
		
		++Date; // overloaded operator(回到今天)
		Date.check();
		cout << "Next day is ";
		++Date; // overloaded operator(回到後一天)
		Date.check();
		Date.print();
		
		cout << endl << "Again? Enter<y/n> : ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;	
}
