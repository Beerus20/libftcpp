#include "Text.hpp"

Text	&Text::operator=(const Text &other)
{
	if (this != &other)
	{
		this->_content = other._content;
		this->_separators = other._separators;
		this->_cursor = other._cursor;
		this->_found_separators = other._found_separators;
	}
	return (*this);
}

Text	&Text::operator>>(std::string &str)
{
	if (this->_mode == Text::Mode::NORMAL)
		str =  this->getWord();
	else
		str = this->getRWord();
	return (*this);
}

Text	&Text::operator<<(const std::string &str)
{
	this->setContent(str);
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Text &to_show)
{
	(void)to_show;
	os << "Text :" << std::endl
		<< "\tcontent : " << to_show.getContent() << std::endl
		<< "\tcursor : " << to_show.getCursor() << std::endl
		<< "\tfound separators : [" << to_show.getFoundSeparators() << "]" << std::endl;
	return (os);
}
