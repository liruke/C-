#include"Date.h"

// ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
// �������캯��
// d2(d1)
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
// ��ֵ���������
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
// ��������
Date::~Date()
{
	_year = -1;
	_month = -1;
	_day = -1;
}
// ����+=����
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
// ����+����
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
// ����-����
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
// ����-=����
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// >���������
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
// ==���������
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
// >=���������
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
// !=���������
bool Date::operator != (const Date & d)
{
	return !(*this == d);
}
//����-���� ��������
int Date::operator-(const Date& d)
{
	int flag = 1;
	int n = 0;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (min != max)
	{
		min++;
		n++;
	}
	return n * flag;
}