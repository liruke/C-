#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<assert.h>
#include<string>
using namespace std;


namespace lyrics
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				for (size_t i = 0;i < sz;i++)
				{
					tmp[i] = _start[i];
					//调用swap也可以
					//std::swap(tmp[i], _start[i]);
				}
				delete[] _start;//释放以前的空间
				_start = tmp;//指向新的空间
				//更新finish和end of storage
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& val = T())
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = val;
			_finish++;
		}
		//这里不能用0初始化，直接给一个默认构造的匿名对象
		//内置类型也可以这样写
		vector(size_t n,const T& val=T())
		{
			for (int i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			for (int i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		//类模版的成员函数，可以用模版参数T，再增加模版参数写成函数
		//如果写iterator就只能用vector的迭代器来进行迭代区间初始化
		//如果用新的函数模版，那么就支持其他类的迭代器区间初始化
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (auto e : il)
			{
				push_back(e);
			}
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//如不写则是浅拷贝
		//拷贝构造也是一种构造
		vector(const vector<T>& v)
		{
			for (auto e : v)
			{
				push_back(e);
			}
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}
		//v1=v3
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		bool empty()
		{
			return _finish == _start;
		}
		void shrink_to_fit()
		{
			size_t sz = size();
			T* tmp = new T[size()];
			for (int i = 0;i < size();i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _end_of_storage = _start + sz;
		}
		void pop_back()
		{
			assert(_finish != _start);
			_finish--;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				while (n < size())
				{
					n++;
					pop_back();
				}
			}
			else
			{
				while (n > size())
				{
					push_back(val);
					n--;
				}
			}
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			size_t sz = last - first;
			T* tmp = new T[sz];
			int i = 0;
			while (first != last)
			{
				tmp[i++] = *first;
				first++;
			}
			delete[] _start;
			_start = tmp;
			_finish = _end_of_storage = _start + sz;
		}
		void assign(size_t n, const T& val = T())
		{
			T* tmp = new T[n];
			for (int i = 0;i < n;i++)
			{
				tmp[i] = val;
			}
			delete[] _start;
			_start = tmp;
			_finish = _end_of_storage = _start + n;
		}
		void assign(int n, const T& val = T())
		{
			T* tmp = new T[n];
			for (int i = 0;i < n;i++)
			{
				tmp[i] = val;
			}
			delete[] _start;
			_start = tmp;
			_finish = _end_of_storage = _start + n;
		}
		iterator insert(iterator pos, const T& val = T())
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			if (_finish == _end_of_storage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + sz;
			}
			iterator last = end();
			while (last != pos)
			{
				*last = *(last - 1);
				last--;
			}
			_finish++;
			*pos = val;
			return pos;
		}
		//这里我们都认为erase删除的pos失效了，所以要返回下一个迭代器
		//因为，我们不知道它删除了元素之后缩不缩容
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			assert(pos >= _start);
			iterator first = pos;
			while (first != end())
			{
				*first = *(first + 1);
				first++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}