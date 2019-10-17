#include <iostream>
#include <assert.h>

using namespace std;

namespace sheena
{
	template<class T>
	class my_vector
	{
	public:
		typedef T* iterator;
		my_vector()//构造
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		my_vector(const my_vector<T>& v)//拷贝构造
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		~my_vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}

		void swap(my_vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		my_vector<T>& operator=(my_vector<T> v)
		{
			swap(v);
			return *this;
		}




		my_vector resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish =  _start + n;
				return;
			}
			if (n > capacity())
				return n;
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				memecpy(tmp, _start, sizeof(T)*sz);
				delete[] _start;
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}




		iterator end()
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}

		void insert(iterator& pos, const T& x)
		{
			assert(pos < _finish && pos >= _start);
			if (_finish == _end_of_storage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;
			while (end > pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		
		void erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator begin = pos + 1;
			while (begin < _finsh)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
		}
		void pop_back()
		{
			assert(_finish >= _start);
			erase(--end());
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}