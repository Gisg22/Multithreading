#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex _mtx1;
mutex _mtx2;


void Print(char ch) {
	_mtx2.lock();

	//this_thread::sleep_for(chrono::milliseconds(1));

	_mtx1.lock();

	for (int i = 0; i < 5; ++i)
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}

	cout << endl;

	_mtx1.unlock();

	_mtx2.unlock();
	
};

void Print2(char ch) {
	_mtx1.lock();

	//this_thread::sleep_for(chrono::milliseconds(1));

	_mtx2.lock();

	for (int i = 0; i < 5; ++i)
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}

	cout << endl;

	_mtx2.unlock();

	_mtx1.unlock();

};


int main()
{

	setlocale(LC_ALL, "ru");
	thread t1(Print, '%');
	thread t2(Print2, '&');

	t1.join();
	t2.join();

	return 0;
}