//设计一个类不能被继承

//方法一：把构造函数私有化（1.子类必须调用父类的构造函数，2.私有函数在子类中不可以见，无法调用）

class A
{
private:
	A()
	{}
};
class B : public A
{};


//方法二：加关键字final（最终类）
class A final
{};
class B : public A
{};