//ģ��ʵ��һ���򵥵�string��
//��������ɾ��ģ�ֻ���ĸ�Ĭ�ϳ�Ա����

#include <iostream>

using namespace std;

namespace sheena
{
	class my_string
	{
	public:
		//���캯��
		my_string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			if (nullptr == str)
				str = "";
			strcpy(_str, str);
		}
		//�������캯��
		my_string(const my_string& s)
			:_str(nullptr)
		{
			my_string tmp(s._str);
			swap(tmp._str, _str);
		}
		//��ֵ����
		my_string& operator=(my_string s)
		{
			swap(s._str, _str);
			return *this;
		}
		//��������
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