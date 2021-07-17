
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork() {
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tDoWork\t"<<i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
   /* cout << "START MAIN" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << this_thread::get_id() << endl;;
    cout << "END MAIN" << endl; */

    thread th(DoWork);
    
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() <<"\tmain\t"<< i <<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();
    return 0;
    
}

