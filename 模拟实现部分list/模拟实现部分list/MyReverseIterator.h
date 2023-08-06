#pragma once

#include<iostream>

using namespace std;

namespace MyReverseIterator
{
	template <class iterator, class Ref, class Rtr>
	class ReverseIterator
	{
		typedef ReverseIterator<iterator, Ref, Rtr> Self;
	public:
		ReverseIterator(iterator it)//���캯��
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