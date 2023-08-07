#pragma once

#include<iostream>
#include<vector>
#include<list>

using namespace std;

namespace MyStack
{
	template <class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& x)//���ݲ���
		{
			_con.push_back(x);
		}

		void pop()//����ɾ��
		{
			_con.pop_back();
		}

		const T& top()//��ȡջ��Ԫ��
		{
			return _con.back();
		}

		size_t size()//��ȡԪ�ظ���
		{
			return _con.size();
		}

		bool empty()//�ж��Ƿ�Ϊ��
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
