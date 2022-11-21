#include <bits/stdc++.h>

using namespace std;

static void ctrlC_Handler(int sig)
{
    cout << "Executed CTRL C\n";
    exit(0);
}

int main()
{

while(1){
::signal(SIGINT, ctrlC_Handler);
cout << "Hellow world\n";
sleep(20);
if(!raise(SIGINT))
    cout << "unable to raise\n";
else
    cout << "Sucess\n";
}

}
