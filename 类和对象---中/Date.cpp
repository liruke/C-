#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
//d1<d2
bool Date::operator<(const Date& d)//内联函数
{
	if (_year < d._day)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
//+复用+=
//思路：先加上天上  天满了先加到月上 月满了加到年上
//d1+=10;
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
//d1+10
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;//出作用域会销毁，所以不能返回引用
}

//+=复用+
//Date Date::operator+(int day)
//{
//	Date tmp = *this;
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month > 12)
//		{
//			tmp._month = 1;
//			tmp._year++;
//		}
//	}
//	return tmp;
//}
//
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//	return *this;
//}
Date& Date::operator-=(int day)
{
	if (*this < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		//借上个月的时间
		_day += GetMonthDay(_year, _month - 1);
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//为了区分，构成重载，给后置++，强行增加了一个int形参
//这里不需要写形参名，因为接收值是多少不重要，也不需要用
//这个参数仅仅
Date& Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
//前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//前置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		//赋值拷贝
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;//flag控制的是符号，如果前面大就是正的，如果后面大就是负数
}