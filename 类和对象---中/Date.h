#pragma once
#include<iostream>
#include<cassert>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();

	//内联不能声明和定义声明,直接写在类中的默认就是内联函数
	inline int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month <= 12);
		static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };//获取每一个月的月份
		if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			return monthDayArray[2] + 1;
		}
		return monthDayArray[month];
	}
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	//++d1;
	Date& operator++();
	//d1++
	//为了区分，构成重载，给后置++，强行增加了一个int形参
	Date& operator++(int);//
	//--d1
	Date& operator--();
	//d1--
	Date operator--(int);

	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};