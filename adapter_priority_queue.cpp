#include <iostream>
#include <vector>

using namespace std;

namespace sheena
{
	template<class T>
	class my_less
	{
	public:
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	class my_greater
	{
	public:
		bool operator()(const T&a, const T& b)
		{
			return  a > b;
		}
	};


    template<class T, class Contanier = vector<T>, class compare = my_less<T>>
	class priority_queue
	{
	public:
		void adjust_up(int child)
		{
			compare com;
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
		void adjust_down(int root)
		{
			compare com;
			int parent = root;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
						++child;
				if (com(_con[parent], _con[child]))
				{
						swap(_con[parent], _con[child]);
						parent = child;
						child = parent * 2 + 1;
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
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		size_t size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con[0];
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Contanier _con;
	};
}

using namespace sheena;

int main()
{
	sheena::priority_queue<int, vector<int>, sheena::my_less<int>> pq;
	pq.push(6);
	pq.push(2);
	pq.push(3);
	pq.push(9);
	pq.push(8);
	pq.push(0);
	pq.push(7);
	cout << pq.size() << endl;

	while (!pq.empty())
	{
		cout << pq.top() << "  ";
		pq.pop();
	}
	cout << endl;
	cout << pq.size() << endl;
	return 0;

}