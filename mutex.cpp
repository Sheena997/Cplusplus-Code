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
		cout << "线程1：" << endl;
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] {return flag; });//只有return flag == true时才不阻塞，上锁成功
		cout << "thread: " << this_thread::get_id() << "  printf:" << i << endl;
		++i;
		flag = false;
		cv.notify_one();//释放锁，并唤醒等在该锁上的线程
	}
}
void mutex2()
{
	while (i <= 100)
	{
		Sleep(1000);
		cout << "线程2：" << endl;
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