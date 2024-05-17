#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


namespace lyrics
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		vector(size_t n, const T& value = T())
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0;i < n;i++)
			{
				push_back(value);
			}
		}
		vector(int  n, const T& value = T())
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0;i < n;i++)
			{
				push_back(value);
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			size_t sz = last - first;
			reserve(sz);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0;i < v.size();i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage == _start + v.capacity();
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		bool empty()
		{
			return _start == _finish;
		}
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
				while (_finish != _end_of_storage)
				{
					*_finish = value;
					_finish++;
				}
			}
		}
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
			_finish = _end_of_storage = _start + sz;
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[] (size_t pos) const
		{
			return _start[pos];
		}
		T& front()
		{
			return *_start;
		}
		const T& front() const
		{
			return *_start;
		}
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back() const
		{
			return *(_finish - 1);
		}
		T& at(size_t pos)
		{
			return _start[pos];
		}
		const T& at(size_t pos) const
		{
			return _start[pos];
		}
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			size_t sz = last - first;
			T* tmp = new T[sz];
			for (size_t i = 0;i < sz;i++)
			{
				tmp[i] = *first;
				first++;
			}
			_start = tmp;
			_finish = _start + sz;
			_end_of_storage = _start + sz;
		}
		void assign(size_t n, const T& value = T())
		{
			T* tmp = new T[n];
			for (size_t i = 0;i < n;i++)
			{
				tmp[i] = value;
			}
			_start = tmp;
			_finish = _end_of_storage = _start + n;
		}
		void assign(int n, const T& value = T())
		{
			T* tmp = new T[n];
			for (int i = 0;i < n;i++)
			{
				tmp[i] = value;
			}
			_start = tmp;
			_finish = _end_of_storage = _start + n;
		}
		vector<T>& operator=(vector<T>& v)
		{
			assign(v.begin(), v.end());
			return *this;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator  cend()const
		{
			return _finish;
		}
		const_iterator cbegin()const
		{
			return _finish;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
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
				}
				delete[] _start;
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(_finish != _start);
			_finish--;
		}
		iterator insert(iterator pos, const T& value)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
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
			*pos = value;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				start++;
			}
			_finish--;
			return pos;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void clear()
		{
			_finish = _start;
		}
	private:
		iterator _start;
		iterator  _finish;
		iterator _end_of_storage;
	};
}