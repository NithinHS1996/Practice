#include<iostream>
#include<thread>
#include<functional>

using namespace std;

void func()
{
    cout << std::this_thread::get_id() <<" Hello from func\n";
}

class CallableObj
{
public:
void operator()()
{
     cout << std::this_thread::get_id() <<" Hello from callable obj\n";
}

};

class ThreadFunc
{
public:
    void func()
    {
	cout << std::this_thread::get_id() <<" Hello from the threadfunc\n";
    }
};

auto lambda = [](){cout << std::this_thread::get_id() <<" Hello from lambda\n"; };

int main()
{
    CallableObj obj;
    ThreadFunc threadfunc;
    std::function<void()> f1 = &func;
    std::function<void()> f2 = lambda;
    std::function<void()> f3 = std::bind(&CallableObj::operator(), obj);
    std::function<void()> f4 = std::bind(&ThreadFunc::func, threadfunc);

    thread thread_1(func);
    thread thread_2(obj);
    thread thread_3(lambda);
    thread thread_4(&ThreadFunc::func,threadfunc);
    thread thread_5(f1);
    thread thread_6(f2);
    thread thread_7(f3);
    thread thread_8(f4);

    cout << "Hello from main\n";

    thread_8.join();
    thread_7.join();
    thread_6.join();
    thread_5.join();
    thread_4.join();
    thread_3.join();
    thread_2.join();
    thread_1.join();

    return 0;
}
