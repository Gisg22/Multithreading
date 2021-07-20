
#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleTimer.h"

using namespace std;

mutex _mtx;

void Print(char ch) {
	_mtx.lock();

	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;

	_mtx.unlock();
}

void PrintMsg(string &msg) {
	_mtx.lock();
	cout << msg << endl;
	_mtx.unlock();
}

int main()
{

	setlocale(LC_ALL, "ru");
	SimpleTimer timer;

	thread t1(Print, '#');
	thread t2(Print, '*');
	string hello = "Hello";
	thread t3(PrintMsg, std::ref(hello));
	t1.join();
	t2.join();
	t3.join();
    return 0;
}

