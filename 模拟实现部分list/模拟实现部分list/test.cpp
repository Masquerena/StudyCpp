#include "mylist.h"

void test1()
{
	MyList::list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);
	

	li.pop_back();
	li.pop_back();
	li.insert(li.begin(), 10);
	MyList::list<int>::iterator it = li.begin();

	while (it != li.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test2()
{
	MyList::list<int> li;
	li.push_front(1);
	li.push_front(2);
	li.push_front(3);
	li.push_front(4);


	//li.pop_front();
	//li.pop_front();
	//li.insert(li.end(), 10);
	//li.erase(li.end());
	/*li.clear();*/
	MyList::list<int>::iterator it = li.begin();

	while (it != li.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test3()
{
	MyList::list<int> li;
	li.push_front(1);
	li.push_front(2);
	li.push_front(3);
	li.push_front(4);
	for (auto& e : li)
	{
		cout << e << " ";
	}
	cout << endl;

	/*MyList::list<int> li2(li);*/
	MyList::list<int> li2;
	li2.push_front(10);
	li2.push_front(20);
	li2.push_front(30);
	li2.push_front(40);
	for (auto& e : li2)
	{
		cout << e << " ";
	}
	cout << endl;

	li2 = li;
	for (auto& e : li2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_iterator(const MyList::list<int>& lt)
{
	MyList::list<int>::const_iterator it = lt.begin();
	for (auto& e : lt)
	{
		cout << *it << " ";

		++it;
	}
	cout << endl;
}
void test4()
{
	MyList::list<int> li;
	li.push_front(1);
	li.push_front(2);
	li.push_front(3);
	li.push_front(4);

	test_iterator(li);
}

void test5()
{
	MyList::list<int> lt;
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);
	lt.push_front(4);

	MyList::list<int> lt2(lt.begin(), lt.end());
	MyList::list<int>::iterator it = lt2.begin();
	lt2.push_front(40);

	for (auto& e : lt2)
	{
		cout << *it << " ";

		++it;
	}
	cout << "size:" << lt2.size() << endl;
}

void test6()
{
	MyList::list<int> lt;
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);
	lt.push_front(4);


	MyList::list<int> lt2(lt);
	MyList::list<int>::iterator it = lt2.begin();
	
	cout << it._pnode << endl;
	for (auto& e : lt2)
	{
		cout << *it << " ";

		++it;
	}
	cout << "size:" << lt2.size() << endl;
}

void test7()
{
	struct Pos
	{
		Pos(int row = 0, int line = 0)
			: _row(row)
			, _line(line)
		{}

		int _row;
		int _line;
	};

	list<Pos> lt;
	lt.push_front(Pos());
	lt.push_front(Pos(1,1));
	lt.push_front(Pos(2,2));
	lt.push_front(Pos(3,3));

	list<Pos>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << it->_row << ":" << it->_line << endl;
		++it;
	}
}
void test8()
{
	MyList::list<int> lt;
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);
	lt.push_front(4);

	cout << "正向迭代器：";
	MyList::list<int>::iterator it = lt.begin();//正向迭代器
	for (auto& e : lt)
	{
		cout << *it << " ";

		++it;
	}
	cout << endl;

	cout << "反向迭代器：";
	MyList::list<int>::reverse_iterator it2 = lt.rbegin();//反向迭代器
	for (auto& e : lt)
	{
		cout << *it2 << " ";

		++it2;
	}
}
int main()
{
	test8();
	return 0;
}