#include<iostream>
using namespace std;

//C++������Ĭ�ϳ�Ա����
//Ĭ�ϳ�Ա�������û�û��д�����������Զ�����

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
	//Ĭ�����ɵĹ��캯��
	//��������û�й涨Ҫ�����ɴ����ɲ���������������

	//C++11�й涨�˿��Ը�ȱʡֵ
	int _year = 1;//ȱʡֵ
	int _month = 1;//ȱʡֵ
	int _day = 1;//ȱʡֵ
	//�Զ������͵���Ĭ�Ϲ��캯��
};

////////////////////////////////////////
//��������

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
	// ��������...
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
	st.~Stack();//������ʽ���е���
	Date d1(2024, 4, 9);
	Date d2(d1);//��������
	Stack st2(st);
	return 0;
}