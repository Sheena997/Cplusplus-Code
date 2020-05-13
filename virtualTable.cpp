//在vs下虚表存在代码段中，代码验证虚表存在哪里
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void func1()
	{
		cout << "Base::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}
private:
	int _a;
};
class Derive : public Base
{
public:
	virtual void func1()
	{
		cout << "Derive::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Derive::func2()" << endl;
	}
private:
	int _b;
};
int main()
{
	Base b;
	int* vftptr = (int*)(*((int*)&b));
	printf("vftptr:%p\n", vftptr);

	static int s = 0;
	printf("static:%p\n", &s);//与vftptr相距比较远

	char* ptr = "hello";
	printf("常量区：%p\n", ptr);//与vftptr相距较近
	printf("函数地址（代码段）：%p\n", &Base::func1);//与vftptr相距较近
}