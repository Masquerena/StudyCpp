#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

namespace MyPriorityQueue
{
	template<class T>
	struct less//���ڱȽϷº���
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater//С�ڱȽϷº���
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
		priority_queue()//һ��ʲô��û�еĹ��캯�����Զ����Ա������������߳�ʼ���б�����Լ��Ĺ��캯��
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)//֧�ֵ������������ȼ�����
			:_con(first, last)
		{}

		void adjust_up(size_t child)//���ϵ�����
		{
			Compare com;
			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				if (com(_con[parent], _con[child]))//�����
				{
					swap(_con[parent], _con[child]);

					child = parent;
					parent = (parent - 1) / 2;
				}
				else
					break;
			}
		}

		void push(const T& x)//��������
		{
			_con.push_back(x);

			adjust_up(_con.size() - 1);
		}

		void adjust_down(size_t parent)//���µ�������
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

		void pop()//ɾ���Ѷ�����
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		size_t size()//��ȡ���ݸ���
		{
			return _con.size();
		}

		const T& top() const//��ȡ�Ѷ�����
		{
			return _con.front();
		}

		bool empty()//�ж��Ƿ�Ϊ��
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}
