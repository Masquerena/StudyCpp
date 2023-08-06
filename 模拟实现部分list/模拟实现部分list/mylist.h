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
	struct ListNode//list�д洢ָ�����½ڵ��ָ������ݿ��е�����
	{
		ListNode* _next;
		ListNode* _prev;
		T _data;

		ListNode(const T& x)//���캯��
			: _next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator//������,ÿ������������һ����ListNode��ָ��
	{
		typedef ListNode<T> node;
		typedef list_iterator<T, Ref, Ptr>	Self;
		node* _pnode;

		list_iterator(node* _pn)//���캯��
			: _pnode(_pn)
		{}

		Ref operator*()//�����*����
		{
			return _pnode->_data;
		}

		Self& operator++()//�����++����
		{
			_pnode = _pnode->_next;
			return *this;
		}

		Self& operator--()//�����--����
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		Ptr operator->()//�����->����
		{
			return &_pnode->_data;
		}

		bool operator!=(const Self& it) const//�������Ƿ����
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
		typedef ListNode<T> node;//�ṹ��������Ϊnode������ʹ��
	public:
		typedef list_iterator<T, T&, T*> iterator;//��������������
		typedef list_iterator<T, const T&, const T*> const_iterator;//const������������

		typedef MyReverseIterator::ReverseIterator<iterator, T&, T*> reverse_iterator;//���������
		typedef MyReverseIterator::ReverseIterator<const_iterator, const T&, const T*>
															const_reverse_iterator;//const���������

		void empty_initialize()//�ճ�ʼ���������ڱ�λ��
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		//Ĭ�ϳ�Ա����
		list()//���캯��
		{
			empty_initialize();
		}

		template<class inputiterator>
		list(inputiterator first, inputiterator last)//���������乹��
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

		list( list<T>& lt)//���캯��
		{
			empty_initialize();

			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
			_size = tmp._size;
		}

		~list()//��������
		{
			clear();

			delete[] _head;
			_head->_prev = _head->_next = nullptr;
			_head = nullptr;
		}

		list<T>& operator=(list<T> lt)//�����=����
		{
			swap(lt);
			
			return *this;
		}

		//������
		iterator begin()//��ͨ������
		{
			return iterator(_head->_next);
		}
		iterator end()//��ͨ������
		{
			return iterator(_head);
		}

		const_iterator begin() const//const������
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const//const������
		{
			return const_iterator(_head);
		}

		//���������
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		//const���������
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//Capacity(�������):
		size_t size() const//�����е����ݸ���
		{
			return _size;
		}

		bool empty() const//�����Ƿ�Ϊ��
		{
			return _size == 0;
		}

		//(���ݲ�����أ�Modifiers:
		iterator insert(iterator pos, const T& val)//������posλ�ò���val
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

		iterator erase(iterator pos)//ɾ��posλ�õ�ֵ
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

		void push_back(const T& x)//β��
		{
			insert(end(), x);
		}

		void pop_back()//βɾ
		{
			erase(--end());
		}

		void push_front(const T& x)//ͷ��
		{
			insert(begin(), x);
		}

		void pop_front()//ͷɾ
		{
			erase(begin());
		}

		void clear()//���list���ڱ�λ�����нڵ�
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void swap(list<T>& lt)//�ڱ�λ����
		{
			std::swap(_head, lt._head);
		}
	private:
		node* _head;//ͷ�ڵ㣨�ڱ�λ��
		size_t _size;//�ڵ����
	};
}


