/*
解析字符串，解析其后缀
*/

#include <iostream>
#include <String>
#include <stdio.h>
using namespace std;

int main()
{
	string file1 = "analysSis.cpp.c.zip";
	size_t first = file1.find('.');
	while (first != string::npos)
	{
		size_t second = file1.find('.', first + 1);
		string suffix = file1.substr(first, second - first);
		cout << suffix << endl;
		first = second;
	}
	//while (first != string::npos)
	//{
	//	size_t second = file1.find('.', first + 1);
	//	if (second != string::npos)
	//	{
	//		string suffix = file1.substr(first, second - first);
	//		cout << suffix << endl;
	//	}
	//	else
	//	{
	//		string suffix = file1.substr(first, file1.size()-first);
	//		cout << suffix << endl;
	//	}
	//	first = second;
	//}
	system("pause");
	return 0;
}