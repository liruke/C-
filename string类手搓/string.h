#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//迭代器
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
		//构造函数
		string(const char* str = "");
		string(const string& s);
		//析构函数
		~string();
		//
		const char* c_str() const;
		//返回大小
		size_t size() const;
		//运算符重载
		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t = 0, size_t len = npos);


		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		string& operator=(const string& s);

		void swap(string& s);

		string substr(size_t pos = 0, size_t = npos);

		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator==(const string& s)const;

		void clear();
	private:
		//char _buff[16]
		size_t _size;
		size_t _capacity;

		char* _str;
		//类中的静态成员变量就相当于全局变量
		//下面如果给缺省值就是既是声明也是定义
		//const static size_t npos = -1;//静态成员变量在类中声明在类外定义
		//这里静态成员变量可以给缺省值，因为 这里不会走初始化列表，因为初始化列表中没有这个
		//静态成员

		const static size_t npos;
		//只有整形可以进行
		//const static double N = 2.2;
	};
	istream& operator>>(istream& is, string& str);
	ostream& operator<<(ostream& is, string& str);
	//在.cpp中包含一份，一共有两份，所以最后会链接错误
}