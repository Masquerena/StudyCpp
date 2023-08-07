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
		void push(const T& x)//数据插入
		{
			_con.push_back(x);
		}

		void pop()//数据删除
		{
			_con.pop_front();
		}

		const T& front()//获取队首元素
		{
			return _con.front();
		}

		const T& back()//获取队尾元素
		{
			return _con.back();
		}

		size_t size()//获取元素个数
		{
			return _con.size();
		}

		bool empty()//判断是否为空
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
