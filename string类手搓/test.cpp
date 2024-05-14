#include"string.h"

using namespace bit;


//void test_string1()
//{
//	bit::string s1("abcdefg");
//	bit::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//	const bit::string s2("aaaaaaaaaaaaaa");
//	bit::string::const_iterator it1 = s2.begin();
//	while (it1 != s2.end())
//	{
//		cout << *it1 << ' ';
//		it1++;
//	}
//	cout << endl;
//	cout << s2[1] << endl;
//
//
//	bit::string s3("hello world");
//	char s4[] = "abcd";
//	s3.insert(0, s4);
//	cout << s3.c_str() << endl;
//	size_t pos = s3.find('h');
//	cout << pos << endl;
//	size_t pos1 = s3.find("hello");
//	cout << pos1 << endl;
//}

int main()
{
	bit::string s1("hello world");
	bit::string s2(s1);//Ç³¿½±´

	cout << s2.c_str() << endl;
	bit::string s3("yyyyyyy");
	s1 = s3;
	cout << s1.c_str() << endl;
	bit::string s4 = s3.substr(0, 2);
	cout << s4.c_str() << endl;
	cout << s4 << endl;
	return 0;
}
