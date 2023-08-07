#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

namespace MyQueue
{
	template <class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& x)//���ݲ���
		{
			_con.push_back(x);
		}

		void pop()//����ɾ��
		{
			_con.pop_front();
		}

		const T& front()//��ȡ����Ԫ��
		{
			return _con.front();
		}

		const T& back()//��ȡ��βԪ��
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
