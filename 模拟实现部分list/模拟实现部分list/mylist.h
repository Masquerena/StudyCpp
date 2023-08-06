#pragma once

#include"MyReverseIterator.h"
#include <iostream>
#include<list>
#include<assert.h>
#include "MyReverseIterator.h"

using namespace std;

namespace MyList
{
	template<class T>
	struct ListNode//list中存储指向上下节点的指针和数据块中的数据
	{
		ListNode* _next;
		ListNode* _prev;
		T _data;

		ListNode(const T& x)//构造函数
			: _next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator//迭代器,每个迭代器都是一个类ListNode的指针
	{
		typedef ListNode<T> node;
		typedef list_iterator<T, Ref, Ptr>	Self;
		node* _pnode;

		list_iterator(node* _pn)//构造函数
			: _pnode(_pn)
		{}

		Ref operator*()//运算符*重载
		{
			return _pnode->_data;
		}

		Self& operator++()//运算符++重载
		{
			_pnode = _pnode->_next;
			return *this;
		}

		Self& operator--()//运算符--重载
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		Ptr operator->()//运算符->重载
		{
			return &_pnode->_data;
		}

		bool operator!=(const Self& it) const//迭代器是否相等
		{
			return _pnode != it._pnode;
		}

		bool operator==(const Self& it) const
		{
			return _pnode == it._pnode;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> node;//结构体重命名为node，方便使用
	public:
		typedef list_iterator<T, T&, T*> iterator;//迭代器类重命名
		typedef list_iterator<T, const T&, const T*> const_iterator;//const迭代器重命名

		typedef MyReverseIterator::ReverseIterator<iterator, T&, T*> reverse_iterator;//反向迭代器
		typedef MyReverseIterator::ReverseIterator<const_iterator, const T&, const T*>
															const_reverse_iterator;//const反向迭代器

		void empty_initialize()//空初始化（创建哨兵位）
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		//默认成员函数
		list()//构造函数
		{
			empty_initialize();
		}

		template<class inputiterator>
		list(inputiterator first, inputiterator last)//迭代器区间构造
		{
			empty_initialize();

			size_t size = 0;
			while (first != last)
			{
				push_back(first._pnode->_data);
				++first;
				++size;
			}

			_size = size;
		}

		list( list<T>& lt)//构造函数
		{
			empty_initialize();

			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
			_size = tmp._size;
		}

		~list()//析构函数
		{
			clear();

			delete[] _head;
			_head->_prev = _head->_next = nullptr;
			_head = nullptr;
		}

		list<T>& operator=(list<T> lt)//运算符=重载
		{
			swap(lt);
			
			return *this;
		}

		//迭代器
		iterator begin()//普通迭代器
		{
			return iterator(_head->_next);
		}
		iterator end()//普通迭代器
		{
			return iterator(_head);
		}

		const_iterator begin() const//const迭代器
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const//const迭代器
		{
			return const_iterator(_head);
		}

		//反向迭代器
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		//const反向迭代器
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//Capacity(容量相关):
		size_t size() const//链表中的数据个数
		{
			return _size;
		}

		bool empty() const//链表是否为空
		{
			return _size == 0;
		}

		//(数据操作相关）Modifiers:
		iterator insert(iterator pos, const T& val)//在任意pos位置插入val
		{
			node* newnode = new node(val);
			node* tail = pos._pnode->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = pos._pnode;
			pos._pnode->_prev = newnode;

			++_size;

			return iterator(newnode);
		}

		iterator erase(iterator pos)//删除pos位置的值
		{
			assert(pos != end());

			node* tail = pos._pnode->_prev;
			node* cur = pos._pnode->_next;

			tail->_next = cur;
			cur->_prev = tail;

			--_size;

			delete pos._pnode;
			return iterator(cur);
		}

		void push_back(const T& x)//尾插
		{
			insert(end(), x);
		}

		void pop_back()//尾删
		{
			erase(--end());
		}

		void push_front(const T& x)//头插
		{
			insert(begin(), x);
		}

		void pop_front()//头删
		{
			erase(begin());
		}

		void clear()//清除list除哨兵位的所有节点
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void swap(list<T>& lt)//哨兵位交换
		{
			std::swap(_head, lt._head);
		}
	private:
		node* _head;//头节点（哨兵位）
		size_t _size;//节点个数
	};
}


