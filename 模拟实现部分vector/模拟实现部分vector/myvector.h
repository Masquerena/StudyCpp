#pragma once
#include<iostream>
#include<assert.h>
#include<vector>

using namespace std;

namespace MyVector 
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		//Member functions
		vector()//默认构造函数
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(int n, T val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		template<class inputiterator>
		vector(inputiterator first, inputiterator last)//迭代器区间构造
			: _start(nullptr)                          //这里再包一层函数模板是因为传进来的类型可能和
			, _finish(nullptr)						   //包该函数的vector类型不同
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		~vector()//析构函数
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		vector(const vector<T>& v)//拷贝构造函数
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<int> x);//运算符=重载

		//Element access
		T& operator[](size_t pos);//运算符[]重载
		const T& operator[](size_t pos) const;//运算符[]重载(const版本)

		//迭代器
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		//容量和数据个数获取（Capacity）
		size_t size() const;//返回数据个数
		size_t capacity() const;//返回容量
		void reserve(size_t n);//开辟n个空间
		bool empty() const;//判空
		void resize(size_t n, T val = T())//将数据个数设置为n个，超过capacity则开辟空间，超过size填充数据
		{													   //超过size填充数据
			if (n > capacity())
			{
				reserve(n);
			}

			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}
		//数据相关操作（Modifiers）
		void push_back(const T& x);//尾插
		void pop_back();//尾删
		iterator insert(iterator pos, const T& x);//在pos位置插入x数据
		iterator erase(iterator pos);//删除pos位置的数据
		void clear();//清除数据
		void swap(vector<T>& x);//交换数据

	private:
		iterator _start;//指向数据的开始
		iterator _finish;//指向数据的尾部位置
		iterator _end_of_storage;//指向容量的尾部位置
	};
}
template<class T>
MyVector::vector<T>& MyVector::vector<T>::operator=(vector<int> x)//运算符=重载
{
	swap(x);
	return *this;
}

//Element access
template<class T>
T& MyVector::vector<T>::operator[](size_t pos)//运算符[]重载
{
	assert(pos < size());
	return _start[pos];
}

template<class T>
const T& MyVector::vector<T>::operator[](size_t pos) const//运算符[]重载(const版本)
{
	assert(pos < size());
	return _start[pos];
}

//容量和数据个数获取
template<class T>
size_t MyVector::vector<T>::size() const
{
	return _finish - _start;
}

template<class T>
size_t MyVector::vector<T>::capacity() const
{
	return _end_of_storage - _start;
}

template<class T >
void MyVector::vector<T>::reserve(size_t n)//开辟n个空间
{
	if (n > capacity())
	{
		T* tmp = new T[n];
		if (_start)
		{
			memcpy(tmp, _start, sizeof(T) * size());
			//for (size_t i = 0; i < size(); ++i)
			//{
			//	tmp[i] = _start[i];
			//}
			delete[] _start;
		}

		size_t OldSize = size();//此处用来记录原来的size（）值，如果不记录而是用_finish = _start + size()
							//的话，就会因为_start已经被改变，导致size（）结果出错				
		_start = tmp;
		_finish = _start + OldSize;
		_end_of_storage = _start + n;
	}
}

template<class T >
bool MyVector::vector<T>::empty()const//判空
{
	return _start == _finish;
}

//数据相关操作（Modifiers）
template<class T>
void MyVector::vector<T>::push_back(const T& x)
{
	if (size() == capacity())
	{
		size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
		reserve(newcapacity);
	}

	*_finish = x;
	++_finish;
}

template<class T>
void MyVector::vector<T>::pop_back()//尾删
{
	assert(!empty());
	--_finish;
}

template<class T>
T* MyVector::vector<T>::insert(iterator pos, const T& x)//在pos位置插入x数据
{
	assert(pos <= _finish);
	assert(pos >= _start);

	if (_finish == _end_of_storage)//如果此处开了空间，那么会因为新开的空间的_start等指针位置被
	{							   //修改，使得迭代器失效
		size_t len = pos - _start;

		size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
		reserve(newcapacity);

		pos = _start + len;//如果新开辟了空间，导致迭代器失效，更新pos位置
	}

	iterator end = _finish;
	++_finish;
	while (end != pos)
	{
		*end = *(end - 1);
		--end;
	}
	*end = x;

	return pos;
}

template<class T>
T* MyVector::vector<T>::erase(iterator pos)//删除pos位置的数据
{
	assert(pos >= _start);
	assert(pos < _finish);

	iterator begin = pos + 1;
	while (begin < _finish)
	{
		*(begin - 1) = *begin;
		++begin;
	}

	--_finish;
	return pos;
}

template<class T>
void MyVector::vector<T>::clear()//清除数据
{
	_finish = _start;
}

template<typename T>
void MyVector::vector<T>::swap(vector<T>& x)//数据交换
{
	std::swap(_start, x._start);
	std::swap(_finish, x._finish);
	std::swap(_end_of_storage, x._end_of_storage);
}