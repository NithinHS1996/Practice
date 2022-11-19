#include<iostream>
#include<thread>

using namespace std;

void func()
{
    cout << std::this_thread::get_id() <<" Hello from func\n";
}

void func_detach()
{
    cout << std::this_thread::get_id() <<" Hello from func detach\n";
}

int main()
{
    thread thread_1(func);

    cout << "Hello from main\n";

    if(thread_1.joinable())
	cout << "thread is joinalbe\n";
    else
	cout << "thread is not joinable\n";

    thread_1.join();

    if(thread_1.joinable())
	cout << "thread is joinalbe\n";
    else
	cout << "thread is not joinable\n";

    thread thread_2(func_detach);
    thread_2.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}
