#include "MockString.h"

//构造与析构相关函数
MockString::string::string(const char* str)//字符串及无参构造
{
	_size = strlen(str);
	_capacity = _size;

	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

//MockString::string::string(const string& s)//拷贝构造的传统写法
//{
//	_size = s._size;
//	_capacity = s._capacity;
//	
//	_str = new char[_capacity + 1];
//	strcpy(_str, s._str);
//}

MockString::string::string(const string& s)//拷贝构造的现代（常用）写法
	:_str(nullptr)
	,_size(0)
	,_capacity(0)
{
	string tmp(s._str);
	swap(tmp);
}

MockString::string& MockString::string::operator=(const char* str)//运算符=重载
{
	size_t len = strlen(str);
	if (_capacity < len)
	{
		reserve(len);
	}
	strcpy(_str, str);
	_size = len;

	return *this;
}

//MockString::string& MockString::string::operator=(const string& s)//“=”运算符类类型重载的传统写法
//{
//	if (this != &s)
//	{
//		char* tmp = new char[s._capacity + 1];
//		strcpy(tmp, s._str);
//
//		delete[] _str;
//		_str = tmp;
//
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	
//	return *this;
//}

MockString::string& MockString::string::operator=(string s)//“=”运算符类类型重载的现代（常用）写法
{
	swap(s);
	return *this;
}

MockString::string::~string()//析构函数
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

//iterator迭代器实现
MockString::string::iterator MockString::string::begin()//iterator的begin（）迭代
{
	return _str;
}

MockString::string::iterator MockString::string::end()//iterator的end（）迭代
{
	return _str + _size;
}

//modify修改字符串相关函数
void MockString::string::push_back(char ch)//单字符插入
{
	if (_size == _capacity)//容量不够扩容
	{
		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
		reserve(newcapacity);
	}
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
}

MockString::string& MockString::string::operator+=(char ch)//运算符+=重载
{
	push_back(ch);

	return *this;
}

void MockString::string::append(const char* str)//字符串插入
{
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		size_t newcapacity = _capacity + len;
		reserve(newcapacity);
	}
	
	strcpy(_str + _size, str);
	_size += len;
}

MockString::string& MockString::string::operator+=(const char* str)//字符串插入的运算符+=重载
{
	append(str);

	return *this;
}

void MockString::string::clear()//清除字符串函数
{
	memset(_str, '\0', sizeof(char) * _size);
	_size = 0;
}

void MockString::string::swap(string& s)//类的字符串交换
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

void MockString::string::insert(size_t pos, char ch)//在pos位置插入ch字符
{
	assert(pos <= _size);
	
	size_t end = _size;

	if (_size + 1 > _capacity)
		reserve((_size + 1) * 2);

	while (pos < end)
	{
		_str[end] = _str[end - 1];
		end--;
	}

	_str[pos] = ch;
	++_size;
	_str[_size] = '\0';
}

void MockString::string::insert(size_t pos, const char* s)//在pos位置插入一个字符串
{
	assert(pos <= _size);

	size_t len = strlen(s);
	size_t end = _size + len;

	if (end > _capacity)
		reserve(end * 2);

	while (end >= pos + len)
	{
		_str[end] = _str[end - len];
		--end;
	}

	strncpy(_str + pos, s, len);

	//size_t i = 0;
	//size_t tmp = pos;
	//while (s[i] != '\0')
	//{
	//	_str[tmp] = s[i];
	//	++tmp;
	//	++i;
	//}

	_size += len;
	_str[_size] = '\0';
}

MockString::string& MockString::string::erase(size_t pos, size_t len)//在pos位置删除len个字符
{
	assert(pos <= _size);

	if (len >= _size - pos)//全删除或未传参时用于全部删除，直接在pos位置赋‘\0’
	{
		_str[pos] = '\0';
		_size = pos;

		return *this;
	}

	size_t end = pos + len;
	size_t i = pos;

	while (_str[end] != '\0')//部分删除
	{
		_str[i] = _str[end];
		++i;
		++end;
	}

	_size -= len;
	_str[_size] = '\0';
	return *this;
}

//capacity数据个数、容量等相关函数
void MockString::string::reserve(size_t capacity)//空间扩容
{
	char* str = new char[capacity + 1];//多一个空间的原因是capacity是有效字符空间，不包含‘\0'
	strcpy(str, _str);                 //多的一个空间是为了存储'\0'

	delete[] _str;
	_str = str;
	_capacity = capacity;
}

size_t MockString::string::size()const//返回字符串个数
{
	return _size;
}

size_t MockString::string::capacity()const//返回字符串对应的空间容量
{
	return _capacity;
}

bool MockString::string::empty()//判断空间是否满
{
	return (_size == _capacity);
}

