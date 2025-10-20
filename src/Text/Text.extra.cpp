#include "Text.hpp"

bool	Text::hasFoundSeparator(const std::string &to_search) const
{
	for (std::size_t i(0); i < to_search.size(); i++)
	{
		if (this->_found_separators.find_first_of(to_search[i]) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	Text::hasFoundSeparatorOther(const std::string &to_search) const
{
	for (std::size_t i(0); i < this->_found_separators.size(); i++)
	{
		if (to_search.find_first_of(this->_found_separators[i]) == std::string::npos)
			return (true);
	}
	return (false);
}

bool	Text::testFoundSeparators(int (*func)(int))
{
	for (std::size_t i(0); i < this->_found_separators.size(); i++)
	{
		if (this->_found_separators[i] == '{')
		{
			std::cout << "TEST { : " << (*func)(this->_found_separators[i]) << std::endl;
		}
		if ((*func)(this->_found_separators[i]) != 0)
			return (true);
	}
	return (false);
}
