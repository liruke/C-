#include<iostream>
using namespace std;

//C++的六个默认成员函数
//默认成员函数：用户没有写，编译器会自动生成

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	//默认生成的构造函数
	//内置类型没有规定要处理（可处理，可不处理，看编译器）

	//C++11中规定了可以给缺省值
	int _year = 1;//缺省值
	int _month = 1;//缺省值
	int _day = 1;//缺省值
	//自定义类型调用默认构造函数
};

////////////////////////////////////////
//析构函数

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		cout << "Stack" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc fail");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		if (_array!=NULL)
		{
			cout << "~Stack";
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
void TestStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
}
int main()
{
	//Date d1;
	//d1.Print();
	//cout << endl;
	//size_t i = 0;
	//cout << i;
	Stack st;
	st.~Stack();//可以显式进行调用
	Date d1(2024, 4, 9);
	Date d2(d1);//拷贝构造
	Stack st2(st);
	return 0;
}