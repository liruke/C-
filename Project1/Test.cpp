//#include<stdio.h>
//#include<stdlib.h>
//int rand = 0;
//
////������ͻ
////���ǺͿ⣬�������ͻ
////������C++��ֻ�ܸ����֣����ܸĿ�
//
//
//int main()
//{
//	printf("%d ", rand);
//	printf("hello world");
//}


namespace lyrics
{
	struct Node
	{
		struct Node* next;
		int val;
	};
	int b = 0;
	int Add(int a, int b)
	{
		return a + b;
	}
}

using lyrics::Add;
using lyrics::b;
using lyrics::Node;
int main()
{
	int i = Add(1, 8);
	b;
	struct Node nenwode;
}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace bit
//{
//	int rand = 0;
//}
//
//
//int main()
//{
//	printf("%d ", bit::rand);//Ĭ�ϲ��������ռ�ᱨ���棬Ĭ�ϵ����ǿ⺯��ָ��
//	printf("hello world");
//}
//#include<stdio.h>
//namespace bit
//{
//	int rand = 0;
//}
//namespace bit1
//{
//	int rand = 1;
//}
//int rand = 2;
////::�������޶���
////����ǿյĻ�����Ĭ�Ϸ���ȫ�ֵ�
//int main()
//{
//	printf("%d ", ::rand);
//	printf("%d ", bit::rand);
//	printf("%d ", bit1::rand);
//	return 0;
//}

//�����ռ䱾���Ƕ�����򣬶���������ռ���
//Ҫ���������ռ��Ҫָ��������

//���������ߵ�ʱ����һ��ԭ��ÿ�����ҵ�ʱ��Ҫȥ�����ĳ������Ҳ����ͻᱨ��
//δ�����ı�ʶ��


//���û��ָ���Ļ���Ĭ�ϵĲ���˳��:�Ⱦֲ�����ȫ��



//���û�ҵ��ǲ��ᵽ�����ռ���ȥ�ҵģ��ͻᱨ��ȫ��

//���кܶ��֣���ǰ�Ӵ���ֻ�������ռ���

//#include<stdio.h>
//namespace bit
//{
//	int rand = 0;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		int val;
//	};
//}
//namespace Bit
//{
//	int rand = 0;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		int val;
//	};
////}
//
//int main()
//{
//	printf("%d \n", Bit::Add(1, 0));
//	printf("%d \n", bit::Add(1, 2));
//	struct bit::Node newnode;
//	newnode.val = 0;
//}

//�����ռ��п��Զ���������������ṹ�塢������Ƕ�������ռ�

//һ���µ������ռ���൱��һ���µ�������


//ʹ�������ռ�

//#include<iostream>
//using namespace std;//���﷨�е�˵������չ�������ռ�
//չ�������ռ��չ��ͷ�ļ�������������չ�������ռ����˼��ʹ�������Ӱ���������������ҹ���

//Ĭ�����ھֲ���Ȼ����ǲ��ң����о��ǵ������ͻص�չ���������ռ��в���

//չ����֮�����������:


//���û�еĻ���Ĭ���ȵ���ǰ��ȥ�ң�Ȼ���ȥȫ���ң�ȫ������û�У��͵������˵������ռ�����
//û��ָ���ȵ�ȫ��ȥ�ң�
//������������ռ�ͬʱչ�����������������ռ䶼����ͬ�Ķ����������������ͻ��
namespace bit
{
	static int x = 0;
	static int y = 0;
}

//ָ��չ��ĳһ��

using bit::x;
//���ַ�ʽ
//1.ָ��չ��
//2.ȫչ��
//3.ָ��ĳһ��չ��

#include<iostream>
//std�ǿ�������ռ䣬�ǽ��⺯��������������ռ���
using std::cout;
using std::endl;
int main()
{
	//<<������
	int i = 0;
	std::cin >> i;
	double j = 1.11;
	//�ص����Զ�ʶ������
}

//printf��scanf���Чһ��

//ȱʡ����
void Func(int a = 1)
{
	cout << a << endl;
}
//��������д�����һ��ֵ���������������ö��پ��Ƕ��٣�������������������ֵ�Ļ�����ֱ�Ӹ���ȱʡ�������г�ʼ��
//����ȱʡ������˵������Ծ�Ĵ�

//ȱʡ��������;

//ȱʡ�������������Ͷ���ͬʱ��
//�涨����������Ϊ��