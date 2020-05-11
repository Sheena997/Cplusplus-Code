//请设计一个类，该类只在堆上创建对象
/*
方法一：构造函数私有化
1.将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
2.提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
*/
class HeapOnly
{
public:
	static HeapOnly* Create()
	{
		return new HeapOnly;
	}
private:
	//C++98 只声明，不实现
	HeapOnly(const HeapOnly&);
	//C++11
	//HeapOnly(const HeapOnly&) = delete;
};



//请设计一个类，该类只在栈上创建对象
class StackOnly
{
public:
	static StackOnly Create()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};
//只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，
//即屏蔽掉operator new和定位new表达式，注意：屏蔽operator new，实际也将定位new屏蔽掉
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};