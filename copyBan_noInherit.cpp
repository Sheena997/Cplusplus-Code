//�����һ���࣬���ܱ�����
//��һ��C++98�������캯���͸�ֵ����ֻ������ʵ�֣�������Ϊ˽�е�
class copyBan
{
private:
		copyBan(const copyBan& );
		copyBan& operator=(const copyBan& );
};
//������C++11
class copyBan
{
	copyBan(const copyBan&) = delete;
	copyBan* operator=(const copyeBan&) = delete;
};




//�����һ���࣬���ܱ��̳�
//��һ��C++98˽�г�Ա�����࿴���������๹�캯��������ø����
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
//������C++11final�ؼ���
class noInherit final
{};