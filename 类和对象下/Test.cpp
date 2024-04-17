#include<iostream>
#include<stdlib.h>

using namespace std;



typedef int DataType;
class Stack
{
public:
	//假设栈不生成默认构造，MyQueue也不会生成默认构造
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

class MyQueue
{
public:
	//Stack不具备，MyQueue也无法生成默认构造
	//初始化列表
	//初始化定义的地方
	//栈没有提供初始化，这里就会使用初始化列表初始化
	//初始化列表本质可以理解为，每个对象中成员定义的地方
	MyQueue(int n,int &rr)
		:_pushst(n)//调用构造函数
		, _popst(n)
		//,_size(0)
		,_x(1)//对于const修饰的变量必须用初始化列表初始化
		//可以混着用
		,_ref(rr)//引用初始化必须用初始化列表
	{
		_size = 0;//内置类型直接初始化
	}
private:
	//声明
	//但是没有开空间
	Stack _pushst;
	Stack _popst;
	int _size = 0;
	const int _x;
	//引用也必须在定义的时候初始化，不能说先定义一个别名，然后后面再把这个别名赋值给一个变量
	int& _ref;
};

void Test1()
{
	//定义
	//开空间了
	int xx = 0;
	MyQueue q(10, xx);
	const int y = 1;//const的变量只能在定义的时候初始化，因为const变量定义之后就不能改了，const变量只能初始化一次
}
//
//class A
//{
//public:
//	//只有单个参数支持直接构造。
//	A(int a = 1, int b = 2)
//		:_a(a)
//	{}
//private:
//	int _a;
//};



//int main()
//{
//	//A aa1(1);//构造函数
//	//A aa2 = aa1;//拷贝构造
//	A aaa2 = { 1,2 };
//	const A& aaa3 = { 1,2 };
//	////隐式类型转换
//	////内置类型转换为自定义类型
//	//A aa3 = 1;
//
//	//A aa4 = 3.3;
//
//	////只能给同类型的取别名，这里用3构造了一个临时对象，然后这里的临时对象的引用就是aa5
//	////aa5是临时对象的别名，没有拷贝构造
//	//const A& aa5 = 3;//这里也有拷贝构造，因为3不可能直接作为aa5的引用
//
//	//A aa5 = "1111";字符串不能隐式类型转换
//}


//class BB
//{
//public:
//	BB()
//	{
//
//	}
//private:
//	int _b1 = 1;
//	int* _ptr = (int*)malloc(40);
//	Stack _pushst = 10;
//	A _a1 = 1;
//	A _a2 = { 1,2 };
//	A _a3 = _a2;//也可以给成员变量，也可以给成员变量
//};
//
//int main()
//{
//	BB bb;
//	return 0;
//}

////////////////////
//类中还有静态成员变量的概念

//class A
//{
//public:
//	//构造的时候++
//	A()
//	{
//		++_scount;
//	}
//	//拷贝构造的时候++
//	A(const A& t)
//	{
//		++_scount;
//	}
//	//析构的时候--
//	~A()
//	{
//		--_scount;
//	}
//
//	//static修饰的成员函数没有this指针，意味着只能访问静态成员
//	//不能访问_a1,_a2.
//	static int GetCount()
//	{
//		return _scount;
//
//	}
//private:
//	//成员变量不存函数，和静态变量，一个存在代码区中，一个存在静态区中
//	int _a1;
//	int _a2;
//	//不能给缺省值，缺省值是给初始化列表的，但是static修饰的不会走初始化列表，所以它不走初始化 列表为什么要给缺省值呢
//	//它在静态区不在对象中，所以不走初始化列表
//
//	//属于所有整个类，属于所有的对象//只能在类中访问，如果是私有的话
//	static int _scount;//这个不在对象里，
//};

//如果__scount只声明不定义是会编译报错的，这里只能声明然后再外面定义

//这是static修饰的成员变量的定义
//定义
//int A::_scount = 1;


//int main()
//{
//	A aa1;//对象在栈中，但是static修饰变量存在静态区中
//	cout << sizeof(aa1);
//	cout << A::GetCount << endl;
//	//如果_scount是公有的话，可以这样访问
//	return 0;
//}

//使用场景，想统计A类型的对象一共创建了多少个，怎么统计？

class Time
{
	//声明Date是time的友元
	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类
	//Date中可以直接访问time的私有成员
	//time中不能访问Date的私有
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

class A
{
private:
	static int k;
	int h;
public:
	class B // B天生就是A的友元
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};


int main()
{
	A a;
	A::B b;//仅仅受到类域的限制
	return 0;
}