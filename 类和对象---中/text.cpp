#include"Date.h"


void Test1()
{
	Date d1(2024, 4, 15);
	Date d2 = d1 + 50;
	Date d3(2024, 4, 15);
	Date d4;
	d4 = d3++;
	cout << "����++" << endl;
	d3.Print();
	d4.Print();
	cout << "����++" << endl;
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

//��̬��������������������
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
