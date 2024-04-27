#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<set>
#include<list>
#include<typeinfo>
#include<algorithm>
using namespace std;

//SLT���㷨�����ݽṹ�Ŀ�
//��һ�㣺����SLT
//�ڶ��㣺�˽ⷺ�ͼ������ں���SLT��ѧ������ʵ��
//�����㣺����SLT

//string
//������Ϊ��һ���ַ�����
//�������ݿ�����ɾ���


//���֤���������string��ģ���Ϊ��Щ���֤������X

void Test_string1()
{
	//����
	string s1;
	string s2("ABCDEF");//����
	string s3(s2);//��������
	string s4;
	s4 = s2;//��ֵ����

	//�˽�
	cout << s4 << endl;
	cout << s3 << endl;
	string s5(s3, 0, 2);//��s5��0��λ�ÿ���һ�������ֽڴ�С�Ĵ�,���г�ʼ��
	cout << s5 << endl;
	string s6("hello world");
	string s7(s6, 0, 5);
	cout << s7 << endl;
	string s8(s7, 0);//����������������ͱ�ʾ�ж��ٿ�������
	cout << s8 << endl;
	string s9("hello world", 5);//ȡǰ�洮��ǰn���ַ�
	cout << s9 << endl;
	string s10(10, 'x');//��������ַ�������ʼ��n��
	cout << s10 << endl;
}

void Test_string2()
{
	string s1("hello world");//���ǹ��캯��
	string s2 = "hello world";//��ʽ����ת����������һ����ʱ����Ȼ���ٿ��������s2.
	const string& s3 = "hello world";//��ʱ�����г��ԣ����Ա���������ǰ���const
}


//���÷���
//1.���ٿ���
//2.�޸ķ��ض���,���ص��Ǳ�����������ĵľ���s��Ӧ���Ǹ����ڵ��Ǹ�ֵ

//operator[]���ܱ���Ҳ���޸�
void Test_string3()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;//��size()����û���κβ�ͬ���𰸶���һ����
	//�ʼд��length������stl������֮�󣬾�д�˸�size��Ϊ�˺�stl����һ��

	//����ÿ���ַ�
	//���������ķ��ʷ�ʽ
	for (int i = 0;i < s1.size();i++)
	{
		cout << s1[i] << ' ';//[]��operator[]������
		//����������һ��ʹ�ã������಻�����ε��ǿ���++��--
	}
	//s1[s1.size() + 20];Խ���飬ֱ�ӱ���
	cout << endl;
	//��һ�ֱ������±�+[]
	//for (int i = 0;i < s1.size();i++)
	//{
	//	s1[i]++;
	//	cout << s1[i];
	//}
	//�ڶ��ֱ�����������
	string::iterator it1 = s1.begin();
	//iterator:���������е�
	//�������������������е�������֧�ֵ������������±����ֻ֧��vector��string
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	cout << typeid(it1).name() << endl;
	//�����ַ��ʷ�ʽ�����������õķ�Χfor
	//�ײ�ĽǶȾ��ǵ�����
	cout << "��Χfor:" << endl;
	for (auto e : s1)//����������֧�ַ�Χfor
	{
		//eÿ���������Ŀ������������ò����޸�ֵ
		cout << e;
	}
}

void Test_string5()
{
	const string s1("hello world");
	string::const_iterator it = s1.begin();//const_iterator��ʾ���ݲ����޸�
	//����const iterator�ǵ���������++������������++���Ͳ��ܱ�����

	//����Ҳ������auto
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		//const�������Ǹ�const_iteratorר������������
		//it�����޸ģ�����*it�����޸�
		cout << *it1;//�����*Ҳ��һ�����صĺ���������ָ�����˼
		it1++;
	}
	cout << endl;
	//���������
	string::const_reverse_iterator it2 = s1.rbegin();
	while (it2 != s1.rend())
	{
		cout << *it2;
		it2++;
	}
	cout << endl;
	string s2("hello world");
	string::reverse_iterator it3 = s2.rbegin();
	while (it3 != s2.rend())
	{
		cout << *it3;
		//++��������ߣ��ײ��������operator++,�Ϳ���ʵ����
		it3++;
	}
}

void List_Test()
{
	list<int> List;
	List.push_back(1);
	List.push_back(2);
	List.push_back(3);
	List.push_back(4);
	List.push_back(5);

	list<int>::iterator it1 = List.begin();
	//��������������
	while (it1 != List.end())
	{
		cout << *it1 << ' ';
		it1++;
	}
	cout << endl;
	for (auto e : List)
	{
		cout << e << ' ';
	}
	cout << endl;
}
//stringҲ֧�������ַ���

void Test_string6()
{
	string s1("hello world");
	cout << s1 << endl;
	//s1���ֵ���������˼���ǰ�ASCII�ţ�
	sort(s1.begin(), s1.end());//sort����������ҿ������䣬��˼�����ұߵ����䲻��һ����Ч��ֵ

	//ֻ����һ���־Ϳ������õ�����++����--

	//��һ�������һ������������
	sort(++s1.begin(), --s1.end());
	cout << s1 << endl;

	//ǰ�������
	sort(s1.begin(), s1.begin() + 5);
}

//�޸Ĳ���
void Test_string7()
{
	string s1("hello world");
	s1.push_back('A');
	//push_back��һ�����ݵĲ���һ�����ݵĲ���
	cout << s1 << endl;
	//append�͹���ķ������

	//������append�õ��������Σ�appendβ��һ���ַ���
	s1.append("yyyyyy");
	cout << s1 << endl;
	//���������+=
	s1 += "dddddd";
	cout << s1 << endl;
	string s2("student");
	//+=������õ�
	s1 += s2;
	cout << s1 << endl;

	//βɾ
	s1.pop_back();
	cout << s1 << endl;

	//ɾ��һ��
	s1.erase(11);//����ǰ����ٸ��ֽ�
	cout << s1 << endl;
}

//vector<char>��string���������vector�ײ����һ�����ݺ�һ������
//string

int main()
{
	Test_string7();
	//string s2("hello world");
	//cout << sizeof(s2) << endl;
	return 0;
}