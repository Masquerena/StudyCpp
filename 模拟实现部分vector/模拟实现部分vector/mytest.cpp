#include "myvector.h"


//void test1()//capacity（）和size（）函数测试
//{
//	MyVector::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//
//	cout << "size:" << v.size() << endl;
//	cout << "capacity:" << v.capacity() << endl;
//}

void test2()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.resize(3);//小于size测试
	cout << "size:" << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}

	v.resize(6);//大于size，小于capacity测试
	cout << "size:" << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.resize(12, 10);//大于capacity测试
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test4()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);

	v.pop_back();
	v.pop_back();
	v.pop_back();


	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test5()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	MyVector::vector<int>:: iterator it = v.insert(v.end() - 1, 50);
	*it *= 100;

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	vector<int>::iterator it = v.begin();
	it = v.erase(it);
	cout << *it << endl;
	++it;


	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);
	//	}
	//	else
	//		++it;
	//}
	// 
	//MyVector::vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		it = v.erase(it);
	//	}
	//	else
	//		++it;
	//}
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}

	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	if (v[i] % 2 == 0)
	//		v.erase(v.begin() + i);
	//}
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}

	//cout << "size:" << v.size() << endl;
	//cout << "capacity:" << v.capacity() << endl;
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
}

void test7()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//cout << "size_v:" << v.size() << endl;

	MyVector::vector<int> v1;
	//v1.push_back(10);
	//v1.push_back(20);
	//v1.push_back(30);
	//v1.push_back(40);
	//v1.push_back(50);
	//cout << "size_v1:" << v1.size() << endl;

	v1 = v;
	//cout << "size_v:" << v.size() << endl;
	//cout << "size_v1:" << v1.size() << endl;
	cout << "v:";
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "v1:";
	for (auto e : v1)
	{
		cout << e << " ";
	}
}

void test8()
{
	MyVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	MyVector::vector<int> v1(v);
	for (auto e : v1)
	{
		cout << e << " ";
	}
} 

void test9()
{
	MyVector::vector<MyVector::vector<int>> vv;
	MyVector::vector<int> v(10, 1);
	vv.push_back(v);
	vv.push_back(v);
	vv.push_back(v);
	vv.push_back(v);
	vv.push_back(v);


	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
			
		}
		cout << endl;
	}
	cout << endl;
}

void test10()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
			++it;
	}

	for (auto e : v)
	{
		cout << e << " ";
	}

}

#include <string>
int main()
{
	/*test10();*/

	return 0;
}