#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex _mtx;

void Print(char ch) {
	this_thread::sleep_for(chrono::milliseconds(2000));
	unique_lock<mutex> ul(_mtx, defer_lock);


	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	ul.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
	
}

int main()
{
   // thread th1(Foo, 10);
    //thread th2(Foo, 10);
	thread th1(Print, '*');
	thread th2(Print, '#');
   th1.join();
 th2.join();

    return 0;
}

