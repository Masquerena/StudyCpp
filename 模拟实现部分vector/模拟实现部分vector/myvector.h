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
		vector()//Ĭ�Ϲ��캯��
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
		vector(inputiterator first, inputiterator last)//���������乹��
			: _start(nullptr)                          //�����ٰ�һ�㺯��ģ������Ϊ�����������Ϳ��ܺ�
			, _finish(nullptr)						   //���ú�����vector���Ͳ�ͬ
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		~vector()//��������
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		vector(const vector<T>& v)//�������캯��
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<int> x);//�����=����

		//Element access
		T& operator[](size_t pos);//�����[]����
		const T& operator[](size_t pos) const;//�����[]����(const�汾)

		//������
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

		//���������ݸ�����ȡ��Capacity��
		size_t size() const;//�������ݸ���
		size_t capacity() const;//��������
		void reserve(size_t n);//����n���ռ�
		bool empty() const;//�п�
		void resize(size_t n, T val = T())//�����ݸ�������Ϊn��������capacity�򿪱ٿռ䣬����size�������
		{													   //����size�������
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
		//������ز�����Modifiers��
		void push_back(const T& x);//β��
		void pop_back();//βɾ
		iterator insert(iterator pos, const T& x);//��posλ�ò���x����
		iterator erase(iterator pos);//ɾ��posλ�õ�����
		void clear();//�������
		void swap(vector<T>& x);//��������

	private:
		iterator _start;//ָ�����ݵĿ�ʼ
		iterator _finish;//ָ�����ݵ�β��λ��
		iterator _end_of_storage;//ָ��������β��λ��
	};
}
template<class T>
MyVector::vector<T>& MyVector::vector<T>::operator=(vector<int> x)//�����=����
{
	swap(x);
	return *this;
}

//Element access
template<class T>
T& MyVector::vector<T>::operator[](size_t pos)//�����[]����
{
	assert(pos < size());
	return _start[pos];
}

template<class T>
const T& MyVector::vector<T>::operator[](size_t pos) const//�����[]����(const�汾)
{
	assert(pos < size());
	return _start[pos];
}

//���������ݸ�����ȡ
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
void MyVector::vector<T>::reserve(size_t n)//����n���ռ�
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

		size_t OldSize = size();//�˴�������¼ԭ����size����ֵ���������¼������_finish = _start + size()
							//�Ļ����ͻ���Ϊ_start�Ѿ����ı䣬����size�����������				
		_start = tmp;
		_finish = _start + OldSize;
		_end_of_storage = _start + n;
	}
}

template<class T >
bool MyVector::vector<T>::empty()const//�п�
{
	return _start == _finish;
}

//������ز�����Modifiers��
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
void MyVector::vector<T>::pop_back()//βɾ
{
	assert(!empty());
	--_finish;
}

template<class T>
T* MyVector::vector<T>::insert(iterator pos, const T& x)//��posλ�ò���x����
{
	assert(pos <= _finish);
	assert(pos >= _start);

	if (_finish == _end_of_storage)//����˴����˿ռ䣬��ô����Ϊ�¿��Ŀռ��_start��ָ��λ�ñ�
	{							   //�޸ģ�ʹ�õ�����ʧЧ
		size_t len = pos - _start;

		size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
		reserve(newcapacity);

		pos = _start + len;//����¿����˿ռ䣬���µ�����ʧЧ������posλ��
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
T* MyVector::vector<T>::erase(iterator pos)//ɾ��posλ�õ�����
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
void MyVector::vector<T>::clear()//�������
{
	_finish = _start;
}

template<typename T>
void MyVector::vector<T>::swap(vector<T>& x)//���ݽ���
{
	std::swap(_start, x._start);
	std::swap(_finish, x._finish);
	std::swap(_end_of_storage, x._end_of_storage);
}