//�����һ���࣬����ֻ�ڶ��ϴ�������
/*
����һ�����캯��˽�л�
1.����Ĺ��캯��˽�У���������������˽�С���ֹ���˵��ÿ�����ջ�����ɶ���
2.�ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶѶ���Ĵ���
*/
class HeapOnly
{
public:
	static HeapOnly* Create()
	{
		return new HeapOnly;
	}
private:
	//C++98 ֻ��������ʵ��
	HeapOnly(const HeapOnly&);
	//C++11
	//HeapOnly(const HeapOnly&) = delete;
};



//�����һ���࣬����ֻ��ջ�ϴ�������
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
//ֻ����ջ�ϴ������󣬼������ڶ��ϴ��������ֻҪ��new�Ĺ������ε����ɣ�
//�����ε�operator new�Ͷ�λnew���ʽ��ע�⣺����operator new��ʵ��Ҳ����λnew���ε�
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};