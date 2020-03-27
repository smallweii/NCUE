#include<iostream>
#include"S0454028_DayOfYear.h"
using namespace std;

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
