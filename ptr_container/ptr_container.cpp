#include<iostream>
#include<boost/ptr_container/ptr_vector.hpp>
#include<boost/ptr_container/ptr_set.hpp>
#include<boost/ptr_container/indirect_fun.hpp>

int main()
{
	boost::ptr_vector<int> vec;
	vec.push_back(new int{1});
	vec.push_back(new int{2});
	std::cout << vec.back() << "\n";

	boost::ptr_set<int> set;
	set.insert(new int{2});
	set.insert(new int{1});
	std::cout << *set.begin() << "\n";
}
