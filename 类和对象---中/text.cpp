#include"Date.h"


void Test1()
{
	Date d1(2024, 4, 15);
	Date d2 = d1 + 50;
	Date d3(2024, 4, 15);
	Date d4;
	d4 = d3++;
	cout << "后置++" << endl;
	d3.Print();
	d4.Print();
	cout << "后置++" << endl;
	Date d5(d3);
	Date d6;
	d6 = ++d5;
	d6.Print();
	d5.Print();
	Date d7(d3);
	Date d8;
	d8 = d7--;
	d8.Print();
	d7.Print();
}

//静态函数的特性是连接属性
void Test2()
{
	Date d1(2024, 4, 15);
	Date d2(2024, 5, 1);
	int n = d2 - d1;
	cout << n;
}

int main()
{
	Test2();
	return 0;
}
