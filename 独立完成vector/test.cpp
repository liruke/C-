#include"vector.h"



namespace lyrics
{
	void test()
	{
		vector<int> v;
		vector<int> v1(10, 1);
		vector<int>  v2(v1);
		vector<int> v3 = v2;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		v3.resize(3);
		cout << endl;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		v3.assign(10, 2);
		cout << endl;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		vector<int>::iterator it = find(v3.begin(), v3.end(), 2);
		it = v3.insert(it, 3);
		cout << endl;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		cout << endl;
		it = v3.erase(it);
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		v3.clear();
		for (auto e : v3)
		{
			cout << e << ' ';
		}
	}
	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
		cout << endl;
		for (auto e : v)
		{
			cout << e << ' ';
		}
		vector<int> v3(v);
		cout << endl;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		vector<int> v4(v3);
		//v4 = v3;
		cout << endl;
		for (auto e : v4)
		{
			cout << e << ' ';
		}
		vector<int> v5;
		v5.push_back(3);
		v5.push_back(6);
		v5.push_back(7);
		v5.push_back(4);
		v5.push_back(7);
		vector<int> v6(v5.begin(), v5.end());
		cout << endl;
		for (auto e : v5)
		{
			cout << e << ' ';
		}
		cout << endl;
		for (auto e : v6)
		{
			cout << e << ' ';
		}
	}
	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		v.push_back(9);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		vector<int> v1(10, 2);
		cout << endl;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
		vector<int> v3(10);
		for (auto e : v3)
		{
			cout << e << ' ';
		}
	}
	void test3()
	{
		//���������ʽ����ת��

		//���ﲻ����ôд����ΪĬ�ϵ��õ��ǹ���
		//���ﲻ����ʽ���͵�ת������ʽ���͵�ת�������ǹ̶���
		//��������Ĳ����ǲ��̶���

		//��������ڲ���Ҫ�õ��������Ҫдһ��initializer_list�Ĺ���
		vector<int> v1 = { 1,2,3,4,5 };
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
		cout << typeid(v1).name() << endl;

		//֧�ֽ��������������ֵ����һ��initializer_list
		initializer_list<int> il2 = { 1,2,3 };

		//�����е�����������֧�ַ�Χfor
		cout << typeid(il2).name() << endl;

		for (auto e : il2)
		{
			cout << e << ' ';
		}
	}

	class A
	{
	public:
		A(int a1,int  a2)
			:_a1(a1)
			,_a2(a2)
		{

		}
	private:
		int _a1;
		int _a2;
	};
	void test4()
	{
		A aa1{ 1,2 };
	}

	void test9()
	{
		vector<string> v;
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		for (auto e : v)
		{
			cout << e << endl;
		}
	}
}


int main()
{
	//��������Ҳ�й��캯��
	int i(0);
	lyrics::test9();
	return 0;
}