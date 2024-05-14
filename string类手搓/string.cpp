#include"string.h"


//安卓的底层是Linux是Linux剪裁的
//npos在.h文件声明,在.cpp文件定义。
namespace bit
{
	const size_t string::npos = -1;//全局变量
	//string::string()
	//{
	//	_str = new char[1] {'\0'};
	//	_size = _capacity = 0;
	//}
	string::string(const char* str)//指定类域
		//strlen的效率很低
		//初始化列表+写在内部函数
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}
	string& string::operator=(const string& s)
	{
		char* tmp = new char[s._capacity + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}

	const char* string::c_str() const
	{
		return _str;
	}

	//析构函数
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	//返回大小
	size_t string::size() const
	{
		return _size;
	}
	//普通版本的[]
	char& string::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];//返回pos位置的字符
	}

	//普通版本的迭代器
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}

	//const版本的迭代器
	string::const_iterator string::begin()const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return _str + _size;
	}

	//const版本的[]重载
	const char& string::operator[](size_t pos)const
	{
		return _str[pos];
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			//开新空间
			char* tmp = new char[n + 1];
			//拷贝数据
			strcpy(tmp, _str);
			//释放新空间
			delete[] _str;
			//指向新空间
			_str = tmp;
			//更新容量
			_capacity = n;
		}
	}
	//尾插一个字符
	void string::push_back(char ch)
	{
		if (_capacity == _size)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	//尾插一个字符串
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_capacity == _size)
		{
			reserve(_size + len);//当前的size+len
		}
		//strcat(_str, str);//效率不高
		//从当前位置开始自己去找\0，所以效率不高
		strcpy(_str + _size, str);//_str+_size就是\0的位置
		_size += len;
	}

	//运算符重载
	//传引用返回出了作用域这个对象还在
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_capacity == _size)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		size_t end = _size + 1;
		while (end > pos)//因为有符号和无符号比较，两个类型不同会将有符号强制类型转换成无符号
			//所以这里直接把pos强制类型转换成int
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_capacity == _size)
		{
			reserve(_size + len);//当前的size+len
		}
		//第一种方法
		//int end = len - 1;
		//while (end >= 0)
		//{
		//	insert(pos, str[end]);
		//	end--;
		//}
		size_t end = _size + len;//找到插入的后一个位置
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			end--;
		}
		memcpy(_str + pos, str, len);
		_size += len;
	}
	//从pos位置删除len个字符
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//当删除的长度len大于后面的长度的时候
		//直接把后面的删完
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos + len);//直接把后面的copy到前面
			_size -= len;
		}
	}
	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = pos;i < _size;i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* sub, size_t pos)
	{
		const char* str = strstr(_str + pos, sub);
		return str - _str;
	}
	//深拷贝
	string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	//一共三个swap，还有一个是string的非成员函数的swap，保证string交换的时候的效率
	void string::swap(string& s)
	{
		//内置类型交换代价更小
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string string::substr(size_t pos, size_t len)
	{
		//检查pos是否合法
		assert(pos <= _size);
		//如果len大于后面的长度那么就后面有多少取多少
		if (len > _size - pos)
		{
			//直接取后面的子串
			string sub(_str + pos);//从pos位置开始进行拷贝构造！！！！
			//返回子串
			return sub;
		}
		else
		{
			//构造子串
			string sub;
			//预开辟空间
			sub.reserve(len);
			//循环拷贝
			for (size_t i = 0;i < len;i++)
			{
				sub += _str[pos + i];
			}
			//返回子串
			return sub;
		}
	}
	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)const
	{
		return *this < s || *this == s;
	}
	bool string::operator>(const string& s)const
	{
		return !(*this <= s);
	}
	bool string::operator>=(const string& s)const
	{
		return !(*this < s);
	}
	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s._str);
	}
	istream& operator>>(istream& is, string& str)
	{
		str.clear();
		char ch = is.get();
		while (ch != ' '&& ch != '\n')
		{
			str += ch;
		}
		return is;
	}
	ostream& operator<<(ostream& os, string& str)
	{
		for (size_t i = 0;i < str.size();i++)
		{
			os << str[i];
		}
		return os;
	}
	void string::clear()
	{
		_str = '\0';
		_size = 0;
	}

}