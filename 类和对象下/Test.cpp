#include<iostream>
#include<stdlib.h>

using namespace std;



typedef int DataType;
class Stack
{
public:
	//����ջ������Ĭ�Ϲ��죬MyQueueҲ��������Ĭ�Ϲ���
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc����ռ�ʧ��");
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
	//Stack���߱���MyQueueҲ�޷�����Ĭ�Ϲ���
	//��ʼ���б�
	//��ʼ������ĵط�
	//ջû���ṩ��ʼ��������ͻ�ʹ�ó�ʼ���б��ʼ��
	//��ʼ���б��ʿ������Ϊ��ÿ�������г�Ա����ĵط�
	MyQueue(int n,int &rr)
		:_pushst(n)//���ù��캯��
		, _popst(n)
		//,_size(0)
		,_x(1)//����const���εı��������ó�ʼ���б��ʼ��
		//���Ի�����
		,_ref(rr)//���ó�ʼ�������ó�ʼ���б�
	{
		_size = 0;//��������ֱ�ӳ�ʼ��
	}
private:
	//����
	//����û�п��ռ�
	Stack _pushst;
	Stack _popst;
	int _size = 0;
	const int _x;
	//����Ҳ�����ڶ����ʱ���ʼ��������˵�ȶ���һ��������Ȼ������ٰ����������ֵ��һ������
	int& _ref;
};

void Test1()
{
	//����
	//���ռ���
	int xx = 0;
	MyQueue q(10, xx);
	const int y = 1;//const�ı���ֻ���ڶ����ʱ���ʼ������Ϊconst��������֮��Ͳ��ܸ��ˣ�const����ֻ�ܳ�ʼ��һ��
}
//
//class A
//{
//public:
//	//ֻ�е�������֧��ֱ�ӹ��졣
//	A(int a = 1, int b = 2)
//		:_a(a)
//	{}
//private:
//	int _a;
//};



//int main()
//{
//	//A aa1(1);//���캯��
//	//A aa2 = aa1;//��������
//	A aaa2 = { 1,2 };
//	const A& aaa3 = { 1,2 };
//	////��ʽ����ת��
//	////��������ת��Ϊ�Զ�������
//	//A aa3 = 1;
//
//	//A aa4 = 3.3;
//
//	////ֻ�ܸ�ͬ���͵�ȡ������������3������һ����ʱ����Ȼ���������ʱ��������þ���aa5
//	////aa5����ʱ����ı�����û�п�������
//	//const A& aa5 = 3;//����Ҳ�п������죬��Ϊ3������ֱ����Ϊaa5������
//
//	//A aa5 = "1111";�ַ���������ʽ����ת��
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
//	A _a3 = _a2;//Ҳ���Ը���Ա������Ҳ���Ը���Ա����
//};
//
//int main()
//{
//	BB bb;
//	return 0;
//}

////////////////////
//���л��о�̬��Ա�����ĸ���

//class A
//{
//public:
//	//�����ʱ��++
//	A()
//	{
//		++_scount;
//	}
//	//���������ʱ��++
//	A(const A& t)
//	{
//		++_scount;
//	}
//	//������ʱ��--
//	~A()
//	{
//		--_scount;
//	}
//
//	//static���εĳ�Ա����û��thisָ�룬��ζ��ֻ�ܷ��ʾ�̬��Ա
//	//���ܷ���_a1,_a2.
//	static int GetCount()
//	{
//		return _scount;
//
//	}
//private:
//	//��Ա�������溯�����;�̬������һ�����ڴ������У�һ�����ھ�̬����
//	int _a1;
//	int _a2;
//	//���ܸ�ȱʡֵ��ȱʡֵ�Ǹ���ʼ���б�ģ�����static���εĲ����߳�ʼ���б����������߳�ʼ�� �б�ΪʲôҪ��ȱʡֵ��
//	//���ھ�̬�����ڶ����У����Բ��߳�ʼ���б�
//
//	//�������������࣬�������еĶ���//ֻ�������з��ʣ������˽�еĻ�
//	static int _scount;//������ڶ����
//};

//���__scountֻ�����������ǻ���뱨��ģ�����ֻ������Ȼ�������涨��

//����static���εĳ�Ա�����Ķ���
//����
//int A::_scount = 1;


//int main()
//{
//	A aa1;//������ջ�У�����static���α������ھ�̬����
//	cout << sizeof(aa1);
//	cout << A::GetCount << endl;
//	//���_scount�ǹ��еĻ���������������
//	return 0;
//}

//ʹ�ó�������ͳ��A���͵Ķ���һ�������˶��ٸ�����ôͳ�ƣ�

class Time
{
	//����Date��time����Ԫ
	friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time��
	//Date�п���ֱ�ӷ���time��˽�г�Ա
	//time�в��ܷ���Date��˽��
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
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
	class B // B��������A����Ԫ
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
	A::B b;//�����ܵ����������
	return 0;
}