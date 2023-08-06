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
		ReverseIterator(iterator it)//构造函数
			: _it(it)
		{}

		Ref operator*()//运算符*重载
		{
			iterator tmp = _it;
			return *(--tmp);
		}

		Rtr operator->()//运算符->重载
		{
			return *(operator*());
		}

		Self& operator++()//前置++重载
		{
			--_it;
			return *this;
		}

		Self& operator--()//前置--重载
		{
			++_it;
			return *this;
		}

		bool operator!=(const iterator& it) const//运算符!=重载
		{
			return _it != it._it;
		}

	private:
		iterator _it;
	};
}