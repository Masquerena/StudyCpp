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
		void push(const T& x)//数据插入
		{
			_con.push_back(x);
		}

		void pop()//数据删除
		{
			_con.pop_back();
		}

		const T& top()//获取栈顶元素
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
