#include<iostream>
#include<boost/algorithm/string.hpp>
#include<boost/lexical_cast.hpp>
#include<boost/format.hpp>
#include<boost/regex.hpp>
#include<boost/tokenizer.hpp>
#include<vector>
#include<string>
using namespace boost::algorithm;
int main()
{
	std::string str = "Hi this String exercise";
	std::cout << boost::algorithm::to_upper_copy(str) << "\n";

	str = "123456Hi Hello How are you";
	std::cout << erase_first_copy(str,"H") << "\n";
	std::cout << erase_nth_copy(str, "o", 1) << "\n";    //to erase last but one copy
	std::cout << erase_last_copy(str, "o") << "\n";
	std::cout << erase_all_copy(str, "o") << "\n";
	std::cout << erase_head_copy(str, 7) << "\n";         //to erase till 8th pos
	std::cout << erase_tail_copy(str, 4) << "\n";

	boost::iterator_range<std::string::iterator> r = find_first(str,"How");
	std::cout << r <<"\n";
	r = find_first(str, "are");
	std::cout << r << "\n";

	std::vector<std::string> vec{"hey","do","you"};
	std::cout << join(vec, "-") << "\n";               //concatinate the str with tok
	std::cout << replace_first_copy(str, "H", "y") << "\n";

	std::cout << "i" << trim_left_copy(str) << "i\n";
	std::cout << trim_left_copy_if(str, is_any_of("i")) << "\n";

	std::cout << trim_left_copy_if(str, is_digit()) << "\n";
	
	std::string s = boost::lexical_cast<std::string> (1234);
	std::cout << s << "\n";
	std::cout << boost::lexical_cast<double>(s) << "\n";

	std::cout << boost::format{"%1%.%2%.%3%"} % 01 % 10 % 2021 << "\n";

	typedef boost::tokenizer<boost::char_separator<char>> tokenizer1;
	std::string str2 = "Boost C++ libraries";
	boost::char_separator<char> sep{" "};
	tokenizer1 tok{str2,sep};
	for(tokenizer1::iterator it = tok.begin();it != tok.end();++it)
		std::cout << *it << "\n";
	
	std::string str3 = "Boost C++ libraries";
	boost::char_separator<char> sep1{" ","+"};
	tokenizer1 tok2{str3,sep1};
	for(tokenizer1::iterator it1 = tok2.begin();it1 != tok2.end();++it1)
		std::cout << *it1 << "\n";
	
}
