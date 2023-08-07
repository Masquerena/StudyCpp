#include "MyStack.h"
#include "MyQueue.h"
#include "MyPriorityQueue.h"

//int main()
//{
//	MyQueue::queue<int> q;
//	q.push(5);
//	q.push(4);
//	q.push(3);
//	q.push(2);
//	q.push(1);
//
//	q.pop();
//	q.pop();
//	q.pop();
//
//	if (!q.empty())
//	{
//		cout << "size:" << q.size() << endl;
//		cout << "front:" << q.front() << endl;
//		cout << "back:" << q.back() << endl;
//	}
//	
//	return 0;
//}

int main()
{
	MyPriorityQueue::priority_queue<int/*, vector<int>, greater<int>*/> pq;
	pq.push(5);
	pq.push(9);
	pq.push(2);
	pq.push(10);

	for (size_t i = pq.size(); i > 0; --i)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}

//namespace test
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& a, const T& b)
//		{
//			return a < b;
//		}
//	};
//
//	template<class T>
//	struct great
//	{
//		bool operator()(const T& a, const T& b)
//		{
//			return a > b;
//		}
//	};
//}
//
//int main()
//{
//	test::less<int> lessfunc;
//	cout << lessfunc(1, 2) << endl;
//
//	return 0;
//}