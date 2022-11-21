#include <bits/stdc++.h>
#include <mqueue.h>

using namespace std;

#define MSG_SIZE 256
#define MSG_BUFFER_SIZE (MSG_SIZE * 10)

int main()
{
    char buffer[MSG_BUFFER_SIZE];
    int recvr_msg_fd = 0;
    
    memset(buffer, 0, MSG_BUFFER_SIZE);
    strcpy(buffer, "Hello");
    
    if((recvr_msg_fd = mq_open("/message1", O_WRONLY | O_CREAT, 0, 0)) == -1)
    {
        cout << "Unable to open the messge que\n";
        exit(0);
    }
    
    if(mq_send(recvr_msg_fd, buffer, strlen(buffer) + 1, 0) == -1)
    {
        cout << "Unable to send the messgae\n";
        exit(0);
    }
    
    mq_close(recvr_msg_fd);
    return 0;
}
