#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

namespace sheena
{
	class my_string
	{
	public:
		typedef const char* const_iterator;
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}



		my_string(const char* str = "")//构造
			:_str(new char[strlen(str + 1)])
		{
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
		}
		my_string(const my_string& s)//拷贝构造
			:_str(nullptr)
		{
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;
		}
		my_string& operator=(const my_string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		 
		char& operator[](size_t pos)
		{
			if (pos < _size)
				return _str[pos];
			else
				printf("输入错误！");
		}
		const char& operator[](size_t pos)const
		{
			if (pos < _size)
				return _str[pos];
			else
				printf("输入错误！");
		}

		const_iterator c_str()
		{
			return _str;
		}
	
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}

		//是对象大小变为n
		void reserve(size_t n)
		{
			if (n < _capacity)
			{
				iterator tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
				reserve(_capacity * 2);
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			size_t end = _size + 1;
			while (end > pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			while (*str)
			{
				_str[pos++] = *str++;
			}
			_size += len;
		}

	    //push_back('a')
		void push_back(char ch)
		{
			insert(_size, ch);
		}

		//append("ssaas")
		void append(const char* str)
		{
			insert(_size, str);
		}

		const my_string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const my_string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		const my_string& operator+=(const  my_string& s)
		{
			append(s._str);
			return *this;
		}


		bool operator>(const my_string& s)const
		{
			const_iterator s1 = _str;
			const_iterator s2 = s._str;
			while (*s1 && *s2)
			{
				if (*s1 > *s2)
				{
					return true;
				}
				else if (*s1 < *s2)
				{
					return false;
				}
				else
				{
					++s1;
					++s2;
				}
			}
			if (*s1)
				return true;
			else
				return false;
		}
		bool operator==(const my_string& s)const
		{
			const_iterator s1 = _str;
			const_iterator s2 = s._str;
			while (*s1 && *s2)
			{
				if (*s1 == *s2)
				{
					++s1;
					++s2;
				}
				else
					return false;
			}
			if (*s1 || *s2)
				return false;
			else
				return true;
		}
		bool operator<(const my_string& s)const
		{
			if (*this > s || *this == s)
				return false;
			else
				return true;
		}
		bool operator>=(const my_string& s)const
		{
			return (*this > s || *this == s);
		}
		bool operator<=(const my_string& s)const
		{
			return (*this < s || *this == s);
		}
		bool operator!= (const my_string& s)const
		{
			if (*this == s)
				return false;
			else
				return true;
		}



		size_t find(char ch)
		{
			for (int i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return string::npos;
		}
		size_t find(const char* str)const
		{
			const_iterator pos = strstr(_str, str);
			if (pos == nullptr)
				return string::npos;
			else
				return pos - _str;
		}



		~my_string()//析构
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}


using namespace sheena;

my_string operator+(const my_string& s1, const my_string& s2)
{
	my_string ret = s1;
	ret += s2;
	return ret;
}


ostream& operator<<(ostream& out, const my_string& s)
{
	for (int i = 0; i < s.size; ++i)
	{
		out << s[i];
	}
	return out;
}

istream& operator >> (istream& in, my_string& s)
{
	char ch;
	while (in >> ch)
	{
		if (ch == ' ' || ch == '\n')
			return in;
		else
			s += ch;
	}
	return in;
}