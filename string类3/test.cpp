#include<iostream>
#include<string>
using namespace std;

void Test_string1()
{
	string A("https://www.google.com/lyrics/master");
	//find ��һ��������char �ڶ���������pos����posλ�ÿ�ʼ��ͷ�����ң�
	//ȱʡ������0
	size_t pos1 = A.find(':');//Ĭ�ϴ��׿�ʼ��
	//substr��ȡ�Ӵ�����posλ�ÿ�ʼȡlen���ַ�
	string B = A.substr(0, pos1);//����ҿ�
	cout << B << endl;
	//ȡ�ڶ���
	size_t pos2 = A.find('/', pos1 + 3);
	string C = A.substr(pos1 + 3, pos2 - (pos1 + 3));//����ҿ�
	cout << C << endl;
	size_t pos3 = A.find('/', pos2 + 1);
	string D = A.substr(pos2 + 1, pos3 - (pos2 + 1));
	cout << D << endl;
	string E = A.substr(pos3 + 1);
	cout << E << endl;
	//npos�����ε����ֵ��������������پ���npos������ȡ���Ӵ���ĩβ
	//rfind�ǵ�����

	//find_first_of
	//������find any of
	//find���ص������������һ���ַ�
	string S1("ABCDEFGHIJK");//���⵱��������һ��ƥ����ַ�
	size_t found = S1.find_first_of("ABCDEFGHIJK");
	while (found != string::npos)
	{
		S1[found] += 32;//�����滻
		found = S1.find_first_of("ABCDEFGHIJK", found + 1);
	}
	cout << S1 << endl;
	//C�����е�strtok������Ĺ�������
	
	//find_last_of
	//�����ʼ��
	//find_not_ofǡ�������෴��find_not_of�������û�е��еľ�ֱ�ӷ���


	//compare���ıȽ�
}

void Test_string2()
{
	string s1 = "hello";
	string s2 = "world";

	string s3 = s1 + s2;
	cout << s3 << endl;

	string s4 = "xxxxx" + s1;
	cout << s4 << endl;

	string s5 = s1 + "Xxxxxx";
	cout << s5 << endl;
}

void Test_string3()
{
	//�ַ����Ƚϴ�С
	//����ASCII�Ƚ�
	string s1 = "hello";
	string s2 = "world";
	cout << (s1 > s2) << endl;//�Ƚϴ�С
	//��Ҫ�����ţ���Ϊcout�����ȼ����ڱȽϵ����ȼ����Ƚϴ�С�ͳ���û��ϵ������ǰ����ֵ���Ƚ�

	//Ĭ�Ϲ涨�ո���߻���ʱ���ֵ�ķָ�
	//getline�Ϳ��Խ����Щ����
}

void Test_string4()
{
	string s1;
	//��ν�����
	//Ctrl C����Ctrl V
	while (cin >> s1)
	{
		cout << s1 << endl;
	}
}

void Test__string5()
{

}

//int main()
//{
//	Test_string4();
//	string s1;
//	//��ȡһ���а����ո񣬣�����������ȡ
//	getline(cin, s1);//֧�ֿո�
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	//�ַ���ת���Σ���������ת�ַ���
//	//atoi���ַ���ת��������
//	//itoa���ǰ�����ת�����ַ���
//	//to_string
//	int x = 0, y = 0;
//	cin >> x >> y;
//	string str = to_string(x + y);
//	cout << str << endl;
//
//	//stoi���ǰ��ַ���ת��������
//	int z = stoi(str);
//	cout << z << endl;;
//	return 0;
//}

//��������ASCII
//ȫ������������

//�õ�������UTF-8

//string��֧��UTF-8

//string������basic_string<char> string
//string��һ��ģ�棬��Ϊ

//����UTF-8����UTF-16������UTF-32

//��һ������ı������gbk�ֿ�

int main()
{
	u16string s1;
	u32string s2;
	wstring s3;
	return 0;
}