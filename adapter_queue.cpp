#include <iostream>
#include <list>
#include <deque>

using namespace std;

namespace sheena
{
	template <class T, class Container = deque<T>>
	class my_queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}
		const T& front() const 
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
void testQueue1()
{
	sheena::my_queue<int, deque<int>> q;

	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "q的size()为：" << q.size() << endl;
	cout << "q的front队头元素为：" << q.front() << endl;
	cout << "q的back队尾元素为： " << q.back() << endl;

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}

}
void testQueue2()
{
    sheena::my_queue<int, list<int>> q;

	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "q的size()为：" << q.size() << endl;
	cout << "q的front队头元素为：" << q.front() << endl;
	cout << "q的back队尾元素为： " << q.back() << endl;

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}

}


int main()
{

	cout << "testQueue1()当底层实现是容器deque：" << endl;
	testQueue1();
	cout << endl;

	cout << "testQueue2()当底层实现是容器list： " << endl;
	testQueue2();
	cout << endl;


	return 0;
}
