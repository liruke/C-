#include<iostream>
#include<string>
using namespace std;

void Test_string1()
{
	string A("https://www.google.com/lyrics/master");
	//find 第一个参数：char 第二个参数：pos（从pos位置开始从头往后找）
	//缺省参数是0
	size_t pos1 = A.find(':');//默认从首开始找
	//substr是取子串，从pos位置开始取len个字符
	string B = A.substr(0, pos1);//左闭右开
	cout << B << endl;
	//取第二段
	size_t pos2 = A.find('/', pos1 + 3);
	string C = A.substr(pos1 + 3, pos2 - (pos1 + 3));//左闭右开
	cout << C << endl;
	size_t pos3 = A.find('/', pos2 + 1);
	string D = A.substr(pos2 + 1, pos3 - (pos2 + 1));
	cout << D << endl;
	string E = A.substr(pos3 + 1);
	cout << E << endl;
	//npos是整形的最大值，如果不给到多少就是npos，就是取到子串的末尾
	//rfind是倒着找

	//find_first_of
	//本质是find any of
	//find返回的是满足的任意一个字符
	string S1("ABCDEFGHIJK");//在这当中找任意一个匹配的字符
	size_t found = S1.find_first_of("ABCDEFGHIJK");
	while (found != string::npos)
	{
		S1[found] += 32;//可以替换
		found = S1.find_first_of("ABCDEFGHIJK", found + 1);
	}
	cout << S1 << endl;
	//C语言中的strtok和这个的功能类似
	
	//find_last_of
	//从最后开始找
	//find_not_of恰好与其相反，find_not_of就是如果没有当中的就直接返回


	//compare串的比较
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
	//字符串比较大小
	//按照ASCII比较
	string s1 = "hello";
	string s2 = "world";
	cout << (s1 > s2) << endl;//比较大小
	//需要打括号，因为cout的优先级大于比较的优先级，比较大小和长度没关系，这个是按照字典序比较

	//默认规定空格或者换行时多个值的分割
	//getline就可以解决这些问题
}

void Test_string4()
{
	string s1;
	//如何结束？
	//Ctrl C或者Ctrl V
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
//	//获取一行中包含空格，，不能用流提取
//	getline(cin, s1);//支持空格
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	//字符串转整形，或者整形转字符串
//	//atoi把字符串转换成整形
//	//itoa就是把整形转换成字符串
//	//to_string
//	int x = 0, y = 0;
//	cin >> x >> y;
//	string str = to_string(x + y);
//	cout << str << endl;
//
//	//stoi就是把字符串转换成整形
//	int z = stoi(str);
//	cout << z << endl;;
//	return 0;
//}

//老美的是ASCII
//全世界的是万国表

//用的最多的是UTF-8

//string就支持UTF-8

//string本质是basic_string<char> string
//string是一个模版，因为

//除了UTF-8还有UTF-16，还有UTF-32

//有一个特殊的编码叫做gbk字库

int main()
{
	u16string s1;
	u32string s2;
	wstring s3;
	return 0;
}