#include <bits/stdc++.h>
#include <mqueue.h>

using namespace std;

#define MSG_SIZE 256
#define MSG_BUFFER_SIZE (MSG_SIZE * 10)
#define MAX_MSG 10
#define QUEUE_PERMISSIONS 0660

int main()
{
    fd_set readfds;
    char buffer[MSG_BUFFER_SIZE];
    int msg_fd = 0;
    
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MSG;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    
    if((msg_fd = mq_open("/message1", O_WRONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1)
    {
        cout << "Unable to open the messge que\n";
        exit(0);
    }
    
    //while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(msg_fd, &readfds);
        select(msg_fd + 1, &readfds, NULL, NULL, NULL);
        if(FD_ISSET(msg_fd, &readfds))
        {
            memset(buffer, 0, MSG_BUFFER_SIZE);
            if(mq_receive(msg_fd, buffer, MSG_BUFFER_SIZE, NULL) == -1)
            {
                cout << "Mq_receive error\n";
            }
        } 
    }
    
    mq_close(msg_fd);
    return 0;
}
