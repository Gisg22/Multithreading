
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

recursive_mutex rm;
mutex m;

void Foo(int a) {
    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(20));

    if (a <= 1) {
        cout << endl;
        rm.unlock();
        return;
    }
    a--;

    Foo(a);
    rm.unlock();
}



int main()
{
    thread th1(Foo, 10);
    thread th2(Foo, 10);

    th1.join();
    th2.join();

    return 0;
}

