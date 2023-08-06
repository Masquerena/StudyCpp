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
		friend istream& operator>>(istream& in, MockString::string& s);//����ȡ>>���������
		friend ostream& operator<<(ostream& out, const MockString::string& s);//������<<��������� 

	public:
		typedef char* iterator;
		static const size_t npos = -1;//����ĳЩ�ض������ķ���ֵ�����
	public:

		//������Ա����
		string(const char* str = "");//�ַ������޲ι���
		string(const string& s);//��������
		string& operator=(const char* str);//��=����������ַ�������
		//string& operator=(const string& s);//��=����������������صĴ�ͳд��
		string& operator=(string str);//��=����������������ص��ִ������ã�д��s
		~string();//��������

		//iterator������
		iterator begin();
		iterator end();

		//modify�޸��ַ�����غ���
		void push_back(char ch);//���ַ�����
		string& operator+=(char ch);//���ַ�����������+=����
		void append(const char* str);//�ַ�������
		string& operator+=(const char* str);//�ַ�������������+=����
		void clear();//����ַ�������
		void swap(string& s);//����ַ�������
		void insert(size_t pos, char ch);//��posλ�ò���ch�ַ�
		void insert(size_t pos, const char* s);//��posλ�ò���һ���ַ���
		string& erase(size_t pos = 0, size_t len = npos);//��posλ��ɾ��len���ַ�

		//capacity���ݸ�������������غ���
		void reserve(size_t capacity);//������������
		size_t size()const;//�����ַ�������
		size_t capacity()const;//�����ַ�����Ӧ�Ŀռ�����
		bool empty();//�жϿռ��Ƿ���
		void resize(size_t n, char ch = '\0');//���ַ�����������Ϊn������³��ȱ�ԭ���ȳ����򳤵Ĳ�����ch����
		const char* c_str();//�������ݵĵ�ַ

		// access֧����"[]"����ʽ�����ַ���
		char& operator[](size_t pos);//[]��������أ�֧���ַ����±���ʽ��ȡ
		const char& operator[](size_t pos)const;//[]��������أ�֧�ֳ����ַ����±���ʽ��ȡ

		//relational operators//�ж���������غ���
		bool operator<(const string& s)const;//��<�����������
		bool operator<=(const string& s)const;//��<=�����������
		bool operator>(const string& s)const;//��>�����������
		bool operator>=(const string& s)const;//��>=�����������
		bool operator==(const string& s)const;//��==�����������
		bool operator!=(const string& s)const;//��!=�����������

		//operations������غ���
		size_t find(char ch, size_t pos = 0)const;//��posλ�ÿ�ʼ����һ��ch�ַ������������±�
		size_t find(const char* s, size_t pos = 0)const;//��posλ�ÿ�ʼ����һ���ַ����������ص�һ���ַ����±�

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}