#include "includes/libftcpp.hpp"

int	main(int, char **argv)
{
	Text		text(argv[1]);
	std::string	tmp;

	text.addSeparators("OL");
	while (1)
	{
		text >> tmp;
		if (tmp.empty())
			break ;
		std::cout << "[" << tmp << "]" << std::endl;
		std::cout << text << std::endl;
	}
	text << "something to test here";
	std::cout << text << std::endl;
	//Utils::readLines(argv[1]);
	return (0);
}