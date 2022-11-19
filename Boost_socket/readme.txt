Socket provide the communication between various entities

Socket interface are bunch of api's

We have two types of sockets
----------------------------
    Unix domain socket:- These are used to communicate between process in same machine

    Network socket:- These are used to communicate between different systems

Socket program steps:-
-----------------------

1. Remove the socket if already exist
2. Create a unix socket using socket()
3. Specify the socket name
4. Bind the socket using bind()
5. listen()
6. accept()
7. Read using recvfrom() and write using sendto()
8. close the data socket
9. close the connection socket
10. remove the socket and exit

Linux system call interface
---------------------------

        Application

     System call interface
  socket(), accept(), connect(), sendto(), recvfrom() close() etc

       OS/Kernel

     Hardware Layer

Liux provides the api's to have the service
Application will use these api's and get the services

Socket Message types
--------------------

Messages or requests exchanged between the client and server are of two types

1. Connection initiaion request messages
   This is the request sent from the client to server for establishing the connection, 
   after the connection only we can avail the service request messages

2. Service request messages
   Client sends these to avail the service from the server

         1.CIR
	--------------------------->
 Client  2. Established connection     Server
process <---------------------------  Process
	 3. SRM
	--------------------------->
	 4. Response
	<---------------------------

State machine of Socket based Client server Communication
---------------------------------------------------------

1. Server creates the socket() when boots up
2. Using accept system call it creates client handle based on the CIR
3. Data exchange happens with client handle only called data_sockets
4. Server should handle the database of the client handles


Unix domain sockets
-------------------

Unix domain sokcets are the inter process communications
There are two types:-
1. Stream based:- Used to send the large data
2. Datagram based:- Used to send the small unit of data


       Server                               Client

      socket()                           socket()
        |                                  |
	|				   |
	V				   |
      bind()				   |
	|				   |
	V				   |
      listen()				   |
	|				   |
	V				   |
      accept()				   |
	|				   |
	V				   |
    wait for connection 		   |
	|				   |
	|	establish conn		   |
	|<------------------------------connect()
	V	request			   |
     recv()<-----------------------------send()
	|				   |
	V	response		   V
      send()--------------------------->recv()




