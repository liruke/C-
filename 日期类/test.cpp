#include"Date.h"
void Test1()
{
	Date d1(2024, 4, 15);
	Date d2(d1);
	d1.Print();
	d2.Print();
}
void Test2()
{
	Date d1(2024, 4, 15);
	Date d2;
	d2 = d1;
	d2.Print();
	d1.Print();
}
void Test3()
{
	Date d1(2024, 4, 15);
	Date d2;
	d2 = d1 + 100;
	d1 += 100;
	d1.Print();
	d2.Print();
}
void Test4()
{
	Date d1(2024, 4, 15);
	Date d2;
	d2 = d1 - 100;
	d1 -= 100;
	d1.Print();
	d2.Print();
}
void Test5()
{
	Date d1(2024, 4, 15);
	Date d2(2024, 6, 15);
	bool i = d1 > d2;
	cout << "大于" << i << endl;
	bool j = d1 < d2;
	cout << "小于" << j << endl;
}
void Test6()
{
	Date d1(2024, 4, 15);
	Date d2(2024, 7, 24);
	int count = d2 - d1;
	cout << count << endl;
}
int main()
{
	Test6();
	return 0;
}