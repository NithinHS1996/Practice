#include <bits/stdc++.h>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;

int main()
{
    boost::asio::io_service io_service;
    std::thread thread_;
    steady_timer timer{io_service, std::chrono::seconds{3}};
    timer.async_wait([](const boost::system::error_code &ec){std::cout << "3 sec\n";});
    thread_ = std::move(std::thread([&io_service](){io_service.run();}));
    cout << "Hey able to complete the pgm\n";
    thread_.join();
    return 0;
}
