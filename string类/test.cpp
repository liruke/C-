#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<set>
#include<list>
#include<typeinfo>
#include<algorithm>
using namespace std;

//SLT是算法和数据结构的库
//第一层：熟用SLT
//第二层：了解泛型计数的内涵与SLT的学理乃至实作
//第三层：扩充SLT

//string
//可以认为是一个字符数组
//可以扩容可以增删查改


//身份证号码就是用string存的，因为有些身份证号码有X

void Test_string1()
{
	//常用
	string s1;
	string s2("ABCDEF");//构造
	string s3(s2);//拷贝构造
	string s4;
	s4 = s2;//赋值拷贝

	//了解
	cout << s4 << endl;
	cout << s3 << endl;
	string s5(s3, 0, 2);//在s5的0的位置拷贝一个两个字节大小的串,进行初始化
	cout << s5 << endl;
	string s6("hello world");
	string s7(s6, 0, 5);
	cout << s7 << endl;
	string s8(s7, 0);//如果传递两个参数就表示有多少拷贝多少
	cout << s8 << endl;
	string s9("hello world", 5);//取前面串的前n个字符
	cout << s9 << endl;
	string s10(10, 'x');//将后面的字符用来初始化n次
	cout << s10 << endl;
}

void Test_string2()
{
	string s1("hello world");//这是构造函数
	string s2 = "hello world";//隐式类型转换，先生成一个临时对象，然后再拷贝构造给s2.
	const string& s3 = "hello world";//临时对象有常性，所以必须在引用前面加const
}


//引用返回
//1.减少拷贝
//2.修改返回对象,返回的是别名，所以你改的就是s对应的那个所在的那个值

//operator[]既能遍历也能修改
void Test_string3()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;//和size()函数没有任何不同，答案都是一样的
	//最开始写的length，但是stl出来了之后，就写了个size，为了和stl保持一致

	//访问每个字符
	//不是主流的访问方式
	for (int i = 0;i < s1.size();i++)
	{
		cout << s1[i] << ' ';//[]是operator[]的重载
		//可以像数组一样使用，日期类不是整形但是可以++和--
	}
	//s1[s1.size() + 20];越界检查，直接报错
	cout << endl;
	//第一种遍历：下标+[]
	//for (int i = 0;i < s1.size();i++)
	//{
	//	s1[i]++;
	//	cout << s1[i];
	//}
	//第二种遍历：迭代器
	string::iterator it1 = s1.begin();
	//iterator:属于类域中的
	//迭代器才是主流，所有的容器都支持迭代器，但是下标访问只支持vector和string
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	cout << typeid(it1).name() << endl;
	//第三种访问方式：遍历数组用的范围for
	//底层的角度就是迭代器
	cout << "范围for:" << endl;
	for (auto e : s1)//所有容器都支持范围for
	{
		//e每个迭代器的拷贝，所以引用才能修改值
		cout << e;
	}
}

void Test_string5()
{
	const string s1("hello world");
	string::const_iterator it = s1.begin();//const_iterator表示内容不能修改
	//但是const iterator是迭代器不能++，迭代器不能++，就不能遍历了

	//这里也可以用auto
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		//const迭代器是给const_iterator专门用来遍历的
		//it可以修改，但是*it不能修改
		cout << *it1;//这里的*也是一个重载的函数并不是指针的意思
		it1++;
	}
	cout << endl;
	//反向迭代器
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
		//++是往左边走，底层就是重载operator++,就可以实现了
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
	//迭代器访问链表
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
//string也支持中文字符串

void Test_string6()
{
	string s1("hello world");
	cout << s1 << endl;
	//s1按字典序排序（意思就是按ASCII排）
	sort(s1.begin(), s1.end());//sort必须是左闭右开的区间，意思就是右边的区间不是一个有效的值

	//只想排一部分就可以是用迭代器++或者--

	//第一个和最后一个不参与排序
	sort(++s1.begin(), --s1.end());
	cout << s1 << endl;

	//前五个排序
	sort(s1.begin(), s1.begin() + 5);
}

//修改部分
void Test_string7()
{
	string s1("hello world");
	s1.push_back('A');
	//push_back是一个数据的插入一个数据的插入
	cout << s1 << endl;
	//append和构造的风格类似

	//下面是append用的最多的情形，append尾插一段字符串
	s1.append("yyyyyy");
	cout << s1 << endl;
	//重载运算符+=
	s1 += "dddddd";
	cout << s1 << endl;
	string s2("student");
	//+=是最好用的
	s1 += s2;
	cout << s1 << endl;

	//尾删
	s1.pop_back();
	cout << s1 << endl;

	//删除一段
	s1.erase(11);//保留前面多少个字节
	cout << s1 << endl;
}

//vector<char>和string的区别就是vector底层就是一个数据和一个数据
//string

int main()
{
	Test_string7();
	//string s2("hello world");
	//cout << sizeof(s2) << endl;
	return 0;
}