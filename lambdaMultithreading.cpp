#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Sum(int a, int b) {

    this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "ID: " << this_thread::get_id() << "============\t" << "DoWork STARTED\t===============" << endl;

    this_thread::sleep_for(chrono::milliseconds(5000));


    cout << "ID: " << this_thread::get_id() << "============\t" << "DoWork END\t===============" << endl;

    
    return a + b;
}

int main()
{
    int q = 5;
    int y = 4;

    int result;
    thread th([&result, q, y]() {
        result = Sum(q, y);
        });
   
   
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    } 

    th.join();
    cout << result << endl;
    return 0;
}