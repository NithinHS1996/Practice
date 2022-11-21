#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <bits/stdc++.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;
#define SOCKET_NAME "/tmp/DemoSocket"
#define BUFFER_SIZE 128

int main()
{
    struct sockaddr_un name;
    char buffer[BUFFER_SIZE];
     /*creates an endpoint for communication and returns a file
       descriptor that refers to that endpoint.*/
    int connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if(connection_socket == -1)
    {
       perror("Unable to create the socket");
       exit(0);
    }
    else
        cout << "Socket creation success\n";
    
    memset(&name, '\0', sizeof(struct sockaddr_un));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path,SOCKET_NAME, sizeof(name.sun_path) - 1);
    /* The connect() system call connects the socket referred to by the
       file descriptor sockfd to the address specified by addr.  The
       addrlen argument specifies the size of addr.  The format of the
       address in addr is determined by the address space of the socket
       sockfd*/
    int ret = connect(connection_socket, (const struct sockaddr *)&name, sizeof(name));
        if(ret != 0)
    {
        perror("Unable to connect the socket");
        exit(0);
    }
    else
        cout << "Socket connect success\n";
        strcpy(buffer ,"hello\n");
         ret = write(connection_socket, buffer, BUFFER_SIZE);
         if(ret != 0)
         {
             perror("Unable to write the data");
             exit(0);
         }
         else
            cout << "write success\n";

    close(connection_socket);   
    cout << "Closed connection\n";
    return 0;
}
