#include <bits/stdc++.h>

using namespace std;

int main()
{

int total_length = 10;
char line[total_length];
FILE * command = popen("pidof sigreceive","r");

fgets(line,total_length,command);

pid_t pid = strtoul(line,NULL,10);
pclose(command);
cout << pid << "\n";

::kill(pid,SIGUSR1);

}
