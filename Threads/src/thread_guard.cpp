#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

class ThreadGuard
{
    thread & thread_id;
public:
    ThreadGuard(std::thread & _t): thread_id(_t){}
    ~ThreadGuard()
    {
     cerr << "exiting guard\n";
     if(thread_id.joinable())
	thread_id.join();
    }
    ThreadGuard(const ThreadGuard & ) = delete;
    ThreadGuard & operator=(const ThreadGuard & ) = delete;
};

void func()
{
cout << "Hello from func\n";
}

void exp_func()
{
throw 1;
}

int main()
{
thread thread_id(func);
ThreadGuard threadguard(thread_id);
std::this_thread::sleep_for(std::chrono::milliseconds(1000));
try{
exp_func();
}
catch(...)
{
cout << "Execption\n";
}

return 0;
}