void MockString::string::resize(size_t n, char ch)//将字符串长度设置为n，如果新长度比原长度长，则长的部分用ch补充
{
	if (n <= _size)//设置的值小于原字符串长度
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n <= _capacity && n > _size)//设置的值大于原字符串长度但小于容量
		{
			if (_str[0] == '\0')
			{
				memset(_str, ch, sizeof(char) * (n - _size));
				_str[n - _size] = '\0';
			}
			else
			{
				memset(_str + _size, ch, sizeof(char) * (_capacity - _size));
				_str[n] = '\0';
			}
			_size = n;
		}
		else if (n > _capacity)//设置的值大于容量
		{
			reserve(n);

			if (_str[0] == '\0')
			{
				memset(_str, ch, sizeof(char) * (n - _size));
				_str[n - _size] = '\0';
			}				
			else
			{
				memset(_str + _size, ch, sizeof(char) * (_capacity - _size));
				_str[n] = '\0';
			}			
			_size = n;
		}
	}
}

const char* MockString::string::c_str()//返回数据的地址
{
	return _str;
}

// access支持用"[]"的形式访问字符串
char& MockString::string::operator[](size_t pos)//[]运算符重载，支持字符串下标形式获取
{
	assert(pos < _size);

	return _str[pos];
}

const char& MockString::string::operator[](size_t pos)const//[]运算符重载，支持常量字符串下标形式获取
{
	assert(pos < _size);

	return _str[pos];
}

//relational operators判断运算符重载函数
bool MockString::string::operator<(const string& s)const//“<”运算符重载
{
	size_t i = 0;
	while (_str[i] != '\0' || s._str[i] != '\0')
	{
		if (_str[i] == s._str[i])
			++i;
		else
		{
			if (_str[i] < s._str[i])
				return 1;
			else
				return 0;
		}
	}
	if (s._str[i] == '\0')
		return 0;

	return 1;
}

bool  MockString::string::operator<=(const string& s)const//“<=”运算符重载
{
	size_t i = 0;
	while (_str[i] != '\0' || s._str[i] != '\0')
	{
		if (_str[i] == s._str[i])
			return 1;
		else
		{
			if (_str[i] < s._str[i])
				return 1;
			else
				return 0;
		}
		++i;
	}
	return 1;
}

bool MockString::string::operator>(const string& s)const//“>”运算符重载
{
	return !(*this <= s);
}

bool MockString::string::operator>=(const string& s)const//“>=”运算符重载
{
	return !(*this < s);
}

bool MockString::string::operator==(const string& s)const//“==”运算符重载
{
	size_t i = 0;
	while (_str[i] != '\0' || s._str[i] != '\0')
	{
		if (_str[i] == s._str[i])
			return 1;
		else
			return 0;

		++i;
	}

	return 1;
}

bool MockString::string::operator!=(const string& s)const//“!=”运算符重载
{
	return !(*this == s);
}

//operations查找相关函数
size_t MockString::string::find(char ch, size_t pos)const//从pos位置开始查找以一个ch字符
{
	assert(pos < _size);
	for (size_t i = pos; i < _size; ++i)
	{
		if (_str[i] == ch)
			return i;

		++i;
	}
	return npos;
}

size_t MockString::string::find(const char* s, size_t pos)const//从pos位置开始查找一个字符串
{															  //并返回第一个字符的下标
	if (_size == 0 && s[0] == '\0')
		return 0;
	else
		assert(pos < _size);

	size_t i = pos;
	while (_str[i] != '\0' && s[0] != '\0')
	{
		size_t per = 0;
		if (_str[i] == s[per])
		{
			size_t rem = i;
			while (_str[rem] == s[per])
			{
				++per;
				++rem;

				if (s[per] == '\0')
					return i;
				else if ((s[per] != '\0' && _str[rem] == '\0'))
					return npos;
			}

			i = rem;
		}
		++i;
	}
	if (_str[0] == '\0' && s[0] == '\0')
		return 0;
	else
		return npos;
}

istream& MockString::operator>>(istream& in, MockString::string& s)//流提取>>运算符重载
{
	//char ch = in.get();

	//while (ch != ' ' && ch != '\n')
	//{
	//	s += ch;
	//	char ch = in.get();
	//}

	char tmp[128] = { '\0' };
	size_t i = 0;
	char ch = in.get();
	while (ch != ' ' && ch != '\n')
	{
		if (i == 127)
		{
			s += tmp;
			i = 0;
		}

		tmp[i++] = ch;
		ch = in.get();
	}

	if (i > 0)
	{
		tmp[i] = '\0';
		s += tmp;
	}

	return in;
}

ostream& MockString::operator<<(ostream& out, const MockString::string& s)//流插入<<运算符重载
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		out << s[i];
	}

	return out;
}