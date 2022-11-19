#include <bits/stdc++.h>
#include <boost/asio.hpp>

int main()
{
    ::unlink("local_socket");
    boost::asio::io_service io_service;
    boost::asio::local::datagram_protocol::endpoint endpoint("local_socket");
    boost::asio::local::datagram_protocol::socket socket(io_service, endpoint);
    char recv_buf[1024];
    while (1)
    {
        boost::asio::local::datagram_protocol::endpoint senderEndpoint;
        size_t len = socket.receive_from(
            boost::asio::buffer(recv_buf, 1024), senderEndpoint);
        printf("***%s###\n", senderEndpoint.path().c_str());

        socket.send_to(
            boost::asio::buffer(recv_buf, len), senderEndpoint);
    }

    return 0;
}