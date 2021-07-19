#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "============\t" << "DoWork STARTED\t===============" << endl;

    this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "a + b = " << a + b << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "============\t" << "DoWork END\t===============" << endl;
}

int main()
{
    thread th(DoWork, 6, 8);

   

    for (size_t i = 0; true; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    th.join();
    return 0;
}