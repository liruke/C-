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
		//������
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
		//���캯��
		string(const char* str = "");
		string(const string& s);
		//��������
		~string();
		//
		const char* c_str() const;
		//���ش�С
		size_t size() const;
		//���������
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
		//���еľ�̬��Ա�������൱��ȫ�ֱ���
		//���������ȱʡֵ���Ǽ�������Ҳ�Ƕ���
		//const static size_t npos = -1;//��̬��Ա�������������������ⶨ��
		//���ﾲ̬��Ա�������Ը�ȱʡֵ����Ϊ ���ﲻ���߳�ʼ���б���Ϊ��ʼ���б���û�����
		//��̬��Ա

		const static size_t npos;
		//ֻ�����ο��Խ���
		//const static double N = 2.2;
	};
	istream& operator>>(istream& is, string& str);
	ostream& operator<<(ostream& is, string& str);
	//��.cpp�а���һ�ݣ�һ�������ݣ������������Ӵ���
}