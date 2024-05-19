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
			:_prev(nullptr)
			,_next(nullptr)
			,_data(val)
		{

		}
	};
	//这里封装一个类，用来控制list的迭代器
	template<class T,class Ref,class Ptr>
	//Ref表示引用是否const
	//Ptr表示指针是否const
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> self;
		node* _node;
		//构造函数
		list_iterator(node* n = nullptr) :_node(node) {}

		//重载迭代器的基本操作
		//operator*用来访问迭代器对应的当前的数据
		//返回值应该是引用，我们的引用用的是Ref
		Ref operator*()const
		{
			return _node->_data;
		}

		//重载一个operator->防止list对应的是自定义类型的时候需要访问自定义类型的数据
		Ptr operator->()
		{
			return &operator*();
		}

		//重载一个++操作，因为在迭代器遍历的时候需要用到++这个操作对迭代器进行移动
		//前置++
		self& operator++()//传递引用防止拷贝构造
		{
			_node = _node->_next;
			return *this;
		}
		//后置++
		self operator++(int)
		{
			self tmp(*this);
			++*this;
			return tmp;
		}
		//前置--
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		self operator--(int)
		{
			self tmp(*this);
			--*this;
			return tmp;
		}
		//除了上面的操作还需要一个！=和==因为我们要判断是否迭代器多久停止
		bool operator==(const self& s)const
		{
			return _node == s._node;
		}
		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}
	};
	//上面封装了正向迭代器接下来封装反向迭代器

	template<class iterator, class Ref, class Ptr>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<iterator, Ref, Ptr> self;
		list_reverse_iterator(iterator it) :_cur(it) {}

		//重载反向迭代器的运算符
		Ref operator*()
		{
			//由于我们的成员变量是正向迭代器，但是我们的反向迭代器是从最后一个开始遍历的
			iterator tmp = _cur;
			tmp--;
			return *tmp;//这里应该返回的是iterator重载的*
		}
		Ptr operator->()
		{
			return &operator*();
		}
		//反向迭代器的++是--
		self& operator++()
		{
			--_cur;
			return *this;
		}
		self operator++(int)
		{
			iterator tmp = _cur;
			--*this;
			return tmp;
		}
		//反向迭代器的--是++
		self& operator--()
		{
			++_cur;
			return *this;
		}
		self operator--(int)
		{
			iterator tmp(_cur);
			--*this;//这里的--是复用上面的运算符重载
			return tmp;
		}
		bool operator!=(const self& s)const
		{
			//这里可以直接复用正向迭代器已经实现的！=操作
			return _cur != s._cur;
		}
		bool operator==(const self& s)const
		{
			return _cur == s._cur;
		}
		iterator _cur;
	};
	template<class T>
	class list
	{
	public:
		typedef list_node<T> node;
		//封装两个正向迭代器
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<const T, const T&, const T*> const_iterator;
		//封装两个反向迭代器
		typedef list_reverse_iterator<T, T&, T*> reverse_iterator;
		typedef list_reverse_iterator<const T, const T&, const T*> const_reverse_iterator;
		iterator begin()
		{
			//因为是双向带头的链表，又因为是左闭右开，所以应该用head指向下一个，传递给begin
			return iterator(_head->_next);
		}
		iterator end()
		{
			//左闭右开的缘故，所以这里传递的是head，因为实际访问不到head
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
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
		list(size_t n, const T& val = T())
		{
			empty_init();
			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
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
		list<T>& operator= (const list<T>& x)
		{
			list<T> tmp(x);
			swap(tmp, *this);
			return *this;
		}
		bool empty() const
		{
			return _head->_next == _head;
		}
		size_t size() const
		{
			size_t count = 0;
			for (auto e : *this)
			{
				count++;
			}
			return count;
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			//先删除所有节点，只剩下一个哨兵位节点
			clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
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
		iterator insert(iterator pos, const T& val = T())
		{
			//插入新的值，应该创建一个新的节点
			node* newnode = new node(val);
			node* next = pos._node->_next;
			node* prev = pos._node->_prev;
			newnode->_next = next;
			newnode->_prev = prev;
			next->_prev = newnode;
			prev->_next = newnode;
			//这里返回的是构造函数
			//用newnode重新构造了一个迭代器
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			node* next = pos._node->_next;
			node* prev = pos._node->_prev;
			delete pos._node;
			next->_prev = prev;
			prev->_next = next;
			return iterator(next);
		}
		void push_back(const T& val = T())
		{
			insert(_head->_prev, val);
		}
		void pop_back()
		{
			erase(_head->_prev);
		}
		void push_front(const T& val = T())
		{
			insert(_head->_next,val);
		}
		void pop_front()
		{
			erase(_head->_next);
		}
		void swap(list<T>& x)
		{
			std::swap(_head, x._head);
		}
		void resize(size_t n, T val = T())
		{
			size_t sz = size();
			while(n < sz)
			{
				pop_back();
				sz--;
			}
			while (n > sz)
			{
				push_back(val);
				sz++;
			}
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
	private:
		node* _head;
		void empty_init()
		{
			_head = new node;
			_head->_next = nullptr;
			_head->_prev = nullptr;
		}
	};
}