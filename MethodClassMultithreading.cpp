// MethodClassMultithreading.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

class User
{
public:
	User();
	User(string name, int id, string job);
	void Print();
	void PrintMsg(string msg);
	int InputNumberSum(int a, int b, int c);
private:
	string name_;
	int id_;
	string job_;
};

User::User()
{
}

User::User(string name, int id, string job) :
	name_(name), id_(id), job_(job)
{}

void User::Print()
{
	cout << "ID: " << this_thread::get_id() << "============\t" << "Print STARTED\t===============" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << name_ << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << id_ << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << job_ << endl;
	cout << "ID: " << this_thread::get_id() << "============\t" << "Print END\t===============" << endl;
}

void User::PrintMsg(string msg)
{
	cout << "ID: " << this_thread::get_id() << "============\t" << "Print STARTED\t===============" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << msg << endl;
	cout << "ID: " << this_thread::get_id() << "============\t" << "Print END\t===============" << endl;
}

int User::InputNumberSum(int a, int b, int c)
{
	cout << "ID: " << this_thread::get_id() << "============\t" << "CheckNumberSum STARTED\t===============" << endl;
	if (c == a + b) {
		cout << "True! " << endl;
	}
	else {
		cout << "False..." << endl;
	}
	cout << "ID: " << this_thread::get_id() << "============\t" << "CheckNumberSum END\t===============" << endl;
	return c;
}





int main()
{
	srand(time(0));
	int a = rand() % 10;
	int b = rand() % 10;
	int c;
	cout << a << "+" << b << " = " << endl;
	cin >> c;
	User Vasya("Vasya", 54, "Programmer");
	int result;
	thread th([&]() {
		 result = Vasya.InputNumberSum(a, b, c);
		});
	cout << result << endl;
	 

	thread th(&User::InputNumberSum, &Vasya, a, b, c);
	

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	\
	th.join();
}


