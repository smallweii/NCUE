#include<iostream>
using namespace std;
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

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
//string DayOfYear::month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int DayOfYear::DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#endif
