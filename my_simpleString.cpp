//模拟实现一个简单的string类
//不包含增删查改，只有四个默认成员函数

#include <iostream>

using namespace std;

namespace sheena
{
	class my_string
	{
	public:
		//构造函数
		my_string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			if (nullptr == str)
				str = "";
			strcpy(_str, str);
		}
		//拷贝构造函数
		my_string(const my_string& s)
			:_str(nullptr)
		{
			my_string tmp(s._str);
			swap(tmp._str, _str);
		}
		//赋值函数
		my_string& operator=(my_string s)
		{
			swap(s._str, _str);
			return *this;
		}
		//析构函数
		~my_string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}