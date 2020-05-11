#include <iostream>
#include <vector>
#include <queue>
#include <functional> //greater的头文件

using namespace std;
namespace sheena
{
	template <class T>
	struct my_less
	{
		//构造大根堆
		bool operator()(const T& l, const T& r)
		{
			return l < r;
		}
	};

	template <class T>
	class my_greater
	{
	public:
		//构造小根堆
		bool operator()(const T& l, const T& r)
		{
			return l > r;
		}
	};

	template <class T, class Container = vector<T>, class Compare = my_less<T>>
	class my_priority_queue
	{
	public:
		
		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		//向下调整大根堆
		void adjust_down(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1< _con.size() && com(_con[child], _con[child + 1]))
					++child;
				if (com(_con[parent],  _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		T& top()
		{
			return _con[0];
		}
		const T& top() const 
		{
			return _con[0];
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

void testPriorityQueue1()
{
	//默认为大的优先级高
	sheena::my_priority_queue<int, vector<int>> pq;
	pq.push(1);
	pq.push(5);
	pq.push(4);
	pq.push(6);
	pq.push(3);
	pq.push(2);

	cout << "pq的size()为：" << pq.size() << endl;
	cout << "pq的top()堆顶元素为：" << pq.top() << endl;

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

}
void testPriorityQueue2()
{
	sheena::my_priority_queue<int, deque<int>, sheena::my_greater<int>> pq;
	pq.push(1);
	pq.push(5);
	pq.push(4);
	pq.push(6);
	pq.push(3);
	pq.push(2);

	cout << "pq的size()为：" << pq.size() << endl;
	cout << "pq的top()堆顶元素为：" << pq.top() << endl;

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

}


int main()
{

	cout << "testPriorityQueue1()默认为大的优先级高：" << endl;
	testPriorityQueue1();
	cout << endl;

	cout << "testPriorityQueue2()变为小的优先级高：  " << endl;
	testPriorityQueue2();
	cout << endl;


	return 0;
}
