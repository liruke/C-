#pragma once
#pragma once

#include <iostream>
using namespace std;
#include <assert.h>

namespace lyrics
{
	template<class T>//模版
	class vector
	{
	public:
		typedef T* iterator;//迭代器
		typedef const T* const_iterator;//const类型的迭代器
		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//有参构造函数
		vector(size_t n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0;i < n;i++)
			{
				push_back(value);
			}
		}

		//重载一个int类型的构造函数
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			for (int i = 0;i < n;i++)
			{
				push_back(value);
			}
		}

		//迭代区间构造
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//拷贝构造函数
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0;i < v.size();i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}

		//赋值拷贝函数
		vector<T>& operator=(vector<T> v)
		{
			assign(v.begin(), v.end());
			return *this;
		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		//迭代器
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		//返回有效数据大小
		size_t size() const
		{
			return _finish - _start;
		}

		//返回总容量大小
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		//判空
		bool empty() const
		{
			return _finish == _start;
		}

		//预开辟空间
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0;i < sz;i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + n;
			}
		}

		//改变size的大小
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _endOfStorage)
				{
					*_finish = value;
					_finish++;
				}
			}
		}

		//[]重载
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}

		//返回第一个元素
		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}

		//返回最后一个值
		T& back()
		{
			return _start[size() - 1];
		}
		const T& back()const
		{
			return _start[size() - 1];
		}

		//尾插一个值
		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

		//尾删一个值
		void pop_back()
		{
			assert(_finish != _start);
			_finish--;
		}
		//vector之间的交换
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}
		//随机位置插入
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t len = _start - pos;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			_finish++;
			return pos;
		}
		//随机位置的删除
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator first = pos + 1;
			while (first != _finish)
			{
				*(first - 1) = *first;
				first++;
			}
			_finish--;
			return pos;
		}
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			size_t sz = last - first;
			T* tmp = new T[sz];
			for (int i = 0;i < sz;i++)
			{
				tmp[i] = *(first + i);
			}
			_start = tmp;
			_finish = _endOfStorage = _start + sz;
		}
		void assign(size_t n, const T& val)
		{
			T* tmp = new T[n];
			for (size_t i = 0;i < n;i++)
			{
				tmp[i] = val;
			}
			delete[] _start;
			_start = tmp;
			_finish = _endOfStorage = tmp + n;
		}
		void assign(int n, const T& val)
		{
			T* tmp = new T[n];
			for (int i = 0;i < n;i++)
			{
				tmp[i] = val;
			}
			delete[] _start;
			_start = tmp;
			_finish = _endOfStorage = tmp + n;
		}

		//缩容
		void shrink_to_fit()
		{
			size_t sz = size();
			T* tmp = new T[sz];
			for (size_t i = 0;i < sz;i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + sz;
		}
		void clear()
		{
			_finish = _start;
		}
	private:
		iterator _start;		// 指向数据块的开始
		iterator _finish;		// 指向有效数据的尾
		iterator _endOfStorage;  // 指向存储容量的尾
	};
}