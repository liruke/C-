#define Add(a,b) ((a)+(b))
#include<iostream>
using namespace std;
//引用做参数可以提高传参的效率
#include <time.h>
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

//inline没有了宏的缺点
inline int add(int a, int b)
{
	return a + b;
}
//内联的缺点
//当内联函数内部的语句比较多时，是不会展开的。
//内联对于编译器只是一个建议，不同的编译器关于inline实现的机制可能不同


//不会建立栈帧直接在用的时候展开这个函数
//debug版本下默认不展开
//展开之后不用call函数
//int main()
//{
//	//TestRefAndValue();
//	char a = 0;
//	cout << typeid(a).name() << endl;
//	return 0;
//}



int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//范围for
	for (auto &x : arr)//e是arr的拷贝
	{
		x *= 2;
	}
	for (auto x : arr)
	{
		cout << x << " ";
	}
	return 0;
}

//1.类：可以定义函数
//2.定义的名称就可以代表类型
struct Stack
{
	void Init()
	{

	}
	int* a;
	int capacity;
	int top;
};
//通常情况下：成员变量设计为私有
//成员函数设计为公有
//体现了C++的封装继承多态
class ListNode
{
public:
	void Init()
	{

	}
private:
	ListNode* next;
	int val;
};