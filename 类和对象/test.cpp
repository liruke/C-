#define Add(a,b) ((a)+(b))
#include<iostream>
using namespace std;
//����������������ߴ��ε�Ч��
#include <time.h>
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

//inlineû���˺��ȱ��
inline int add(int a, int b)
{
	return a + b;
}
//������ȱ��
//�����������ڲ������Ƚ϶�ʱ���ǲ���չ���ġ�
//�������ڱ�����ֻ��һ�����飬��ͬ�ı���������inlineʵ�ֵĻ��ƿ��ܲ�ͬ


//���Ὠ��ջֱ֡�����õ�ʱ��չ���������
//debug�汾��Ĭ�ϲ�չ��
//չ��֮����call����
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
	//��Χfor
	for (auto &x : arr)//e��arr�Ŀ���
	{
		x *= 2;
	}
	for (auto x : arr)
	{
		cout << x << " ";
	}
	return 0;
}

//1.�ࣺ���Զ��庯��
//2.��������ƾͿ��Դ�������
struct Stack
{
	void Init()
	{

	}
	int* a;
	int capacity;
	int top;
};
//ͨ������£���Ա�������Ϊ˽��
//��Ա�������Ϊ����
//������C++�ķ�װ�̳ж�̬
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