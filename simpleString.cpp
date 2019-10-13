#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

namespace sheena
{
	class my_string
	{
	public:
		my_string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		my_string(const my_string& s)
			:_str(nullptr)
		{
			my_string tmp(s._str);
			swap(tmp._str, _str);
		}
		my_string& operator=(my_string s)
		{
			swap(_str, s._str);
			return *this;
		}
		~my_string()
		{
			if(_str)
				delete[]_str;
		}
		const char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
	};
}
int main()
{
	sheena::my_string s1("welcome");
	sheena::my_string s2(s1);
	sheena::my_string s3("Cplusplus");
	s1 = s3;
	cout << s1.c_str()<< endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;

	system("pause");
	return 0;
}