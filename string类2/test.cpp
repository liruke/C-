#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void Test_String1()
{
	//assign����һ�ָ�ֵ��Ϊ
	string s1("hello world");
	cout << s1 << endl;
	s1.assign("111111");//�൱�ڸ�ֵ��ֱ�Ӹ�����
	cout << s1 << endl;
}

void Test_string2()
{

	//insert����->ʱ�临�Ӷ���O(N)Ч�ʲ���
	//ʵ���У�����Ҳ����
	string s1("hello world ");
	s1.insert(0, "xxx");
	cout << s1 << endl;

	//��ͨ�汾
	s1.insert(0, 1, 'y');//��0��λ�ò���һ���ַ�
	cout << s1 << endl;

	//�������汾
	s1.insert(s1.begin(), 'y');
	cout << s1 << endl;

	string s2("11111");
	s1.insert(s1.begin(), s2.begin(), s2.end());//��s1��λ�ò���һ����������������ָ���λ����s2��begin��s2��endλ��
	cout << s1 << endl;
}

void Test_string3()
{
	//erase���ã�Ч�ʲ��ߣ���ΪҪŲ��˳������ʱ�临�ӶȾ���O(N)
	//���eraseɾ����len�����ַ����ĳ��ȣ����ж���ɾ���٣�
	string s1("hello world");
	cout << s1 << endl;
	s1.erase(0, 1);//ͷɾһ���ַ�
	cout << s1 << endl;
	s1.erase(3, 2);
	cout << s1 << endl;
	s1.erase(0, 100);
	cout << s1 << endl;//��
	//ע�⣺�±�λ�ñ����ǺϷ���

	//�滻
	string s2("hello world");
	s2.replace(5, 1, "%20");
	cout << s2 << endl;;
	string s3("hello world hello bit");
	cout << s3 << endl;
	for (size_t i = 0;i < s3.size();i++)
	{
		if (s3[i] == ' ')
		{
			s3.replace(i, 1, "%20");//Ų�����ݣ�ʱ�临�Ӷ���O(Z)
		}
	}
	cout << s3 << endl;
	//�ռ任ʱ�䣬���¿�һ���ռ�
	string s4("hello world hello bit");
	string s5;
	for (auto ch : s4)
	{
		if (ch != ' ')
		{
			s5.push_back(ch);
		}
		if (ch == ' ')
		{
			s5 += "%20";
		}
	}
	cout << s5 << endl;
}

void Test_string4()
{
	
}
int main()
{
	Test_string3();
	return 0;
}