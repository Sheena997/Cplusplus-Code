//请设计一个类，不能被拷贝
//法一：C++98拷贝构造函数和赋值函数只声明不实现，且声明为私有的
class copyBan
{
private:
		copyBan(const copyBan& );
		copyBan& operator=(const copyBan& );
};
//法二：C++11
class copyBan
{
	copyBan(const copyBan&) = delete;
	copyBan* operator=(const copyeBan&) = delete;
};




//请设计一个类，不能被继承
//法一：C++98私有成员在子类看不见，子类构造函数必须调用父类的
class noInherit
{
public:
	static noInherit GetInstance
	{
		return inHerit();
	}
private:
	inHerit()
	{}
};
//法二：C++11final关键字
class noInherit final
{};