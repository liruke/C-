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
	//�����װһ���࣬��������list�ĵ�����
	template<class T,class Ref,class Ptr>
	//Ref��ʾ�����Ƿ�const
	//Ptr��ʾָ���Ƿ�const
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> self;
		node* _node;
		//���캯��
		list_iterator(node* n = nullptr) :_node(node) {}

		//���ص������Ļ�������
		//operator*�������ʵ�������Ӧ�ĵ�ǰ������
		//����ֵӦ�������ã����ǵ������õ���Ref
		Ref operator*()const
		{
			return _node->_data;
		}

		//����һ��operator->��ֹlist��Ӧ�����Զ������͵�ʱ����Ҫ�����Զ������͵�����
		Ptr operator->()
		{
			return &operator*();
		}

		//����һ��++��������Ϊ�ڵ�����������ʱ����Ҫ�õ�++��������Ե����������ƶ�
		//ǰ��++
		self& operator++()//�������÷�ֹ��������
		{
			_node = _node->_next;
			return *this;
		}
		//����++
		self operator++(int)
		{
			self tmp(*this);
			++*this;
			return tmp;
		}
		//ǰ��--
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//����--
		self operator--(int)
		{
			self tmp(*this);
			--*this;
			return tmp;
		}
		//��������Ĳ�������Ҫһ����=��==��Ϊ����Ҫ�ж��Ƿ���������ֹͣ
		bool operator==(const self& s)const
		{
			return _node == s._node;
		}
		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}
	};
	//�����װ�������������������װ���������

	template<class iterator, class Ref, class Ptr>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<iterator, Ref, Ptr> self;
		list_reverse_iterator(iterator it) :_cur(it) {}

		//���ط���������������
		Ref operator*()
		{
			//�������ǵĳ�Ա������������������������ǵķ���������Ǵ����һ����ʼ������
			iterator tmp = _cur;
			tmp--;
			return *tmp;//����Ӧ�÷��ص���iterator���ص�*
		}
		Ptr operator->()
		{
			return &operator*();
		}
		//�����������++��--
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
		//�����������--��++
		self& operator--()
		{
			++_cur;
			return *this;
		}
		self operator--(int)
		{
			iterator tmp(_cur);
			--*this;//�����--�Ǹ�����������������
			return tmp;
		}
		bool operator!=(const self& s)const
		{
			//�������ֱ�Ӹ�������������Ѿ�ʵ�ֵģ�=����
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
		//��װ�������������
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<const T, const T&, const T*> const_iterator;
		//��װ�������������
		typedef list_reverse_iterator<T, T&, T*> reverse_iterator;
		typedef list_reverse_iterator<const T, const T&, const T*> const_reverse_iterator;
		iterator begin()
		{
			//��Ϊ��˫���ͷ����������Ϊ������ҿ�������Ӧ����headָ����һ�������ݸ�begin
			return iterator(_head->_next);
		}
		iterator end()
		{
			//����ҿ���Ե�ʣ��������ﴫ�ݵ���head����Ϊʵ�ʷ��ʲ���head
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
			//��ɾ�����нڵ㣬ֻʣ��һ���ڱ�λ�ڵ�
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
			//�����µ�ֵ��Ӧ�ô���һ���µĽڵ�
			node* newnode = new node(val);
			node* next = pos._node->_next;
			node* prev = pos._node->_prev;
			newnode->_next = next;
			newnode->_prev = prev;
			next->_prev = newnode;
			prev->_next = newnode;
			//���ﷵ�ص��ǹ��캯��
			//��newnode���¹�����һ��������
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