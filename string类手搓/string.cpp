#include"string.h"


//��׿�ĵײ���Linux��Linux���õ�
//npos��.h�ļ�����,��.cpp�ļ����塣
namespace bit
{
	const size_t string::npos = -1;//ȫ�ֱ���
	//string::string()
	//{
	//	_str = new char[1] {'\0'};
	//	_size = _capacity = 0;
	//}
	string::string(const char* str)//ָ������
		//strlen��Ч�ʺܵ�
		//��ʼ���б�+д���ڲ�����
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

	//��������
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	//���ش�С
	size_t string::size() const
	{
		return _size;
	}
	//��ͨ�汾��[]
	char& string::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];//����posλ�õ��ַ�
	}

	//��ͨ�汾�ĵ�����
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}

	//const�汾�ĵ�����
	string::const_iterator string::begin()const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return _str + _size;
	}

	//const�汾��[]����
	const char& string::operator[](size_t pos)const
	{
		return _str[pos];
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			//���¿ռ�
			char* tmp = new char[n + 1];
			//��������
			strcpy(tmp, _str);
			//�ͷ��¿ռ�
			delete[] _str;
			//ָ���¿ռ�
			_str = tmp;
			//��������
			_capacity = n;
		}
	}
	//β��һ���ַ�
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
	//β��һ���ַ���
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_capacity == _size)
		{
			reserve(_size + len);//��ǰ��size+len
		}
		//strcat(_str, str);//Ч�ʲ���
		//�ӵ�ǰλ�ÿ�ʼ�Լ�ȥ��\0������Ч�ʲ���
		strcpy(_str + _size, str);//_str+_size����\0��λ��
		_size += len;
	}

	//���������
	//�����÷��س������������������
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
		while (end > pos)//��Ϊ�з��ź��޷��űȽϣ��������Ͳ�ͬ�Ὣ�з���ǿ������ת�����޷���
			//��������ֱ�Ӱ�posǿ������ת����int
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
			reserve(_size + len);//��ǰ��size+len
		}
		//��һ�ַ���
		//int end = len - 1;
		//while (end >= 0)
		//{
		//	insert(pos, str[end]);
		//	end--;
		//}
		size_t end = _size + len;//�ҵ�����ĺ�һ��λ��
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			end--;
		}
		memcpy(_str + pos, str, len);
		_size += len;
	}
	//��posλ��ɾ��len���ַ�
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//��ɾ���ĳ���len���ں���ĳ��ȵ�ʱ��
		//ֱ�ӰѺ����ɾ��
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos + len);//ֱ�ӰѺ����copy��ǰ��
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
	//���
	string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	//һ������swap������һ����string�ķǳ�Ա������swap����֤string������ʱ���Ч��
	void string::swap(string& s)
	{
		//�������ͽ������۸�С
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string string::substr(size_t pos, size_t len)
	{
		//���pos�Ƿ�Ϸ�
		assert(pos <= _size);
		//���len���ں���ĳ�����ô�ͺ����ж���ȡ����
		if (len > _size - pos)
		{
			//ֱ��ȡ������Ӵ�
			string sub(_str + pos);//��posλ�ÿ�ʼ���п������죡������
			//�����Ӵ�
			return sub;
		}
		else
		{
			//�����Ӵ�
			string sub;
			//Ԥ���ٿռ�
			sub.reserve(len);
			//ѭ������
			for (size_t i = 0;i < len;i++)
			{
				sub += _str[pos + i];
			}
			//�����Ӵ�
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