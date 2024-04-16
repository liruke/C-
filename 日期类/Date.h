#include<iostream>
using namespace std;



class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;

	}
	int GetMonthDay(int year, int month)
	{
		static int monthday[13] = { -1,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && year % 4 == 0 && year % 100 == 0 || year % 400 == 0)
		{
			return 29;
		}
		return monthday[month];
	}
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	// �������캯��
	// d2(d1)
	Date(const Date& d);
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// ��������
	~Date();
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	//����-���� ��������
	int operator-(const Date& d);
private:

	int _year;

	int _month;

	int _day;

};