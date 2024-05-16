#pragma once
#pragma once

#include <iostream>
using namespace std;
#include <assert.h>

namespace lyrics
{
	template<class T>//ģ��
	class vector
	{
	public:
		typedef T* iterator;//������
		typedef const T* const_iterator;//const���͵ĵ�����
		//���캯��
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//�вι��캯��
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

		//����һ��int���͵Ĺ��캯��
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

		//�������乹��
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
		//�������캯��
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

		//��ֵ��������
		vector<T>& operator=(vector<T> v)
		{
			assign(v.begin(), v.end());
			return *this;
		}

		//��������
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		//������
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

		//������Ч���ݴ�С
		size_t size() const
		{
			return _finish - _start;
		}

		//������������С
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		//�п�
		bool empty() const
		{
			return _finish == _start;
		}

		//Ԥ���ٿռ�
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

		//�ı�size�Ĵ�С
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

		//[]����
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}

		//���ص�һ��Ԫ��
		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}

		//�������һ��ֵ
		T& back()
		{
			return _start[size() - 1];
		}
		const T& back()const
		{
			return _start[size() - 1];
		}

		//β��һ��ֵ
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

		//βɾһ��ֵ
		void pop_back()
		{
			assert(_finish != _start);
			_finish--;
		}
		//vector֮��Ľ���
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}
		//���λ�ò���
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
		//���λ�õ�ɾ��
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

		//����
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
		iterator _start;		// ָ�����ݿ�Ŀ�ʼ
		iterator _finish;		// ָ����Ч���ݵ�β
		iterator _endOfStorage;  // ָ��洢������β
	};
}