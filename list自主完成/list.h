#pragma once
#include<iostream>
using namespace std;

namespace lyrics
{
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _data;
		list_node(const T& val = T())
		{
			_prev = nullptr;
			_next = nullptr;
			_data = val;
		}
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> self;
		typedef list_node<T> node;
		node* _node;
		list_iterator(node* n)
			:_node(n)
		{

		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &operator*();
		}
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			++*this;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			--*this;
			return tmp;
		}
		bool operator==(const self& s)const
		{
			return _node == s._node;
		}
		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}
	};

	template<class T,class Ref,class Ptr>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<T, Ref, Ptr> self;
		typedef list_iterator<T, Ref, Ptr> iterator;
		iterator _cur;
		list_reverse_iterator(iterator it) :_cur(it) {}

		Ref operator*()
		{
			iterator tmp(*this);
			--tmp;
			return *tmp;
		}
		self operator->()
		{
			return &operator*();
		}
		self& operator++()
		{
			--_cur;
			return *this;
		}
		self operator++(int)
		{
			iterator tmp(_cur);
			--_cur;
			return tmp;
		}
		self& operator--()
		{
			++_cur;
			return *this;
		}
		self operator--(int)
		{
			iterator tmp(_cur);
			++_cur;
			return tmp;
		}
		bool operator==(const self& s)const
		{
			return _cur == s._cur;
		}
		bool operator!=(const self& s)const
		{
			return _cur != s._cur;
		}
	};
	template<class T>
	class list
	{
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<const T, const T&, const T*> const_iterator;
		typedef list_reverse_iterator<T, T&, T*> reverse_iterator;
		typedef list_reverse_iterator<const T, const T&, const T*> const_reverse_iterator;
		typedef list_node<T> node;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator emd()
		{
			return const_iterator(_head);
		}
		reverse_iterator rbegin() 
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}
		list()
		{
			empty_init();
		}
		list(size_t n, const T& value = T())
		{
			empty_init();
			for (size_t i = 0;i < n;i++)
			{
				push_back(value);
			}
		}
		list(int n, const T& value = T())
		{
			empty_init();
			for (int i = 0;i < n;i++)
			{
				push_back(value);
			}
		}
		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const list<T>& x)
		{
			empty_init();
			for (auto e : x)
			{
				push_back(e);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		list<T>& operator=(list<T> x)
		{
			swap(x);
			return *this;
		}
		bool empty()
		{
			return _head->_next == _head;
		}
		size_t size()
		{
			size_t count = 0;
			for (auto e : *this)
			{
				count++;
			}
			return count;
		}
		void assign(size_t n, const T& val = T())
		{
			clear();
			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		void assign(int n, const T& val = T())
		{
			clear();
			for (int i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		iterator insert(iterator pos, const T& val = T())
		{
			node* prev = pos._node->_prev;
			node* newnode = new node(val);
			node* cur = pos._node;
			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			node* next = pos._node->_next;
			node* prev = pos._node->_prev;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		void push_back(const T& val = T())
		{
			insert(end(), val);
		}
		void push_front(const T& val = T())
		{
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void swap(list<T>& x)
		{
			std::swap(_head, x._head);
		}
		void resize(size_t n, const T& val = T())
		{
			while(n < size())
			{
				pop_back();
				n++;
			}
			while (n > size())
			{
				push_back(val);
				n--;
			}
		}
		void clear()
		{
			iterator first = begin();
			iterator last = end();
			while (first != last)
			{
				first = erase(first);
			}
		}
	private:
		node* _head;
		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	};
}
