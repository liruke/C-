#include<iostream>
#include<cstdlib>
using namespace std;

//��������
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
//	//��������ֻ�ڵ�ǰ��һ��
//	A(2);//��������
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
//	//�����÷��ϣ�c mallocûʲô����
//	int* a1 = (int*)malloc(sizeof(int) * 10);
//	int* a2 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//�������ĳ�ʼ��
//	a2 = new int[10];
//	//����ռ�
//	delete[] a2;//�ͷſռ�
//	int* p1 = new int;
//	//�����ռ�
//	delete p1;
//	return 0;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int* a1 = new int[n];//�����ñ���
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
//	//A* p2 = new A(2);//������Զ������ͣ�new����ֱ�ӵ��ù��캯��ֱ�ӳ�ʼ����
//	//delete p1;//delete�������������
//	//delete p2;//����Ҳ�������������
//	//new��delete���˻Ὺ�ռ���ͷſռ䣬����������������͹��캯��
//	//free��������
//
//	A* p4 = new A[10];//ʮ����������ʮ�ι��캯��
//	//��ʼ������ֱ����ʽ����ת��
//	A* p5 = new A[10]{ 1,2,3,4 };//��ʽ����ת��
//	A* p6 = new A[10]{ 1,2,3,4,5,{9,10} };//������������ݲ���
//	delete[] p4;
//	return 0;
//}

//C++û��realloc,�ֶ����ݣ���ԭ�������ݿ���������Ȼ�����´���һ���ռ�Ȼ�󿽱���
int main()
{
	//����
	//operator new-> (malloc) + ���캯��
	A* p2 = new A;

	//delete���ȵ����������������ͷſռ�
	delete p2;
	return 0;
}