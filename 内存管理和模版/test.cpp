#include<iostream>
using namespace std;

//malloc每次都要考虑一下会不会成功


//new的底层是operator new+构造函数
//delete的底层是operator delete+析构函数

//还有一个函数是operator new[];
//底层还是new[] -> operator new[] -> operator new -> malloc()


//new和new[]还有delete和delete[]尽量匹配使用
//结论：不要去错配使用，一定要匹配使用，否则结果是不确定的
class A
{
public:
	A(int a=0)
		:_a(a)
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
		_a = 0;
	}
private:
	int _a;
};

//int main()
//{
//	int* p1 = new int[10];
//	delete[] p1;
//	A* p2 = new A[10];//这里会多开四个字节，因为会留四个字节存放对象的个数
//	//free(p2);
//	//这里会多开四个字节，但是free的时候会只free后面四十个，所以没有free玩，所以只能调用delete
//	delete[] p2;
//	//delete p2,也会报错，因为delete匹配的是new，而new不会多开字节，对应的是单个对象，所以只会调用一次析构
//	//最后调用的也是一次析构
//	return 0;
//}


//下面是new和delete的模拟
//int main()
//{
//	//等价于new
//	//这样写是不会多开四个字节，因为这里是我们手动写的，所以我们可以直接控制
//	A* p1 = (A*)operator new(sizeof(A)*10);//可以显示的调用operator new和malloc的用法
//	//一样，也可以显示的调用析构函数
//	
//	//提供一种新的方式是定位new也是placement-new
//	//new+地址+构造函数
//	for(int i=0;i<10;i++)
//	new(p1+i)A;//定位new，调用构造函数
//
//	//等价于delete
//	for(int i=0;i<10;i++)
//	(p1+i)->~A();//调用析构函数
//	operator delete[](p1);
//	return 0;
//}


void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
//有很多swap函数需要写，




//模版：


//用模版写的被称为泛型编程
template<typename T1>
void Swap(T1& left, T1& right)
{
	T1 temp = left;
	left = right;
	right = temp;
}
int main()
{
	//下面两个调用的不是一个函数，不可能不是一个函数
	//temp都不是一个类型，当函数内部的参数不一样，函数开的栈帧也不一样
	int left = 0;
	int right = 1;
	Swap(left, right);
	cout << "left=" << left << " right=" << right << endl;

	double left1 = 0.1;
	double right1 = 0.2;
	Swap(left1, right1);
	cout << "left1=" << left1 << " right1=" << right1 << endl;
	return 0;
}