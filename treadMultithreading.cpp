
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork() {
    for (int i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tDoWork\t"<<i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void NewDoWork() {
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tNewDoWork\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main()
{
   /* cout << "START MAIN" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << this_thread::get_id() << endl;;
    cout << "END MAIN" << endl; */

    thread th(DoWork);
    thread th2(NewDoWork);
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() <<"\tmain\t"<< i <<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();
    th2.join();
    return 0;
}

