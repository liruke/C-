#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void Test_String1()
{
	//assign属于一种赋值行为
	string s1("hello world");
	cout << s1 << endl;
	s1.assign("111111");//相当于赋值，直接覆盖了
	cout << s1 << endl;
}

void Test_string2()
{

	//insert慎用->时间复杂度是O(N)效率不高
	//实践中，需求也不高
	string s1("hello world ");
	s1.insert(0, "xxx");
	cout << s1 << endl;

	//普通版本
	s1.insert(0, 1, 'y');//在0的位置插入一个字符
	cout << s1 << endl;

	//迭代器版本
	s1.insert(s1.begin(), 'y');
	cout << s1 << endl;

	string s2("11111");
	s1.insert(s1.begin(), s2.begin(), s2.end());//在s1的位置插入一个迭代器，迭代器指向的位置是s2的begin到s2的end位置
	cout << s1 << endl;
}

void Test_string3()
{
	//erase慎用，效率不高，因为要挪动顺序，所以时间复杂度就是O(N)
	//如果erase删除的len大于字符串的长度，则有多少删多少，
	string s1("hello world");
	cout << s1 << endl;
	s1.erase(0, 1);//头删一个字符
	cout << s1 << endl;
	s1.erase(3, 2);
	cout << s1 << endl;
	s1.erase(0, 100);
	cout << s1 << endl;//空
	//注意：下标位置必须是合法的

	//替换
	string s2("hello world");
	s2.replace(5, 1, "%20");
	cout << s2 << endl;;
	string s3("hello world hello bit");
	cout << s3 << endl;
	for (size_t i = 0;i < s3.size();i++)
	{
		if (s3[i] == ' ')
		{
			s3.replace(i, 1, "%20");//挪动数据，时间复杂度是O(Z)
		}
	}
	cout << s3 << endl;
	//空间换时间，重新开一个空间
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