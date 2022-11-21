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
    /*Remove the socket if already done, unlink() deletes a name from the file system. If that name was the last link to a file and no processes have the file open the file is deleted and the space it was using is made available for reuse.*/
    int ret = unlink(SOCKET_NAME);
    if(ret != 0)
    {
        perror("Unable to delete the socket");

    }
    else
        cout << "Socket deletion success\n";
    
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
    /*When a socket is created with socket(2), it exists in a name
       space (address family) but has no address assigned to it.  bind()
       assigns the address specified by addr to the socket referred to
       by the file descriptor sockfd.  addrlen specifies the size, in
       bytes, of the address structure pointed to by addr.*/
    ret = bind(connection_socket, (const struct sockaddr *)&name, sizeof(name));
        if(ret != 0)
    {
        perror("Unable to bind the socket");
        exit(0);
    }
    else
        cout << "Socket bind success\n";
        
    /*listen() marks the socket referred to by sockfd as a passive
       socket, that is, as a socket that will be used to accept incoming
       connection requests using accept(2).*/
    ret = listen(connection_socket, 10); //only max 10 connecitons
    if(ret != 0)
    {
        perror("Unable to listen the socket");
        exit(0);
    }
    else
        cout << "Socket listen success\n";
    
    while(1)
    {
    /*It extracts the first
       connection request on the queue of pending connections for the
       listening socket, sockfd, creates a new connected socket, and
       returns a new file descriptor referring to that socket.*/
     int data_socket = accept(connection_socket, NULL, NULL);
     if(data_socket == 0)
     {
        perror("Unable to accept the socket");
        exit(0);
     }
     else
        cout << "Socket accept success\n";
        
     while(1)
     {
         memset(buffer, 0 , BUFFER_SIZE);
         ret = read(data_socket, buffer, BUFFER_SIZE);
         if(ret == 0)
         {
             perror("Unable to read the data");
             exit(0);
         }
         else
            cout << "read success\n";
         cout << buffer << "\n";
         ret = 0;
     }
     close(data_socket);
     data_socket = 0; 
    }
    close(connection_socket);   
    cout << "Closed connection\n";
    return 0;
}
