#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace MockString
{
	class string
	{
		friend istream& operator>>(istream& in, MockString::string& s);//流提取>>运算符重载
		friend ostream& operator<<(ostream& out, const MockString::string& s);//流插入<<运算符重载 

	public:
		typedef char* iterator;
		static const size_t npos = -1;//用于某些特定函数的返回值或参数
	public:

		//基本成员函数
		string(const char* str = "");//字符串及无参构造
		string(const string& s);//拷贝构造
		string& operator=(const char* str);//“=”运算符的字符串重载
		//string& operator=(const string& s);//“=”运算符类类型重载的传统写法
		string& operator=(string str);//“=”运算符类类型重载的现代（常用）写法s
		~string();//析构函数

		//iterator迭代器
		iterator begin();
		iterator end();

		//modify修改字符串相关函数
		void push_back(char ch);//单字符插入
		string& operator+=(char ch);//单字符插入的运算符+=重载
		void append(const char* str);//字符串插入
		string& operator+=(const char* str);//字符串插入的运算符+=重载
		void clear();//清除字符串函数
		void swap(string& s);//类的字符串交换
		void insert(size_t pos, char ch);//在pos位置插入ch字符
		void insert(size_t pos, const char* s);//在pos位置插入一个字符串
		string& erase(size_t pos = 0, size_t len = npos);//在pos位置删除len个字符

		//capacity数据个数、容量等相关函数
		void reserve(size_t capacity);//容量不够扩容
		size_t size()const;//返回字符串个数
		size_t capacity()const;//返回字符串对应的空间容量
		bool empty();//判断空间是否满
		void resize(size_t n, char ch = '\0');//将字符串长度设置为n，如果新长度比原长度长，则长的部分用ch补充
		const char* c_str();//返回数据的地址

		// access支持用"[]"的形式访问字符串
		char& operator[](size_t pos);//[]运算符重载，支持字符串下标形式获取
		const char& operator[](size_t pos)const;//[]运算符重载，支持常量字符串下标形式获取

		//relational operators//判断运算符重载函数
		bool operator<(const string& s)const;//“<”运算符重载
		bool operator<=(const string& s)const;//“<=”运算符重载
		bool operator>(const string& s)const;//“>”运算符重载
		bool operator>=(const string& s)const;//“>=”运算符重载
		bool operator==(const string& s)const;//“==”运算符重载
		bool operator!=(const string& s)const;//“!=”运算符重载

		//operations查找相关函数
		size_t find(char ch, size_t pos = 0)const;//从pos位置开始查找一个ch字符，并返回其下标
		size_t find(const char* s, size_t pos = 0)const;//从pos位置开始查找一个字符串，并返回第一个字符的下标

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}