//#define SCOPED_PTR
#ifdef SCOPED_PTR

#include <boost/scoped_ptr.hpp>
#include <iostream>

int main()
{
	boost::scoped_ptr<int> p{new int{1}};
	std::cout << *p << "\n";
	p.reset(new int{2});
	std::cout << *p.get() << "\n";
	std::cout << std::boolalpha << static_cast<bool>(p) << "\n";
	p.reset();
	std::cout << std::boolalpha << static_cast<bool>(p) << "\n";
}

#else

#include <boost/scoped_array.hpp>
#include <iostream>

int main()
{
	boost::scoped_array<int> p{new int[2]};
	*p.get() = 2;
	p[1] = 3;
	std::cout << p[0] << p[1] << "\n";
	p.reset();
	std::cout << std::boolalpha << static_cast<bool>(p) << "\n";
}
#endif
