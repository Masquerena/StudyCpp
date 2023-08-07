#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

namespace MyReverseIterator
{
	template <class iterator, class Ref, class Rtr>
	class reverse_iterator
	{
		typedef reverse_iterator<iterator> Self;
	public:
		reverse_iterator(iterator it)//���캯��
			: _it(it)
		{}

		Ref operator*()//�����*����
		{
			iterator tmp = _it;
			return *(--tmp);
		}

		Rtr operator->()//�����->����
		{
			return *(operator*());
		}

		Self& operator++()//ǰ��++����
		{
			--_it;
			return *this;
		}

		Self& operator--()//ǰ��--����
		{
			++_it;
			return *this;
		}

		bool operator!=(const iterator& it) const//�����!=����
		{
			return _it != it._it;
		}

	private:
		iterator _it;
	};
}