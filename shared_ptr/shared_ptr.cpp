#include <iostream>
#include <boost/shared_ptr.hpp>

int main()
{

	boost::shared_ptr<int> ptr{new int{1}};
	std::cout << *ptr << "\n";
	boost::shared_ptr<int> ptr1{ptr};
	std::cout << *ptr1 << "\n";
	ptr.reset();
	std::cout << std::boolalpha << static_cast<bool>(ptr1) << "\n" ;
	ptr1.reset();
	std::cout << std::boolalpha << static_cast<bool>(ptr1) ;
}
