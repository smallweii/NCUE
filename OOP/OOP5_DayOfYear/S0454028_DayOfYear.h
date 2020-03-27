#include<iostream>
using namespace std;
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

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
//string DayOfYear::month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int DayOfYear::DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#endif
