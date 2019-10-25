#include <iostream>

using namespace std;

namespace sheena
{
	//�ڶ����������ṹ��
	template <class T>
	struct _list_node
	{
		_list_node<T> *_next;
		_list_node<T> *_prev;
		T _data;

		_list_node<T>(const T& x)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};
	//������������
	template <class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;

		node *_node;

		_list_iterator(node *node)//���캯��
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()//ǰ��++
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)//����++
		{
			Self tmp = *this;//��������
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()//ǰ��--
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)//����--
		{
			Self tmp = *this;//��������
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return (_node != it._node);
		}
		bool operator==(const Self& it)
		{
			return (_node == it._node);
		}
	};

	
	//��һ��
	template <class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()//���캯��
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& l)//��������
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator=(const list<T>& l)//��ֵ
		{
			if (_head != l._head)
			{
				swap(_head, l._head);
			}
			return *this;
		}

		~list()//��������
		{
			clean();

			delete _head;
			_head = nullptr;
		}

		void clean()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void insert(iterator pos, const T& x)
		{
			node *cur = pos._node;
			node *prev = cur->_prev;
			node *newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			node *cur = pos._node;
			node *prev = cur->_prev;
			node *next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);//����
		}
		iterator pop_back()
		{
			return erase(--end());
		}
		iterator pop_front()
		{
			return erase(begin());
		}
	private:
		node *_head;
	};
	void list_print(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}

using namespace sheena;
void test()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	list_print(l);
	l.push_front(5);
	l.push_front(6);
	l.push_front(7);
	list_print(l);

	l.pop_back();
	list_print(l);
	l.pop_front();
	list_print(l);

	list<int> c = l;//��������
	list_print(c);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			it++;
		}
	}

	list_print(l);
}
int main()
{
	test();
	return 0;
}