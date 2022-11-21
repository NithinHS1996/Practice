#include <bits/stdc++.h>

using namespace std;

static void signal_Handler(int sig)
{
    cout << "Received signal\n";
    exit(0);
}

int main()
{
::signal(SIGUSR1, signal_Handler);
while(1){
cout << "Hellow world\n";
sleep(20);
}
}
