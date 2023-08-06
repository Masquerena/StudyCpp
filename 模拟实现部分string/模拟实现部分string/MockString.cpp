#include "MockString.h"

//������������غ���
MockString::string::string(const char* str)//�ַ������޲ι���
{
	_size = strlen(str);
	_capacity = _size;

	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

//MockString::string::string(const string& s)//��������Ĵ�ͳд��
//{
//	_size = s._size;
//	_capacity = s._capacity;
//	
//	_str = new char[_capacity + 1];
//	strcpy(_str, s._str);
//}

MockString::string::string(const string& s)//����������ִ������ã�д��
	:_str(nullptr)
	,_size(0)
	,_capacity(0)
{
	string tmp(s._str);
	swap(tmp);
}

MockString::string& MockString::string::operator=(const char* str)//�����=����
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

//MockString::string& MockString::string::operator=(const string& s)//��=����������������صĴ�ͳд��
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

MockString::string& MockString::string::operator=(string s)//��=����������������ص��ִ������ã�д��
{
	swap(s);
	return *this;
}

MockString::string::~string()//��������
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

//iterator������ʵ��
MockString::string::iterator MockString::string::begin()//iterator��begin��������
{
	return _str;
}

MockString::string::iterator MockString::string::end()//iterator��end��������
{
	return _str + _size;
}

//modify�޸��ַ�����غ���
void MockString::string::push_back(char ch)//���ַ�����
{
	if (_size == _capacity)//������������
	{
		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
		reserve(newcapacity);
	}
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
}

MockString::string& MockString::string::operator+=(char ch)//�����+=����
{
	push_back(ch);

	return *this;
}

void MockString::string::append(const char* str)//�ַ�������
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

MockString::string& MockString::string::operator+=(const char* str)//�ַ�������������+=����
{
	append(str);

	return *this;
}

void MockString::string::clear()//����ַ�������
{
	memset(_str, '\0', sizeof(char) * _size);
	_size = 0;
}

void MockString::string::swap(string& s)//����ַ�������
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

void MockString::string::insert(size_t pos, char ch)//��posλ�ò���ch�ַ�
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

void MockString::string::insert(size_t pos, const char* s)//��posλ�ò���һ���ַ���
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

MockString::string& MockString::string::erase(size_t pos, size_t len)//��posλ��ɾ��len���ַ�
{
	assert(pos <= _size);

	if (len >= _size - pos)//ȫɾ����δ����ʱ����ȫ��ɾ����ֱ����posλ�ø���\0��
	{
		_str[pos] = '\0';
		_size = pos;

		return *this;
	}

	size_t end = pos + len;
	size_t i = pos;

	while (_str[end] != '\0')//����ɾ��
	{
		_str[i] = _str[end];
		++i;
		++end;
	}

	_size -= len;
	_str[_size] = '\0';
	return *this;
}

//capacity���ݸ�������������غ���
void MockString::string::reserve(size_t capacity)//�ռ�����
{
	char* str = new char[capacity + 1];//��һ���ռ��ԭ����capacity����Ч�ַ��ռ䣬��������\0'
	strcpy(str, _str);                 //���һ���ռ���Ϊ�˴洢'\0'

	delete[] _str;
	_str = str;
	_capacity = capacity;
}

size_t MockString::string::size()const//�����ַ�������
{
	return _size;
}

size_t MockString::string::capacity()const//�����ַ�����Ӧ�Ŀռ�����
{
	return _capacity;
}

bool MockString::string::empty()//�жϿռ��Ƿ���
{
	return (_size == _capacity);
}

void MockString::string::resize(size_t n, char ch)//���ַ�����������Ϊn������³��ȱ�ԭ���ȳ����򳤵Ĳ�����ch����
{
	if (n <= _size)//���õ�ֵС��ԭ�ַ�������
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n <= _capacity && n > _size)//���õ�ֵ����ԭ�ַ������ȵ�С������
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
		else if (n > _capacity)//���õ�ֵ��������
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

const char* MockString::string::c_str()//�������ݵĵ�ַ
{
	return _str;
}

// access֧����"[]"����ʽ�����ַ���
char& MockString::string::operator[](size_t pos)//[]��������أ�֧���ַ����±���ʽ��ȡ
{
	assert(pos < _size);

	return _str[pos];
}

const char& MockString::string::operator[](size_t pos)const//[]��������أ�֧�ֳ����ַ����±���ʽ��ȡ
{
	assert(pos < _size);

	return _str[pos];
}

//relational operators�ж���������غ���
bool MockString::string::operator<(const string& s)const//��<�����������
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

bool  MockString::string::operator<=(const string& s)const//��<=�����������
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

bool MockString::string::operator>(const string& s)const//��>�����������
{
	return !(*this <= s);
}

bool MockString::string::operator>=(const string& s)const//��>=�����������
{
	return !(*this < s);
}

bool MockString::string::operator==(const string& s)const//��==�����������
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

bool MockString::string::operator!=(const string& s)const//��!=�����������
{
	return !(*this == s);
}

//operations������غ���
size_t MockString::string::find(char ch, size_t pos)const//��posλ�ÿ�ʼ������һ��ch�ַ�
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

size_t MockString::string::find(const char* s, size_t pos)const//��posλ�ÿ�ʼ����һ���ַ���
{															  //�����ص�һ���ַ����±�
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

istream& MockString::operator>>(istream& in, MockString::string& s)//����ȡ>>���������
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

ostream& MockString::operator<<(ostream& out, const MockString::string& s)//������<<���������
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		out << s[i];
	}

	return out;
}