#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int &a) {

	this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "ID: " << this_thread::get_id() << "============\t" << "DoWork STARTED\t===============" << endl;
    
	this_thread::sleep_for(chrono::milliseconds(5000));

    a *= 2;

    cout << "ID: " << this_thread::get_id()  << "============\t" << "DoWork END\t===============" << endl;

    

}

int main()
{
int q = 5;

thread th(DoWork,std::ref( q));



    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    } 

   th.join();
   cout << q << endl;
    return 0;
}
