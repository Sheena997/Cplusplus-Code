#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <windows.h>

using namespace std;

mutex mtx;
condition_variable cv;
bool flag = true;
int i = 0;

void mutex1()
{
	while (i <= 100)
	{
		Sleep(1000);
		cout << "�߳�1��" << endl;
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] {return flag; });//ֻ��return flag == trueʱ�Ų������������ɹ�
		cout << "thread: " << this_thread::get_id() << "  printf:" << i << endl;
		++i;
		flag = false;
		cv.notify_one();//�ͷ����������ѵ��ڸ����ϵ��߳�
	}
}
void mutex2()
{
	while (i <= 100)
	{
		Sleep(1000);
		cout << "�߳�2��" << endl;
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] {return !flag; });
		cout << "thread: " << this_thread::get_id() << " printf:" << i << endl;
		++i;
		flag = true;
		cv.notify_one();
	}
}


int main()
{
	thread th1(mutex1);
	thread th2(mutex2);

	th1.join();
	th2.join();

	return 0;
}