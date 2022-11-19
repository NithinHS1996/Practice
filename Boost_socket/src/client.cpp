#include <bits/stdc++.h>
#include <boost/asio.hpp>

#include <boost/asio.hpp>

enum
{
    max_length = 1024
};

int main(int argc, char *argv[])
{
    boost::asio::io_service io_service;
    boost::asio::local::datagram_protocol::endpoint server_endpoint("local_socket");
    // Create client endpoint on which to receive response
    std::string client_addr = "local_socket.";
    client_addr += std::to_string(::getpid());
    ::unlink(client_addr.c_str());
    boost::asio::local::datagram_protocol::endpoint client_endpoint(client_addr.c_str());
    boost::asio::local::datagram_protocol::socket socket(io_service, client_endpoint);

    std::cout << "Enter message: ";
    char request[max_length];
    std::cin.getline(request, max_length);
    size_t request_length = strlen(request);

    socket.send_to(
        boost::asio::buffer(request, request_length), server_endpoint);

    char reply[max_length];
    size_t reply_length = socket.receive_from(
        boost::asio::buffer(reply, max_length), client_endpoint);

    std::cout << "Reply is: ";
    std::cout.write(reply, reply_length);
    std::cout << "\n";

    return 0;
}