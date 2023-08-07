#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

namespace MyPriorityQueue
{
	template<class T>
	struct less//大于比较仿函数
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater//小于比较仿函数
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue()//一个什么都没有的构造函数，自定义成员变量进来后会走初始化列表调用自己的构造函数
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)//支持迭代器构造优先级队列
			:_con(first, last)
		{}

		void adjust_up(size_t child)//向上调整法
		{
			Compare com;
			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				if (com(_con[parent], _con[child]))//建大堆
				{
					swap(_con[parent], _con[child]);

					child = parent;
					parent = (parent - 1) / 2;
				}
				else
					break;
			}
		}

		void push(const T& x)//插入数据
		{
			_con.push_back(x);

			adjust_up(_con.size() - 1);
		}

		void adjust_down(size_t parent)//向下调整建堆
		{
			Compare com;

			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void pop()//删除堆顶数据
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		size_t size()//获取数据个数
		{
			return _con.size();
		}

		const T& top() const//获取堆顶数据
		{
			return _con.front();
		}

		bool empty()//判断是否为空
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}
