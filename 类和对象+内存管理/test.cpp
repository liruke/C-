#include<iostream>
#include<cstdlib>
using namespace std;

//匿名对象
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1;
//	A aa2(1);
//
//	//声明周期只在当前这一行
//	A(2);//匿名对象
//	return 0;
//}
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	int* a = new int(10);
//	int* b = new int[10];
//	for (int i = 0;i < 10;i++)
//	{
//		b[i] = i;
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << endl;
//	delete[] b;
//	cout << *a;
//	return 0;
//}
//
//int main()
//{
//	//除了用法上，c malloc没什么区别
//	int* a1 = (int*)malloc(sizeof(int) * 10);
//	int* a2 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//多个对象的初始化
//	a2 = new int[10];
//	//多个空间
//	delete[] a2;//释放空间
//	int* p1 = new int;
//	//单个空间
//	delete p1;
//	return 0;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int* a1 = new int[n];//可以用变量
//
//}
class A
{
public:
	A(int a = 0, int b = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}

//int main()
//{
//	//A* p1 = new A;
//	//A* p2 = new A(2);//针对于自定义类型，new可以直接调用构造函数直接初始化。
//	//delete p1;//delete会调用析构函数
//	//delete p2;//这里也会调用析构函数
//	//new和delete除了会开空间和释放空间，还会调用析构函数和构造函数
//	//free不会析构
//
//	A* p4 = new A[10];//十个对象会调用十次构造函数
//	//初始化可以直接隐式类型转换
//	A* p5 = new A[10]{ 1,2,3,4 };//隐式类型转换
//	A* p6 = new A[10]{ 1,2,3,4,5,{9,10} };//多参数这样传递参数
//	delete[] p4;
//	return 0;
//}

//C++没有realloc,手动扩容，将原来的数据拷贝下来，然后重新创建一个空间然后拷贝。
int main()
{
	//本质
	//operator new-> (malloc) + 构造函数
	A* p2 = new A;

	//delete是先调用析构函数，再释放空间
	delete p2;
	return 0;
}