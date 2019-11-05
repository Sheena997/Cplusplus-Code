#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace sheena
{
	template <class T, class Contanier>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
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
		Contanier _con;
	};
}

using namespace sheena;
int main()
{
	sheena::stack<int, vector<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << s.size() << endl;
	return 0;
}